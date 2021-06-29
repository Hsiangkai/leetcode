/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if (nums.size() == 0)
        return nullptr;
      unsigned mid = nums.size() / 2;
      vector<int> first_part(nums.begin(), nums.begin() + mid);
      vector<int> second_part(nums.begin() + mid + 1, nums.end());
      return new TreeNode(nums[mid], sortedArrayToBST(first_part),
                                     sortedArrayToBST(second_part));
    }
};

int main() {
  vector<int> input = {-10,-3,0,5,9};
  Solution *resolver = new Solution();
  TreeNode *result = resolver->sortedArrayToBST(input);
  return 0;
}
