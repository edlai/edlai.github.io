# [Image Processing](../../)

## Grayscale

```
$author:   Ching-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, colormap, grayscale
```

An implementation of digital image processing to convert RGB image or colormap to grayscale (rgb2gray).

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
  var avg = Math.round(imgData.data[i] + imgData.data[i+1] + imgData.data[i+2]) / 3;
  imgData.data[i]   = avg;
  imgData.data[i+1] = avg;
  imgData.data[i+2] = avg;
  imgData.data[i+3] = 255;
}
ctx.putImageData(imgData, 0, 0);
</script>

```

## Running

| Original | Grayscale, r=g=b=(r+g+b)/3 |
|----------|----------------------------|
| <img id="lena" src="../../lena.png" alt="The Lena" width="300" height="300"> | <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas> |


<script type="text/JavaScript">
document.getElementById("lena").onload = function() {
  var c = document.getElementById("myCanvas");
  var ctx = c.getContext("2d");
  var img = document.getElementById("lena");
  ctx.drawImage(img, 0, 0);
  var imgData = ctx.getImageData(0, 0, c.width, c.height);
  // invert colors
  var i;
  for (i = 0; i < imgData.data.length; i += 4) {
    // 0.299r+0.587g+0.114b
    //var avg = Math.round(imgData.data[i]*0.299+imgData.data[i+1]*0.587+imgData.data[i+2]*0.114);
    var avg = Math.round(imgData.data[i]+imgData.data[i+1]+imgData.data[i+2])/3;

    imgData.data[i]   = avg;
    imgData.data[i+1] = avg;
    imgData.data[i+2] = avg;
    imgData.data[i+3] = 255;
  }
  ctx.putImageData(imgData, 0, 0);
};
</script>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page ( Press <kbd>F5</kbd> ) if you cannot see the result.
