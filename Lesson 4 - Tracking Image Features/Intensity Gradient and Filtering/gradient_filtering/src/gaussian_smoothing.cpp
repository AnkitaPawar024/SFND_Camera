#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void gaussianSmoothing1()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("../images/img1gray.png");
  
    // create filter kernel
    float factor = 273;
    float gauss_data[25] = {1, 4, 7, 4, 1,
                            4, 16, 26, 16, 4,
                            7, 26, 41, 26, 7,
                            4, 16, 26, 16, 4,
                            1, 4, 7, 4, 1};
    
    cv::Mat kernel = cv::Mat(5, 5, CV_32F, gauss_data);
  
  	// TODO: Divide each element of the kernel by the sum of all the values in the kernel.
    for(int i = 0; i < 25; i++){
      gauss_data[i] /= factor;
    }

    // apply filter
    cv::Mat result; // destination
    int depth = -1;
    cv::Point anchor = cv::Point(-1, -1); //anchor point; default value Point(-1,-1) means that the anchor is at the kernel center. 
    double delta = 0; //ptional value added to the filtered pixels before storing them in dst. 

    cv::filter2D(img, result, depth, kernel, anchor, delta, cv::BORDER_DEFAULT);

    // show result
    string windowName = "Gaussian Blurring";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, result);
    cv::waitKey(0); // wait for keyboard input before continuing
}

int main()
{
    gaussianSmoothing1();
}