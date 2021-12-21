/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        
        while(num >= 10){
            int ads =  0;
            while(num!= 0){
                ads+=num%10;
                num = num /10;
            
            }
            num = ads;
        }
        return num;
            
    }
};
// @lc code=end

