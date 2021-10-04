#写各种脚本的文件
#作者：xinao-seven
#用处：狗子的机组作业

import xlwt

tage_list = ["型号","CPU","显卡","硬盘","内存","屏幕"]
data_list_1 = ["暗影精灵7plus","i7-11800H","RTX-3080","三星PM9A1 1TB","16G DDR4-3200MHz","17.3寸2kIPS"]
date_list_2 = ["华为matebook13s","i7-11370H","Intel Iris Xe Graphics核显","三星PM981a 512GB","LPDDR4X-3733MHz",
"13.4寸2kIPS"]
data_list_3 = ["联想拯救者Y7000P","i7-11800H","RTX-3050Ti","三星PM9A1 512GB"," 16G DDR4-3200MHz",
"15.6寸1080pIPS"]
data_list_4 = ["华硕飞行堡垒9","i7-11400H","RTX-3050","三星PM991a 512GB"," 16G DDR4-3200MHz","15.6寸1080pIPS"]
data_list_5 = ["ThinkBook14p","R7-5800H","vega8核显","海力士PC711 512GB"," 16G DDR4-3200MHz","14寸2kIPS"]
data_list_6 = ["ThinkPad X1 Carbon 2021","i7-1165G7","英特尔锐炬® Xe 显卡","三星PM9A1 1TB",
" 16G LPDDR4X-4266MHz","14寸2kIPS"]
data_list_7 = ["联想小新Pro16","R7-5800H","GTX1650","美光2300 512GB"," 16G DDR4-3200MHz","16寸2kIPS"]
data_list_8 = ["ROG幻13","R7-5800HS","GTX1650MAX-Q","西数SN530 512GB"," 16G LPDDR4X-4266MHz","13.4寸2kIPS"]

book = xlwt.Workbook(encoding="utf-8")
sheet = book.add_sheet('cpm',cell_overwrite_ok=True)
for i in range(len(tage_list)):
    sheet.write(0,i,tage_list[i])
for i in range(len(tage_list)):
    sheet.write(1,i,data_list_1[i])
for i in range(len(tage_list)):
    sheet.write(2,i,date_list_2[i])
for i in range(len(tage_list)):
    sheet.write(3,i,data_list_3[i])
for i in range(len(tage_list)):
    sheet.write(4,i,data_list_4[i])
for i in range(len(tage_list)):
    sheet.write(5,i,data_list_5[i])
for i in range(len(tage_list)):
    sheet.write(6,i,data_list_6[i])
for i in range(len(tage_list)):
    sheet.write(7,i,data_list_7[i])
for i in range(len(tage_list)):
    sheet.write(8,i,data_list_8[i])
book.save("assist/computer_list.xls")