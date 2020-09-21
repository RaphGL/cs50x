// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdint.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 20;
static int number_of_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *curr = table[index];
    while (curr->next != NULL)
    {
        if(strcasecmp(word, curr->word) == 0) return true;
        curr = curr->next;
    }
    return false;
}

// Hashes word to a number
// Jenkins One At A Time Hash from wikipedia
unsigned int hash(const char *word)
{
    uint32_t nhash, i;
    for(nhash = i = 0; i < N; ++i)
    {
        nhash += word[i];
        nhash += (nhash << 10);
        nhash ^= (nhash >> 6);
    }
    nhash += (nhash << 3);
    nhash ^= (nhash >> 11);
    nhash += (nhash << 15);
    printf("%d", nhash);
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen("./dictionaries/small", "r");
    char str[LENGTH + 1];
    for (int i = 0; i < N; i++) table[i] = NULL;
    while (fscanf(dict, "%s", str) != EOF)
    {
        int index = hash(str);
        node *item = malloc(sizeof(node));
        // stops loading if there's no memory available
        if (item == NULL) return false;
        strcpy(item->word, str);
        item->next = NULL;
        if (table[index] == NULL)
        {
            table[index] = item;
            number_of_words++;
        printf("%s", item->word);
        } else {
            node *curr = table[index];
            // loops until it finds a null curr->next assigns curr to it
            for (; curr->next != NULL; curr = curr->next);
            curr->next = item;
            number_of_words++;
        }
        free(item);
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return number_of_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return true;
}
