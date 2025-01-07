#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> matrix){
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void make_row_zero(vector<vector<int>> &matrix,int row){
    
    for(int i=0; i<matrix[0].size(); i++){
        matrix[row][i] = 0;
    }
}

void make_col_zero(vector<vector<int>> &matrix,int col){
    
    for(int j=0; j<matrix.size(); j++){
        matrix[j][col] = 0;
    }
}

void set_matrix_zero(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> zeros;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                zeros.push_back(temp);
            }
        }
    }

    for(auto it : zeros){
        int row = it[0];
        int col = it[1];

        make_row_zero(matrix,row);
        make_col_zero(matrix,col);

    }
}

void set_matrix_zero_better(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> rows(row,0);
    vector<int> cols(col,0);

    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(rows[i] || cols[j]){
                matrix[i][j] = 0;
            }
        }
    }


}
int main() {

vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
print(matrix);
set_matrix_zero_better(matrix);
print(matrix);

return 0;
}