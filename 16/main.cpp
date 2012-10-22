/**
*@file		main.cpp
*@brief		This file contains the main function that implementing tasks.
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#include "School.h"

int main(int argc, char ** argv)
{
	School *scList ;
	scList = ( School* ) malloc ( sizeof ( School ) * N ) ;
	ScanData ( scList ) ;
	SortData ( scList ) ;
	PrintData ( scList ) ;
	CheckSchool ( scList ) ;
	return 0;
}