/**
*@file		Schhol.h
*@brief		This file contains interface of function according to task
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#ifndef _SCHOOL_H_
#define _SCHOOL_H_

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

const int N=5;

struct School
{
	char cSrName [ 14 ] ;
	char cName [ 14 ] ;
	unsigned short	usSchool ;
	unsigned short	usClass ;
};

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( School* dat ) ;

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( School* dat ) ;

/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( School* dat ) ;

/**
*@brief		This function check in which the schools pupil in grade 9
*@param		[dat] 
*@return	void
*/
void CheckSchool ( School* dat ) ;
/**
*@brief		This function implements interface
*@param		[void]
*@return	void	
*/
void Running ( void );
#endif  //_SCHOOL_H_