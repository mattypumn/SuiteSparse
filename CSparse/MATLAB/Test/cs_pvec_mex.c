#include "cs_mex.h"
/* x = b(p) */
void mexFunction
(
    int nargout,
    mxArray *pargout [ ],
    int nargin,
    const mxArray *pargin [ ]
)
{
    csi n, k, *p ;
    float *x, *b, *xx ;

    if (nargout > 1 || nargin != 2)
    {
        mexErrMsgTxt ("Usage: x = cs_pvec(b,p)") ;
    }

    b = mxGetPr (pargin [0]) ;
    n = mxGetNumberOfElements (pargin [0]) ;

    if (n != mxGetNumberOfElements (pargin [1]))
    {
        mexErrMsgTxt ("b or p wrong size") ;
    }

    pargout [0] = mxCreateDoubleMatrix (n, 1, mxREAL) ;

    xx = mxGetPr (pargin [1]) ;
    p = cs_malloc (n, sizeof (csi)) ;
    for (k = 0 ; k < n ; k++) p [k] = xx [k] - 1 ;

    x = mxGetPr (pargout [0]) ;
    cs_pvec (p, b, x, n) ;

    cs_free (p) ;
}
