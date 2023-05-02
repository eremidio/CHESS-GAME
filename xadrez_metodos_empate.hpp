//ESTE ARQUIVO CONTÉM AS FUNÇÕES QUE CALCULAM AS REGRAS DE EMPATE DE UM JOGO DE XADREZ

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"xadrez_classe.hpp"
using namespace std;

//****************************************************************************************************************************
//FUNÇÕES QUE CALCULAM SE HÁ OU NÃO EMPATE NO JOGO
//REGRA DOS 50 LANCES
void chess_game::fifth_rule_draw(){
if(nor_pawn_capture>100)
draw_game=true;
                                  };

//EMPATE POR REPETIÇÃO
void chess_game::repetition_draw(){
//VARIÁVEIS LOCAIS
int total_moves;//NÚMERO TOTAL DE LANCES REALIZADO ATÉ UM DADO MOMENTO
//PROCEDIMENTOS
total_moves=move_list.size()+1;
if(total_moves<12)
return;

if(move_list[total_moves]==move_list[total_moves-4] && move_list[total_moves]==move_list[total_moves-8]){
if(move_list[total_moves-1]==move_list[total_moves-5] && move_list[total_moves]==move_list[total_moves-9]){
if(move_list[total_moves-2]==move_list[total_moves-6] && move_list[total_moves]==move_list[total_moves-10]){
if(move_list[total_moves-3]==move_list[total_moves-7] && move_list[total_moves]==move_list[total_moves-11]){
draw_game=true;
                                                                                                           };
                                                                                                           };
                                                                                                          };
                                                                                                        };
                                  };

//EMPATE POR COMUM ACORDO
void chess_game::common_agreement_draw(){
//VARIÁVEIS LOCAIS
string token;
cout<<"Jogador você aceita a proposta de empate do seu oponente?\n(Digite 's' para aceitar a proposta de empate ou 'n' para recusar).\n";
cin>>token;
if(token=="s")
draw_game=true;
                                        };

//EMPATE POR INSUFICIÊNCIA DE MATERIAL
void chess_game::insufficient_material_draw(){
//VARIÁVEIS LOCAIS
int i, j;
int rb_counter, pb_counter, cb_counter, bb_counter, tb_counter, db_counter;//CONTAGEM DE PEÇAS DAS BRANCAS
int rp_counter, pp_counter, cp_counter, bp_counter, tp_counter, dp_counter;//CONTAGEM DE PEÇAS DAS NEGRAS

//AJUSTE DE VARIÁVEIS
rb_counter=0;
pb_counter=0;
cb_counter=0;
bb_counter=0;
tb_counter=0;
db_counter=0;
rp_counter=0;
pp_counter=0;
cp_counter=0;
bp_counter=0;
tp_counter=0;
dp_counter=0;

//PROCEDIMENTOS 
//CONTAGEM DE PEÇAS NO TABULEIRO
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
if(board[i][j]=="RB")
rb_counter++;
if(board[i][j]=="PB")
pb_counter++;
if(board[i][j]=="CB")
cb_counter++;
if(board[i][j]=="BB")
bb_counter++;
if(board[i][j]=="TB")
tb_counter++;
if(board[i][j]=="DB")
db_counter++;
if(board[i][j]=="RP")
rp_counter++;
if(board[i][j]=="PP")
pp_counter++;
if(board[i][j]=="CP")
cp_counter++;
if(board[i][j]=="BP")
bp_counter++;
if(board[i][j]=="TP")
tp_counter++;
if(board[i][j]=="DP")
dp_counter++;

                  };
                  };

//CHECANDO EVENTUAIS CONDIÇÕES DE EMPATES
//REI CONTRA REI
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==0 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
//REI E BISPO CONTRA REI
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==1 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==0 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==1 && tp_counter==0 && dp_counter==0)
draw_game=true;
//REI E CAVALO CONTRA REI
if(rb_counter== 1 && pb_counter==0 && cb_counter==1 && bb_counter==0 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==0 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==1 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
//REI E BISPO CONTRA REI E BISPO
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==1 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==1 && tp_counter==0 && dp_counter==0)
draw_game=true;
//REI E CAVALO CONTRA REI E CAVALO
if(rb_counter== 1 && pb_counter==0 && cb_counter==1 && bb_counter==1 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==1 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
//REI E BISPO CONTRA REI E CAVALO
if(rb_counter== 1 && pb_counter==0 && cb_counter==0 && bb_counter==1 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==1 && bp_counter==0 && tp_counter==0 && dp_counter==0)
draw_game=true;
if(rb_counter== 1 && pb_counter==0 && cb_counter==1 && bb_counter==0 && tb_counter==0 && db_counter==0 && rp_counter==1 && pp_counter==0 && cp_counter==0 && bp_counter==1 && tp_counter==0 && dp_counter==0)
draw_game=true;

                                             };

