import pyautogui
import os
import time

def funx(path :str):
    time.sleep((1))
    xy1 = list(pyautogui.locateAllOnScreen(path,confidence=0.8)) 
    for xy in xy1:
        x,y = pyautogui.center(xy) # 寻找图片的中心 
        pyautogui.click(x-22,y)
    

while True:
    if pyautogui.locateOnScreen("D:\\abcin\\test.jpg",confidence=0.8):
        funx("D:\\abcin\\test.jpg")
        print("ok")
        pyautogui.scroll(-500)
        if pyautogui.locateOnScreen("D:\\abcin\\all.jpg",confidence=0.8):
            funx("D:\\abcin\\all.jpg")
            pyautogui.click(pyautogui.locateOnScreen("D:\\abcin\\bia.jpg",confidence=0.9))
            pyautogui.typewrite("asdfawfawfawfawddawdfawdqawfawfgawfawfwafawgawgawawdawdawda")
            
        else:
            print("error")
            
        break
    else:
        print("none")