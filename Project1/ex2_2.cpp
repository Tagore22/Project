//�ܹ��� ���Ḯ��Ʈ�� �־����� �� �ڿ��� k��° ���Ҹ� ã�� �˰����� �����϶�.

/*#include "Chapter2_Linkedlist.h"
#include "Chapter2_Node.h"
#include <iostream>

int FindKNode(const Chapter_Linkedlist& list, int k)//�Ű������� ��ü�Ͻ� const ���������� �ϴ°��� ��������. �⺻��. Chapter_Linkedlist���� �������縦 ���� ���� �����ڰ� ���� �������� �ʴ´�.
{                                                   //�׷��� �Ű������� const ���������� ���� ��쿡�� �Ű����� list�� �μ� list�� ���� ��������Ǹ鼭 �� �ȿ� �ִ� �������� �ڷ���� ���� ����
	int listnum = list.GetIndexNum() - k;           //�� �ƴ� ���� �����Ͽ� �ּҰ��� ��ġ�ϰ� �Ǹ�, FindKNode�Լ��� ����Ǹ鼭 ������� �Ű����� list�� �μ� list�� �ڷ���� ����������.
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

	std::cout << "�ڿ��� ���° ���Ҹ� Ȯ���� �̴ϱ�? : ";
	std::cin >> K;

	std::cout << "�ڿ��� K��° ���Ҵ� " << FindKNode(list, K) << "�Դϴ�." << std::endl;

	list.ShowList();

	return 0;
}*/