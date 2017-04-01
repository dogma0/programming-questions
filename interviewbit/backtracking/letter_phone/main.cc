/*
 * Created on 2017-04-01.
 * -------------------------------------------------------------------------------
 * Question:
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * (Diagram on Interview Bit)
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken: 37/42 minutes
 * Complexities:
 *      Time: O(~3 ^ n) = O(n)
 *      Space: O(|n|)
 * Idea: While iterating first number's mapped characters, recur into input's next character's mapping
 * Add to the result vector when recursion hits the length of input.
 * -------------------------------------------------------------------------------
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string findChars(int num) {
    string charMap[10];
    charMap[0] = "0";
    charMap[1] = "1";
    charMap[2] = "abc";
    charMap[3] = "def";
    charMap[4] = "ghi";
    charMap[5] = "jkl";
    charMap[6] = "mno";
    charMap[7] = "pqrs";
    charMap[8] = "tuv";
    charMap[9] = "wxyz";
    return charMap[num];
}

void letterComboHelper(string A, int index, string prefix, vector<string> &result) {
    if (index > A.size() - 1) {
        result.push_back(prefix);
        return;
    }
    string myChars = findChars(A[index] - '0');
    for (auto c : myChars) {
        prefix += c;
        letterComboHelper(A, index+1, prefix, result);
        prefix.pop_back();
    }
}

vector<string> letterCombinations(string A) {
    vector<string> result;
    letterComboHelper(A, 0, "", result);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    auto answer = letterCombinations("234");
    for (auto s : answer) {
        cout << s << endl;
    }
}
