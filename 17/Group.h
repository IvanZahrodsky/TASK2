/**
*@file		Group.h
*@brief		This file contains interface of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#ifndef _GROUP_H_
#define _GROUP_H_

#include "stdafx.h"

const int N=5;

struct Group
{
	char cName [ 14 ] ;
	unsigned short	usYear ;
	unsigned short	usCnt ;
	char cShef [ 14 ] ;
};

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( Group* dat ) ;

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( Group* dat ) ;

/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( Group* dat ) ;


/**
*@brief		This function random chooses 3 group and looks most numerous
*@param		[dat] 
*@return	void
*/
void RandGr ( Group* dat ) ;

/**
*@brief		This function implemets interface
*@param		[void] 
*@return	void
*/
void Run ( void ) ;
#endif //_GROUP_H_