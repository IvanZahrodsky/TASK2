/**
*@file		CodMessage.cpp
*@brief		This file contains implementations of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#include "stdafx.h"

/**
*@brief		This function implemets interface
*@param		[void] 
*@return	void
*/
void Run ( void )
{
	srand ( ( unsigned  int ) time ( NULL ) ) ;
	CodMes *cmList ;
	cmList = ( CodMes* ) malloc ( sizeof ( CodMes ) * N ) ;
	if ( !cmList )
	{
		printf ( "\nError in allocate memory!\n" );
		return;
	}
	ScanData ( cmList ) ;
	SortData ( cmList ) ;
	PrintData ( cmList ) ;
	Print ( cmList );
	free ( cmList );
}

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( CodMes* dat )
{
	printf ( "Enter please data:\n" ) ;
	char *tmp = ( char* ) malloc ( 22 ) ;
	if ( !tmp )
	{
		printf ( "Error" );
		return;
	}
	for ( register int i = 0 ; i < N ; ++i )
	{
		printf ( "\n%d :\n" , i + 1 ) ;
		printf ( "Enter Code:\t" ) ;
		while ( !scanf ( "%12[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Code!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
		dat [i].ulCod = atol ( tmp );
		printf ( "Enter Message:\t" ) ;
		while ( !scanf ( "%20[a-z,A-Z,',','-','.']s" , dat [i] .cMEssage ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Year!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
	}
	free ( tmp );
}

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( CodMes* dat )
{
	printf ( "\n\t    Code:\t\tMessage:\n\n" ) ;
	for ( register int i = 0 ; i < N ; ++i )
	{
		printf ( "\n%15u%25s\n" , dat[ i ].ulCod , dat [i].cMEssage ) ;
	}
}

/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( CodMes* dat )
{
	CodMes temp;
	for ( register int i = 0 ; i < N ; ++i )
	{
		for ( register int j = i + 1 ; j < N ; ++j )
		{
			if ( dat[j].ulCod > dat[i].ulCod )
			{
				temp = dat [ j ] ;
				dat [ j ] = dat [ i ] ;
				dat [ i ] = temp;
			}
		}
	}
}


/**
*@brief		This function check two identical digits in the code
*@param		[dat] 
*@return	bool
*/
bool  CheckDigits( unsigned long x ) 
{
	int temp = -1;
	do
	{
		if ( x%10 == temp)
		{
			return true;
		}
		temp = x%10;
		x /= 10;
	}
	while ( x > 0 );
	return false;
}

/**
*@brief		This function  displays data that have two identical digits in the code
*@param		[dat] 
*@return	void
*/
void Print ( CodMes* dat )
{
	printf ( "\n\t    Code:\t\tMessage:\n\n" ) ;
	for ( register int i = 0 ; i < N ; ++i )
	{
		if ( CheckDigits ( dat[i].ulCod ) )
		{
			printf ( "\n%15u%25s\n" , dat[ i ].ulCod , dat [i].cMEssage ) ;
		}
	}
}
