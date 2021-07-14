# Under Construction …

# Surveillance System

## LPR - License Plate Recognition

An exercise of comparing each graphics processing engine of Recognition Rate Estimate for `License Plate Recognition`.

```
$keywords: surveillanc, lrp, license plate, recognition
```

## Content

* [Concept](#concept)
* [Requirements](#requirements)
* [Programming](#programming)
* [Observation](#observation)

## Concept

Comparing each engine for the function of `License Plate Recognition`.

## Requirements

1. Apply user account for each Ecosystem of `License Plate Recognition`.
2. Prepare 100 pcs of License Plate (in the same country).
3. Or parepare 10 mintues video clip.
3. Feed all License Plates/or video clip to LPR and comparing the results of each Ecosystem.

## Programming

- The Main Routine (feed.py), pick up the image and feed it to each Engine/Subroutine   
  ```
  ...
  ```
- The engine for each application of License Plate Recognition 

  |ID| Engine                                                                                                       | Subroutine    | Recognition Rate Estimate (%)|
  |--|--------------------------------------------------------------------------------------------------------------|---------------|------------------------------|
  | 1| [Openalpr](https://github.com/openalpr/openalpr)                                                             | [shell](alpr) |                              |
  | 2| [pyANPD](https://github.com/abdulfatir/pyANPD)                                                               | shell         |                              |
  | 3| [CHT IoT - Smart Service API](https://iot.cht.com.tw/iot/developer/intelligence)                             | [python](cht) |                              |
  | 4| [Google Cloud Platform - Vision API:TEXT_DETECTION](https://cloud.google.com/vision/)                        | [python](gcp) |                              |
  | 5| [Amazon Rekognition - Detecting Text](https://docs.aws.amazon.com/rekognition/latest/dg/text-detection.html) |               |                              |
  | 6| [Microsoft Azure - Computer Vision API](https://azure.microsoft.com/zh-tw/services/cognitive-services/face/) |               |                              |
  | 7| [Baidu - 通用文字識別](http://ai.baidu.com/tech/ocr/general)                                                   |               |                              |


### Reference

- [Developing a License Plate Recognition System with Machine Learning in Python](https://blog.devcenter.co/developing-a-license-plate-recognition-system-with-machine-learning-in-python-787833569ccd)
- [Openalpr - 如何產生測試用的車牌影像](http://albert-oma.blogspot.tw/2016/02/openalpr.html)

- Node RED http://iot.cht.com.tw/iot/developer/download
```
為降低IoT開發板程式開發門檻，中華電信IoT大平台提供Node RED圖控開發工具元件，可支援Raspberry Pi 3、BeagleBone Black 兩款 IoT開發板。相關元件、範例程式及說明文件已上架至 IoT大平台網站->開發者中心->相關下載->開發版SDK (http://iot.cht.com.tw/iot/developer/download)歡迎各位使用者下載試用
```

- CHT API
```
提供影像辨識、語音合成及語音辨識三大類型API，新增人臉辨識、車輛偵測、多語者國語語音合成 共3項API，累積完成9項API上架。詳情請參考 開發者中心->API文件->智慧服務->AI應用http://iot.cht.com.tw/iot/developer/intelligence
```

## Appendix

### WinIO for Win7

