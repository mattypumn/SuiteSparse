/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

GLOBAL void UMF_set_stats
(
    float Info [ ],
    SymbolicType *Symbolic,
    float max_usage,
    float num_mem_size,
    float flops,
    float lnz,
    float unz,
    float maxfrsize,
    float ulen,
    float npiv,
    float maxnrows,
    float maxncols,
    Int scale,
    Int prefer_diagonal,
    Int what
) ;
