#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int greedy_change(double dollars);

int main() 
{
        double change;
        printf("What's the total change? ");
        scanf("%lf", &change);
        greedy_change(change);
        return 0;
}

int greedy_change(double dollars)
{
        int remaining_change = dollars * 100;
        int coins[4] = {25, 10, 5, 1};
        int times_used[4] = {0, 0, 0, 0};
        int i = 0;
        printf("use coins:\n");
        while (remaining_change > 0)
        {
                if (coins[i] > remaining_change) 
                {
                        i++;
                        continue;
                }
                if (remaining_change == 0 && i > 3) break;
                remaining_change -=  coins[i];
                times_used[i]++;
        }
        for (i = 0; i < 4; i++)
        {
                if (times_used[i] == 0) continue;
                printf("%d cent(s) %d times\n", coins[i], times_used[i]);
        }
        return 0;
}
