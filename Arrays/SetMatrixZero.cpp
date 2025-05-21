#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int col0 = 1; // yeh flag batayega agar first column me kahin 0 mila to
    int r = matrix.size();
    int c = matrix[0].size();

    // Step 1: Matrix ke first row aur first column ko markers ki tarah use
    // karenge
    for (int i = 0; i < r; i++) {
        // agar kisi row ka pehla element 0 hai, to col0 = 0 set kar do
        if (matrix[i][0] == 0)
            col0 = 0;

        // baaki columns ke liye, agar 0 milta hai to uske row aur column ka
        // pehla element 0 mark karo
        for (int j = 1; j < c; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // row ke first cell ko 0 set karo
                matrix[0][j] = 0; // column ke first cell ko 0 set karo
            }
        }
    }

    // Step 2: Matrix ko second row and second column se traverse karke 0 lagao
    // using markers
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            // agar uske row ya column ka pehla cell 0 hai to us cell ko 0 bana
            // do
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Agar first row ka pehla cell 0 hai to poori first row ko 0 karo
    if (matrix[0][0] == 0) {
        for (int j = 0; j < c; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Agar col0 flag 0 hai to poori first column ko 0 karo
    if (col0 == 0) {
        for (int i = 0; i < r; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    setZeroes(matrix);

    // Output the modified matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}