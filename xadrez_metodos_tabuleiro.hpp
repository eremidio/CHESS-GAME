//ESTE ARQUIVO CONTÉM A DECLARAÇÃO DOS MÉTODOS DO JOGO DE XADREZ RELACIONADOS AO TABULEIRO.
//****************************************************************************************************************************

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include"xadrez_classe.hpp"
using namespace std;

//****************************************************************************************************************************
//MÉTODOS

//FUNÇÃO QUE PRINTA O TABULEIRO NA TELA
void chess_game::print_board(){
printf("\n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 8\n", board[7][0].c_str(), board[7][1].c_str(), board[7][2].c_str(), board[7][3].c_str(), board[7][4].c_str(), board[7][5].c_str(), board[7][6].c_str(), board[7][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 7\n", board[6][0].c_str(), board[6][1].c_str(), board[6][2].c_str(), board[6][3].c_str(), board[6][4].c_str(), board[6][5].c_str(), board[6][6].c_str(), board[6][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 6\n", board[5][0].c_str(), board[5][1].c_str(), board[5][2].c_str(), board[5][3].c_str(), board[5][4].c_str(), board[5][5].c_str(), board[5][6].c_str(), board[5][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 5\n", board[4][0].c_str(), board[4][1].c_str(), board[4][2].c_str(), board[4][3].c_str(), board[4][4].c_str(), board[4][5].c_str(), board[4][6].c_str(), board[4][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 4\n", board[3][0].c_str(), board[3][1].c_str(), board[3][2].c_str(), board[3][3].c_str(), board[3][4].c_str(), board[3][5].c_str(), board[3][6].c_str(), board[3][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 3\n", board[2][0].c_str(), board[2][1].c_str(), board[2][2].c_str(), board[2][3].c_str(), board[2][4].c_str(), board[2][5].c_str(), board[2][6].c_str(), board[2][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 2\n", board[1][0].c_str(), board[1][1].c_str(), board[1][2].c_str(), board[1][3].c_str(), board[1][4].c_str(), board[1][5].c_str(), board[1][6].c_str(), board[1][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("|      |      |      |      |      |      |      |      |  \n");
printf("|  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 1\n", board[0][0].c_str(), board[0][1].c_str(), board[0][2].c_str(), board[0][3].c_str(), board[0][4].c_str(), board[0][5].c_str(), board[0][6].c_str(), board[0][7].c_str());
printf("|      |      |      |      |      |      |      |      |  \n");
printf("+------+------+------+------+------+------+------+------+  \n");
printf("   a      b       c      d      e      f      g      h     \n\n");
                              };

//FUNÇÃO QUE RESETA O TABULEIRO SECUNDÁRIO
void chess_game::reset_board(){
//VARIÁVEIS LOCAIS
int i, j;
//AJUSTE DOS TABULEIROS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
secondary_board[i][j]="  ";
                  };
                  };
                              };

//FUNÇÃO QUE AJUSTA O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
void chess_game::set_board(){
printf("\n");
printf("Eis o tabuleiro de xadrez em sua configuração inicial:\n");
board[0][0]="TB"; //PEÇAS BRANCAS 
board[0][1]="CB";
board[0][2]="BB";
board[0][3]="DB";
board[0][4]="RB";
board[0][5]="BB";
board[0][6]="CB";
board[0][7]="TB";
board[1][0]="PB";
board[1][1]="PB";
board[1][2]="PB";
board[1][3]="PB";
board[1][4]="PB";
board[1][5]="PB";
board[1][6]="PB";
board[1][7]="PB";
board[6][0]="PP";//PEÇAS PRETAS
board[6][1]="PP";
board[6][2]="PP";
board[6][3]="PP";
board[6][4]="PP";
board[6][5]="PP";
board[6][6]="PP";
board[6][7]="PP";
board[7][0]="TP";
board[7][1]="CP";
board[7][2]="BP";
board[7][3]="DP";
board[7][4]="RP";
board[7][5]="BP";
board[7][6]="CP";
board[7][7]="TP";
                            };

//FUNÇÃO QUE OBTÉM AS COORDENADAS DAS CASAS NAS QUAIS UMA PEÇA ESTÁ
void chess_game::index1(){
//RECEBENDO INPUT DO USUÁRIO
cout<<"Digite as coordenadas (letra+número) da casa onde está a peça que você deseja mover:\n(Digite 'o-o' para executar o roque curto, 'o-o-o' executar o roque longo ou 'en' para executar a captura en passant).\n";
cin>>initial_square;

//EM CASO DE MOVIMENTOS ESPECIAIS ENCERRAR ESTA FUNÇÃO E ACIONAR A FUNÇÃO QUE EXECUTA O MOVIMENTO ESPECIAL
if(initial_square=="en" || initial_square=="o-o" || initial_square=="o-o-o")
return;

//OBTENDO AS COORDENADAS
string char1, char2;//VARIÁVEIS LOCAIS

char1 = initial_square[0];

if(char1=="a")
column1=0;
if(char1=="b")
column1=1;
if(char1=="c")
column1=2;
if(char1=="d")
column1=3;
if(char1=="e")
column1=4;
if(char1=="f")
column1=5;
if(char1=="g")
column1=6;
if(char1=="h")
column1=7;

char2 = initial_square[1];
row1=stoi(char2)-1;

//TESTE1, USE UM /**/ APÓS O TESTE
/*cout<<"TESTE 1\n";
cout<<"row1: "<< row1<<"\n";
cout<<"column1: "<< column1<<"\n";*/
            };

//FUNÇÃO QUE OBTÉM AS COORDENADAS DAS CASAS NAS QUAIS UMA PEÇA SERÁ ALOCADA
void chess_game::index2(){
//RECEBENDO INPUT DO USUÁRIO
cout<<"Digite as coordenadas (letra+número) da casa para a qual você deseja mover a peça:\n";
cin>>final_square;
//OBTENDO AS COORDENADAS
string char1, char2;//VARIÁVEIS LOCAIS

char1 = final_square[0];



if(char1=="a")
column2=0;
if(char1=="b")
column2=1;
if(char1=="c")
column2=2;
if(char1=="d")
column2=3;
if(char1=="e")
column2=4;
if(char1=="f")
column2=5;
if(char1=="g")
column2=6;
if(char1=="h")
column2=7;

char2 = final_square[1];
row2=stoi(char2)-1;

//TESTE1, USE UM /**/ APÓS O TESTE
/*cout<<"TESTE 1\n";
cout<<"row2: "<< row2<<"\n";
cout<<"column2: "<< column2<<"\n";*/

            };


//FUNÇÃO QUE OBTÉM AS COORDENADAS DAS CASAS NAS QUAIS UMA PEÇA ESTÁ (CAPTURA EN PASSANT)
void chess_game::index3(){
//RECEBENDO INPUT DO USUÁRIO
cout<<"Digite as coordenadas (letra+número) da casa onde está a peça que você deseja mover:\n";
cin>>initial_square;

//OBTENDO AS COORDENADAS
string char1, char2;//VARIÁVEIS LOCAIS

char1 = initial_square[0];

if(char1=="a")
column1=0;
if(char1=="b")
column1=1;
if(char1=="c")
column1=2;
if(char1=="d")
column1=3;
if(char1=="e")
column1=4;
if(char1=="f")
column1=5;
if(char1=="g")
column1=6;
if(char1=="h")
column1=7;

char2 = initial_square[1];
row1=stoi(char2)-1;
            };

//FUNÇÃO QUE AVALIA O VALOR DAS PEÇAS DAS BRANCAS
int chess_game::evaluate_white_pieces(){
int i, j, soma; //VARIÁVEIS LOCAIS

soma=0; //AJUSTE DE VARIÁVEL

for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
if(board[i][j]=="PB")
soma+=100;
if(board[i][j]=="CB")
soma+=350;
if(board[i][j]=="BB")
soma+=400;
if(board[i][j]=="TB")
soma+=500;
if(board[i][j]=="DB")
soma+=900;
if(board[i][j]=="RB")
soma+=10000;
                  };
                  };

return soma;
                                       };

//FUNÇÃO QUE AVALIA O VALOR DAS PEÇAS DAS NEGRAS
int chess_game::evaluate_black_pieces(){
int i, j, soma; //VARIÁVEIS LOCAIS

soma=0; //AJUSTE DE VARIÁVEL

for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
if(board[i][j]=="PP")
soma-=100;
if(board[i][j]=="CP")
soma-=350;
if(board[i][j]=="BP")
soma-=400;
if(board[i][j]=="TP")
soma-=500;
if(board[i][j]=="DP")
soma-=900;
if(board[i][j]=="RP")
soma-=10000;
                  };
                  };

