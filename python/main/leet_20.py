"""
有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

"""
class Solution:
    def isValid(self, s: str) -> bool:
        top = -1     #栈顶指针
        data1 = ["(","{","["]
        data2 = [")","}","]"]
        zhan =[]
        for i in range(len(s)):
            if s[i] in data1:
                zhan.append(s[i])
                top +=1
            elif s[i] in data2 and zhan :
                temp = zhan[top]
                for j in range(3):
                    if data1[j]==temp and s[i] != data2[j]:
                        return False
                top -= 1
                zhan.pop()
            else:
                return False
        return True if  not zhan else False
c = Solution()
str_te = "]"
ret = c.isValid(str_te)
print(ret)