#ifndef Chapter2_Node 1.0
#define Chapter2_Node 1.0
#include <iostream>

class Chapter_Linkedlist;

class Chapter_Node
{
private:
	friend class Chapter_Linkedlist;
	int data;
	Chapter_Node * prev;
	Chapter_Node * next;

public: 
	Chapter_Node(int a);
	Chapter_Node();
	Chapter_Node(Chapter_Node* node);
	~Chapter_Node();
	Chapter_Node* GetNext() const;
	Chapter_Node* GetPrev() const;
	int GetData() const;
};

Chapter_Node::Chapter_Node(int a) : data(a)
{
	prev = nullptr;
	next = nullptr;
	//std::cout << "��� ����" << std::endl;
}

Chapter_Node::Chapter_Node()
{
	data = -1;
	prev = nullptr;
	next = nullptr;
	//std::cout << "��� ����" << std::endl;
}

Chapter_Node::Chapter_Node(Chapter_Node* node) : data(node->data), prev(node->prev), next(node->next)
{
	//std::cout << "��� ����" << std::endl;
}

Chapter_Node::~Chapter_Node()
{
	//std::cout << "��� ����" << std::endl;
}

Chapter_Node* Chapter_Node::GetNext() const
{
	//std::cout << "���� ��� ��ȯ" << std::endl;
	return next;
}

Chapter_Node* Chapter_Node::GetPrev() const
{
	//std::cout << "���� ��� ��ȯ" << std::endl;
	return prev;
}

int Chapter_Node::GetData() const
{
	//std::cout << "����� �� ��ȯ" << std::endl;
	return data;
}
#endif