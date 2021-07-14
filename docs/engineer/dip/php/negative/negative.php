<?php

$img = imagecreatefrompng("../../lena.png");
imageTrueColorToPalette($img,true,256);
$numColors = imageColorsTotal($img);
for ($x = 0; $x < $numColors; $x++)
{
  list($r,$g,$b) = array_values(imageColorsForIndex($img,$x));
  $r = 255 - $r;
  $g = 255 - $g;
  $b = 255 - $b;
  imageColorSet($img,$x,$r,$g,$b);
}

$img_negative= 'lena_negative.png';
imagepng($img, $img_negative);
imagedestroy($img);

?>
