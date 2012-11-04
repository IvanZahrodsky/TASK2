/**
*@file		School.cpp
*@brief		This file contains implementations of function according to task
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#include "School.h"

/**
*@brief		This function scaning data from keyboard
*@param		[dat] 
*@return	void
*/
void ScanData ( School* dat )
{
	printf ( "Enter please data:\n" ) ;
	char *tmp = (char*) malloc(4);
	for ( register int i = 0 ; i < N ; ++i )
	{
		printf ( "\n%d :\n" , i + 1 ) ;
		printf ( "Enter Surname:\t" ) ;
		while ( !scanf ( "%13[A-Z,a-z]s" , dat[ i ].cSrName ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Surname!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
		printf ( "Enter Name:\t" ) ;
		while ( !scanf ( "%13[A-Z,a-z]s" , dat[ i ].cName ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Name!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
		printf ( "Enter School:\t" ) ;
		while ( !scanf ( "%3[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered School!! Enter again:\t" ) ;
		}
		dat[ i ].usSchool = atoi ( tmp ) ;
		fflush ( stdin ) ;
		printf ( "Enter Class:\t" ) ;
		while ( !scanf ( "%3[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Class!! Enter again:\t" ) ;
		}
		dat[ i ].usClass = atoi ( tmp ) ;
		fflush ( stdin ) ;
	}
}

/**
*@brief		This function  displays data
*@param		[dat] 
*@return	void
*/
void PrintData ( School* dat )
{
	printf ( "\n\t    Surname:\t\t   Name:   School:    Class:\n\n" ) ;
	for ( register int i = 0 ; i < N ; ++i )
	{
		printf ( "\n%20s%20s%10u%10u\n" ,
			dat[ i ].cSrName , dat[ i ].cName , dat[ i ].usSchool , dat[ i ].usClass ) ;
	}


}

/**
*@brief		This function sorting data 
*@param		[dat] 
*@return	void
*/
void SortData ( School* dat )
{
	School temp;
	for( register int i = 0 ; i < N ; ++i )
	{
		for( register int j = i + 1 ; j < N ; ++j )
		{
			if ( dat[ j ].usSchool <  dat[ i ].usSchool )
			{
				temp = dat [ j ] ;
				dat [ j ] = dat [ i ] ;
				dat [ i ] = temp;
			}
			else if ( dat [ j ].usSchool ==  dat [ i ].usSchool &&
					 dat [ j ].usClass <  dat [ i ].usClass )
			{
				temp = dat [ j ] ;
				dat [ j ] = dat [ i ] ;
				dat [ i ] = temp ;
			}
		}
	}
}


/**
*@brief		This function check in which the schools pupil in grade 9
*@param		[dat] 
*@return	void
*/
void CheckSchool ( School* dat )
{
	int iCount = 0 ;
	int iSch = 0 ;
	for( register int i = 0 ; i < N ; ++i )
	{
		if ( dat [ i ].usClass == 9 )
		{
			if ( dat [ i ].usSchool == iSch )
			{
				iCount++;
			}
			else
			{
				iCount = 1 ;
				iSch = dat [ i ].usSchool ;
			}
		}
	}
	if ( iCount == 0 )
	{
		printf ( "\nAmong the participants no students in grade 9!!\n" ) ;
	}
	else
	{
		printf ( "\nMost students in grade 9 were from School No. %u\n" , iSch ) ;
	}
}
/**
*@brief		This function implements interface
*@param		[void]
*@return	void	
*/
void Running ( void )
{
	School *scList ;
	scList = ( School* ) malloc ( sizeof ( School ) * N ) ;
	if ( !scList )
	{
		printf ( "Error in alocate memory!" );
		return;
	}
	ScanData ( scList ) ;
	SortData ( scList ) ;
	PrintData ( scList ) ;
	CheckSchool ( scList ) ;
	free ( scList );
}