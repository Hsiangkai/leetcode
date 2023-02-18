#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> ret;
    if (firstList.empty())
      return ret;
    if (secondList.empty())
      return ret;

    int first_n = firstList.size();
    int second_n = secondList.size();
    int first_i = 0;
    int second_i = 0;
    vector<int> interval(2, 0);
    while (first_i < first_n && second_i < second_n) {
      if (firstList[first_i][0] <= secondList[second_i][0]) {
	if (secondList[second_i][0] <= firstList[first_i][1]) {
	  if (secondList[second_i][1] <= firstList[first_i][1]) {
	    interval[0] = secondList[second_i][0];
	    interval[1] = secondList[second_i][1];
	    ret.push_back(interval);
	    second_i++;
	  } else {
	    interval[0] = secondList[second_i][0];
	    interval[1] = firstList[first_i][1];
	    ret.push_back(interval);
	    first_i++;
	  }
	} else {
	  first_i++;
	}
      } else {
	if (firstList[first_i][0] <= secondList[second_i][1]) {
	  if (firstList[first_i][1] <= secondList[second_i][1]) {
	    interval[0] = firstList[first_i][0];
	    interval[1] = firstList[first_i][1];
	    ret.push_back(interval);
	    first_i++;
	  } else {
	    interval[0] = firstList[first_i][0];
	    interval[1] = secondList[second_i][1];
	    ret.push_back(interval);
	    second_i++;
	  }
	} else {
	  second_i++;
	}
      }
    }
    return ret;
  }
};

void print(vector<vector<int>> &data) {
  for (auto &interval : data) {
    cout << "{" << interval[0] << ", " << interval[1] << "}" << ", ";
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> interval1_1 {{0,2},{5,10},{13,23},{24,25}};
  vector<vector<int>> interval1_2 {{1,5},{8,12},{15,24},{25,26}};
  vector<vector<int>> ret;
  ret = sol.intervalIntersection(interval1_1, interval1_2);
  print(ret);
  return 0;
}
