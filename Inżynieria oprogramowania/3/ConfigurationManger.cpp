#include <iostream>
#include<fstream> 
#include <string>
#include "ConfigurationManger.h"

using namespace std;

ConfigurationManger::ConfigurationManger()
{
	ifstream file("data.txt", ios::in);
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line[0] == '#')
			{
				string temp = line.substr(1, line.length());
				if (temp == "database host hostname")
				{
					getline(file, line);
					host = line;
				}

				if (temp == "user")
				{
					getline(file, line);
					user = line;
				}

				if (temp == "password")
				{
					getline(file, line);
					pass = line;
				}

				if (temp == "path to tmp folder")
				{
					getline(file, line);
					xmlPath = line;
					instanceFlag = true;
				}

			}
			else
				continue;
		}
	}

	else 
		cout << "Unable to open file" << std::endl;
	file.close();
}

bool ConfigurationManger::isValid()
{
	return instanceFlag;
}

bool ConfigurationManger::instanceFlag = false;
ConfigurationManger* ConfigurationManger::singleInstance = nullptr;
ConfigurationManger* ConfigurationManger::getInstance()
{
    if(singleInstance == nullptr)
    {
        singleInstance = new ConfigurationManger();
        
		return singleInstance;
    }
	else
		return singleInstance;
}


string ConfigurationManger::GetPop3host()
{
	return host; 
}

string ConfigurationManger::GetPop3user()
{
	return user; 
}


string ConfigurationManger::GetPop3pass()
{
	return pass; 
}


string ConfigurationManger::GetXMLPath()
{
	return xmlPath; 
}

ConfigurationManger::~ConfigurationManger()
{
	instanceFlag = false;
}