#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumber(int n)
{
    srand(time(NULL)); // takes seed as a input and included in stdlib.h
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    
    if ((c1 == 'r') && (c2 == 's'))
    {
        return 1;
    }
    else if ((c2 == 'r') && (c1 == 's'))
    {
        return 0;
    }
    else if ((c1 == 'p') && (c2 == 'r'))
    {
        return 1;
    }
    else if ((c2 == 'p') && (c1 == 'r'))
    {
        return 0;
    }
    if ((c1 == 's') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c2 == 's') && (c1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int rounds, choice, plScore = 0, compScore = 0;
    char pChoice, compChoice;
    char opt[] = {'r', 'p', 's'};
    printf("Welcome to the game!!!!\n");
    printf("Enter number of rounds you want to play -> ");
    scanf("%d", &rounds);
    for (int i = 0; i < rounds; i++)
    {
        // Player's Turn
        printf("Player's turn\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors \n");
        scanf("%d", &choice);

        pChoice = opt[choice - 1];
        printf("You chose -> %c\n\n", pChoice);

        // Computer's Turn
        printf("Computer's turn \n");
        // printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors \n");
        choice = generateNumber(3);

        compChoice = opt[choice];
        printf("Computer chose -> %c\n", compChoice);

        if (greater(pChoice, compChoice) == 1)
        {
            compScore += 1;
            printf("You lost it :(\n");
        }
        else if (greater(pChoice, compChoice) == -1)
        {
            printf("Nulled\n");
        }
        else
        {
            plScore += 1;
            printf("You got it :)\n");
        }

        printf("You : %d\n\nComputer : %d\n", plScore, compScore);
    }

    if (plScore > compScore)
    {
        printf("You Won!!!");
    }
    else if (plScore == compScore)
    {
        printf("DRAW!!!");
    }
    else{
        printf("Better Luck Next Time!!!");
    }

    return 0;
}
