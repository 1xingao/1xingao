# -*- coding: utf-8 -*-
import requests as r
from bs4 import BeautifulSoup
import os
#url和ua
id_url = "https://pvp.qq.com/web201605/js/herolist.json"
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36"
}
base_url = "https://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/"
#os构建新的文件夹
hero_dir='D:\PycharmProjects\pic\\'
if not os.path.exists(hero_dir):
     os.mkdir(hero_dir)
#获取所有的英雄代号
def get_id(url):
    respone = r.get(url=url,headers=headers).json()
    #print(respone)
    id_data_list = []
    for data in respone:
        id_data_list.append(data['ename'])
    return id_data_list     #返回英雄的id列表
#获取图片的主函数
def get_pic(url_list,name_list):
    for url,list_1 in zip(url_list,name_list):
        #zip函数同时迭代两个参数
        res = r.get(url=url, headers=headers).content       #以二进制写入图片
        with open(hero_dir+list_1,"wb") as fp:
            fp.write(res)
        print(list_1,"存储完毕")
#获取图片连接的函数
def init_url(data_list):
    url_list = []       #用以存储所有拼接好的英雄链接
    for data in data_list:
        url = base_url + str(data) + "/"  + str(data) + "-bigskin-1.jpg"        #bigskin后面跟的参数为皮肤（未写）
        url_list.append(url)
    return url_list
#拼接文件名的函数
def init_file_name(data_list):
    name_list = []      #所有英雄的文件名
    for data in data_list:
        name = str(data) + ".jpg"
        name_list.append(name)
    return name_list
if __name__ == "__main__":
    data_list = get_id(id_url)
    #print(data_list)
    name_list = init_file_name(data_list)
    url_list = init_url(data_list)
    get_pic(url_list,name_list)
#一堆没用的网页select
#body > div.wrapper > div.zk-con1.zk-con > div > div > div.pic-pf > ul > li:nth-child(1)
#body > div.wrapper > div.zk-con1.zk-con > div > div > div.pic-pf > ul > li:nth-child(2) > i
#https://game.gtimg.cn/images/yxzj/img201606/skin/hero-info/105/105-bigskin-1.jpg