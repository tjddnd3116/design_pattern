#include <iostream>
#include <typeinfo>

class Context;

class State
{
	protected:
		Context* context;
	public:
		virtual ~State() {}
		void setContext(Context* context)
		{
			this->context = context;
		}
		virtual void handle1() = 0;
		virtual void handle2() = 0;
};

class Context
{
	private:
		State* state_;
	public:
		Context(State* state) : state_(nullptr)
		{
			this->transitionTo(state);
		}
		~Context()
		{
			delete state_;
		}
		void transitionTo(State* state)
		{
			std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
			if (this->state_ != nullptr)
				delete this->state_;
			this->state_ = state;
			this->state_->setContext(this);
		}
		void request1()
		{
			this->state_->handle1();
		}
		void request2()
		{
			this->state_->handle2();
		}
};

class ConcreteStateA : public State
{
	public:
		void handle1() override;
		void handle2() override
		{
			std::cout << "ConcreteStateA handles request2.\n";
		}
};

class ConcreteStateB : public State
{
	public:
		void handle1() override
		{
			std::cout << "ConcreteStateB handles request1.\n";
		}
		void handle2() override
		{
			std::cout << "ConcreteStateB handles request2.\n";
			std::cout << "ConcreteStateB wants to change the state of the context.\n";
			this->context->transitionTo(new ConcreteStateA);
		}
};

void ConcreteStateA::handle1()
{
	{
		std::cout << "ConcreteStateA handles request1.\n";
		std::cout << "ConcreteStateA wants to change the state of the context.\n";
		this->context->transitionTo(new ConcreteStateB);
	}
}

void clientCode()
{
	Context* context = new Context(new ConcreteStateA);
	context->request1();
	context->request2();
	delete context;
}

int main(void)
{
	clientCode();
	return 0;
}
