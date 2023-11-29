#ifndef Singleton_hpp
#define Singleton_hpp

#include <iostream>

// Description:
//
class Singleton
{
		private:
			Singleton() {};

			int cnt = 0;

		public:
			static Singleton& getInstance();

			Singleton(Singleton const&) = delete;
			void operator=(Singleton const&) = delete;

			void show();
};
#endif //Singleton_hpp
