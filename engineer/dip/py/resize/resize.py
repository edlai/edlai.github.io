import cv2
 
# load the image with imread()
imageSource = '../../lena.png'
src = cv2.imread(imageSource)
 
height, width = src.shape[:2]
dest = cv2.resize(src,(width/2, height/2), interpolation = cv2.INTER_CUBIC)
 
cv2.imwrite('lena_resize.png',dest)

# display the images on screen with imshow()
# cv2.imshow( "Original", dest )
  
# wait time in milliseconds
# this is required to show the image
# 0 = wait indefinitely
# cv2.waitKey(0)
 
# close the windows
#cv2.destroyAllWindows()

