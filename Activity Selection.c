
#include <stdio.h>

int main() {
    int n, i, j, temp;
    int start[100], finish[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter start and finish time of activity %d: ", i+1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities by finish time
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(finish[j] > finish[j+1]) {
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    printf("\nSelected Activities:\n");

    int lastFinish = -1;

    for(i = 0; i < n; i++) {
        if(start[i] >= lastFinish) {
            printf("Activity %d (%d - %d)\n",
                   i+1, start[i], finish[i]);

            lastFinish = finish[i];
        }
    }

    return 0;
}
