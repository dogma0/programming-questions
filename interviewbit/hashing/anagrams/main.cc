/*
 * Created on 2017-04-09.
 * -------------------------------------------------------------------------------
 * Question: Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of
 * integers representing the index in the original list. Look at the sample case for clarification.
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: "cat dog god tca"
 * Output: [[1, 4], [2, 3]]
 * -------------------------------------------------------------------------------
 * Note: Used map instead of unordered_map, map's count is O(lgn)
 * Time taken to solve:  61 min. / Average Solving Time: 36 min. (Mostly on finding the right
 * container and type for key)
 * Complexities:
 *      Time: (Assuming we are find is now O(1)) O(n)
 *      Space: O(n)
 * Idea: Hash the letter counts when traversing the string array. Increment the value for the key
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> letterMap(string s) {
    vector<int> result(26, 0);
    for (char c : s) {
        result[c - 'a'] = result[c - 'a'] + 1;
    }
    return result;
}
vector<vector<int> > anagrams(const vector<string> &A) {
    map<vector<int>, vector<int> > letterCountsMap;
    int index = 1;
    for (string s : A) {
        auto tmp = letterMap(s);
        if (letterCountsMap.count(tmp) != 0) {
            letterCountsMap[tmp].push_back(index);
        } else {
            vector<int> tmpVec = {index};
            letterCountsMap[tmp] = tmpVec;
        }
        ++index;
    }

    vector<vector<int> > result;
    for (auto it=letterCountsMap.begin(); it!=letterCountsMap.end(); ++it) {
        result.push_back(it->second);
    }
    return result;
}

int main() {
    vector<string> tmp{"cat",  "tca", "xyz",};
    auto result = anagrams(tmp);
    for (auto i : result) {
        cout << "[";
        for (auto j : i) {
            cout << j << ", ";
        }
        cout << "]" << endl;
    }
}