/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        string all;
        for(int i=0;i<s.length();i+=2*k){
            string temp = s.substr(i,4);
            for(int j=0;j<k;j++){
                string temp2;
                temp2 = temp[j];
                temp[j] = temp[k-1];
                temp[k-1] = temp2;
            }
            all+=temp;
        }
        return all;
    }
};
// @lc code=end

