/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

GLOBAL Int UMF_solve
(
    Int sys,
    const Int Ap [ ],
    const Int Ai [ ],
    const float Ax [ ],
    float Xx [ ],
    const float Bx [ ],
#ifdef COMPLEX
    const float Az [ ],
    float Xz [ ],
    const float Bz [ ],
#endif
    NumericType *Numeric,
    Int irstep,
    float Info [UMFPACK_INFO],
    Int Pattern [ ],
    float SolveWork [ ]
) ;
