'''
Author: xinao_seven_
Date: 2021-10-05 22:27:03
LastEditTime: 2022-11-01 15:52:14
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\bilibili_find.py

'''
import requests as r
import xlwt
from lxml import etree

#demo
# r_text = requests.get(url=base_url).text
# tree = etree.HTML(r_text)
# li_list = tree.xpath("//*[@id='app']/div[2]/div[2]/ul/li[1]/div[2]/div[2]/a")
# print(li_list[0].text)
# print(li_list[0].get("href"))
#/div[2]/div[2]/a
base_url = "https://www.bilibili.com/v/popular/rank/all"

headres = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"
}
# //*[@id="app"]/div/div[2]/div[2]/ul/li[1]/div/div[2]/a

def get_url(url):
    respone = r.get(url=url, headers=headres).text
    tree = etree.HTML(respone)
    li_list = tree.xpath("//*[@id='app']/div/div[2]/div[2]/ul/li")
    link_list = []
    for i in range(len(li_list)):
        a_list = li_list[i].xpath("div/div[2]/a")
        link = a_list[0].get("href")
        link_list.append(link)
    #print(link_list)
    return link_list


def get_text(url):
    respone = r.get(url=url, headers=headres).text
    tree = etree.HTML(respone)
    li_list = tree.xpath("//*[@id='app']/div/div[2]/div[2]/ul/li")
    text_list = []
    for i in range(len(li_list)):
        a_list = li_list[i].xpath("div/div[2]/a")
        link = a_list[0].text
        text_list.append(link)

    return text_list
# //*[@id="app"]/div/div[2]/div[2]/ul/li[1]/div/div[2]/div/a/span/text()

def get_upname(url):
    respone = r.get(url=url, headers=headres).text
    tree = etree.HTML(respone)
    li_list = tree.xpath("//*[@id='app']/div/div[2]/div[2]/ul/li")
    upname_list = []
    for i in range(len(li_list)):
        link = li_list[i].xpath("div/div[2]/div/a/span/text()")

        upname_list.append(link)

    return upname_list


def save_data(datalist):
    book = xlwt.Workbook(encoding="utf-8")
    sheet = book.add_sheet('bilibli', cell_overwrite_ok=True)
    col = ("全站排行", "视频链接", "视频名", "视频up主")
    for i in range(len(col)):
        sheet.write(0, i, col[i])
    for i in range(100):
        sheet.write(i + 1, 0, i + 1)
    for i in range(3):
        new_list = datalist[i]
        for j in range(len(new_list)):
            sheet.write(j + 1, i + 1, new_list[j])

    book.save("bilibili_TOP.xls")


if __name__ == "__main__":
    link_list = get_url(base_url)
    text_list = get_text(base_url)
    upname_list = get_upname(base_url)
    all_list = [link_list, text_list, upname_list]
    save_data(all_list)
    # print(len(link_list))



# / html/body/div[2]/div[2]/div[2]/div[2]/p[4]/span

# /html/body/div[2]/div[2]/div[2]/div[2]/p[4]/span/span[1]

