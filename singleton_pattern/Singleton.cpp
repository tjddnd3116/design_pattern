#include "Singleton.hpp"

Singleton& Singleton::getInstance()
{
	static Singleton instance;
	return instance;
}

void Singleton::show()
{
	std::cout << "Hello " << cnt++ << std::endl;
}

