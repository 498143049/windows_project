//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
class Matrix {
public:
    int n, m;
    vector<vector<int>> mat;
    Matrix(vector<int>& vec) {
        n = 1;
        m = vec.size();
        mat.emplace_back(vec);
    }

    Matrix(int n, int m) : n(n), m(m) {
        mat.resize(n, vector<int>(m, 0));
    }

    Matrix(int n = 0) : n(n), m(n) {
        //构造矩阵B
        mat.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            mat[i][i] = 1;
            if (i + 1 < n)
                mat[i+1][i] = 1;
            else
                mat[0][i] = 1;
        }
    }

    Matrix& operator * (Matrix& b) {
        Matrix temp(this->n, b.m);
        if (this->m == b.n) {
            for (int i = 0; i < temp.n; ++i) {
                for (int j = 0; j < temp.m; ++j) {
                    for (int k = 0; k < m; ++k) {
                        temp.mat[i][j] += this->mat[i][k] * b.mat[k][j];
                    }
                }
            }
        }
        *this = temp;
        return *this;
    }

    Matrix& operator % (int k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                this->mat[i][j] %= k;
            }
        }
        return *this;
    }

    void display() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << mat[i][m-1] << endl;
        }
        for (int i = 0; i < m - 1; ++i) {
            cout << mat[n-1][i] << " ";
        }
        cout << mat[n-1][m-1] << endl;
    }
};

int main() {
    freopen("../../net_21/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int n, k;
    while (cin >> n >> k) {
        vector<int> vecs(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecs[i];
        }
        Matrix ans(vecs);
        Matrix mul(n);
        while (k != 0) {
            //快速幂求余算法
            if (k & 1) {
                ans = ans * mul % 100;
            }
            mul = mul * mul % 100;
            k >>= 1;
        }
        ans.display();
    }
    return 0;
}