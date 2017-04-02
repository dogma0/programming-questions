/*
 * Created on 2017-04-02.
 * -------------------------------------------------------------------------------
 * Question:
 * -------------------------------------------------------------------------------
 * Examples:
 * Given a string s, partition s such that every string of the partition is a palindrome.
 * Return all possible palindrome partitioning of s
 * Input: s = "aab"
 * Output:
 *  [
    ["a","a","b"]
    ["aa","b"],
    ]
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 
 * Complexities:
 *      Time: Since the time taken is a function of sum(n - 1 choose i) from i to n - 1. Hence, T(n) = O(2^ n -1)
 *      Space: S(n) = O(n) since recursion goes as deep as the length of the input string
 * Idea: Do a DFS on the tree. The tree is defined as each branch starting a substr that starts from the beginning
 * , e.g. a, aa, aab, and recur in the remaining substrings. E.g. "aab" -> tree = [a, aa, ab] -> [[a, ab], [b], []]
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPanlindrome(string s) {
    for (int i=0, j = s.size()-1; j >= ceil(s.size()/2.0); ++i, --j) {
        if (s[i] != s[j]) {return false;}
    }
    return true;
}
void partitionHelper(int start, string input, vector<string> &current, vector<vector<string> > &result) {
    // Base case
    if (start >= input.size()) {
        result.push_back(current);
        return;
    }
    for (int j = 1; start + j <= input.size(); ++j) {
        if (isPanlindrome(input.substr(start, j))) {
            current.push_back(input.substr(start, j));
            partitionHelper(start + j, input, current, result);
            current.pop_back();
        }
    }
}
vector<vector<string> > partition(string s) {
    vector<string> current;
    vector<vector<string> > result;
    partitionHelper(0, s, current, result);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    auto answer = partition("aaaa");
    cout << "[\n";
    for (auto i : answer) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << "]\n";


    answer = partition("aab");
    cout << "[\n";
    for (auto i : answer) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << "]\n";
}