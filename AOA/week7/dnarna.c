#include <stdio.h>
#include <string.h>

void longestCommonSubsequence(char s1[], char s2[]) {
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];  // rows = m & columns = n

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;    // char are equal, so diagonal_elem + 1 = current_elem
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];   // max(d[i-1][j], d[i][j-1])
        }
    }

    int index = dp[m][n];   // right-bottommost element, from where we will start printing the subsequence
    char lcs[index + 1];    // result string
    lcs[index] = '\0';      // the last element is '\0'

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("Longest Common Subsequence: %s\n", lcs);
    printf("Length: %d\n", dp[m][n]);
}

int main() {
    char dna[] = "ATGCGTACGTTAGC";
    char rna[] = "AUGCGUACGUUAGC";

    longestCommonSubsequence(dna, rna);

    return 0;
}