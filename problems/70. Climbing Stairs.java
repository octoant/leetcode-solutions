// https://leetcode.com/problems/climbing-stairs/

class Solution {
  public int climbStairs(int n) {
    int[] ways = new int[n];
    for (int i = 0; i < n; i++) {
      if (i < 2) {
        ways[i] = i + 1;
      } else {
        ways[i] = ways[i - 1] + ways[i - 2];
      }
    }
    return ways[n - 1];
  }
}
