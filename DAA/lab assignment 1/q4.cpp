// Merge Sort (Recursive)
#include <stdlib.h>
#include <stdio.h>
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
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
}
else
{
arr[k] = R[j];
j++;

Aarush Pruthi
2CO17
102203793

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
int arr[] = {153, 4, 81, 239, 244, 108, 90, 136, 15, 169, 120, 39, 216, 45, 263, 135, 199, 236, 87, 245, 141, 9, 179, 197, 213, 214, 206, 138, 282, 228, 143, 2, 298, 43, 115, 257, 13, 266, 31, 144, 188, 52, 217, 28, 104, 155, 278, 181, 51, 7, 5, 118, 164, 156, 20, 102, 255, 158, 112, 201, 190, 249, 258, 209, 237, 256, 36, 202, 121, 53, 77, 223, 243, 27, 165, 22, 60, 56, 186, 80, 250, 173, 265, 246, 192, 276, 178, 96, 33, 50, 227, 207, 259, 14, 75, 166, 131, 284, 275, 159};
int arr_size = sizeof(arr) / sizeof(arr[0]);
printf("Given array is \n");
printArray(arr, arr_size);
mergeSort(arr, 0, arr_size - 1);
printf("\nSorted array is \n");
printArray(arr, arr_size);
return 0;
}