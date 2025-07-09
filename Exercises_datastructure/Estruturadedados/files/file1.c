/*
Ler primeiro nome e idade de n pessoas.
Guardar dados em um arquivo texto.
*/

#include <stdio.h>

void main() {
    FILE *f; // Ponteiro do arquivo
    char name[12]; // Nome
    int age; // Idade
    int n; // Número de pessoas

    f = fopen("people.txt", "w"); // Tenta abrir o arquivo para escrita
    
    // Verificação da variável após pedido
    if (f == NULL) {
        printf("\n\tErro ao abrir arquivo.");
        return;
    }

    // Solicitação do número de pessoas
    printf("Quantas pessoas deseja registrar? ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        // Leitura e gravação de nome lido
        printf("Nome da pessoa %d: ", i+1); 
        scanf("%s", &name);
        fprintf(f, "%s\n", name);

        // Leitura e gravação da idade lida
        printf("Idade da pessoa %d: ", i+1);
        scanf("%d", &age);
        fprintf(f, "%d\n", age);
    }  

    printf("\nDados gravados com sucesso no arquivo 'people.txt'.\n");

    fclose(f); // Fecha o arquivo
}