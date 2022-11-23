#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void eliminacao_gaussiana(int tam, float mat[tam][tam])
{
    int i, j, t = tam;
    float matriz[t][t];

    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++)
        {
            matriz[i][j] = mat[i][j];
        }
    }

    printf("\n\trealizando a eliminacao gaussiana: ");

    int aux, aux2, IM1, IM2, conta_p = 0, percorre;
    float div;

    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++)
        {
            if (i == j && matriz[i][j] == 0)
            {
                float mat2[t][t];
                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {
                        mat2[IM1][IM2] = matriz[IM1][IM2];
                    }
                }
                int lin;
                float VetLin1[t], VetLin2[t], tst;
                percorre = 0;
                do
                {
                    tst = matriz[percorre][j];
                    if (tst == 1 && tst != 0)
                    {
                        lin = percorre;
                    }
                    if (tst != 1 && tst != 0)
                    {
                        lin = percorre;
                    }
                    percorre++;
                } while (percorre < t);

                percorre = 0;
                do
                {
                    VetLin1[percorre] = matriz[lin][percorre];
                    VetLin2[percorre] = matriz[i][percorre];
                    matriz[i][percorre] = VetLin1[percorre];
                    matriz[lin][percorre] = VetLin2[percorre];
                    percorre++;
                } while (percorre < t);

                conta_p++;

                printf("\n\t-precione qualquer tecla-");
                getchar();
                printf("\n\n\tTROCA DE LINHAS \n\npasso %d\n\n ", conta_p);

                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {

                        printf(" %.1f ", mat2[IM1][IM2]);
                        if (IM2 == t - 1 && IM1 == i)
                        {
                            printf(" --- L%d <-> L%d ", i + 1, lin + 1);
                        }
                    }
                    printf("\n");
                }

                printf("\n\t|"
                       "\n\t|\n\n");

                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {

                        printf(" %.1f ", matriz[IM1][IM2]);
                    }
                    printf("\n");
                }
            }
            if (i == j && matriz[i][j] != 1 && matriz[i][j] != 0)
            {
                // diagonal = 1
                float mat2[t][t];
                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {
                        mat2[IM1][IM2] = matriz[IM1][IM2];
                    }
                }
                aux = 0;
                div = matriz[i][j];
                do
                {
                    matriz[i][aux] = matriz[i][aux] * (1 / div);
                    aux++;
                } while (aux < t);

                conta_p++;

                printf("\n\t-precione qualquer tecla-");
                getchar();
                printf("\n\n\tFAZER COM QUE A PRIMEIRA ENTRADA NAO NULA SEJA = 1 \n\npasso %d\n\n ", conta_p);

                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {

                        printf(" %.1f ", mat2[IM1][IM2]);
                        if (IM2 == t - 1 && IM1 == i)
                        {
                            printf("---L%d <- L%d * 1/%.1f", i + 1, i + 1, div);
                        }
                    }
                    printf("\n");
                }

                printf("\n\t|");
                printf("\n\t|\n\n");

                for (IM1 = 0; IM1 < t; IM1++)
                {
                    for (IM2 = 0; IM2 < t; IM2++)
                    {

                        printf(" %.1f ", matriz[IM1][IM2]);
                    }
                    printf("\n");
                }

            } // final
            float mult_lin;
            if (i == j && matriz[i][j] == 1) // zerando as entradas abaixo
            {

                percorre = j;
                for (aux = i + 1; aux < t; aux++)
                {
                    float mat2[t][t];
                    for (IM1 = 0; IM1 < t; IM1++)
                    {
                        for (IM2 = 0; IM2 < t; IM2++)
                        {
                            mat2[IM1][IM2] = matriz[IM1][IM2];
                        }
                    }
                    if (matriz[aux][j] != 0)
                    {

                        mult_lin = matriz[aux][j] * -1;
                        for (aux2 = j; aux2 < t; aux2++)
                        {
                            matriz[aux][aux2] = matriz[aux][aux2] + (matriz[i][percorre] * mult_lin);
                            percorre++;
                        }
                        percorre = j;
                        conta_p++;

                        printf("\n\t-precione qualquer tecla-");
                        getchar();
                        printf("\n\n\tZERANDO AS ENTRADAS ABAXO DO PIVOT \n\npasso %d\n\n ", conta_p);
                        for (IM1 = 0; IM1 < t; IM1++)
                        {
                            for (IM2 = 0; IM2 < t; IM2++)
                            {

                                printf(" %.1f ", mat2[IM1][IM2]);
                                if (IM1 == aux && IM2 == t - 1)
                                {
                                    printf("---L%d <- L%d + %.1f*L%d", aux + 1, aux + 1, mult_lin, i + 1);
                                }
                            }
                            printf("\n");
                        }

                        printf("\n\t|");
                        printf("\n\t|\n\n");
                        for (IM1 = 0; IM1 < t; IM1++)
                        {
                            for (IM2 = 0; IM2 < t; IM2++)
                            {

                                printf(" %.1f ", matriz[IM1][IM2]);
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    int loop;
    printf("Este programa realiza a eliminacao gaussiana de uma matriz quadrada qualquer\n"
           "voce pode escolher entre gerar uma matriz aleatoria ou digitar uma propria\n"
           "\n\t-pressione qualquer tecla para continuar");
    getchar();

    do
    {

        int t, ch;
        printf("\ndeseja:"
               "\n-uma matriz aleatoria --- pressione 1"
               "\n-digitar uma matriz --- pressione 0"
               "\n-->");

        scanf("%d", &ch);

        if (ch == 1)
        {
            do
            {
                t = rand() % 8;
            } while (t < 3);
            float matriz[t][t];

            int i, j;
            printf("\n\na matriz gerada foi:\n");
            for (i = 0; i < t; i++)
            {
                for (j = 0; j < t; j++)
                {

                    matriz[i][j] = rand() % 10;
                    printf(" %.1f ", matriz[i][j]);
                }
                printf("\n");
            }
            fflush(stdin);
            eliminacao_gaussiana(t, matriz);
        }
        else if (ch == 0)
        {
            printf("\ndigite o tamanho da matriz"
                   "\n-->");
            scanf("%d", &t);

            float matriz[t][t];

            int i, j;
            for (i = 0; i < t; i++)
            {
                printf("\n\tLINHA %d", i + 1);
                for (j = 0; j < t; j++)
                {
                    printf("\n-->");
                    scanf("%f", &matriz[i][j]);
                }
            }
            printf("\n\na matriz digitada foi:\n");
            for (i = 0; i < t; i++)
            {
                for (j = 0; j < t; j++)
                {

                    printf(" %.1f ", matriz[i][j]);
                }
                printf("\n");
            }
            fflush(stdin);
            eliminacao_gaussiana(t, matriz);
        }
        printf("\n\tse deseja continuar digite 1\n\tse nao, digite 0\n\t->");
        scanf("%d", &loop);
    } while (loop == 1);
    return 0;
}
