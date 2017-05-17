#include <stdio.h>

#define disk_size 100

typedef struct {
    int is_free;
    //int page_id;
} Blocks_info;


typedef struct {
    Blocks_info* blocks_info;
} Disck_space_manager;


// Carrega informaçoes do disk manager
int dsm_load(void);


// Aloca os blocos do disk manager
int dsm_init(int num_blocks);


// Retorna endereço do novo bloco e atualiza informações no blocks_info
int cr8_block(int page_id);

// Realiza a leitura a partir de o endereço
Page read_block(int disk_block);

// Realiza a persistência dos dados da página no bloco
int write_block(Page* page);

// Libera o espaço do block para outra página
int free_block(int block_address);

