#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRA 50

void escolherPalavra(char *palavraAleatoria)  {
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Leitura das palavras e armazenamento em um vetor
    char palavras[100][50]; // Suponha que haja no máximo 100 palavras de até 49 caracteres cada.
    int numPalavras = 0;

    while (fgets(palavras[numPalavras], sizeof(palavras[0]), arquivo) != NULL) {
        // Remova o caractere de nova linha se estiver presente
        char *pos = strchr(palavras[numPalavras], '\n'); //strchr para buscar a primeira ocorrência do caractere de nova linha ('\n') na string
        if (pos != NULL) {
            *pos = '\0';
        }
        numPalavras++;
    }

    // Gerar um número aleatório
    srand(time(NULL));
    int indiceAleatorio = rand() % numPalavras;

    // Escolher a palavra aleatória
    strcpy(palavraAleatoria, palavras[indiceAleatorio]);

    fclose(arquivo);
}
