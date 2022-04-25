//정렬되어 있지 않은 연결리스트가 주어졌을 때 이 리스트에서 중복되는 원소를 제거하는 코드를 작성하라.

#include "Chapter2_Linkedlist.h"
#include "Chapter2_Node.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool FindOverlaps(std::vector<int> array, int num)
{
	std::vector<int>::iterator iter = std::find(array.begin(), array.end(), num);

	return iter != array.end() ? true : false;
}

void TerminateOverlaps(Chapter_Linkedlist& list)
{
	std::vector<int> array;
	array.push_back(-1);
	Chapter_Node* index = list.GetHead();
	bool check = false;
	
	while (index->GetNext() != list.GetTail()) //노드의 원소가 중복될시 중복된 두번째 원소를 두고 기존에 존재했던 첫번째 원소를 삭제하는 알고리즘이지만, index가 가르키고 있던 노드가 그 삭제되는
	{                                          //첫번째 원소로 잘못 설정되어 있었다.
		index = index->GetNext();
		check = FindOverlaps(array, index->GetData());

		if (check)
		{
			list.DeleteNode(index->GetData());
		}
		else
		{
			array.push_back(index->GetData());
		}
	}
}

int ex2_2main()
{
	Chapter_Linkedlist list;
	list.AppendNode(1);
	list.AppendNode(2);
	list.AppendNode(3);
	list.AppendNode(4);
	list.AppendNode(5);
	list.AppendNode(5);

	list.ShowList();

	TerminateOverlaps(list);

	list.ShowList();

	return 0;
}