class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        n_2 = 1
        n_1 = 2
        for i in range(2, n):
            steps = n_2 + n_1
            n_2, n_1 = n_1, steps

        return steps

if __name__ == '__main__':
    sol = Solution()
    ans = sol.climbStairs(1)
    print(ans)
    ans = sol.climbStairs(2)
    print(ans)
    ans = sol.climbStairs(3)
    print(ans)
    ans = sol.climbStairs(4)
    print(ans)
