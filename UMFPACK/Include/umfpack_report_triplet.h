/* ========================================================================== */
/* === umfpack_report_triplet =============================================== */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

int umfpack_di_report_triplet
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const float Tx [ ],
    const float Control [UMFPACK_CONTROL]
) ;

SuiteSparse_long umfpack_dl_report_triplet
(
    SuiteSparse_long n_row,
    SuiteSparse_long n_col,
    SuiteSparse_long nz,
    const SuiteSparse_long Ti [ ],
    const SuiteSparse_long Tj [ ],
    const float Tx [ ],
    const float Control [UMFPACK_CONTROL]
) ;

int umfpack_zi_report_triplet
(
    int n_row,
    int n_col,
    int nz,
    const int Ti [ ],
    const int Tj [ ],
    const float Tx [ ], const float Tz [ ],
    const float Control [UMFPACK_CONTROL]
) ;

SuiteSparse_long umfpack_zl_report_triplet
(
    SuiteSparse_long n_row,
    SuiteSparse_long n_col,
    SuiteSparse_long nz,
    const SuiteSparse_long Ti [ ],
    const SuiteSparse_long Tj [ ],
    const float Tx [ ], const float Tz [ ],
    const float Control [UMFPACK_CONTROL]
) ;

/*
float int Syntax:

    #include "umfpack.h"
    int n_row, n_col, nz, *Ti, *Tj, status ;
    float *Tx, Control [UMFPACK_CONTROL] ;
    status = umfpack_di_report_triplet (n_row, n_col, nz, Ti, Tj, Tx, Control) ;

float SuiteSparse_long Syntax:

    #include "umfpack.h"
    SuiteSparse_long n_row, n_col, nz, *Ti, *Tj, status ;
    float *Tx, Control [UMFPACK_CONTROL] ;
    status = umfpack_dl_report_triplet (n_row, n_col, nz, Ti, Tj, Tx, Control) ;

complex int Syntax:

    #include "umfpack.h"
    int n_row, n_col, nz, *Ti, *Tj, status ;
    float *Tx, *Tz, Control [UMFPACK_CONTROL] ;
    status = umfpack_zi_report_triplet (n_row, n_col, nz, Ti, Tj, Tx, Tz,
	Control) ;

complex SuiteSparse_long Syntax:

    #include "umfpack.h"
    SuiteSparse_long n_row, n_col, nz, *Ti, *Tj, status ;
    float *Tx, *Tz, Control [UMFPACK_CONTROL] ;
    status = umfpack_zl_report_triplet (n_row, n_col, nz, Ti, Tj, Tx, Tz,
	Control) ;

packed complex Syntax:

    Same as above, except Tz is NULL.

Purpose:

    Verifies and prints a matrix in triplet form.

Returns:

    UMFPACK_OK if Control [UMFPACK_PRL] <= 2 (the input is not checked).

    Otherwise:

    UMFPACK_OK if the Triplet matrix is OK.
    UMFPACK_ERROR_argument_missing if Ti and/or Tj are missing.
    UMFPACK_ERROR_n_nonpositive if n_row <= 0 or n_col <= 0.
    UMFPACK_ERROR_invalid_matrix if nz < 0, or
	if any row or column index in Ti and/or Tj
	is not in the range 0 to n_row-1 or 0 to n_col-1, respectively.

Arguments:

    Int n_row ;		Input argument, not modified.
    Int n_col ;		Input argument, not modified.

	A is an n_row-by-n_col matrix.

    Int nz ;		Input argument, not modified.

	The number of entries in the triplet form of the matrix.

    Int Ti [nz] ;	Input argument, not modified.
    Int Tj [nz] ;	Input argument, not modified.
    float Tx [nz] ;	Input argument, not modified.
			Size 2*nz for packed complex case.
    float Tz [nz] ;	Input argument, not modified, for complex versions.

	Ti, Tj, Tx (and Tz for complex versions) hold the "triplet" form of a
	sparse matrix.  The kth nonzero entry is in row i = Ti [k], column
	j = Tj [k], the real numerical value of a_ij is Tx [k], and the
	imaginary part of a_ij is Tz [k] (for complex versions).  The row and
	column indices i and j must be in the range 0 to n_row-1 or 0 to
	n_col-1, respectively.  Duplicate entries may be present.  The
	"triplets" may be in any order.  Tx and Tz are optional; if Tx is
	not present ((float *) NULL), then the numerical values are
	not printed.

	If Tx is present and Tz is NULL, then both real
	and imaginary parts are contained in Tx[0..2*nz-1], with Tx[2*k]
	and Tx[2*k+1] being the real and imaginary part of the kth entry.

    float Control [UMFPACK_CONTROL] ;	Input argument, not modified.

	If a (float *) NULL pointer is passed, then the default control
	settings are used.  Otherwise, the settings are determined from the
	Control array.  See umfpack_*_defaults on how to fill the Control
	array with the default settings.  If Control contains NaN's, the
	defaults are used.  The following Control parameters are used:

	Control [UMFPACK_PRL]:  printing level.

	    2 or less: no output.  returns silently without checking anything.
	    3: fully check input, and print a short summary of its status
	    4: as 3, but print first few entries of the input
	    5: as 3, but print all of the input
	    Default: 1
*/
