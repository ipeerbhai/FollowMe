// OpenCVRecognizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <Windows.h>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
// Class:
//	imageProcess is a series of image enhancers.  It can change colors, blur, sharpen, etc.  
//	It's not designed to do detection -- just imge processing transforms on whatever the cv::Mat m_imageToProcess.
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
class imageProcessor
{

public:
	bool bProcessImage = false;
	cv::Mat m_imageToProcess;
	//-----------------------------------------------------------------------------------------------------------------------------------
	// Function:
	//	This processes an image matrix in place, and returns a success code.
	// Parameters:
	//	Mat -- the matrix to process.
	// Returns:
	//	0 -- S_OK
	//	-1 -- E_FAIL
	//	1 -- E_WARN
	int imageMakeGray()
	{
		// Convert the image to greyscale.
		cv::Mat imageOutput;
		cv::cvtColor(m_imageToProcess, imageOutput, CV_RGB2GRAY);
		m_imageToProcess = imageOutput;
		return(0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------
	int drawCirclesInImage()
	{
		// BGR format, each value between 0 and 255
		cv::Scalar blue(150, 0, 0); // the blue color...
		cv::Scalar green(0, 200, 0);
		cv::Scalar white(200, 200, 200);
		int thickness = 2;
		int LINE_TYPE = CV_AA;

		string theText = "Hello, Imran";
		cv::Point centerOfBigCircle(640/2, 360/2);
		int circleRadius = 50; // in points, I think.

		cv::circle(m_imageToProcess, centerOfBigCircle, circleRadius, green, thickness, LINE_TYPE);
		return(0);

	}

	//-----------------------------------------------------------------------------------------------------------------------------------
	// Detect something.
	int DetectSomething()
	{
		
	}


	//-----------------------------------------------------------------------------------------------------------------------------------
	// Function:
	//	This processes an image matrix in place, and returns a success code.
	// Parameters:
	//	Mat -- the matrix to process.
	// Returns:
	//	0 -- S_OK
	//	-1 -- E_FAIL
	//	1 -- E_WARN
	int processImage()
	{
		if ((!bProcessImage) || (m_imageToProcess.empty()))
			return(0); // do nothing and exit
		//imageMakeGray();
		drawCirclesInImage();
		return(0);
	}


};

//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
// Class:
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
class imageRecognizer
{
public:
	cv::Mat m_imageToRecognize;

};

//-----------------------------------------------------------------------------------------------------------------------------------
void on_tackbar(int pos, void *processPointer)
{
	imageProcessor *myProcessor = (imageProcessor *)processPointer;
	if (pos > 0)
	{
		myProcessor->bProcessImage = true;
	}
	else
	{
		myProcessor->bProcessImage = false;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------
// Function:
//	This processes an image matrix in place, and returns a success code.
// Parameters:
//	Mat -- the matrix to process.
// Returns:
//	0 -- S_OK
//	-1 -- E_FAIL
//	1 -- E_WARN
int convertMatToGrayscale(cv::Mat * matrixToTransform)
{

	return (0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int cameraNumber = 1; // This is done by trial and error -- on a surface pro 3, 0 is the back camera, and 1 the front.
	char keyPressed = 0; // We read it through openCV's library
	imageProcessor myProcessor;
	cv::Mat imageFromCamera;
	cv::Mat imageToDisplay;
	int slider = 0; // A slider position
	const int SLIDER_MAX = 1; // The furthest value possible in the slider.

	// Create a window and initialize the video camera.

	cv::namedWindow("Hello"); // just what I want to name this window...
	cv::VideoCapture camera(cameraNumber);
	camera.open(cameraNumber);

	// out a trackbar in the window...
	cv::createTrackbar("Color", "Hello", &slider, SLIDER_MAX, on_tackbar, &myProcessor);

	// Read the camera in a loop and break out if the letter "q" is pressed on the keyboard.

	while (camera.isOpened())
	{
		camera >> imageFromCamera;
		if (!imageFromCamera.empty())
		{
			// Process the image by doing something to it...
			myProcessor.m_imageToProcess = imageFromCamera;
			myProcessor.processImage();
			imageToDisplay = myProcessor.m_imageToProcess;
		}
		else
		{
			// We should probably show an error image...
			// But for now, do nothing.
		}
		cv::imshow("Hello", imageToDisplay);
		keyPressed = cv::waitKey(20); // need to call this to actually render the drawing.  Bad API name...
		if (keyPressed == 'q')
			break;
	}
	cout << "bye-bye" << endl;
	Sleep(100);
	return 0;
}
