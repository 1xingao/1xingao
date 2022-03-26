/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>hash;
        for(auto& x:s){
            hash[x]++;
        }
        vector<pair<char,int>>res(hash.begin(),hash.end());
        sort(res.begin(),res.end(),[](pair<char,int> a,pair<char,int> b){
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
// @lc code=end

