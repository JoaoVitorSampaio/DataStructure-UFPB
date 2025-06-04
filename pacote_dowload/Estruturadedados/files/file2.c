
/*
Mostrar o nome das pessoas maiores de 18 anos.
*/

#include <stdio.h>

void main() {
    FILE *f; // Ponteiro do arquivo
    char name[12]; // Nome
    int age; // Idade
    int count = 0; // Contador de pessoas acima de 18 anos

    f = fopen("people.txt", "r"); // Tenta abrir o arquivo para escrita
    
    // Verificação da variável após pedido
    if (f == NULL) {
        printf("\n\tErro ao abrir arquivo.");
        return;
    }

    printf("Pessoas com mais de 18 anos:\n");

    // Ler o arquivo linha a linha
    while ((fscanf(f, "%s", name) == 1) && (fscanf(f, "%d", &age) == 1)) {
        // Verifica a idade das pessoas registradas
        if (age > 18) {
            count++; // Incrementa o contador de maiores
            printf("Maior de idade %d: %s (%d anos)\n", count, name, age); // Mostra o nome da pessoa adulta
        }
    }
        
    // Verifica se não há ninguém maior de idade
    if (count == 0) {
        printf("Nenhuma pessoa com mais de 18 anos encontrada.\n");
    }

    fclose(f); // Fecha o arquivo
}
