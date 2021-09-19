# under construction...

# Surveillance System

## CHT IoT - Smart Service API

## Content

- [Conpect](#conpect)
- [Requirements](#requirements)
- [Programming](#programming)
- [Advanced](#advanced)

## Conpect

An exercise of CHT IoT - Smart Service API.

## Requirements

- sample.jpg
  ![sample.jpg](sample.jpg)

## Programming

  - cht.py ( borrowed from [LPR-Client-Sample](https://github.com/CHTTL912/LPR-Client-Sample) )
  ``` py
  #!/usr/bin/env python
  # -*- coding: utf-8 -*-

  import  os, sys, requests

  #parameters
  url = 'http://iot.cht.com.tw/api/ivs-lpr/snapshot'

  def main(argv):
    filepath =argv[1]
    files = {'file': open(filepath, 'rb')}
    r = requests.post(url, files=files)
    if r.status_code != 200:
        print(r)
        sys.exit(1)
    else:
        print(r.json())

  if __name__ == "__main__":
    main(sys.argv)
  ```
## Reference

- [LPR-Client-Sample](https://github.com/CHTTL912/LPR-Client-Sample)
