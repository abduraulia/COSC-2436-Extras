//N-th Tribonacci Numbers LeetCode

class Solution {
public:
    int tribonacci(int n)
    {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        if (n == 2) { return 1; }
        
        int T[n+1];
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;

        for (int i=0; i<=n-3; i++)
        {
            T[i+3] = T[i] + T[i+1] + T[i+2];
        }

        return T[n];
    }
};