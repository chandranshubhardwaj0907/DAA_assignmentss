#include <iostream>
#include <climits>
using namespace std;
int maxSubArraySum(int arr[], int size)
{
int max_sum = INT_MIN;
int current_sum = 0;
for (int i = 0; i < size; i++)
{
current_sum = max(arr[i], current_sum + arr[i]);
max_sum = max(max_sum, current_sum);
}
return max_sum;
}
int main()
{

Aarush Pruthi
2CO17
102203793

int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
int n = sizeof(arr) / sizeof(arr[0]);
int max_sum = maxSubArraySum(arr, n);
cout << "Given array is: ";
for (int i = 0; i < n; i++)
{
cout << arr[i] << " ";
}
cout << "\nMaximum contiguous sum is: " << max_sum << endl;
return 0;