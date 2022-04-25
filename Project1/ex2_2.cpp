//단방향 연결리스트가 주어졌을 때 뒤에서 k번째 원소를 찾는 알고리즘을 구현하라.

/*#include "Chapter2_Linkedlist.h"
#include "Chapter2_Node.h"
#include <iostream>

int FindKNode(const Chapter_Linkedlist& list, int k)//매개변수가 객체일시 const 참조형으로 하는것좀 잊지마라. 기본임. Chapter_Linkedlist에는 깊은복사를 위한 복사 생성자가 따로 존재하지 않는다.
{                                                   //그래서 매개변수가 const 참조형이지 않을 경우에는 매개변수 list가 인수 list에 의해 복사생성되면서 그 안에 있던 포인터형 자료들을 깊은 복사
	int listnum = list.GetIndexNum() - k;           //가 아닌 얕은 복사하여 주소값이 일치하게 되며, FindKNode함수가 종료되면서 사라지는 매개변수 list가 인수 list의 자료까지 날려버린다.
	Chapter_Node* index = list.GetHead();

	while (listnum != 0)
	{
		index = index->GetNext();
		listnum--;
	}

	return index->GetData();
}

int EX2_2main()
{
	int K;

	Chapter_Linkedlist list;
	list.AppendNode(1);
	list.AppendNode(2);
	list.AppendNode(3);
	list.AppendNode(4);
	list.AppendNode(5);
	list.DeleteNode(3);

	std::cout << "뒤에서 몇번째 원소를 확인할 겁니까? : ";
	std::cin >> K;

	std::cout << "뒤에서 K번째 원소는 " << FindKNode(list, K) << "입니다." << std::endl;

	list.ShowList();

	return 0;
}*/