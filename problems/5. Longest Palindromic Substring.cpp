// https://leetcode.com/problems/longest-palindromic-substring/
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    for (int i = (int) s.size(); i > 0; i--) {
      for (int j = 0; j < (int) s.size() - i + 1; j++) {
        if (isPalindrome(s, j, j + i - 1)) {
          return s.substr(j, i);
        }
      }
    }
    return "";
  }

  bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) return false;
    }
    return true;
  }
};