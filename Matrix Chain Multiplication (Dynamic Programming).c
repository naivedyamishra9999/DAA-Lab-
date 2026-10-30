
#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, k, L;
    int p[20];
    int dp[20][20];
    int split[20][20];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array:\n");

    for(i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for(i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for(L = 2; L <= n; L++) {
        for(i = 1; i <= n-L+1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;

            for(k = i; k < j; k++) {
                int cost = dp[i][k] +
                           dp[k+1][j] +
                           p[i-1] * p[k] * p[j];

                if(cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum multiplication cost: %d\n",
           dp[1][n]);

    printf("DP Table:\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(j < i)
                printf("-\t");
            else
                printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
