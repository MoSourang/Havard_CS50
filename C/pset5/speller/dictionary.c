// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

  // Represents a node in a hash table
    typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    }
    node;
  // Variable Declarations!!

    const unsigned int N = 5381;
    int num_word;
    char temp_word[LENGTH + 1];
    char new_word[LENGTH + 1];
    // Hash table
    node *table[N];
    node *temp;
    node *tracker;
    node *n ;
    FILE* DIC;
  // Returns true if word is in dictionary else false
  bool check(const char *word)
  {
   // lower case of all the letter
    for(int i = 0 ; i < (strlen(word) + 1); i++)
     {
        new_word[i] = tolower(word[i]);
     }
    // accesing hash value of the word for spell check and creating a pointer variable to iterate throught the linked list
    int link_index =  hash(new_word);
    struct node *find =  table[link_index];

    // iterating through the linked list to determine if word is in dictionary
    while(find != NULL)
    {
        if(strcasecmp(new_word , find->word) == 0 )
        {
            return true;
        }
        else
        {
            find = find -> next;
        }
    }
        return false;
  }
   // Hashes word to a number by - Dan bernstein
    unsigned int hash(const char *word)
    {
        unsigned int hash = 5381;
        int c;
        while ((c = *word++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash % N;
    }
  // Loads dictionary into memory, returning true if successful else false
  bool load(const char *dictionary)
    {
    // Open the dictrionary file
        DIC = fopen(dictionary, "r");
         if (DIC == NULL)
         {
            return 1;
         }
    // Iterate throught the index in my hash table and setting linked list heads to NULL

    // Looping through each word in the dictionary until i reach the end of the flle
        while(fscanf(DIC , "%s", temp_word) != EOF)
        {
    // Create a new node
          n =  malloc(sizeof(node));
            if(n == NULL)
          {
              return 1;
          }
            // copy my current tempory word into the node
          {
               strcpy(n -> word, temp_word);
               n -> next = NULL;
               num_word++;
          }
    // Hash the current word and storing the index into a variable link_index
         int link_index = hash(n -> word);
    // insert first word into the begning of the linked list
         if(table[link_index] == NULL)
          {
            table[link_index] = n;
          }
    // if there is already a word in the begining of the link list moved new node to be at the begining of the linked list
         else
          {
            n -> next =  table[link_index];
            table[link_index] = n;
          }
        }
     return true;
    }
    // Returns number of words in dictionary if loaded else 0 if not yet loaded
    unsigned int size(void)
    {
        return num_word;
    }
   // Unloads dictionary from memory, returning true if successful else false
    bool unload(void)
    {
   // variable tracking the linked list that i am iterating throught
        for(int i = 0 ; i < N  ; i++)
          {
            tracker = table[i];
            while(tracker != NULL)
            {
                 temp = tracker;
                 tracker = tracker -> next;
                 free(temp);
            }
          }
        fclose(DIC);
        return true;


   }