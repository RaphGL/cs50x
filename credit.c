#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_card_valid(long long n);
void identify_card(long long card_number);

int main()
{
        long long card_number;
        printf("Card Number: ");
        scanf("%lld", &card_number);
        identify_card(card_number);
        return 0;
}

bool is_card_valid(long long n)
{
        // find number size
        long long num_size = 0, num = n;
        int sum = 0;
        while (num != 0)
        {
                num /= 10;
                num_size++;
        }
        double current = n / 10.0;
        int currint = (int)fmod(current, 10.0);
        // iterates over digits in number starting from second to last digit, multiplies them by two and gets the total sum
        for(int i = num_size; i > 0; i--) 
        {
                if (currint != 0)
                {
                        currint *= 2;
                        if (currint > 9)
                        {
                                sum += currint % 10;
                                while (currint > 0)
                                {
                                        currint /= 10;
                                        currint %= 10;
                                        sum += currint;
                                }
                        } else {
                                sum += currint;
                        }
                }
                current /= 100;
                currint = (int)fmod(current, 10.0);
        }
        current = n;
        currint = (int)fmod(current, 10.0);
        // iterates over digits starting from last digit and gets the total sum
         for(int i = num_size; i > 0; i--) 
        {
                sum += currint;
                current /= 100;
                currint = (int)fmod(current, 10.0);
        }
        if (sum % 10 == 0)
        {
                return true;
        } else {
                return false;
        }
}

void identify_card(long long card_number)
{
        int num_size = 0;
        long long num = card_number;
        while (num != 0)
        {
                num /= 10;
                num_size++;
        }
        int initials = card_number / pow(10, num_size - 2);
        if (is_card_valid(card_number))
        {
                if (num_size == 15 && (initials == 34 || initials == 37))
                {
                        puts("AMEX");
                }
                else if (num_size == 16 && (initials == 51 || initials == 52 || initials == 53 || initials == 54 || initials == 55)) 
                {
                        puts("MASTERCARD");
                }
                else if ((num_size == 13 || num_size == 16) && initials / 10 == 4)
                {
                        puts("VISA");
                }
        } else {
                puts("INVALID");
        }
}
