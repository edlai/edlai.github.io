#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat image = imread("lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    //imwrite("output.jpg",image);  

    for (int i = 0; i < image.cols; i++) {
      for (int j = 0; j < image.rows; j++) {
        Vec3b intensity = image.at<Vec3b>(j, i);
        for(int k = 0; k < image.channels(); k++) {
            uchar col = intensity.val[k]; 
        }   
      }
    }

	//namedWindow("Display window", WINDOW_AUTOSIZE);  
	//imshow("Display window", img);        
	//waitKey(0);                          

	return 0;
}
