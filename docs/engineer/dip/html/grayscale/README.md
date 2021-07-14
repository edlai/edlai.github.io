

### CSS

``` html
<style>
img.grayscale {
    -webkit-filter: grayscale(100%); /* Safari 6.0 - 9.0 */
    filter: grayscale(100%);
}
</style>
```

<style>
img.grayscale {
    -webkit-filter: grayscale(100%); /* Safari 6.0 - 9.0 */
    filter: grayscale(100%);
}
</style>


<p>Convert the image to grayscale:</p>
    
| Original                                                       | Grayscale                  |  
|----------------------------------------------------------------|----------------------------|  
|<img src="../../lena.png" alt="Lenna" width="300" height="300"> | <img class="grayscale" src="../../lena.png" alt="Lenna" width="300" height="300"> |   


<p><strong>Note:</strong> The filter property is not supported in Internet Explorer, Edge 12, or Safari 5.1 and earlier.</p>


## Reference

- [CSS filter Property](https://www.w3schools.com/cssref/css3_pr_filter.asp)