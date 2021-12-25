#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))            //if NOT! false = true
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool flag = false;
    
    int i = 0;
    
    while (i < candidate_count)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            flag = true;
            candidates[i].votes++;
        }
        i++;
    }

    return flag;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Linear search for highest value,
    //if highest value comes up multiple times
    //then get who it is and print them
    
    int max = 0;
    int pos = -1;
    int pos2 = -1;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
            pos = i;
        }
    }
    
    //here we verify if the max is repeated double, if it is it will print out each instance
    for (int i = 0; i < 5; i++)
    {
        if (max == candidates[i].votes)
        {
            pos2 = i;
            printf("%s\n", candidates[pos2].name);
        }
    }
    
    return;
}

//this sadly did not work but I will keep it to remind me of my shortcomings and how I overcame them. 
//the reason it did not work despite going over all the candidates and accurately giving them a vote was because depending on the order...
//in the last iteration of the loop it always checked the last candidate against the vote, lets say the candidates in order are Alice [0], Bob[1] and Charlie [2]
//if I vote for Bob, it would run the vote through first alice, the bob where it will match as true but since it loops through all candidates,
//it then checks for charlie which will return false. Many ways to solve this, 
//1. set the flag to false when declaring the bool variable and its only true once it hits its mark
//2. using or || instead of loops
//3. setting a break to the loop once it finds the vote


/*
for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            flag = false; //I should have put true
            candidates[i].votes++;
        }
        else
        {
            //when it's called above in line 56, it essentially asking if not false, which means if true
            //vice versa if its not true then it's false 
            flag = true; //I should have put false but it does is reverse those getting an invalid. 
        }
    }
*/
