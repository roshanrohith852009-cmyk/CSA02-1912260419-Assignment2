#include <stdio.h>
#include <math.h>

int main(void) {
    double balance = 10000.00;
    double rate = 0.02;
    double repayment = 2000.00;
    double total_interest = 0.0;
    int month = 0;
    const int LIMIT = 360;

    printf("MONTHLY LOAN REPAYMENT SCHEDULE\n");
    printf("Initial loan: Rs. %.2f\n\n", balance);
    printf("Month\tOpening\t\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.005) {
        if (month >= LIMIT) {
            printf("Safety limit reached. Loan not fully repaid.\n");
            break;
        }

        double opening = balance;
        double interest = round(balance * rate * 100) / 100;
        balance += interest;
        total_interest += interest;

        if (repayment <= interest) {
            printf("Repayment is insufficient to reduce the loan.\n");
            break;
        }

        double payment = repayment;
        if (payment > balance)
            payment = balance;

        balance = round((balance - payment) * 100) / 100;
        month++;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
            month, opening, interest, payment, balance);
    }

    if (balance <= 0.005) {
        printf("\nLoan fully repaid!\n");
        printf("Total months: %d\n", month);
        printf("Total interest: Rs. %.2f\n", total_interest);
    }

    return 0;
}
