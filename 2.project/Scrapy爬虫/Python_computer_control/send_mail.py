#!/usr/bin/env python
# coding=utf-8

import smtplib
from email.mime.text import MIMEText


def get_userinfo():
    with open("userinfo.json", "r") as fin:
        import json
        return json.loads(fin.read())

# 发送html格式文件
def get_msg():
    with open("test.html", "r") as fin:
        return fin.read()

userinfo = get_userinfo()
mail = smtplib.SMTP("smtp.163.com")
mail.login(userinfo["username"], userinfo["password"])

msg = get_msg()
content = MIMEText(msg, _subtype = "html")
content["subject"] = "test title"
content["from"] = userinfo["username"]
content["to"] = userinfo["username"]


mail.sendmail(userinfo["username"], userinfo["username"], content.as_string())

mail.close()
