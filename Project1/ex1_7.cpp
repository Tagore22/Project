//�̹����� ǥ���ϴ� M*N ����� �ִ�. �̹����� �� �ȼ��� 4����Ʈ�� ǥ���ȴ�. �̶�, �̹����� 90�� ȸ����Ű�� �޼��带 �ۼ��϶�. ����� �߰��� ������� �ʰ��� �� �� �ְڴ°�?
#include <iostream>
#include <vector>

/*void ReRotaion(int (*array)[3], int row, int column)
{
	int ReArray[][3] = { 0 };

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			ReArray[i][j] = array[i][j];
		}
	}

	int RowNum, ColumnNum = 0;
	for (int i = 0; i < row; i++)
	{
		RowNum = row - 1;
		for (int j = 0; j < column; j++)
		{
			//array[i][j] = ReArray[RowNum][ColumnNum];
			RowNum--;
		}
		ColumnNum++;
	}
}*/

void ReRotaion(int(*array)[3], int length)
{
	int ReArray[3][3] = { 0 };

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			ReArray[i][j] = array[i][j];
		}
	}

	int RowNum = 0;
	int ColumnNum = 0;
	for (int i = 0; i < length; i++)
	{
		RowNum = 2;
		for (int j = 0; j < length; j++)
		{
			array[i][j] = ReArray[RowNum][ColumnNum];
			RowNum--;
		}
		ColumnNum++;
	}
}

void IntReRotaion(int(*array)[4], int length) 
{
	int BP;
	int last = length;
	int temp;

	for (int first = 0; first < length / 2; first++)
	{
		BP = 0;
		last--; //���� ���� - 1 �������� 1�� �پ���. ��, length - 1 - first;

		for (int j = first; j < last; j++)
		{
			temp = array[first][j];

			array[first][j] = array[last - BP][first];

			array[last - BP][first] = array[last][last - BP];

			array[last][last - BP] = array[j][last];

			array[j][last] = temp;

			BP++;
		}
	}
}

int ex1_7main()
{
	int array[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	IntReRotaion(array, sizeof(array) / sizeof(array[0]));

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

using Vvector = std::vector<std::vector<int>>;

Vvector sonyhi(const Vvector& vec)
{
	Vvector sony;
	int size = vec.size();

	sony.resize(size);
	for (auto& v : sony)
		v.resize(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			sony[i][j] = vec[size - j - 1][i];
	}
	return sony; //NRVO
}

int ex1_7main_2()
{
	Vvector ins = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16} };
	Vvector ins2 = sonyhi(ins);

	/*for (int i = 0; i < ins2.size(); ++i) //�Ϲ����� for������ ���� ��� for��(vector�� ������̹Ƿ�)
	{
		for (int j = 0; j < ins2.size(); ++j)
		{
			std::cout << ins2[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	for (const auto& v : ins2) //�Ϲ����� for������ ���� ��� for��(vector�� ������̹Ƿ�)
	{
		for (int n : v)
			std::cout << n << " ";
		std::cout << std::endl;
	}

	return 0;
}