# Image Processing

## Text Image

An implementation of digital image processing to create the text image .

## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- PHP

## Programming

``` php
<?php

$img_file = 'string.png';
$im = imagecreatetruecolor(400, 30);

// Create some colors
$white = imagecolorallocate($im, 255, 255, 255);
$grey = imagecolorallocate($im, 128, 128, 128);
$black = imagecolorallocate($im, 0, 0, 0);
imagefilledrectangle($im, 0, 0, 399, 29, $white);

$text = "1234567890";
$font = './arial.ttf';

imagettftext($im, 20, 0, 11, 21, $grey, $font, $text);
imagettftext($im, 20, 0, 10, 20, $black, $font, $text);
imagepng($im, $img_file);
imagedestroy($im);

?>

```

## Result

![r](string.png)

