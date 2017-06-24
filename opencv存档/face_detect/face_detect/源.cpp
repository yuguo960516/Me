#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay(Mat frame);

/** Global variables */
String face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

/** @function main */
int main(void)
{
	Mat picture = imread("G://My picture//pavF-fxxwrwh4527289.jpg");
	namedWindow("My Test", CV_WINDOW_NORMAL);
	//-- 1. Load the cascades
	face_cascade.load(face_cascade_name);

	while (1)
	{

		//-- 3. Apply the classifier to the frame
		detectAndDisplay(picture);

		int c = waitKey(10);
		if ((char)c == 27) { break; } // escape
	}
	return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 4, 8, 0);

	}
	//-- Show what you got
	imshow("My Test", frame);
}

