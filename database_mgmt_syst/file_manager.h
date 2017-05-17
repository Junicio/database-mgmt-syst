#include <stdio.h>

int last_page;

typedef struct {
    int page id;
    int disk_block;             // Qual bloco do disco a página se encontra
    int free_space;             // Quantidade de espaço livre que a página contém
    Directory_pages* next;      // Próxima página do diretório de página
} Directory_pages;

// Nome do Heap file e seu primeiro endereço
typedef struct {
    int heap_id;                    // Id do HeapFile (Tabela)
    Directory_pages* header_page;   // Endereço da primeira página no diretório
    Heap_dictionary* next;          // Próxima informações de outra tabela
} Heap_dictionary;


// Carrega informações do file manager
int fm_load(void);


// Aloca campos na tabela para nova página e inicializa valores e gera page id
int cr8_heapfile();


// retorna o id da página com espaço livre ou avisa que nao existe. Além de atualizar free_space etc
int free_page(int heap_id);


// Pede para o dsm alocar espaço e retorna o id para a função freepage() gera os id's das paginas
int cr8_page(void);


// Retrona o endereço da página buscada
int fetch_page(int page_id);
