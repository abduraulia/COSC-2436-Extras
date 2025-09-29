//Unique Paths LeetCode

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        long long result = 1;
        for (int i = 1; i <= m - 1; i++)
        {
            result = result * (n-1+i) / i;
        }
        return (int)result;
    }
};