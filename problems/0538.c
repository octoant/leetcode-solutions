// https://leetcode.com/problems/convert-bst-to-greater-tree/

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int sumBST(struct TreeNode *node, int parent) {
  if (node) {
    int right = sumBST(node->right, parent);
    int current = node->val;
    node->val += parent + right;
    int left = sumBST(node->left, node->val);
    return left + current + right;
  } else {
    return 0;
  }
}

struct TreeNode *convertBST(struct TreeNode *root) {
  sumBST(root, 0);
  return root;
}
