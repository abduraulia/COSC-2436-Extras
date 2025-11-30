class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        auto dfs = [&](int i, int j, auto&& dfs_ref) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
            grid[i][j] = '0'; 
            dfs_ref(i+1, j, dfs_ref);
            dfs_ref(i-1, j, dfs_ref);
            dfs_ref(i, j+1, dfs_ref);
            dfs_ref(i, j-1, dfs_ref);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, dfs);
                }
            }
        }

        return count;
    }
};