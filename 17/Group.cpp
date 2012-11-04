/**
*@file		Group.cpp
*@brief		This file contains implementations of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#include "stdafx.h"
#include "Group.h"

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( Group* dat )
{
	printf ( "Enter please data:\n" ) ;
	char *tmp = ( char* ) malloc ( 5 ) ;
	for ( int i = 0 ; i < N ; i++ )
	{
		printf ( "\n%d :\n" , i + 1 ) ;
		printf ( "Enter Name:\t" ) ;
		while ( !scanf ( "%13[A-Z,a-z,'-']s" , dat [ i ].cName ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Name!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
		printf ( "Enter Year:\t" ) ;
		while ( !scanf ( "%4[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Year!! Enter again:\t" ) ;
		}
		dat [ i ].usYear = atoi ( tmp ) ;
		fflush ( stdin ) ;
		printf ( "Enter Count:\t" ) ;
		while ( !scanf ( "%4[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Count!! Enter again:\t" ) ;
		}
		dat [ i ].usCnt = atoi ( tmp ) ;
		fflush ( stdin ) ;
		printf ( "Enter Name of Shef:\t" ) ;
		while ( !scanf ( "%13[a-z,A-Z]s" , dat [ i ].cShef ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Name of Shef!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
	}
}

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( Group* dat )
{
	 srand ( unsigned int ( time(NULL)));
	printf ( "\n\t    Name:\t   Year:   Count:\tName of Shef:\n\n" ) ;
	for ( int i = 0 ; i < N ; i++ )
	{
		printf ( "\n%20s%10u%10u%20s\n" ,
			dat[ i ].cName , dat[ i ].usYear , dat[ i ].usCnt , dat[ i ].cShef ) ;
	}
}



/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( Group* dat )
{
	Group temp;
	for ( register int i = 0 ; i < N ; ++i )
	{
		for ( register int j = i + 1 ; j < N ; ++j )
		{
			if ( strcmp ( dat[ j ].cName , dat [ i ].cName ) < 0 )
			{
				temp = dat [ j ] ;
				dat [ j ] = dat [ i ] ;
				dat [ i ] = temp;
			}
		}
	}
}

/**
*@brief		This function random chooses 3 group and looks most numerous
*@param		[dat] 
*@return	void
*/
void RandGr ( Group* dat ) 
{
	
	unsigned char X1 , X2 , X3 ;
	X1 = rand ( ) % N;
	while ( ( X2 = rand ( ) % N ) == X1 ) { }
	do
	{
		X3 = rand ( ) % N ;
	} while ( X3 == X1 || X3 == X2 ) ;
	int max;
	max = ( dat [ X1 ].usCnt > dat [ X2 ].usCnt ) ? dat [ X1 ].usCnt : dat [ X2 ].usCnt ;
	max = ( max > dat [ X3 ].usCnt ) ? max : dat [ X3 ].usCnt ;
	printf ( "\n\nIn random 3 schosed group : %d %d %d the most numerous is:\n\n" , X1 + 1 , X2 + 1 , X3 + 1 ) ;
	if ( dat [ X1 ].usCnt == max )
	{
		printf ( "In group %d \t %d participants \n" , X1 + 1 , max ) ;
	}
	if ( dat [ X2 ].usCnt == max )
	{
		printf ( "In group %d \t %d participants \n" , X2 + 1 , max ) ;
	}
	if ( dat [ X3 ].usCnt == max )
	{
		printf ( "In group %d \t %d participants \n" , X3 + 1 , max ) ;
	}

}

/**
*@brief		This function implemets interface
*@param		[void] 
*@return	void
*/
void Run ( void ) 
{
	srand ( ( unsigned  int ) time ( NULL ) ) ;
	Group *grList ;
	grList = ( Group* ) malloc ( sizeof ( Group ) * N ) ;
	if ( !grList )
	{
		printf ( "\nError in allocate memory!\n" );
		return;
	}
	ScanData ( grList ) ;
	SortData ( grList ) ;
	PrintData ( grList ) ;
	RandGr(grList);
	free ( grList );
}