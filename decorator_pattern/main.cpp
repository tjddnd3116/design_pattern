#include <iostream>
#include <string>

class Beverage {
	public:
		virtual std::string getDescription() const = 0;
		virtual double cost() const = 0;
		virtual ~Beverage() {}
};

class Espresso : public Beverage {
	public:
		std::string getDescription() const override { return "Espresso"; }
		double cost() const override { return 1.99; }
};

class CondimentDecorator : public Beverage {
	public:
		virtual std::string getDescription() const = 0;
};

class Milk : public CondimentDecorator {
	private:
		Beverage* beverage;

	public:
		Milk(Beverage* beverage) : beverage(beverage) {}
		std::string getDescription() const override { return beverage->getDescription() + " + Milk"; }
		double cost() const override { return beverage->cost() + 0.10; }
};

int main(void)
{
	Beverage* espresso = new Espresso();
	std::cout << "Order: " <<  espresso->getDescription() << " $" << espresso->cost() << std::endl;

	Beverage* milk = new Milk(espresso);
	std::cout << "Order: " <<  milk->getDescription() << " $" << milk->cost() << std::endl;

	delete espresso;
	delete milk;

	return 0;
}
