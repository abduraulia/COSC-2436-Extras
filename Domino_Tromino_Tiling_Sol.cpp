//Domino and Tronimo Tiling LeetCode

class Solution {
public:
    int numTilings(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        const int MOD = 1e9 + 7;

        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 5;

        for (int i=3; i<=n-1; i++)
        {
            arr[i+1] = ((2*arr[i] % MOD) + (arr[i-2] % MOD)) % MOD;
        }

        return arr[n] % MOD;
    }
};