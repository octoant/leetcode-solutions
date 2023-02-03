// https://leetcode.com/problems/increasing-order-search-tree/
#include <stack>
#include <vector>

using namespace std;
/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *increasingBST(TreeNode *root) {
    vector<TreeNode *> result;
    stack<TreeNode *> stack;

    while (true) {
      if (root) {
        stack.push(root);
        root = root->left;
      } else {
        if (stack.empty()) break;
        root = stack.top();
        stack.pop();

        if (!result.empty()) {
          result.back()->right = root;
        }
        root->left = nullptr;
        result.push_back(root);
        root = root->right;
      }
    }
    return result.front();
  }
};
