/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>

int main() {
    int p, q;
    
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);
    
    int a[p];
    printf("Enter arrival times for server log 1:\n");
    for(int i = 0; i < p; i++)
        scanf("%d", &a[i]);
    
    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);
    
    int b[q];
    printf("Enter arrival times for server log 2:\n");
    for(int i = 0; i < q; i++)
        scanf("%d", &b[i]);
    
    int i = 0, j = 0;
    
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }
    
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }
    
    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }
    
    return 0;
}
