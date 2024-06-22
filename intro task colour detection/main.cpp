#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <stdlib.h>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/imgproc/detail/distortion_model.hpp"
#include "opencv2/imgproc/hal/hal.hpp"
#include "opencv2/imgproc/hal/interface.h"


using namespace cv;
using namespace std;

//Create a function to threshold the stored image to detect the specific colour range

Mat TestThreshold(const Mat& hsvimage, const Scalar& lowerBound,const Scalar& upperBound)
{
    Mat mask;

    inRange(hsvimage, lowerBound, upperBound, mask);

    return mask;

}


//Create function to check if colour is present in image presented

bool ifColourPresent(const Mat & mask)
{
    int nonZEROcount = countNonZero(mask);

    return nonZEROcount > 100;
}



int main()
{
    //store image. In this case, blue car. But we are writing code to detect this colour
    Mat image = imread("red_car.png"); //blue car stored in variable image( this can change to anything

    if(image.empty()) //check if image is there
    {
        cerr << "No image available" << endl; //print out no image available

        return -1;
    }

    //Converting the image into HSV

    Mat hsvimage;

    cvtColor(image, hsvimage, COLOR_BGR2HSV); //COLOR_BGR2HSV is the colour conversion.

    //DEFINE THE HSV RANGES FOR DIFFERENT COLOURS.

    //HSV colour characteristics for red, green, blue, yellow, turquise, orange

    //RED


    Scalar lowerBlue(99, 115, 86), upperBlue(107, 255, 255);//BLUE


    Scalar lowerGreen(58, 103, 49), upperGreen(92, 255, 255);//GREEN


    Scalar lowerRed(0, 197, 131), upperRed(179, 255, 255);//RED



    Scalar lowerYellow(20, 100, 100), upperYellow(30, 255, 255);//YELLOW

    Scalar lowerOrange(18, 40, 90), upperOrange(27, 255, 255); //ORANGE

   // Scalar lowerPink(99, 115, 86), upperPink(107, 255, 255);



   //Now Threshold the image to check the colour range


   Mat BlueMask = TestThreshold(hsvimage, lowerBlue, upperBlue);//BLUE


   Mat GreenMask = TestThreshold(hsvimage, lowerGreen, upperGreen);//Green


   Mat RedMask = TestThreshold(hsvimage, lowerRed, upperRed); //RED


   //Mat YellowMask = TestThreshold(hsvimage, lowerYellow, upperYellow); //Yellow

   //Mat OrangeMask = TestThreshold(hsvimage, lowerOrange, upperOrange);//Orange


   // Check for the presence of each color
 if(ifColourPresent(BlueMask)) //red
    {
        cout << "Colour Blue detected" << endl;

 imshow("Blue photo", BlueMask);
 }

 else if(ifColourPresent(GreenMask)) //green
    {
        cout << "Colour green detected" << endl;

 imshow("Green photo", GreenMask);
 }

  else if(ifColourPresent(RedMask)) //green
    {
        cout << "Colour Red detected" << endl;

 imshow("Red photo", RedMask);
 }

 /*
 else if(ifColourPresent(YellowMask)) //green
    {
        cout << "Colour Yellow detected" << endl;

 imshow("Yellow photo", YellowMask);
 }

  else if(ifColourPresent(YellowMask)) //green
    {
        cout << "Colour Yellow detected" << endl;

 imshow("Yellow photo", YellowMask);
 }

 */

 waitKey(0);

 destroyAllWindows();

 return 0;









}
