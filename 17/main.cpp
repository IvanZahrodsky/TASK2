#include "Group.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
	srand ( ( unsigned  int ) time ( NULL ) ) ;
	Group *grList ;
	grList = ( Group* ) malloc ( sizeof ( Group ) * N ) ;
	ScanData ( grList ) ;
	SortData ( grList ) ;
	PrintData ( grList ) ;
	RandGr(grList);
	
	return 0;
}