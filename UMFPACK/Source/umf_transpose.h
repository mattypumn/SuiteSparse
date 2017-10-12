/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

GLOBAL Int UMF_transpose
(
    Int n_row,
    Int n_col,
    const Int Ap [ ],
    const Int Ai [ ],
    const float Ax [ ],
    const Int P [ ],
    const Int Q [ ],
    Int nq,
    Int Rp [ ],
    Int Ri [ ],
    float Rx [ ],
    Int W [ ],
    Int check
#ifdef COMPLEX
    , const float Az [ ]
    , float Rz [ ]
    , Int do_conjugate
#endif
) ;
