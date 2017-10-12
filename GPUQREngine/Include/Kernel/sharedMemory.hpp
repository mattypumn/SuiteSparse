// =============================================================================
// === GPUQREngine/Include/Kernel/sharedMemory.cu ==============================
// =============================================================================

#ifndef GPUQRENGINE_SHAREDMEMORY_HPP
#define GPUQRENGINE_SHAREDMEMORY_HPP

typedef union sharedMemory
{
    struct
    {
        #define MAX_MCHUNK 12

        // shared memory for factorize kernel (tile case)
        // size of A must match size of V in apply, below.
        float A [PANELSIZE * TILESIZE + 1][TILESIZE + PADDING] ;
        float T [TILESIZE + 1][TILESIZE + PADDING] ;
        float Z [MAX_MCHUNK][TILESIZE+1] ;
        float A1 [TILESIZE] ;
        float V1 [TILESIZE] ;
        float tau ;

        #undef MAX_MCHUNK
    } factorize ;

    struct
    {
        #define MAX_COL_TILES 2

        // shared memory for block_apply kernels
        // size of V must match size of A in factorize, above.
        float V [PANELSIZE * TILESIZE + 1][TILESIZE + PADDING] ;
        float C [TILESIZE][MAX_COL_TILES * TILESIZE + PADDING] ;

        #undef MAX_COL_TILES
    } apply ;

    struct
    {
        int Rimap[PACKASSEMBLY_SHMEM_MAPINTS];
        int Rjmap[PACKASSEMBLY_SHMEM_MAPINTS];
    } packassemble ;

} SharedMemory ;

/* Shared memory for all kernels is defined globally and allocated here. */
__shared__ SharedMemory shMemory;
__shared__ TaskDescriptor myTask;
__shared__ int IsApplyFactorize;

#endif
