import numpy as np
import cv2
from PIL import ImageFont, ImageDraw, Image

img = np.zeros((20, 200, 3), np.uint8)

img[:] = (0, 0, 255)

text = '1234567890'

fontPath = "./arial.ttf"

font = ImageFont.truetype(fontPath, 20)

imgPil = Image.fromarray(img)

draw = ImageDraw.Draw(imgPil)
draw.text((0, 0),  text, font = font, fill = (0, 0, 0))

img = np.array(imgPil)

cv2.imwrite('text.png',img)