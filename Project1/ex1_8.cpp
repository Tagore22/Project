//M*N 행렬의 한 원소가 0일 경우, 해당 원소가 속한 행과 열의 모든 원소를 0으로 설정하는 알고리즘을 작성하라.

#include <iostream>

void ChangeZero(int (*array)[3], int height, int width, int ZeroHeight, int ZeroWidth)
{
	for (int i = 0; i < height; i++)
		array[i][ZeroWidth] = 0;
	for (int i = 0; i < width; i++)
		array[ZeroHeight][i] = 0;
}

void SearchZero(int (*array)[3], int height, int width)
{
	int ZeroWidth = -1;
	int ZeroHeigth = -1;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (array[i][j] == 0)
			{
				ZeroHeigth = i;
				ZeroWidth = j;
				break;
			}
		}
		if (ZeroHeigth != -1 && ZeroWidth != -1)
			break;
	}
	ChangeZero(array, height, width, ZeroHeigth, ZeroWidth);
}

void Need2ArrayZero(int(*array)[3], int height, int width)
{
	bool heightArray[3] = { false, false, false };
	bool widthArray[3] = { false, false, false };

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (array[i][j] == 0)
			{
				heightArray[i] = true;
				widthArray[j] = true;
			}
		}
	}

	for (int i = 0; i < height; i++)
	{
		if (heightArray[i] == true)
		{
			for (int j = 0; j < width; j++)
				array[i][j] = 0;
		}
	}

	for (int i = 0; i < width; i++)
	{
		if (widthArray[i] == true)
		{
			for (int j = 0; j < height; j++)
				array[j][i] = 0;
		}
	}
}

void Need2BoolZero(int(*array)[3], int height, int width)
{
	bool heightZero = false;
	bool widthZero = false;

	for (int i = 0; i < height; i++)
	{
		if (array[i][0] == 0)
		{
			heightZero = true;
			break;
		}
	}

	for (int i = 0; i < width; i++)
	{
		if (array[0][i] == 0)
		{
			widthZero = true;
			break;
		}
	}

	for (int i = 1; i < height; i++)
	{
		for (int j = 1; j < width; j++)
		{
			if (array[i][j] == 0)
			{
				array[i][0] = 0;
				array[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < height; i++)
	{
		if (array[i][0] == 0)
		{
			for (int j = 0; j < width; j++)
				array[i][j] = 0;
		}
	}

	for (int i = 1; i < width; i++)
	{
		if (array[0][i] == 0)
		{
			for (int j = 0; j < height; j++)
				array[j][i] = 0;
		}
	}

	if (heightZero)
	{
		for (int i = 0; i < height; i++)
			array[i][0] = 0;
	}

	if (widthZero)
	{
		for (int i = 0; i < width; i++)
			array[0][i] = 0;
	}
}

int ex1_8main()
{
	int Exarray[][3] = {0,0,0,4,0,6,7,8,9};
	
	int Arrayheight = sizeof(Exarray) / sizeof(Exarray[0]);
	int Arraywidth = sizeof(Exarray[0]) / sizeof(Exarray[0][0]);

	Need2BoolZero(Exarray, Arrayheight, Arraywidth);

	for (int i = 0; i < Arrayheight; i++)
	{
		for (int j = 0; j < Arraywidth; j++)
			std::cout << Exarray[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}