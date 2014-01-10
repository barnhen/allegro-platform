#pragma once

#include<string>
#include <vector>
#include<fstream>
#include <sstream>
#include <iostream>

class FileManager
{

private:
	enum LoadType { Attributes, Contents };
	int types;
	bool identifierFound;

	std::vector<std::string> tempAttributes, tempContents;
public:
	FileManager();
	~FileManager();

	void LoadContent(const char *filename, std::vector<std::vector<std::string>> attributes,
		std::vector<std::vector<std::string>> contents);

	void LoadContent(const char *filename, std::vector<std::vector<std::string>> attributes,
		std::vector<std::vector<std::string>> contents, std::string identifier);

};

