#include "FileManager.h"


FileManager::FileManager(void)
{
	identifierFound = false;
}


FileManager::~FileManager(void)
{
}

void FileManager::LoadContent(const char *filename,
	std::vector<std::vector<std::string>> attributes,
	std::vector<std::vector<std::string>> contents)
{
	std::string line, newLine;

	std::ifstream openfile(filename);	
	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			std::stringstream str;
			std::getline(openfile, line);

			str << line;
			while(std::getline(str, newLine, ']'))
			{
				std::cout <<newLine << std::endl;
			}
		}
	}
	else
	{
	
	}
}

void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> attributes,
	std::vector<std::vector<std::string>> contents, std::string identifier){}

