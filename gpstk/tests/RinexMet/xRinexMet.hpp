#pragma ident "$Id: xRinexMet.hpp 3140 2012-06-18 15:03:02Z susancummins $"

//============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 2.1 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//
//  Copyright 2009, The University of Texas at Austin
//
//============================================================================

#ifndef XRINEXMET_HPP
#define XRINEXMET_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "RinexMetBase.hpp"
#include "RinexMetData.hpp"
#include "RinexMetHeader.hpp"
#include "RinexMetFilterOperators.hpp"
#include "RinexMetStream.hpp"
#include "Exception.hpp"
#include <fstream>

/*
**** This test covers the RinexMet*.[ch]pp files for Rinex I/O Manipulation
*/

using namespace std;

class xRinexMet: public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (xRinexMet);
        CPPUNIT_TEST (bitsAsStringTest);
	CPPUNIT_TEST (bitStringTest);
	CPPUNIT_TEST (reallyPutRecordTest);
	CPPUNIT_TEST (reallyGetRecordTest);
	CPPUNIT_TEST (convertObsTypeSTRTest);
	CPPUNIT_TEST (convertObsTypeHeaderTest);
	CPPUNIT_TEST (hardCodeTest);
	CPPUNIT_TEST (continuationTest);
	CPPUNIT_TEST (dataExceptionsTest);
	CPPUNIT_TEST (filterOperatorsTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);

	protected:
		void bitsAsStringTest (void);
		void bitStringTest (void);
		void reallyPutRecordTest (void);
		void reallyGetRecordTest (void);
		void convertObsTypeSTRTest (void);
		void convertObsTypeHeaderTest (void);
		void hardCodeTest (void);
		void continuationTest (void);
		void dataExceptionsTest (void);
		void filterOperatorsTest (void);
		bool fileEqualTest (char* handle1, char* handle2);
	private:

};

#endif
