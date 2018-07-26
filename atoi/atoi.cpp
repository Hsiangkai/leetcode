#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        bool parsing = false;
	bool minus = false;
	bool max = false;
        for (auto c : str) {
            if (c == ' ') {
                if (parsing)
                    break;
                continue;
            } else if ('0' <= c && c <= '9') {
                parsing = true;
		int ten_times = ret * 10;
		long expected = (long)ret * 10;
		if (ten_times < expected) {
		  max = true;
		  break;
		}
		if ((ten_times + (c - '0')) < ten_times) {
		  max = true;
		  break;
		}
                ret = ten_times + (c - '0');
            } else if (c == '-' || c == '+') {
                if (parsing)
                    break;
		if (c == '-')
                    minus = true;
		parsing = true;
            } else {
                break;
            }
        }

	if (max && minus)
	  ret = -2147483648;
	else if (max)
	  ret = 2147483647;
	else if (minus)
	  ret = -ret;

        return ret;
    }
};

int main()
{
  Solution solution;

  int ans = solution.myAtoi("-6147483648");
  cout << ans << endl;

  return 0;
}
