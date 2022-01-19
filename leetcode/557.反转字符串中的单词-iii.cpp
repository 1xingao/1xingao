/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string all;
        string retu;
        int i = 0;
        while(i<s.size()){
            if(s[i]==' '){
                reverse(all.begin(),all.end());
                retu+=all;
                retu+=' ';
                all.clear();
                i++;
                continue;
            }
            all+=s[i];i++;
        }
        reverse(all.begin(),all.end());
        return retu+=all;
    }
};
// @lc code=end

