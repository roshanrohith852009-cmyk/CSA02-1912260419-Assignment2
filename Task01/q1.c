#include <stdio.h>

int main(void) {
    double bills[][2] = {{100, 2}, {500, 3}, {1200, 1}};
    int senior_values[] = {1, 0, 1};

    printf("JAN AUSHADHI BILLING\n\n");

    for (int i = 0; i < 3; i++) {
        double price = bills[i][0];
        double qty = bills[i][1];
        int senior = senior_values[i];

        double gross = price * qty;
        double buggy = price * qty - price * qty * 15 / 100 * senior
                       + price * qty * 5 / 100;
        double net_buggy = buggy > 1000 ? buggy - 50 : buggy;

        double discount = senior ? gross * 0.15 : 0;
        double taxable = gross - discount;
        double tax = taxable * 0.05;
        double correct = taxable + tax;
        double final_amount = correct > 1000 ? correct - 50 : correct;

        printf("Bill %d\n", i + 1);
        printf("Gross: %.2f\n", gross);
        printf("Buggy total: %.2f\n", buggy);
        printf("Buggy net: %.2f\n", net_buggy);
        printf("Correct discount: %.2f\n", discount);
        printf("Correct GST: %.2f\n", tax);
        printf("Correct net: %.2f\n\n", final_amount);
    }

    printf("count++ + 1 is undefined behaviour because count is\n");
    printf("modified and read without proper sequencing.\n");
    return 0;
}
