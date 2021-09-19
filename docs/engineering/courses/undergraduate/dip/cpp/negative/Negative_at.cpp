#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace cv;

void sharpen(const Mat &src, Mat &dst);

int main( int argc, char** argv )
{

 Mat src  = imread("../../lena.png", CV_LOAD_IMAGE_UNCHANGED);
 Mat dst;
 sharpen(src, dst);
 //namedWindow("window1");
 //imshow("window1", src);
 //imshow("window2", dst);
 //waitKey(0);
 imwrite("lena_negative.png", dst);

 return 0;
}

void sharpen(const Mat &src, Mat &dst){
    src.copyTo(dst);
    const int nChannels = src.channels();
    int heightLimit = src.rows - 1;
    int widthLimit = nChannels * (src.cols-1);
    for(int iH=1; iH<heightLimit; iH++){
        const uchar *prePtr = src.ptr<const uchar>(iH-1);
        const uchar *curPtr = src.ptr<const uchar>(iH);
        const uchar *nextPtr = src.ptr<const uchar>(iH+1);
        uchar *dstPtr = dst.ptr<uchar>(iH);
        for(int iW=nChannels; iW<widthLimit; iW++){
            dstPtr[iW] = saturate_cast<uchar>(5*curPtr[iW]-curPtr[iW-nChannels]-curPtr[iW+nChannels]-prePtr[iW]-nextPtr[iW]);
        }
    }
}

if(img.channels()==1){
    Mat_<uchar>::iterator it = img.begin<uchar>();
    Mat_<uchar>::iterator itend = img.end<uchar>();
    for(;it!=itend;it++){
        (*it) = (*it) + 20;
    }
}
if(img.channels()==3){
    Mat_<Vec3b>::iterator it = img.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = img.end<Vec3b>();
    for(;it!=itend;it++){
        (*it)[0] = 255 - (*it)[0];
        (*it)[1] = (*it)[1] + 20;
        (*it)[2] = (*it)[2] + 20;
    }
}