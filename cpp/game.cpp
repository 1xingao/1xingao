/*
 * @Author: xinao_seven_
 * @Date: 2021-10-05 22:27:03
 * @LastEditTime: 2022-11-06 23:42:36
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\game.cpp
 * 
 */
#include <iostream>
void change(int x, int y, int book, int array_2[3][3])
{
    if (book == 1)
    {
        array_2[x][y] = book;
    }
    else
    {
        array_2[x][y] = book;
    }
}
bool game(int array_3[3][3])
{
    int x, y, book, n = 1;
    while (n > 0)
    {

        std::cin >> x;
        std::cin >> y;
        std::cin >> book;

        std::cout << "-------------" << std::endl;
        change(x - 1, y - 1, book, array_3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                std::cout << array_3[i][j] << " ";
            }
            std::cout << "" << std::endl;
        }
        std::cout << "-------------" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (array_3[i][1] == array_3[i][2] && array_3[i][1] == array_3[i][0] && array_3[i][1] != 0)
            {
                return 1;
            }
            if (array_3[1][i] == array_3[2][i] && array_3[1][i] == array_3[0][i] && array_3[1][i] != 0)
            {
                return 1;
            }
        }
        if ((array_3[0][0] == array_3[1][1] && array_3[1][1] == array_3[2][2] && array_3[1][1] != 0) ||
            (array_3[0][2] == array_3[1][1] && array_3[1][1] == array_3[2][0] && array_3[1][1] != 0))
        {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (array_3[i][j] != 0)
                {
                    count += 1;
                }
            }
        }
        if (count == 9)
        {
            return 0;
        }
    }
    return 0;
}
int main()
{
    int array_1[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array_1[i][j] = 0;
        }
    }
    int c = game(array_1);
    //std::cout << c << std::endl;

    return 0;
}