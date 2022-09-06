#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                res.push_back(asteroids[i]);
            }
            else{
                //int flag=asteroids[i];
                for(int j=i-1;j>=0&&res.empty()==0;j--){    
                    if((asteroids[i]+asteroids[j])<0){
                        res.pop_back();
                    }
                    else if((asteroids[i]+asteroids[j])>0){
                        break;   
                    }
                    else{
                        res.pop_back();
                        break;
                    }
                    if(j==0) res.push_back(asteroids[i]);
                }
            }
        }
        return res;
    }
};
int main()
{
    int c ;
    cin >> c;
    cout << c;
    return 0;
}