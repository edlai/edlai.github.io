# [Image Processing](../../)

## Mirror (Flipping)

An implementation of digital image processing to change RGB image to the flipping images.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- Python
- OpenCV `apt-get install python-opencv`

## Programming

- create file `mirror.py`

  ``` python
  import cv2
 
  # load the image with imread()
  imageSource = '../../lena.png'
  img = cv2.imread(imageSource)
   
  # copy image to display all 4 variations
  horizontal_img = img.copy()
  vertical_img = img.copy()
  both_img = img.copy()
   
  # flip img horizontally, vertically,
  # and both axes with flip()
  horizontal_img = cv2.flip( img, 0 )
  vertical_img = cv2.flip( img, 1 )
  both_img = cv2.flip( img, -1 )
   
  cv2.imwrite('lena_horizontal.png',horizontal_img)
  cv2.imwrite('lena_vertical.png',vertical_img)
  cv2.imwrite('lena_both.png',both_img)
  ```

## Running

  | Original            | Horizontal                | Vertical                | Both               |
  |---------------------|---------------------------|-------------------------|--------------------|
  |![r](../../lena.png) | ![r](lena_horizontal.png) | ![r](lena_vertical.png) |![r](lena_both.png) |


## Observation

- n/a

## Advanced

- n/a

## Reference

- [FLIP IMAGE OPENCV PYTHON](https://scottontechnology.com/flip-image-opencv-python/)

