#include "dados.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

enum ConsoleColor {
    BLACK = 0,
    DARK_BLUE = 1,
    DARK_GREEN = 2,
    DARK_CYAN = 3,
    DARK_RED = 4,
    DARK_MAGENTA = 5,
    DARK_YELLOW = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};


void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void preencheJogadores(vector<Jogador>& jogadores) {
    jogadores = {
        {"Neymar", "Atacante", 32, {30, 15, 50, 25, 15, 10}},
        {"Messi", "Atacante", 37, {45, 20, 60, 35, 15, 10}},
        {"Ronaldo", "Atacante", 39, {40, 10, 55, 30, 20, 5}},
        {"Kante", "Meio-campo", 33, {10, 12, 60, 30, 20, 10}},
        {"Mbappe", "Atacante", 25, {50, 20, 55, 30, 20, 5}}
    };
}

// Função de comparação para ordenar jogadores pelo nome
bool compareByName(const Jogador& a, const Jogador& b) {
    return a.nome < b.nome;
}

// Função para tornar a busca insensível a maiúsculas e minúsculas
string toLower(const string& str) {
    string lowerStr;
    for (char c : str) {
        lowerStr += tolower(c);
    }
    return lowerStr;
}

// Função de busca binária
int buscaBinaria(const vector<Jogador>& jogadores, const string& nome) {
    int esquerda = 0;
    int direita = jogadores.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (toLower(jogadores[meio].nome) == toLower(nome)) {
            return meio; // Retorna o índice do jogador encontrado
        }

        if (toLower(jogadores[meio].nome) < toLower(nome)) {
            esquerda = meio + 1; // Busca na metade direita
        } else {
            direita = meio - 1; // Busca na metade esquerda
        }
    }

    return -1; // Jogador não encontrado
}

// Função para listar todos os jogadores
void listarJogadores(const vector<Jogador>& jogadores) {
    system("cls");
    cout << endl << "Jogadores:" << endl;
    for (const auto& jogador : jogadores) {
        cout << "- " << jogador.nome << endl;
    }
    cout<<endl;
}

// Função para buscar jogador e exibir suas estatísticas
void buscarJogador(vector<Jogador>& jogadores) {
    system("cls");
    string nome;
    cout << endl << "Digite o nome do jogador que deseja buscar (ou parte do nome): ";
    cin.ignore();
    getline(cin, nome);

    // Ordenar o vetor de jogadores pelo nome
    sort(jogadores.begin(), jogadores.end(), compareByName);

    // Listar jogadores que correspondem à busca
    cout << endl << "Resultados da busca para \"" << nome << "\":\n";
    bool encontrado = false;
    for (const auto& jogador : jogadores) {
        if (toLower(jogador.nome).find(toLower(nome)) != string::npos) {
            cout << "- " << jogador.nome << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << endl << "Nenhum jogador encontrado com esse nome." << endl;
    } else {
        cout << endl << "Digite o nome exato do jogador para ver suas estatisticas: ";
        getline(cin, nome);
        int indice = buscaBinaria(jogadores, nome);

        if (indice != -1) {
            cout<<endl;
            desempenhoJogador(jogadores, indice);
        } else {
            cout << "Jogador nao encontrado." << endl;
        }
    }
}

void desempenhoJogador(vector<Jogador>& jogadores, int indice) {
    system("cls");
    Jogador jogador = jogadores[indice];
    cout << "Nome: " << jogador.nome << endl;
    cout << "Posicao: " << jogador.pos << endl;
    cout << "Idade: " << jogador.idade << endl;
    cout << "Gols: " << jogador.desempenho.gols << endl;
    cout << "Assistencias: " << jogador.desempenho.assis << endl;
    cout << "Partidas: " << jogador.desempenho.partidas << endl;
    cout << "Vitorias: " << jogador.desempenho.vitorias << endl;
    cout << "Derrotas: " << jogador.desempenho.derrotas << endl;
    cout << "Empates: " << jogador.desempenho.empates << endl << endl;
}