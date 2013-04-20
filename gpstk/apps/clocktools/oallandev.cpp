#pragma ident "$Id: oallandev.cpp 3140 2012-06-18 15:03:02Z susancummins $"
/**********************************************
/ GPSTk: Clock Tools
/ oallandev.cpp
/ 
/ Computes the overlapping Allan deviation
/ (reference)
/
/ Written by Timothy J.H. Craddock (tjhcraddock@gmail.com)
/ Last Updated: Dec. 11, 2008
**********************************************/

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


#include <iostream>
#include <vector>

#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
	// Structures used to store time and clock phase information
	vector <double> timeArray;
	vector <double> phaseArray;
	long double time, phase;
	long unsigned int numPoints, i, numGaps;
	
	// All of the time and clock phase data is read in from the standard input
	i = 0;
	while(!feof(stdin))
	{
		cin >> time >> phase;
		if(feof(stdin)) break;
		timeArray.resize(i+1);
		phaseArray.resize(i+1);
		timeArray[i] = time;
		phaseArray[i] = phase;
		i++;
	}
	
	numPoints = i-1;
	
	// Variables used in Overlapping Allan Deviation calculations
	double Tau, Tau0, sum, sigma;
	int N, m;
	
	// Ensures there are at least the minimum number of points required to do calculations
	N = numPoints;
	if(N > 1) Tau0 = timeArray[1] - timeArray[0];
	else
	{
		cout << "Not Enough Points to Calculate Tau0" << endl;
		Tau0;
	}
	
	// Actual Overlapping Allan Deviation Calculation is done here
	// The Overlapping Allan Deviation is calculated as follows
	//  Sigma^2(Tau) = 1 / (2*(N-2*m)*Tau^2) * Sum(X[i+2*m]-2*X[i+m]+X[i], i=1, i=N-2*m)
	//  Where Tau is the averaging time, N is the total number of points, and Tau = m*Tau0
	//  Where Tau0 is the basic measurement interval
	
        for(m = 1; m <= (N-1)/2; m++)
	{
	        numGaps=0;
                Tau = m*Tau0;
		sigma = 0;
		
		for(i = 0; i < (N-2*m); i++)
		{
			sum = 0;
			if((phaseArray[i+2*m]==0 ||  phaseArray[i+m]==0 || phaseArray[i]==0) 
			   && i!=0 && i!=(N-2*m-1))
			    numGaps++;
                        else
                            sum = phaseArray[i+2*m] - 2*phaseArray[i+m] + phaseArray[i];
			sigma += sum * sum;
		}
		
		sigma = sigma / (2.0*((double)N-(double)numGaps-0-2.0*(double)m)*Tau*Tau);
		sigma = sqrt(sigma);
		fprintf(stdout, "%.1f %.4e \n", Tau, sigma); // outputs results to the standard output
        }
	/*************
	*************/

	return(0);
}