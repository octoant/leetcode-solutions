// https://leetcode.com/problems/make-the-string-great/
class Solution {
  public:
    string makeGood(string s) {
      string good;
      for (const char c : s) {
        if (good.empty() || abs(c - good.back()) != 32) {
          good.push_back(c);
        } else {
          good.pop_back();
        }
      }
      return good;
    }
};
