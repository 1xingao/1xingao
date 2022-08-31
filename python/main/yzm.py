import http.client
import json
import urllib
# 使用互亿无线
host = "106.ihuyi.com"
sms_send_uri = "/webservice/sms.php?method=Submit"

# 查看用户名 登录用户中心->验证码通知短信>产品总览->API接口信息->APIID
account = "C65130268"
# 查看密码 登录用户中心->验证码通知短信>产品总览->API接口信息->APIKEY
password = "9952367c2b8ac1a2b2ab2eda025c080d"


def send_sms(text, mobile):
    text = f"您的验证码是：{text}。请不要把验证码泄露给其他人。"
    params = urllib.parse.urlencode(
        {'account': account, 'password': password, 'content': text, 'mobile': mobile, 'format': 'json'})
    headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}
    conn = http.client.HTTPConnection(host, port=80, timeout=30)
    conn.request("POST", sms_send_uri, params, headers)
    response = conn.getresponse()
    response_str = response.read()
    conn.close()
    return response_str


if __name__ == '__main__':
    mobile = "19804863977"
    text = '356791'

    print(json.loads(send_sms(text, mobile).decode('utf-8')))
