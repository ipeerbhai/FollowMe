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
		cv::Point centerOfBigCircle(640 / 2, 360 / 2);
		int circleRadius = 50; // in points, I think.

		cv::circle(m_imageToProcess, centerOfBigCircle, circleRadius, green, thickness, LINE_TYPE);
		return(0);

	}
	//-----------------------------------------------------------------------------------------------------------------------------------
	int  BlurImage()
	{
		cv::blur(m_imageToProcess, m_imageToProcess, cv::Size(5, 5));
		int MatType = m_imageToProcess.type();
		return(0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------
	// Sobel is one of the edge highlighting algorithms.  The two ones mentioned in the docs are Sobel and Scharr.
	//	Sobel is the worse one ( according to the docs ), but easier to use?
	//	It can detect edges in X and Y ( though I'm unsure if both at the same time. )
	//	See "HighlightEdges" to see Sobel used for both X and Y.  This Function does it only in Y.
	int SobelImage()
	{
		cv::Sobel(m_imageToProcess, m_imageToProcess, CV_8U, 1, 0, 3, 1, 0, 4); // CV_8U is the default type.  This is an 8-bit, unsigned single int per point ( Greyscale )
		return(0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------
	// HighlightEdges is a double Sobel edge highlight function.
	int HighlightEdges()
	{
		cv::Mat imageXHighlyight; //highlight horizontal edges
		cv::Mat imageYHighlyight; // highlight vertical edges
		cv::Mat imageResult; // A matrix to store a result of adding X and Y together.

		cv::Sobel(m_imageToProcess, imageXHighlyight, CV_8U, 1, 0, 3, 2, 0, 4); // X highlight
		cv::Sobel(m_imageToProcess, imageYHighlyight, CV_8U, 0, 1, 3, 2, 0, 4); // Y highlight

		cv::addWeighted(imageXHighlyight, 0.5, imageYHighlyight, 0.5, 1, imageResult);
		m_imageToProcess = imageResult;

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
		imageMakeGray();
		//drawCirclesInImage();
		BlurImage();
		HighlightEdges();
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
		try
		{
			cv::imshow("Hello", imageToDisplay);
			keyPressed = cv::waitKey(20); // need to call this to actually render the drawing.  Bad API name...
			if (keyPressed == 'q')
				break;
		}
		catch (exception e)
		{
			Sleep(100);
		}
	}
	cout << "bye-bye" << endl;
	Sleep(100);
	return 0;
}
