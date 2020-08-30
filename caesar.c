#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(int key, char *argv[], int argc);

int main(int argc, char *argv[]) 
{
        int key = atoi(argv[1]);
        encrypt(key, argv, argc);
        return 0;
}

void encrypt(int key, char *argv[], int argc)
{
        char abc[] = "abcdefghijklmnoqrstuvwxyz";
        int j = 0;
        int letter;
        for (int i = 2; i < argc; i++)
        {
                #define CURR argv[i][j]
                while (true)
                {
                        if (isupper(CURR)) 
                        {
                                letter = ((int)(tolower(CURR)) + key - 97) % 26;
                                printf("%c", toupper(abc[letter]));
                        } 
                        else if (islower(CURR))
                        {
                                letter = ((int)CURR + key - 97) % 26;
                                printf("%c", abc[letter]);
                        } 
                        j++;
                        if (CURR == NULL)
                        {
                                /*atoi(&argv[i][j]) + key) % 26*/
                                j = 0;
                                break;
                        }
                }
                printf(" ");
        }
        printf("\n");
}
