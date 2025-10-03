#include <stdio.h>

int main() {
    long long cc_number; 
    int digits = 0, sum = 0, is_second = 0;

    
    printf("Number: ");
    scanf("%lld", &cc_number);

    // Calculate number of digits and utilize Luhn's algorithm
    long long temp = cc_number;
    while (temp > 0) {
        int digit = temp % 10; 
        if (is_second) {
            digit *= 2; // Double every second digit
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10); // Sum digits if > 9
            }
        }
        sum += digit;
        is_second = !is_second; 
        temp /= 10;
        digits++;
    }

    // Check card type and validity
    if (sum % 10 == 0) {
        if ((digits == 15) && (cc_number / 10000000000000 == 34 || cc_number / 10000000000000 == 37)) {
            printf("AMEX\n");
        } else if ((digits == 13 || digits == 16) && (cc_number / 1000000000000000 == 4 || cc_number / 1000000000000 == 4)) {
            printf("VISA\n");
        } else if (digits == 16 && (cc_number / 1000000000000000 >= 51 && cc_number / 1000000000000000 <= 55)) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}
