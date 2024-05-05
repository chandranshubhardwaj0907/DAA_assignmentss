// 1.N-Queen Problem:

#include <iostream>
#include <cmath> //
#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
for (int i = 0; i < n; i++) {
cout << a[i] << " ";
}
}

int isSafe(int result[], int x2, int y2) { for (int i = 0; i < x2;
i++) { if ((result[i] == y2) || (abs(i - x2) == abs(result[i] -
y2))) {
return 0;
}
}
return 1;
}

void placeQueens(int result[], int x, int size) {
for (int i = 0; i < size; i++) {
if (isSafe(result, x, i) == 1) {
result[x] = i; if (x == size
- 1) {
cout << "\nSolution found.\n";
printArray(result, size);
}

Sayiam Handa
102203777
2CO-17

placeQueens(result, x + 1, size);
}
}
}

int main() {
int n;
cout << "In Number of queens: ";
cin >> n;
int result[n];
placeQueens(result, 0, n);
return 0;
}