class Solution(object):
    def maxAscendingSum(self, nums:int) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        li = []
        alel = []
        s= 0
        c= 0
        for i in nums:
            if s<i:
                s = i
                li.append(i)
            elif s>i:
                c=0
                for j in li:
                    c+=j
                alel.append(c)
                li=[]
                s=i
                li.append(s)
            elif s==i:
                s=i
                c=0
                for j in li:
                    c+=j
                alel.append(c)
                li=[]
                li.append(s)

        c=0
        for j in li:
            c+=j
        alel.append(c)
                
        max_re = max(alel)
        return max_re
c= [5,5,6,6,6,9,1,2]
b= Solution()
b.maxAscendingSum(c)