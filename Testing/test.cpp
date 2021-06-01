#include "pch.h"
#include "C:\Users\abdul\source\repos\File Directory Tree Shell\File Directory Tree Shell\Header.h" // include header file here
using namespace std;

#include <fstream>
#include <string>


TEST(testNTreeCreation, InputFileReadingTest) // 10 marks
{
	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\output1.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\LevelOrderOutput.txt";

	createTree(inputFilePath);
	levelOrderFunction(outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();

}


TEST(insertFile, insertFileTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myInsertFileOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\InsertFileOutput.txt";
	string source = "testcase.txt";
	string targetPath = "/root/bin/apt-get";

	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(insertFolder, insertFolderTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myInsertFolderOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\InsertFolderOutput.txt";
	string source = "testcase";
	string targetPath = "/usr/dev";

	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(insertFolderFail, insertFolderFailTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myInsertFileOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\LevelOrderOutput.txt";
	string source = "testcase";
	string targetPath = "/usr/dev/echo.txt";

	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(deleteFile, deleteFileTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myDeleteFileOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\DeleteFileOutput.txt";
	string targetPath = "/root/bin/ls.cpp";

	createTree(inputFilePath);
	deleteFileFolder(targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(deleteFolder, deleteFolderTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myDeleteFolderOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\DeleteFolderOutput.txt";
	string targetPath = "/home/Desktop/Assignments";

	createTree(inputFilePath);
	deleteFileFolder(targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(mergeFolder, mergeFolderTest) { // 20 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\myMergeFolderOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\MergeFolderOutput.txt";
	string sourcePath = "/home/Desktop/Assignments";
	string targetPath = "/root/bin/apt-get";

	createTree(inputFilePath);
	mergeFolder(sourcePath, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}



TEST(searchFile, searchFileTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\mySearchFileOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\SearchFileOutput.txt";
	string targetFile = "Test.cpp";

	createTree(inputFilePath);
	searchFileFolder(targetFile, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(searchFolder, searchFolderTest) { // 5 marks

	string inputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\input.txt";
	string outputFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\mySearchFolderOutput.txt"; // file must be created in solution folder
	string expectedFilePath = "C:\\Users\\abdul\\source\\repos\\File Directory Tree Shell\\File Directory Tree Shell\\SearchFolderOutput.txt";
	string targetFolder = "lib";

	createTree(inputFilePath);
	searchFileFolder(targetFolder, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}


