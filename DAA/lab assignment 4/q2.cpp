// 2.Sum of Subsets Problem:

#include <iostream> using
namespace std;

void subsetSum(int set[], int n, int target) {
int total = 1 << n;

bool found = 0;

for (int i = 0; i < total; i++) {
int sum = 0; for (int j =
0; j < n; j++) { if (i & (1
<< j)) { sum +=
set[j];
}
}
if (sum == target) {
found = 1;
cout << "Subset with sum " << target << " found: ";
for (int j = 0; j < n; j++) {
if (i & (1 << j)) {
cout << set[j] << " ";
}
}
cout << endl;
}
}

if (!found) {
cout << "No subset found with sum " << target << endl;
}
}

int main() {
int set[] = {1, 3, 4, 5}; int n =
sizeof(set) / sizeof(set[0]); int
target = 9;
subsetSum(set, n, target);
return 0;
}