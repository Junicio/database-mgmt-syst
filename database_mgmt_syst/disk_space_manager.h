#include <stdio.h>

#define disk_size 100

typedef struct {
    int is_free;
    int page_id;
} Blocks_info;


typedef struct {
    Blocks_info* blocks_info;
} Disck_space_manager;
