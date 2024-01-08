#include "mem_mgr.h"

int mem_init()
{
  return 0;
}

void *mem_alloc(size_t size)
{
  return malloc(size);
}

void mem_free(void *ptr)
{
  free(ptr);
}