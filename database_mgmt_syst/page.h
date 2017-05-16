#include "record.h"




typedef struct {
    int id;
    Record* slots;
    int* bitmap_slots;
    int num_slots;
} Page;
