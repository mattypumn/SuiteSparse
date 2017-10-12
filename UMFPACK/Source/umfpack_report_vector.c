/* ========================================================================== */
/* === UMFPACK_report_vector ================================================ */
/* ========================================================================== */

/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

/*
    User-callable.  Prints a real or complex vector.
    See umfpack_report_vector.h for details.
*/

#include "umf_internal.h"
#include "umf_report_vector.h"

GLOBAL Int UMFPACK_report_vector
(
    Int n,
    const float Xx [ ],
#ifdef COMPLEX
    const float Xz [ ],
#endif
    const float Control [UMFPACK_CONTROL]
)
{
    Int prl ;

#ifndef COMPLEX
    float *Xz = (float *) NULL ;
#endif

    prl = GET_CONTROL (UMFPACK_PRL, UMFPACK_DEFAULT_PRL) ;

    if (prl <= 2)
    {
	return (UMFPACK_OK) ;
    }

    return (UMF_report_vector (n, Xx, Xz, prl, TRUE, FALSE)) ;
}
