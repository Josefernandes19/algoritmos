/*
 * File:   main.c
 * Authors: José Fernandes & Leonardo Yoshimura
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUNAS 1024
#define COLLUNAS 64

int menu(){
    int escolha;
    printf("------ M E N U  D E  O P Ç Õ E S ------\n");
    printf("1 - Escurecer\n");
    printf("2 - Clarear\n");
    printf("3 - Suavizar\n");
    printf("4 - Binarizar\n");
    printf("5 - Inverter\n");
    printf("6 - Iconizar\n");
    printf("7 - Inversão de cores\n");
    printf("8 - Sair\n");
    printf("Escolha uma das opções acima: ");
    fflush(stdout);
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int menuinv(){
    int escolha;
    printf("------ M E N U  D E  I N V E R S Õ E S ------\n");
    printf("1 - Inverter na Horizontal\n");
    printf("2 - Inverter na Vertical\n");
    printf("3 - Inverter na Diagonal\n");
    printf("Escolha uma das opções acima: ");
    fflush(stdout);
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int menucor(){
    int escolha;
    printf("------ M E N U  D E  I N V E R S Ã O  D E  C O R E S ------\n");
    printf("1 - Inverter somente lado direito\n");
    printf("2 - Inverter somente lado esquerdo\n");
    printf("3 - Inverter inteiro\n");
    printf("Escolha uma das opções acima: ");
    fflush(stdout);
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}
void escurecer(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j;
    float esc;
    esc = -1;
    while (esc < 0 || esc > 1)
    {
        printf("Digite o fator de escurecimento (Valor entre 0 e 1): ");
        fflush(stdout);
        scanf("%f", &esc);
    }
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < co; j++)
        {
            aux[i][j] = imagem[i][j] * esc;
        }
    }
    salvararq(aux, li, co);
}

void clarear(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j;
    float cla;
    cla = -1;
    while (cla <= 1)
    {
        printf("Digite o fator de clareamento (Valor maior que 1): ");
        fflush(stdout);
        scanf("%f", &cla);
    }
    for (i = 0; i < li; i++)
    {
        for ( j = 0; j < co; j++)
        {
            if ((imagem[i][j] * cla) >= 255)
            {
                aux[i][j] = 255;
            }
            else
            {
                aux[i][j] = imagem[i][j] * cla;
            }
        }
    }
    salvararq(aux, li, co);
}

void suavizar(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, iaux, jaux, va, med;
    for(i = 0; i < li; i++)
    {
        for(j = 0; j < co; j++)
        {
            aux[i][j] = imagem[i][j];
        }
    }
    for(i = 1; i < li - 3; i++)
    {
        for(j = 1; j < co - 3; j++)
        {
            va = 0;
            for(iaux = i; iaux < i + 3; iaux++)
            {
                for(jaux = j; jaux < j + 3; jaux++)
                {
                    va = va + imagem[iaux][jaux];
                }
            }
            med = va / 9;
            for(iaux = i; iaux < i + 3; iaux++)
            {
                for(jaux = j; jaux < j + 3; jaux++)
                {
                    aux[iaux][jaux] = med;
                }
            }
        }
    }
    salvararq(aux, li, co);
}

void binarizar(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int f, i, j;
    printf("Digite o número a partir do qual a imagem será binarizada: ");
    fflush(stdout);
    scanf("%d", &f);
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < co; j++)
        {
            if (imagem[i][j] >= f)
            {
                aux[i][j] = 255;
            }
            else
            {
                aux[i][j] = 0;
            }
        }
    }
    salvararq(aux, li, co);
}

void inverterH(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, jaux;
    for (i = 0; i < li; i++)
    {
        jaux = co;
        for (j = 0; j < co; j++)
        {
            aux[i][jaux] = imagem[i][j];
            jaux = jaux - 1;
        }
    }
    salvararq(aux, li, co);
}

void inverterV(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, iaux;
    for (j = 0; j < co; j++)
    {
        iaux = li;
        for (i = 0; i < li; i++)
        {
            aux[iaux][j] = imagem[i][j];
            iaux = iaux - 1;
        }
    }
    salvararq(aux, li, co);
}

void inverterD(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, iaux, jaux;
    jaux = co;
    for (j = 0; j < co; j++)
    {
        iaux = li;
        for (i = 0; i < li; i++)
        {
            aux[iaux][jaux] = imagem[i][j];
            iaux = iaux - 1;
        }
        jaux = jaux - 1;
    }
    salvararq(aux, li, co);
}

void icon(int imagem[][COLUNAS], int li, int co){
    int aux[64][64], i, j, i2, j2, i3, j3, som, med;
    i3 = 0;
    for (i = 0; i < li; i = i + 16)
    {
        j3 = 0;
        for(j = 0; j < co; j = j + 16)
        {
            som = 0;
            for(i2 = i; i2 < (i + 15); i2++)
            {
                for(j2 = j; j2 < (j + 15); j2++)
                {
                    som = som + imagem[i][j];
                }
            }
                med = som / 256;
                aux[i3][j3] = med;
                j3 = j3 + 1;
        }
        i3 = i3 + 1;
    }

    salvararqicon(aux, 64, 64);
}

void coresi(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, dist;
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < co; j++)
        {
            if (imagem[i][j] > 128)
            {
                dist = 256 - imagem[i][j];
                aux[i][j] = dist - 1;
            }
            else
            {
                dist = imagem[i][j];
                aux[i][j] = 256 - dist - 1;
            }
        }
    }
    salvararq(aux, li, co);
}

void coresd(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, dist;
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < co; j++)
        {
            if(j > (li/2))
            {
                if (imagem[i][j] > 128)
                {
                    dist = 256 - imagem[i][j];
                    aux[i][j] = dist - 1;
                }
                else
                {
                    dist = imagem[i][j];
                    aux[i][j] = 256 - dist - 1;
                }
            }
            else
            {
                aux[i][j] = imagem[i][j];
            }
        }
    }
    salvararq(aux, li, co);
}

void corese(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co){
    int i, j, dist;
    for (i = 0; i < li; i++)
    {
        for (j = 0; j < co; j++)
        {
            if(j < (li/2))
            {
                if (imagem[i][j] > 128)
                {
                    dist = 256 - imagem[i][j];
                    aux[i][j] = dist - 1;
                }
                else
                {
                    dist = imagem[i][j];
                    aux[i][j] = 256 - dist - 1;
                }
            }
            else
            {
                aux[i][j] = imagem[i][j];
            }
        }
    }
    salvararq(aux, li, co);
}

void sair(){
    exit(0);
}


void salvararqicon(int imagem[][COLLUNAS], int li, int cl){
    FILE *arqueevo;
    char nome[40];
    int i, j;
    printf("Digite o nome do arquivo e a extensão desejada, sem espaçamento. (Exemplo: arquivo.pgm): ");
    scanf("%s", &nome);
    arqueevo = fopen(nome, "w");
    if (arqueevo == NULL)
    {
        printf("Erro ao abrir ou criar o arquivo!\n");
    }
    else
    {
       fprintf(arqueevo, "P2\r\n# 'Gambiarra você não corrige. Você Melhora. CARVALHO, Leandra' \r\n%d %d\r\n255\r\n", cl, li);
        for(i = 0; i < li; i++)
        {
            for(j = 0; j < cl; j++)
            {
                fprintf(arqueevo, "%d ", imagem[i][j]);
            }
            fprintf(arqueevo, "\r\n");
        }
    }
    fclose(arqueevo);
}

void salvararq(int imagem[][COLUNAS], int li, int cl){
    FILE *arqueevo;
    char nome[40];
    int i, j;
    printf("Digite o nome do arquivo e a extensão desejada, sem espaçamento. (Exemplo: arquivo.pgm): ");
    scanf("%s", &nome);
    arqueevo = fopen(nome, "w");
    if (arqueevo == NULL)
    {
        printf("Erro ao abrir ou criar o arquivo!\n");
    }
    else
    {
       fprintf(arqueevo, "P2\r\n# 'Gambiarra você não corrige. Você Melhora. CARVALHO, Leandra' \r\n%d %d\r\n255\r\n", cl, li);
        for(i = 0; i < li; i++)
        {
            for(j = 0; j < cl; j++)
            {
                fprintf(arqueevo, "%d ", imagem[i][j]);
            }
            fprintf(arqueevo, "\r\n");
        }
    }
    fclose(arqueevo);
}

void sac(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co, int escolha){
    int escinv, esccor;
    switch (escolha){
        case 1:
            escurecer(imagem, aux, li, co);
        break;
        case 2:
            clarear(imagem, aux, li, co);
        break;
        case 3:
            suavizar(imagem, aux, li, co);
        break;
        case 4:
            binarizar(imagem, aux, li, co);
        break;
        case 5:
            escinv = menuinv();
            sacinv(imagem, aux, li, co, escinv);
        break;
        case 6:
            icon(imagem, li, co);
        break;
        case 7:
            esccor = menucor();
            saccor(imagem, aux, li, co, esccor);
        break;
        case 8:
            sair();
        break;
    }
}

void sacinv(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co, int escinv){
    switch(escinv){
        case 1:
            inverterH(imagem, aux, li, co);
        break;
        case 2:
            inverterV(imagem, aux, li, co);
        break;
        case 3:
            inverterD(imagem, aux, li, co);
        break;
    }
}

void saccor(int imagem[][COLUNAS], int aux[][COLUNAS], int li, int co, int esccor){
    switch(esccor){
        case 1:
            coresd(imagem, aux, li, co);
        break;
        case 2:
            corese(imagem, aux, li, co);
        break;
        case 3:
            coresi(imagem, aux, li, co);
        break;
    }
}
int main() {
    FILE *imagem;
    int escolha, li, co, buffer3, i, j;
    static int imageM[1024][1024], aux[1024][1024];
    char buffer[200], buffer2 = 'i', check[10];
    imagem = fopen("imagemO.pgm", "r");
    if (imagem == NULL)
    {
        printf("Erro ao abrir a imagem!\n");
    }
    else
    {
        printf("Imagem aberta com sucesso!\n");
        //le o P2
        fscanf(imagem, "%s", &check);
        strcpy(buffer, "P2");
        if(strcmp (check, buffer) == 0)
        {
            fscanf(imagem, "%s", buffer);
            fgets(buffer, 150, imagem);
            //printf("%s\n", buffer);


            fscanf(imagem, "%d %d", &co, &li);
            fscanf(imagem, "%s", &buffer);
            for(i = 0; i < li; i++)
            {
                for (j = 0; j < co; j++)
                {
                    fscanf(imagem, "%d", &buffer3);
                    imageM[i][j] = buffer3;
                    aux[i][j] = 255;
                }
            }
            while(1)
            {
            escolha = menu();
            sac(imageM, aux, li, co, escolha);
            }
        }
        else
        {
            printf("Formato incorreto de imagem!");
        }
    }
    return 0;
}
