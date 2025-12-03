#include <iostream>
#include <memory>
#include <vector>

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

	int operator[](int index)
	{
		if (m_root == nullptr)
		{
			throw std::out_of_range("Error: Cannot access element in an empty tree");
		}

		if (index < 0 || index >= m_size)
		{
			throw std::out_of_range("Error: Index is out of bounds");
		}

		if (m_values.size() == m_size)
		{
			return m_values.at(index);
		}

		m_values.clear();
		saveValues(m_root.get());

		return m_values.at(index);
	}

	virtual ~BinaryTree() = default;

	int getSize() const { return m_size; }

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

protected:
	std::unique_ptr<Node> m_root;
	int m_size;
	std::vector<int> m_values;

	virtual void saveValues(const Node* node) = 0;

private:
	void addValue(Node* node, const int value)
	{
		while (true)
		{
			if (value == node->getValue())
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
};

class InorderTree : public BinaryTree
{
public:
	InorderTree() : BinaryTree() {}

	friend std::ostream& operator<<(std::ostream& output, const InorderTree& tree)
	{
		tree.printInorder(output, tree.m_root.get());
		return output;
	}

private:
	void printInorder(std::ostream& output, const Node* node) const
	{
		if (node == nullptr) return;

		printInorder(output, node->getLeft());
		output << node->getValue() << " ";
		printInorder(output, node->getRight());
	}

	void saveValues(const Node* node) override
	{
		if (node == nullptr) return;

		saveValues(node->getLeft());
		m_values.push_back(node->getValue());
		saveValues(node->getRight());
	}
};

class PostorderTree : public BinaryTree
{
public:
	PostorderTree() : BinaryTree() {}

	friend std::ostream& operator<<(std::ostream& output, const PostorderTree& tree)
	{
		tree.printPostorder(output, tree.m_root.get());
		return output;
	}

private:
	void printPostorder(std::ostream& output, const Node* node) const
	{
		if (node == nullptr) return;

		printPostorder(output, node->getLeft());
		printPostorder(output, node->getRight());
		output << node->getValue() << " ";
	}

	void saveValues(const Node* node) override
	{
		if (node == nullptr) return;

		saveValues(node->getLeft());
		saveValues(node->getRight());
		m_values.push_back(node->getValue());
	}
};

class PreorderTree : public BinaryTree
{
public:
	PreorderTree() : BinaryTree() {}

	friend std::ostream& operator<<(std::ostream& output, const PreorderTree& tree)
	{
		tree.printPreorder(output, tree.m_root.get());
		return output;
	}

private:
	void printPreorder(std::ostream& output, const Node* node) const
	{
		if (node == nullptr) return;

		output << node->getValue() << " ";
		printPreorder(output, node->getLeft());
		printPreorder(output, node->getRight());
	}

	void saveValues(const Node* node) override
	{
		if (node == nullptr) return;

		m_values.push_back(node->getValue());
		saveValues(node->getLeft());
		saveValues(node->getRight());
	}
};

int main()
{
	InorderTree myInorderTree{};
	PostorderTree myPostorderTree{};
	PreorderTree myPreorderTree{};

	myInorderTree.add(3);
	myInorderTree.add(5);
	myInorderTree.add(6);
	myInorderTree.add(1);

	myPostorderTree.add(3);
	myPostorderTree.add(5);
	myPostorderTree.add(6);
	myPostorderTree.add(1);

	myPreorderTree.add(3);
	myPreorderTree.add(5);
	myPreorderTree.add(6);
	myPreorderTree.add(1);

	std::cout << "Inorder: " << myInorderTree << '\n';
	std::cout << "Postorder: " << myPostorderTree << '\n';
	std::cout << "Preorder: " << myPreorderTree << '\n';
}