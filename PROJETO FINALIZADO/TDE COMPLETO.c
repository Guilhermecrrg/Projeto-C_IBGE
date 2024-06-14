#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


void ler(char*** dados);

int main() {
    setlocale(LC_ALL,"Portuguese");
    int i, j, c, f, x;
    char*** dados;
    char codigo_m[8];

    /// Alocação dinâmica de dados na matriz
    dados = (char***)malloc(5570 * sizeof(char**));
    for (i = 0; i < 5570; i++) {
        dados[i] = (char**)malloc(6 * sizeof(char*));
        for (j = 0; j < 6; j++) {
            dados[i][j] = (char*)malloc(100 * sizeof(char));
        }
    }

    ler(dados);

    do {
        printf("-----------------------------------------------------\n");
        printf("---Consulta do PIB de municípios do Brasil em 2020---\n");
        printf("-----------------------------------------------------\n");
        printf("\n");
        printf("1 - Consultar o PIB de um município\n");
        printf("2 - Consultar o PIB per capita de um município\n");
        printf("3 - Encerrar o programa\n");
        printf("\n");
        printf("Insira uma opção: ");
        scanf("%i", &x);
        printf("\n");
        switch(x) {

            /// PIB
            case (1) :
                printf("Digite o código do município: ");
                scanf("%s", codigo_m);
                    for (i = 0; i < 5570; i++) {
                    j = 2;
                    c = strcasecmp(dados[i][j], codigo_m);
                        if (c == 0) {
                        f = i;
                        break;
                        }
                    }
            if (i == 5570) {
                printf("Município não encontrado.\n");
                printf("\n");
            }
            else{
                printf("Nome do município: %s\n", dados[f][3]);
                printf("PIB do município a preços correntes (R$1,00): %s\n", dados[f][4]);
                printf("\n");
            }
                break;

            ///PIB per capita
            case (2) :
                printf("Digite o código do município: ");
                scanf("%s", codigo_m);
                    for (i = 0; i < 5570; i++) {
                    j = 2;
                    c = strcasecmp(dados[i][j], codigo_m);
                        if (c == 0) {
                        f = i;
                        break;
                        }
                    }
            if (i == 5570) {
                printf("Município não encontrado.\n");
                printf("\n");
            }
            else{
                printf("Nome do município: %s\n", dados[f][3]);
                printf("PIB per capita do município a preços correntes (R$1,00): %s\n", dados[f][5]);
                printf("\n");
            }
            break;
            /// Encerra o programa
            case(3) :
                printf("Obrigado por usar nosso programa!\n");
                break;


            default : printf ("Valor inválido!\n");
                printf("\n");
                break;

            }
            } while(x!=3);

    /// Libera a memória alocada
        for (i = 0; i < 5570; i++) {
        for (j = 0; j < 6; j++) {
            free(dados[i][j]);
        }
            free(dados[i]);
        }
            free(dados);

        return 0;
    }

/// Le os dados do arquivo .csv
void ler(char*** dados) {
    FILE* arquivo;
    int i = 0;
    char linha[600];
    char* token;

    arquivo = fopen("PIB.csv", "r");

    if (arquivo == NULL) {
        printf("Erro! Não foi possível abrir o arquivo de leitura.\n");
        return;
    }

    /// Grava os dados da tabela em matrizes
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        token = strtok(linha, ",");
        strcpy(dados[i][0], token);

        token = strtok(NULL, ",");
        strcpy(dados[i][1], token);

        token = strtok(NULL, ",");
        strcpy(dados[i][2], token);

        token = strtok(NULL, ",");
        strcpy(dados[i][3], token);

        token = strtok(NULL, ",");
        strcpy(dados[i][4], token);

        token = strtok(NULL, ",");
        strcpy(dados[i][5], token);

        i++;
    }

    fclose(arquivo);
}
