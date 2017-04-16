/*
 * Created on 2017-04-16.
 * -------------------------------------------------------------------------------
 * Question: Given a root of a binary search tree and a key x, find the largest key in the tree that is smaller than x.
 * -------------------------------------------------------------------------------
 * Examples: if an in-order list of all keys in the tree is {2, 3, 4, 7, 17, 19, 21, 35, 89} and x is 19, the biggest
 * key that is smaller than x is 17.
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 
 * Complexities:
 *      Time: 
 *      Space: 
 * Idea: 
 * -------------------------------------------------------------------------------
 */
//                    17
//                7       19
//            3               21
//          2    4                35
//                                    89

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
public:
    Node(int val, Node *left=NULL, Node *right=NULL) : val(val), left(left), right(right) {};
};

int findClosetSmallerToX(Node *root, int x) {
    Node* cur = root;
    int result = NULL;
    while (cur) {
        if (cur->val < x) {
           result = cur->val;
           cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return result;
}
int main() {
    Node left(3);
    Node right(7);
    Node root(5, &left, &right);
    int result = findClosetSmallerToX(&root, 4);
    cout << result << endl;
}