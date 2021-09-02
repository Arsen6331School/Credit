#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_valid(long);
long remove_last_digit(long);
int get_last_digit(long);
int int_len(long);
int add_digits(int);
int get_first_two_digits(long);

int main() 
{
    long card_num = 6011111111111117;
    bool ok = is_valid(card_num);
    if (!ok) {
        printf("INVALID\n");
        return 0;
    }
    switch (int_len(card_num))
    {
    case 15:
        printf("AMEX\n");
        break;
    case 13:
        printf("VISA\n");
        break;
    case 16:
        switch (get_first_two_digits(card_num))
        {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            default:
                printf("VISA\n");
        }
        break;
    }
}

bool is_valid(long ccn)
{
    int len_ccn = int_len(ccn);
    long ccn_work = ccn;
    int sum_one = 0;
    int sum_two = 0;
    for (int i = 0; i < len_ccn; i++)
    {
        sum_one += add_digits(get_last_digit(ccn_work));
        ccn_work = remove_last_digit(ccn_work);
        sum_two += add_digits(get_last_digit(ccn_work)*2);
        ccn_work = remove_last_digit(ccn_work);
    }
    return ((sum_one + sum_two) % 10 == 0);
}

int add_digits(int orig)
{
    int len_orig = int_len(orig);
    int sum = 0;
    long work = orig;
    for (int i = 0; i < len_orig; i++)
    {
        sum += get_last_digit(work);
        work = remove_last_digit(work);

    }
    return sum;
}

long remove_last_digit(long orig)
{
    return orig/10;
}

int get_last_digit(long whole)
{
    return whole%10;
}

int int_len(long num)
{
    return (num == 0) ? 1 : log10(num) + 1;
}

int get_first_two_digits(long whole) 
{
    long work = whole;
    while (work >= 100) 
    {
        work /= 10;
    }
    return work;
}