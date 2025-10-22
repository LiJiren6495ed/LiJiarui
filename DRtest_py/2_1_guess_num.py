import random

num = random.randint(1, 10)
count = 0
print("===猜！数！游！戏！===")
while True:
    guess = int(input("猜一个一到十以内的数字："))
    count += 1
    if guess == num:
        print("你猜对了！")
        print("你总共猜了", count, "次")
        break
    elif guess < num:
        print("猜小了！")
    else:
        print("猜大了！")