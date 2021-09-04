# Image Processing

## Colorbar

An implementation of digital image processing to generate colorbar for screen test.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- PHP

## Programming

- create file `colorbar.php`

``` php
<?php

$im = imagecreatetruecolor(560, 80);

$gray    = imagecolorallocate($im, 0xC0, 0xC0, 0xC0);
$yellow  = imagecolorallocate($im, 0xFF, 0xFF, 0x00);
$cyan    = imagecolorallocate($im, 0x00, 0xFF, 0XFF);
$green   = imagecolorallocate($im, 0x00, 0xFF, 0x00);
$magenta = imagecolorallocate($im, 0xFF, 0x00, 0xFF);
$red     = imagecolorallocate($im, 0xFF, 0x00, 0x00);
$blue    = imagecolorallocate($im, 0x00, 0x00, 0xFF);

imagefilledrectangle($im,   0, 0,  80, 80, $gray);
imagefilledrectangle($im,  80, 0, 160, 80, $yellow);
imagefilledrectangle($im, 160, 0, 240, 80, $cyan);
imagefilledrectangle($im, 240, 0, 320, 80, $green);
imagefilledrectangle($im, 320, 0, 400, 80, $magenta);
imagefilledrectangle($im, 400, 0, 480, 80, $red);
imagefilledrectangle($im, 480, 0, 560, 80, $blue);

imagepng($im,'colorbar.png');
imagedestroy($im);

?>
```

## Running

- Issue below command    
  ```
  # php ./colorbar.php
  ```

### Result    

  ![colorbar.png](colorbar.png)

## Demo

- [Demo Site](http://45.77.13.97/cgi-bin/dip/colorbar.php)

#### Reference

- [Color Bars and How To Use ‘em](http://www.videouniversity.com/articles/color-bars-and-how-to-use-em)
- [HTML color codes and names](http://www.computerhope.com/htmcolor.htm)
- [imagegd](http://tw2.php.net/manual/en/function.imagegd.php)
- [色碼表 RGB值越大 顏色越亮](http://rhinejo.myweb.hinet.net/home/color/color-cord.html)
- C語言數位影像處理 p.115(978-957-21-5247-8)
- [libpng](http://www.libpng.org/pub/png/libpng.html)
