# -*-coding:utf-8 -*-
import io
import sys
#改变标准输出的默认编码
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding='utf8')
import random as r

def main():
    base = Base()
    way = Game_way()
    while True:
        print("第",base.count,"次游戏")
        #玩家输入
        #user = int(input('请出拳 0（石头） 1（剪刀） 2（布）3（退出游戏）'))

        #电脑与最少策略对战
        if base.count %2 == 1:
            user = way.calc_sort(base.ston,base.jiandao,base.bravo)
        else:
            user = base.ran_dom()

        if user >=4:
            print("输入错误")
            continue
        elif user == 3:
            break
        last = user
        peo_c = base.ran_dom()

        base.battle(peo_c, user)
        print("当前游戏比分：")
        print("电脑1（随机策略）：",base.my_lost,"电脑2（随机与最少交替使用）：",base.my_win)
        if base.count > 2000:
            break


class Base:
    def __init__(self):
        self.count = 1                  #次数
        self.my_win= 0
        self.my_lost = 0
        self.ston = 0
        self.bravo =0
        self.jiandao = 0                #英文不够，拼音来凑

    def ran_dom(self):                  #电脑的随机策略

        ran = r.randint(0,2)

        return ran

    def battle(self,pc_s,pe_s):         #对比函数

        if pc_s or pe_s == 0:
            self.ston+=1
        if pc_s or pe_s == 1:           #后面的策略计数
            self.jiandao+=1
        if pc_s or pe_s == 2:
            self.bravo +=1
        if (0 == pc_s and 1 == pe_s) or (1 == pc_s and 2 == pe_s) or(2 == pc_s and 0 == pe_s):
            print("电脑胜利")
            self.count+=1
            self.my_lost +=1
        elif (1 == pc_s and 0 == pe_s) or (2 == pc_s and 1 == pe_s) or(0 == pc_s and 2 == pe_s):
            print("玩家获胜")
            self.count += 1
            self.my_win += 1
        elif pc_s == pe_s:

            print("平局")
            self.count += 1

class Game_way():
    def last_way(self,last):
        print("此时为上一个策略")
        return last

    def calc_sort(self,ston,jiandao,brave):

        sort_list = []

        sort_list.append(ston)
        sort_list.append(jiandao)
        sort_list.append(brave)
        sort_list.sort()

        print("此时为最少策略")
        if sort_list[0] == ston:
            return 0
        if sort_list[0] == jiandao:
            return 1
        if sort_list[0] == brave:
            return 2

if __name__ == "__main__":
    main()

#demo
# num = 1
# yin_num = 0
# shu_num = 0
# while num <= 3:
#     if shu_num == 2 or yin_num == 2:
#         break
#     user = int(input('请出拳 0（石头） 1（剪刀） 2（布）'))
#     if user > 2:
#         print('不能出大于2的值')
#     else:
#         data = ['石头', '剪刀', '布']
#         com = random.randint(0, 2)
#         print("您出的是{}，电脑出的是{}".format(data[user], data[com]))
#         if user == com:
#             print('平局')
#             continue
#         elif (user == 0 and com == 1) or (user == 1 and com == 2) or (user == 2 and com == 0):
#             print('你赢了')
#             yin_num += 1
#         else:
#             print('你输了')
#             shu_num += 1
#     num += 1
