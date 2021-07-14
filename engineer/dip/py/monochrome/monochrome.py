# pip install pillow
from PIL import Image, ImageFilter

with Image.open('../../lena.png') as image:
    width, height = image.size
    monochrome = Image.new("RGB", (width, height), "white")
    pixels = monochrome.load()
    for i in range(width):
        for j in range(height):
            pixel = image.getpixel((i, j))
            red =   pixel[0]
            green = pixel[1]
            blue =  pixel[2]
            pixel_monochrome = (red * 0.299) + (green * 0.587) + (blue * 0.114)
            if (pixel_monochrome > 127):
                pixel_monochrome = 255
            else:
                pixel_monochrome = 0; 
            pixels[i, j] = (int(pixel_monochrome), int(pixel_monochrome), int(pixel_monochrome)) 
    monochrome.save('lena_monochrome.png', 'png')
