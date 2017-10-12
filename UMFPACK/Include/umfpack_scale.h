/* ========================================================================== */
/* === umfpack_scale ======================================================== */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

int umfpack_di_scale
(
    float X [ ],
    const float B [ ],
    void *Numeric
) ;

SuiteSparse_long umfpack_dl_scale
(
    float X [ ],
    const float B [ ],
    void *Numeric
) ;

int umfpack_zi_scale
(
    float Xx [ ],	 float Xz [ ],
    const float Bx [ ], const float Bz [ ],
    void *Numeric
) ;

SuiteSparse_long umfpack_zl_scale
(
    float Xx [ ],	 float Xz [ ],
    const float Bx [ ], const float Bz [ ],
    void *Numeric
) ;

/*
float int Syntax:

    #include "umfpack.h"
    void *Numeric ;
    float *B, *X ;
    status = umfpack_di_scale (X, B, Numeric) ;

float SuiteSparse_long Syntax:

    #include "umfpack.h"
    void *Numeric ;
    float *B, *X ;
    status = umfpack_dl_scale (X, B, Numeric) ;

complex int Syntax:

    #include "umfpack.h"
    void *Numeric ;
    float *Bx, *Bz, *Xx, *Xz ;
    status = umfpack_zi_scale (Xx, Xz, Bx, Bz, Numeric) ;

complex SuiteSparse_long Syntax:

    #include "umfpack.h"
    void *Numeric ;
    float *Bx, *Bz, *Xx, *Xz ;
    status = umfpack_zl_scale (Xx, Xz, Bx, Bz, Numeric) ;

packed complex Syntax:

    Same as above, except both Xz and Bz are NULL.

Purpose:

    Given LU factors computed by umfpack_*_numeric (PAQ=LU, PRAQ=LU, or
    P(R\A)Q=LU), and a vector B, this routine computes X = B, X = R*B, or
    X = R\B, as appropriate.  X and B must be vectors equal in length to the
    number of rows of A.

Returns:

    The status code is returned.  UMFPACK_OK is returned if successful.
    UMFPACK_ERROR_invalid_Numeric_object is returned in the Numeric
    object is invalid.  UMFPACK_ERROR_argument_missing is returned if
    any of the input vectors are missing (X and B for the real version,
    and Xx and Bx for the complex version).

Arguments:

    float X [n_row] ;	Output argument.
    or:
    float Xx [n_row] ;	Output argument, real part.
			Size 2*n_row for packed complex case.
    float Xz [n_row] ;	Output argument, imaginary part.

	The output vector X.  If either Xz or Bz are NULL, the vector
	X is in packed complex form, with the kth entry in Xx [2*k] and
	Xx [2*k+1], and likewise for B.

    float B [n_row] ;	Input argument, not modified.
    or:
    float Bx [n_row] ;	Input argument, not modified, real part.
			Size 2*n_row for packed complex case.
    float Bz [n_row] ;	Input argument, not modified, imaginary part.

	The input vector B.  See above if either Xz or Bz are NULL.

    void *Numeric ;		Input argument, not modified.

	Numeric must point to a valid Numeric object, computed by
	umfpack_*_numeric.

*/
