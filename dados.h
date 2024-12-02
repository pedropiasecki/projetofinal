#ifndef DADOS_H
#define DADOS_H

#include <string>
#include <vector>

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

void setConsoleColor(int color);
void preencheJogadores(vector<Jogador>& jogadores);
bool compareByName(const Jogador& a, const Jogador& b);
string toLower(const string& str);
int buscaBinaria(const vector<Jogador>& jogadores, const string& nome);
void listarJogadores(const vector<Jogador>& jogadores);
void buscarJogador(vector<Jogador>& jogadores);
void desempenhoJogador(vector<Jogador>& jogadores, int indice);

#endif // DADOS_H