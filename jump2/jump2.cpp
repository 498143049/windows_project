//
// Created by dubing on 2017/6/28.
//https://leetcode.com/problems/jump-game-ii/#/description
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include "string"
int jump(vector<int>& nums) {
    int size = nums.size();
    if(size==0||size==1) return 0;
    if(size==2) return 1;
    vector<int> ans(size,1000);
    ans[size-1] = 0;
    for(int i = size -2; i >= 0; --i) {
        if(nums[i]>=size-i-1){
            ans[i] = 1;
            continue;
        }
        //贪心做优化
        for(int j = 1; j <=nums[i]; ++j){
            ans[i] = min(ans[i],1+ans[i+j]);
        }
    }
    return ans[0];
}
int main() {

    string letters = "ABCabc";
    std::partition(letters.begin(), letters.end(), [](char A){ return A>'Z';});
    cout<<letters<<endl;
    vector<int> vt = {2,3,0,1,4};
    cout<<jump(vt)<<endl;
}
//rest[i] = sell[i-1]
//Substitute this in to buy[i] we now have 2 functions instead of 3:
//
//buy[i] = max(sell[i-2]-price, buy[i-1])
//sell[i] = max(buy[i-1]+price, sell[i-1])