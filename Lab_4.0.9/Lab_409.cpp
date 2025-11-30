#include <iostream>
#include <memory>
#include <stdexcept>

class Node
{
public:
	Node(const int value) : m_value(value), m_next(nullptr) {}

	// Getters
	const int getValue() const { return m_value; }
	Node* getNext() const { return m_next.get(); }

	// Setters
	void setValue(const int newValue) { m_value = newValue; }
	void setNext(std::unique_ptr<Node> newNext) { m_next = std::move(newNext); }

	// Methods
	std::unique_ptr<Node> moveNext() { return std::move(m_next); }

private:
	int m_value;
	std::unique_ptr<Node> m_next;
};

class Stack
{
public:
	Stack() : size(0), m_top(nullptr) {}

	// Operators
	friend std::ostream& operator<<(std::ostream& output, const Stack& stack)
	{
		try
		{
			output << stack.top();
		}
		catch (std::exception& e)
		{
			output << e.what();
		}
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Stack& stack)
	{
		int value{};
		input >> value;
		stack.push(value);
		return input;
	}

	// Methods
	void push(const int value)
	{
		auto newNode = std::make_unique<Node>(value);
		newNode->setNext(std::move(m_top));
		m_top = std::move(newNode);
		size++;
	}

	int pop()
	{
		if (m_top == nullptr)
		{
			throw std::underflow_error("Stack underflow: Cannot pop from empty stack.");
		}

		int value = m_top->getValue();
		m_top = m_top->moveNext();
		size--;

		return value;
	}

private:
	std::unique_ptr<Node> m_top;
	int size;

	// Auxiliary Methods
	const int top() const
	{
		if (size == 0)
		{
			throw std::underflow_error("Stack underflow: Cannot print top from empty stack.");
		}

		return m_top->getValue();
	}
};

int main()
{
	Stack myStack{};
	int pushCount = 0;
	int popCount = 0;

	// Input Data
	std::cout << "How many items should be pushed onto the stack? ";
	std::cin >> pushCount;

	for (int i = 0; i < pushCount; ++i)
	{
		std::cout << "Enter item " << (i + 1) << ": ";
		std::cin >> myStack;
	}

	// Pop and Print Data
	std::cout << "\nHow many items should be printed and popped? ";
	std::cin >> popCount;

	std::cout << "\nPopping items:\n";
	for (int i = 0; i < popCount; ++i)
	{
		try
		{
			std::cout << "Popped value: " << myStack.pop() << "\n";
		}
		catch (const std::underflow_error& e)
		{
			std::cerr << "Exception occurred: " << e.what() << "\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << "An unexpected error occurred: " << e.what() << "\n";
		}
	}

	// Print Top Element
	std::cout << "\nCurrent top of stack: " << myStack << std::endl;

	return 0;
}