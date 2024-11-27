#ifndef DADOS_H
#define DADOS_H

#include <vector>
#include <string>

using namespace std;

typedef struct {
    int gols;
    int assis;
    int partidas;
    int vitorias;
    int derrotas;
    int empates;
} Estatistica;

typedef struct {
    string nome;
    string pos;
    int idade;
    Estatistica desempenho;
} Jogador;

void menu(int highlight);
void menuJogadores(int highlightJogadores, vector<Jogador>& jogadores, int nmr);
void mostrarEstatisticas(const Jogador& jogador);
void desempenhoTime(vector<Jogador>& jogadores);
void preencheJogadores(vector<Jogador>& jogadores);
void galeria();
void setConsoleColor(int color);
void mostrarHistoria();

#endif // DADOS_H