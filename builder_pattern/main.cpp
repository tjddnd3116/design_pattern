#include <iostream>
#include <string>

class ComplexObject {
	public:
		int value;
		int position;
		std::string subject;
		std::string description;

	public:
		ComplexObject(int param1, int param2, std::string param3, std::string param4)
			: value(param1), position(param2), subject(param3), description(param4)
		{
		}

		void display()
		{
			std::cout << "value : " << value << std::endl;
			std::cout << "position : " << position << std::endl;
			std::cout << "subject : " << subject << std::endl;
			std::cout << "description : " << description << std::endl;
		}
};

class Builder {
	public:
		virtual void buildInt1(int v = 0) = 0;
		virtual void buildInt2(int v = 0) = 0;
		virtual void buildStr3(std::string str = "") = 0;
		virtual void buildStr4(std::string str = "") = 0;
		virtual ComplexObject getResult() = 0;
};

class ConcreteBuilder : public Builder {
	private:
		ComplexObject obj;

	public:
		ConcreteBuilder() : obj(0, 0, "", "")
		{
		}

		void buildInt1(int v) override
		{
			obj.value = v;
		}

		void buildInt2(int v = 0) override
		{
			obj.position = v;
		}

		void buildStr3(std::string str = "") override
		{
			obj.subject = str;
		}

		void buildStr4(std::string str = "") override
		{
			obj.description = str;
		}

		ComplexObject getResult() override
		{
			return obj;
		}
};

class Director {
	public:
		void construct(Builder* builder)
		{
			builder->buildInt1(1);
			builder->buildInt2(2);
			builder->buildStr3("3");
			builder->buildStr4("4");
		}
};

int main(void)
{
	ConcreteBuilder builder;
	Director director;

	ComplexObject obj = builder.getResult();
	obj.display();

	director.construct(&builder);

	obj = builder.getResult();
	obj.display();

	return 0;
}
