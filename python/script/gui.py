'''
Author: xinao_seven_
Date: 2022-11-09 09:51:53
LastEditTime: 2022-11-09 13:14:28
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\script\\gui.py

'''

import pyautogui
import time
# x,y = pyautogui.size()
# ps,py = pyautogui.position()
# pyautogui.click(1566,84,duration=1)


path = "D:\\abcin\\code\\1xingao\\python\\script\\Genshin_impact.py"

def main():
    time.sleep(3)
    with open(path,"r",encoding='utf-8') as f:
        for i in f.readlines():
            pyautogui.typewrite(i,interval=0.1)
            
            time.sleep(1)


if __name__ == "__main__":
    main()