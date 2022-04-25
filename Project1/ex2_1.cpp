//���ĵǾ� ���� ���� ���Ḯ��Ʈ�� �־����� �� �� ����Ʈ���� �ߺ��Ǵ� ���Ҹ� �����ϴ� �ڵ带 �ۼ��϶�.

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
	
	while (index->GetNext() != list.GetTail()) //����� ���Ұ� �ߺ��ɽ� �ߺ��� �ι�° ���Ҹ� �ΰ� ������ �����ߴ� ù��° ���Ҹ� �����ϴ� �˰���������, index�� ����Ű�� �ִ� ��尡 �� �����Ǵ�
	{                                          //ù��° ���ҷ� �߸� �����Ǿ� �־���.
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