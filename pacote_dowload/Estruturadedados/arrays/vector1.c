/*
Função que conta todas as vogais de um vetor de caracteres local à "main".
Solicitando a entrada do usuário.
*/
#include <stdio.h>

#define MAX_SIZE 101 // Constante para tamanho máximo da string

void main() {
    char str[MAX_SIZE]; // String (vetor de caracteres) 
    char v[] = "AaEeIiOoUu"; // Vetor de vogais
    int count = 0; // Contador de vogais inicializado com 0

    printf("Digite uma expressao de ate %d caracteres: ", MAX_SIZE-1); // Solicita entrada do usuário
    scanf("%s", str); // Leitura da entrada

    // Laço de repetição para percorrer até o primeiro '\0' da string lida
    // Ou seja, percorre até a primeira "palavra"
    for (int i=0; str[i]!='\0'; i++) {
        for (int j=0; v[j]!='\0'; j++) {
            // Verifica se o caractere é alguma vogal
            if (str[i] == v[j]) {
                count++; // Incrementa o contador de vogais
            }
        }
    }

    printf("Contador de vogais de -%s-: %d\n", str, count);
}