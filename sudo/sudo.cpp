//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;


bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if(i==9) return true;
    if(j==9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != '0') return solveSudoku(board, i, j+1);

    for(char c='1'; c<='9'; c++)
    {
        if(check(board, i, j, c))
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)) return true;
            board[i][j] = '0';
        }
    }

    return false;
}

int main() {
    vector<vector<char>> ch(9,vector<char>(9,0));
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j)
            cin>>ch[i][j];
    solveSudoku(ch,0,0);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j) {
            cout << ch[i][j];
            if(j!=8){
                cout  <<" ";
            }
        }
        if(i!=9){
            cout <<"\n";
        }

    }


}