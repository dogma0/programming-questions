/*
 * Created on 2017-04-16.
 * -------------------------------------------------------------------------------
 * Question:
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: 
 * Output: 
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 
 * Complexities:
 *      Time: 
 *      Space: 
 * Idea: 
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

//  Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left=NULL, TreeNode *right=NULL) : val(x), left(left), right(right) {}
};

void helper(TreeNode *node, int &cur, vector<vector<int> > &result) {
    if (!node) return;
    if (!node->left && !node->right) {
        if (cur < 0) {cur = 0; }
        int size = result.size();
        if (size -1 < cur || result.size() == 0) {
            vector<int> tmp;
            tmp.push_back(node->val);
            result.push_back(tmp);
        } else {result[cur].push_back(node->val);}
        return;
    }
    --cur; helper(node->left, cur, result);
    ++cur;
    if (cur < 0) {cur = 0; }
    int size = result.size();
    if (size - 1 < cur) {
        vector<int> tmp;
        tmp.push_back(node->val);
        result.push_back(tmp);
    } else {
        result[cur].push_back(node->val);
    }

    ++cur; helper(node->right, cur, result);
    --cur;
}
vector<vector<int> > verticalOrderTraversal(TreeNode* node) {
    vector<vector<int> > result;
    int cur = -1;
    helper(node, cur, result);
    return result;
}

int main() {
    TreeNode right(2);
    TreeNode input(1, nullptr, &right);
    verticalOrderTraversal(&input);
}