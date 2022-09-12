from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        up_row = [grid[0][0]]
        for i in range(1, n):
            up_row.append(up_row[i-1] + grid[0][i])

        down_row = [0] * n
        for i in range(1, m):
            down_row[0] = up_row[0] + grid[i][0]
            for j in range(1, n):
                down_row[j] = min(up_row[j], down_row[j-1]) + grid[i][j]

            up_row, down_row = down_row, up_row
       
        return up_row[n-1]

if __name__ == '__main__':
    sol = Solution()
    ans = sol.minPathSum([[1,3,1],[1,5,1],[4,2,1]])
    print(ans)
    ans = sol.minPathSum([[1,2,3],[4,5,6]])
    print(ans)
