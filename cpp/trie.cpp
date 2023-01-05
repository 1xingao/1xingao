/*
 * @Author: xinao_seven_
 * @Date: 2023-01-05 17:56:25
 * @LastEditTime: 2023-01-05 18:28:07
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\trie.cpp
 * 
 */


#include<bits/stdc++.h>

using namespace std;

struct Trie{

    array<Trie*,2> child{nullptr,nullptr};
    int sum ;
    Trie():sum(0){}
};


class Solution {
public:

    Trie* root = nullptr;
    static constexpr int H = 14;

    void put(int num)
    {
        Trie* node = root;
        for(int i=H;i>=0;i--){
            int n = (num>>i)&1;
            if(node->child[n] == nullptr){
                node->child[n] = new Trie();
            }
            node = node->child[n];
            node->sum++;
        }
    }

    int get(int num,int high)
    {
        Trie* node = root;
        int sum = 0 ;
        for(int i=H;i>=0;i--){
            int nbit = (num>>i)&1;
            if((high>>i)&1){//当前最大值的这个位上有值为1
                if(node->child[nbit]!=nullptr){
                    sum += node->child[nbit]->sum;
                }
                if(node->child[nbit^1]==nullptr){
                    return sum;
                }
                node = node->child[nbit^1];
            }else{ //当前high此位上没有值，则只有num这一位上
                if(node->child[nbit]==nullptr){
                    return sum;
                }
                node = node->child[nbit];
            }
            
        }
        sum += node->sum;
        return sum;
    }
    int f(vector<int>& nums, int x) {
        root = new Trie();
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            put(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        return f(nums, high) - f(nums, low - 1);
    }

};
int main()
{
    return 0;
}