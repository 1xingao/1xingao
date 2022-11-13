'''
Author: xinao_seven_
Date: 2022-11-01 15:53:27
LastEditTime: 2022-11-12 22:22:19
LastEditors: xinao_seven_
Description: 
Encoding: utf8
FilePath: \\1xingao\\python\\main\\res.py

'''

import requests as r

from lxml import etree

base_url = "https://music.migu.cn/v3/music/song/60054701958"

song_url = "https://music.migu.cn/v3/music/top/jianjiao_newsong"

headres = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"
}

def get_span():
    respone = r.get(url=base_url, headers=headres).text
    tree = etree.HTML(respone)
    li_list = tree.xpath("/html/body/div[2]/div[2]/div[2]/div[2]/p[4]/span/span")
    res = []
    for i in li_list:
        res.append(i.text)
    return res

# //*[@id="js_songlist"]/div[1]/div[3]/span[1]/a
# //*[@id="js_songlist"]/div[1]
def get_id():
    respone = r.get(url = song_url,headers= headres).text
    print(respone)
    tree = etree.HTML(respone)
    res = tree.xpath("/html/body/div[2]/div[2]/div[4]/div[2]/div[1]/div[3]/span[1]/a")
    print(res[0].get("href"))
    # div_list = tree.xpath("/html/body/div[2]/div[2]/div[4]/div[2]/div")
    # ans  = []
    # for div in div_list:
    #     res = tree.xpath("div[3]/a")
    #     ans.append(res[0].get("href"))
    # print(ans)
get_id()

# /html/body/div[2]/div[2]/div[4]/div[2]/div[1]/div[3]/a
# /html/body/div[2]/div[2]/div[4]/div[2]/div[2]
# /html/body/div[2]/div[2]/div[4]/div[2]/div[1]/div[3]/a