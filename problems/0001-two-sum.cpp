// https://leetcode.com/problems/two-sum/
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(std::vector<int> &nums, int target) {
    vector<int> result(2);
    for (int i = 0; i < (int) nums.size(); i++) {
      for (int j = i + 1; j < (int) nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          result[0] = i;
          result[1] = j;
        }
      }
    }
    return result;
  }
};
