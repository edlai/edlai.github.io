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