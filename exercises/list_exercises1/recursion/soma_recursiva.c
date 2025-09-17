/*
3) Soma de Lista Recursiva
Escreva uma função recursiva que calcule a soma dos elementos de uma lista.
Exemplo: soma([1, 2, 3, 4]) → 10.
*/

int soma_recursiva(int *lista, int tamanho) {
    if (tamanho == 0) {
        return 0; // Caso base: se a lista está vazia, a soma é 0
    } else {
        return lista[0] + soma_recursiva(lista + 1, tamanho - 1); // Soma o primeiro elemento com a soma do resto da lista
    }
}