// Created By June

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void countDown()
{
    for(int i =0; i<3; i++)
    {
        printf(" o");
        Sleep(350);
    }
}

void manual()
{
    printf("Computer Will give Random number\n");
    Sleep(500);
    printf("You have to Guess number!\n");
    Sleep(500);
}

void StartGame()
{
    srand((unsigned int) time(NULL));   
    int num = rand()%100+1;

    int guess;
    int count=1;

    while(guess != num)
    {
        printf("Guess the number! : ");
        scanf("%d", &guess);

        if(num > guess)
        {
            countDown();
            printf("\nYou have to increase number!\n");
            count++;
        }
        else if(num < guess)
        {
            countDown();
            printf("\nYou have to Decrease number!\n");
            count++;
        }
    }
    countDown();
    printf("\nYou Got the number!!\n");
    printf("You Tried %d Times\n", count);
}


int reGame(char n)
{
    int result;

    while(1)
    {
        if(n =='Y' || n == 'y')
        {
            countDown();
            printf("\nReStart Game!! \n");
            result = 1;
            break;
        }
        else if(n == 'N' || n == 'n')
        {
            countDown();
            printf("\nEnd Game!\n");
            result = 0;
            break;
        }
        else
        {
            printf("\nPlease Input Y/N or y/n : ");
            scanf("%c", &n);
            continue;
        }
    }

    return result;
}


int main(void)
{
    char n;
    int result = 1;

    manual();
    countDown();
    printf("\n");

    while(result == 1)
    {
        StartGame();

        printf("\nReStart Game? (Y/N) : ");
        scanf(" %c", &n);
        result = reGame(n);
    }

    return 0;
}