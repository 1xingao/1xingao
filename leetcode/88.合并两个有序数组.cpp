/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            for (int i = 0;i<nums2.size();i++){
                nums1[i] = nums2[i];
            }
        }
        else if (m!=0 && n != 0){
            for (int j =0;j<nums2.size();j++){
                nums1[j+m] = nums2[j];
            }
            sort(nums1.begin(),nums1.end());
            /*
            int nums3[m+n];
            int i=0,j=0,c= 0;
            while (1){
                if (nums1[i] <= nums2[j]){
                    nums3[c] = nums1[i];
                    c++;i++;
                }
                else if (nums1[i] >nums2[j]){
                    nums3[c] = nums2[j];
                    c++;j++;
                }
                else if (i ==m)
            }
            */
        }
    }
};
// @lc code=end

