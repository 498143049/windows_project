//
// Created by dubing on 2017/6/28.
// question:
// 
// url:
#include <bits/stdc++.h>
struct tree{
    tree * left = nullptr;
    tree * right = nullptr;
    int  count=0;
    tree(int c):count(c){

    }
};
void deleteTree(tree *p){
    if(p!= nullptr){
        deleteTree(p->left);
        deleteTree(p->right);
        delete(p);
    }
}
int robot(int &s1,int &target,int time,tree *root){
    if(root== nullptr||time>=32) return 0;
    if(target&(0x8000000>>time)) {
        if(s1&(0x8000000>>time)){
            //
        }
        else{

        }
    }
    else{
        if(s1&(0x8000000>>time)){

        }
        else{

        }
    }

}
using namespace std;
int main() {
    freopen("../../toutiao_test2/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num,target;
    while (cin>>num>>target){
        vector<int> vt(num);
        int ans = 0;
        tree * root = new tree(1);
        for (int i = 0; i < num; ++i) {
            cin>>vt[i];
            tree * temproot = root;
            for(auto j=0;j<32;++j){
                if(vt[i]&(0x8000000>>j)){
                    if(temproot->left){
                        temproot = temproot->left;
                        temproot->count++;
                    }
                    else{
                        temproot->left =  new tree(1);
                        temproot = temproot->left;
                    }
                }
                else{
                    if(temproot->right){
                        temproot = temproot->right;
                        temproot->count++;
                    }
                    else{
                        temproot->right =  new tree(1);
                        temproot = temproot->right;
                    }
                }
            }

        }

        for (int i = 0; i < num; ++i){
            tree * temproot = root;
            for(auto j=0;j<32;++j){
                if(target&(0x8000000>>j)){
                    //m==1

                }
                else{
                    //m==0
                    ans+=root->left->count;
                }
            }
        }

        deleteTree(root);

        cout<<ans<<endl;

    }
}