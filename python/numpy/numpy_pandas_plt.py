import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x = np.arange(9).reshape(3,3)
np.save('test',x)
print((np.load('test.npy')))
np.random.seed(19)
ran = np.random.randint(100,200,(3,4))
print(ran)
# np.random.shuffle(ran) #随机打乱轴

# print(np.random.choice(ran,(2,2),replace=False))

xpoint = ran[1,:]
print((xpoint))
yPoint = xpoint

data = np.arange(0,4*np.pi,0.5)
z = np.sin(data)
y = np.cos(data)

plt.plot(data,y,"*-r")
plt.plot(data,z,".:y")
plt.plot(data,data,"s-.k")
plt.show()