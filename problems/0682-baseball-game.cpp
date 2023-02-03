// https://leetcode.com/problems/baseball-game/
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int calPoints(vector<string> &ops) {
    vector<int> records;
    for (const string &val : ops) {
      if (val == "+") {
        records.push_back(*(records.end() - 1) + *(records.end() - 2));
      } else if (val == "C") {
        records.pop_back();
      } else if (val == "D") {
        records.push_back(*(records.end() - 1) * 2);
      } else {
        records.push_back(stoi(val));
      }
    }
    return accumulate(records.begin(), records.end(), 0);
  }
};