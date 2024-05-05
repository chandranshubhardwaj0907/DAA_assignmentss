// 1. LONGEST COMMON SUBSEQUENCE:

#include <iostream> #include<cstring> using namespace
std; void lowestcommonsub(char *S1, char *S2, int m,
int n) { int LCS_table[m + 1][n + 1];
for (int i = 0; i <= m; i++) { for
(int j = 0; j <= n; j++) { if (i
== 0 || j == 0)
LCS_table[i][j] = 0; else if
(S1[i - 1] == S2[j - 1])
LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
else
LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
}
}
int index = LCS_table[m][n]; char
lowestcommonsub [index + 1];
lowestcommonsub [index] = '\0';

int i = m, j = n; while (i
> 0 && j > 0) { if (S1[i -
1] == S2[j - 1]) {
lowestcommonsub [index - 1] = S1[i - 1];
i--;
j--;
index--;
}

else if (LCS_table [i - 1] [j] > LCS_table[i] [j - 1])

Sayiam Handa
102203777
2CO-17

i--;
else
j--;
}
cout << "S1: " << S1 << "\nS2: " << S2 << "\n LCS: " << lowestcommonsub << "\n";
}
int main() { char S[]
= "ACADB"; char
S1[] = "CBDA";
int X = strlen(S); int Y =
strlen(S1); lowestcommonsub
(S, S1, X, Y);
}