#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return true;
    }

    // Convert characters to lowercase before comparison
    char startChar = tolower(str[start]);
    char endChar = tolower(str[end]);

    if (startChar != endChar) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    if (isPalindrome(input, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
