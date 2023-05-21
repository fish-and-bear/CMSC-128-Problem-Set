/************************************************************************************************************************************
 *  CMSC 128 Problem Set: Money Dispenser
 *
 *  This program dispenses money from a machine.
 *  The program first asks the user to input the number of PHP 100 bills, PHP 50 bills, PHP 20 bills, PHP 5 coins, and PHP 1 coins.
 *  The program, then, asks the user to input the money they want to dispense.
 *  If possible, the program will dispense the amount of money requested using the minimum number of bills and coins.
 *  The program will stop when the user inputs 0 or when there are no more bills or coins left.
 *
 *  Author: Angelica Anne A. Naguio
 *  Date: 2023-05-21
 *
 *************************************************************************************************************************************/

#include <stdio.h>

int main()
{
    // variables
    int bills[5] = {100, 50, 20, 5, 1};
    int remainingBills[5] = {0}, dispensedBills[5] = {0};
    int numBills = sizeof(bills) / sizeof(bills[0]);
    int amount, dispensedAmount;

    // get user input
    for (int i = 0; i < numBills; i++)
    {
        printf("Enter the number of PHP%d bills: ", bills[i]);
        scanf("%d", &remainingBills[i]);
    }

    // main loop
    while (1)
    {
        // Get input from the user
        printf("Dispensing amount: ");
        scanf("%d", &amount);

        // if the user inputs 0, stop the program
        if (amount == 0)
        {
            break;
        }

        // reset dispensed amount every loop
        dispensedAmount = 0;
        for (int i = 0; i < numBills; i++)
        {
            dispensedBills[i] = 0;
        }

        // calculate minimum possible dispensed bills
        for (int i = 0; i < numBills; i++)
        {
            while (remainingBills[i] > 0 && amount >= bills[i])
            {
                dispensedAmount += bills[i];
                amount -= bills[i];
                remainingBills[i]--;
                dispensedBills[i]++;
            }
        }

        // if money in the machine is not enough to dispense amount
        if (amount > 0)
        {
            printf("Not enough money in the machine\n");
            dispensedAmount = 0;
            for (int i = 0; i < numBills; i++)
            {
                remainingBills[i] += dispensedBills[i]; // reset remaining bills to value before calculation
            }
            // if dispensing the amount is possible with the bills and coins available
        }
        else
        {
            // print the dispensed amount
            printf("Amount: ");
            for (int i = 0; i < numBills; i++)
            {
                if (dispensedBills[i] > 0)
                {
                    printf("%d P%d", dispensedBills[i], bills[i]);
                    for (int j = i + 1; j < numBills; j++)
                    {
                        if (dispensedBills[j] > 0)
                        {
                            printf(", ");
                            break;
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    printf("End\n");
    return 0;
}
