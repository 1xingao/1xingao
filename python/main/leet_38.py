"""
题目描述
1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1 
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"

"""
class Solution:
    def countAndSay(self, n: int) -> str:
        first = "1"#用于记录第n项的外观数组描述
        
        for _ in range(n-1):
            res = first[0]#记录外观数组的第一项
            count = 1#记录数组出现次数
            none = "" #临时构造记录数组
            for j in range(1,len(first)):
                tes = first[j]
                if res != tes:
                    none =none+ str(count) + str(res)
                    count = 0
                    res = tes
                count +=1
            first =none+ str(count) + str(res)
        return first
