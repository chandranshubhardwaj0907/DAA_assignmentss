// Merge Sort (Iterative)
#include <stdlib.h>
#include <stdio.h>
void merge(int arr[], int l, int m, int r);
int min(int x, int y) { return (x < y) ? x : y; }
void mergeSort(int arr[], int n)
{
int curr_size;
int left_start;
for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
{
for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
{
int mid = min(left_start + curr_size - 1, n - 1);
int right_end = min(left_start + 2 * curr_size - 1, n - 1);
merge(arr, left_start, mid, right_end);
}
}
}
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;

Aarush Pruthi
2CO17
102203793

}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void printArray(int A[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}
int main()
{
int arr[] = {47, 75, 164, 137, 156, 108, 270, 225, 63, 159, 128, 287, 235, 205, 258, 260, 76, 126, 23, 125, 96, 274, 203, 130, 127, 70, 209, 242, 195, 222, 52, 124, 213, 140, 149, 276, 250, 192, 50, 92, 5, 148, 174, 144, 246, 14, 90, 138, 208, 107, 118, 271, 291, 85, 41, 160, 290, 12, 165, 297, 196, 216, 83, 229, 31, 6, 219, 61, 33, 34, 57, 190, 217, 16, 48, 292, 193, 228, 189, 10, 273, 268, 214, 187, 251, 17, 42, 51, 105, 129, 71, 65, 175, 3, 180, 200, 147, 221, 188, 280};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Given array is \n");
printArray(arr, n);
mergeSort(arr, n);
printf("\nSorted array is \n");
printArray(arr, n);
return 0;
}