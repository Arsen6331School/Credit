#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_valid(long);
long remove_last_digit(long);
int get_last_digit(long);
int int_len(long);
int add_digits(int);
int get_first_two_digits(long);
long get_valid_ccn();
long get_ccn();
bool is_visa(long);
bool is_amex(long);
bool is_mastercard(long);

int main() 
{
    long card_num = get_valid_ccn();
    bool ok = is_valid(card_num);
    if (!ok) {
        printf("INVALID\n");
        return 0;
    }
    if (is_visa(card_num))
    {
        printf("VISA\n");
    }
    else if (is_amex(card_num))
    {
        printf("AMEX\n");
    }
    else if (is_mastercard(card_num))
    {
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
}

bool is_visa(long ccn) {
    switch (get_first_two_digits(ccn))
    {
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return true;
    }
    return false;
}

bool is_amex(long ccn) {
    switch (get_first_two_digits(ccn))
    {
        case 34:
        case 37:
            return true;
    }
    return false;
}

bool is_mastercard(long ccn) {
    switch (get_first_two_digits(ccn))
    {
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            return true;
    }
    return false;
}

long get_valid_ccn()
{
    long ccn;
    // Ask for height until greater than one and less than 8
    do
    {
        ccn = get_ccn();
    }
    while (ccn < 0);
    return ccn;
}

long get_ccn()
{
    // Print prompt
    printf("Credit Card Number: ");
    char input[100];
    // Get input string
    fgets(input, 100, stdin);
    long ccn = -1;
    // Scan input string for integer
    sscanf(input, "%li", &ccn);
    return ccn;
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