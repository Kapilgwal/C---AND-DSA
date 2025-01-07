#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotateMatrix(vector<vector<int>> &matrix){
    vector<vector<int>> ans;

    for(int i=0; i<matrix.size(); i++){
       vector<int> temp;
       for(int j=matrix[0].size()-1; j>=0; j--){
        temp.push_back(matrix[j][i]);
       }

       ans.push_back(temp);
    }

    matrix = ans;

}

void rotateMatrixBetter(vector<vector<int>> &matrix){

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0; i<matrix.size(); i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(matrix);
    rotateMatrixBetter(matrix);
    print(matrix);

    return 0;
}