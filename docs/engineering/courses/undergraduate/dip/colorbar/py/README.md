# [Image Processing](../../)

## Colorbar

An implementation of digital image processing to generate Colorbar (Colormap) for screen test.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- Python
- OpenCV `apt install python-opencv`

## Programming

- create file `colorbar.py`    

  ``` python
  import numpy as np
  import cv2 

  # Create a black image
  img = np.zeros((80,560,3), np.uint8)

  cv2.rectangle(img,   (0,0),  (80,80), (0xC0, 0xC0, 0xC0), -1)  # gray (BGR)
  cv2.rectangle(img,  (80,0), (160,80), (0x00, 0xFF, 0xFF), -1)  # yellow
  cv2.rectangle(img, (160,0), (240,80), (0xFF, 0xFF, 0x00), -1)  # cyan
  cv2.rectangle(img, (240,0), (320,80), (0x00, 0xFF, 0x00), -1)  # green
  cv2.rectangle(img, (320,0), (400,80), (0xFF, 0x00, 0xFF), -1)  # magenta
  cv2.rectangle(img, (400,0), (480,80), (0x00, 0x00, 0xFF), -1)  # red
  cv2.rectangle(img, (480,0), (560,80), (0xFF, 0x00, 0x00), -1)  # blue
  cv2.imwrite('colorbar.png',img)
  ```

## Running

- Running `colorbar.py`      
  ```
  # python ./colorbar.py
  ```
- Result    
  ![r](colorbar.png)

## Advanced

- n/a

## Reference

- [Python 與 OpenCV 加入線條圖案與文字教學](https://blog.gtwang.org/programming/opencv-drawing-functions-tutorial/)

