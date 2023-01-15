/*
 * @Author: xinao_seven_
 * @Date: 2022-10-19 21:03:55
 * @LastEditTime: 2023-01-15 16:50:58
 * @LastEditors: xinao_seven_
 * @Description: 字典树板子
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\dict_tree.hpp
 *
 */
#include <bits/stdc++.h>

using namespace std;

//前缀树/字典树的实现
class Trie
{
public:
    bool end; //是否为结尾
    vector<Trie *> children;
    Trie() : children(26), end(false) {}
    ~Trie() {for (auto &i:children){delete i;}}
    
    void insert(string word)
    {
        Trie *temp = this;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                temp->children[c - 'a'] = new Trie();
            }
            temp = temp->children[c - 'a'];
        }
        temp->end = true;
    }

    bool search(string word)
    {
        Trie *temp = this;
        for (char c : word)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return temp->end;
    }

    bool startsWith(string prefix)
    {
        Trie *temp = this;
        for (char c : prefix)
        {
            if (temp->children[c - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return true;
    }
    bool startwithdot(string word)
    {
        return dfs(this, word, 0);
    }
    /// @brief 匹配含有占位符的单词如.bac/ab.c
    /// @param root
    /// @param word
    /// @param index
    /// @return 是否存在这个单词(含占位符)
    bool dfs(Trie *root, string word, int index)
    {
        if (index >= word.size())
        {
            return root->end;
        }
        char c = word[index];
        if (c != '.')
        {
            if (root->children[c - 'a'] != nullptr)
            {
                return dfs(root->children[c - 'a'], word, index + 1);
            }
            else
            {
                return false;
            }
        }
        for (Trie *temp : root->children)
        {
            if (temp != nullptr && dfs(temp, word, index + 1))
            {
                return true;
            }
        }
        return false;
    }
};

//字典树实现前缀和后缀查找
class WordFilter
{
public:
    struct Trie
    {
        vector<int> idxs;
        Trie *children[26]{nullptr};
    };
    Trie *t1 = new Trie();
    Trie *t2 = new Trie();
    void insert(Trie *p, string &word, int idx, bool isturn)
    {
        int n = word.size();
        p->idxs.push_back(idx);
        for (int i = isturn ? n - 1 : 0; i >= 0 && i < n; i += isturn ? -1 : 1)
        {
            if (!p->children[word[i] - 'a'])
            {
                p->children[word[i] - 'a'] = new Trie();
            }
            p = p->children[word[i] - 'a'];
            p->idxs.push_back(idx);
        }
    }
    int battle(string &a, string &b)
    {
        int n = a.size(), m = b.size();
        auto p = t1;
        for (int i = 0; i < n; i++)
        {
            int u = a[i] - 'a';
            if (p->children[u] == nullptr)
            {
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp1 = p->idxs;
        p = t2;
        for (int i = m - 1; i >= 0; i--)
        {
            int u = b[i] - 'a';
            if (p->children[u] == nullptr)
            {
                return -1;
            }
            p = p->children[u];
        }
        vector<int> &temp2 = p->idxs;
        int e = temp1.size(), f = temp2.size();
        for (int i = e - 1, j = f - 1; i >= 0 && j >= 0;)
        {
            if (temp1[i] > temp2[j])
            {
                i--;
            }
            else if (temp1[i] < temp2[j])
            {
                j--;
            }
            else
            {
                return temp1[i];
            }
        }
        return -1;
    }
    /// @brief
    /// @param words
    WordFilter(vector<string> &words)
    {
        int s = words.size();
        for (int i = 0; i < s; i++)
        {
            insert(t1, words[i], i, false);
            insert(t2, words[i], i, true);
        }
    }

    int f(string pref, string suff)
    {
        return battle(pref, suff);
    }
};

