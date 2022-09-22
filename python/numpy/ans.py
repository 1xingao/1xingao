'''
Author: xinao_seven_
Date: 2022-09-18 13:46:50
LastEditTime: 2022-09-22 12:20:00
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\numpy\\ans.py

'''

import math

import xlrd
import numpy as np
from typing import *
from numpy.linalg import inv
import pandas as pd


# print(NewCoordinates)
class Two_dimensional:
    def __init__(self, old: np.ndarray, new: np.ndarray) -> None:
        # data
        self.OldCoordinates = old
        self.NewCoordinates = new
        self.V = np.empty((0, 1))
        

    # 坐标参数解算
    def GetParameters(self) -> np.ndarray:
        L = []
        B = np.empty((0, 4))
        for i in range(self.OldCoordinates.shape[0]):
            x_left = self.OldCoordinates[i][0]
            y_left = self.OldCoordinates[i][1]

            x_right = self.NewCoordinates[i][0]
            y_right = self.NewCoordinates[i][1]

            L.extend((x_right - x_left, y_right - y_left))

            ParameterMatrix = np.array([[1, 0, -y_left, x_left],
                                        [0, 1, x_left, y_left]])
            B_temp = np.matrix(ParameterMatrix)
            B = np.append(B, B_temp, axis=0)

        # print(B)
        # print(L)
        L = np.array([L]).T

        Nbb = inv(np.dot(B.T, B))

        W = np.dot(B.T, L)
        x = np.dot(Nbb, W)
        v = np.dot(B, x) - L
        # print(v.shape)
        self.V = np.append(self.V, v, axis=0)
        
        # m = math.sqrt(a**2+b**2)-1
        # alpha = math.atan(b/a)
        # print(m,math.degrees(alpha))
        return x

    #       print(x)

    # GetParameters()

    def GetNewCoordinates(self, x: float, y: float) -> np.ndarray:
        # 解算参数
        res = self.GetParameters()

        # print(res[2]*206265)
        TemporaryMatrix = np.array([[1, 0, -y, x], [0, 1, x, y]])
        startmat = np.array([x, y])
        startmat = np.matrix(startmat).T

        # 实际计算公式
        ans = startmat + np.dot(TemporaryMatrix, res)
        # self.V = np.append(self.V,np.dot(TemporaryMatrix,res)-(ans+startmat),axis=0)
        # print(ans)
        return ans


# 三维七参数坐标转换
class Three_dimensional:
    def __init__(self, old: np.ndarray, new: np.ndarray) -> None:
        self.OldCoordinates = old
        self.NewCoordinates = new
        self.V = np.empty((0, 1))
        self.ParameterList = np.empty((7, 0))

    def GetParameters(self) -> np.ndarray:
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
            B_temp = np.row_stack(
                (ParameterMatrix1, ParameterMatrix2, ParameterMatrix3))
            B = np.append(B, B_temp, axis=0)

        L = np.array([L]).T

        Nbb = inv(np.dot(B.T, B))

        W = np.dot(B.T, L)
        x = np.dot(Nbb, W)
        self.V = np.dot(B, x) - L
        self.ParameterList = x
        return x

    def GetNewCoordinates(self, x: float, y: float, z: float) -> np.ndarray:
        # 解算参数
        res = self.GetParameters()
        TemporaryMatrix = np.array([[1, 0, 0, 0, -z, y, x],
                                    [0, 1, 0, z, 0, -x, y],
                                    [0, 0, 1, -y, x, 0, z]])
        startmat = np.array([x, y, z])
        startmat = np.matrix(startmat).T

        # 实际计算公式
        ans = startmat + np.dot(TemporaryMatrix, res)
        # print(ans)
        return ans


def excel2matrix(path: str) -> np.ndarray:
    data = xlrd.open_workbook(path)
    table = data.sheets()[0]
    nrows = table.nrows  # 行数
    ncols = table.ncols  # 列数
    datamatrix = np.zeros((nrows, ncols))
    for i in range(ncols):
        cols = table.col_values(i)
        datamatrix[:, i] = cols
    # print(datamatrix)
    return datamatrix


def threedTest() -> None:
    old = excel2matrix("python\\numpy\\data\\old.xlsx")
    # print(old)
    new = excel2matrix("python\\numpy\\data\\new.xlsx")
    calcT = Three_dimensional(old, new)
    res = calcT.GetParameters()
    res[3:-1] *= 206265
    data = res.reshape(7, 1)
    data_list = map(lambda x: x[0], data)

    ser = pd.Series(data_list, index=['x0', 'y0', 'z0', 'x', 'y', 'z', 'k'])
    print("参数列表：")
    print(ser)
    print("改正数：")
    Correction = pd.DataFrame(calcT.V.reshape((6, 3)) * -1,
                              columns=['x', 'y', 'z'])
    print(Correction)


def twodTest() -> None:
    OldCoordinates = np.array([[2886585.7645, 531481.3787],
                               [2891839.8474, 479813.8408],
                               [2861398.5526, 509387.9347],
                               [2819325.6136, 524901.0211]])
    NewCoordinates = np.array([[29459.3157, 31382.5801],
                               [34711.8401,
                                -20285.8858], [4271.0302, 9289.6093],
                               [-37802.0351, 24804.2516]])
    calc = Two_dimensional(OldCoordinates, NewCoordinates)
    firstcoor = calc.GetNewCoordinates(2860046.5165, 524597.2659).T
    print("-------------------------------------------------")
    print("改正数:")
    Correlation = pd.DataFrame(calc.V.reshape((4, 2)) * -1, columns=['x', 'y'])
    print(Correlation)
    secondcoor = calc.GetNewCoordinates(2865890.2564, 519087.7625).T

    res = np.vstack((firstcoor, secondcoor))
    print("-------------------------------------------------")
    print("转换后坐标:")
    coor = pd.DataFrame(res, columns=['x', 'y'])
    print(coor)

    print("---------------------------------------------------")
    print("各个参数:\n")
    # print(calc.ParameterList.shape)
    data = calc.GetParameters()
    data_list = map(lambda x: x[0], data)
    x = pd.Series(data_list, index=['x0', 'y0', 'a', 'b'])
    print(x)


def main() -> None:
    print("-----------------------------------------")
    print("二维坐标转换：")
    twodTest()

    print("-----------------------------------------")
    print("三维坐标转换：")
    threedTest()


if __name__ == "__main__":
    main()
