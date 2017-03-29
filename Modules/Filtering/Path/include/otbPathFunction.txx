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

#ifndef otbPathFunction_txx
#define otbPathFunction_txx

#include "otbPathFunction.h"

namespace otb
{

/**
 * Constructor
 */
template <class TInputPath, class TOutput>
PathFunction<TInputPath, TOutput>
::PathFunction()
{
  m_Path = ITK_NULLPTR;
}

/**
 * Standard "PrintSelf" method
 */
template <class TInputPath, class TOutput>
void
PathFunction<TInputPath, TOutput>
::PrintSelf(std::ostream& os, itk::Indent indent) const
{
  Superclass::PrintSelf(os, indent);
  os << indent << "InputPath: " << m_Path.GetPointer() << std::endl;
}

/**
 * Initialize by setting the input image
 */
template <class TInputPath, class TOutput>
void
PathFunction<TInputPath, TOutput>
::SetInputPath(const InputPathType * ptr)
{
  // set the input path
  m_Path = ptr;
}

} // end namespace otb

#endif
