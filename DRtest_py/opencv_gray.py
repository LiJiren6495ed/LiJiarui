import cv2

def display_image_vscode(img, filename="display_gray.jpg"):
    # 保存图片
    cv2.imwrite(filename, img)
    print(f"图片已保存为: {filename}")

 # 加载一张图片（请准备一张jpg或png图片放在代码同目录下）
img = cv2.imread('art.jpg')
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
if img is None:
    print("图片加载失败！")
else:
    display_image_vscode(gray_img)
    print("图片显示成功！")