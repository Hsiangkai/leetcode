class Solution:
    def longestPalindrome(self, s: str) -> str:
        str_len = len(s)
        if str_len == 1:
            return s[0]

        possible_palindrome = set()
        for i in range(str_len):
            possible_palindrome.add((i, 0))
            possible_palindrome.add((i, 1))

        max_start = 0
        max_length = 1
        for n in range(2, str_len + 1):
            for i in range(str_len - n + 1):
                if (i + 1, n - 2) in possible_palindrome:
                    if s[i] == s[i + n - 1]:
                        possible_palindrome.add((i, n))
                        if n > max_length:
                            max_start = i
                            max_length = n

        return s[max_start:max_start + max_length]

if __name__ == "__main__":
    S = Solution()
    answer = S.longestPalindrome("babad")
    print(answer)
    answer = S.longestPalindrome("cbbd")
    print(answer)
