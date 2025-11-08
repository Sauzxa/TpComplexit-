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

   
    int primes[100];
    int count = 0;
    int number;

    // Read numbers from file and keep only primes in range [1000, 1000000]
    while (count < 100 && fscanf(file, "%d", &number) == 1) {
        if (number >= 1000 && number <= 1000000 && is_prime(number)) {
            primes[count] = number;
            count++;
        }
    }

    fclose(file);

    // Print all prime numbers ta3 array
    printf("Found %d prime numbers in range [1000, 1000000]:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d\n", primes[i]);
    }

    return 0;
}
