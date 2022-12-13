// https://leetcode.com/problems/spiral-matrix-ii/
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int val = 0, i = 0, j = n - 1;
    while (i < j) {
      val = fill(matrix, i++, j--, val);
    }
    if (n % 2) {
      matrix[n / 2][n / 2] = n * n;
    }
    return matrix;
  }

  int fill(vector<vector<int>> &matrix, int a, int b, int sum) {
    for (int i = a; i < b; i++) {
      matrix[a][i] = ++sum;
    }
    for (int i = a; i < b; i++) {
      matrix[i][b] = ++sum;
    }
    for (int i = b; i > a; i--) {
      matrix[b][i] = ++sum;
    }
    for (int i = b; i > a; i--) {
      matrix[i][a] = ++sum;
    }
    return sum;
  }
};
