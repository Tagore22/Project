#ifndef Chapter2_Linkedlist 1.0
#define Chapter2_Linkedlist 1.0

#include "Chapter2_Node.h"
#include <iostream>

class Chapter_Linkedlist
{
private:
	int IndexNum;
	Chapter_Node * head;
	Chapter_Node * tail;

public:
	Chapter_Linkedlist();
	~Chapter_Linkedlist();
	void AppendNode(int num);
	Chapter_Linkedlist& DeleteNode(int num);
	Chapter_Node* GetHead() const;
	Chapter_Node* GetTail() const;
	int GetIndexNum() const;
	void ShowList() const;
};

Chapter_Linkedlist::Chapter_Linkedlist() : IndexNum(2)
{
	head = new Chapter_Node();
	tail = new Chapter_Node();

	head->prev = tail;
	head->next = tail;

	tail->prev = head;
	tail->next = head;
	//std::cout << "����Ʈ ����" << std::endl;
}

Chapter_Linkedlist::~Chapter_Linkedlist()
{
	Chapter_Node* deleter = head;

	while (head->next != tail)
	{
		deleter = head->next;
		head->next = head->next->next;
		delete deleter;
	}

	delete head;
	delete tail;
	//std::cout << "����Ʈ ����" << std::endl;
}

void Chapter_Linkedlist::AppendNode(int num)
{
	Chapter_Node * end = new Chapter_Node(num);
	
	end->prev = tail->prev;
	end->next = tail;

	tail->prev->next = end;
	tail->prev = end;
	IndexNum++;
	//std::cout << "��� �߰� :" << num << std::endl;
}

Chapter_Linkedlist& Chapter_Linkedlist::DeleteNode(int num) // *this �� �̹� �����Ǿ��ִ� ��ü�� �ƴ� Ŭ���� Ʋ�� �������� ��ȯ�ϱ� ������ *this�� ��ȯ�ϸ� �ȵȴ�.
{
	if (head->next == tail)
	{
		std::cout << "����Ʈ�� �������" << std::endl;
		return *this;
	}

	Chapter_Node* end = head;

	while (end->next != tail)
	{
		end = end->next;

		if (end->data == num)
		{
			end->prev->next = end->next;
			end->next->prev = end->prev;
			std::cout << "���� " << num << "�� ��� ����" << std::endl;
			delete end;
			IndexNum--;
			return *this;
		}
	}
	std::cout << "���� num�� ��尡 ����" << std::endl;
	return *this;
}

Chapter_Node* Chapter_Linkedlist::GetHead() const
{
	//std::cout << "head ��ȯ" << std::endl;
	return head;
}

Chapter_Node* Chapter_Linkedlist::GetTail() const
{
	//std::cout << "tail ��ȯ" << std::endl;
	return tail;
}

int Chapter_Linkedlist::GetIndexNum() const
{
	//std::cout << "IndexNum ��ȯ" << std::endl;
	return IndexNum;
}

void Chapter_Linkedlist::ShowList() const
{
	if (head->next == tail)
	{
		std::cout << "����Ʈ�� ����ֽ��ϴ�." << std::endl;
	}

	Chapter_Node* rotate = head->next;

	while (rotate != tail)
	{
		std::cout << rotate->data << " ";
		rotate = rotate->next;
	}
	std::cout << std::endl;
}
#endif
