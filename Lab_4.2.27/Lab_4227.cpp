#include <iostream>
#include <memory>

class Node
{
public:
	Node(const int value) : m_value(value), m_left(nullptr), m_right(nullptr) {}

	int getValue() const { return m_value; }
	Node* getLeft() const { return m_left.get(); }
	Node* getRight() const { return m_right.get(); }

	void setValue(const int newValue) { m_value = newValue; }
	void setLeft(std::unique_ptr<Node> newLeft) { m_left = std::move(newLeft); }
	void setRight(std::unique_ptr<Node> newRight) { m_right = std::move(newRight); }

	std::unique_ptr<Node> moveLeft() { return std::move(m_left); }
	std::unique_ptr<Node> moveRight() { return std::move(m_right); }

private:
	int m_value;
	std::unique_ptr<Node> m_left;
	std::unique_ptr<Node> m_right;
};

class BinaryTree
{
public:
	BinaryTree() : m_root(nullptr), m_size(0) {};

	int getSize() const { return m_size; }

	friend std::ostream& operator<<(std::ostream& output, const BinaryTree& tree)
	{
		tree.printInorder(output, tree.m_root.get());
		return output;
	}

	void add(const int value)
	{
		if (m_root == nullptr)
		{
			m_root = std::make_unique<Node>(value);
			m_size++;
			return;
		}

		Node* current = m_root.get();
		addValue(current, value);
	}

private:
	std::unique_ptr<Node> m_root;
	int m_size;

	void addValue(Node* node, const int value)
	{
		while(true)
		{
			if(value == node->getValue())
			{
				return;
			}

			if (value < node->getValue())
			{
				if (node->getLeft() == nullptr)
				{
					auto newNode = std::make_unique<Node>(value);
					node->setLeft(std::move(newNode));
					m_size++;
					break;
				}
				node = node->getLeft();
			}

			if (value > node->getValue())
			{
				if (node->getRight() == nullptr)
				{
					auto newNode = std::make_unique<Node>(value);
					node->setRight(std::move(newNode));
					m_size++;
					break;
				}
				node = node->getRight();
			}
		}
	}

	void printInorder(std::ostream& output, const Node* node) const
	{
		if (node == nullptr) return;

		printInorder(output, node->getLeft());
		output << node->getValue() << " ";
		printInorder(output, node->getRight());
	}
};

int main()
{
	BinaryTree myBinaryTree{};

	myBinaryTree.add(3);
	myBinaryTree.add(5);
	myBinaryTree.add(2);

	std::cout << myBinaryTree;
}