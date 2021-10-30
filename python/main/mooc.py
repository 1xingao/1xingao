import requests
import time
headres = {
     "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.54 Safari/537.36"
}
url_list = ["https://mooc1.chaoxing.com/mycourse/studentstudy?chapterId=468297489&courseId=219712649&clazzid=44380281&enc=9d922f678291b192bacfee33f3d85b22&mooc2=1&cpi=156057921&openc=134326c3d2437c50aa6dc9d05d8e2ec2",
"https://mooc1.chaoxing.com/mycourse/studentstudy?chapterId=468297488&courseId=219712649&clazzid=44380281&enc=9d922f678291b192bacfee33f3d85b22&mooc2=1&cpi=156057921&openc=134326c3d2437c50aa6dc9d05d8e2ec2"]

for _ in range(10):
    r = requests.get(url=url_list[0],headers=headres)
    time.sleep(1)
    print("once success!!")