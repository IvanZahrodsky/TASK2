/**
*@file		School.cpp
*@brief		This file contains implementations of function according to task 16
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
	char *tmp = ( char* ) malloc ( 4 ) ;
	for ( int i = 0 ; i < N ; i++ )
	{
		printf ( "\n%d :\n" , i + 1 ) ;
		printf ( "Enter Surname:\t" ) ;
		while ( !scanf ( "%13[A-Z,a-z]s" , dat [ i ].cSrName ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Surname!! Enter again:\t" ) ;
		}
		fflush ( stdin ) ;
		printf ( "Enter Name:\t" ) ;
		while ( !scanf ( "%13[A-Z,a-z]s" , dat [ i ].cName ) )
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
		dat [ i ].usSchool = atoi ( tmp ) ;
		fflush ( stdin ) ;
		printf ( "Enter Class:\t" ) ;
		while ( !scanf ( "%3[0-9]s" , tmp ) )
		{
			fflush ( stdin ) ;
			printf ( "\nError in entered Class!! Enter again:\t" ) ;
		}
		dat [ i ].usClass = atoi ( tmp ) ;
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
	for ( int i = 0 ; i < N ; i++ )
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
	for ( int i = 0 ; i < N ; i++ )
	{
		for ( int j = i + 1 ; j < N ; j++ )
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
	unsigned char * pCnt = ( unsigned char* ) malloc ( N * 2 ) ;
	pCnt [ 0 ] = 0;
	pCnt [ 1 ] = 0;
	int k = 0;
	int max = 0;
	for( int i = 0 ; i < N ; i++ )
	{
		if ( dat [ i ].usClass == 9 )
		{
			if ( dat [ i ].usSchool == pCnt [ k - 1 ] )
			{
				pCnt [ k - 2 ] ++;
			}
			else
			{
				k = k + 2 ;
				pCnt [ k - 2 ] = 1 ;
				pCnt [ k - 1 ] = dat [ i ].usSchool ;
			}
			if ( pCnt [ k - 2] > max )
			{
					max = pCnt [ k - 2 ] ;
			}
		}
	}
	if ( k != 0 )
	{
		printf ( "\nMost students in grade 9 were:\n" ) ;
		for ( int i = 0 ; i < k ; i = i + 2 )
		{
			if( pCnt [ i ] == max )
			{
				printf ( "\nIn School No. %u\t%u\tstudents\n" , pCnt [ i + 1 ] , pCnt [ i ] ) ;
			}
		}
	}
	else
	{
		printf ( "\nAmong the participants no students in grade 9!!\n" ) ;
	}
}