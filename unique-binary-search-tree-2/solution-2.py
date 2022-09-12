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
    def generate(self, start: int, end:int, records) -> List[Optional[TreeNode]]:
        if start > end:
            return [None]

        if (start, end) in records:
            return records[(start, end)]

        res = []
        for root in range(start, end+1):
            left_trees = self.generate(start, root-1, records)
            right_trees = self.generate(root+1, end, records)

            for left in left_trees:
                for right in right_trees:
                    tree = TreeNode(root)
                    tree.left = left
                    tree.right = right
                    res.append(tree)

        records[(start, end)] = res
        return res

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.generate(1, n, {})

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
