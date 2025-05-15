#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n) {
    for(int j = 0; j < n; j++) 
        if(board[row][j] == 'Q') return false;

    for(int i = 0; i < n; i++) 
        if(board[i][col] == 'Q') return false;

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if(board[i][j] == 'Q') return false;

    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j] == 'Q') return false;
    return true;
}
void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if(row == n) {
        ans.push_back(board);
        return;
    }
    for(int j = 0; j < n; j++) {
        if(isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans; 
    nQueens(board, 0, n, ans);
    return ans;
}
int main() {
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;
    vector<vector<string>> solutions = solveNQueens(n);
    if (solutions.empty()) {
        cout << "No solutions found!" << endl;
    } else {
        cout << "Total Solutions: " << solutions.size() << endl;
        for(int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << i + 1 << ":" << endl;
            for(int j = 0; j < n; j++) {
                cout << solutions[i][j] << endl;
            }
            cout << endl;
        }
    }
}