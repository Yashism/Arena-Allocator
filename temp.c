// The MIT License (MIT)
//
// Copyright (c) 2021, 2022 Trevor Bakker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES UTA OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

struct block
{
    size_t size;
    int free;
    struct block *next;
    struct block *prev;
    struct block *next_free;
    struct block *prev_free;
};

struct block *head = NULL;
struct block *tail = NULL;
struct block *current = NULL;
struct block *best = NULL;
struct block *worst = NULL;
struct block *first = NULL;

// Define first and last
struct block *first = NULL;
struct block *last = NULL;
struct bloack *next = NULL;

#include "mavalloc.h"

int mavalloc_init(size_t size, enum ALGORITHM algorithm)
{
    // Initialize memory arena
    size = ALIGN4(size);
    if (size <= 0)
    {
        return -1;
    }
    void *memory = malloc(size);
    if (memory == NULL)
    {
        return -1;
    }
    // Initialize the memory
    if (algorithm == FIRST_FIT)
    {
        // Initialize the first block
        struct block *first_block = (struct block *)memory;
        first_block->size = size - sizeof(struct block);
        first_block->free = 1;
        first_block->next = NULL;
        first_block->prev = NULL;
        // Set the global variables
        first = first_block;
        last = first_block;
        return 0;
    }
    else if (algorithm == NEXT_FIT)
    {
        // Initialize the first block
        struct block *first_block = (struct block *)memory;
        first_block->size = size - sizeof(struct block);
        first_block->free = 1;
        first_block->next = NULL;
        first_block->prev = NULL;
        // Set the global variables
        first = first_block;
        last = first_block;
        next = first_block;
        return 0;
    }
    else if (algorithm == BEST_FIT)
    {
        // Initialize the first block
        struct block *first_block = (struct block *)memory;
        first_block->size = size - sizeof(struct block);
        first_block->free = 1;
        first_block->next = NULL;
        first_block->prev = NULL;
        // Set the global variables
        first = first_block;
        last = first_block;
        return 0;
    }
    else if (algorithm == WORST_FIT)
    {
        // Initialize the first block
        struct block *first_block = (struct block *)memory;
        first_block->size = size - sizeof(struct block);
        first_block->free = 1;
        first_block->next = NULL;
        first_block->prev = NULL;
        // Set the global variables
        first = first_block;
        last = first_block;
        return 0;
    }
    // else if (algorithm == NEXT_FIT)
    // {
    //   return next_fit_init(memory, size);
    // }
    // else if (algorithm == BEST_FIT)
    // {
    //   return best_fit_init(memory, size);
    // }
    // else if (algorithm == WORST_FIT)
    // {
    //   return worst_fit_init(memory, size);
    // }
    else
    {
        return -1;
    }

    return 0;
}

void mavalloc_destroy()
{
    // Free the memory
    free(first);
    // Reset the global variables
    first = NULL;
    last = NULL;
    next = NULL;
    return;
}

void *mavalloc_alloc(size_t size)
{
    // only return NULL on failure
    return NULL;
}

void mavalloc_free(void *ptr)
{
    return;
}

int mavalloc_size()
{
    int number_of_nodes = 0;
    struct block *current = first;
    while (current != NULL)
    {
        number_of_nodes++;
        current = current->next;
    }

    return number_of_nodes;
}
