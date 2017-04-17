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

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, left=nullptr, right=nullptr) : val(x), left(left), right(right) {}
};

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* node) {
    vector<vector<int> > result;
    if (!node) return result;
    map<int, vector<int> > m;
    queue<pair<int , TreeNode *> > q;
    q.push(make_pair(0, node));
    while (!q.empty()) {
        auto curPair = q.front();
        q.pop();
        TreeNode *curNode = curPair.second;
        int curHorizontalPos = curPair.first;
        // all vectors in map have been initialized
        m[curHorizontalPos].push_back(curNode -> val);
        if (curNode->left != NULL) {q.push(make_pair(curHorizontalPos - 1, curNode->left));}
        if (curNode->right != NULL) {q.push(make_pair(curHorizontalPos + 1, curNode->right));}
    }
    for (auto it=m.begin(); it!=m.end(); ++it) {
        result.push_back(it->second);
    }
    return result;
}

int main() {

}