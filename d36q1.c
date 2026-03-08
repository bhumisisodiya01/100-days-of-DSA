/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>

int main()
{
    int queue[100];
    int front = -1, rear = -1;
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        rear = (rear + 1) % n;
        queue[rear] = x;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        if(front == -1)
            break;

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
    }

    if(front != -1)
    {
        int i = front;

        while(1)
        {
            printf("%d ", queue[i]);

            if(i == rear)
                break;

            i = (i + 1) % n;
        }
    }

    return 0;
}