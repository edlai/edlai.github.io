# [Image Processing](../../)

## Negative Film

An implementation of digital image processing to change RGB image or colormap to negative-film image.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- Python
- OpenCV
  ```
  # apt-get install python-opencv
  ```

## Programming

- create file `grayscale.py`

  ``` python
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
  ```

## Running

  | Original            | Negative Film            |
  |---------------------|--------------------------|
  |![r](../../lena.png) | ![r](lena_negative.png)  |


## Observation

- Observation by `file` command of Linux Shell

  ```
  # file ../../lena.png
  ../../lena.png: PNG image data, 300 x 300, 8-bit/color RGB, non-interlaced

  # file lena_negative.png
  lena_negative.png: PNG image data, 300 x 300, 8-bit/color RGB, non-interlaced
  ```

## Advanced

There are some packages which support Image Processing for Python also. User can test on it also.
- scipy
- Pygame
- Numpy
- pillow

## Reference

- [Image Manipulation in Python](https://www.codementor.io/isaib.cicourel/image-manipulation-in-python-du1089j1u)

