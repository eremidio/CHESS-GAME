//ESTE ARQUIVO CONTÉM AS FUNÇÕES QUE AJUSTAM O TABULEIRO DO JOGO E EXECUTAM O LOOP PRINCIPAL DE UMA PARTIDA

/*CABEÇALHO*/
#pragma once
#include<iostream>
#include<string>
#include<cstdio>
#include"xadrez_classe.hpp"
using namespace std;

//****************************************************************************************************************************
//FUNÇÃO QUE AJUSTA O JOGO DE XADREZ EM SUA CONFIGURAÇÃO INICIAL
void chess_game::setup_game(){
set_default_values();
set_board();
print_board();
                             };
//****************************************************************************************************************************
//FUNÇÃO QUE EXECUTA O LOOP PRINCIPAL DO JOGO
void chess_game::mainloop(){

//LOOP PRINCIPAL
while(true){

//BRANCAS REALIZAM O LANCE PRIMEIRO
white_to_move();
print_board();

//EM CASO DE EMPATE OU CHEQUE O JOGO É ENCERRADO
//CHEQUEMATE
if(checkmate==true)
break;

//EMPATE
//PROPONDO EMPATE POR REPETIÇÃO
cout<<"::: (Pressione enter para continuar, digite 'e' para propor empate ou digite 'a' para para abandonar o jogo) ";
int flag1=cin.get();
char wd = getchar();

if(wd=='e')
common_agreement_draw();
if(wd=='a')
resignate();

//ABANDONANDO O JOGO
if(resignation==true)
break;


//CHECANDO OUTROS CRITÉRIOS DE EMPATE
fifth_rule_draw();
repetition_draw();
insufficient_material_draw();
black_stalemate_draw();

if(draw_game==true){
draw_warning();
break;
                   };

//CASO NÃO HAJA EMPATE OU CHEQUEMATE AS NEGRAS FAZEM O SEU LANCE
black_to_move();
print_board();

//EM CASO DE EMPATE OU CHEQUE O JOGO É ENCERRADO
//CHEQUEMATE
if(checkmate==true)
break;

//EMPATE
//PROPONDO EMPATE POR REPETIÇÃO
cout<<"::: (Pressione enter para continuar, digite 'e' para propor empate ou digite 'a' para para abandonar o jogo) ";
int flag2=cin.get();
char bd = getchar();
if(bd=='e')
common_agreement_draw();
if(bd=='a')
resignate();
//ABANDONANDO O JOGO
if(resignation==true)
break;


//CHECANDO OUTROS CRITÉRIOS DE EMPATE
fifth_rule_draw();
repetition_draw();
insufficient_material_draw();
white_stalemate_draw();
if(draw_game==true){
draw_warning();
break;
                   };




           };//FIM DO LOOP PRINCIPAL
                           };
