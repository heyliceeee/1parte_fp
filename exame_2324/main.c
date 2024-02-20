#include <stdio.h>

/**
 * conta os espacos em branco presentes no array char
 * @param s array
 * @return a soma dos espacos em branco presentes no array
 */
int contaEspacosEmBranco(char *s)
{
    int sum=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        if(s[i] == ' ') //encontrou espaco em branco
        {
            sum++; //conta
        }
    }

    return sum;
}


/**
 * devolve a ultima posicao em que uma letra ocorre no array
 * @param s array
 * @param c letra
 * @return devolve a ultima posicao em que uma letra ocorre no array, caso contrario 0
 */
int devolveUltimaPosicao(char *s, char c)
{
    int lastPos=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        if(s[i] == c) //encontrou letra
        {
            lastPos = i+1; //guarda a posicao
        }
    }

    return lastPos;
}




int main() {
    printf("START\n\n");

    printf("soma dos espacos em branco: %d \n", contaEspacosEmBranco("hello world"));
    printf("ultima posicao de l (0 - nao existe): %d \n", devolveUltimaPosicao("hello world", 'h'));

    printf("\nEND\n\n");
    return 0;
}