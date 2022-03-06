/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin =0 ,end = height.size()-1;
        int area=0,max_area = 0;
        while(begin!=end){
            area = (end-begin)*min(height[begin],height[end]);
            if(max_area<area){
                max_area=area;
            }
            if(height[begin]>height[end]){
                end--;
            }else{
                begin++;
            }
        }
        return max_area;

    }
    //双指针双向查找，每次移动的是短的那一端
};
// @lc code=end

