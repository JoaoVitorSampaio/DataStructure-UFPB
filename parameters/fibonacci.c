#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n == 0) {
        return 0; // 1º termo é 0
    }
    else if (n == 1) {
        return 1; // 2º termo é 1
    }

    unsigned long long n1 = 0, n2 = 1, aux;
    
    // A partir do 3º termo, realizará a soma dos 2 anteriores
    for (int i=2; i<=n; i++) {
        aux = n1 + n2; // Calcula o próximo número da sequência
        n1 = n2; // Atualiza o valor anterior
        n2 = aux; // Atualiza o valor atual
    }

    return n2; // Retorna o valor atual
}

int main() {
    int num;

    // Entrada do usuário
    printf("Digite a posicao do termo da sequencia de Fibonacci: ");
    scanf("%d", &num);

    // Calcula o valor da posição
    if (num < 0) {
        printf("ERRO! A posicao deve ser um numero inteiro positivo."); // ERRO para entrada inválida (posição negativa)
    }
    else {
        printf("Numero da posicao %d: %d\n", num, fibonacci(num));
    }
    
    return 0;
}