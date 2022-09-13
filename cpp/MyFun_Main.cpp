/*
 * @Author: xinao_seven_
 * @Date: 2022-09-08 16:22:46
 * @LastEditTime: 2022-09-11 22:48:41
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\MyFun_Main.cpp
 * 
 */

#include "myFunc.h"
using namespace std;

int main()
{
    vector<double> test = {1.1,2.2,3.3};
    Matrix<double> mat{test};
    mat.Print();
    auto res = mat.getElement();
    std::cout << std::endl;
    std::cout << mat.at(1,1);
    std::cout<<mat[0][0]<<endl;
    vector<double> tes = {2.2,3.3,4.4};
    Matrix<double> matr(tes);
    auto r = mat*matr;
    r.Print();
    cout << "----------------------------------"<<endl;
    vector<vector<double>> ma {{1.,1.},{2.,1.}};
    Matrix<double> arr(ma);
    arr.Print();
    double rese = arr.Determinant(arr);
    cout <<rese;
    return 0;
}