// Created By June

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ONE_SECOND 350


void GameStart(int const *baseball, int * answer, int chance)
{
    while(chance > 0)
    {
        int ball=0, strike=0, HomeRun=0;

        printf("Input Answer : ");
        for(int i =0; i<4; i++)
        {
            scanf("%d", &answer[i]);
        }

        for(int i =0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(answer[i] == baseball[j])
                {
                    if(i == j)
                    {
                        HomeRun++;
                    }
                    else if(i != j)
                    {
                        ball++;
                    }
                }
            }
        }

        strike = 4-(HomeRun+ball);

        if(HomeRun == 4)
        {
            int i=0;
            printf("Result Calculating");
            while (i < 3)
            {
                printf(" o");
                Sleep(ONE_SECOND);
                i++;
            }
            printf("\n\n");
            printf("================ You Got all HomeRun!! ================\n\n");
            break;
        }
        else if(chance > 0)
        {
            int i=0;
            printf("Result Calculating");
            while (i < 3)
            {
                printf(" o");
                Sleep(ONE_SECOND);
                i++;
            }
            printf("\n\n");
            printf("HomeRun : %d , Ball : %d , Strike : %d\n", HomeRun, ball, strike);
            chance --;
            printf("================ You have %d Chance ================\n\n", chance);
        }
        else if(chance == 0)
        {
            printf("Game Finish\n\n");
        }
    }
}

void RandomNum(int *baseball)
{
    int i =0;
    const int arr[9] = {1,2,3,4,5,6,7,8,9};
    int compare[9] = {0};
    int index;

    printf("Creating Random number");
    while (i < 3)
    {
        printf(" o");
        Sleep(ONE_SECOND);
        i++;
    }

    srand((unsigned int) time(NULL));
    
    for(i =0; i<4; i++)
    {
        while(1)
        {
            index = rand()%9;
            if(compare[index] == 0)
            {
                baseball[i] = arr[index];
                compare[index] = 1;
                break;
            }
            else
            {
                index = rand()%9;
            }
        }
    }

    printf("\nRandom number Created!\n");
    printf("Guess the number! \n\n");
}


#if 1
int restart(char Game)
{
    int result;
    while(1)
    {
        if(Game == 'Y' || Game == 'y')
        {
            printf("Restart Game!\n\n");
            result = 1;
            break;
        }
        else if(Game == 'N' || Game == 'n')
        {
            printf("End the game\n");
            result = 0;
            break;
        }
        else
        {
            printf("please input Y or N : ");
            scanf(" %c", &Game);
        }
    }
    return result;
}
#endif


int main(void)
{
    int baseball[4];
    int answer[4];
    char game = '1';
    int chance;
    int Regame;

    while(1)
    {

        fputs("================ Start Game ================", stdout); printf("\n");
        printf("How many chance to find ball? : ");
        scanf("%d", &chance);
        RandomNum(baseball);

#if 0    
        for(int i =0; i<4; i++)
        {
            printf("%2d", baseball[i]);
        }
        printf("\n");
#endif

        GameStart(baseball, answer, chance);
        printf("The answer was ");
        for(int i =0; i<4; i++)
        {
            printf("%2d", baseball[i]);
        }
        printf("\n");
        

#if 1
        printf("Do you want to restart game? Y/N : ");
        scanf(" %c", &game);
        Regame = restart(game);

        if(Regame == 1)
        {
            continue;
        }
        else if(Regame == 0)
        {
            break;
        }
#endif
    }
return 0;
}