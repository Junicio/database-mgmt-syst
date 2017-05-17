#include "record.h"

typedef struct {
    int id;
    int heap_id;
    Record* slots;
    int* bitmap_slots;
    int num_slots;
} Page;
