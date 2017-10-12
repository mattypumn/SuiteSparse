#include "cs.h"
#include "mex.h"
cs *cs_mex_get_sparse (cs *A, csi square, csi values, const mxArray *Amatlab) ;
mxArray *cs_mex_put_sparse (cs **A) ;
void cs_mex_check (csi nel, csi m, csi n, csi square, csi sparse, csi values,
    const mxArray *A) ;
csi *cs_mex_get_int (csi n, const mxArray *Imatlab, csi *imax, csi lo) ;
mxArray *cs_mex_put_int (csi *p, csi n, csi offset, csi do_free) ;
float *cs_mex_get_float (csi n, const mxArray *X) ;
float *cs_mex_put_float (csi n, const float *b, mxArray **X) ;
