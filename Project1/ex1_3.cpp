//���ڿ��� ��� �ִ� ��� ������ '&20'���� �ٲ� �ִ� �޼��带 �ۼ��϶�. ���������� ��� ���ڸ� �� ���� �� ���� ��ŭ ����� ������ �̹� Ȯ���Ǿ� ������ ���ڿ��� ���� ���̰� �Բ�
//�־����ٰ� �����ص� �ȴ�(�ڹٷ� �����Ѵٸ� �迭 �ȿ��� �۾��� �� �ֵ��� ���� �迭(character array)�� �̿��ϱ� �ٶ���).

#include <iostream>

void replaceSpaces(char str[], int trueLength, int strLength)
{
    int spaceCount = 0, index, i = 0;
    for (i = 0; i < trueLength; i++)
    {
        if (str[i] == ' ')
            spaceCount++;
    }

    index = trueLength + spaceCount * 2;
    if (trueLength < strLength)
        str[trueLength] = '\0';
    for (i = trueLength - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }
        else
        {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int ex1_3main()
{
    char ex[50] = "mr john smith";
    int exp = 13;
    int i = 0;
    while (ex[i] != '\0')
    {
        i++;
    }
    replaceSpaces(ex, exp, i);

    std::cout << ex << std::endl;

    return 0;
}

void ChangeVoid(std::string Str, int StrLength)
{
    int Void = 0;
    for (int i = 0; i < StrLength; i++)
    {
        if (Str[i] == ' ')
            Void++;
    }

    if (Str.length() > StrLength)
        Str[StrLength] = '\0';

    int Index = StrLength + Void * 2;

    for (int i = StrLength - 1; i >= 0; i--)
    {
        if (Str[i] == ' ')
        {
            Str[Index - 1] = '0';
            Str[Index - 2] = '2';
            Str[Index - 3] = '%';
            Index -= 3;
        }
        else
        {
            Str[Index - 1] = Str[i];
            Index--;
        }
    }
}