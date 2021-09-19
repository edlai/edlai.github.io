# Image Processing

## Mirror
```
$author:   Ching-Wen (Ed) Lai           
$date:     Mar. 2018
$keywords: image, processing, rgb, colormap, b&w, black, white
```


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

```

## Running

| Original | Monochrome                                   |
|----------|----------------------------------------------|
| <img id="lena" src="../../lena.png" alt="The Lena" width="300" height="300"> | <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas> |

<script>

var canvas = document.getElementById('canvas'),
    ctx = canvas.getContext('2d'),
    flipButton = document.getElementById('flipButton'),
    img = new Image(),
    width = 500,
    height = 328;

function flipImage(image, ctx, flipH, flipV) {
    var scaleH = flipH ? -1 : 1, // Set horizontal scale to -1 if flip horizontal
        scaleV = flipV ? -1 : 1, // Set verical scale to -1 if flip vertical
        posX = flipH ? width * -1 : 0, // Set x position to -100% if flip horizontal 
        posY = flipV ? height * -1 : 0; // Set y position to -100% if flip vertical
    
    ctx.save(); // Save the current state
    ctx.scale(scaleH, scaleV); // Set scale to flip the image
    ctx.drawImage(img, posX, posY, width, height); // draw the image
    ctx.restore(); // Restore the last saved state
};

function flipNinjas() {
    var flipH = document.getElementById('horizontalCheckbox').checked,
        flipV = document.getElementById('verticalCheckbox').checked;
    
    flipImage(img, ctx, flipH, flipV);
    
    return false;
}

flipButton.onclick = flipNinjas;
img.onload = flipNinjas;

img.src = 'http://3.bp.blogspot.com/-h_hVjcMqx8Q/TdSbVhT18sI/AAAAAAAAACQ/y-egUR0AtRM/s1600/ninja_true-ninjas.gif';

//////////////////

var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var img = document.getElementById("lena");
ctx.drawImage(img, 0, 0);
var imgData = ctx.getImageData(0, 0, c.width, c.height);


/* invert colors
var i;
for (i = 0; i < imgData.data.length; i += 4) {
  // 0.299r + 0.587g + 0.114b
  var avg = Math.round(imgData.data[i]*0.299+imgData.data[i+1]*0.587+imgData.data[i+2]*0.114);
  if(avg >= 127){ 
    avg = 255; 
  }else{
    avg = 0;
  }
  imgData.data[i]   = avg;
  imgData.data[i+1] = avg;
  imgData.data[i+2] = avg;
  imgData.data[i+3] = 255;
}
ctx.putImageData(imgData, 0, 0);
*/
</script>

#### Note:
- The canvas tag is not supported in Internet Explorer 8 and earlier versions.
- Try to Refresh this Page (e.q. Pressing `F5`) if you cannot see the result.
