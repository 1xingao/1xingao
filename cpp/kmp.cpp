#include <bits/stdc++.h>
using namespace std;
// namespace std;

// kmp算法具体实现
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    //判断重复的子字符串
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0){
            return true;
        }
        int len = s.size();
        int next[s.size()];
        getNext(next,s);
        if(next[len-1]!=0&&len%(len-next[len-1])==0){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution test;
    string s1 = {"mississippi"};
    string s2 = {"issip"};
    int n = test.strStr(s1, s2);
    cout << n;
}