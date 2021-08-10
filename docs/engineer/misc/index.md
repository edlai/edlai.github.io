# Miscellaneous

## imagemagick

_Install:_

``` sh
$ sudo apt-get install imagemagick
```

_Usage:_

``` sh
$ convert  -resize 20% source.png dest.jpg
# - OR -
$ convert -resize 1024X768  source.png dest.jpg
```

## Youtube-dl

_Install:_

``` sh
$ sudo apt-get install ffmpeg
$ sudo pip3 install youtube-dl
$ sudo pip3 install ffmpeg
```

_Usage:_

``` sh
youtube-dl 'bestvideo[height<=480][ext=mp4]+bestaudio/best[height<=480][ext=m4a]' https://www.youtube.com/watch?v=jxSR_NDnR9Y&t=25s&ab_channel=LearnEnglishThroughStory
```