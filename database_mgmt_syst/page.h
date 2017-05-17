#include "record.h"

typedef struct {
    int id;
    int heap_id;
    Record* slots;
    int* bitmap_slots;
    int num_slots;
} Page;

// Insere registro na página e atualiza bitmap
int inst_record(Record record);


// Remove registro na página e atualiza bitmap
int remove_record(int num_slot);

