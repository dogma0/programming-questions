/*
 * Created on 2017-04-23.
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
#include <queue>
#include <cmath>

using namespace std;

void bubbleDown(vector<int> &arr, int i) {
    queue<int> q;
    q.push(i);
    while (!q.empty() && q.front() <= (int) arr.size()/2) {
        int cur = q.front(); q.pop();
        int toSwap;
        if (2*cur + 1 > arr.size()) {
            if (arr[cur - 1] >= arr[2*cur - 1]) {break;}
            else {toSwap = 2*cur;}
        } else {
            if (arr[cur - 1] >= arr[2*cur - 1] && arr[cur - 1] >= arr[2*cur]) {break;}
            else if (arr[2*cur - 1] >= arr[2*cur]) {toSwap = 2*cur;}
            else {toSwap = 2*cur + 1;}
        }
        swap(arr[cur - 1], arr[toSwap - 1]);
        q.push(toSwap);
    }
}
void adjustPriority(vector<int> &arr, int i, int adjustTo) {
    arr[i - 1] = adjustTo;
    bubbleDown(arr, i);
}
void buildHeap(vector<int> &arr) {
    for(int i=arr.size()/2; i >= 1; --i) {
        bubbleDown(arr, i);
    }
}
int nchoc(int k, vector<int> &arr) {
    buildHeap(arr);
    long long sum = 0;
    for (int i=0; i<k; ++i) {
        sum += arr[0];
        adjustPriority(arr, 1, arr[0]/2);
    }
    int res = (int) (sum % (int) (pow((float) 10,9)+7));
    return res;
}

int main() {
    vector<int> arr{2147483647, 2000000014, 2147483647};
    nchoc(10, arr);
}