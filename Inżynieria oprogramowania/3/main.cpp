#include <iostream>
#include "ConfigurationManger.h"

using namespace std;

int main()
{
    ConfigurationManger *object = ConfigurationManger::getInstance();

	if (ConfigurationManger::getInstance()->isValid())
	{
		cout << "Host: " << ConfigurationManger::getInstance()->GetPop3host() << endl;
		cout <<  "User: " << ConfigurationManger::getInstance()->GetPop3user() << endl;
		cout << "Password: " << ConfigurationManger::getInstance()->GetPop3pass() << endl;
		cout << "XML Path: " << ConfigurationManger::getInstance()->GetXMLPath() << endl;
	}

	cin.get();
    return 0;
}