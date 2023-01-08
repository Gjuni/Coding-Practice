// Created By June

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define ONE_SECOND 350

void countDown()
{
    for(int i =0; i<3; i++)
    {
        printf("  o");
        Sleep(ONE_SECOND);
    }
}

void manual()
{
    printf("if you want to call a number");
    Sleep(800);
    printf("\nyou just input count number like");
    Sleep(800);
    printf("\n3 = 1,2,3 / 2 = 1,2\n");
    Sleep(800);
    printf("Enjoy game!!\n\n");
}

int GameStart(char regame)
{
    int result;

    while(1)
    {
        if(regame == 'Y' || regame == 'y')
        {
            result = 1;
            break;
        }
        else if(regame == 'N' || regame == 'n')
        {
            result = 0;
            break;
        }
        else
        {
            printf("Please Input Y/N : ");
            scanf(" %c", &regame);
            continue;
        }
    }
    return result;
}

void randnumberAdd()
{
    int total = 0;
    int input;

    while(total < 31)
    {
        
        printf("Baskin Robbins 31 : %d\nInput Number : ", total);
        scanf("%d", &input);
        
        while(1)
        {
        if(input == 1)
        {
            total += 1;
            printf("%3d", total);
            printf("\n");
            break;
        }
        else if(input == 2)
        {
            total += 2;
            for(int i=1; i<=2; i++)
            {
                printf("%3d", total-2+i);
            }
            printf("\n");
            break;
        }
        else if(input == 3)
        {
            total += 3;
            for(int i=1; i<=3; i++)
            {
                printf("%3d", total-3+i);
            }
            printf("\n");
            break;
        }
        else
        {
            printf("Input 1 - 3 Only : ");
            scanf("%d", &input);
            continue;
        }
        }

        countDown();
        printf("\n");
        
        srand((unsigned int) time(NULL));

        int number=0;

        if(total <= 30)
        {
            if(total == 30)
            {
                countDown();
                printf("\n\nComputer Loose  OTL \n");
                break;
            }
            else if(total == 29)
            {
                total ++;
                printf("%3d", total);
                printf("\n");
                countDown();
                printf("\n\nYou Loose HAHA (*^_^*)\n");
                break;
            }      
            else if(total == 28)
            {
                for(int i=1; i<=2; i++)
                {
                    total ++;
                    printf("%3d", total);
                }
                printf("\n");
                countDown();
                printf("\n\nYou Loose HAHA (*^_^*)\n");
                break;
            }
            else if(total == 27)
            {
                for(int i =1; i<=3; i++)
                {
                    total ++;
                    printf("%3d", total);
                }
                printf("\n");
                countDown();
                printf("\n\nYou Loose HAHA (*^_^*)\n");
                break;
            }
            else if(total == 26)
            {
                printf("\n");
                total ++;
                printf("%3d", total);
                printf("\n I m loose...");
                printf("\n");
            }
            else if(total == 25)
            {
                printf("\n");
                total ++;
                printf("%3d", total);
                printf("\n I m Win!!");
                printf("\n");
            }
            else if(total == 24)
            {
                printf("\n");
                for(int i =0; i<2; i++)
                {
                    total ++;
                    printf("%3d", total);
                }
                printf("\n");
            }
            else
            {
                printf("\n");
                number = rand()%3 +1;
                total += number;
                for(int i=1; i<= number; i++)
                {
                    printf("%3d", total - number +i);
                }
                printf("\n");
            }
        }
    }

}


int main(void)
{
    char regame;
    int restart = 1;

    manual();

    while(restart == 1)
    {

        randnumberAdd();

        // restart Game
        printf("Do you want to Restart Game? : ");
        scanf(" %c", &regame);
        restart = GameStart(regame);
    }
    
    
    return 0;
}