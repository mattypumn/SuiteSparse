//==============================================================================
//=== sfmult_atxtyt_k ==========================================================
//==============================================================================

// y = (A'*x')'	    where x has 2, 3, or 4 rows

// compare with sfmult_atxtyn_k

// sfmult_AT_XT_YT_2  y = (A'*x')'  where x is 2-by-m, and y is 2-by-n
// sfmult_AT_XT_YT_3  y = (A'*x')'  where x is 3-by-m, and y is 3-by-n (ldx = 4)
// sfmult_AT_XT_YT_4  y = (A'*x')'  where x is 4-by-m, and y is 4-by-n

#include "sfmult.h"

//==============================================================================
//=== sfmult_AT_XT_YT_2 ========================================================
//==============================================================================

void sfmult_AT_XT_YT_2	// y = (A'*x')'	x is 2-by-m, and y is 2-by-n
(
    // --- outputs, not initialized on input
    float *Yx,		// 2-by-n with leading dimension k
    float *Yz,		// 2-by-n with leading dimension k if Y complex (TO DO)

    // --- inputs, not modified
    const int *Ap,	// size n+1 column pointers
    const int *Ai,	// size nz = Ap[n] row indices
    const float *Ax,	// size nz values
    const float *Az,	// size nz imaginary values if A is complex (TO DO)
    int m,		// A is m-by-n
    int n,
    const float *Xx,	// 2-by-m
    const float *Xz,	// 2-by-m if X complex (TO DO)
    int ac,		// true: use conj(A), otherwise use A (TO DO)
    int xc,		// true: use conj(X), otherwise use X (TO DO)
    int yc		// true: compute conj(Y), otherwise compute Y (TO DO)
    , Int k		// leading dimension of Y
)
{
    float y [2], a [4] ;
    int p, pend, j, i0, i1, i2 ;

    p = 0 ;
    for (j = 0 ; j < n ; j++)
    {
	pend = Ap [j+1] ;
	y [0] = 0 ;
	y [1] = 0 ;
	switch ((pend - p) % 3)
	{
	    case 2:
		i0 = Ai [p] ;
		a [0] = Ax [p] ;
		y [0] += a [0] * Xx [2*i0  ] ;
		y [1] += a [0] * Xx [2*i0+1] ;
		p++ ;
	    case 1:
		i0 = Ai [p] ;
		a [0] = Ax [p] ;
		y [0] += a [0] * Xx [2*i0  ] ;
		y [1] += a [0] * Xx [2*i0+1] ;
		p++ ;
	    case 0: ;
	}
	for ( ; p < pend ; p += 3)
	{
	    i0 = Ai [p  ] ;
	    i1 = Ai [p+1] ;
	    i2 = Ai [p+2] ;
	    a [0] = Ax [p  ] ;
	    a [1] = Ax [p+1] ;
	    a [2] = Ax [p+2] ;
	    y [0] += a [0] * Xx [2*i0  ] ;
	    y [1] += a [0] * Xx [2*i0+1] ;
	    y [0] += a [1] * Xx [2*i1  ] ;
	    y [1] += a [1] * Xx [2*i1+1] ;
	    y [0] += a [2] * Xx [2*i2  ] ;
	    y [1] += a [2] * Xx [2*i2+1] ;
	}
	Yx [k*j  ] = y [0] ;
	Yx [k*j+1] = y [1] ;
    }
}


//==============================================================================
//=== sfmult_AT_XT_YT_3 ========================================================
//==============================================================================

