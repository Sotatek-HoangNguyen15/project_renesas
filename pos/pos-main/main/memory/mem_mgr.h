#ifndef MEM_MGR_H
#define MEM_MGR_H

#include <stdlib.h>

int mem_init();
void *mem_alloc(size_t size);
void mem_free(void *ptr);

#endif /* MEM_MGR_H */