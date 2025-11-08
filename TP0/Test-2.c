#include <stdio.h>
#include <stdlib.h>


int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}


int count_digits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s primes10.txt\n", argv[0]);
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r"); // mode read here 
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Array to store 10 primes for each digit count (3 to 9 digits)
    int primes[70]; // 10 primes * 7 digit categories = 70
    int digit_counts[7] = {0}; // counters for 3,4,5,6,7,8,9 digits
    int total_count = 0;
    int number;

    // Read numbers and collect 10 premiers pour chaque digit length
    while (total_count < 70 && fscanf(file, "%d", &number) == 1) {
        if (is_prime(number)) {
            int digits = count_digits(number);
            if (digits >= 3 && digits <= 9) {
                int index = digits - 3; // 3 digits -> index 0, 4 digits -> index 1, etc.
                if (digit_counts[index] < 10) {
                    primes[total_count] = number;
                    digit_counts[index]++;
                    total_count++;
                }
            }
        }
    }

    fclose(file);

   
    printf("Found %d prime numbers:\n", total_count);
    int pos = 0;
    for (int d = 3; d <= 9; d++) {
        int index = d - 3;
        if (digit_counts[index] > 0) {
            printf("\n%d-digit primes (%d numbers):\n", d, digit_counts[index]);
            for (int i = 0; i < digit_counts[index]; i++) {
                printf("%d\n", primes[pos++]);
            }
        }
    }

    return 0;
}
