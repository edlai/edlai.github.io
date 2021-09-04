#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{

 Mat image;
 image = imread("../../lena.png");

 Mat gray_image;
 cvtColor( image, gray_image, CV_BGR2GRAY );

 imwrite( "lena_grayimage.png", gray_image );

 //namedWindow( imageName, CV_WINDOW_AUTOSIZE );
 //namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

 //imshow( imageName, image );
 //imshow( "Gray image", gray_image );

 //waitKey(0);

 return 0;
}
