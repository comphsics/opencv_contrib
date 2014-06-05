/*M///////////////////////////////////////////////////////////////////////////////////////
 //
 //  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
 //
 //  By downloading, copying, installing or using the software you agree to this license.
 //  If you do not agree to this license, do not download, install,
 //  copy or use the software.
 //
 //
 //                           License Agreement
 //                For Open Source Computer Vision Library
 //
 // Copyright (C) 2013, OpenCV Foundation, all rights reserved.
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
 //   * The name of the copyright holders may not be used to endorse or promote products
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

#include "precomp.hpp"

namespace cv
{
Saliency::~Saliency()
{

}

Ptr<Saliency> Saliency::create( const String& saliencyType )
{

  /*if( saliencyType.find( "STATIC_SALIENCY.SPECTRAL_RESIDUAL" ) == 0 )
  {
    return Ptr < Saliency > ( new StaticSaliencySpectralResidual() );
  }
  else if( saliencyType.find( "STATIC_SALIENCY.ITTI_CIO" ) == 0 )
  {
    //return Ptr < Saliency > ( new SaliencyIttiCIO() );
  }
  else if( saliencyType.find( "MOTION_SALIENCY.PBAS" ) == 0 )
  {
    return Ptr < Saliency > ( new MotionSaliencyPBAS() );
  }
  else if( saliencyType.find( "OBJECTNESS.BING" ) == 0 )
  {
    return Ptr < Saliency > ( new ObjectnessBING() );
  } */

  return Algorithm::create<Saliency>( "SALIENCY." + saliencyType );

  //CV_Error( -1, "Saliency algorithm type " + saliencyType + " not supported" );
  //return Ptr<Saliency>();
}

bool Saliency::computeSaliency( const InputArray& image, OutputArray& saliencyMap )
{
  if( image.empty() )
    return false;

  return computeSaliencyImpl( image, saliencyMap );
}

String Saliency::getClassName() const
{
  return className;
}

} /* namespace cv */
