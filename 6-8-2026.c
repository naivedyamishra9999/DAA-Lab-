//read all the elements of an array and print them
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
//find the sum of all the elements of an array
int sumArray(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}
//find the maximum element in an array
int maxArray(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
//reverse the elements of an array
void reverseArray(int arr[], int n) {
    for(int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}