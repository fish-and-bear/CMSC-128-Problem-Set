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

int main() {
    int remainingHundredBills, remainingFiftyBills, remainingTwentyBills, remainingFiveCoins, remainingOneCoins;
    int dispensedHundredBills = 0, dispensedFiftyBills = 0, dispensedTwentyBills = 0, dispensedFiveCoins = 0, dispensedOneCoins = 0;
    int amount, remainingAmount, dispensedAmount;

    // get user input
    printf("Enter the number of PHP 100 bills: ");
    scanf("%d", &remainingHundredBills);

    printf("Enter the number of PHP 50 bills: ");
    scanf("%d", &remainingFiftyBills);

    printf("Enter the number of PHP 20 bills: ");
    scanf("%d", &remainingTwentyBills);

    printf("Enter the number of PHP 5 coins: ");
    scanf("%d", &remainingFiveCoins);

    printf("Enter the number of PHP 1 coins: ");
    scanf("%d", &remainingOneCoins);

    while(1) {
        printf("Dispensing amount: ");
        scanf("%d", &amount);
        
        // if the user inputs 0, stop the program
        if (amount == 0) {
            break;
        }

        // reset dispensed amount every loop
        dispensedAmount = 0;
        dispensedHundredBills = 0;
        dispensedFiftyBills = 0;
        dispensedTwentyBills = 0; 
        dispensedFiveCoins = 0;
        dispensedOneCoins = 0;
        while (amount > 0) {
            if (remainingHundredBills > 0 && amount >= 100) {
                dispensedAmount += 100;
                amount -= 100;
                remainingHundredBills--;
                dispensedHundredBills++;
            } else if (remainingFiftyBills > 0 && amount >= 50) {
                dispensedAmount += 50;
                amount -= 50;
                remainingFiftyBills--;
                dispensedFiftyBills++;
            } else if (remainingTwentyBills > 0 && amount >= 20) {
                dispensedAmount += 20;
                amount -= 20;
                remainingTwentyBills--;
                dispensedTwentyBills++;
            } else if (remainingFiveCoins > 0 && amount >= 5) {
                dispensedAmount += 5;
                amount -= 5;
                remainingFiveCoins--;
                dispensedFiveCoins++;
            } else if (remainingOneCoins > 0 && amount >= 1) {
                dispensedAmount += 1;
                amount -= 1;
                remainingOneCoins--;
                dispensedOneCoins++;
            } else { // not enough money
                printf("Not enough money in the machine\n");
                dispensedAmount = 0;
                remainingHundredBills += dispensedHundredBills;
                remainingFiftyBills += dispensedFiftyBills;
                remainingTwentyBills += dispensedTwentyBills;
                remainingFiveCoins += dispensedFiveCoins;
                remainingOneCoins += dispensedFiveCoins;
                break;
            }
        }

        // print the dispensed amount
        if (dispensedAmount > 0) {
            printf("Amount: %d P100, %d P50, %d P20, %d P5, %d P1\n", 
                    dispensedHundredBills, dispensedFiftyBills, dispensedTwentyBills, dispensedFiveCoins, dispensedFiveCoins
            );
        }

        // update the remaining amount
        remainingAmount = amount;
    }
    printf("End\n");
    return 0;
}