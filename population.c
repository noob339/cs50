#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    //declared my variables
    int startPop, endPop, count = 0, n;
    
    // TODO: Prompt for start size
    do
    {
        startPop = get_int("Start size: ");
    }
    while (startPop < 9);
    
    // TODO: Prompt for end size
    do
    {
        endPop = get_int("End size: ");
    }
    while (endPop < startPop);

    n = startPop;
    
    // TODO: Calculate number of years until we reach threshold
    while (n < endPop)
    {
        n = n + (n / 3) - (n / 4);
        count++;
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", count);
}
