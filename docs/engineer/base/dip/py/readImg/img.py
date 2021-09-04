# pip install pillow

from PIL import Image, ImageFilter

im = Image.open('../../lena.png')
im2 = im.filter(ImageFilter.BLUR)
im2.save('lena_test.png', 'png')
