# Image Processing

## Monochrome (B&W; Black-and-White)

An implementation of digital image processing to change RGB image or colormap to monochrome (black-and-white) image.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- PHP

## Programming

``` php
<?php

$img = imagecreatefrompng("../../lena.png");
imageTrueColorToPalette($img,true,256);
$numColors = imageColorsTotal($img);
for ($x = 0; $x < $numColors; $x++)
{
  list($r,$g,$b) = array_values(imageColorsForIndex($img,$x));
  $avg = intval($r * 0.299 + $g * 0.587 + $b * 0.114);
  if($avg >= 127) { 
    $avg = 255; 
  } else {
    $avg = 0;
  }
  imageColorSet($img,$x,$avg,$avg,$avg);
 }
 
 $img_monochrome = 'lena_monochrome.png';
 imagepng($img, $img_monochrome);
 imagedestroy($img);

?>
```

## Running

- Issue below command    
  ```
  # php ./monochrome.php
  ```

### Result

  | Original            | Monochrome                |
  |---------------------|---------------------------|
  |![r](../../lena.png) | ![r](lena_monochrome.png) |


