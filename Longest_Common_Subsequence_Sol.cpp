//Longest Common Subsequence LeetCode

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int MAX = 1001;
        int table[MAX][MAX] = {0};

        int m = text1.length();
        int n = text2.length();

        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    table[i][j] = table[i-1][j-1] + 1;
                }
                else
                {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        return table[m][n];
    }
};