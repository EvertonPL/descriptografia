#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef REMOVE_H
#define REMOVE_H

int func_val(int x, int b) {
    double result = 186.752 + (-148.235 + b) * x + 34.5049 * pow(x, 2) + (-3.5091) * pow(x, 3) + 0.183166 * pow(x, 4) + (-0.00513554) * pow(x, 5) + 0.0000735464 * pow(x, 6) + (-4.22038e-7) * pow(x, 7);
    return round(result);
}

#endif /* REMOVE_H */

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        int b;
        scanf("%d", &b);

        char hex_string[101];
        scanf("%100s", hex_string);

        char decoded_message[51];
        int j = 0;

        for (int x = 1; x <= strlen(hex_string) / 2; x++) {
            char hex_byte[3];
            strncpy(hex_byte, hex_string + (x - 1) * 2, 2);
            hex_byte[2] = '\0';

            int decimal_value = strtol(hex_byte, NULL, 16);

            if (func_val(x, b) != 0) {
                decoded_message[j++] = (char) decimal_value;
            }
        }

        decoded_message[j] = '\0';

        printf("%s\n", decoded_message);
    }

    return 0;
}