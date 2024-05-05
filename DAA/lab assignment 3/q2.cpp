// 2. MATRIX CHAIN MULTIPLICATION:

#include <bits/stdc++.h>
using namespace std; int
dp[100][100]; int
matrix(int* p, int i, int j)
{
if (i == j)
{
return 0;
}

if (dp[i][j] != -1)
{
return dp[i][j];
}
dp[i][j] = INT_MAX;
for (int k = i; k < j; k++)
{
dp[i][j] = min(
dp[i][j], matrix(p, i, k)

+ matrix(p, k + 1, j)
+ p[i - 1] * p[k] * p[j]);

}
return dp[i][j];
}
int MatrixOrder(int* p, int n)
{
int i = 1, j = n - 1;
return matrix(p, i, j);
}

int main()
{
int arr[] = { 2,4,6,8}; int n = sizeof(arr) / sizeof(arr[0]);
memset(dp, -1, sizeof dp); cout << "Minimum number of multiplications is
“<< MatrixOrder(arr, n);
}
