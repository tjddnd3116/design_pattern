#include <iostream>

#include "Singleton.hpp"

using namespace std;

void otherFunc()
{
	Singleton& singleton = Singleton::getInstance();
	singleton.show();
}

int main(void)
{
	Singleton& singleton = Singleton::getInstance();

	singleton.show();
;

	otherFunc();
	singleton.show();

	return 0;
}


