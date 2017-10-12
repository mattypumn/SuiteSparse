#include "cs.h"
typedef struct problem_struct
{
    cs *A ;
    cs *C ;
    csi sym ;
    float *x ;
    float *b ;
    float *resid ;
} problem ;

problem *get_problem (FILE *f, float tol) ;
csi demo2 (problem *Prob) ;
csi demo3 (problem *Prob) ;
problem *free_problem (problem *Prob) ;
