//ESTE ARQUIVO IRÁ CONTER AS FUNÇÕES QUE CALCULAM SE HOUVE CHEQUE MATE OU NÃO/
//ESTAS FUNÇÕES SERÃO ACIONANDAS QUANDO O REI ESTIVER EM CHEQUE ISTO É SE white_king_in_check OU black_king_in_check TIVER O VALOR true E AS FUNÇÕES DE CHECAGEM DE STATUS FOREM ACIONADAS REGISTRANDO A POSIÇÃO DAS PEÇAS ATACANTES E DO REI

//****************************************************************************************************************************

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<array>
#include<vector>
#include"xadrez_classe.hpp"
using namespace std;

//***************************************************************************************************************************
//FUNÇÕES QUE TESTA O MOVIMENTO DE PEÇAS EM CASO DE CHEQUE
//BRANCAS
bool chess_game::white_test_for_check(int x1, int y1, int x2, int y2){
//VARIÁVEL LOCAL
bool result;
bool king_state;//VARIÁVEL QUE ALOCA SE O REI ESTÁ EM CHEQUE OU NÃO

//PROCEDIMENTOS
//SALVANDO O ESTADO DO TABULEIRO PRINCIPAL
save_state();
king_state=white_king_in_check;

//EXECUTANDO O MOVIMENTO
board[x2][y2]=board[x1][y1];
board[x1][y1]="  ";

//TESTE SE O REI ESTÁ EM CHEQUE
white_king_status();
if(white_king_in_check==true)
result=true;
else if(white_king_in_check==false)
result=false;

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();
reset_board();
white_king_in_check=king_state;

//RESULTADO
return result;

                                                                    };

//NEGRAS
bool chess_game::black_test_for_check(int x1, int y1, int x2, int y2){
//VARIÁVEL LOCAL
bool result;
bool king_state;//VARIÁVEL QUE ALOCA SE O REI ESTÁ EM CHEQUE OU NÃO

//PROCEDIMENTOS
//SALVANDO O ESTADO DO TABULEIRO PRINCIPAL
save_state();
king_state=black_king_in_check;

//EXECUTANDO O MOVIMENTO
board[x2][y2]=board[x1][y1];
board[x1][y1]="  ";

//TESTE SE O REI ESTÁ EM CHEQUE
black_king_status();
if(black_king_in_check==true)
result=true;
else if(black_king_in_check==false)
result=false;

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();
reset_board();
black_king_in_check=king_state;

//RESULTADO
return result;

                                                                    };

//***************************************************************************************************************************
//FUNÇÕES QUE DETERMINA SE É CHEQUE MATE OU NÃO
//BRANCAS
bool chess_game::white_checkmate_checker(){
white_stalemate_draw();
if(draw_game==true && white_king_in_check==true)
checkmate=true;
return checkmate;
                                          };

//NEGRAS
bool chess_game::black_checkmate_checker(){
black_stalemate_draw();

if(draw_game==true && black_king_in_check==true)
checkmate=true;

//RESULTADO
return checkmate;
                                          };

//***************************************************************************************************************************
//FUNÇÃO QUE INFORMA AOS JOGADORES QUANDO HÁ UM CHEQUEMATE
void chess_game::checkmate_warning(){
cout<<"Chequemate!!!\nFim de jogo.\n";
                                    };

//****************************************************************************************************************************
//FUNÇÃO QUE PERMITE A UM JOGADOR ABANDONAR O JOGO
void chess_game::resignate(){
string token;
cout<<"Jogador você deseja abandonar o jogo?\n(Digite 's' para encerrar a partida ou 'n' para continuar)\n";
cin>>token;
if(token=="s")
resignation=true;

                            };
