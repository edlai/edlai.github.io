#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{

 Mat im_rgb  = imread("../../lena.png");
 Mat im_gray;
 cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
 Mat img_bw = im_gray > 128;
 imwrite("lena_monochrome.png", img_bw);
 return 0;
}
