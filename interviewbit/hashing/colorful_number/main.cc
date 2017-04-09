/*
 * Created on 2017-04-09.
 * -------------------------------------------------------------------------------
 * Question: For Given Number N find if its COLORFUL number or not
 * A number can be broken into different contiguous sub-subsequence parts.
 * Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245.
 * And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: N = 23
 * 2 3 23
 * 2 -> 2
 * 3 -> 3
 * 23 -> 6
 * this number is a COLORFUL number since product of every digit of a sub-sequence are different.
 * Output: 1
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: Time to Solve: 54 min. / Average Solving Time: 36 min.
 * Complexities:
 *      Time: n, n - 1, ... 1 sub-strings = O(n^2)
 *      Space: O(n^2)
 * Idea:
 * A sub-string's length varies from 1 to n. Generate all substrings and get their products into a hash set.
 * If a duplicate is found, report 0
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int getProduct(string input) {
    if (input.size() == 0) {return -1;}
    int count = 1;
    for (int i=0; i<input.size(); ++i) {
        count *= stoi(input.substr(i, 1));
    }
    return count;
}
int colorful(int input) {
    string A = to_string(input);
    unordered_set<int> myMap;
    for (size_t len=1; len<=A.size(); ++len) {
        for (size_t i=0; i+len-1<A.size(); ++i) {
            auto insertionResult = myMap.insert(getProduct(A.substr(i, len)));
            if (!insertionResult.second) {return 0;}
        }
    }
    return 1;
}
int main() {
    int res = colorful(3245);
    cout << res << endl;
}