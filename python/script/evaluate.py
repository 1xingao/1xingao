'''
Author: xinao_seven_
Date: 2023-03-24 15:24:01
LastEditTime: 2023-03-24 22:01:21
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
    xy1 = list(pyautogui.locateAllOnScreen(path,confidence=0.8)) 
    for xy in xy1:
        x,y = pyautogui.center(xy) # 寻找图片的中心 
        pyautogui.click(x-22,y)
    
count = 0
while True:
    time.sleep(3)
    if pyautogui.locateOnScreen("assist\\pingjia.jpg",confidence=0.8):
        pyautogui.click(pyautogui.locateOnScreen("assist\\pingjia.jpg",confidence=0.8))
        time.sleep(3)
    if pyautogui.locateOnScreen("assist\\very.jpg",confidence=0.8):
        funx("assist\\very.jpg")
        print("ok")
        pyautogui.scroll(-500)
        if pyautogui.locateOnScreen("assist\\agree.jpg",confidence=0.8):
            funx("assist\\agree.jpg")
            pyautogui.click(pyautogui.locateOnScreen("assist\\bia.jpg",confidence=0.8))
            pyautogui.typewrite("asdfawfawfdgiehfiwhoifh")
            pyautogui.press("space")
            pyautogui.typewrite( "awiofawjawdawdawawfawddawdfawdqawfa")
            pyautogui.press("space")
            pyautogui.typewrite("wfgawfawfwafawgawgawawdawdawda")
            pyautogui.press("space")
            pyautogui.click(pyautogui.locateOnScreen("assist\\tijiao.jpg",confidence=0.869))
            time.sleep(3)
            pyautogui.click(pyautogui.locateOnScreen("assist\\queding.jpg",confidence=0.869))
            time.sleep(4)
            pyautogui.click(pyautogui.locateOnScreen("assist\\queding.jpg",confidence=0.869))
            
        else:
            print("error")
            
        
    else:
        count += 1
        if(count == 10):
            break
        print("none")