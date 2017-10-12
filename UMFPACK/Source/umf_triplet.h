/* -------------------------------------------------------------------------- */
/* Copyright (c) 2005-2012 by Timothy A. Davis, http://www.suitesparse.com.   */
/* All Rights Reserved.  See ../Doc/License.txt for License.                  */
/* -------------------------------------------------------------------------- */

GLOBAL Int UMF_triplet_map_x
(
    Int n_row,
    Int n_col,
    Int nz,
    const Int Ti [ ],
    const Int Tj [ ],
    Int Ap [ ],
    Int Ai [ ],
    Int Rp [ ],
    Int Rj [ ],
    Int W [ ],
    Int RowCount [ ]
    , const float Tx [ ]
    , float Ax [ ]
    , float Rx [ ]
#ifdef COMPLEX
    , const float Tz [ ]
    , float Az [ ]
    , float Rz [ ]
#endif
    , Int Map [ ]
    , Int Map2 [ ]
) ;

GLOBAL Int UMF_triplet_map_nox
(
    Int n_row,
    Int n_col,
    Int nz,
    const Int Ti [ ],
    const Int Tj [ ],
    Int Ap [ ],
    Int Ai [ ],
    Int Rp [ ],
    Int Rj [ ],
    Int W [ ],
    Int RowCount [ ]
    , Int Map [ ]
    , Int Map2 [ ]
) ;

GLOBAL Int UMF_triplet_nomap_x
(
    Int n_row,
    Int n_col,
    Int nz,
    const Int Ti [ ],
    const Int Tj [ ],
    Int Ap [ ],
    Int Ai [ ],
    Int Rp [ ],
    Int Rj [ ],
    Int W [ ],
    Int RowCount [ ]
    , const float Tx [ ]
    , float Ax [ ]
    , float Rx [ ]
#ifdef COMPLEX
    , const float Tz [ ]
    , float Az [ ]
    , float Rz [ ]
#endif
) ;

GLOBAL Int UMF_triplet_nomap_nox
(
    Int n_row,
    Int n_col,
    Int nz,
    const Int Ti [ ],
    const Int Tj [ ],
    Int Ap [ ],
    Int Ai [ ],
    Int Rp [ ],
    Int Rj [ ],
    Int W [ ],
    Int RowCount [ ]
) ;
