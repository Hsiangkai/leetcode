
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_n = len(s1)
        s2_n = len(s2)
        s3_n = len(s3)

        if s1_n + s2_n != s3_n:
            return False

        answer = [False for i in range(s1_n+1)]
        for i in range(s1_n+1):
            if s3.startswith(s1[:i]):
                answer[i] = True

        for i in range(1, s2_n+1):
            buffer = [False for a in range(s1_n+1)]
            if s3.startswith(s2[:i]):
                buffer[0] = True
            for j in range(1, s1_n+1):
                # buffer[j] = buffer[j-1] + answer[j]
                if buffer[j-1] and (i+j <= s3_n) and (s3[i+j-1] == s1[j-1]):
                    buffer[j] = True
                elif answer[j] and (i+j <= s3_n) and (s3[i+j-1] == s2[i-1]):
                    buffer[j] = True

            answer = buffer

        return answer[s1_n]


if __name__ == '__main__':
    sol = Solution()
    ans = sol.isInterleave("", "", "a")
    print(ans)
    ans = sol.isInterleave("a", "bd", "bad")
    print(ans)
    ans = sol.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    print(ans)
    ans = sol.isInterleave("aabcc", "dbbca", "aadbbbaccc")
    print(ans)
    ans = sol.isInterleave("cabbcaaacacbac", "acabaabacabcca", "cacabaabacaabccbabcaaacacbac")
    print(ans)
    ans = sol.isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb", "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc", "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc")
    print(ans)
