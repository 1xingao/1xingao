'''
Author: xinao_seven_
Date: 2022-11-12 21:15:24
LastEditTime: 2022-11-13 14:15:34
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\script\\xingz.py

'''


import requests as r
from lxml import etree
import time
from fake_useragent import UserAgent

headres = {
    "User-Agent":
    UserAgent().random
}
url = "https://xingzhengquhua.bmcx.com/"

def get_span(base_url = "https://xingzhengquhua.bmcx.com"):
    respone = r.get(url=base_url, headers=headres).text
    
    tree = etree.HTML(respone)
    
    tr_list = tree.xpath("//*[@id='main_content']/table/tr/td/table/tr")
    name_l = []
    res = []
    for i in range(len(tr_list)):
        name = tr_list[i].xpath("td[1]/a")
        a = tr_list[i].xpath("td[2]/a")
        
        if len(a)>0:
            if "*" in a[0].text:
                break
            res.append(a[0].text)
        if len(name)>0:
            name_l.append(name[0].text)
    return res,name_l


if __name__ == "__main__":
    start = time.time()
    first,_ = get_span()
    print(first)
    print("一级索引完成")
    second_list = []
    for idx,i in enumerate(first):
        next_url = url + i + "__xingzhengquhua/"
        we,_ = get_span(next_url)
        second_list.extend(we)
        print(f"二级索引part  {i}:   succeed!!,    count:{idx}")
        time.sleep(1)

    print(second_list)
    print("二级索引完成")
    third_list = []
    for idx,i in enumerate(second_list):
        next_url = url + i + "__xingzhengquhua/"
        next,_ = get_span(next_url)
        third_list.extend(next)
        print(f"三级索引part  {i}:   succeed!!,    count:{idx}")
        time.sleep(1)
    print(third_list)
    print("三级索引完成")
    fouth_list = []
    
    for idx,i in enumerate(third_list):
        next_url = url + i + "__xingzhengquhua/"
        next,name_list = get_span(next_url)
        fouth_list.extend(next)
        
        print(f"四级索引part  {i}:   succeed!!,    count:{idx}")
        time.sleep(1)
    print(fouth_list)
    
    fifth_list = []
    fifth_list_name = []
    for idx,i in enumerate(fouth_list):
        next_url = url + i + "__xingzhengquhua/"
        next,name_list = get_span(next_url)
        fifth_list.extend(next)
        fifth_list_name.extend(name_list)
        print(f"五级索引part  {i}:   succeed!!,    count:{idx}")
        time.sleep(1)
    print(fifth_list)
    end = time.time()
    print(f"共计耗时{end-start}s")


# /html/body/div[3]/div[2]/div[1]/div[2]/table/tbody/tr/td/table/tbody/tr[4]/td[2]/a
# //*[@id="main_content"]/table/tbody/tr/td/table/tbody/tr[4]/td[2]/a
# //*[@id="main_content"]/table/tbody/tr/td/table/tbody/tr[3]/td[2]/a

# #main_content > table > tbody > tr > td > table > tbody > tr:nth-child(3) > td:nth-child(2) > a