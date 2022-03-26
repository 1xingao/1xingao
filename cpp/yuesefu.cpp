#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> strd{1,2,3,4,1};//快速初始化
    
    unordered_map<int, int> hash;
    for (int x : strd)
    {
        hash[x]++;
    }
    cout << hash.count(1);//count函数返回key的出现此时
    cout<<hash[1];
    return 0;
}