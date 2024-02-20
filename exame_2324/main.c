#include <stdio.h>
#define LINHAS 5
#define COLUNAS 5

/**
 * conta os espacos em branco presentes no array char
 * @param s array
 * @return a soma dos espacos em branco presentes no array
 */
int contaEspacosEmBranco(char *s)
{
    int soma=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        if(s[i] == ' ') //encontrou espaco em branco
        {
            soma++; //conta
        }
    }

    return soma;
}


/**
 * devolve a ultima posicao em que uma letra ocorre no array
 * @param s array
 * @param c letra
 * @return devolve a ultima posicao em que uma letra ocorre no array, caso contrario 0
 */
int devolveUltimaPosicao(char *s, char c)
{
    int ultimaPos=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        if(s[i] == c) //encontrou letra
        {
            ultimaPos = i+1; //guarda a posicao
        }
    }

    return ultimaPos;
}


/**
 * devolve 0/1 consoante o array de inteiros tiver ordenado
 * @param array de inteiros
 * @param tam tamanho do array
 * @return 1 caso o array esteja ordenado por ordem crescente, caso contrario 0
 */
int ordenado(int *array, int tam)
{
    for(int i=0; i < tam-1; i++)
    {
        if(array[i] > array[i+1])
        {
            return 0;
        }
    }

    return 1;
}


/**
 * soma elementos da diagonal e acima da mesma
 * @param matrix
 * @return soma todos os elementos localizados na diagonal e acima da mesma
 */
int somaMatrizDiagonalSuperior(int matrix[LINHAS][COLUNAS])
{
    int soma=0;

    for(int i=0; i < LINHAS; i++) //percorrer linhas
    {
        for(int j=i; j < COLUNAS; j++) //percorrer colunas
        {
            soma += matrix[i][j];
        }
    }

    return soma;
}


/**
 * devolve total elementos pares da matriz
 * @param matrix
 * @return total elementos pares
 */
int totalParesMatriz(int matrix[LINHAS][COLUNAS])
{
    int soma=0;

    for(int i=0; i < LINHAS; i++) //percorrer linhas
    {
        for(int j=i; j < COLUNAS; j++) //percorrer colunas
        {
            if(matrix[i][j] % 2 == 0) //elemento par
            {
                soma++;
            }
        }
    }

    return soma;
}


/**
 * inverter palavra
 * @param s
 */
void invertePalavra(char *s)
{
    int tam=0;

    for(int i=0; s[i] != '\0'; i++) //percorrer o array
    {
        tam++;
    }

    for(int i=0; i < tam/2; i++)
    {
        char temp = s[i]; //temp = letra atual

        s[i] = s[tam - i - 1]; //letra atual = ultimo slot vazio
        s[tam - i - 1] = temp; //ultimo slot vazio = temp (letra atual)
    }
}



int main() {
    int array[] = {2, 3, 1, 6, 4};
    int matrix[5][5] = {10, -5, 1, 100, 0,
                        300, 12, -53, 2, 13,
                        -25, -8, 16, 45, 123,
                        13, 67, -3, -98, 9,
                        29, 1, 90, 78, 4};
    char palavra[] = "fundamentos";

    
    printf("START\n\n");


    printf("soma dos espacos em branco: %d \n", contaEspacosEmBranco("hello world"));
    printf("ultima posicao de l (0 - nao existe): %d \n", devolveUltimaPosicao("hello world", 'h'));
    printf("array esta ordenado? %d \n", ordenado(array, 5));
    printf("soma dos elementos da diagonal e acima da mesma: %d \n", somaMatrizDiagonalSuperior(matrix));
    printf("total elementos pares: %d \n", totalParesMatriz(matrix));

    invertePalavra(palavra);
    printf("Palavra invertida: %s\n", palavra);


    printf("\n\nEND\n\n");
    return 0;
}