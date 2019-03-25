#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<string, string> mapping;
  hash<string> str_hash;

  bool duplicate(const string& longUrl, const string& code) {
    auto it = mapping.find(code);
    if (it != mapping.end()) {
      if (longUrl.compare(it->second) != 0)
	return true;
    }
    return false;
  }

  string generate_key(const string& longUrl, const string& code) {
    string url(longUrl);
    string new_code = to_string(str_hash(url.append(code)));
    new_code.resize(6);
    return new_code;
  }

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    string code("");
    do {
      code = generate_key(longUrl, code);
    } while(duplicate(longUrl, code));

    mapping.insert({code, longUrl});
    return "http://tinyurl.com/" + code;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string code = shortUrl.substr(sizeof("http://tinyurl.com/") - 1, 6);
    return mapping[code];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main ()
{
  Solution solution;
  string web("http://www.google.com");

  cout << solution.decode(solution.encode(web)) << endl;

  return 0;
}
