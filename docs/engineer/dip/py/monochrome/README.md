# [Image Processing](../../)

## Monochrome (B&W; Black-and-White)

An implementation of digital image processing to change RGB image or colormap to monochrome (black-and-white) image.

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

- create file `monochrome.py`    

  ``` python
  import cv2
  
  thresh = 127
  img_gray = cv2.imread('../../lena.png', cv2.CV_LOAD_IMAGE_GRAYSCALE)
  (thresh, img_bw) = cv2.threshold(img_gray, 128, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
  img_monochrome = cv2.threshold(img_gray, thresh, 255, cv2.THRESH_BINARY)[1]
  cv2.imwrite('lena_monochrome.png', img_monochrome)
  ```

## Running

  | Original            | Monochrome                |
  |---------------------|---------------------------|
  |![r](../../lena.png) | ![r](lena_monochrome.png) |


- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page (e.q. Pressing `F5`) if you cannot see the result.

## Advanced

There are some packages which support Image Processing for Python also. User can test on it also.
- scipy
- Pygame
- Numpy
- OpenCV

## Reference

- [Image Manipulation in Python](https://www.codementor.io/isaib.cicourel/image-manipulation-in-python-du1089j1u)

