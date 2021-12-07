#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    //declare my variables, could do it all on one line but would exceed page width
    long int ccNum, ccNum2, ccNum3, ccNum4, firstSetOfDigit, secondSetOfDigits, checkSum, passedCheckSum;
    long int timesTwo, splitTimes, totalSum = 0, totalSum2 = 0, ccLength = 0;

    //This prompts user to enter their cc and copy's that original value into several similar variables
    do
    {
        ccNum = get_long("What's your card number: ");
        ccNum2 = ccNum; //do I need more variables? Idk but for now, it seems to help
        ccNum3 = ccNum;
        ccNum4 = ccNum;
        ccNum /= 10;
    }
    while (ccNum < 0);

    //This is for the sum of every other number starting with the SECOND to last number of the cc
    while (ccNum > 0)
    {
        firstSetOfDigit = ccNum % 10;
        timesTwo = firstSetOfDigit * 2;
        splitTimes = (timesTwo / 10) + (timesTwo % 10);
        totalSum += splitTimes;
        ccNum /= 100;

    }

    //This is for the sum of every other number starting with the last number of the cc
    while (ccNum2 > 0)
    {
        secondSetOfDigits = ccNum2 % 10;
        totalSum2 += secondSetOfDigits;
        ccNum2 /= 100;
    }

    //these calculations sum up the calculations from both while loops to get the sum
    checkSum = totalSum + totalSum2;
    passedCheckSum = checkSum % 10; //if check sum ends in 0 it should be divisible by 10 with no remainders

    //this gets the length of the card
    while (ccNum3 > 0)
    {
        firstSetOfDigit = ccNum3 % 10;
        ccNum3 /= 10;
        ccLength++;
    }

    //This loop gets the first two digits of the card number, simple as it is, it took some time to realize just how simple it was
    for (int p = 0; p <= (ccLength - 3); p++)
    {
        ccNum4 /= 10;
    }

    //This gives an prints an output based on the conditions below using the calculations from above
    //VISA
    if ((ccLength == 16 || ccLength == 13) && (passedCheckSum == 0) && (ccNum4 >= 40 && ccNum4 <= 49))
    {
        printf("VISA\n");
    }
    //AMEX
    else if ((ccLength == 15) && (passedCheckSum == 0) && (ccNum4 == 34 || ccNum4 == 37))
    {
        printf("AMEX\n");
    }
    //MASTERCARD
    else if ((ccLength == 16) && (passedCheckSum == 0) && (ccNum4 >= 51 && ccNum4 <= 55))
    {
        printf("MASTERCARD\n");
    }
    //INVALID
    else
    {
        printf("INVALID\n");
    }
}

