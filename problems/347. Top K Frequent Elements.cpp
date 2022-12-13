// https://leetcode.com/problems/top-k-frequent-elements/
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> count;
    for (const int &i : nums) {
      count[i]++;
    }
    vector<pair<int, int>> pairs(count.size());
    for (const auto &[key, value] : count) {
      pairs.emplace_back(value, key);
    }
    sort(pairs.rbegin(), pairs.rend());
    vector<int> result(k);
    for (int i = 0; i < k; i++) {
      result[i] = pairs[i].second;
    }
    return result;
  }
};
