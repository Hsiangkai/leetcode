class Solution:
    def numTrees(self, n: int) -> int:
        if n == 1:
            return 1

        records = [[list() for i in range(n+1)] for i in range(n+1)]
        for length in range(2, n+1):
            for start in range(1, n):
                end = start + length - 1
                if end > n:
                    continue

                records[start][end] = 0
                for root in range(start, end+1):
                    left_trees = 1
                    right_trees = 1
                    if start < root-1:
                        left_trees = records[start][root-1]
                    if root+1 < end:
                        right_trees = records[root+1][end]
                    records[start][end] += left_trees * right_trees
        return records[1][n]

if __name__ == '__main__':
    sol = Solution()
    ans = sol.numTrees(4)
    print(ans)
