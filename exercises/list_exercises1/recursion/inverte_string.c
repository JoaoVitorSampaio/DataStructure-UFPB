/* 1) Inverter String
Escreva uma função recursiva que receba uma string e retorne a string invertida.
Exemplo: inverter("recursao") → "oasrucer".*/

void inverte_string(char *str, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    char temp = str[inicio];
    str[inicio] = str[fim]; //troca os caracteres do inicio e do fim
    str[fim] = temp;
    inverte_string(str, inicio + 1, fim - 1); //chamada recursiva
  }