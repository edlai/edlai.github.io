<?php

$img = imagecreatefrompng("../../lena.png");
imageTrueColorToPalette($img,true,256);
$numColors = imageColorsTotal($img);

for ($x = 0; $x < $numColors; $x++)
{
  list($r,$g,$b) = array_values(imageColorsForIndex($img,$x));
  $avg = intval(($r + $g + $b) / 3);
  imageColorSet($img,$x,$avg,$avg,$avg);
}
  
$img_grayscale = 'lena_grayscale.png';
imagepng($img, $img_grayscale);
imagedestroy($img);

?>


