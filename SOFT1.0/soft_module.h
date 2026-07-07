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
/* Important: This file is not part of original SOFT1.0 */

#ifndef SOFT_MODULE_H
#define SOFT_MODULE_H

#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(SOFT_EXPORT)
#define SOFT_DECL __declspec(dllexport)
#define SOFT_DECL_PRIVATE
#elif defined(SOFT_IMPORT)
#define SOFT_DECL __declspec(dllimport)
#define SOFT_DECL_PRIVATE
#else
#define SOFT_DECL
#define SOFT_DECL_PRIVATE
#endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#if defined(SOFT_EXPORT) || defined(SOFT_IMPORT)
#define SOFT_DECL __attribute__((visibility("default")))
#define SOFT_DECL_PRIVATE __attribute__((visibility("hidden")))
#else
#define SOFT_DECL
#define SOFT_DECL_PRIVATE
#endif
#else
#define SOFT_DECL
#define SOFT_DECL_PRIVATE
#endif

#endif
