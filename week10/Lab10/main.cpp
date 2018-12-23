/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 11-30-2018
** Description: fibonacci experiment  
*********************************************************************/

#include <ctime>
#include <iostream>

#include "inputValidation.hpp"
#include "FibonacciFunctions.hpp"

int main () {
	

	// timing idea adapted from: http://www.cplusplus.com/reference/ctime/clock/

	int n, rfn,ifn;
	std::cout << "Enter a positive integer to find its fibonacci number" << std::endl;
	n = isIntAboveX(0);

	// iterative function
	clock_t  itclock = clock();
	std::cout << std::endl;
	ifn = fibonacciIterative(n);
	std::cout << ifn  << std::endl;
	itclock = clock() - itclock;
	std::cout << "Found by iterative function in " << ((double)itclock)/(CLOCKS_PER_SEC/1000) << " milliseconds" << std::endl;

	// recursive function
	clock_t  rtclock = clock();
	std::cout << std::endl;
	rfn = fibonacciRecursive(n);
	std::cout << rfn  << std::endl;
	rtclock = clock() - rtclock;
	std::cout << "Found by recursive function in " << ((double)rtclock)/(CLOCKS_PER_SEC/1000) << " milliseconds" << std::endl;

	return 0;
}
