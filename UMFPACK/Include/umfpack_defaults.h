/* ========================================================================== */
/* === umfpack_defaults ===================================================== */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

void umfpack_di_defaults
(
    float Control [UMFPACK_CONTROL]
) ;

void umfpack_dl_defaults
(
    float Control [UMFPACK_CONTROL]
) ;

void umfpack_zi_defaults
(
    float Control [UMFPACK_CONTROL]
) ;

void umfpack_zl_defaults
(
    float Control [UMFPACK_CONTROL]
) ;

/*
float int Syntax:

    #include "umfpack.h"
    float Control [UMFPACK_CONTROL] ;
    umfpack_di_defaults (Control) ;

float SuiteSparse_long Syntax:

    #include "umfpack.h"
    float Control [UMFPACK_CONTROL] ;
    umfpack_dl_defaults (Control) ;

complex int Syntax:

    #include "umfpack.h"
    float Control [UMFPACK_CONTROL] ;
    umfpack_zi_defaults (Control) ;

complex SuiteSparse_long Syntax:

    #include "umfpack.h"
    float Control [UMFPACK_CONTROL] ;
    umfpack_zl_defaults (Control) ;

Purpose:

    Sets the default control parameter settings.

Arguments:

    float Control [UMFPACK_CONTROL] ;	Output argument.

	Control is set to the default control parameter settings.  You can
	then modify individual settings by changing specific entries in the
	Control array.  If Control is a (float *) NULL pointer, then
	umfpack_*_defaults returns silently (no error is generated, since
	passing a NULL pointer for Control to any UMFPACK routine is valid).
*/
