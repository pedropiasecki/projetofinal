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

typedef struct {
    string nomeTime;
    int golsMarcados;
    int golsSofridos;
    int vitorias;
    int empates;
    int derrotas;
    int titulos;
} Time;

void clearScreen();
void preencheJogadores(vector<Jogador>& jogadores);
void preencheTime(Time& clube);
bool compareNome(const Jogador& a, const Jogador& b);
string toLower(const string& str);
int buscaBinaria(const vector<Jogador>& jogadores, const string& nome, int esquerda, int direita);
void buscarJogador(vector<Jogador>& jogadores);
void listarJogadores(const vector<Jogador>& jogadores);
void desempenhoJogador(vector<Jogador>& jogadores, int indice);
void mostrarTitulos();
void mostrarDesempenho(Time& clube);
void insertionSort(vector<Jogador>& jogadores, int nmr);
void mostrarArtilharia(const vector<Jogador>& jogadores);
void gerencia(vector<Jogador>& jogadores);
void excluirJogador(vector<Jogador>& jogadores);
bool jogadorExiste(const vector<Jogador>& jogadores, const string& nome);
void addNovoJogador(vector<Jogador>& jogadores);
void lista(const vector<Jogador>& jogadores, const Time& clube);


#endif