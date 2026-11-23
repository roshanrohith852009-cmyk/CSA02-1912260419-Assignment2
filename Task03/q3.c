#include <stdio.h>

enum { LIGHT = 0, FAN = 1, AC = 2, HEATER = 3, PUMP = 4 };

unsigned char switch_on(unsigned char reg, int dev) {
    return reg | (1u << dev);
}

unsigned char switch_off(unsigned char reg, int dev) {
    return reg & ~(1u << dev);
}

unsigned char toggle(unsigned char reg, int dev) {
    return reg ^ (1u << dev);
}

int is_on(unsigned char reg, int dev) {
    return (reg & (1u << dev)) != 0;
}

void show(unsigned char reg) {
    for (int bit = 7; bit >= 0; bit--)
        putchar(((reg >> bit) & 1u) ? '1' : '0');
    putchar('\n');
}

int main(void) {
    unsigned char reg = 0;

    printf("Initial: ");
    show(reg);

    reg = switch_on(reg, LIGHT);
    printf("After LIGHT ON: ");
    show(reg);

    reg = switch_on(reg, AC);
    printf("After AC ON: ");
    show(reg);

    reg = toggle(reg, FAN);
    printf("After FAN toggle: ");
    show(reg);

    reg = switch_off(reg, LIGHT);
    printf("After LIGHT OFF: ");
    show(reg);

    printf("AC is %s, PUMP is %s\n",
        is_on(reg, AC) ? "ON" : "OFF",
        is_on(reg, PUMP) ? "ON" : "OFF");

    int count = 0;
    for (int i = 0; i < 8; i++)
        count += is_on(reg, i);

    printf("Devices ON: %d\n", count);
    return 0;
}
