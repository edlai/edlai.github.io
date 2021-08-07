# [Image Processing](../../)

## Grayscale

An implementation of digital image processing to convert RGB image or colormap to grayscale (rgb2gray).

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
  import numpy as np
  import cv2
  
  # Load an color image in grayscale
  img = cv2.imread('../../lena.png', cv2.IMREAD_GRAYSCALE)
  
  cv2.imwrite('lena_grayscale.png',img)
  ```

## Running

  | Original            | Grayscale                |
  |---------------------|--------------------------|
  |![r](../../lena.png) | ![r](lena_grayscale.png) |


- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page (e.q. Pressing `F5`) if you cannot see the result.

## Advanced

There are some packages which support Image Processing for Python also. User can test on it also.
- scipy
- Pygame
- Numpy
- Pillow

## Reference

- [Image Manipulation in Python](https://www.codementor.io/isaib.cicourel/image-manipulation-in-python-du1089j1u)

