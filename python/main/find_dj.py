
import requests as r
import time
from lxml import etree
import os
headres = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"
}

base_url = "https://www.9ku.com/dj/"

pin_url = "https://www.9ku.com/down/"
mic_url = "https://mp3.haoge500.com/hot/2009/12-23/"

mic_dir='D:\mic\\'
if not os.path.exists(mic_dir):
     os.mkdir(mic_dir)
# with open("123.mp3","wb") as f:
#     f.write(res)
def get_id(url):
    respone = r.get(url = url,headers=headres).text
    tree = etree.HTML(respone)
    li_list = tree.xpath("//*[@id='hot_tuijian']/li")
    link_list = []
    for i in range(len(li_list)):
        a_list = li_list[i].xpath("input")
        link = a_list[0].get("value")
        link_list.append(link)
    return link_list
id_list = get_id(base_url)
# print(id_list)

def get_url_list(id_list):
    new_url_list = []
    for i in id_list:
        new_url = mic_url + i +".mp3"
        new_url_list.append(new_url)
    return new_url_list


def get_mic(url_list,id_list):
    for i,j in zip(url_list,id_list):
        res = r.get(url = i,headers=headres).content
        with open(j+".mp3","wb") as f:
            f.write(res)
        time.sleep(1)
        print(j,"保存完毕")


if __name__ == "__main__":
    id_list = get_id(base_url)
    new_url = get_url_list(id_list)
    get_mic(new_url,id_list)
