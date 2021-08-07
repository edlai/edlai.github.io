#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace cv;

int main(int argc, char **argv)
{
  Mat image;
  image = imread("../../lena.png");

  Mat grayscale;
  cvtColor(image, grayscale, CV_BGR2GRAY);
  imwrite("lena_`grayscale.png", grayscale);
  return 0;
}