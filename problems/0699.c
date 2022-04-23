// https://leetcode.com/problems/trim-a-binary-search-tree/

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *trimBST(struct TreeNode *root, int low, int high) {
  if (!root) return nullptr;
  if (root->val < low) {
    return trimBST(root->right, low, high);
  } else if (root->val > high) {
    return trimBST(root->left, low, high);
  }
  root->left = trimBST(root->left, low, high);
  root->right = trimBST(root->right, low, high);
  return root;
}
