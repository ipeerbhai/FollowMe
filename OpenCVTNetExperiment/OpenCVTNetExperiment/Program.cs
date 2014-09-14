using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenCV;

namespace OpenCVTNetExperiment
{
    class Program
    {
        static void Main(string[] args)
        {
            //OpenCV.Net.
            OpenCV.Net.Mat myImage = new OpenCV.Net.Mat(640, 480, OpenCV.Net.Depth.U8, 2);
            OpenCV.Net.Capture myCapture = OpenCV.Net.Capture.CreateCameraCapture(1);
            myCapture.GrabFrame();
            myImage = myCapture.RetrieveFrame(0);


        }
    }
}
