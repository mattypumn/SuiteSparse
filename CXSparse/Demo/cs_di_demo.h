#include "cs.h"
typedef struct problem_struct
{
    cs_di *A ;
    cs_di *C ;
    int sym ;
    float *x ;
    float *b ;
    float *resid ;
} problem ;

problem *get_problem (FILE *f, float tol) ;
int demo2 (problem *Prob) ;
int demo3 (problem *Prob) ;
problem *free_problem (problem *Prob) ;
