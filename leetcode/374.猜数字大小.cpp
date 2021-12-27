/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int left = 1,right = n;
        int retur;
        while(left <= right){
            int mid = left+(right - left)/2;
            retur = guess(mid);
            if(retur == -1){
                right = mid-1;
            }
            else if(retur == 1){
                left = mid+1;//二分查找一生之敌
                
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end

