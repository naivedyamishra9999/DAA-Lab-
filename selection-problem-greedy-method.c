#include <stdio.h>

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int S[] = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12};
    int F[] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};

    int n = 10;
    int lastFinish = 0;

    printf("Selected Activities:\n");

    for (int i = 0; i < n; i++)
    {
        if (S[i] >= lastFinish)
        {
            printf("A%d (%d, %d)\n", A[i], S[i], F[i]);
            lastFinish = F[i];
        }
    }

    return 0;
}