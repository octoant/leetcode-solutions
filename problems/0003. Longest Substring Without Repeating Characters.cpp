// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> index(128, -1);
    int result = 0, j = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (index[s[i]] != -1) {
        result = max(result, i - j);
        j = max(j, index[s[i]] + 1);
      }
      index[s[i]] = i;
    }
    return max(result, (int) s.size() - j);
  }
};
