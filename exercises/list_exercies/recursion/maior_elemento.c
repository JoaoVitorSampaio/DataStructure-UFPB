/* 2) Máximo em Lista
Crie uma função recursiva que receba uma lista de números e retorne o maior elemento.
Exemplo: maximo([3, 7, 2, 9, 1]) → 9.
*/
int maior_elemento(int *lista, int tamanho) {
    if (tamanho == 1) {
        return lista[0]; // Caso base: se a lista tem um elemento, retorna esse elemento
    } 

    int primeiro_elemento = lista[0];
    int maximo_resto = maior_elemento(lista + 1, tamanho -1); // Chamada recursiva para o resto da lista

    if (primeiro_elemento > maximo_resto) {
        return primeiro_elemento; // Retorna o maior entre o primeiro elemento e o máximo do resto
    } else {
        return maximo_resto;
    }
}