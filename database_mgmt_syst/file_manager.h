#include <stdio.h>



typedef struct {
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


// Dicionário no catálogo
