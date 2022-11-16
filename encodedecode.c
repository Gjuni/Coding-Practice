#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//compare password
int checkCondition(const char* str, int length)
{
    int upper = 0, lower = 0, number = 0, special = 0, space = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(str[i]))
        {
            upper++;
        }
        else if (islower(str[i]))
        {
            lower++;
        }
        else if (isdigit(str[i]))
        {
            number++;
        }
        else if (isblank(str[i]))
        {
            space++;
        }
        else
        {
            special++;
        }
    }


    if ((upper > 1) || (lower > 1))
    {
        if (number > 1)
        {
            return 1;
        }
    }
    return 0;
}


// encoding  ���ڿ� �����ϴ� �� �˾Ƴ��� Ư�� �� ���ھ� newStrȰ���ؼ� �ٲ� ���� �־���
void encode(const char* str, int length, const char* encodingTable, char* newStr)
{
    int number = 0, index = 0, lower = 0;
    const char* original = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; i++)
    {
        newStr[i] = str[i];
    }

    for (int i = 0; i < length; i++)
    {
        number = isdigit(newStr[i]);
        lower = islower(newStr[i]);

        if (number == 0) // ���ڿ� �� ��
        {
            if (lower >= 1)
            {
                for (int j = 0; j <= 27; j++) // orginal �迭���� index�̾Ƽ� encodingtable ����
                {
                    if (newStr[i] == original[j])
                    {
                        index = j;
                    }
                }
                newStr[i] = encodingTable[index];
            }
            else // �빮�� �ҹ��ڴ� �״��
            {
                newStr[i] = newStr[i];
            }

        }
        else if (number >= 1) // ������ ��
        {
            if (47 < newStr[i] < 58)
            {
                if ((newStr[i] == 56) || (newStr[i] == 57))
                {
                    newStr[i] = (newStr[i] - 8);
                }
                else
                {
                    newStr[i] = (newStr[i] + 2);
                }
            }
        }
    }



    printf("Your password encode to ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", newStr[i]);
    }
    printf("\n");
}

//decoding
void decode(const char* str, int length, const char* encodingTable, char* newStr)
{
    int number = 0, index = 0, lower = 0;
    const char* original = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; i++)
    {
        number = isdigit(newStr[i]);
        lower = islower(newStr[i]);

        if (number == 0) // ���ڿ��̶��
        {
            if (lower >= 1) // �ҹ��ڶ��
            {
                for (int j = 0; j <= 27; j++)
                {
                    if (newStr[i] == encodingTable[j])
                    {
                        index = j;
                    }
                }
                newStr[i] = original[index];
            }
            else
            {
                newStr[i] = newStr[i];
            }
        }
        else if (number >= 1)
        {
            if (47 < newStr[i] < 58)
            {
                if ((newStr[i] == 48) || (newStr[i] == 49))
                {
                    newStr[i] = (newStr[i] + 8);
                }
                else
                {
                    newStr[i] = (newStr[i] - 2);
                }
            }
        }
    }

    printf("password decode to ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", newStr[i]);
    }
    printf("\n");
}


int main(void)
{
    char str[100];
    int length;
    char newStr[100];
    const char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";

    printf("Input Password(8-12 length and contain number & Alphabet) : ");

    while (1)
    {
        scanf("%s", str);

        length = strlen(str);

        checkCondition(str, length);

        if ((length < 8) || (length > 12))
        {
            printf("you must input 8-12 length password : ");
        }
        else if (8 <= length <= 12)
        {
            if (checkCondition(str, length) != 1)
            {
                printf("combine number & alphabet : ");
            }
            else
            {
                break;
            }
        }
    }

    encode(str, length, encodingTable, newStr);
    decode(str, length, encodingTable, newStr);

    return 0;
}