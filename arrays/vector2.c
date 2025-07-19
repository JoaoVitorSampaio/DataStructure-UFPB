/*
Função que conta todas as vogais de um vetor de caracteres local à "main".
Atribuindo uma string no código para realizar a contagem de vogais por completo.
*/

#include <stdio.h>

void main() {
    char str[] = "Estrutura de Dados - UFPB"; // String (vetor de caracteres)
    char v[] = "AaEeIiOoUu"; // Vetor de vogais
    int count = 0; // Contador de vogais inicializado com 0

    // Laço de repetição para percorrer até o primeiro '\0' da string lida
    for (int i=0; str[i]!='\0'; i++) {
        for (int j=0; v[j]!='\0'; j++) {
            // Verifica se o caractere é alguma vogal
            if (str[i] == v[j]) {
                count++; // Incrementa o contador de vogais
            }
        }
    }

    printf("Contador de vogais de '%s': %d\n", str, count);
}