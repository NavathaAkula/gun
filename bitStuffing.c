#include <stdio.h>
#include <string.h>

int main() {
    char in[100], stuffed[200], destuffed[200];
    int i, j, ones;

    printf("Enter bit string: ");
    scanf("%s", in);

    /* ---------- Bit Stuffing ---------- */
    j = ones = 0;
    for (i = 0; i < strlen(in); i++) {
        stuffed[j++] = in[i];
        if (in[i] == '1') {
            ones++;
            if (ones == 5) {          // insert '0' after 5 ones
                stuffed[j++] = '0';
                ones = 0;
            }
        } else {
            ones = 0;
        }
    }
    stuffed[j] = '\0';

    /* ---------- Bit De-stuffing ---------- */
    j = ones = 0;
    for (i = 0; i < strlen(stuffed); i++) {
        destuffed[j++] = stuffed[i];
        if (stuffed[i] == '1') {
            ones++;
            if (ones == 5 && stuffed[i+1] == '0') {
                i++;     // skip stuffed zero
                ones = 0;
            }
        } else {
            ones = 0;
        }
    }
    destuffed[j] = '\0';

    /* ---------- Output ---------- */
    printf("\nOriginal   : %s\n", in);
    printf("Stuffed    : %s\n", stuffed);
    printf("De-stuffed : %s\n", destuffed);

    return 0;
}

