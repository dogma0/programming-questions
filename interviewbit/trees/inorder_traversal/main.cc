/*
 * Created on 2017-04-17.
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
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    stack<pair<TreeNode*, bool> > nodeStack;
    nodeStack.push(make_pair(root, false));
    vector<int> result;
    while (!nodeStack.empty()) {
        pair<TreeNode*, bool> &topPair = nodeStack.top();
        TreeNode *topNode = topPair.first;
        // look for left node
        if (topNode->left != NULL && !topPair.second) {
            nodeStack.push(make_pair(topNode->left, false));
            topPair.second = true;
            continue;
        }
        // pop node and add to result
        nodeStack.pop();
        result.push_back(topNode->val);
        // push its right if exist
        if (topNode->right != NULL) {nodeStack.push(make_pair(topNode->right, false)); continue;}
    }
    return result;
}

int main() {

}