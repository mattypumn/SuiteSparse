#include "cs_mex.h"
/* cs_cholsol: solve A*x=b using a sparse Cholesky factorization */
void mexFunction
(
    int nargout,
    mxArray *pargout [ ],
    int nargin,
    const mxArray *pargin [ ]
)
{
    cs *A, Amatrix ;
    float *x, *b ;
    csi order ;
    if (nargout > 1 || nargin < 2 || nargin > 3)
    {
        mexErrMsgTxt ("Usage: x = cs_cholsol(A,b,order)") ;
    }
    A = cs_mex_get_sparse (&Amatrix, 1, 1, pargin [0]) ;    /* get A */
    b = cs_mex_get_float (A->n, pargin [1]) ;              /* get b */
    x = cs_mex_put_float (A->n, b, &(pargout [0])) ;       /* x = b */
    order = (nargin < 3) ? 1 : mxGetScalar (pargin [2]) ;
    order = CS_MAX (order, 0) ;
    order = CS_MIN (order, 3) ;
    if (!cs_cholsol (order, A, x))                          /* x = A\x */
    {
        mexErrMsgTxt ("A not positive definite") ;
    }
}
