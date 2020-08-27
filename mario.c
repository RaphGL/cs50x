#include <stdio.h>
#include <stdlib.h>

void pyramid();
int check_positive(int n);

int main()
{
        pyramid();
        return 0;
}

void pyramid() 
{
        int height;
        printf("Height: ");
        scanf("%d", &height);
        char *hash = (char *)malloc(sizeof(char) * height);
        hash[0] = '#';
        int space = height - 1;
        for (int i = 1; i < height; i++)
        {
                for (int j = 0; j < space; j++)
                {
                        printf(" ");
                }
                printf("%s", hash);
                printf(" ");
                printf("%s", hash);
                hash[i] = '#';
                space--;
                printf("\n");
        }
        free(hash);
}
