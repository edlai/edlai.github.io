<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <meta name="Generator" content="">
  <meta name="Author" content="">
  <meta name="Keywords" content="">
  <meta name="Description" content="">
  
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>

  <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>

  <title>Document</title>
 </head>
 <body>
  
 Text to Image <br>
 <form method="POST" action="<?=$_SERVER['PHP_SELF'];?>">  
 <table>
<tr>
	<td>Input Text:</td>
	<td><input type="text" name="string"> (max: 10)</td>
	<td align="right"><input type="submit" value="Send File" name="submit" /></td>
</tr>
</table> 
</form>  


<?php
if(isset($_POST['submit']))
{
   
$uploaddir = 'img/';
$string = $_POST["string"];
$img_file = $uploaddir . 'string.png';

// Set the content-type
// header('Content-Type: image/png');

// Create the image
$im = imagecreatetruecolor(400, 30);

// Create some colors
$white = imagecolorallocate($im, 255, 255, 255);
$grey = imagecolorallocate($im, 128, 128, 128);
$black = imagecolorallocate($im, 0, 0, 0);
imagefilledrectangle($im, 0, 0, 399, 29, $white);

// The text to draw
$text = $string;  // 10 chars
// Replace path by your own font path
$font = './arial.ttf';

// Add some shadow to the text
imagettftext($im, 20, 0, 11, 21, $grey, $font, $text);

// Add the text
imagettftext($im, 20, 0, 10, 20, $black, $font, $text);

// Using imagepng() results in clearer text compared with imagejpeg()
imagepng($im, $img_file);

imagedestroy($im);

echo "<hr> Output PNG:";
print '<img src='. $img_file .' alt="string">';
}
?>

<hr>
 </body>
</html>
