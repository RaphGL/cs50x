#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// max number of candidates
#define MAX 9

typedef struct 
{
        int votes;
        char *name[20];
} candidate_t;

candidate_t candidates[MAX];
int candidate_count;

bool vote(char name[]);
void print_winner(void);

int main(int argc, char *argv[])
{
        if (argc < 2)
        {
                printf("Usage: plurality [candidate ...]\n");
                return 1;
        }

        candidate_count = argc - 1;
        if (candidate_count > MAX)
        {
                printf("Maximum number of candidates is %d\n", MAX);
                return 2;
        }
        for (int i = 0; i < candidate_count; i++)
        {
                *candidates[i].name = argv[i + 1];
                candidates[i].votes = 0;
        }
        int voter_count;
        printf("Number of voters: ");
        scanf("%d", &voter_count);

        char name[20];
        for (int i = 0; i < voter_count; i++)
        {
                printf("Vote: ");
                scanf("%s", name);
                if (!vote(name))
                {
                        printf("Invalid vote.\n");
                }
        }
        print_winner();
        return 0;
}

bool vote(char name[])
{
        // increment candidate's vote by one if it matches user's input
        for (int i = 0; i < MAX; i++)
        {
                if (*candidates[i].name == NULL) break;
                if (strcmp(*candidates[i].name, name) == 0)
                {
                        candidates[i].votes++;
                        return true;
                }
        }
        return false;
}

void print_winner(void)
{
        candidate_t hold[2];
        hold[0] = candidates[0];
        for (int i = 1; i < MAX; i++)
        {
                if (candidates[i].votes > hold[0].votes)
                {
                        hold[0] = candidates[i];
                }
                else if (candidates[i].votes == hold[0].votes) 
                {
                        hold[1] = candidates[i];
                }
        }
        puts(*hold[0].name);
        puts(*hold[1].name);
}
