#pragma once
#include<string>
#include<fstream>
using namespace std;


// M.Abdullah Bilal
// 19I-0616



struct Node {
	string name;

	Node* parent;
	Node* leftMostchild;
	Node* childToRight;

	Node(string n = "") {
		name = n;
		leftMostchild = NULL;
		childToRight = NULL;
		parent = NULL;
	}
};

struct qNode {
	Node* q;
	qNode* next;

	qNode(Node* data = NULL) {
		q = data;
		next = NULL;
	}
};

struct queue {
	qNode* front;
	qNode* rear;
	int size;

	queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}

	void push(Node* data) {
		if (front == NULL) {
			front = new qNode;
			front->q = data;
			rear = front;
		}
		else {
			rear->next = new qNode;
			rear = rear->next;
			rear->q = data;
		}
		size++;
	}
	Node* pop() {
		Node* ret;
		if (front == NULL) {
			return NULL;
		}
		else if (front == rear) {
			ret = front->q;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else {
			ret = front->q;
			qNode* temp = front;
			front = front->next;
			delete temp;
		}
		size--;
		return ret;
	}
};

struct lNode {
	string data;
	lNode* next;

	lNode() {
		data = "";
		next = 0;
	}
};

struct list {
	lNode* head;
	int size;
	list() {
		head = 0;
		size = 0;
	}
	void push(string d) {
		lNode* temp = new lNode;
		temp->data = d;
		if (head == NULL) {
			head = temp;
			return;
		}
		lNode* itt = head;
		while (itt->next != NULL) {
			itt = itt->next;
		}
		itt->next = temp;
		size++;
	}
	string pop() {
		string ret = head->data;
		lNode* temp = head;
		head = head->next;
		delete head;
		size--;
	}
};

Node* root = NULL;

Node* isPresent(Node* treeNode, string fileName) {  // checks whether node with particular name is present and if so, returns its address.
	Node* itt = treeNode->leftMostchild;  // assigning left most child to iterator.
	while (itt != NULL) {  // iterate over all childeren nodes.
		if (itt->name == fileName) {  // if found, return its address.
			return itt;
		}
		itt = itt->childToRight;
	}
	return NULL;  // if not found, don't return anything.
}

Node* addChild(Node* treeNode, string fileName) {
	Node* temp = new Node;  // creating new child node.
	temp->name = fileName;
	temp->parent = treeNode;
	Node* itt = treeNode->leftMostchild;// assigning left most child to iterator
	if (itt == NULL) {
		//itt = temp;
		treeNode->leftMostchild = temp;
		return treeNode->leftMostchild;
	}
	while (itt->childToRight != NULL) {
		itt = itt->childToRight;
	}
	itt->childToRight = temp;
	temp->parent = treeNode;
	return itt->childToRight;
}

bool foundChar(string s, char c) {
	int i = 0;
	while (s[i] != '\0') {  // if end of string: break
		if (s[i] == c) {  // if character found
			return true;
		}
		i++;
	}
	// will only reach here if character not found.
	return false;
}

void FinalMerging(Node* source, Node* target) {
	source = source->leftMostchild;
	if (target->leftMostchild == NULL) {
		target->leftMostchild = source;
		return;
	}
	target = target->leftMostchild;
	while (target->childToRight != NULL) {
		target = target->childToRight;
	}
	target->childToRight = source;
}

Node* traversal(string n) {
	int s = 0;
	Node* temp = root;
	if (temp == NULL) { // if no tree exists
		return NULL;
	}
	queue q1;
	q1.push(temp);
	while (q1.front != NULL) { // 
		s = q1.size;
		for (int i = 0; i < s; i++) {
			Node* temp = q1.pop();
			if (temp->name == n) {
				return temp;
			}
			Node* itt = temp->leftMostchild;
			while (itt != NULL) {
				q1.push(itt);
				itt = itt->childToRight;
			}
		}
	}
	return NULL;
}

