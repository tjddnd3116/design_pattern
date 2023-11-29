#include <iostream>

// Factory Method Pattern
//

class Product {
	public:
		virtual void use() = 0;
};


class ConcreteProductA : public Product {
	public:
		void use() override {
			std::cout << "ConcreateProductA" << std::endl;
		}
};

class ConcreteProductB : public Product {
	public:
		void use() override {
			std::cout << "ConcreateProductB" << std::endl;
		}
};

class Creator {
	public:
		virtual Product* factoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
	public:
		Product* factoryMethod() override {
			return new ConcreteProductA();
		}
};

class ConcreteCreatorB : public Creator {
	public:
		Product* factoryMethod() override {
			return new ConcreteProductB();
		}
};

int main(void)
{
	ConcreteCreatorA A;
	ConcreteCreatorB B;

	Product* pResult_A = A.factoryMethod();
	Product* pResult_B = B.factoryMethod();

	pResult_A->use();
	pResult_B->use();

	return 0;
}
