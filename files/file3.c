/*
Ordenar os nomes (com idades respectivas).
Salvar em novo arquivo.
*/

#include <stdio.h>
#include <string.h>

#define NAME_SIZE 12 // Constante para tamanho do primeiro nome
#define MAX_COUNT 101 // Constante para quantidade máxima de pessoas

void sort_names(char names[][NAME_SIZE], int ages[], int count) {
    char temp_name[NAME_SIZE];
    int temp_age;

    // Ordenação simples por Bubble Sort
    for (int i=0; i<count-1; i++) {
        for (int j=i+1; j<count; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                // Trocar nomes
                strcpy(temp_name, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp_name);

                // Trocar idades correspondentes
                temp_age = ages[i];
                ages[i] = ages[j];
                ages[j] = temp_age;
            }
        }
    }
}

void main() {
    FILE *input, *output; // Ponteiro do arquivo
    char name[MAX_COUNT][NAME_SIZE]; // Array para armazenar até 100 nomes
    int age[MAX_COUNT]; // Array para armazenar até 100 idades
    int count = 0; // Contador de pessoas

    input = fopen("people.txt", "r"); // Tenta abrir o arquivo de entrada para leitura

    // Verificação da variável após pedido
    if (input == NULL) {
        printf("\n\tErro ao abrir arquivo.");
        return;
    }

    // Ler o arquivo linha a linha
    while ((fscanf(input, "%s", name[count]) == 1) && (fscanf(input, "%d", &age[count]) == 1)) {
        count++; // Incrementa o contador de pessoas
    }

    fclose(input); // Fecha o arquivo de entrada

    sort_names(name, age, count); // Ordenar os nomes

    output = fopen("sorted_people.txt", "w"); // Abrir um novo arquivo para salvar os dados ordenados

    // Verificação da variável após pedido
    if (output == NULL) {
        printf("\n\tErro ao abrir arquivo.");
        return;
    }

    for (int i=0; i<count; i++) {
        fprintf(output, "%s\n%d\n", name[i], age[i]); // Escrita dos dados ordenados no novo arquivo
        printf("%s (%d anos)\n", name[i], age[i]); // Mostra os nomes ordenados
    }

    fclose(output); // Fecha o arquivo de saída
}
