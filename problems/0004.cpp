// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = (int) nums1.size(), m = (int) nums2.size();
    int i = 0, j = 0, half = (n + m) / 2 + 1;
    double prev, curr = 0;
    while (i + j < half && i < n && j < m) {
      prev = curr;
      if (nums1[i] < nums2[j]) {
        i++;
        curr = nums1[i];
      } else {
        j++;
        curr = nums2[j];
      }
    }
    while (i + j < half && i < n) {
      prev = curr;
      curr = nums1[i++];
    }
    while (i + j < half && j < m) {
      prev = curr;
      curr = nums2[j++];
    }
    if ((n + m) % 2) {
      return curr;
    } else {
      return (prev + curr) / 2;
    }
  }
};
