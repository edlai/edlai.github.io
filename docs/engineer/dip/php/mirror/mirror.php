<?php
$imgstream   =   file_get_contents('lena_std.png');   
$im   =   imagecreatefromstring($imgstream);      
$thumbw   =   imagesx($im);
$thumbh   =   imagesy($im);
if(function_exists("imagecreatetruecolor"))   
  $dim   =   imagecreatetruecolor($thumbw,   $thumbh);
else   
  $dim   =   imagecreate($thumbh,   $thumbw);
for($x=0;$x<$thumbw;$x++)
{
  for($y=0;$y<$thumbh;$y++)
    {
     //左右對調
      imagecopyresized($dim,$im,$thumbw-$x-1,$y,$x,$y,1,1,1,1);
     //上下翻轉
      //imagecopyresized($dim,$im,$x,$thumbh-$y-1,$x,$y,1,1,1,1);
    }
}   
imagepng($dim,'lena_mirror.png');
imagedestroy($dim);
?>

<?php 
$im   =   imagecreatefrompng('lena_std.png');      
$thumbw   =   imagesx($im);
$thumbh   =   imagesy($im);
    
if(function_exists("imagecreatetruecolor"))   
  $dim   =   imagecreatetruecolor($thumbw,   $thumbh);
else   
  $dim   =   imagecreate($thumbh,   $thumbw);

for($x=0;$x<$thumbw;$x++)
{
  for($y=0;$y<$thumbh;$y++)
    {
    $rgb = ImageColorAt ($im, $x, $y);
    ImageSetPixel ($dim, $thumbw-$x, $y, $rgb);
    }
}   
imagepng($dim,'lena_mirr.png');
imagedestroy($dim);
?>
