#include <stdio.h>

unsigned long checks;

int is_prime_basic(unsigned long n) {
    checks = 0;
    if (n < 2) return 0;

    for (unsigned long i = 2; i < n; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    for (int i = 0; i < 4; i++) {
        int p = is_prime_basic(numbers[i]);
        printf("%8lu %-9s divisions = %lu\n",
            numbers[i], p ? "prime" : "not prime", checks);
    }
    return 0;
}
