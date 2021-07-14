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

<fieldset>
  <legend>Request:</legend>
  <form enctype="multipart/form-data" action="<?=$_SERVER['PHP_SELF'];?>" method="POST">
    <input type="hidden" name="MAX_FILE_SIZE" value="300000" />
      Send File: <input name="userfile" type="file" />
    <input type="submit" value="Send File" name="submit" />
  </form>
</fieldset>

<hr>

<?php

$uploaddir = '../dummy/';

if(isset($_POST['submit']))
{

  echo "<fieldset>";
  echo "<legend>Response:</legend>";
  
  print_r($uploadfile = $uploaddir.basename($_FILES['userfile']['name']));

  echo '<pre>';
  if (move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) {
      echo "File is valid, and was successfully uploaded.\n";
  } else {
      echo "Possible file upload attack!\n";
  }
/*
  echo 'info:';
  print_r($_FILES);
  echo "<br />";
  echo "result: ";
  print_r($_FILES['userfile']['error']);
*/
  print "</pre>";

  $file = $uploaddir . $_FILES['userfile']['name']; 
  #print '<img src='. $file .' alt="original">';

  $img = imagecreatefrompng($file);
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
  
  $img_negative_1 = $uploaddir . 'lena_negative_1.png';
  imagepng($img, $img_negative_1);
  imagedestroy($img);
  #print '<img src='. $img_negative_1 .' alt="negative">';

  echo "<table board =1>";
  echo "<tr>";
	echo "<td> Original </td>";
	echo "<td> Negative (Formula: x = 255 - x) </td>";
  echo "</tr>";
  echo "<tr>";
	echo '<td>'. '<img src='. $file .' alt="original">'. '</td>';
	echo '<td>' . '<img src='. $img_negative_1 .' alt="negative">'. '</td>';
  echo "</tr>";
  echo "</table>";

  echo "</fieldset>";
}
?>

</body>
</html>
