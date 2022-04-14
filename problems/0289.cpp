// https://leetcode.com/problems/game-of-life/
#include <vector>

using namespace std;

class Solution {
 public:
  void gameOfLife(vector<vector<int>> &board) {
    int n = (int) board.size(), m = (int) board[0].size();
    vector<vector<int>> cnt(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i - 1 >= 0) {
          if (j - 1 >= 0) {
            cnt[i][j] += board[i - 1][j - 1];
          }
          cnt[i][j] += board[i - 1][j];
        }
        if (i + 1 < n) {
          if (j + 1 < m) {
            cnt[i][j] += board[i + 1][j + 1];
          }
          cnt[i][j] += board[i + 1][j];
        }
        if (j - 1 >= 0) {
          if (i + 1 < n) {
            cnt[i][j] += board[i + 1][j - 1];
          }
          cnt[i][j] += board[i][j - 1];
        }
        if (j + 1 < m) {
          if (i - 1 >= 0) {
            cnt[i][j] += board[i - 1][j + 1];
          }
          cnt[i][j] += board[i][j + 1];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] && (cnt[i][j] < 2 || cnt[i][j] > 3)) {
          board[i][j] = 0;
        } else if (!board[i][j] && cnt[i][j] == 3) {
          board[i][j] = 1;
        }
      }
    }
  }
};
