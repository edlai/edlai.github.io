# [Image Processing](../../)

## Text Image

```
$author:   Ching-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, text
```

An implementation of digital image processing to create the text image .

## Content

* [Requirements](#requirements)
* [Programming](#programming)
  * [HTML5](#html5)
  * [Javascript](#javascript)
* [Running](#running)
  * [Request](#request)
  * [Response](#response)

## Requirements

- Web Browsers

## Programming

### HTML5

```html
<h3>Request:</h3>

<form>
  <div>
    Input Text you want to show: (Could be in Chinese) <br> <input type="text"> <br>
    <input type="submit">
  </div>
</form>

<h3>Response:</h3>

<canvas id="myCanvas" width="200" height="100" style="border:1px solid #d3d3d3;">
</canvas>
```

### Javascript

```javascript
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script> 

<script>
$(document).ready(function(){
  $("form").submit(function(event) {
    var canvas = document.getElementById("myCanvas");
    var ctx = canvas.getContext("2d");
    ctx.font = "20px Arial";
    ctx.fillText($( "input:first" ).val() ,10, 50);
    event.preventDefault();
  });
});
</script> 
```

## Running

<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>

<script>
$(document).ready(function(){
  $("form").submit(function(event) {
    var canvas = document.getElementById("myCanvas");
    var ctx = canvas.getContext("2d");
    //ctx.clear();
    ctx.font = "20px Arial";
    ctx.fillText($( "input:first" ).val() ,10, 50);
    event.preventDefault();
  });
});
</script>

<h3>Request:</h3>

<form>
  <div>
    Input Text you want to show: (Could be in Chinese) <br> 
    <input type="text"> 
    <input type="submit">
  </div>
</form>

<h3>Response:</h3>

<canvas id="myCanvas" width="200" height="100" style="border:1px solid #d3d3d3;">
Your browser does not support the canvas element.
</canvas>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page ( Press <kbd>F5</kbd> ) if you cannot see the result.
