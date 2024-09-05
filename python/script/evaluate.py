'''
Author: xinao_seven_
Date: 2023-03-24 15:24:01
LastEditTime: 2024-03-05 22:13:10
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \1xingao\python\script\evaluate.py

'''

import pyautogui
import os
import time

def funx(path :str):
    time.sleep((1))
    xy1 = list(pyautogui.locateAllOnScreen(path,confidence=0.7)) 
    for xy in xy1:
        x,y = pyautogui.center(xy) # 寻找图片的中心 
        pyautogui.click(x-22,y)
flag = 1
count = 0
while True:
    time.sleep(3)
    if pyautogui.locateOnScreen("assist\\pingjia.png",confidence=0.8):
        pyautogui.click(pyautogui.locateOnScreen("assist\\pingjia.png",confidence=0.8))
        time.sleep(3)
        print("enter the elvatuation")
        flag = 1
    if pyautogui.locateOnScreen("assist\\very.jpg",confidence=0.7):
        if(flag >=2):
            print("******again agree prase******")
            flag = 1
        flag += 1
        funx("assist\\very.jpg")
        print("very agree click is ok")
        pyautogui.scroll(-500)
        if pyautogui.locateOnScreen("assist\\agree.jpg",confidence=0.7):
            funx("assist\\agree.jpg")
            print("agree click is ok")
            pyautogui.click(pyautogui.locateOnScreen("assist\\bia.png",confidence=0.7))
            pyautogui.typewrite("jiaoxueyanjinfengquyoumo")
            pyautogui.press("space")
            pyautogui.typewrite( "xueshushuipinggaofudsbsksmxhd")
            pyautogui.press("space")
            pyautogui.typewrite("duidaixueshengrenzhenrenzhenyindaoffwagawgaffw")
            pyautogui.press("space")
            print("input prase text is fine")
            pyautogui.click(pyautogui.locateOnScreen("assist\\tijiao.jpg",confidence=0.7))
            time.sleep(10)
            pyautogui.click(pyautogui.locateOnScreen("assist\\queding.jpg",confidence=0.7))
            time.sleep(10)
            pyautogui.click(pyautogui.locateOnScreen("assist\\queding.jpg",confidence=0.7))
            
        else:
            print("error")
    
    else:
        count += 1
        if(count == 10):
            break
        print("none")
    print("one evaluation is fine")        
    print("--------------------------------------------------------")   