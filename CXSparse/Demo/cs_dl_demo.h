#include "cs.h"
typedef struct problem_struct
{
    cs_dl *A ;
    cs_dl *C ;
    cs_long_t sym ;
    float *x ;
    float *b ;
    float *resid ;
} problem ;

problem *get_problem (FILE *f, float tol) ;
cs_long_t demo2 (problem *Prob) ;
cs_long_t demo3 (problem *Prob) ;
problem *free_problem (problem *Prob) ;
