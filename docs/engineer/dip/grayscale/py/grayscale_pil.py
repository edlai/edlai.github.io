# pip install pillow
from PIL import Image, ImageFilter

with Image.open('../../lena.png') as image:
    width, height = image.size
    grayscale = Image.new("RGB", (width, height), "white")
    pixels = grayscale.load()
    for i in range(width):
        for j in range(height):
            pixel = image.getpixel((i, j))
            red = pixel[0]
            green = pixel[1]
            blue = pixel[2]
            gray = (red * 0.299) + (green * 0.587) + (blue * 0.114)
            pixels[i, j] = (int(gray), int(gray), int(gray))
    grayscale.save('lena_grayscale.png', 'png')
