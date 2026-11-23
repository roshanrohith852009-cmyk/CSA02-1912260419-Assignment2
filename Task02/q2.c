#include <stdio.h>

int calls = 0;
int audit_calls = 0;

int verify_card(int disability) {
    calls++;
    audit_calls++;
    return disability;
}

int main(void) {
    int senior[4] = {1, 0, 1, 0};
    int eligible[4] = {1, 1, 0, 0};
    int disability[4] = {0, 1, 0, 1};

    int first_order = 0, second_order = 0;
    int passengers = 1000;

    for (int i = 0; i < passengers; i++) {
        int s = senior[i % 4];
        int e = eligible[i % 4];
        int d = disability[i % 4];

        calls = 0;
        int result1 = (s && e) || verify_card(d);
        first_order += calls;

        calls = 0;
        int result2 = verify_card(d) || (s && e);
        second_order += calls;

        if (result1 != result2)
            printf("Logic mismatch at passenger %d\n", i + 1);
    }

    printf("Passengers checked: %d\n", passengers);
    printf("Calls, senior condition first: %d\n", first_order);
    printf("Calls, verification first: %d\n", second_order);

    int a = 0, b = 1;
    calls = 0;
    int x = a && verify_card(b);
    printf("\n&& calls when first operand is false: %d\n", calls);

    calls = 0;
    int y = b || verify_card(b);
    printf("|| calls when first operand is true: %d\n", calls);

    calls = 0;
    int z = a & verify_card(b);
    printf("& calls when first operand is false: %d\n", calls);

    (void)x; (void)y; (void)z;
    return 0;
}
