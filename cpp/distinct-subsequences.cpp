#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1,vector<uint64_t>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(j>i){
                    continue;
                }
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        return dp[s.size()][t.size()];
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int temp:asteroids){
            while(st.size()!=0&&temp<0&&st.back()>0){
                if(st.back() > -temp){
                    temp = st.back();
                    st.pop_back();
                }else if(st.back() == temp){
                    st.pop_back();
                    break;
                }else{
                    st.pop_back();
                    
                }
            }
        }
        
        return st;
    }
};
int main()
{
    string s {"babag"};
    string t{"bag"};
    Solution test;
    int res = test.numDistinct(s,t);
    return res >0?1:2;
    return 0;
}