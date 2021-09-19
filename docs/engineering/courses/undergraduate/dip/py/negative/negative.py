import cv2

img=cv2.imread("../../lena.png")
height, width, channels = img.shape

print(height,width,channels)

for x in range(0,width):
    for y in range(0,height):      
        img[x,y,0] = 255 - img[x,y,0]
        img[x,y,1] = 255 - img[x,y,1]
        img[x,y,2] = 255 - img[x,y,2]

cv2.imwrite('lena_negative.png',img)