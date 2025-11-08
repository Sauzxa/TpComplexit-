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


    FILE *file = fopen(argv[1], "r"); // mode read here 
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    int primes[100];
    int digit_counts[4] = {0}; // counters for 3, 6, 9, 12 digits
    int target_digits[4] = {3, 6, 9, 12};
    int total_count = 0;
    int number;

    while (total_count < 100 && fscanf(file, "%d", &number) == 1) {
        if (is_prime(number)) {
            int digits = count_digits(number);
            
            for (int i = 0; i < 4; i++) {
                if (digits == target_digits[i] && digit_counts[i] < 25) {
                    primes[total_count] = number;
                    digit_counts[i]++;
                    total_count++;
                    break;
                }
            }
        }
    }

    fclose(file);

    printf("Found %d prime numbers:\n", total_count);
    int pos = 0;
    for (int i = 0; i < 4; i++) {
        if (digit_counts[i] > 0) {
            printf("\n%d-digit primes (%d numbers):\n", target_digits[i], digit_counts[i]);
            // Print the primes for this digit count
            int printed = 0;
            for (int j = 0; j < total_count && printed < digit_counts[i]; j++) {
                if (count_digits(primes[j]) == target_digits[i]) {
                    printf("%d\n", primes[j]);
                    printed++;
                }
            }
        }
    }

    return 0;
}
