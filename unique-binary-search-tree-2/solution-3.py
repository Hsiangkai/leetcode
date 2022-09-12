from typing import List
from typing import Optional
import copy

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        records = [[list() for i in range(n+1)] for i in range(n+1)]
        for i in range(1, n+1):
            records[i][i].append(TreeNode(i))

        for length in range(2, n+1):
            for start in range(1, n):
                end = start + length - 1
                if end > n:
                    continue
                for root in range(start, end+1):
                    left_trees = [None]
                    right_trees = [None]
                    if start <= root-1:
                        left_trees = records[start][root-1]
                    if root+1 <= end:
                        right_trees = records[root+1][end]
                    for left_tree in left_trees:
                        for right_tree in right_trees:
                            records[start][end].append(TreeNode(root, left_tree, right_tree))

        return records[1][n]

# help functions
def printTree(tree, outList):
    if tree == None:
        outList.append('null')
        return

    outList.append(tree.val)
    if tree.left != None or tree.right!= None:
        printTree(tree.left, outList)
        printTree(tree.right, outList)

def printTreeList(treeList):
    for tree in treeList:
        outList = []
        printTree(tree, outList)
        print(outList)

if __name__ == '__main__':
    sol = Solution()
    ans = sol.generateTrees(4)
    printTreeList(ans)
