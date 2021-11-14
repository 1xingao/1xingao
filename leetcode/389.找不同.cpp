/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        //找不同就用所有的字符加一起求出多出来那个
        int at=0,as= 0;
        for (char ts:s){    
            as+=ts;
        }
        for(char tt:t){
            at+=tt;
        }
        return at-as;
    }
};
// @lc code=end

