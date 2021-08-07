# [Image Processing](../../)

## Colorbar

```
$author:   Ching-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, colormap, colorbar
```

An implementation of digital image processing to generate colorbar for screen test.

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
<canvas id="myCanvas" width="240" height="320" style="border:1px solid #d3d3d3;"> </canvas>
```

### Javascript

```javascript
<script>
var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
ctx.fillStyle="gray";
ctx.fillRect(0,0,30,320);
ctx.fillStyle="yellow";
ctx.fillRect(30,0,30,320);
ctx.fillStyle="cyan";
ctx.fillRect(60,0,30,320);
ctx.fillStyle="green";
ctx.fillRect(90,0,30,320);
ctx.fillStyle="magenta";
ctx.fillRect(120,0,30,320);
ctx.fillStyle="red";
ctx.fillRect(150,0,30,320);
ctx.fillStyle="blue";
ctx.fillRect(180,0,30,320);
ctx.fillStyle="black";
ctx.fillRect(210,0,30,320);
ctx.putImageData(imgData, 0, 0);
</script>
```

## Running

<canvas id="myCanvas" width="240" height="320" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas>

<script>
var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
ctx.fillStyle="gray";
ctx.fillRect(0,0,30,320);
ctx.fillStyle="yellow";
ctx.fillRect(30,0,30,320);
ctx.fillStyle="cyan";
ctx.fillRect(60,0,30,320);
ctx.fillStyle="green";
ctx.fillRect(90,0,30,320);
ctx.fillStyle="magenta";
ctx.fillRect(120,0,30,320);
ctx.fillStyle="red";
ctx.fillRect(150,0,30,320);
ctx.fillStyle="blue";
ctx.fillRect(180,0,30,320);
ctx.fillStyle="black";
ctx.fillRect(210,0,30,320);
ctx.putImageData(imgData, 0, 0);
</script>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page ( e.q. Press <kbd>F5</kbd> ) if you cannot see the result.
