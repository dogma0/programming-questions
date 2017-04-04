/*
 * Created on 2017-04-03.
 * -------------------------------------------------------------------------------
 * Question:
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
 * A gray code sequence must begin with 0.
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: n
 * Output: [0,1,3,2] because
 * Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * There might be multiple gray code sequences possible for a given n.
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: Time to Solve: 104 min. / Average Solving Time: 40 min.
 * Complexities:
 *      Time: T(n) = T(n-1) + T(n-1) = O(2^n-1) since it's the number of nodes in a balanced binary tree
 *      Space: O(n) since recursion goes n levels deep
 * Idea: Note all grey code sequence has 01 10 for every 4 nodes in the same bit position in the search tree.
 * Have an array that stores booleans for positions' state. While recurring into the search tree, decide whether next
 * level of recursion will 01 or 10 based on the element for the position in question.
 *
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> grayBinaryCode(int n);
vector<int> grayCodeIB(int n);

void grayCodeHelper(int n, int index, string &current, vector<bool> &dict, vector<string> &result) {
    if (index == n-1) {
        result.push_back(current);
        return;
    }
    if (dict[index+1] == true) {
        current += "0";
        grayCodeHelper(n, index+1, current, dict, result);
        current[current.size() - 1] = '1';
        grayCodeHelper(n, index+1, current, dict, result);
        current.pop_back();
    } else {
        current += "1";
        grayCodeHelper(n, index+1, current, dict, result);
        current[current.size() - 1] = '0';
        grayCodeHelper(n, index+1, current, dict, result);
        current.pop_back();
    }
    dict[index+1] = !dict[index+1];
}

vector<int> grayCode(int n) {
    string current = "";
    vector<bool> dict(5, true);
    vector<string> resultBinary;
    grayCodeHelper(n, -1, current, dict, resultBinary);
    vector<int> result;
    for (int i=0; i<resultBinary.size(); ++i) {
        result.push_back(std::stoi(resultBinary[i], nullptr, 2));
    }
    return result;
}

int main() {
    auto result = grayCode(3);
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}

vector<string> grayBinaryCode(int n) {
    string current = "";
    vector<bool> dict(n, true);
    vector<string> resultBinary;
    grayCodeHelper(n, -1, current, dict, resultBinary);
    return resultBinary;
}

// Interviewbit's answer
vector<int> grayCodeIB(int n) {
    vector<int> result(1, 0);
    for (int i = 0; i < n; i++) {
        int curSize = result.size();
        // push back all element in result in reverse order
        for (int j = curSize - 1; j >= 0; j--) {
            result.push_back(result[j] + (1 << i));
        }
    }
    return result;
}
