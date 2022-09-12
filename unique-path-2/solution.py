from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        up_row = []
        if obstacleGrid[0][0]:
            up_row.append(0)
        else:
            up_row.append(1)

        for i in range(1, n):
            if obstacleGrid[0][i]:
                up_row.append(0)
            else:
                up_row.append(up_row[i-1])

        if m == 1:
            return up_row[n-1]

        down_row = [0] * n  # fill the dummy value
        for i in range(1, m):
            if obstacleGrid[i][0]:
                down_row[0] = 0
            else:
                down_row[0] = up_row[0]

            for j in range(1, n):
                if obstacleGrid[i][j]:
                    down_row[j] = 0
                else:
                    down_row[j] = down_row[j-1] + up_row[j]
            up_row, down_row = down_row, up_row

        return up_row[n-1]


if __name__ == '__main__':
    sol = Solution()
    ans = sol.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]])
    print(ans)
    ans = sol.uniquePathsWithObstacles([[0,1],[0,0]])
    print(ans)
    ans = sol.uniquePathsWithObstacles([[0,1]])
    print(ans)
    ans = sol.uniquePathsWithObstacles([[1,0]])
    print(ans)
    ans = sol.uniquePathsWithObstacles([[0,1,0]])
    print(ans)
    ans = sol.uniquePathsWithObstacles([[0], [1]])
    print(ans)
