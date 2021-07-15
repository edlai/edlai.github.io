# -*- coding: utf-8 -*-
#!/usr/bin/python

import os
import subprocess 
import re

files = os.listdir("./")

files = sorted(files)

total = 0;
hit = 0;

for file in files:
    total = total + 1
    if (file.endswith('.JPG')):
        print ('--------------------------------------------------')
        print("filename = %s" % file)              # ex. B01001_AAA-1234.JPG
        f = re.split('\_|\.|\-', file)             # split to B01001 AAA 1234
        idealo = (f[1] + '-' +f[2])                
        ideal = (f[1] + f[2])
        serial = f[0]                              # serial
        print ( "ideal plate =  %s" % ideal)
        
        cmd = []
        cmd.append('alpr')
		#cmd.append('python ./plant-gcp.py')
        cmd.append(file)
        run = ' '.join(cmd)
        p = subprocess.Popen(run, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        i = 0
        result = ''
        for line in p.stdout.readlines():
            if (i == 0):
                print ("%d %s" % (i, line))
            else:
                line = re.sub( '\s+|\-|\t', ' ', line ).strip()
                l = line.split(' ')
                candidate = l[0]
                if (candidate == ideal):
                    hit = hit + 1
                    result = candidate
                    print ("[OK]  %02d: %10s | %s" % (i, ideal, candidate))
                else:
                    print ("[NOK] %02d: %10s | %s" % (i, ideal, candidate))
            i = i + 1
        print ("total= %d hit= %d" % (total, hit))
 
        record= open('car.csv','a')
        if (len(result)):
		  record.write("%02d, %02d, %10s, %10s, %10s\n" % (total, hit, serial, idealo, result))
        else:
          record.write("%02d, %02d, %10s, %10s, %10s\n" % (total, hit, serial, idealo, candidate))
        record.close()

        retval = p.wait()


