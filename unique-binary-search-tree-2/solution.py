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
    def generateNextTree(self, newTree: List, index: int, target: int, n: int):
        for i in range(index+1, 0, -1):
            if newTree[i-1] == target:
                newTree.insert(i-1, n)
                if i+1 < len(newTree):
                    newTree.insert(i+1, None)
                else:
                    newTree.append(None)
                return i-1
        return -1

    def generateTreeLists(self, n: int) -> List[Optional[int]]:
        treeLists = [[1]]
        if n == 1:
            return treeLists

        for i in range(1, n):
            nextTreeLists = []
            for tree in treeLists:
                newTree = copy.deepcopy(tree)
                if tree[-1] == None:
                    newTree[-1] = i+1
                else:
                    newTree.append(None)
                    newTree.append(i+1)
                nextTreeLists.append(newTree)

                index = len(tree) - 1
                for target in range(i, 0, -1):
                    newTree = copy.deepcopy(tree)
                    ret = self.generateNextTree(newTree, index, target, i+1)
                    if ret == -1:
                        continue
                    index = ret
                    nextTreeLists.append(newTree)

            nextTreeLists, treeLists = treeLists, nextTreeLists

        return treeLists

    def insert(self, tree: TreeNode, val: int):
        if val < tree.val:
            if tree.left == None:
                tree.left = TreeNode(val)
            else:
                self.insert(tree.left, val)
        elif val > tree.val:
            if tree.right == None:
                tree.right = TreeNode(val)
            else:
                self.insert(tree.right, val)

    def convert(self, treeList: List) -> TreeNode:
        tree = TreeNode(treeList[0])

        for node in treeList[1:]:
            if node == None:
                continue
            self.insert(tree, node)

        return tree

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        treeLists = self.generateTreeLists(n)
        answer = []
        for treeList in treeLists:
            treeG = self.convert(treeList)
            answer.append(treeG)

        return answer

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
