#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

int main()
{
    //initilization of Dice amount
    char dice[64];
    unsigned diceSides, diceAmount;
    signed modifier = 0;
    int diceTotal = 0;
    char *diceResultList = 0;
    char *diceList = 0;

    srand ( time (NULL) );

    //Ask user for number of sides and dice and how many dice to roll
    printf("Enter dice amount and sides (example, 1d20 or 1d20 +5): ");
    gets(dice);
    sscanf(dice, "%ud%u %i", &diceAmount, &diceSides, &modifier);


    int memorySize =(floor(log(diceSides)) + 3) * (diceAmount);
    //Allocation of memory
    diceResultList = malloc(sizeof(int)*diceAmount);
    diceList = malloc(sizeof(int)*diceAmount);

    //Initilization of dicePrintList to diceList to allow printing of results
    char *dicePrintList = diceList;

    int i;
    //Hold will increase and when it it is greater than or equal to diceAmount, the loop ends
    for(i = 0; i < diceAmount; i++)
    {
        int r = rand() % diceSides + 1;

        //Adds all dice results to an array
        diceResultList[i] = r;

        //By adding each instanchttp://www.bettercallsaul.com/e of "r" to diceTotal, we can get a total of all numbers rolled
        diceTotal += r;
    }

    int j;
    //loop to print out every number in the diceResultList array
    for(j = 0; j < diceAmount; j++)
    {
        if(j + 1 < diceAmount)
            dicePrintList += sprintf(dicePrintList, "%d, ", diceResultList[j]);
        else
            dicePrintList += sprintf(dicePrintList, "%d", diceResultList[j]);
    }
    printf("%s\n", diceList);

    diceTotal += modifier;
    printf("\nTotal is: %d \n", diceTotal);

    getchar();
}
