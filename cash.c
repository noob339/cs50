#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompts user for the change owed to customer and converts it to cents
    float i;

    do
    {
        i = get_float("change owed: ");
    }
    while (i <= 0);
    printf("%.2f", i);
    printf("\n");
    
    int cents = round(i * 100);
    int coin = 0;
    
    //uses the greedy algorithm for starting with quarters using while loops to check for the biggest coin possible to give the feweest possible
    //this one is for quarters
    while (cents >= 25)
    {
        cents = cents - 25;   //or cents-=25
        coin++;   //adds one coin everytime it's true
    } 
    //this is for dimes
    while (cents >= 10)
    {
        cents = cents - 10;
        coin++;
    }
    //this is for nickels
    while (cents >= 5)
    {
        cents = cents - 5;
        coin++;
    } 
    //this is for pennies
    
    //if for some reason one of the coins aren't needed, it will skip because it's too big to handle so 77 cents would be two qtrs and 2 pennies.
    while (cents >= 1)
    {
        cents = cents - 1;
        coin++;
    }
    //prints tha mount of coins
    printf("%i\n", coin);
    printf("\n");

}
