#include<string>
#include<iostream>
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
int main()
{
    Solution s;
    string st ="TFFT";
    int k = 1;
    int max_s = s.maxConsecutiveAnswers(st,k);
    cout<<max_s;
    return 0;
}