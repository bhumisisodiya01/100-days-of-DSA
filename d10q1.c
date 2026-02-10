/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;
    int flag = 1;

    printf("Enter a string: ");
    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
