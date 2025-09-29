//Recursion: Davis' Staircase | HackerRank

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stepPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

const long long MOD = 10000000007;

typedef vector<vector<long long>> matrix;

// Multiply two 3x3 matrices
matrix multiply(const matrix &a, const matrix &b) {
    matrix c(3, vector<long long>(3, 0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]%MOD) % MOD;
    return c;
}

// Recursive matrix exponentiation
matrix power(matrix a, long long n) {
    if(n==1) return a;
    if(n%2==0) {
        matrix half = power(a, n/2);
        return multiply(half, half);
    } else {
        return multiply(a, power(a, n-1));
    }
}

int stepPerms(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;

    matrix T = {
        {1,1,1},
        {1,0,0},
        {0,1,0}
    };

    matrix R = power(T, n-2);

    // stepPerms(n) = 2*R[0][0] + 1*R[0][1] + 1*R[0][2]
    return (2*R[0][0] + R[0][1] + R[0][2]) % MOD;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
