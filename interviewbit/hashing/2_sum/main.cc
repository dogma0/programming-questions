/*
 * Created on 2017-04-09.
 * -------------------------------------------------------------------------------
 * Question:
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
 * Put both these numbers in order in an array and return the array from your function ( Looking at the function
 * signature will make things clearer ). Note that, if no pair exists, return empty list.
 * If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum
 * index2, choose the one with minimum index1 out of them.
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: [2, 7, 11, 15], target=9
 * Output: [1.2] since index1 = 1, index2 = 2
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: 
 * Complexities:
 *      Time: O(n)
 *      Space: O(n)
 * Idea:
 * For each element, we ask if target - current_element exists in our hash map.
 * The key for the hash map is the element's value and the mapped value is the index
 * -------------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

vector<int> twoSum(const vector<int> &A, int target) {
    unordered_map<int, int > myMap;
    vector<int> result;
    for (int i=0; i<A.size(); ++i) {
        if (myMap.count(target - A[i]) != 0) {
            result.push_back(myMap[target-A[i]]);
            result.push_back(i+1);
            return result;
        } else {
            if (myMap.count(A[i]) == 0) {myMap[A[i]] = i + 1;}
        }
    }
    return result;
}
int main() {

}