import cv2
import sys
 
#cascPath = sys.argv[1]
cascPath = "haarcascade_frontalface_default.xml";
faceCascade = cv2.CascadeClassifier(cascPath)

# from argv (could be WebCam or Streaming)
# videoPath = sys.argv[2]
# video_capture = cv2.VideoCapture(videoPath)

# from WebCam
# video_capture = cv2.VideoCapture(0)

# from Streaming
# video_capture = cv2.VideoCapture("rtsp://admin:@192.168.167.30/1/h264major")

# while True:
# Capture frame-by-frame
# ret, frame = video_capture.read()

# gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

img = cv2.imread("../../lena.png")

gray =cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)    

faces = faceCascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30),
    flags=cv2.cv.CV_HAAR_SCALE_IMAGE
)

# Draw a rectangle around the faces
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)

cv2.imwrite('lena_face.png',img)

# Display the resulting frame
# cv2.imshow('Video', frame)

# if cv2.waitKey(1) & 0xFF == ord('q'):
#    break
 
# When everything is done, release the capture
# video_capture.release()
# cv2.destroyAllWindows()