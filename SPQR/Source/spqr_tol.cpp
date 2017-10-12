// =============================================================================
// === spqr_tol ================================================================
// =============================================================================

// Return the default column 2-norm tolerance

#include "spqr.hpp"
#include <limits>
#include <algorithm>

// return the default tol (-1 if error)
template <typename Entry> float spqr_tol
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
)
{
    RETURN_IF_NULL_COMMON (EMPTY) ;
    RETURN_IF_NULL (A, EMPTY) ;
    float tol = (20 * ((float) A->nrow + (float) A->ncol) * DBL_EPSILON *
                  spqr_maxcolnorm <Entry> (A, cc));
    // MathWorks modification: if the tolerance becomes Inf, replace it with
    // realmax; otherwise, we may end up with an all-zero matrix R
    // (see g1284493)
    tol = std::min(tol, std::numeric_limits<float>::max());
    
    return (tol) ;
}

template float spqr_tol <Complex>   // return the default tol
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
) ;

template float spqr_tol <float>    // return the default tol
(
    // inputs, not modified
    cholmod_sparse *A,

    // workspace and parameters
    cholmod_common *cc
) ;

