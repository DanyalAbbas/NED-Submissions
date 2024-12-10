#include <stdio.h>


void sort(int cards[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cards[i] > cards[j]) {
                // Swap cards
                int temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[9] = {54,65,65,2,4,57,4,55,4};
    sort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d, ", arr[i]);
    }
}