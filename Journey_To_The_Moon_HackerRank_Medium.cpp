#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adj(n);
    for (auto &p : astronaut) {
        int u = p[0], v = p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<long long> component_sizes;

    function<long long(int)> dfs = [&](int src) {
        stack<int> st;
        st.push(src);
        visited[src] = true;
        long long size = 1;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    st.push(v);
                    size++;
                }
            }
        }
        return size;
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component_sizes.push_back(dfs(i));
        }
    }

    long long total = 0;
    long long sum = 0;

    for (long long c : component_sizes) {
        total += c * sum;  
        sum += c;
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
