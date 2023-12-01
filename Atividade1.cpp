#include <stdio.h>
#include <string.h>

int romanToDecimal(char romanNumeral) {
    switch (romanNumeral) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int isValidRomanNumeral(char *roman) {
    for (int i = 0; i < strlen(roman); i++) {
        if (romanToDecimal(roman[i]) == 0) {
            return 0; 
        }
    }
    return 1; 
}

int romanToDecimalConverter(char *roman) {
    if (!isValidRomanNumeral(roman)) {
        return -1; 
    }

    int result = 0;
    int prevValue = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int value = romanToDecimal(roman[i]);

        if (value < prevValue) {
            result -= value;
        } else {
            result += value;
        }

        prevValue = value;
    }

    return result;
}

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    char romanNumeral[10]; 


    memset(romanNumeral, 0, sizeof(romanNumeral));

    //printf("Digite um número romano (I, V, X, L, C, D, M): ");
    scanf("%s", romanNumeral);

    int decimalValue = romanToDecimalConverter(romanNumeral);
    if (decimalValue == -1) {
        printf("Numero romano invalido.\n");
        return 1;
    }

    printf("%s na base 2: ", romanNumeral);
    decimalToBinary(decimalValue);
    printf("\n%s na base 10: %d\n", romanNumeral, decimalValue);
    printf("%s na base 16: %x\n", romanNumeral, decimalValue);

    return 0;
}

