from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stack = []
        res = [0] * n
        last = 0
        for log in logs:
            spl = log.split(':')

            idx = int(spl[0])
            lent = int(spl[2])

            if spl[1] == "start":
                if len(stack) != 0:
                    res[stack[-1]] += lent - last

                stack.append(idx)
                last = lent
            else:
                res[stack[-1]] += lent - last + 1
                stack.pop()
                last = lent + 1

        return res

    def makeLargestSpecial(self, s: str) -> str:
        left = cnt = 0
        if len(s) < 2:
            return s
        subs = []
        for i in range(len(s)):
            if s[i] == '1':
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    subs.append('1' + self.makeLargestSpecial(s[left + 1:i]) +
                                '0')
                    left = i + 1
        subs.sort(reverse=True)
        return "".join(subs)


# 这是装饰器函数，参数 func 是被装饰的函数
def logger(func):
    def wrapper(*args, **kw):
        print('主人，我准备开始执行：{} 函数了:'.format(func.__name__))

        # 真正执行的是这行。
        func(*args, **kw)

        print('主人，我执行完啦。')

    return wrapper


@logger
def add(x, y):
    print('{} + {} = {}'.format(x, y, x + y))


# 带参数的装饰器实现
def say_hello(contry):
    def wrapper(func):
        def deco(*args, **kwargs):
            if contry == "china":
                print("你好!")
            elif contry == "america":
                print('hello.')
            else:
                return

            # 真正执行函数的地方
            func(*args, **kwargs)

        return deco

    return wrapper


# 解方程
def solveEquation(equation: str) -> str:
    mid = equation.split('=')
    mid[0] = mid[0].replace("-", "+-")
    mid[1] = mid[1].replace("-", "+-")
    left = mid[0].split("+")
    right = mid[1].split("+")
    leftnum = 0
    rightnum = 0
    leftx = 0
    rightx = 0
    for i in left:
        if i == "":
            continue
        if i == "x":
            leftx += 1
        elif i == "-x":
            leftx -= 1
        elif 'x' in i:
            leftx += int(i[0:len(i) - 1])
        else:
            leftnum += int(i)
    for i in right:
        if i == "":
            continue
        if i == "x":
            rightx += 1
        elif i == "-x":
            rightx -= 1
        elif 'x' in i:
            rightx += int(i[0:len(i) - 1])
        else:
            rightnum += int(i)
    x = leftx - rightx
    c = rightnum - leftnum
    if x == 0 and c == 0:
        return "Infinite solutions"
    elif x == 0 and c != 0:
        return "No solution"
    return "x=" + str(int(c / x))


class Solution1:
    def connect(self, root):
        global last
        que = []
        que.append(root)
        while len(que) != 0:
            n = len(que)
            for i in range(n):
                node = que.pop()
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
                if i != 0:
                    last.next = node
                last = node
        return root
