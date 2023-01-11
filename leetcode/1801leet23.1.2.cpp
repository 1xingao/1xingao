/*
 * @Author: xinao_seven_
 * @Date: 2023-01-02 16:42:50
 * @LastEditTime: 2023-01-08 10:50:16
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\1801leet23.1.2.cpp
 * 
 */
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>> buy;//大顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> sell;//小顶堆
        int res=0,mod=1e9+7;
        for(auto&v:orders)
            if(v[2]==0)
            {
                while(v[1]&&!sell.empty()&&sell.top().first<=v[0])
                {
                    auto [price,amoumt]=sell.top();
                    sell.pop();
                    if(amoumt<=v[1])
                        res=(res-amoumt+mod)%mod,v[1]-=amoumt;
                    else
                        sell.push({price,amoumt-v[1]}),res=(res-v[1]+mod)%mod,v[1]=0;
                }
                if(v[1])
                    buy.push({v[0],v[1]}),res=(res+v[1])%mod;
            }
            else
            {
                while(v[1]&&!buy.empty()&&buy.top().first>=v[0])//找到出价最高的买家
                {
                    auto [price,amoumt]=buy.top();
                    buy.pop();
                    if(amoumt<=v[1]){
                        res=(res-amoumt+mod)%mod;
                        v[1]-=amoumt;
                    }
                    else
                        buy.push({price,amoumt-v[1]}),res=(res-v[1]+mod)%mod,v[1]=0;
                }
                if(v[1])
                    sell.push({v[0],v[1]}),res=(res+v[1])%mod;
            }
        return res;
    }
};


class Solution {
public:
    bool canPoss(unordered_map<char,int>& more,unordered_map<char,int>&less){
        if(more.size()-less.size()>2){return false;}
        else if(more.size()-less.size()==2){
            for(auto &[fir,sec]:more){
                if(sec == 1){return true;}
            }
            return false;
        }
        bool flag = false;
        for(auto &[fir,sec]:more){
            if(sec >= 2){
                flag = true;
                break;
            }
        }
        for(auto &[fir,sec]:less){
            if(sec>=2&&flag){
                return true;
            }
        }
        return false;
    }
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> hash1,hash2;
        for(char &c:word1){
            hash1[c]++;
        }
        for(char &c:word2){
            hash2[c]++;
        }
        if(hash1.size()==hash2.size()){return word1.size()==word2.size();}
        if(hash1.size()>hash2.size()){
            return canPoss(hash1,hash2);
        }
        return canPoss(hash2,hash1);
        
    }
};
int main()
{
    return 0;
}