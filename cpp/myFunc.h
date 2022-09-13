/*
 * @Author: xinao_seven_
 * @Date: 2022-09-07 12:48:22
 * @LastEditTime: 2022-09-11 22:37:16
 * @LastEditors: xinao_seven_
 * @Description:线代运算和string函数
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\myFunc.h
 *
 */

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

class string_Fun
{
public:
    const std::vector<std::string> split(const std::string &str, const std::string &pattern)
    {
        std::vector<std::string> result;
        std::string::size_type begin, end;

        end = str.find(pattern);
        begin = 0;

        while (end != std::string::npos)
        {
            if (end - begin != 0)
            {
                result.push_back(str.substr(begin, end - begin));
            }
            begin = end + pattern.size();
            end = str.find(pattern, begin);
        }

        if (begin != str.length())
        {
            result.push_back(str.substr(begin));
        }
        return result;
    }
};
template <class T>
class Matrix
{
private:
    std::vector<std::vector<T>> element;
    int row = 0;
    int col = 0;

    /// @brief 初始化
    /// @param i 
    /// @param j 
    /// @param value 
    void Init(int i = 0, int j = 0, T value = 0)
    {
        this->row = i;
        this->col = j;
        this->element = std::vector<std::vector<T>>(i, std::vector<T>(j, value));
    }

public:
    int getRow() { return this->row; }
    int getCol() { return this->col; }
    std::vector<std::vector<T>> getElement() { return this->element; }

    void setElement(T value, int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
        {
            this->element[i][j] = value;
        }
    }

    Matrix(std::vector<std::vector<T>> &matrix) : row(matrix.size()), col(matrix[0].size())
    {
        this->element = matrix;
    }

    Matrix(int i = 0, int j = 0, T value = 0)
    {
        Init();
    }

    Matrix(std::vector<T> &diag)
    {
        int range = 0;
        int n = diag.size();
        Init(n, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    this->element[i][j] = diag[range++];
                }
            }
        }
    }
    
    /// @brief 格式化输出
    void Print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                std::cout << element[i][j];
                if (j == col - 1)
                {
                    break;
                }
                std::cout << ",";
            }
            std::cout << std::endl;
        }
    }
    /// @brief 索引器
    /// @param i 
    /// @param j 
    /// @return 对应值
    T at(int i, int j)
    {
        return element[i][j];
    }
    std::vector<T> at(int i)
    {
        return element[i];
    }

    std::vector<T> operator[](int row)
    {
        return element[row];
    }

    Matrix<T> operator+(T value)
    {
        Matrix<T> res(row,col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.setElement(element[i][j] + value,i,j);
            }
        }
        return res;
    }

    Matrix<T> operator-(T value)
    {
        Matrix<T> res(row,col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.setElement(element[i][j] - value,i,j);
            }
        }
        return res;
    }
    Matrix<T> operator+(Matrix<T> &newele)
    {
        if (row == newele.getRow() && col == newele.getCol())
        {
            std::vector<std::vector<T>> res(row, std::vector<T>(col, 0));
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    res[i][j] = element[i][j] + newele[i][j];
                }
            }
            Matrix ret{res};
            return ret;
        }
        return element;
    }
    Matrix<T> operator-(Matrix<T> &newele)
    {
        if (row == newele.getRow() && col == newele.getCol())
        {
            std::vector<std::vector<T>> res(row, std::vector<T>(col, 0));
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    res[i][j] = element[i][j] - newele[i][j];
                }
            }
            Matrix ret{res};
            return ret;
        }
        return element;
    }

    Matrix<T> operator*(Matrix<T> &ele)
    {
        Matrix<T> result(ele.getRow(), ele.getCol());
        if (col == ele.getRow())
        {
            for (int row1 = 0; row1 < row; row1++)
            {
                int row2 = 0;
                for (int column2 = 0; column2 < ele.getCol(); column2++)
                {
                    T Sum = 0;
                    for (int column1 = 0; column1 < col; column1++)
                    {
                        Sum += element[row1][column1] * ele[column1][row2];
                    }
                    result.setElement(Sum, row1, column2);
                    row2++;
                }
            }
        }
        return result;
    }
    /// @brief 乘法
    /// @param value 
    /// @return 
    Matrix<T> operator*(T value)
    {
        Matrix<T> res(row,col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.setElement(element[i][j] * value,i,j);
            }
        }
        return res;
    }
    /// @brief 转置
    /// @return 
    Matrix<T> Transpose()
    {
        Matrix res(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.setElement(element[i][j], j, i);
            }
        }
        return res;
    }
    /// @brief 代数余子式求和
    /// @param martix 
    /// @return 
    double Determinant(Matrix<T> &martix)
    {
        double sum = 0;
        int sign = 1;
        if (martix.getRow() == 1)
        {
            return martix[0][0];
        }
        for (int i = 0; i < martix.getRow(); i++)
        {
            Matrix<T> tempmatrix(martix.getRow() - 1, martix.getCol() - 1);
            for (int j = 0; j < martix.getRow() - 1; j++)
            {
                for (int k = 0; k < martix.getCol() - 1; k++)
                {
                    tempmatrix.setElement(martix[j + 1][k >= i ? k + 1 : k], j, k);
                }
            }
            sum += sign * martix[0][i] * Determinant(tempmatrix);
            sign *= (-1);
        }
        return sum;
    }
    /// @brief 伴随矩阵
    /// @param martix 
    /// @return Matrix对象
    Matrix<T> Complement(Matrix<T> &martix)
    {
        Matrix result(martix.getRow(), martix.getCol());
        if (martix.getRow() == martix.getCol()) //方阵
        {
            for (int i = 0; i < martix.getRow(); i++)
            {
                for (int j = 0; j < martix.getCol(); j++)
                {
                    //生成aij的余子式矩阵
                    std::vector<std::vector<T>> complement(martix.getRow() - 1, martix.getCol() - 1); // n-1阶
                    Matrix<T> martix1(complement);
                    int row = 0;
                    for (int k = 0; k < martix.getRow(); k++)
                    {
                        int column = 0;
                        if (k == i) //去除第i行
                            continue;
                        for (int l = 0; l < martix.getRow(); l++)
                        {
                            if (l == j) //去除第j列
                                continue;
                            martix1.setElement(martix[k][l], row, column++);
                        }
                        row++;
                    }
                    result.setElement(pow(-1, i + j) * Determinant(martix1), i, j);
                }
            }
        }
        return result.Transpose();
    }

    /// @brief 求逆
    /// @return Matrix对象
    Matrix<T> Inverse()
        {
            Matrix<T> result (col,row);
            if (row == col)//方阵
            {
                Matrix<T> martix(element);
                if (Determinant(martix) != .0)
                {
                    if (martix.getRow() > 1)
                        result = Complement(martix) * (1 / Determinant(martix));
                    else
                        result.setElement( 1 / martix[0][0],0,0);
                }
            }
            return result;
        }
};
