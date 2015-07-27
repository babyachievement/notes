#postgresql内存管理涉及到的核心数据结构


typedef struct MemoryContextData
{
    NodeTag     type;           /* identifies exact kind of context */
    MemoryContextMethods *methods;      /* virtual function table */
    MemoryContext parent;       /* NULL if no parent (toplevel context) */
    MemoryContext firstchild;   /* head of linked list of children */
    MemoryContext nextchild;    /* next child of same parent */
    char       *name;           /* context name (just for debugging) */
    bool        isReset;        /* T = no space alloced since last reset */
} MemoryContextData;


typedef struct AllocSetContext
{
    MemoryContextData header;   /* Standard memory-context fields */
    /* Info about storage allocated in this context: */
    AllocBlock  blocks;         /* head of list of blocks in this set */
    AllocChunk  freelist[ALLOCSET_NUM_FREELISTS];       /* free chunk lists */
    /* Allocation parameters for this context: */
    Size        initBlockSize;  /* initial block size */
    Size        maxBlockSize;   /* maximum block size */
    Size        nextBlockSize;  /* next block size to allocate */
    Size        allocChunkLimit;    /* effective chunk size limit */
    AllocBlock  keeper;         /* if not NULL, keep this block over resets */
} AllocSetContext;


typedef struct AllocBlockData
{
    AllocSet    aset;           /* aset that owns this block */
    AllocBlock  next;           /* next block in aset's blocks list */
    char       *freeptr;        /* start of free space in this block */
    char       *endptr;         /* end of space in this block */
}   AllocBlockData;


typedef struct AllocChunkData
{
    /* aset is the owning aset if allocated, or the freelist link if free */
    void       *aset;
    /* size is always the size of the usable space in the chunk */
    Size        size;
#ifdef MEMORY_CONTEXT_CHECKING
    /* when debugging memory usage, also store actual requested size */
    /* this is zero in a free chunk */
    Size        requested_size;
#endif
}   AllocChunkData;




