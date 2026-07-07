/***************************************************************************
  **************************************************************************
  
                SOFT: SO(3) Fourier transform code

                Version 1.0

  
   Peter Kostelec, Dan Rockmore
   {geelong,rockmore}@cs.dartmouth.edu
  
   Contact: Peter Kostelec
            geelong@cs.dartmouth.edu
  
  
   Copyright 2003 Peter Kostelec, Dan Rockmore
  
  
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
  
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
  
     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  
  
   Commercial use is absolutely prohibited.
  
   See the accompanying LICENSE file for details.
  
  ************************************************************************
  ************************************************************************/

/**
   
   header file for functions that are all concerned with the construction of
   Wigner functions:

   L2_aN_so3(), L2_bN_so3(), L2_cN_so3():
          coefficients in the recurrence relation

   EvalPtsW(), CosEvalPts(), CosEvalPts2(), SinEvalPts(), SinEvalPts2():
          where to sample Wigners

   wigSpec_L2():
          make a wigner whose degree equals the absolute value of one of
	  its order

   genWig_L2():
          make an array of wigners

   genWigTrans_L2():
          make an array of wigners (the transpose of above function)

   genAllWig():
          make ALL the Wigner little-d's necessary to do a full
	  FORWARD SOFT (i.e. SO(3)) transform

   genAllWigTrans():
          make ALL the Wigner little-d's necessary to do a full
	  INVERSE SOFT (i.e. SO(3)) transform


  ************************************************************************/


#ifndef _MAKEWIGNER_H
#define _MAKEWIGNER_H 1

#include "soft_module.h"

SOFT_DECL
extern double L2_aN_so3( int ,
		     int ,
		     int ) ;

SOFT_DECL
extern double L2_bN_so3( int ,
		     int ,
		     int ) ;

SOFT_DECL
extern double L2_cN_so3( int ,
		     int ,
		     int ) ;

SOFT_DECL
extern void EvalPtsW( int ,
		      double * ) ;

SOFT_DECL
extern void CosEvalPts( int ,
			double * ) ;

SOFT_DECL
extern void SinEvalPts( int ,
			double * ) ;

SOFT_DECL
extern void CosEvalPts2( int ,
			 double * ) ;

SOFT_DECL
extern void SinEvalPts2( int ,
			 double * ) ;

SOFT_DECL
extern void wigSpec_L2( int ,
			int ,
			double * ,
			double * ,
			int ,
			double * ) ;

SOFT_DECL
extern void genWig_L2( int ,
		       int ,
		       int ,
		       double * ,
		       double * ,
		       double * ,
		       double * ,
		       double * ,
		       double * ) ;

SOFT_DECL
extern void genWigTrans_L2( int ,
			    int ,
			    int ,
			    double * ,
			    double * ,
			    double * ,
			    double * ,
			    double * ,
			    double * ) ;

SOFT_DECL
extern void genWigAll( int ,
		       double * ,
		       double * ) ;

SOFT_DECL
extern void genWigAllTrans( int ,
			    double * ,
			    double * ) ;

#endif /* _MAKEWIGNER_H */
