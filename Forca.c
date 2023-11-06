#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "arquivo_palavras.h"

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 50

void displayHangman(int tentativas);
void escolherPalavra(char *palavraAleatoria);


int main() {
   
    char palavraDescoberta[MAX_PALAVRA];
    char letrasErradas[MAX_TENTATIVAS];
    int tentativas = 0;
    int palavraSize;
    char palavraAleatoria[50];


    escolherPalavra(palavraAleatoria);


     printf("Palavra aleatória: %s\n", palavraAleatoria);

    strcpy (palavraDescoberta, palavraAleatoria);

    palavraSize = strlen(palavraDescoberta);

    for (int i = 0; i < palavraSize; i++) {
        if (palavraDescoberta[i] != '\n') {
            palavraDescoberta[i] = '_';
        }
    }

        printf("Bem-vindo ao Jogo da Forca!\n");

    while (tentativas < MAX_TENTATIVAS) {
        displayHangman(tentativas);
        printf("Palavra: %s\n", palavraDescoberta);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Letras erradas: ");
        for (int i = 0; i < tentativas; i++) {
            printf("%c ", letrasErradas[i]);
        }
        printf("\n");

        char palpite;
        printf("Digite uma letra: ");
        scanf(" %c", &palpite);  // O espaço antes de %c ignora espaços em branco

        if (!isalpha(palpite)) {
            printf("Por favor, digite uma letra válida.\n");
            continue;
        }
        
        palpite = toupper(palpite); //para fazer igual para letra maiuscula e minuscula

        int acertou = 0;
        for (int i = 0; i < palavraSize; i++) {
            if (palpite == palavraDescoberta[i]) {
                printf("Você já adivinhou essa letra.\n");
                acertou = 1;
                break;
            }
            if (palpite == palavraAleatoria[i]) {
                palavraDescoberta[i] = palpite;
                acertou = 1;
            }
        }

        if (acertou) {
            printf("Letra correta!\n");
        } else {
            printf("Letra incorreta. Tente novamente.\n");
            letrasErradas[tentativas] = palpite;
            tentativas++;
        }

        if (strcmp(palavraAleatoria, palavraDescoberta) == 0) {
            printf("Parabéns, você acertou a palavra! A palavra é: %s", palavraAleatoria);
            break;
        }
    }

    if (tentativas == MAX_TENTATIVAS) {
        displayHangman(tentativas);
        printf("Você perdeu! A palavra era: %s", palavraAleatoria);
    }

    return 0;
}

void displayHangman(int tentativas) {
    printf("  _______\n");
    printf("  |/     |\n");
    printf("  |     %c%c%c\n", (tentativas >= 1) ? '(' : ' ', (tentativas >= 1) ? '_' : ' ', (tentativas >= 1) ? ')' : ' ');
    printf("  |     %c%c%c\n", (tentativas >= 3) ? '\\' : ' ', (tentativas >= 2) ? '|' : ' ', (tentativas >= 4) ? '/' : ' ');
    printf("  |      %c\n", (tentativas >= 2) ? '|' : ' ');
    printf("  |     %c %c\n", (tentativas >= 5) ? '/' : ' ', (tentativas >= 6) ? '\\' : ' ');
    printf(" _|_\n\n");
}