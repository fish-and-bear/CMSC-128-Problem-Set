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
#include <string.h>

#define NUM_DENOMINATIONS 5 // denominations are bills and coins collectively

void clearInputBuffer() {   // clear input buffer upon invalid input
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void getUserInput(int denominations[], int remainingDenominations[]) {
    for (int i = 0; i < NUM_DENOMINATIONS; i++) {
        printf("Enter the number of PHP %d %s: ", denominations[i], (i < 3) ? "bills" : "coins");

        while (1) {
            if (scanf("%d", &remainingDenominations[i]) == 1) {
                if (remainingDenominations[i] >= 0) {
                    clearInputBuffer();
                    break;
                } else {    // if input is a negative integer
                    printf("Invalid input. Please enter a non-negative integer.\n");
                    printf("Enter the number of PHP %d %s: ", denominations[i], (i < 3) ? "bills" : "coins");
                    clearInputBuffer();
                }
            } else {    // if input is a non-integer
                printf("Invalid input. Please enter a valid integer.\n");
                printf("Enter the number of PHP %d %s: ", denominations[i], (i < 3) ? "bills" : "coins");
                clearInputBuffer();
            }
        }
    }
}

// check if there is no more money in the machine
int checkRemainingDenominations(int remainingDenominations[]) {
    for (int i = 0; i < NUM_DENOMINATIONS; i++) {
        if (remainingDenominations[i] != 0) return 1;
    }
    return 0;
}

void dispenseAmount(int denominations[], int remainingDenominations[], int amount) {
    // reset dispensed amount every loop
    int dispensedDenominations[NUM_DENOMINATIONS] = {0};
    int dispensedAmount = 0;

    // calculate minimum possible dispensed bills
    for (int i = 0; i < NUM_DENOMINATIONS; i++) {
        while (remainingDenominations[i] > 0 && amount >= denominations[i]) {
            dispensedAmount += denominations[i];
            amount -= denominations[i];
            remainingDenominations[i]--;
            dispensedDenominations[i]++;
        }
    }

    // if money in the machine is not enough to dispense amount
    if (amount > 0) {
        printf("Not enough money in the machine\n");
        for (int i = 0; i < NUM_DENOMINATIONS; i++) {
            remainingDenominations[i] += dispensedDenominations[i];  // reset remaining bills to value before calculation
        }
    // if dispensing the amount is possible with the bills and coins available
    } else {
        printf("Bills and/or coins dispensed: ");  // print the dispensed amount
        for (int i = 0; i < NUM_DENOMINATIONS; i++) {
            if (dispensedDenominations[i] > 0) {
                printf("%d PHP %d", dispensedDenominations[i], denominations[i]);

                for (int j = i + 1; j < NUM_DENOMINATIONS; j++) {
                    if (dispensedDenominations[j] > 0) {
                        printf(", ");
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int denominations[NUM_DENOMINATIONS] = {100, 50, 20, 5, 1};
    int remainingDenominations[NUM_DENOMINATIONS] = {0};

    getUserInput(denominations, remainingDenominations);

    while (1) {
        if (!checkRemainingDenominations(remainingDenominations)) {
            printf("No more money left in the machine.\n");
            break;
        }

        printf("Enter the amount of money (in PHP) that you want to dispense: PHP ");
        int amount;

        while (1) {
            if (scanf("%d", &amount) == 1 && amount >= 0) {
                clearInputBuffer();
                break;
            } else {
                printf("Invalid input. Please enter a valid non-negative integer.\n");
                printf("Enter the amount of money (in PHP) that you want to dispense: PHP ");
                clearInputBuffer();
            }
        }

        if (amount == 0) {
            break;
        }

        dispenseAmount(denominations, remainingDenominations, amount);
    }

    printf("Program terminated.\n");
    return 0;
}