#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaErroDeArquivo(FILE *file)
{
    if (file == NULL)
    {
        printf("Erro!");
        exit(1);
    }
}

void filtragem(char *palavraBuscada, char *definicaoBuscada)
{
    FILE *file;
    file = fopen("teste.txt", "r");
    verificaErroDeArquivo(file);

    char conteudo[100];
    char *delimitador = "-";

    while (fgets(conteudo, sizeof(conteudo), file))
    {
        char *leftString = strtok(conteudo, delimitador);
        char *rightString = strtok(NULL, delimitador);

        if (!(strcmp(leftString, palavraBuscada)))
        {
            strcpy(definicaoBuscada, rightString);
            break;
        }
    }

    fclose(file);
}

void cadastrarPalavra()
{
    char palavra[100];
    char definicao[100];
    char *delimitador = "-";
    char linhaPraSalvar[100] = "";
    char definicaoBuscada[100] = "";

    printf("Digite uma palavra: ");
    scanf(" %s", palavra);

    filtragem(palavra, definicaoBuscada);

    if (definicaoBuscada[0] != '\0')
    {
        printf("A palavra ja esta cadastrada no dicionario.\n");
    }
    else
    {
        FILE *file;
        file = fopen("teste.txt", "a");
        verificaErroDeArquivo(file);

        printf("Digite a definição de \"%s\": ", palavra);
        scanf(" %[^\n]", definicao);

        strcat(linhaPraSalvar, palavra);
        strcat(linhaPraSalvar, delimitador);
        strcat(linhaPraSalvar, definicao);
        strcat(linhaPraSalvar, "\n");

        fputs(linhaPraSalvar, file);

        fclose(file);
    }
}

void buscarPalavra()
{
    char busca[100];
    char definicaoBuscada[100] = "";

    printf("Busca: ");
    scanf(" %s", busca);

    filtragem(busca, definicaoBuscada);

    if (definicaoBuscada[0] == '\0')
    {
        printf("A palavra buscada: %s, nao foi encontrada no dicionario.\n", busca);
    }
    else
    {
        printf("Definicao: %s", definicaoBuscada);
    }
}

void opcoes()
{
    int opcao = 0;

    while (opcao != 4)
    {
        printf("\nDigite uma opção:\n\n1 - Cadastrar uma palavra nova no dicionário\n2 - Consultar a definição de uma palavra\n3 - Jogar o Jogo da Forca\n4 - Sair\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarPalavra();
            break;
        case 2:
            buscarPalavra();
            break;
        case 3:
            printf("Value is 3\n");
            break;
        case 4:
            printf("Obrigado, volte sempre!\n");
            break;
        default:
            printf("Opção não encontrada, tente novamente.\n");
            break;
        }
    }
}

int main(void)
{
    opcoes();
    return 0;
}