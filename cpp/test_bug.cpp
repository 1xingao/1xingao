#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getchar1(char tage,int k,string& answerKey)
    {
        int ans = 0;
        int n = answerKey.length();
        for(int left =0,right=0,sum=0;right<n;right++){//sum用来储存传进来的参数在窗口的数量，传进来的参数                                                 
            if(answerKey[right]!=tage){//是需要更改的占用k的次数，当大于k的时候left++就会寻找新的最大
                sum++;
            }
            while(sum>k){
                if(answerKey[left++]!=tage){
                    sum--;
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getchar1('T',k,answerKey),getchar1('F',k,answerKey));
    }
    
};

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0;
        int left = 0;
        int sum = 0;
        // for(int i=0;i<nums.size();++i){
        //     sum+=nums[i];
        //     while(sum>=target){
        //         len = len==0?i-left+1:min(i-left+1,len);
        //         sum-=nums[left++];
        //     }
        // }
        // return len;
        for(int i =0;i<nums.size();i++){
            while(sum<target){
                sum+=nums[left];
                if(left<nums.size()){
                    left++;
                }
            }
            len = len==0?left-i:min(left-i,len);
            sum-=nums[i];
        }
        return len;
    }
};
class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int left=0;left<n-2;left++){
            int mid = left+1;
            int right = n-1;
            if(nums[left]>0){
                return res;//如果最左边数大于零则之后都没有满足的
            }
            if(left>0&&nums[left]==nums[left-1]){//left去重
                continue;
            }
            int target = -nums[left];
            while(mid<right){
                if(nums[mid]+nums[right]==target){
                    res.push_back(vector<int>{nums[left],nums[right],nums[mid]});
                    
                    while(right>mid&&nums[right]==nums[right-1]){
                        right--;
                    }
                    while(right>mid&&nums[mid]==nums[mid+1]){
                        mid++;
                    }
                    right--;
                    mid++;
                }else if(nums[mid]+nums[right]>target){
                    right--;
                }else{
                    mid++;
                }
            }
            
        }
        return res;
    }
};
int main()
{
    Solution3 test;
    vector<int> trs = {-1,0,1,2,-1,-4};
    //-4,-1,-1,0,1,2
    vector<vector<int>>res =  test.threeSum(trs);
    cout<<res.size();
    return 0;
}