class Solution {
public:
    int numIslands(vector <vector<char>> &grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] != 0) continue;
                if (searchMap(grid, visited, i, j)) {
                    count += 1;
                }
            }
        }
        return count;
    }

    bool searchMap(vector <vector<char>> &grid, vector <vector<int>> &visited, int i, int j) {
        if (!(i < grid.size() && j < grid[0].size() && i >= 0 && j >= 0)) {
            return false;
        }
        if (visited[i][j] == 1) {
            return false;
        }

        visited[i][j] = 1;
        if (grid[i][j] == '0') {
            return false;
        }

        searchMap(grid, visited, i - 1, j);
        searchMap(grid, visited, i, j - 1);
        searchMap(grid, visited, i + 1, j);
        searchMap(grid, visited, i, j + 1);
        return true;

    }
};