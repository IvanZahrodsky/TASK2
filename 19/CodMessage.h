/**
*@file		CodMessage.h
*@brief		This file contains interface of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/


#ifndef  _COD_MESSAGE_H
#define _COD_MESSAGE_H

#include "stdafx.h"
#include "CodMessage.h"

const int N=5;

struct CodMes
{
	char cMEssage [ 20 ] ;
	unsigned long ulCod; 
};
/**
*@brief		This function implemets interface
*@param		[void] 
*@return	void
*/
void Run ( void );

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( CodMes*  ) ;

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( CodMes*  ) ;

/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( CodMes* ) ;

/**
*@brief		This function check two identical digits in the code
*@param		[dat] 
*@return	bool
*/
bool CheckDigits( unsigned long ) ;
/**
*@brief		This function  displays data that have two identical digits in the code
*@param		[dat] 
*@return	void
*/
void Print( CodMes* dat );

#endif //_COD_MESSAGE_H
