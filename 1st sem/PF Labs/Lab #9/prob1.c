#include <stdio.h>
#include <string.h>

void CountFrequency(int size);
int main()
{
    int arr_size = 5;
    CountFrequency(arr_size);


}

void CountFrequency(int size)
{
    int freq[11] = {0};
    int arr[] = {2,3,5,6,0};

    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= size; i++)
        printf("%d : %d\n", i, freq[i]);
}