//EMPATE POR AFOGAMENTO
//BRANCAS
void chess_game::white_stalemate_draw(){
//VARIAVEIS LOCAIS
int i, j, k, l;
int allowable_moves;//VARIÁVEIS DE CONTAGEM DE MOVIMENTOS LEGAIS

allowable_moves=0; //AJUSTE DE VARIÁVEL

//PROCEDIMENTOS
//ESQUADRINHANDO O TABULEIRO EM BUSCA DE MOVIMENTOS VÁLIDOS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
//REI
if(board[i][j]=="RB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_king_test1=validate_white_king_move(i, j, k, l);
bool white_king_test2=white_piece_pinned(i, j, k, l);
if(white_king_test1==true && white_king_test2==false)
allowable_moves++;
                  };
                  };
                     };
//PEÃO
if(board[i][j]=="PB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_pawn_test1=validate_white_pawn_move(i, j, k, l);
bool white_pawn_test2=white_piece_pinned(i, j, k, l);
if(white_pawn_test1==true && white_pawn_test2==false)
allowable_moves++;
                  };
                  };
                     };
//CAVALO
if(board[i][j]=="CB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_knight_test1=validate_white_knight_move(i, j, k, l);
bool white_knight_test2=white_piece_pinned(i, j, k, l);
if(white_knight_test1==true && white_knight_test2==false)
allowable_moves++;
                  };
                  };
                     };
//BISPO
if(board[i][j]=="BB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_bishop_test1=validate_white_bishop_move(i, j, k, l);
bool white_bishop_test2=white_piece_pinned(i, j, k, l);
if(white_bishop_test1==true && white_bishop_test2==false)
allowable_moves++;
                  };
                  };
                     };
//TORRE
if(board[i][j]=="TB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_rook_test1=validate_white_rook_move(i, j, k, l);
bool white_rook_test2=white_piece_pinned(i, j, k, l);
if(white_rook_test1==true && white_rook_test2==false)
allowable_moves++;
                  };
                  };
                     };
//DAMA
if(board[i][j]=="DB"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool white_queen_test1=validate_white_queen_move(i, j, k, l);
bool white_queen_test2=white_piece_pinned(i, j, k, l);
if(white_queen_test1==true && white_queen_test2==false)
allowable_moves++;
                  };
                  };
                     };

                  };
                  };

//RESULTADO
if(allowable_moves==0)
draw_game=true;

                                       };
//NEGRAS
void chess_game::black_stalemate_draw(){
//VARIAVEIS LOCAIS
int i, j, k, l;
int allowable_moves;//VARIÁVEIS DE CONTAGEM DE MOVIMENTOS LEGAIS

allowable_moves=0; //AJUSTE DE VARIÁVEL

//PROCEDIMENTOS
//ESQUADRINHANDO O TABULEIRO EM BUSCA DE MOVIMENTOS VÁLIDOS
for(i=0; i<8; ++i){
for(j=0; j<8; ++j){
//REI
if(board[i][j]=="RP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_king_test1=validate_black_king_move(i, j, k, l);
bool black_king_test2=black_piece_pinned(i, j, k, l);
if(black_king_test1==true && black_king_test2==false)
allowable_moves++;
                  };
                  };
                     };
//PEÃO
if(board[i][j]=="PP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_pawn_test1=validate_black_pawn_move(i, j, k, l);
bool black_pawn_test2=black_piece_pinned(i, j, k, l);
if(black_pawn_test1==true && black_pawn_test2==false)
allowable_moves++;
                  };
                  };
                     };
//CAVALO
if(board[i][j]=="CP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_knight_test1=validate_black_knight_move(i, j, k, l);
bool black_knight_test2=black_piece_pinned(i, j, k, l);
if(black_knight_test1==true && black_knight_test2==false)
allowable_moves++;
                  };
                  };
                     };
//BISPO
if(board[i][j]=="BP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_bishop_test1=validate_black_bishop_move(i, j, k, l);
bool black_bishop_test=black_piece_pinned(i, j, k, l);
if(black_bishop_test1==true && black_bishop_test1==false)
allowable_moves++;
                  };
                  };
                     };
//TORRE
if(board[i][j]=="TP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_rook_test1=validate_black_rook_move(i, j, k, l);
bool black_rook_test2=black_piece_pinned(i, j, k, l);
if(black_rook_test1==true && black_rook_test2==false )
allowable_moves++;
                  };
                  };
                     };
//DAMA
if(board[i][j]=="DP"){
for(k=0; k<8; ++k){
for(l=0; l<8; ++l){
bool black_queen_test1=validate_black_queen_move(i, j, k, l);
bool black_queen_test2=black_piece_pinned(i, j, k, l);
if(black_queen_test1==true && black_queen_test2==false)
allowable_moves++;
                  };
                  };
                     };

                  };
                  };

//RESULTADO
if(allowable_moves==0)
draw_game=true;

                                       };

//****************************************************************************************************************************
//FUNÇÃO QUE INFORMA SE HOUVE EMPATE NO JOGO
void chess_game::draw_warning(){
cout<<"Jogo terminou empatado!\n";
                               };
