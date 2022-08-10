//ESPECIFICAÇAO

#ifndef JOGO_VELHA_H
#define JOGO_VELHA_H

//ASSINATURAS

//RESERVA MEMORIA 
char **AlocaMemoria();

//CONDICOES DE FINALIZACAO
int FinalizaJogo(char **M);

//LIBERAR O ESPACO ALOCADO
void LiberarTabuleiro(char **M);

//INSERE AS POSICOES DE CADA JOGADOR
void InserirJogador2(char **M);
void InserirJogador1(char **M);

//ATUALIZA O TABULEIRO
void Tabuleiro(char **M);

#endif