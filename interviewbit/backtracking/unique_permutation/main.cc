/*
 * Created on 2017-04-22.
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
#include <unordered_map>

using namespace std;

void helper(const vector<int> input, vector<vector<int> > &result, unordered_map<int, int> myMap, vector<int> current, int index) {
    if (index == input.size()) {
        result.push_back(current); return;
    }
    auto myIterMap(myMap);
    for (auto it=myIterMap.begin(); it!=myIterMap.end(); ++it) {
        int key = it->first;
        current.push_back(it->first);
        if (myMap[key] > 0) {--myMap[key];}
        if (myMap[key] == 0) {myMap.erase(key);}
        helper(input, result, myMap, current, index + 1);

        int justRemoved = current[current.size() - 1];
        current.pop_back();
        if (myMap.count(justRemoved) != 0) {++myMap[justRemoved];}
        else {myMap[justRemoved] = 1;}
    }
}
vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > result;
    unordered_map<int, int> myMap;
    for (auto elm : A) {
        if (myMap.count(elm) != 0) {
            ++myMap[elm];
        } else {
            myMap[elm] = 1;
        }
    }
    vector<int> current;
    helper(A, result, myMap, current, 0);
    return result;
}

int main() {
    vector<int> A{1,2,3};
    auto res = permute(A);
}