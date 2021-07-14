#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;
// start of pixel navigation

Mat navigate(Mat img) {

    if(img.channels()==1){
        Mat_<uchar>::iterator it = img.begin<uchar>();
        Mat_<uchar>::iterator itend = img.end<uchar>();
        for(;it!=itend;it++){
            (*it) = 255 - (*it);
        }
    }
    if(img.channels()==3){
        Mat_<Vec3b>::iterator it = img.begin<Vec3b>();
        Mat_<Vec3b>::iterator itend = img.end<Vec3b>();
        for(;it!=itend;it++){
            (*it)[0] = 255 - (*it)[0];
            (*it)[1] = 255 - (*it)[1];
            (*it)[2] = 255 - (*it)[2];
        }
    }
    return img;
}

// end of pixel navigation

int main( int argc, char** argv )
{
    Mat src = cv::imread("../../lena.png", CV_LOAD_IMAGE_COLOR);

    if(! src.data){
        cout << "could not open or find the image" << endl;
        return -1;
    }
    Mat dst = navigate(src.clone());    
    imwrite("lena_negative.png", dst);

    //cv::imshow( " Original", img);
    //cv::imshow( " Altered ", newImage);
    //cv::waitKey(0);

    return 0;

}