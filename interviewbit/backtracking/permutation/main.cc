/*
 * Created on 2017-04-02.
 * -------------------------------------------------------------------------------
 * Question: Given a collection of numbers, return all possible permutations.
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: [1,2,3]
 * Output:
 * [1,2,3]
 * [1,3,2]
 * [2,1,3]
 * [2,3,1]
 * [3,1,2]
 * [3,2,1]
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 45 min. / Average Solving Time: 28 min.
 * Complexities:
 *      Time: O(n!) since the function satisfies the recurrence T(n) = n*T(n-1)
 *      Space: O(n)
 * Idea:
 *      Iterate through all the numbers in the array and swap it to the beginning of the array. Pass the the remaining of the
 *      array into recursion. Once we hit the end of the array in the recursion, we know we have one array of the answer.
 *
 * The function here actually doesn't generate vectors in the correct order, though it passed OJ.
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

// First revision
void permuteHelper(int index, vector<int> &input, vector<vector<int> > &result) {
    if(index == input.size()) {
        result.push_back(input);
        return;
    }
    for (int i=index; i<input.size(); ++i) {
        swap(input[i], input[index]);
        permuteHelper(index+1, input, result);
        swap(input[i], input[index]);
    }
}
vector<vector<int> > permute(vector<int> &input) {
    vector<vector<int> > result;
    permuteHelper(0, input, result);
    return result;
}

int main() {
    vector<int> input = {1,2,3};
    auto result = permute(input);
    for (auto i : result) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }
}


// Submitted Version
//void permuteHelper(vector<vector<int> > &result, vector<int> &current, unordered_set<int> &mySet) {
//    if(mySet.empty()) {
//        result.push_back(current);
//        return;
//    }
//    for (auto s : mySet) {
//        current.push_back(s);
//        int curNum = s;
//        unordered_set<int> mySecondSet( mySet );
//        mySecondSet.erase(s);
//        permuteHelper(result, current, mySecondSet);
//        current.pop_back();
//        mySecondSet.insert(curNum);
//    }
//}
//vector<vector<int> > permute(vector<int> &input) {
//    vector<vector<int> > result;
//    vector<int> current;
//    unordered_set<int> mySet(input.begin(), input.end());
//    permuteHelper(result, current, mySet);
//    return result;
//}
