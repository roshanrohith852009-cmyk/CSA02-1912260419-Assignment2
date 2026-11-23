#include <stdio.h>

unsigned long checks;

int is_prime(unsigned long n) {
    checks = 0;
    if (n < 2) return 0;

    unsigned long i = 2;

    do {
        if (i > n / i) break;
        checks++;
        if (n % i == 0) return 0;
        i++;
    } while (1);

    return 1;
}

int main(void) {
    unsigned long numbers[] = {2, 3, 97, 100, 7919, 1000003};

    for (int i = 0; i < 6; i++) {
        int p = is_prime(numbers[i]);
        printf("%8lu %-9s divisions = %lu\n",
            numbers[i], p ? "prime" : "not prime", checks);
    }
    return 0;
}
