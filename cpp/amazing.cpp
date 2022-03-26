#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
//保存各种花式操作
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>hash;
        for(auto& x:s){
            hash[x]++;
        }
        vector<pair<char,int>>res(hash.begin(),hash.end());
        sort(res.begin(),res.end(),[](pair<char,int> a,pair<char,int> b){//lamb
            return a.second>b.second;
        });
        string rns;
        for(auto a:res){
            for(int i=0;i<a.second;i++){
                rns.push_back(a.first);
            }
        }
        return rns;

    }
};
//以普通函数的方式实现自定义排序规则
bool mycomp(int i, int j) {
    return (i < j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};
