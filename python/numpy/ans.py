'''
Author: xinao_seven_
Date: 2022-09-18 13:46:50
LastEditTime: 2022-09-19 11:23:22
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\numpy\\ans.py

'''


from typing import *
import numpy as np
import math


Vector = np.array(list[float])


# print(NewCoordinates)
class Two_dimensional:
    def __init__(self) -> None:
        # data
        self.OldCoordinates = np.array([[2886585.7645, 531481.3787], [2891839.8474, 479813.8408],
                                        [2861398.5526, 509387.9347], [2819325.6136, 524901.0211]])
        self.NewCoordinates = np.array([[29459.3157, 31382.5801], [34711.8401, -20285.8858], [4271.0302, 9289.6093],
                                        [-37802.0351, 24804.2516]])

    # 坐标参数解算
    def GetParameters(self) -> Vector:
        L = []
        B = np.empty((0, 4))
        for i in range(self.OldCoordinates.shape[0]):
            x_left = self.OldCoordinates[i][0]
            y_left = self.OldCoordinates[i][1]

            x_right = self.NewCoordinates[i][0]
            y_right = self.NewCoordinates[i][1]

            L.extend((x_right - x_left, y_right - y_left))

            ParameterMatrix = np.array([[1, 0, -y_left, x_left],[0, 1, x_left, y_left]])
            B_temp = np.matrix(ParameterMatrix)
            B = np.append(B, B_temp, axis=0)

        # print(B)
        # print(L)
        L = np.array([L]).T

        Nbb = np.linalg.inv(np.dot(B.T, B))

        W = np.dot(B.T, L)
        ParameterList = np.dot(Nbb, W)

        a ,b= ParameterList[2],ParameterList[3]
        m = math.sqrt(a**2+b**2)-1
        alpha = math.atan(b/a)
        print(m,math.degrees(alpha))
        return ParameterList

    #       print(x)

    # GetParameters()

    def GetNewCoordinates(self, x: float, y: float) -> Vector:
        # 解算参数
        res = self.GetParameters()
        
        # print(res[2]*206265)
        TemporaryMatrix = np.array([[1, 0, -y, x], [0, 1, x, y]])
        startmat = np.array([x, y])
        startmat = np.matrix(startmat).T

        # 实际计算公式
        ans = startmat + np.dot(TemporaryMatrix, res)
        # print(ans)
        return ans



# 三维七参数坐标转换
class Three_dimensional:
    def __init__(self) -> None:
        self.OldCoordinates = np.array([[]])
        self.NewCoordinates = np.array([[]])

    def GetParameters(self) -> Vector:
        L = []
        B = np.empty((0, 7))
        for i in range(self.OldCoordinates.shape[0]):
            x_left = self.OldCoordinates[i][0]
            y_left = self.OldCoordinates[i][1]
            z_left = self.OldCoordinates[i][2]

            x_right = self.NewCoordinates[i][0]
            y_right = self.NewCoordinates[i][1]
            z_right = self.NewCoordinates[i][2]

            L.extend((x_right - x_left, y_right - y_left, z_right - z_left))

            ParameterMatrix1 = np.array([1, 0, 0, 0, -z_left, y_left, x_left])
            ParameterMatrix2 = np.array([0, 1, 0, z_left, 0, -x_left, y_left])
            ParameterMatrix3 = np.array([0, 0, 1, -y_left, x_left, 0, z_left])
            B_temp = np.row_stack((ParameterMatrix1, ParameterMatrix2, ParameterMatrix3))
            B = np.append(B, B_temp, axis=0)

        L = np.array([L]).T

        Nbb = np.linalg.inv(np.dot(B.T, B))

        W = np.dot(B.T, L)
        x = np.dot(Nbb, W)

        return x

    def GetNewCoordinates(self, x: float, y: float, z: float) -> Vector:
        # 解算参数
        res = self.GetParameters()
        TemporaryMatrix = np.array([[1, 0, 0, 0, -z, y, x], [0, 1, 0, z, 0, -x, y], [0, 0, 1, -y, x, 0, z]])
        startmat = np.array([x, y, z])
        startmat = np.matrix(startmat).T

        # 实际计算公式
        ans = startmat + np.dot(TemporaryMatrix, res)
        # print(ans)
        return ans


def main() -> None:
    calc = Two_dimensional()
    firstcoor = calc.GetNewCoordinates(2860046.5165, 524597.2659).T
    secondcoor = calc.GetNewCoordinates(2865890.2564, 519087.7625).T

    res = np.vstack((firstcoor, secondcoor))
    print(res)
    


if __name__ == "__main__":
    main()


