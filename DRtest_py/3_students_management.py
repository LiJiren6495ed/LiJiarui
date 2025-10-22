import time

# 学生类，用于存储学生属性
class Student:
    def __init__(self, name, id, age, major, python_score, math_score, english_score):
        self.name = name
        self.id = id
        self.age = age
        self.major = major
        self.python_score = python_score
        self.math_score = math_score
        self.english_score = english_score

    def calculate_sum(self): # 计算总分
        return self.python_score + self.math_score + self.english_score
    
    def average_score(self): # 计算平均分
        return round(self.calculate_sum() / 3, 2)
    
    def print_info(self): # 打印学生信息
        print(f"姓名：{self.name}")
        print(f"学号：{self.id}")
        print(f"年龄：{self.age}")
        print(f"专业：{self.major}")
        print(f"Python成绩：{self.python_score}")
        print(f"数学成绩：{self.math_score}")
        print(f"英语成绩：{self.english_score}")
        print(f"总分：{self.calculate_sum()}")
        print(f"平均分：{self.average_score()}")

# 学生管理类，用于管理学生信息
class StudentManagement:
    def __init__(self):
        self.students = {}

    def add_student(self): # 添加学生信息
        name = input("请输入学生姓名：")
        id = input("请输入学生学号：")
        
        if id in self.students:
            print("[提示]学号已存在，请重新输入！")
            return
        age = int(input("请输入学生年龄："))
        major = input("请输入学生专业：")
        python_score = float(input("请输入学生Python成绩："))
        math_score = float(input("请输入学生数学成绩："))
        english_score = float(input("请输入学生英语成绩："))
        
        student = Student(name, id, age, major, python_score, math_score, english_score)
        self.students[id] = student
        print("[提示]学生信息添加成功！")

    def search_student(self): # 查询学生信息
        id = input("请输入学生学号：")
        if id in self.students:
            time.sleep(1)
            print("\n[提示]查询到学生信息如下：")
            self.students[id].print_info()
        else:
            time.sleep(1)
            print("\n[提示]未查询到该学生信息。")

    def run_system(self): # 运行系统
        while True:
            print("=" * 40)
            print(f'{"学生信息管理系统":^20}')
            print("=" * 40)

            print("\n")
            print("1. 新增学生信息")
            print("2. 查询学生信息")
            print("3. 退出系统")
            print("\n")

            choice = input("请输入你的选择（1-3）：")
            if choice == "1":
                self.add_student()
            elif choice == "2":
                self.search_student()
            elif choice == "3":
                print("欢迎下次使用！")
                break
            else:
                print("输入错误，请选择1-3中的数字！")

#  主函数
system = StudentManagement()
system.run_system()