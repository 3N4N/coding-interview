#include "int-to-roman.h"

#include <iostream>
#include <cstring>

using namespace std;

const char *numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L",
    "XL", "X", "IX", "V", "IV", "I"};
const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10,
    9, 5, 4, 1};

const char* int_to_roman(int val)
{
    if (val > 3999 || val < 1)
        return "ERROR: Cannot process a number of more than 3999.";

    char* numeral = new char[10];

    int i = 0;
    int j = 0;
    while (val > 0) {
        if (val - values[i] >= 0) {
            for (int m = 0; m < strlen(numerals[i]); m++) {
                numeral[j++] = numerals[i][m];
            }
            val -= values[i];
        } else {
            i++;
        }
    }
    numeral[j] = '\0';

    return numeral;
}
