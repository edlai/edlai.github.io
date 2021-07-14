import numpy as np
import cv2

# Load an color image in grayscale
img = cv2.imread('../../lena.png', cv2.IMREAD_GRAYSCALE)

cv2.imwrite('lena_grayscale.png',img)