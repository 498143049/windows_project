//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int robot(int left,int right,vector<int>& nums,vector<vector<int>> &array){
    if(array[left][right]!=0) return array[left][right];
    int maxvalue = 0;
    for(int k=left;k<=right;++k){
        int a =  nums[left-1]*nums[k]*nums[right+1];
        int b = robot(left,k-1,nums,array);
        int c = robot(k+1,right,nums,array);
        maxvalue = max(maxvalue, a+b +c);
    }
    array[left][right] = maxvalue;
    return maxvalue;
}

int maxCoins(vector<int>& nums) {
    // Write your code here
    int size = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> array(size+2,vector<int>(size+2,0));
    int temp =  robot(1,2,nums,array);
    //temp = 280;
    return temp;
}
int main() {
    vector<int> vt={4,1,5,10};
  //  cout<<"xxxx"<<endl;
    cout<<maxCoins(vt)<<endl;
}