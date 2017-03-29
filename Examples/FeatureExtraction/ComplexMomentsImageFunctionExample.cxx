/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#include "itkMacro.h"
#include "otbImage.h"

#include "otbImageFileReader.h"

//  Software Guide : BeginCommandLineArgs
//    INPUTS: {ROISpot5.png}
//    2 2
//  Software Guide : EndCommandLineArgs

// Software Guide : BeginLatex
//
// This example illustrates the use of the \doxygen{otb}{ComplexMomentsImageFunction}.
//
// The first step required to use this filter is to include its header file.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
#include "otbComplexMomentsImageFunction.h"
// Software Guide : EndCodeSnippet

int main(int argc, char * argv[])
{
  if (argc != 4)
    {
    std::cerr << "Usage: " << argv[0] << " inputImageFile ";
    std::cerr << " p q" << std::endl;
    return EXIT_FAILURE;
    }

  const char * inputFilename  = argv[1];

  unsigned int P((unsigned char) ::atoi(argv[2]));
  unsigned int Q((unsigned char) ::atoi(argv[3]));

  typedef unsigned char InputPixelType;
  const unsigned int Dimension = 2;
  typedef otb::Image<InputPixelType,  Dimension> InputImageType;

  typedef otb::ImageFileReader<InputImageType> ReaderType;

  ReaderType::Pointer reader = ReaderType::New();

  reader->SetFileName(inputFilename);

  //  Software Guide : BeginLatex
  //
  //  The \doxygen{otb}{ComplexMomentImageFunction} is templated over the
  //  input image type and the output complex type value, so we start by
  //  defining:
  //
  //  Software Guide : EndLatex

  // Software Guide : BeginCodeSnippet
  typedef otb::ComplexMomentsImageFunction<InputImageType> CMType;
  typedef CMType::OutputType OutputType;

  CMType::Pointer cmFunction = CMType::New();
  // Software Guide : EndCodeSnippet

  //  Software Guide : BeginLatex
  //
  // Next, we plug the input image into the complex moment function
  // and we set its parameters.
  //
  //  Software Guide : EndLatex

  // Software Guide : BeginCodeSnippet
  reader->Update();
  cmFunction->SetInputImage(reader->GetOutput());
  cmFunction->SetQmax(Q);
  cmFunction->SetPmax(P);
  // Software Guide : EndCodeSnippet

  //  Software Guide : BeginLatex
  // We can chose the pixel of the image which will used as center
  // for the moment computation
  //
  //  Software Guide : EndLatex

  // Software Guide : BeginCodeSnippet
  InputImageType::IndexType center;
  center[0] = 50;
  center[1] = 50;
  // Software Guide : EndCodeSnippet

  //  Software Guide : BeginLatex
  // We can also choose the size of the neighborhood around the
  // center pixel for the moment computation.
  //
  //  Software Guide : EndLatex

  cmFunction->SetNeighborhoodRadius(15);

  //  Software Guide : BeginLatex
  // In order to get the value of the moment, we call the
  // \code{EvaluateAtIndex} method.
  //
  //  Software Guide : EndLatex

  // Software Guide : BeginCodeSnippet
  OutputType Result = cmFunction->EvaluateAtIndex(center);

  std::cout << "The moment of order (" << P << "," << Q <<
  ") is equal to " << Result.at(P).at(Q) << std::endl;
  // Software Guide : EndCodeSnippet

  return EXIT_SUCCESS;
}
