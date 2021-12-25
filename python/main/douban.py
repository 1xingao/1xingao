import urllib.request
import bs4
import re
import xlwt

base_url = "https://movie.douban.com/top250?start="
headers = {
    "user-agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36 Edg/87.0.664.66"
}
rule_find_link = re.compile(r'<a class="" href="(.*?)">')

rule_find_title = re.compile(r'<span class="title">(.*)</span>')

rule_find_data = re.compile(r'<span class="inq">(.*?)</span>')

rule_find_score = re.compile(
    r'<span class="rating_num" property="v:average">(.*?)</span>')

rule_find_people = re.compile(r'<span>(.*?)人评价</span>')


#获取所有的url并执行dillurl
def main():
    data_list = dill_url(base_url)
    #sav_data(data_list)
    print(data_list)
    #break


#对列表里的所有url里面的内容进行获取
def dill_url(nexturl):
    datalist = []
    for i in range(0, 10):
        next_url = nexturl + str(i * 25)
        #print(next_url)
        request = urllib.request.Request(next_url, headers=headers)
        respond = urllib.request.urlopen(request)
        html = respond.read().decode("utf-8")
        soup = bs4.BeautifulSoup(html, "html.parser")
        for item in soup.find_all('div', class_="item"):
            data = []
            item = str(item)

            link = re.findall(rule_find_link, item)[0]  #链接提取
            data.append(link)

            title = re.findall(rule_find_title, item)[0]  #标题提取
            data.append(title)

            dector = re.findall(rule_find_data, item)  #人数提取
            data.append(dector)

            score = re.findall(rule_find_score, item)[0]  #评分提取
            data.append(score)
            people = re.findall(rule_find_people, item)
            data.append(people)

            datalist.append(data)  #将每个的列表放入总列表

            #break
    return datalist


def save_data(data_list):
    print("saving....")
    #print(len(data_list))
    book = xlwt.Workbook(encoding="utf-8")
    sheet = book.add_sheet('dou', cell_overwrite_ok=True)
    col = ("电影链接", "电影名", "电影简介", "电影评分", "评分人数")
    for i in range(len(col)):
        sheet.write(0, i, col[i])

    #print(len(data_list))

    for i in range(0, 250):
        data = data_list[i]

        for j in range(0, 5):
            sheet.write(i + 1, j, data[j])
    book.save("豆瓣top250.xls")


if __name__ == "__main__":

    main()
