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
int Max_vote;
string Win_name;

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
        if (!vote(name))
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
   for(int i = 0 ; i < candidate_count; i++)

      if (strcmp(candidates[i].name, name) == 0)
      {
          candidates[i].votes = candidates[i].votes + 1;
          return true;
      }
       return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
// Iterate throught the entire array  creating a variable min to store the index of the first element in my array
     for(int i = 0 ; i < candidate_count -  1; i++)
     {
      int min = i;
// In the outter loop, interate throught my element and fiding the smallest element in they array and storing it's index in min
      for (int j = min + 1;  j < candidate_count; j++)
          if(candidates[j].votes < candidates[min].votes)
           {
               min = j;
           }
// creating a vairable temp and temp_2 and using them to swaps the smallest variable to their appropriate possition in my sorted array
         int temp = candidates[i].votes;
         string temp_2 = candidates[i].name;
         candidates[i].votes = candidates[min].votes;
         candidates[i].name = candidates[min].name;
         candidates[min].votes = temp;
         candidates[min].name = temp_2;
     }
// iterate through my sorted array and comparing all the element in the array, which should be the largest element and if any element
// in the array is equal to the last element, i print the name of tha candidate
int max = candidates[candidate_count - 1].votes;

  for(int i = 0 ; i <= candidate_count - 1 ; i++)
  {
   if(candidates[i].votes == max)
         {
          printf("%s\n", candidates[i].name);
         }
  }
    return;

}

