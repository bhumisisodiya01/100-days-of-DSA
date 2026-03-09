/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int pq[1000];
    int size = 0;

    for(int i=0;i<n;i++)
    {
        char op[10];
        scanf("%s",op);

        if(op[0]=='i')
        {
            int x;
            scanf("%d",&x);

            int j=size-1;

            while(j>=0 && pq[j]>x)
            {
                pq[j+1]=pq[j];
                j--;
            }

            pq[j+1]=x;
            size++;
        }

        else if(op[0]=='d')
        {
            if(size==0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",pq[0]);

                for(int j=1;j<size;j++)
                    pq[j-1]=pq[j];

                size--;
            }
        }

        else if(op[0]=='p')
        {
            if(size==0)
                printf("-1\n");
            else
                printf("%d\n",pq[0]);
        }
    }

    return 0;
}