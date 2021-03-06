// @(#)root/tmva $Id$
// Author: Manos Stergiadis

/**********************************************************************************
 * Project: TMVA - a Root-integrated toolkit for multivariate data analysis       *
 * Package: TMVA                                                                  *
 * Class  :                                                                       *
 * Web    : http://tmva.sourceforge.net                                           *
 *                                                                                *
 * Description:                                                                   *
 *      Testing Flatten function for Reference backend                            *
 *                                                                                *
 * Authors (alphabetical):                                                        *
 *      Manos Stergiadis      <em.stergiadis@gmail.com - CERN, Switzerland        *
 *                                                                                *
 * Copyright (c) 2005-2015:                                                       *
 *      CERN, Switzerland                                                         *
 *      U. of Victoria, Canada                                                    *
 *      MPI-K Heidelberg, Germany                                                 *
 *      U. of Bonn, Germany                                                       *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in LICENSE           *
 * (http://tmva.sourceforge.net/LICENSE)                                          *
 **********************************************************************************/

////////////////////////////////////////////////////////////////////
// Testing Flattening/Deflattening on the GPU                     //
////////////////////////////////////////////////////////////////////

#include "TMVA/DNN/Architectures/Cuda.h"
#include "TestReshape.h"

int main()
{
   using Scalar_t = Double_t;
   std::cout << "Testing Flattening/Deflattening on the GPU:" << std::endl;

   bool status = true;

   std::cout << "Test Reshape: " << std::endl;
   status &= testReshape<TCuda<Scalar_t>>();
   if (!status) {
      std::cerr << "ERROR - testReshape failed " << std::endl;
      return 1;
   }

   std::cout << "Test Flatten: " << std::endl;
   status &= testFlatten<TCuda<Scalar_t>>();
   if (!status) {
      std::cerr << "ERROR - testFlatten failed " << std::endl;
      return 1;
   }

   std::cout << "Test Deflatten: " << std::endl;
   status &= testDeflatten<TCuda<Scalar_t>>();
   if (!status) {
      std::cerr << "ERROR - testDeflatten failed " << std::endl;
      return 1;
   }
}
