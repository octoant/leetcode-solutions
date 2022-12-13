// https://leetcode.com/problems/shift-2d-grid/
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int n = (int) grid.size(), m = (int) grid[0].size();
    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = i * m + j + k;
        result[(x / m) % n][x % m] = grid[i][j];
      }
    }
    return result;
  }
};
