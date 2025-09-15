#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    int isPal = 1;
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            isPal = 0; break;
        }
    }
    if (isPal)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
