
<a name="readme-top"></a>

<!-- HEADER -->
<br />
<div align="center">
  <a href="https://github.com/fish-and-bear/CMSC-128-Problem-Set">
    <img src="https://static.vecteezy.com/system/resources/previews/018/922/005/original/3d-money-safe-icon-with-transparent-background-perfect-for-template-design-ui-or-ux-and-more-free-png.png" alt="logo" width="150" height="150">
  </a>
  <h3 align="center">CMSC 128 Problem Set</h3>
  <p align="center">
    Money Dispenser Program
  </p>
</div>

<!-- BODY -->
## Description
The program acts as a dispensing machine, initially accepting 5 positive integer numbers as inputs, representing the number of PHP100 bills, PHP50 bills, PHP20 bills, PHP5 coins, and PHP1 coins, respectively. The program, then, prompts for a set of integer inputs representing the amount to be dispensed from the machine. The program aims to dispense the amount using the available bills and coins while minimizing the total number of bills or coins used.

The program will stop running only under the following conditions:

1. There are no more bills or coins left.
2. The user enters 0 to signify the program to stop.

## Usage
1. Compile the program using the following command:
    ```
    gcc -o money_dispenser money_dispenser.c
    ```
2. Run the program using the following command:
    ```
    ./money_dispenser
    ```
3. Follow the prompts on the screen to dispense money from the machine.

## Example Run
```
Enter the number of PHP100 bills: 1
Enter the number of PHP50 bills: 2
Enter the number of PHP20 bills: 5
Enter the number of PHP5 coins: 10
Enter the number of PHP1 coins: 10
Dispensing amount: 125
Amount: 1 P100, 1 P20, 1 P5
Dispensing amount: 500
Not enough money in the machine
Dispensing amount: 125
Amount: 2 P50, 1 P20, 1 P5
Dispensing amount: 10
Amount: 2 P5
Dispensing amount: 0
End
```

## Author
The program is  written by Angelica Naguio.