void createTree(string inputFilePath) {
	root = new Node("/");
	Node* treeIterator = NULL;
	string pathBuffer = "", tempBuffer = "";  // pathBuffer for getting whole line, tempBuffer for getting each file/folder name
	int i = 0;  // to iterate through each line.
	ifstream file;
	file.open(inputFilePath, ios::in);
	if (!file.is_open()) {
		cout << "File Not Open" << endl;
		exit(0);
	}
	getline(file, pathBuffer);  // getting first line.
	while (true) {
		treeIterator = root;
		i = 1; // i = 1 to discard the first forward slash.
		tempBuffer = "";  // resetting buffer.
		while (!foundChar(tempBuffer, '.')) {  // if file found, that means it is a leaf node so go to new file.
			tempBuffer = "";  // resetting buffer.
			while (pathBuffer[i] != '/' && pathBuffer[i] != '\0') {  // reading complete folder/file name.
				tempBuffer += pathBuffer[i];
				i++;
			}
			i++;
			if (tempBuffer == "") {  // if leaf node has folder, next node would be empty.
				break;
			}
			else if (isPresent(treeIterator, tempBuffer) != NULL) {
				treeIterator = isPresent(treeIterator, tempBuffer);
			}
			else {
				treeIterator = addChild(treeIterator, tempBuffer);
			}
		}
		if (file.eof()) {  // breaking condition for while loop.
			break;
		}
		getline(file, pathBuffer);  // reading next line.
	}
	file.close();
	return;
}

void deleteNode(Node* parentNode, string inp) {
	Node* itt = parentNode->leftMostchild;
	Node* temp = NULL;
	if (itt->name == inp) {
		temp = parentNode->leftMostchild;
		parentNode->leftMostchild = parentNode->leftMostchild->childToRight;
		delete temp;
		return;
	}
	while (itt->childToRight != NULL) {
		if (itt->childToRight->name == inp) {
			temp = itt->childToRight;
			itt->childToRight = temp->childToRight;
			delete temp;
			return;
		}
		itt = itt->childToRight;
	}
}

void levelOrderFunction(string outputFilePath) {
	ofstream file;
	file.open(outputFilePath, ios::ate);
	int s = 0;
	Node* temp = root;
	if (temp == NULL) { // if no tree exists
		return;
	}
	queue q1;
	q1.push(temp);
	while (q1.front != NULL) { // 
		list l1;
		s = q1.size;
		for (int i = 0; i < s; i++) {
			Node* temp = q1.pop();
			l1.push(temp->name);
			Node* itt = temp->leftMostchild;
			while (itt != NULL) {
				q1.push(itt);
				itt = itt->childToRight;
			}
		}
		lNode* lItt = l1.head;
		while (lItt != NULL) {
			file << lItt->data;
			if (lItt->next != NULL) {
				file << " ";
			}
			lItt = lItt->next;
		}
		if (q1.front != NULL) {
			file << '\n';
		}
	}
	file.close();
}

void insertFileFolder(string source, string targetPath, string outputFilePath) {
	ofstream file;
	file.open(outputFilePath, ios::app);
	if (!file.is_open()) {
		cout << "File Not Open" << endl;
		exit(0);
	}
	Node* treeIterator = root;
	int i = 1;  // to iterate through each line. i = 1 to discard the first forward slash.
	int size = targetPath.size();
	string tempBuffer = "";  // emptying buffer.
	while (!foundChar(tempBuffer, '.')) {  // if "." found, that means it is a leaf node so go to new file.
		tempBuffer = "";  // resetting buffer.
		while (targetPath[i] != '/' && i != size) {  // reading complete folder/file name.
			tempBuffer += targetPath[i];
			i++;
		}
		i++;
		if (isPresent(treeIterator, tempBuffer) != NULL) {
			treeIterator = isPresent(treeIterator, tempBuffer);
		}
		else {
			if (foundChar(tempBuffer, '.')) {
				break;
			}
			tempBuffer = source;
			treeIterator = addChild(treeIterator, tempBuffer);
		}
		if (i > size) {
			break;
		}
	}
	if (!foundChar(tempBuffer, '.')) {
		addChild(treeIterator, source);
	}
	levelOrderFunction(outputFilePath);
}

