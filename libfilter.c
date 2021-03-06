#include <scilab/scicos_block4.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "filter.h"

#define pi		3.14159265358979323846	/* pi */

#define r_IN(n, i) ((GetRealInPortPtrs(blk, n+1))[(i)]) 
#define r_OUT(n, i) ((GetRealOutPortPtrs(blk, n+1))[(i)])

void rfilter1(scicos_block *blk, int flag)
{
	static int64_t x1=0;
	static int64_t x2=0;
	static int64_t y1=0;
	static int64_t y2=0;
	static int64_t y=0;
	int64_t x;
	
	int64_t a2;
	int64_t a3;
	int64_t b1;
	int64_t b2;
	int64_t b3;
	int64_t shift;
	
    switch(flag)
    {
	case 1:		
	    r_OUT(0, 0) = (double)(y>>10);
	break;
	case 2:
		a2 = r_IN(1,1);
		a3 = r_IN(1,2);
		b1 = r_IN(2,0);
		b2 = r_IN(2,1);
		b3 = r_IN(2,2);
		shift = r_IN(3,0);
	
		x = (int64_t)r_IN(0, 0);
		x = x;
		y = (-a2*y1 - a3*y2 + b1*x + b2*x1 + b3*x2) >> shift;
		
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;	

	break;
	case 4:
		x1=0;
		x2=0;
		y1=0;
		y2=0;
		y=0;
	break;
    }
}
