#include <stdio.h>
bool isPalindrome(int x)
{
    if (x < 0 || x % 10 == 0 && x != 0)
    {
        return false;
    }
    int size = 0;
    while (x > size)
    {
        size = size * 10 + x % 10;
        x /= 10;
    }
    return x == size || x == size / 10;
}
int main()
{
    int x = 121;
    isPalindrome(x);
    return 0;
}