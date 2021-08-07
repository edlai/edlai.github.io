# Grayscale

---
title: Grayscale
summary: A brief description of my document.
authors: Ching-Wen (Ed) Lai
date: Mar. 2018
keywords: image, processing, rgb, colormap, grayscale
---

## Content

An implementation of digital image processing to convert RGB image or colormap to grayscale (rgb2gray).

## Programming

!!! SampleCode

    === "CPP"

        _Example_:

        Grayscale.cpp

        ``` c
        --8<--
        docs/engineer/dip/grayscale/cpp/Grayscale.cpp
        --8<--
        ```

        CMakeLists

        ``` makefile
        --8<--
        docs/engineer/dip/grayscale/cpp/CMakeLists.txt
        --8<--
        ```

    === "Javascript"

        _Requirements_:

        - Web Browsers

        _Example_:

        ``` html
        --8<--
        docs/engineer/dip/grayscale/js/grayscale.html
        --8<--
        ```

        _JavaScript_:

        ``` makefile
        --8<--
        docs/engineer/dip/grayscale/js/grayscale.js
        --8<--
        ```

    === "PHP"

        _Example_:

        ``` c
        --8<--
        docs/engineer/dip/grayscale/php/grayscale.php
        --8<--
        ```

    === "Python"

        _Example_:

        ``` c
        --8<--
        docs/engineer/dip/grayscale/py/grayscale.py
        --8<--
        ```

## Running

| Original | Grayscale, r=g=b=(r+g+b)/3 |
|----------|----------------------------|
| <img id="lena" src="../lena.png" alt="The Lena" width="300" height="300"> | <canvas id="myCanvas" width="300" height="300" style="border:1px solid #d3d3d3;"> Your browser does not support the HTML5 canvas tag.</canvas> |


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
