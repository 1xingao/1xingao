# -*- coding: utf-8 -*-
import requests
import xlwt


first_url = "http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsList"   #首页的Id链接
second_url = "http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsById"    #具体信息的链接

#first_url的请求数据\
data_1 = {
    "on": "true",
    "page": "1",
    "pageSize": "15",
    "productName": "",
    "conditionType": "1",
    "applyname": "",
    "applysn": ""
}

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36"
}


data_list=[]    #存储所有企业的ID
data_3=[]    #存储返回的具体数据


def get_url(url):
    resopne = requests.post(url=url,data=data_1,headers=headers)
    json_data = resopne.json()
    #print(json_data)

    for ads in json_data["list"]:
        data_list.append(ads["ID"])
    #print(data_list)

    return data_list

def get_ID(url):
    respone_1 = requests.post(url=url,data=data_2,headers=headers).json()
    #print(respone_1)
    return respone_1


def save_data():
    book = xlwt.Workbook(encoding="utf-8")

    sheet = book.add_sheet('dou', cell_overwrite_ok=True)
    pass

if __name__ == "__main__":
    data = get_url(first_url)
    for kb in data:
        data_2 = {
            "id": kb
        }
        res = get_ID(second_url)
        data_3.append(res)

    print(data_3)

