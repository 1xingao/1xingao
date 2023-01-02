'''
Author: xinao_seven_
Date: 2022-12-29 19:25:25
LastEditTime: 2022-12-29 19:31:49
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\2211leet.py

'''
def countCollisions(directions: str) -> int:
        stack = []
        res = 0
        for idx in list(directions):
            if len(stack) == 0:
                stack.append(idx)
                continue
            s = stack[-1]+idx
            if s== 'RL' or s == 'RS' or s=='SL':
                stack.pop()
                stack.append('S')
                res += 2 if s == 'RL' else 1            
            else:
                stack.append(idx)
        return res

if __name__ == "__main__":
    res = countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR")
    print(res)