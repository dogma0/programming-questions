/*
 * Created on 2017-04-15.
 * -------------------------------------------------------------------------------
 * Question: Given an array of sorted distinct integers named arr,
 * write a function that returns an index i in arr for which arr[i] = i or -1 if no such index exists.
 * Implement the most efficient solution possible, prove the correctness of your solution and analyze its
 * runtime complexity (in terms of n - the length of arr).
 * -------------------------------------------------------------------------------
 * Examples:
 * Given arr = [-8,0,2,5] the function returns 2, since arr[2] = 2
 * Given arr = [-1,0,3,6] the function returns -1, since no index in arr satisfies arr[i] = i
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 30 minutes with guideance (Pramp)
 * Complexities:
 *      Time: O(lgn)
 *      Space: O(1)
 * Idea: Perform binary search on the array. Based on what current value is
 * relative to its index, we know whether we're going left and right. The base
 * case is when we hit a leaf.
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int findIndex(const vector<int>, int, int);

int main() {
    vector<int> input{0, 10, 20, 55};
    int result = findIndex(input, 0, input.size() - 1);
    cout << result << endl;
}

int findIndex(const vector<int> input, int start, int end) {
    if (start > end) { return -1; }
    int rootIndex = ceil((end + start) / 2);
    if (input[rootIndex] < rootIndex) {
        return findIndex(input, rootIndex + 1, end);
    } else if (input[rootIndex] > rootIndex) {
        return findIndex(input, start, rootIndex - 1);
    } else {
        return rootIndex;
    }
}

