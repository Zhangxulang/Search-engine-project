#include "../../include/SearchEngineServer/SearchEngineServer.h"


__thread const char * name;

void test1()
{
	map<string, string> &config = Configuration::getInstance()->getConfigMap();
	
	SearchEngineServer server(config);
	server.start();
}
 
int main()
{
	test1();
	return 0;
}