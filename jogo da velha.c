//FUNÇOES

#include "jogo da velha.h"
#include <stdio.h>
#include <stdlib.h>

char **AlocaMemoria()
  {
  char **M;
  int linha=3, coluna=3;

//RESERVA ESPACO NA MEMORIA COM UM ENDERECO DE MEMORIA DO TIPO ESEPCIFICO(ASSIM SENDO UM PONTEIRO QUE APONTA PARA OUTRO PONTEIRO)
  M =(char **) malloc(linha * sizeof(char *));

//PERCORRE POSICAO NA MEMORIA DOS ENDERECOS ALOCADOS ANTES
//ALOCA EM CADA POSICAO QUANTIDADE DO TIPO DE DADO DO PONTEIRO
    for(linha = 0; linha < 3; linha++)
      {
      *(M + linha) = (char *) malloc(coluna * sizeof(char));
      }

//INSERE NOS VALORES DE CHAR "espaco", ESPACO LIVRE NO TABULEIRO
    for(linha = 0; linha < 3; linha++)
      {
        for(coluna = 0; coluna < 3; coluna++)
          {
          *(*(M + linha) + coluna) =  ' ';
          }
      }
  return(M);
  }


void Tabuleiro(char **M)
  {
  system("cls");
  printf("\n\t %c | %c | %c", (*(*(M + 0) + 0)), (*(*(M + 0) + 1)), (*(*(M + 0) + 2)));
  printf("\n\t-----------");
  printf("\n\t %c | %c | %c", (*(*(M + 1) + 0)), (*(*(M + 1) + 1)), (*(*(M + 1) + 2)));
  printf("\n\t-----------");
  printf("\n\t %c | %c | %c", (*(*(M + 2) + 0)), (*(*(M + 2) + 1)), (*(*(M + 2) + 2)));
  }

//CONTEM AS CONDICOES DE TERMINO DO JOGO
int FinalizaJogo(char **M)
  {
  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 0) + 1)) == 'x' && (*(*(M + 0) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 1) + 0)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 1) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 2) + 0)) == 'x' && (*(*(M + 2) + 1)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 1) + 0)) == 'x' && (*(*(M + 2) + 0)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 1)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 1)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 2)) == 'x' && (*(*(M + 1) + 2)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 2)) == 'x' )
    return 1;
  if( (*(*(M + 0) + 2)) == 'x' && (*(*(M + 1) + 1)) == 'x' && (*(*(M + 2) + 0)) == 'x' )
    return 1;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 0) + 1)) == 'o' && (*(*(M + 0) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 1) + 0)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 1) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 2) + 0)) == 'o' && (*(*(M + 2) + 1)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 1) + 0)) == 'o' && (*(*(M + 2) + 0)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 1)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 1)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 2)) == 'o' && (*(*(M + 1) + 2)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;


  if( (*(*(M + 0) + 0)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 2)) == 'o' )
    return 2;
  if( (*(*(M + 0) + 2)) == 'o' && (*(*(M + 1) + 1)) == 'o' && (*(*(M + 2) + 0)) == 'o' )
    return 2;

return 0;
  }


//IMPORTANTE LIBERAR MEMORIA
void LiberarTabuleiro(char **M)
  {
  int linha = 0;
    for(linha = 0; linha < 3; linha++)
      {
      free(*(M + linha));
      *(M + linha) = NULL;
      }
  free(M);
  M = NULL;
  }


//COORDENADA DE INSERCAO NO TABUEIRO DO JOGADOR 2
void InserirJogador2(char **M)
  {
  int linha = 0, coluna = 0;

//INSERCAO PADRAO
  printf("\n\n-JOGADOR 2(x)-\n");
  printf("\nLINHA: ");
  fflush(stdin);
  scanf("%d", &linha);
  printf("\nCOLUNA: ");
  fflush(stdin);
  scanf("%d", &coluna);

//LIMITADOR DE POSICAO DO JOGADOR
    if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
      {
        while(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
          {
          printf("\n\nPOSICAO INEXISTENTE");
          printf("\n\n-JOGADOR 2(x)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);
          }
      }

//CORRECAO DE POSICAO DO VETOR
  linha = (linha - 1);
  coluna = (coluna - 1);

//CASO PARA POSICAO DO TABULEIRO JA OCUPADA
    if( (*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o' )
      {
        while((*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o')
          {
          Tabuleiro(M);
     
          printf("\n\n-POSICAO JA OCUPADA\n\n");
          printf("\n\n-JOGADOR 2(x)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);

          linha = (linha - 1);
          coluna = (coluna - 1);
          }
      *(*(M + linha) + coluna) = 'x';
      }
    else
      {
      *(*(M + linha) + coluna) = 'x';
      }
  }


//COORDENADA DE INSERCAO NO TABUEIRO DO JOGADOR 1
void InserirJogador1(char **M)
  {
  int linha = 0, coluna = 0;

//INSERCAO PADRAO
  printf("\n\n-JOGADOR 1(o)-\n");
  printf("\nLINHA: ");
  fflush(stdin);
  scanf("%d", &linha);
  printf("\nCOLUNA: ");
  fflush(stdin);
  scanf("%d", &coluna);

//LIMITADOR DE POSICAO DO JOGADOR
  if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
      {
        while(linha > 3 || linha < 1 || coluna > 3 || coluna < 1)
          {
          printf("\n\nPOSICAO INEXISTENTE");
          printf("\n\n-JOGADOR 1(o)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);
          }
      }

//CORRECAO DE POSICAO DO VETOR
  linha = (linha - 1);
  coluna = (coluna - 1);

//CASO PARA POSICAO DO TABULEIRO JA OCUPADA
    if( (*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o' )
      {
        while((*(*(M + linha) + coluna)) == 'x' || (*(*(M + linha) + coluna)) == 'o')
          {
          Tabuleiro(M);
          
          printf("\n\n-POSICAO JA OCUPADA\n\n");
          printf("\n\n-JOGADOR 1(o)-\n");
          printf("\nLINHA: ");
          fflush(stdin);
          scanf("%d", &linha);
          printf("\nCOLUNA: ");
          fflush(stdin);
          scanf("%d", &coluna);

          linha = (linha - 1);
          coluna = (coluna - 1);
          }
        *(*(M + linha) + coluna) = 'o';
      }
    else
      {
      *(*(M + linha) + coluna) = 'o';
      }
  }