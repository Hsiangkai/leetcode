#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool decodable_by_2(string &s) {
      if (s.length() <= 1)
	return false;
      if (s[0] == '1')
	return true;
      else if (s[0] == '2') {
	if ('0' <= s[1] && s[1] <= '6')
	  return true;
      }
      return false;
    }
    bool decodable_by_1(string &s) {
      if (s.length() <= 0)
	return false;
      if (s[0] == '0')
	return false;
      return true;
    }

    int decode(string s, int index, vector<int> &decode_len) {
      if (s.length() == 0)
	return 1;
      else if (s.length() == 1 && decodable_by_1(s))
	return 1;
      else {
	bool decode_2 = decodable_by_2(s);
	bool decode_1 = decodable_by_1(s);
	int decode_2_len;
	int decode_1_len;
	if (decode_2 && decode_1) {
	  if (decode_len[index + 2] != -1)
	    decode_2_len = decode_len[index + 2];
	  else {
	    decode_2_len = decode(s.substr(2), index + 2, decode_len);
	    decode_len[index + 2] = decode_2_len;
	  }
	  if (decode_len[index + 1] != -1)
	    decode_1_len = decode_len[index + 1];
	  else {
	    decode_1_len = decode(s.substr(1), index + 1, decode_len);
	    decode_len[index + 1] = decode_1_len;
	  }
	  return decode_2_len + decode_1_len;
	} else if (decode_2) {
	  int decode_2_len;
	  if (decode_len[index + 2] != -1)
	    decode_2_len = decode_len[index + 2];
	  else {
	    decode_2_len = decode(s.substr(2), index + 2, decode_len);
	    decode_len[index + 2] = decode_2_len;
	  }
	  return decode_2_len;
	} else if (decode_1) {
	  int decode_1_len;
	  if (decode_len[index + 1] != -1)
	    decode_1_len = decode_len[index + 1];
	  else {
	    decode_1_len = decode(s.substr(1), index + 1, decode_len);
	    decode_len[index + 1] = decode_1_len;
	  }
	  return decode_1_len;
	} else
	  return 0;
      }
    }

public:
    int numDecodings(string s) {
      vector<int> decode_len;
      decode_len.reserve(s.length() + 1);
      decode_len.assign(s.length() + 1, -1);
      return decode(s, 0, decode_len);
    }
};

int main()
{
  string s("9355141842519423434975558424574331479338913773268525913972842463395324957127519863135646135786662832");
  Solution sol;
  int ans = sol.numDecodings(s);
  cout << ans << endl;
  return 0;
}
