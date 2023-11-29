#include <iostream>
#include <string>

class LegacyPrinter { // adaptee
	public:
		void printWithLine(std::string text){
			std::cout << "LegacyPrinter: " << text << std::endl;
		}
};

class Printer { // target
	public:
		virtual void print(std::string text) = 0;
};

class LegacyPrinterAdapter : public Printer { // adapter
	private:
		LegacyPrinter *legacyPrinter;
	public:
		LegacyPrinterAdapter(LegacyPrinter *legacyPrinter){
			this->legacyPrinter = legacyPrinter;
		}
		void print(std::string text){
			legacyPrinter->printWithLine(text);
		}
};


int main(void)
{
	LegacyPrinter printer;
	LegacyPrinterAdapter adapter(&printer);

	adapter.print("Hello World!");

	return 0;
}
