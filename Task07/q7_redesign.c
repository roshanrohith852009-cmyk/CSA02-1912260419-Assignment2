#include <stdio.h>

unsigned long original_checks = 0;
unsigned long redesigned_checks = 0;

int original_prime(unsigned long n) {
    original_checks = 0;
    if (n < 2) return 0;

    for (unsigned long i = 2; i <= n / i; i++) {
        original_checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

/* Redesigned algorithm: check 2, then skip all even divisors. */
int redesigned_prime(unsigned long n) {
    redesigned_checks = 0;
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) {
        redesigned_checks++;
        return 0;
    }

    redesigned_checks++;

    for (unsigned long i = 3; i <= n / i; i += 2) {
        redesigned_checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    printf("ORIGINAL VS REDESIGNED PRIME TEST\n\n");

    for (int i = 0; i < 4; i++) {
        int a = original_prime(numbers[i]);
        int b = redesigned_prime(numbers[i]);

        printf("Number: %lu\n", numbers[i]);
        printf("Original: %s, checks = %lu\n",
            a ? "Prime" : "Not prime", original_checks);
        printf("Redesigned: %s, checks = %lu\n",
            b ? "Prime" : "Not prime", redesigned_checks);

        if (original_checks > 0) {
            double improvement =
                100.0 * (original_checks - redesigned_checks)
                / original_checks;
            printf("Reduction: %.2f%%\n\n", improvement);
        }
    }

    return 0;
}
