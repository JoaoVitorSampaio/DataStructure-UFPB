#include <stdio.h>

int main() {
    unsigned char ascii; // Garantir valores de 0 a 255

    // Cabeçalho da tabela
    printf("%-10s %-10s\n", "Codigo", "Caractere");
    printf("----------------------\n");

    // Loop para gerar a tabela ASCII
    for (ascii = 32; ascii <= 126; ascii++) { // Inicialização corrigida
        printf("%-10d %-10c\n", ascii, ascii);
    }
    return 0;
}
