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