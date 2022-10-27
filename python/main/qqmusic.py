'''
Author: xinao_seven_
Date: 2022-10-25 18:43:21
LastEditTime: 2022-10-26 22:39:58
LastEditors: xinao_seven_
Description: qq音乐评论爬虫
Encoding: utf8
FilePath: \\1xingao\\python\\main\\qqmusic.py

'''

import requests as r
import json
from fake_useragent import UserAgent
import xlwt

base_url = "https://y.qq.com/n/ryqq/profile/like/song?uin="

headers = {'user-agent': UserAgent().random}

# request_url = "https://u.y.qq.com/cgi-bin/musics.fcg?_=1666694196869&sign=zzbbce545d9zqqdrc2ii8dv06w5urismq01782005"
# res_url = "https://u.y.qq.com/cgi-bin/musics.fcg?"

resquest_url = "https://c.y.qq.com/base/fcgi-bin/fcg_global_comment_h5.fcg?g_tk_new_20200303=5381&g_tk=5381&loginUin=0&hostUin=0&format=json&inCharset=utf8&outCharset=GB2312&notice=0&platform=yqq.json&needNewCode=0&cid=205360772&reqtype=2&biztype=2&topid=12924001&cmd=8&needmusiccrit=0&pagenum="

data_list = []


def get_json(num: int) -> None:
    new_url = resquest_url + str(num) + "&pagesize=25"
    res = r.get(url=new_url, headers=headers)

    json_data = json.loads(res.text)
    json_list = json_data['comment']['commentlist']

    id = [i.get("encrypt_uin") for i in json_list]
    # for i in json_list:
    #     id.append(i.get("encrypt_uin"))
    for i in id:
        data_list.append(base_url + i)


def main():

    for i in range(1, 2):

        get_json(i)
    print("获取数据数：" + str(len(data_list)))
    data = set(data_list)
    print("去重后数据：" + str(len(data)))
    data = list(data)
    book = xlwt.Workbook(encoding="utf-8")
    sheet = book.add_sheet('resdata', cell_overwrite_ok=True)
    for i in range(len(data)):
        sheet.write(i+1,0,data[i])
    book.save("res_date.xls")
    with open("res_da.txt","w") as fp:
        for i,num in enumerate(data_list):
            num += ","
            if(i%5==0):
                num = num+"\n"
            
            fp.writelines(num)


if __name__ == "__main__":
    main()