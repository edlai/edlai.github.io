# [Image Processing](../../)

## Mirror (Flipping)

```
$author:   Jin-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, colormap, b&w, mirror, flip
```

An implementation of digital image processing to change RGB image or colormap to negative-film image.

## Content

* [Requirements](#requirements)
* [Programming](#programming)
  * [HTML5](#html5)
  * [Javascript](#javascript)
* [Running](#running)
* [Reference](#reference)

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
<script type="text/JavaScript">
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var img = document.getElementById("lena");
ctx.drawImage(img, 0, 0);
var imgData = ctx.getImageData(0, 0, c.width, c.height);

var i;
var imgLen = imgData.data.length;

for (i = 0; i < imgData.data.length / 2; i += 4) {

  var tmp = imgData.data[i+0];
  imgData.data[i+0] = imgData.data[imgLen - 1 - (i + 3)];
  imgData.data[imgLen - 1 - (i + 3)] = tmp;
  
  tmp = imgData.data[i+1];
  imgData.data[i+1] = imgData.data[imgLen - 1 - (i + 2)];
  imgData.data[imgLen - 1 - (i + 2)] = tmp;

  tmp = imgData.data[i+2];
  imgData.data[i+2] = imgData.data[imgLen - 1 - (i + 1)];
  imgData.data[imgLen - 1 - (i + 1)] = tmp;

  tmp = imgData.data[i+3];
  imgData.data[i+3] = imgData.data[imgLen - 1 - (i + 0)];
  imgData.data[imgLen - 1 - (i + 0)] = tmp;
}
ctx.putImageData(imgData, 0, 0);

</script>
```

## Running

| Original                                                                     | Mirror (Horizontal + Vertical) |
|------------------------------------------------------------------------------|-------------------------------------------|
| <img id="lena" width="300" height="300" src="../../lena.png" alt="The Lena"> | <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas> |

<script type="text/JavaScript">
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var img = document.getElementById("lena");
ctx.drawImage(img, 0, 0);
var imgData = ctx.getImageData(0, 0, c.width, c.height);

var i;
var imgLen = imgData.data.length;

for (i = 0; i < imgData.data.length / 2; i += 4) {

  var tmp = imgData.data[i+0];
  imgData.data[i+0] = imgData.data[imgLen - 1 - (i + 3)];
  imgData.data[imgLen - 1 - (i + 3)] = tmp;
  
  tmp = imgData.data[i+1];
  imgData.data[i+1] = imgData.data[imgLen - 1 - (i + 2)];
  imgData.data[imgLen - 1 - (i + 2)] = tmp;

  tmp = imgData.data[i+2];
  imgData.data[i+2] = imgData.data[imgLen - 1 - (i + 1)];
  imgData.data[imgLen - 1 - (i + 1)] = tmp;

  tmp = imgData.data[i+3];
  imgData.data[i+3] = imgData.data[imgLen - 1 - (i + 0)];
  imgData.data[imgLen - 1 - (i + 0)] = tmp;
}
ctx.putImageData(imgData, 0, 0);

</script>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page ( Press <kbd>F5</kbd> ) if you cannot see the result.


## Reference

- [HTML5: Using Canvas to Flip Images](https://permadi.com/2009/04/html5-using-canvas-to-flip-images/)