#include <stdio.h>

char grade(int marks) {
    if (marks < 0 || marks > 100) return '?';
    if (marks >= 90) return 'S';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}

int main(void) {
    int marks[] = {100, 90, 89, 84, 80, 79, 75, 70,
                   69, 60, 59, 50, 49, 0, -1, 101};
    int n = sizeof(marks) / sizeof(marks[0]);

    printf("ELSE-IF GRADE SYSTEM\n");
    for (int i = 0; i < n; i++)
        printf("%d : %c\n", marks[i], grade(marks[i]));

    return 0;
}
