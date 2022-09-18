'''
Author: xinao_seven_
Date: 2022-09-18 13:46:50
LastEditTime: 2022-09-18 14:58:37
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\numpy\\ans.py

'''



from tokenize import Double
import numpy as np


# data
OldCoordinates = np.array([[2886585.7645,531481.3787],[2891839.8474,479813.8408],
                [2861398.5526,509387.9347],[2819325.6136,524901.0211]])
NewCoordinates = np.array([[29459.3157,31382.5801],[34711.8401,-20285.8858],[4271.0302,9289.6093],
                [-37802.0351,24804.2516]])

# print(NewCoordinates)
class Two_dimensional:

# 坐标参数解算
    def GetParameters(self):
    
        L = []
        B = np.empty((0,4))
        for i in range(OldCoordinates.shape[0]):
            x_left = OldCoordinates[i][0]
            y_l = OldCoordinates[i][1]

            x_right = NewCoordinates[i][0]
            y_r = NewCoordinates[i][1]

            L.extend((x_right - x_left,y_r - y_l))

            ParameterMatrix1 = np.array([1,0,-y_l,x_left])
            ParameterMatrix2 = np.array([0,1,x_left,y_l])
            B_temp = np.row_stack((ParameterMatrix1,ParameterMatrix2))
            B = np.append(B,B_temp,axis=0)
    
        L = np.array([L]).T


        a = np.linalg.inv(np.dot(B.T,B))

        b = np.dot(B.T,L)
        x = np.dot(a,b)
        return x
#       print(x)


# GetParameters()


    def GetNewCoordinates(self,x:Double,y:Double) :

        # 解算参数
        res = self.GetParameters()
        TemporaryMatrix = np.array([[1,0,-y,x],[0,1,x,y]])
        startmat = np.array([x,y])
        startmat = np.matrix(startmat).T


        # 实际计算公式
        ans = startmat + np.dot(TemporaryMatrix,res)
        # print(ans)
        return ans


if __name__ == "__main__":
    calc = Two_dimensional()
    firstcoor = calc.GetNewCoordinates(2860046.5165,524597.2659).T
    secondcoor = calc.GetNewCoordinates(2865890.2564,519087.7625).T

    res = np.vstack((firstcoor,secondcoor))
    print(res)


    