from psd_tools import PSDImage
import os
import traceback

def modify_psd_template(title, author, playing):
    try:
        # 加载PSD文件
        input_path = r'D:\PhotoShop\Image\body.psd'

        if not os.path.exists(input_path):
            print(f"错误: 文件不存在 - {input_path}")
            return

        # 给出文件打开反馈
        print(f"正在打开文件: {input_path}")
        psd = PSDImage.open(input_path)
        print("文件打开成功")
        
        # 查找并修改图层
        for layer in psd:
            if layer.name == "zhuanji mingzi.psb":
                layer.text = title
            elif layer.name == "yuedui mingzi.psb":
                layer.text = author
            elif layer.name == "yuequ mingzi.psb":
                layer.text = playing
        
        # 保存修改后的文件
        output_path = r"D:\PhotoShop\Image\ready.psd"
        psd.save(output_path)
        
        print(f"文件已保存到: {output_path}")
    
    except Exception as e:
        print(f"发生错误: {str(e)}")
        traceback.print_exc()
        return False

# 获取用户输入
title = input("请输入标题: ")
author = input("请输入作者: ")
playing = input("请输入正在播放的内容: ")

# 调用函数
modify_psd_template(title, author, playing)