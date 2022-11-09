'''
Author: xinao_seven_
Date: 2022-11-08 18:10:31
LastEditTime: 2022-11-08 23:42:01
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\hello.py

'''
print("""

   __   _                        __               __  __ _                      
  / /  (_) _ __   _   _ __  __  / _|  ___   _ __  \ \/ /(_) _ __    __ _   ___  
 / /   | || '_ \ | | | |\ \/ / | |_  / _ \ | '__|  \  / | || '_ \  / _` | / _ \ 
/ /___ | || | | || |_| | >  <  |  _|| (_) || |     /  \ | || | | || (_| || (_) |
\____/ |_||_| |_| \__,_|/_/\_\ |_|   \___/ |_|    /_/\_\|_||_| |_| \__,_| \___/ 
                                                                                
""")
import matplotlib.pyplot as plt
import numpy as np
import math
 
i = np.linspace(-math.pi,math.pi)
print(i)
a = 1
x=a*(2*np.sin(i)-np.sin(2*i))
y=a*(2*np.cos(i)-np.cos(i*2))

plt.plot(x,y)
plt.show()