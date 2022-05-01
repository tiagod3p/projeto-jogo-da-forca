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
        char *palavra = strtok(conteudo, delimitador);
        char *descricao = strtok(NULL, delimitador);

        if (!(strcmp(palavra, palavraBuscada)))
        {
            strcpy(definicaoBuscada, descricao);
            break;
        }
    }

    fclose(file);
}

void cadastrarPalavra()
{
    printf("--------- CADASTRAR PALAVRA ---------\n\n");

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
    printf("--------- BUSCAR PALAVRA ---------\n\n");

    char busca[100];
    char definicaoBuscada[100] = "";

    printf("Palavra que deseja buscar: ");
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

void sortearPalavraDoDicionario(char *palavraSorteada)
{
    FILE *file;
    file = fopen("teste.txt", "r");
    verificaErroDeArquivo(file);

    char conteudo[100];
    char *delimitador = "-";
    char *palavras[100];
    int incremento = 0;
    int tamanhoDicionario = 0;

    while (fgets(conteudo, sizeof(conteudo), file))
    {
        char *palavra = strtok(conteudo, delimitador);
        char *descricao = strtok(NULL, delimitador);

        palavras[incremento] = malloc(sizeof(char) * 101);
        strcpy(palavras[incremento], palavra);

        incremento++;
    }
    fclose(file);

    for (int i = 0; i <= 100; i++)
    {
        if (palavras[i] == NULL)
        {
            tamanhoDicionario = i - 1;
            break;
        }
    }

    strcpy(palavraSorteada, palavras[rand() % tamanhoDicionario]);
}

void formataLetras(char *letrasJaDigitadas, char *letrasFormatadas)
{
    strcpy(letrasFormatadas, "");

    for (int i = 0; i <= strlen(letrasJaDigitadas); i++)
    {
        if (i == strlen(letrasJaDigitadas) - 2)
        {
            sprintf(letrasFormatadas, "%s%c e ", letrasFormatadas, letrasJaDigitadas[i]);
        }
        else if (i == strlen(letrasJaDigitadas) - 1)
        {
            sprintf(letrasFormatadas, "%s%c", letrasFormatadas, letrasJaDigitadas[i]);
        }
        else
        {
            sprintf(letrasFormatadas, "%s%c, ", letrasFormatadas, letrasJaDigitadas[i]);
        }
    }
}

void adicionaAsteriscos(char *palavraSorteada, char *palavraPraDescobrirComAsteriscos, char letraDigitada, int *erros)
{
    char palavraPraDescobrirComAsteriscosAuxiliar[100];
    strcpy(palavraPraDescobrirComAsteriscosAuxiliar, palavraPraDescobrirComAsteriscos);

    for (int i = 0; i <= strlen(palavraSorteada) - 1; i++)
    {
        if (toupper(palavraSorteada[i]) == toupper(letraDigitada))
        {
            palavraPraDescobrirComAsteriscos[i] = toupper(letraDigitada);
        }
        else if (palavraPraDescobrirComAsteriscos[i] == NULL)
        {
            palavraPraDescobrirComAsteriscos[i] = '.';
        }
    }

    if (strcmp(palavraPraDescobrirComAsteriscos, palavraPraDescobrirComAsteriscosAuxiliar) == 0)
    {
        *erros = *erros + 1;
    }
}

void bonecoDeErros(int erros)
{
    switch (erros)
    {
    case 0:
        printf("X==:==\n");
        printf("X     \n");
        printf("X     \n");
        printf("X     \n");
        printf("X     \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 1:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X     \n");
        printf("X     \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 2:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X  |  \n");
        printf("X     \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 3:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X \\| \n");
        printf("X     \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 4:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X \\|/ \n");
        printf("X     \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 5:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X \\|/ \n");
        printf("X /   \n");
        printf("X     \n");
        printf("===========\n");
        break;
    case 6:
        printf("X==:==\n");
        printf("X  :  \n");
        printf("X  O  \n");
        printf("X \\|/ \n");
        printf("X / \\ \n");
        printf("X     \n");
        printf("===========\n");
        break;
    default:
        break;
    }
}

void jogarForca()
{
    char palavraSorteada[100] = "";
    char letrasJaDigitadas[100] = "";
    char palavraPraDescobrirComAsteriscos[100] = "";
    char letraDigitada;
    char letrasFormatadas[100] = "";
    int erros = 0;

    sortearPalavraDoDicionario(palavraSorteada);

    printf("--------- JOGO DA FORCA ---------\n\n");

    while (1)
    {
        adicionaAsteriscos(palavraSorteada, palavraPraDescobrirComAsteriscos, letraDigitada, &erros);

        bonecoDeErros(erros);

        printf("%s\n\n", palavraPraDescobrirComAsteriscos);

        if (strchr(palavraPraDescobrirComAsteriscos, '.') == NULL)
        {
            printf("Parabens, voce ganhou. A palavra correta era: %s.\n\n", palavraSorteada);
            break;
        }

        if (erros >= 6)
        {
            printf("Voce perdeu. A palavra correta era: %s.\n\n", palavraSorteada);
            break;
        }

        formataLetras(letrasJaDigitadas, letrasFormatadas);

        printf("Letras ja digitadas: %s\n\n", letrasFormatadas);

        printf("Digite uma letra: ");
        scanf(" %c", &letraDigitada);

        if (strchr(letrasJaDigitadas, toupper(letraDigitada)) != NULL)
        {
            printf("A letra: %c ja foi digitada. Digite uma nova letra.\n", toupper(letraDigitada));
            erros--;
            continue;
        }

        sprintf(letrasJaDigitadas, "%s%c", letrasJaDigitadas, toupper(letraDigitada));
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
            jogarForca();
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