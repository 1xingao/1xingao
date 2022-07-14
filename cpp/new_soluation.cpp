#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//前缀树/字典树的实现
class Trie {
public:
    bool end;//是否为结尾
    vector<Trie*> children;
    Trie() :children(26),end (false){
        
        
    }
    
    void insert(string word) {
        Trie* temp = this;
        for(char c:word){
            if(temp->children[c-'a'] == nullptr){
                temp->children[c-'a'] = new Trie();
            }
            temp = temp->children[c-'a'];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        Trie* temp  =this;
        for(char c:word){
            if(temp->children[c-'a'] == nullptr){
                return false;
            }
            temp = temp->children[c-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        Trie* temp  =this;
        for(char c:prefix){
            if(temp->children[c-'a'] == nullptr){
                return false;
            }
            temp = temp->children[c-'a'];
        }
        return true;

    }
};


//字典树实现前缀和后缀查找
class WordFilter {
public:
    struct Trie{
        vector<int>idxs;
        Trie* children[26]{nullptr};
    };
    Trie* t1 = new Trie();
    Trie* t2 = new Trie();
    void insert(Trie* p,string& word,int idx,bool isturn)
    {
        int n = word.size();
        p->idxs.push_back(idx);
        for(int i =isturn?n-1:0;i>=0&&i<n;i +=isturn?-1:1){
            if(!p->children[word[i]-'a']){
                p->children[word[i]-'a'] = new Trie();
            }
            p = p->children[word[i]-'a'];
            p->idxs.push_back(idx);
        }
    }
    int battle(string& a,string& b)
    {
        int n = a.size(),m = b.size();
        auto p = t1;
        for(int i=0;i<n;i++){
            int u = a[i]-'a';
            if(p->children[u] == nullptr){
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp1 = p->idxs;
        p = t2;
        for(int i=m-1;i>=0;i--){
            int u = b[i]-'a';
            if(p->children[u] == nullptr){
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp2 = p->idxs;
        int e = temp1.size(),f=temp2.size();
        for(int i=e-1,j=f-1;i>=0&&j>=0;){
            if(temp1[i] > temp2[j]){
                i--;
            }else if(temp1[i] < temp2[j]){
                j--;
            }else{
                return temp1[i];
            }
        }
        return -1;
    }
    WordFilter(vector<string>& words) {
        int s = words.size();
        for(int i=0;i<s;i++){
            insert(t1,words[i],i,false);
            insert(t2,words[i],i,true);
        }
    }
    
    int f(string pref, string suff) {
        return battle(pref,suff);
    }
};
int main()
{

    return 0;
}