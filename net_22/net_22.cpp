//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int robot(int time,int num,string &ss,vector<vector<int>> &vt,int &k){
    if(num<0) num+=k;
    if(time<0)  return 0;  //访问条件


    if(ss[time]!='X'){
        return robot(time-1,num-(ss[time]-'0')%k,ss,vt,k);
    }
}
int main() {
    freopen("../../net_22/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    string ss; int k;
    cin>>ss>>k;
    vector<vector<int>> vt(ss.size(),vector<int>(k,0));

}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main(){
//        string s;
//        int n;
//        while (cin >> s >> n){
//                int len = s.length();
//                vector<vector<long long int>> dp(len + 1, vector<long long int>(n, 0));
//                dp[0][0] = 1;
//                for (int i = 1; i <= s.length(); i++){
//                        for (int j = 0; j < n; j++){
//                                if (s[i - 1] == 'X'){
//                                        for (int k = 0; k < 10; k++){
//                                                int newJ = (j * 10 + k) % n;
//                                                dp[i][newJ] += dp[i - 1][j];
//                                            }
//                                    }
//                                else{
//                                        int newJ = (j * 10 + (s[i - 1] - '0')) % n;
//                                        dp[i][newJ] += dp[i - 1][j];
//                                    }
//                            }
//                    }
//                cout << dp[len][0] << endl;
//            }
//        return 0;
//}