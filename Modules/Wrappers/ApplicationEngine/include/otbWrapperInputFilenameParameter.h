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

#ifndef otbWrapperInputFilenameParameter_h
#define otbWrapperInputFilenameParameter_h

#include <string>
#include "otbWrapperStringParameter.h"

namespace otb
{
namespace Wrapper
{

/** \class InputFilenameParameter
 *  \brief This class represent a string parameter for the wrapper framework
 *
 * \ingroup OTBApplicationEngine
 */
class OTBApplicationEngine_EXPORT InputFilenameParameter
  : public Parameter
{
public:
  /** Standard class typedef */
  typedef InputFilenameParameter        Self;
  typedef StringParameter               Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Defining ::New() static method */
  itkNewMacro(Self);

  /** RTTI support */
  itkTypeMacro(InputFilenameParameter, Parameter);


  bool HasValue() const ITK_OVERRIDE
  {
    return m_StringParam->HasValue();
  }

  // Get Value
  otbGetObjectMemberMacro(StringParam, Value , std::string);

  // Set Value
  virtual void SetValue(const std::string value)
    {
    itkDebugMacro("setting member m_StringParam to " << value);
    this->m_StringParam->SetValue(value);
    SetActive(true);
    this->Modified();
    }

  // Clear Value
  void ClearValue() ITK_OVERRIDE
  {
    m_StringParam->ClearValue();
  }

protected:
  /** Constructor */
  InputFilenameParameter()
  {
    // Initialize the String Parameter
    m_StringParam= StringParameter::New();


  }

  /** Destructor */
  ~InputFilenameParameter() ITK_OVERRIDE
  {}

private:
  InputFilenameParameter(const InputFilenameParameter &); //purposely not implemented
  void operator =(const InputFilenameParameter&); //purposely not
                                                  //implemented

  StringParameter::Pointer m_StringParam;

}; // End class Parameter

} // End namespace Wrapper
} // End namespace otb

#endif
