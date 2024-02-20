#include <stdio.h>

/**
 * conta os espacos em branco presentes no array char
 * @param s string
 * @return a soma dos espacos em branco presentes no array
 */
int contaEspacosEmBranco(char *s)
{
    int sum=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        if(s[i] == ' ') //espaco em branco
        {
            sum++;
        }
    }

    return sum;
}

int main() {
    printf("START\n\n");

    printf("soma dos espacos em branco: %d \n", contaEspacosEmBranco("hello world"));

    printf("\nEND\n\n");
    return 0;
}