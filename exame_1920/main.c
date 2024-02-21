#include <stdio.h>

#define MAX_IMAGEM 35
#define MAX_PARTE 5
#define MAX_IMAGEM_EX2 6


/**
 * verifica se existe a matriz parte dentro da imagem
 * @param imagem
 * @param parte
 * @return 1 se existe, caso contrario 0
 */
int existe(int imagem[MAX_IMAGEM][MAX_IMAGEM], int parte[MAX_PARTE][MAX_PARTE])
{
    //verifica cada ponto de partida possível em 'imagem'
    for(int i=0; i <= MAX_IMAGEM-MAX_PARTE; i++) //percorrer linhas em comum
    {
        for(int j=0; j <= MAX_IMAGEM-MAX_PARTE; j++) //percorrer colunas em comum
        {
            int match = 1; //supoe-se que a 'parte' existe na 'imagem' neste ponto de partida

            //verifica se 'parte' corresponde a 'imagem' na posição atual (i, j)
            for(int k=0; k < MAX_PARTE; k++) //percorrer linhas parte
            {
                for(int l=0; l < MAX_PARTE; l++) //percorrer colunas parte
                {
                    if (imagem[i+k][j+l] != parte[k][l])  //elementos de ambos nao corresponder
                    {
                        match = 0;
                        break;
                    }
                }

                if (!match) //se ja sabemos que 'parte' não está nesta posicao, nao precisamos verificar mais
                {
                    break;
                }
            }

            if (match) //se apos verificar todos os elementos de 'parte', ainda acreditamos que ha um 'match', retornamos 1
            {
                return 1;
            }
        }
    }

    return 0;
}


/**
 * mostra para cada cor, a quatidade de pixeis que têm essa cor
 * @param imagemEx2
 */
void conta_cores(int imagemEx2[MAX_IMAGEM_EX2][MAX_IMAGEM_EX2])
{
    int quantidadeCores[256] = {0}, existe=0;

    for(int i=0; i < MAX_IMAGEM_EX2; i++) //percorrer linhas
    {
        for(int j=0; j < MAX_IMAGEM_EX2; j++) //percorrer colunas
        {
            quantidadeCores[imagemEx2[i][j]]++;
        }
    }


    //mostrar matriz quantidadeCores
    for (int i = 0; i < 256; i++)
    {
        if (quantidadeCores[i] > 0)
        {
            printf("Cor %d: %d pixel(s)\n", i, quantidadeCores[i]);
        }
    }
}


/**
 * inverte a matriz
 * @param imagemEx2
 */
void inverte(int imagemEx2[MAX_IMAGEM_EX2][MAX_IMAGEM_EX2])
{
    for(int i=0; i < MAX_IMAGEM_EX2; i++) //percorrer linhas
    {
        for(int j=0; j < MAX_IMAGEM_EX2; j++) //percorrer colunas
        {
            printf("%d ", 255 - imagemEx2[i][j]);
        }
        printf("\n");
    }
}


/**
 * altera a intensidade da cor da imagem
 * @param imagemEx2
 * @param valorPercentual positivo (aumentar intensidade) ou negativo (reduzir intensidade)
 */
void altera(int imagemEx2[MAX_IMAGEM_EX2][MAX_IMAGEM_EX2], float valorPercentual)
{
    //valor da intensidade
    do
    {
        printf("introduza um valor: (-1.0 - 1.0) ");
        scanf("%f", &valorPercentual);
    } while (valorPercentual < -1.0 || valorPercentual > 1.0);


    printf("ANTES: \n");

    for(int i=0; i < MAX_IMAGEM_EX2; i++) //percorrer linhas
    {
        for(int j=0; j < MAX_IMAGEM_EX2; j++) //percorrer colunas
        {
            printf("%d ", imagemEx2[i][j]);
        }
        printf("\n");
    }

    printf("\nDEPOIS: \n");

    for(int i=0; i < MAX_IMAGEM_EX2; i++) //percorrer linhas
    {
        for(int j=0; j < MAX_IMAGEM_EX2; j++) //percorrer colunas
        {
            int novoValor;

            if(valorPercentual == 1.0)
            {
                novoValor = 255;
            }
            else if(valorPercentual == -1.0)
            {
                novoValor = 0;
            }
            else
            {
                novoValor = imagemEx2[i][j] + (int)(255*valorPercentual);
            }

            if(novoValor < 0)
            {
                novoValor = 0;
            }
            else if(novoValor > 255)
            {
                novoValor = 255;
            }

            printf("%d ", novoValor);
        }
        printf("\n");
    }
}




int main()
{
    //#region VARIAVEIS
    int imagem[MAX_IMAGEM][MAX_IMAGEM] = {
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1},
    };
    int parte[MAX_PARTE][MAX_PARTE] = {
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
    };

    int imagemEx2[MAX_IMAGEM_EX2][MAX_IMAGEM_EX2] = {
            {170, 238, 85, 255, 221, 0},
            {68, 136, 17, 170, 119, 68},
            {221, 0, 238, 136, 0, 255},
            {119, 255, 85, 170, 136, 238},
            {238, 17, 221, 68, 119, 255},
            {85, 170, 119, 221, 17, 136},
    };

    float valorPercentual = 2.0;
    //#endregion


    printf("START\n\n");


    printf("existe: %s", existe(imagem, parte) == 0 ? "nao\n\n" : "sim\n\n");

    conta_cores(imagemEx2);
    printf("\n");

    inverte(imagemEx2);
    printf("\n");


    altera(imagemEx2, valorPercentual);
    printf("\n");


    printf("\n\nEND\n");
    return 0;
}
