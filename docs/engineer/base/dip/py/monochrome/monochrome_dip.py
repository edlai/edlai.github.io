import cv2

thresh = 127
img_gray = cv2.imread('../../lena.png', cv2.CV_LOAD_IMAGE_GRAYSCALE)
(thresh, img_bw) = cv2.threshold(img_gray, 128, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
img_monochrome = cv2.threshold(img_gray, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imwrite('lena_monochrome.png', img_monochrome)
