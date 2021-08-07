# [Image Processing](../../)

## Shrink (resizeing)

An implementation to resize RGB image.

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

- create file `resize.py`

  ``` python
  import cv2
 
  # load the image with imread()
  imageSource = '../../lena.png'
  src = cv2.imread(imageSource)
 
  height, width = src.shape[:2]
  dest = cv2.resize(src,(width/2, height/2), interpolation = cv2.INTER_CUBIC)
 
  cv2.imwrite('lena_resize.png',dest)
  ```

## Running

  | Original            | Resized               | 
  |---------------------|-----------------------|
  |![r](../../lena.png) | ![r](lena_resize.png) |


## Observation

- n/a

## Advanced

- n/a

## Reference

- [Geometric Transformations of Images](https://docs.opencv.org/3.4.0/da/d6e/tutorial_py_geometric_transformations.html)

