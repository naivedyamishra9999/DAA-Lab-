
#include <stdio.h>

int main() {
    int n, i, j, capacity;
    float weight[20], profit[20], ratio[20];
    float totalProfit = 0;
    float temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");

    for(i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort according to profit/weight ratio
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(ratio[j] < ratio[j+1]) {

                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        }
    }

    printf("\nMaximum Greedy Profit = %.2f\n",
           totalProfit);

    return 0;
}
