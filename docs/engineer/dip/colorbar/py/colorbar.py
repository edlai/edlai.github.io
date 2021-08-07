import numpy as np
import cv2 

# Create a black image
img = np.zeros((80,560,3), np.uint8)
#img.fill(200)

# BGR (not RGB)

# gray
cv2.rectangle(img,   (0,0),  (80,80), (0xC0, 0xC0, 0xC0), -1)
# yellow
cv2.rectangle(img,  (80,0), (160,80), (0x00, 0xFF, 0xFF), -1)
# cyan
cv2.rectangle(img, (160,0), (240,80), (0xFF, 0xFF, 0x00), -1)
# green
cv2.rectangle(img, (240,0), (320,80), (0x00, 0xFF, 0x00), -1)
# magenta
cv2.rectangle(img, (320,0), (400,80), (0xFF, 0x00, 0xFF), -1)
# red
cv2.rectangle(img, (400,0), (480,80), (0x00, 0x00, 0xFF), -1)
# blue
cv2.rectangle(img, (480,0), (560,80), (0xFF, 0x00, 0x00), -1)

cv2.imwrite('colorbar.png',img)
