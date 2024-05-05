// Binary search (Iterative)
#include <stdio.h>
int binary_search_iterative(int arr[], int target, int size)
{
int low = 0, high = size - 1; while (low <= high)
{
int mid = (low + high) / 2;
if (arr[mid] == target)
{
return mid;
}
else if (arr[mid] < target)
{
low = mid + 1;
}
else
{
high = mid - 1;
}
}
return -1;
}
int main()
{
int arr[] = {1, 4, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 22, 23, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 41, 42, 44, 47, 48, 51, 52, 54, 56, 57, 60, 61, 62, 65, 66, 67, 68, 70, 71, 72, 74, 76, 78, 79, 82, 83, 84, 85, 88, 91, 92, 95, 97, 99, 101, 104, 105, 107, 108, 109, 111, 112, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 127, 129, 130, 131, 132, 133, 134, 135, 136, 137, 139, 141, 143, 145, 146, 147, 149};
int size = sizeof(arr) / sizeof(arr[0]);
int target;
printf("Enter the number to search: ");
scanf("%d", &target);
int result = binary_search_iterative(arr, target, size);
if (result != -1)
{
printf("Index of %d: %d\n", target, result);
}
else
{
printf("%d not found in the array.\n", target);
}
return 0;}