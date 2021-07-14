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

<?php
if(isset($_POST['Submit']))
{

  $im = imagecreatetruecolor(240, 320);

  $gray    = imagecolorallocate($im, 0xC0, 0xC0, 0xC0);
  $yellow  = imagecolorallocate($im, 0xFF, 0xFF, 0x00);
  $cyan    = imagecolorallocate($im, 0x00, 0xFF, 0XFF);
  $green   = imagecolorallocate($im, 0x00, 0xFF, 0x00);
  $magenta = imagecolorallocate($im, 0xFF, 0x00, 0xFF);
  $red     = imagecolorallocate($im, 0xFF, 0x00, 0x00);
  $blue    = imagecolorallocate($im, 0x00, 0x00, 0xFF);
  $black   = imagecolorallocate($im, 0x00, 0x00, 0x00);
  
  $i = 0;
  $step = 30;
  
  foreach ($_POST['bar'] as &$bar) 
  {

    $start = $step * $i;
    $end = $step * ($i+1);
    print "$start, $end, <br>";
    $i++;
    
    echo "your input:", $bar, "  ";
    
    switch ($bar):
    case "gray":
        echo "gray <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $gray);
        break;
    case "yellow":
        echo "yellow <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $yellow);
        break;
    case "cyan":
        echo "cyan <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $cyan);
        break;
    case "green":
        echo "green <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $green);
        break;
    case "magenta":
        echo "magenta <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $magenta);
        break;
    case "red":
        echo "red  <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $red);
        break;
    case "blue":
        echo "blue  <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $blue);
        break;
    case "black":
        echo "black  <br>";
        imagefilledrectangle($im, $start, 0,  $end, 320, $black);
        break;
    default:
        echo "default  <br>";
    endswitch;
  }

  imagepng($im,'img/colorbar.png');

  ob_start();
  imagepng($im);
  $buffer = ob_get_clean();
  ob_end_clean();

  $imageData = base64_encode($buffer);
  imagedestroy($im);
  
  // Format the image SRC:  data:{mime};base64,{data};
  $src = 'data: '.mime_content_type($buffer).';base64,'.$imageData;
  
  // Echo out a sample image
  
  echo "<fieldset>";
  echo "<legend>Result</legend>";
  //echo '<img src="' . $src . '"> <br>';
  echo '<a href="img/colorbar.png" download>';
  echo '<img border="0" src="img/colorbar.png" alt="colorbar" width="240" height="320">';
  echo '</a>';
  echo '<br>';
  echo 'Click Image to Download';
  
  echo "</fieldset>";

  echo "<fieldset>";
  echo "<legend>Pixel</legend>";

/*  
  $image = imagecreatefrompng('img/colorbar.png');
  
  $width = imagesx($image);
  $height = imagesy($image);
  $colors = array();

  for ($y = 0; $y < $height; $y++) {
  $y_array = array() ;

  for ($x = 0; $x < $width; $x++) {
    $rgb = imagecolorat($image, $x, $y);
    $r = ($rgb >> 16) & 0xFF;
    $g = ($rgb >> 8) & 0xFF;
    $b = $rgb & 0xFF;

    $x_array = array($r, $g, $b) ;
    $y_array[] = $x_array ; 
  } 
  $colors[] = $y_array ;
  }

  print_r($colors);

  echo "</fieldset>";
*/
}
?>

<fieldset>
  <legend>Colorbar Generation for Adafruit 2.4" TFT LCD (240 x 320, 65k)</legend>

<details>colorbar generation</details>

<form method="POST" action="<?=$_SERVER['PHP_SELF'];?>">
<table>
<!--
FIXME: datalist is not working
<tr>
  <td>Bar:</td>
	<td>
	  <input list="bar[]">
    <datalist id="bar[]">
      <option value="Gray">
      <option value="Yellow">
      <option value="Cyan">
      <option value="Green">
      <option value="Magenta">
      <option value="Red">
      <option value="Blue">
      <option value="Black">
    </datalist>
	</td>
</tr>
-->
<?php

for ($i=0; $i<8; $i++)
{
  echo <<<HTML

<tr>
		<td>
	    <select name="bar[]">
	      <option value="gray" selected> Gray </option>
	      <option value="yellow"> Yellow </option>
    	  <option value="cyan"> Cyan </option>
	      <option value="green"> Green </option>
	      <option value="magenta"> Magenta </option>
    	  <option value="red"> Red </option>
    	  <option value="blue"> Blue </option>
    	  <option value="black"> Black </option>
        </select> 
	</td>
</tr>

HTML;
}

?>

<tr>
	<td colspan="2">
	    <input type="reset" value="reset"> 
	    <input type="submit" name="Submit">
	</td>
</tr>

</table>
</form>	
</fieldset>

 </body>
</html>

<!--
https://vmaker.tw/archives/10466
-->
