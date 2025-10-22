import cv2

def display_image_vscode(img, filename="display_blur.jpg"):
    # 保存图片
    cv2.imwrite(filename, img)
    print(f"图片已保存为: {filename}")
 # 加载图片
img = cv2.imread('art.jpg')
 # 应用模糊效果
blurred = cv2.GaussianBlur(img, (15, 15), 0)
if img is None:
    print("图片加载失败！")
else:
    display_image_vscode(blurred)
    print("图片显示成功！")