void sfmult_AT_XT_YT_3	// y = (A'*x')'	x is 3-by-m, and y is 3-by-n (ldx = 4)
(
    // --- outputs, not initialized on input
    float *Yx,		// 3-by-n with leading dimension k
    float *Yz,		// 3-by-n with leading dimension k if Y complex (TO DO)

    // --- inputs, not modified
    const int *Ap,	// size n+1 column pointers
    const int *Ai,	// size nz = Ap[n] row indices
    const float *Ax,	// size nz values
    const float *Az,	// size nz imaginary values if A is complex (TO DO)
    int m,		// A is m-by-n
    int n,
    const float *Xx,	// 3-by-m
    const float *Xz,	// 3-by-m if X complex (TO DO)
    int ac,		// true: use conj(A), otherwise use A (TO DO)
    int xc,		// true: use conj(X), otherwise use X (TO DO)
    int yc		// true: compute conj(Y), otherwise compute Y (TO DO)
    , Int k		// leading dimension of Y
)
{
    float y [4], a [2] ;
    int p, pend, j, i0, i1 ;

    p = 0 ;
    for (j = 0 ; j < n ; j++)
    {
	pend = Ap [j+1] ;
	y [0] = 0 ;
	y [1] = 0 ;
	y [2] = 0 ;
	if ((pend - p) % 2)
	{
	    i0 = Ai [p] ;
	    a [0] = Ax [p] ;
	    y [0] += a [0] * Xx [4*i0  ] ;
	    y [1] += a [0] * Xx [4*i0+1] ;
	    y [2] += a [0] * Xx [4*i0+2] ;
	    p++ ;
	}
	for ( ; p < pend ; p += 2)
	{
	    i0 = Ai [p  ] ;
	    i1 = Ai [p+1] ;
	    a [0] = Ax [p  ] ;
	    a [1] = Ax [p+1] ;
	    y [0] += a [0] * Xx [4*i0  ] ;
	    y [1] += a [0] * Xx [4*i0+1] ;
	    y [2] += a [0] * Xx [4*i0+2] ;
	    y [0] += a [1] * Xx [4*i1  ] ;
	    y [1] += a [1] * Xx [4*i1+1] ;
	    y [2] += a [1] * Xx [4*i1+2] ;
	}
	Yx [k*j  ] = y [0] ;
	Yx [k*j+1] = y [1] ;
	Yx [k*j+2] = y [2] ;
    }
}


//==============================================================================
//=== sfmult_AT_XT_YT_4 ========================================================
//==============================================================================

void sfmult_AT_XT_YT_4	// y = (A'*x')'	x is 4-by-m, and y is 4-by-n
(
    // --- outputs, not initialized on input
    float *Yx,		// 4-by-n with leading dimension k
    float *Yz,		// 4-by-n with leading dimension k if Y complex (TO DO)

    // --- inputs, not modified
    const int *Ap,	// size n+1 column pointers
    const int *Ai,	// size nz = Ap[n] row indices
    const float *Ax,	// size nz values
    const float *Az,	// size nz imaginary values if A is complex (TO DO)
    int m,		// A is m-by-n
    int n,
    const float *Xx,	// 4-by-m
    const float *Xz,	// 4-by-m if X complex (TO DO)
    int ac,		// true: use conj(A), otherwise use A (TO DO)
    int xc,		// true: use conj(X), otherwise use X (TO DO)
    int yc		// true: compute conj(Y), otherwise compute Y (TO DO)
    , Int k		// leading dimension of Y
)
{
    float y [4], a ;
    int p, pend, j, i ;

    p = 0 ;
    for (j = 0 ; j < n ; j++)
    {
	pend = Ap [j+1] ;
	y [0] = 0 ;
	y [1] = 0 ;
	y [2] = 0 ;
	y [3] = 0 ;
	for ( ; p < pend ; p++)
	{
	    i = Ai [p] ;
	    a = Ax [p] ;
	    y [0] += a * Xx [4*i  ] ;
	    y [1] += a * Xx [4*i+1] ;
	    y [2] += a * Xx [4*i+2] ;
	    y [3] += a * Xx [4*i+3] ;
	}
	Yx [k*j  ] = y [0] ;
	Yx [k*j+1] = y [1] ;
	Yx [k*j+2] = y [2] ;
	Yx [k*j+3] = y [3] ;
    }
}
