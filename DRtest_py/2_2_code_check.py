import time

print("===密码安全检查器===")

code = input("请输入密码：")
print("检查中...")
time.sleep(0.5)

print("检查结果：")
count = 0
print("长度检查：", end = "")
if len(code) > 8:
    print("通过")
    count += 1
else:
    print("不通过")

print("数字检查：", end = "")
if any(c.isdigit() for c in code):
    print("通过")
    count += 1
else:
    print("不通过")

print("字母检查：", end = "")
if any(c.isalpha() for c in code):
    print("通过")
    count += 1
else:
    print("不通过")

time.sleep(0.5)
if count == 3:
    print("强密码")
elif count == 2:
    print("中等密码")
elif count == 1:
    print("弱密码")
else:
    print("很不安全的密码")