void deleteFileFolder(string targetPath, string outputFilePath) {
	ofstream file;
	file.open(outputFilePath, ios::app);
	if (!file.is_open()) {
		cout << "File Not Open" << endl;
		exit(0);
	}
	Node* treeIterator = root;
	int i = 1;  // to iterate through each line. i = 1 to discard the first forward slash.
	int size = targetPath.size();
	string tempBuffer = "";  // emptying buffer.
	while (!foundChar(tempBuffer, '.')) {  // if "." found, that means it is a leaf node so go to new file.
		tempBuffer = "";  // resetting buffer.
		while (targetPath[i] != '/') {  // reading complete folder/file name.
			if (i == size) {
				deleteNode(treeIterator, tempBuffer);
				levelOrderFunction(outputFilePath);
				return;
			}
			tempBuffer += targetPath[i];
			i++;
		}
		i++;
		if (isPresent(treeIterator, tempBuffer) != NULL) {
			treeIterator = isPresent(treeIterator, tempBuffer);
		}
	}
	levelOrderFunction(outputFilePath);
}

void mergeFolder(string sourcePath, string targetPath, string outputFilePath) {
	ofstream file;
	file.open(outputFilePath, ios::app);
	if (!file.is_open()) {
		cout << "File Not Open" << endl;
		exit(0);
	}
	Node* treeIterator = root;
	Node* toBeCopied = root;
	int i = 1;  // to iterate through each line. i = 1 to discard the first forward slash.
	int size = targetPath.size();
	int sourceSize = sourcePath.size();
	string tempBuffer = "";  // emptying buffer.
	while (i < sourceSize) {  // if "." found, that means it is a leaf node so go to new file.
		tempBuffer = "";  // resetting buffer.
		while (sourcePath[i] != '/' && i != sourceSize) {  // reading complete folder/file name.
			tempBuffer += sourcePath[i];
			i++;
		}
		i++;
		if (isPresent(toBeCopied, tempBuffer) != NULL) {
			toBeCopied = isPresent(toBeCopied, tempBuffer);
		}
	}
	tempBuffer = "";
	i = 1;
	while (i < size) {  // if "." found, that means it is a leaf node so go to new file.
		tempBuffer = "";  // resetting buffer.
		while (targetPath[i] != '/' && i != size) {  // reading complete folder/file name.
			tempBuffer += targetPath[i];
			i++;
		}
		i++;
		if (isPresent(treeIterator, tempBuffer) != NULL) {
			treeIterator = isPresent(treeIterator, tempBuffer);
		}
	}
	if (treeIterator->leftMostchild == NULL) {

	}
	else {
		treeIterator = treeIterator->leftMostchild;
		while (treeIterator->childToRight != NULL) {
			treeIterator = treeIterator->childToRight;
		}
		treeIterator->childToRight = toBeCopied->leftMostchild;
	}
	FinalMerging(toBeCopied, treeIterator);
	levelOrderFunction(outputFilePath);
}

void searchFileFolder(string targetFileFolder, string outputFilePath) {
	ofstream file;
	file.open(outputFilePath, ios::ate);
	if (!file.is_open()) {
		cout << "File Not Open." << endl;
		exit(0);
	}
	int reverseItt = 0;
	bool done = false;
	string path, buffer1;
	int s = 0;
	Node* temp = root;
	if (temp == NULL) { // if no tree exists
		return;
	}
	queue q1;
	q1.push(temp);
	while (q1.front != NULL) { // 
		s = q1.size;
		for (int i = 0; i < s; i++) {
			Node* temp = q1.pop();
			if (temp->name == targetFileFolder) {
				Node* itt = temp;
				if (done == true) {
					file << endl;
				}
				done = true;
				path = "";
				buffer1 = "";
				while (itt->parent != NULL) {
					buffer1 += '/';
					buffer1.append(itt->name);
					buffer1.append(path);
					path = buffer1;
					itt = itt->parent;
					buffer1 = "";
				}
				file << path;
				path = "";
			}
			Node* itt = temp->leftMostchild;
			while (itt != NULL) {
				q1.push(itt);
				itt = itt->childToRight;
			}
		}
	}
	return;
}