return soma;
                                       };

//FUNÇÃO QUE DETERMINA SE HOUVE CAPTURA DE PEÇAS DAS BRANCAS
void chess_game::white_pieces_counter(){
int result= white_evaluation1-white_evaluation2;
if(result==100){
cout<<"Um peão das brancas foi capturado.\n";
nor_pawn_capture=0;
               };
if(result==350){
cout<<"Um cavalo das brancas foi capturado.\n";
nor_pawn_capture=0;
               };
if(result==400){
cout<<"Um bispo das brancas foi capturado.\n";
nor_pawn_capture=0;
               };
if(result==500){
cout<<"Uma torre das brancas foi capturada.\n";
nor_pawn_capture=0;
               };
if(result==900){
cout<<"Uma dama das brancas foi capturada.\n";
nor_pawn_capture=0;
               };

                                       };

//FUNÇÃO QUE DETERMINA SE HOUVE CAPTURA DE PEÇAS DAS BRANCAS
void chess_game::black_pieces_counter(){
int result= black_evaluation1-black_evaluation2;
if(result==(-100)){
cout<<"Um peão das negras foi capturado.\n";
nor_pawn_capture=0;
                  };
if(result==(-350)){
cout<<"Um cavalo das negras foi capturado.\n";
nor_pawn_capture=0;
                  };
if(result==(-400)){
cout<<"Um bispo das negras foi capturado.\n";
nor_pawn_capture=0;
                  };
if(result==(-500)){
cout<<"Uma torre das negras foi capturada.\n";
nor_pawn_capture=0;
                  };
if(result==(-900)){
cout<<"Uma dama das negras foi capturada.\n";
nor_pawn_capture=0;
                  };

                                       };


//FUNÇÃO QUE CÓPIA O TABULEIRO PRINCIPAL NO TABULEIRO SECUNDÁRIO
void chess_game::save_state(){
int i, j; //VARIÁVEIS LOCAIS

//SALVANDO O ESTADO DO TABULEIRO 1 NO TABULEIRO2
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
secondary_board[i][j]=board[i][j];
                  };
                  };
                             };

//FUNÇÃO QUE RETORNA O ESTADO SALVO NO TABULEIRO SECUNDÁRIO NO TABULEIRO PRINCIPAL
void chess_game::restore_state(){
int i, j; //VARIÁVEIS LOCAIS

//RESTAURANDO O TABULEIRO PRINCIPAL EM SEU ESTADO ORIGINAL 
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
board[i][j]=secondary_board[i][j];
                  };
                  };
reset_board();//RESTAURANDO O STATUS PADRÃO DO TABULEIRO SECUNDÁRIO
                       
                                };
