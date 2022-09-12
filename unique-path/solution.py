class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 or n == 1:
            return 1

        up_row = [1] * n
        down_row = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                down_row[j] = down_row[j-1] + up_row[j]
            up_row, down_row = down_row, up_row

        return up_row[n-1]


if __name__ == '__main__':
    sol = Solution()
    ans = sol.uniquePaths(3, 2)
    print(ans)
    ans = sol.uniquePaths(3, 7)
    print(ans)
