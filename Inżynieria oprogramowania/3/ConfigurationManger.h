#include <string>

using namespace std;

class ConfigurationManger
{
private:
    static bool instanceFlag;
    static ConfigurationManger *singleInstance;
	string host;
	string user;
	string pass;
	string xmlPath;
    ConfigurationManger();
public:
    static ConfigurationManger* getInstance();
	bool isValid();
    string GetPop3host();
	string GetPop3user();
	string GetPop3pass();
	string GetXMLPath();
    ~ConfigurationManger();
};