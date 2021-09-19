import cv2
import sys

vcap = cv2.VideoCapture("rtsp://admin:@192.168.167.30/1/h264major")

while(1):
    ret, frame = vcap.read()
    cv2.imshow('VIDEO', frame)
    cv2.waitKey(1)