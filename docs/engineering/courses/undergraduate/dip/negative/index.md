# [Image Processing](../../)

## Negative Film

```
$author:   Ching-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, colormap, b&w, negative, film
```

An implementation of digital image processing to change RGB image or colormap to negative-film image.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
  * [HTML5](#html5)
  * [Javascript](#javascript)
* [Running](#running)

## Requirements

- Web Browsers

## Programming

### HTML5

```html
Before: <img id="lena" src="../../lena.png" alt="The Lena" width="300" height="300">
After:  <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> </canvas>
```

### Javascript

```javascript
<script>
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var img = document.getElementById("lena");
ctx.drawImage(img, 0, 0);
var imgData = ctx.getImageData(0, 0, c.width, c.height);

var i;
for (i = 0; i < imgData.data.length; i += 4) {
  imgData.data[i]   = 255 - imgData.data[i];
  imgData.data[i+1] = 255 - imgData.data[i+1];
  imgData.data[i+2] = 255 - imgData.data[i+2];
  imgData.data[i+3] = 255;
}
ctx.putImageData(imgData, 0, 0);
</script> 
```

## Running

| Original | Negative Film, x = (255 -x ), x = {r,g,b} |
|----------|-------------------------------------------|
| <img id="lena" src="../../lena.png" alt="The Lena" width="300" height="300"> | <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas> |

<script type="text/JavaScript">
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var img = document.getElementById("lena");
ctx.drawImage(img, 0, 0);
var imgData = ctx.getImageData(0, 0, c.width, c.height);

var i;
for (i = 0; i < imgData.data.length; i += 4) {
  imgData.data[i]   = 255 - imgData.data[i];
  imgData.data[i+1] = 255 - imgData.data[i+1];
  imgData.data[i+2] = 255 - imgData.data[i+2];
  imgData.data[i+3] = 255;
}
ctx.putImageData(imgData, 0, 0);
</script>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page ( Press <kbd>F5</kbd> ) if you cannot see the result.
