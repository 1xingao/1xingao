# -*- coding: utf-8 -*-

import os
import re
import xlrd
import xlwt

AllClass_list = []

PersonName = []

for i in range(42):
    AllClass_list.append('')


def getfiles():
    dirs = os.listdir(os.getcwd())
    xls_list = []
    for i in dirs:
        if os.path.splitext(i)[1] == '.xls':
            xls_list.append(i)
    return xls_list


def jag(ifmt):
    st = []
    for i in range(1, 18):
        st.append(i)
    for line in ifmt.splitlines():
        if line.find('周]') != -1:
            week = re.split(r'[,\[\]]', line)
            n = 0
            m = -1
            if week[-2] == '周':
                n = 1
            elif week[-2] == '单周':
                m = 0
            else:
                m = 1
            del week[-2:]
            for items in week:
                if items.find('-') != -1:
                    item = re.split(r'-', items)
                    for i in range(int(item[0]), int(item[1]) + 1):

                        if n == 1:
                            if i in st:
                                st.remove(i)
                        if m == 0:
                            if (i in st) & (i % 2 == 1):
                                st.remove(i)
                        if m == 1:
                            if (i in st) & (i % 2 == 0):
                                st.remove(i)
                else:
                    if int(items) in st:
                        st.remove(int(items))
    st.remove(9)
    return st


def echfl(xls):
    wb = xlrd.open_workbook(xls)
    sheet_1 = wb.sheet_by_index(0)
    title = sheet_1.cell_value(0, 0)
    title = title.split()
    PersonName.append(title[1])
    n = 0
    for i in range(3, 9):
        for j in range(1, 8):
            kb = str(jag(sheet_1.cell_value(i, j)))
            if kb != '[]' and len(kb) != 56:
                AllClass_list[n] += title[1] + kb + ',' + '\n'
            if len(kb) == 56:
                AllClass_list[n] += title[1] + ',' + '\n'
            n += 1


def data_dill():
    xls_list = getfiles()
    for xls in xls_list:
        echfl(xls)
    print(PersonName, '\n', '共', len(PersonName), '人')

def class_set():
    book = xlwt.Workbook()
    sheet_1 = book.add_sheet('无课表')
    week = ['一', '二', '三', '四', '五', '六', '日']
    i = 1
    for days in week:
        sheet_1.write(0, i, '星期' + days)
        i += 1
    j = 102
    for i in range(1, 6):
        sheet_1.write(i, 0, (str(j) + '节').zfill(5))
        j += 202
    n = 0
    i = j = 1
    for i in range(1, 6):
        for j in range(1, 8):
            sheet_1.write(i, j, AllClass_list[n])
            n += 1
    beizhu = "备注:1.课表未统计第九周和十八周之后的课程,每个名字后面的是没有课程的周数,若没有数字则代表此时段一直没有课"
    qita = "        2.周三0506节是体育课时间大一学生都有课,由于空白则被前面单元格占用"
    sheet_1.write(6, 0, beizhu)
    sheet_1.write(7, 0, qita)
    book.save('无课表.xls')
    print('无课表制作完成，请将其移出该目录，防止下次运行出错！')


if __name__ == '__main__':
    data_dill()
    class_set()
