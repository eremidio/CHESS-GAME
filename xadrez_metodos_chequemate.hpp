//ESTE ARQUIVO IRÁ CONTER AS FUNÇÕES QUE CALCULAM SE HOUVE CHEQUE MATE OU NÃO/
//ESTAS FUNÇÕES SERÃO ACIONANDAS QUANDO O REI ESTIVER EM CHEQUE ISTO É SE white_king_in_check OU black_king_in_check TIVER O VALOR true E AS FUNÇÕES DE CHECAGEM DE STATUS FOREM ACIONADAS REGISTRANDO A POSIÇÃO DAS PEÇAS ATACANTES E DO REI

//****************************************************************************************************************************

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"xadrez_classe.hpp"
using namespace std;

//****************************************************************************************************************************
//FUNÇÕES QUE DETERMINAM SE É POSSÍVEL ESCAPAR DO CHEQUE COM UM MOVIMENTO DE REI
//BRANCAS
bool chess_game::white_check_king_escape(){
//VARIÁVEIS LOCAIS
int safe_moves_counter;//REGISTRADO O NÚMERO DE LANCES SEGUROS
bool status;//RESULTADO 

safe_moves_counter=0;//AJUSTE DE VARIÁVEIS


//PROCEDIMENTOS
//UM REI POSSUI 8 POSSUI AO TODO 8 MOVIMENTOS POSSÍVEIS
//(+1, +1)
if(board[white_king_row+1][white_king_column+1]!="PB" && board[white_king_row+1][white_king_column+1]!="CB" && board[white_king_row+1][white_king_column+1]!="BB" && board[white_king_row+1][white_king_column+1]!="TB" && board[white_king_row+1][white_king_column+1]!="DB" && (white_king_row+1)<8 && (white_king_column+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row+1][white_king_column+1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(+1, -1)
if(board[white_king_row+1][white_king_column-1]!="PB" && board[white_king_row+1][white_king_column-1]!="CB" && board[white_king_row+1][white_king_column-1]!="BB" && board[white_king_row+1][white_king_column-1]!="TB" && board[white_king_row+1][white_king_column-1]!="DB" && (white_king_row+1)<8 && (white_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row+1][white_king_column-1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(+1, 0)
if(board[white_king_row+1][white_king_column]!="PB" && board[white_king_row+1][white_king_column]!="CB" && board[white_king_row+1][white_king_column]!="BB" && board[white_king_row+1][white_king_column]!="TB" && board[white_king_row+1][white_king_column]!="DB" && (white_king_row+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row+1][white_king_column]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                         };
//(-1, +1)
if(board[white_king_row-1][white_king_column+1]!="PB" && board[white_king_row-1][white_king_column+1]!="CB" && board[white_king_row-1][white_king_column+1]!="BB" && board[white_king_row-1][white_king_column+1]!="TB" && board[white_king_row-1][white_king_column+1]!="DB"&& (white_king_row-1)>=0 && (white_king_column+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row-1][white_king_column+1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                          };
//(-1, -1)
if(board[white_king_row-1][white_king_column-1]!="PB" && board[white_king_row-1][white_king_column-1]!="CB" && board[white_king_row-1][white_king_column-1]!="BB" && board[white_king_row-1][white_king_column-1]!="TB" && board[white_king_row-1][white_king_column-1]!="DB" && (white_king_row-1)>=0 && (white_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row-1][white_king_column-1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                    };
//(-1, 0)
if(board[white_king_row-1][white_king_column]!="PB" && board[white_king_row-1][white_king_column]!="CB" && board[white_king_row-1][white_king_column]!="BB" && board[white_king_row-1][white_king_column]!="TB" && board[white_king_row-1][white_king_column]!="DB" && (white_king_row-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row-1][white_king_column]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                          };
//(0, -1)
if(board[white_king_row][white_king_column-1]!="PB" && board[white_king_row][white_king_column-1]!="CB" && board[white_king_row][white_king_column-1]!="BB" && board[white_king_row][white_king_column-1]!="TB" && board[white_king_row][white_king_column-1]!="DB" && (white_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row][white_king_column-1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                           };
//(0, +1)
if(board[white_king_row][white_king_column+1]!="PB" && board[white_king_row][white_king_column+1]!="CB" && board[white_king_row][white_king_column+1]!="BB" && board[white_king_row][white_king_column+1]!="TB" && board[white_king_row][white_king_column+1]!="DB" && (white_king_column+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[white_king_row][white_king_column+1]="RB";
board[white_king_row][white_king_column]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                           };

//RESULTADO
white_king_in_check=true;//VALOR ATUAL

if(safe_moves_counter>0)
status=true;
if(safe_moves_counter==0)
status=false;
return status;

                                          };



//NEGRAS
bool chess_game::black_check_king_escape(){
//VARIÁVEIS LOCAIS
int safe_moves_counter;//REGISTRADO O NÚMERO DE LANCES SEGUROS
bool status;//RESULTADO 

safe_moves_counter=0;//AJUSTE DE VARIÁVEIS


//PROCEDIMENTOS
//UM REI POSSUI 8 POSSUI AO TODO 8 MOVIMENTOS POSSÍVEIS
//(+1, +1)
if(board[black_king_row+1][black_king_column+1]!="PP" && board[black_king_row+1][black_king_column+1]!="CP" && board[black_king_row+1][black_king_column+1]!="BP" && board[black_king_row+1][black_king_column+1]!="TP" && board[black_king_row+1][black_king_column+1]!="DP" && (black_king_row+1)<8 && (black_king_column+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row+1][black_king_column+1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(+1, -1)
if(board[black_king_row+1][black_king_column-1]!="PP" && board[black_king_row+1][black_king_column-1]!="CP" && board[black_king_row+1][black_king_column-1]!="BP" && board[black_king_row+1][black_king_column-1]!="TP" && board[black_king_row+1][black_king_column-1]!="DP" && (black_king_row+1)<8 && (black_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row+1][black_king_column-1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(+1, 0)
if(board[black_king_row+1][black_king_column]!="PP" && board[black_king_row+1][black_king_column]!="CP" && board[black_king_row+1][black_king_column]!="BP" && board[black_king_row+1][black_king_column]!="TP" && board[black_king_row+1][black_king_column]!="DP" && (black_king_row+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row+1][black_king_column]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(-1, +1)
if(board[black_king_row-1][black_king_column+1]!="PP" && board[black_king_row-1][black_king_column+1]!="CP" && board[black_king_row-1][black_king_column+1]!="BP" && board[black_king_row-1][black_king_column+1]!="TP" && board[black_king_row-1][black_king_column+1]!="DP" && (black_king_row-1)>=0 && (black_king_column+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row-1][black_king_column+1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(-1, -1)
if(board[black_king_row-1][black_king_column-1]!="PP" && board[black_king_row-1][black_king_column-1]!="CP" && board[black_king_row-1][black_king_column-1]!="BP" && board[black_king_row-1][black_king_column-1]!="TP" && board[black_king_row-1][black_king_column-1]!="DP"  && (black_king_row-1)>=0 && (black_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row-1][black_king_column-1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(-1, 0)
if(board[black_king_row-1][black_king_column]!="PP" && board[black_king_row-1][black_king_column]!="CP" && board[black_king_row-1][black_king_column]!="BP" && board[black_king_row-1][black_king_column]!="TP" && board[black_king_row-1][black_king_column]!="DP" && (black_king_row-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row-1][black_king_column]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(0, -1)
if(board[black_king_row][black_king_column-1]!="PP" && board[black_king_row][black_king_column-1]!="CP" && board[black_king_row][black_king_column-1]!="BP" && board[black_king_row][black_king_column-1]!="TP" && board[black_king_row][black_king_column-1]!="DP" && (black_king_column-1)>=0){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row][black_king_column-1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };
//(0, +1)
if(board[black_king_row][black_king_column+1]!="PP" && board[black_king_row][black_king_column+1]!="CP" && board[black_king_row][black_king_column+1]!="BP" && board[black_king_row][black_king_column+1]!="TP" && board[black_king_row][black_king_column+1]!="DP" && (black_king_row+1)<8){
//REGISTRANDO O STATUS ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO DO REI 
board[black_king_row][black_king_column+1]="RP";
board[black_king_row][black_king_column]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++;

//RESTAURANDO O TABULEIRO EM SUA CONFIGURAÇÃO INICIAL
restore_state();

                                                   };

//RESULTADO
black_king_in_check=true;//VALOR ATUAL

if(safe_moves_counter>0)
status=true;
if(safe_moves_counter==0)
status=false;
return status;                                          };

//****************************************************************************************************************************
//FUNÇÕES QUE DETERMINAM SE É POSSÍVEL ESCAPAR DO CHEQUE COM UM MOVIMENTO DE PEÇA
//BRANCAS
bool chess_game::white_check_piece_escape(){
//VARIÁVEIS LOCAIS
int i, j;//COORDENADAS INICIAIS 
int k, l;//COORDENADAS FINAIS
int safe_moves_counter; 
bool status;

//PROCEDIMENTOS 
//ESQUADRINHANDO O TABULEIRO
for(i=0; i<8; i++){
for(j=0; j<8; j++){
//ESQUADRINHANDO O TABULEIRO EM BUSCA DE PEÇAS DAS BRANCAS
if(board[i][j]!="PB" && board[i][j]!="CB" && board[i][j]!="BB" && board[i][j]!="TB" && board[i][j]!="DB")
continue;
//CASO UMA PEÇA SEJA ENCONTRADA CHECAR POR MOVIMENTOS VÁLIDOS
//PEÃO
if(board[i][j]=="PB"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool white_pawn_move_test=validate_white_pawn_move(i, j, k, l);
if(white_pawn_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };
//CAVALO
if(board[i][j]=="CB"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool white_knight_move_test=validate_white_knight_move(i, j, k, l);
if(white_knight_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                                };

                  };
                  };
                     };

//BISPO
if(board[i][j]=="BB"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool white_bishop_move_test=validate_white_bishop_move(i, j, k, l);
if(white_bishop_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };

//TORRE
if(board[i][j]=="TB"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool white_rook_move_test=validate_white_rook_move(i, j, k, l);
if(white_rook_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };
//DAMA
if(board[i][j]=="DB"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool white_queen_move_test=validate_white_queen_move(i, j, k, l);
if(white_queen_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
white_king_status();

if(white_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };

                  };
                  };

//RESULTADO
white_king_in_check=true;//VALOR ATUAL

if(safe_moves_counter>0)
status=true;
if(safe_moves_counter==0)
status=false;
return status;
                                           };


//NEGRAS
bool chess_game::black_check_piece_escape(){
//VARIÁVEIS LOCAIS
int i, j;//COORDENADAS INICIAIS 
int k, l;//COORDENADAS FINAIS
int safe_moves_counter; 
bool status;

//PROCEDIMENTOS 
//ESQUADRINHANDO O TABULEIRO
for(i=0; i<8; i++){
for(j=0; j<8; j++){
//ESQUADRINHANDO O TABULEIRO EM BUSCA DE PEÇAS DAS NEGRAS
if(board[i][j]!="PP" && board[i][j]!="CP" && board[i][j]!="BP" && board[i][j]!="TP" && board[i][j]!="DP")
continue;
//CASO UMA PEÇA SEJA ENCONTRADA CHECAR POR MOVIMENTOS VÁLIDOS
//PEÃO
if(board[i][j]=="PP"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool black_pawn_move_test=validate_black_pawn_move(i, j, k, l);
if(black_pawn_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };
//CAVALO
if(board[i][j]=="CP"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool black_knight_move_test=validate_black_knight_move(i, j, k, l);
if(black_knight_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                                };

                  };
                  };
                     };

//BISPO
if(board[i][j]=="BP"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool black_bishop_move_test=validate_black_bishop_move(i, j, k, l);
if(black_bishop_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };

//TORRE
if(board[i][j]=="TP"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool black_rook_move_test=validate_black_rook_move(i, j, k, l);
if(black_rook_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };
//DAMA
if(board[i][j]=="DP"){
for(k=0; k<8; k++){
for(l=0; l<8; l++){
//BUSCA POR MOVIMENTOS VÁLIDOS
bool black_queen_move_test=validate_black_queen_move(i, j, k, l);
if(black_queen_move_test==true){
//CHECANDO SE UM MOVIMENTO VÁLIDO RETIRA O REI DO CHEQUE
//SALVANDO O ESTADO ATUAL DO TABULEIRO
save_state();
//TESTANDO O MOVIMENTO VÁLIDO
board[k][l]=board[i][j];
board[i][j]="  ";
black_king_status();

if(black_king_in_check==false)
safe_moves_counter++; //CONTABILIZANDO MOVIMENTOS QUE RETIRAM O REI DO CHEQUE

//RESTAURANDO O ESTADO DO TABULEIRO
restore_state();

                              };

                  };
                  };
                     };

                  };
                  };

//RESULTADO
black_king_in_check=true;//VALOR ATUAL

if(safe_moves_counter>0)
status=true;
if(safe_moves_counter==0)
status=false;
return status;
                                           };

//****************************************************************************************************************************
//FUNÇÕES QUE DETERMINA SE É CHEQUE MATE OU NÃO
//BRANCAS
bool chess_game::white_checkmate_checker(){
//VARIÁVEIS LOCAIS
bool test1, test2;
//PROCEDIMENTOS
test1=white_check_piece_escape();
test2=white_check_king_escape();

//SE HOUVE A POSSIBILIDADE DE ESCAPE NÃO É CHEQUE MATE
if(test1==true || test2==true)
checkmate=false;
else if(test1==false && test2==false)
checkmate=true;


return checkmate;
                                          };

//NEGRAS
bool chess_game::black_checkmate_checker(){
//VARIÁVEIS LOCAIS
bool test1, test2;
//PROCEDIMENTOS
test1=black_check_piece_escape();
test2=black_check_king_escape();

//SE HOUVE A POSSIBILIDADE DE ESCAPE NÃO É CHEQUE MATE
if(test1==true || test2==true)
checkmate=false;
else if(test1==false && test2==false)
checkmate=true;

return checkmate;
                                          };

//****************************************************************************************************************************
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
