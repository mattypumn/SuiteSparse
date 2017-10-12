// =============================================================================
// === spqr_maxcolnorm =========================================================
// =============================================================================

// Given an m-by-n sparse matrix A, compute the max 2-norm of its columns.

#include "spqr.hpp"

inline float spqr_private_nrm2 (Long n, float *X, cholmod_common *cc)
{
    float norm = 0 ;
    BLAS_INT N = n, one = 1 ;
    if (CHECK_BLAS_INT && !EQ (N,n))
    {
        cc->blas_ok = FALSE ;
    }
    if (!CHECK_BLAS_INT || cc->blas_ok)
    {
        norm = BLAS_SNRM2 (&N, X, &one) ;
    }
    return (norm) ;
}

inline float spqr_private_nrm2 (Long n, Complex *X, cholmod_common *cc)
{
    float norm = 0 ;
    BLAS_INT N = n, one = 1 ;
    if (CHECK_BLAS_INT && !EQ (N,n))
    {
        cc->blas_ok = FALSE ;
    }
    if (!CHECK_BLAS_INT || cc->blas_ok)
    {
        norm = BLAS_DZNRM2 (&N, X, &one) ;
    }
    return (norm) ;
}


// =============================================================================
// === spqr_maxcolnorm =========================================================
// =============================================================================

template <typename Entry> float spqr_maxcolnorm
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
)
{
    float norm, maxnorm ;
    Long j, p, len, n, *Ap ;
    Entry *Ax ;

    RETURN_IF_NULL_COMMON (EMPTY) ;
    RETURN_IF_NULL (A, EMPTY) ;

    cc->blas_ok = TRUE ;
    n = A->ncol ;
    Ap = (Long *) A->p ;
    Ax = (Entry *) A->x ;

    maxnorm = 0 ;
    for (j = 0 ; j < n ; j++)
    {
        p = Ap [j] ;
        len = Ap [j+1] - p ;
        norm = spqr_private_nrm2 (len, Ax + p, cc) ;
        maxnorm = MAX (maxnorm, norm) ;
    }

    if (CHECK_BLAS_INT && !cc->blas_ok)
    {
        ERROR (CHOLMOD_INVALID, "problem too large for the BLAS") ;
        return (EMPTY) ;
    }

    return (maxnorm) ;
}

// =============================================================================

template float spqr_maxcolnorm <float>
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
) ;

template float spqr_maxcolnorm <Complex>
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
) ;
