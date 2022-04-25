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
	//std::cout << "리스트 생성" << std::endl;
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
	//std::cout << "리스트 삭제" << std::endl;
}

void Chapter_Linkedlist::AppendNode(int num)
{
	Chapter_Node * end = new Chapter_Node(num);
	
	end->prev = tail->prev;
	end->next = tail;

	tail->prev->next = end;
	tail->prev = end;
	IndexNum++;
	//std::cout << "노드 추가 :" << num << std::endl;
}

Chapter_Linkedlist& Chapter_Linkedlist::DeleteNode(int num) // *this 는 이미 생성되어있는 객체가 아닌 클래스 틀의 복사형을 반환하기 때문에 *this로 반환하면 안된다.
{
	if (head->next == tail)
	{
		std::cout << "리스트가 비어있음" << std::endl;
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
			std::cout << "값이 " << num << "인 노드 제거" << std::endl;
			delete end;
			IndexNum--;
			return *this;
		}
	}
	std::cout << "값이 num인 노드가 없음" << std::endl;
	return *this;
}

Chapter_Node* Chapter_Linkedlist::GetHead() const
{
	//std::cout << "head 반환" << std::endl;
	return head;
}

Chapter_Node* Chapter_Linkedlist::GetTail() const
{
	//std::cout << "tail 반환" << std::endl;
	return tail;
}

int Chapter_Linkedlist::GetIndexNum() const
{
	//std::cout << "IndexNum 반환" << std::endl;
	return IndexNum;
}

void Chapter_Linkedlist::ShowList() const
{
	if (head->next == tail)
	{
		std::cout << "리스트가 비어있습니다." << std::endl;
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
