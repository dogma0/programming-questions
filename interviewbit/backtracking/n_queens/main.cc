/*
 * Created on 2017-04-03.
 * -------------------------------------------------------------------------------
 * Question: Find configuation of n queens in an nxn chessboard, s.t. no two or more queens are in
 * mutual attacking positions. A queen can attack any number of steps vertically, horizontally and diagonally
 * -------------------------------------------------------------------------------
 * Examples:
 * Input: 4
 * Output:
 * [
 * [".Q..",  // Solution 1
 *  "...Q",
 *  "Q...",
 *  "..Q."],
 *
 * ["..Q.",  // Solution 2
 *  "Q...",
 *  "...Q",
 *  ".Q.."]
 * ]
 * -------------------------------------------------------------------------------
 * Note:
 * Time taken to solve: Resolved  25mins/ Average Solving Time: 56 min.
 * Complexities:
 *      Time: idk, a loose bound would n^n as Time = n cols * Time(n-1) = T(n) = N*(n-1)
 *      Space: O(n)
 * Idea:
 * Since we know each one row can only have one queen and one column can only have one
 * queen, we can start upper left corner and iterate all the columns in th row.
 * If the cell is available, place a queen there and recur into the next row.
 * If when trying to place the ith queen, we realize no cell is available in the row, we backtrack
 * and try other options for the ith queen
 * -------------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> map(const vector<int> solution) {
    int n = solution.size();
    string cols(n, '.');
    vector<string> board(n, cols);
    for (int i = 0; i < n; ++i) {
        board[i][solution[i]] = 'Q';
    }
    return board;
}
bool isAvailable(const vector<int> solution, int i, int j) {
    for (int k = 0; k < solution.size(); ++k) {
        if (solution[k] == j || k + solution[k] == i + j || k - solution[k] == i - j) {
            return false;
        }
    }
    return true;
}
void solveNQueensHelper(int n, int row, vector<vector<string> > &result, vector<int> &solution) {
    if (row == n) {
        result.push_back(map(solution));
    }
    for (int j=0; j<n; ++j) {
        if(isAvailable(solution, row, j)) {
            solution[row] = j;
            solveNQueensHelper(n, row+1, result, solution);
            solution[row] = -10000;
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<int> solution(n, -10000);
    solveNQueensHelper(n , 0, result, solution);
    return result;
}

int main() {
    auto result = solveNQueens(20);
    for (auto solution : result) {
        for (auto row : solution) {
            cout << row << endl;
        }
        cout << "\n" << endl;
    }
}