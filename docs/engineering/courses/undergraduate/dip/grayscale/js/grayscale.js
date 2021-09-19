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