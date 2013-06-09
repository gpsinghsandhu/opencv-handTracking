//*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                                License Agreement
//                       For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2008-2011, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of Intel Corporation may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef _HANDDETECTOR_HPP_
#define _HANDDETECTOR_HPP_

#include <vector>
#include "opencv2/core.hpp"

using namespace std;

namespace cv {
namespace HT {

//Base class for Detector module. Defines bare minimum for derived classes to provide common interface

//Initialization of all detectors must be done using a mask which the user has to provide. */

class CV_EXPORTS HandDetector {
protected:
	//Initialization method - returns true if initialization successful. Each detector class may define overloaded functions according to different needs.
	virtual bool initialize(Mat & _rgbImg, Mat & _depthImg, Mat & _mask, bool _useDepth) = 0;

	//Detect function to be called in the video loop for subsequent detection of the hand
	virtual void detect(Mat & _rgbImg, Mat & _depthImg, OutputArray probImg) = 0;

	//Get params value of the detector class. Here vector is used where the exact ordering of the individual parameters must be defined by the detector class itself.
	virtual void getParams(vector<int> intPrams, vector<double> doubleParams) const = 0;

	//Set params value. Ordering must be similar to what is defined for getParams
	virtual void setParams(vector<int> intParams, vector<double> doubleParams) = 0;

	//Virtual Destructor for HandDetector class
	virtual ~HandDetector() { }
};

}
}
#endif