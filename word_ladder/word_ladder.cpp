//
// Created by dubing on 2017/6/28.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;
vector<string> join(int n,string src, string s,unordered_map<string, string> &unmap){
    vector<string> sans;
    sans.resize(n);
    sans[--n] = s;
    while(n--) {
        sans[n] = src;
        src = unmap[src];
    }
    return sans;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> unset;
    unordered_map<string, string> unmap;
    vector<vector<string>>  ans;
    for (auto i : wordList)
    {
        unset.insert(i);
    }
    // 广度优先搜索
    int count = 2;
    queue<string> qu;
    if (unset.find(endWord) == unset.end()) return ans;
    qu.push(beginWord);
    while (!qu.empty())
    {
        int num = qu.size();
        bool find = false;
        while (num--)
        {
            string s = qu.front(), src = qu.front();
            qu.pop();
            for (int i = 0; i < s.size(); ++i)
            {
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    char letter = s[i];
                    s[i] = j;
                    if (s == endWord){
                        //找到结果
                        find = true;
                        ans.push_back(join(count,src,s,unmap));
                    }
                    if (!find&&unset.find(s) != unset.end())
                    {
                        unmap[s] = src; //s 是唯一一个
                        qu.push(s);
                        unset.erase(s);
                    }
                    s[i] = letter;
                }
            }
        }
        if(find) return ans;
        count++;
    }
    return ans;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> unset;
    for (auto i : wordList)
    {
        unset.insert(i);
    }
    // 广度优先搜索
    int count = 2;
    queue<string> qu;
    qu.push(beginWord);
    while (!qu.empty())
    {
        int num = qu.size();
        while (num--)
        {
            string s = qu.front();
            qu.pop();
            for (int i = 0; i < s.size(); ++i)
            {
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    char letter = s[i];
                    s[i] = j;
                    if (s == endWord)
                        return count;
                    if (unset.find(s) != unset.end())
                    {
                        qu.push(s);
                        unset.erase(s);
                    }
                    s[i] = letter;
                }
            }
        }
        count++;
    }
    return 0;
}

int main() {
    vector<string> vt = {"hot","dot","dog","lot","log","cog"};
    string s1  = "hit";
    string s2 = "cog";
    auto s = findLadders(s1,s2,vt);
    cout<<s.size()<<endl;
}