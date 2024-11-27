#include "dados.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

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

void galeria() {
    system("cls");
    setConsoleColor(WHITE);
    cout << "+--------------------------TITULOS OFICIAIS-------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "+-----------------------------HONRARIAS-----------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "|           COMPETICAO           |   TITULOS    |     TEMPORADAS    |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "| Triplice Coroa Internacional          1          2006             |" << endl;
    cout << "+-----------------------------MUNDIAIS------------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "|           COMPETICAO           |   TITULOS    |     TEMPORADAS    |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "| Mundial de Clubes FIFA                1          2006             |" << endl;
    cout << "+-------------------------INTERCONTINENTAIS-------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "|           COMPETICAO           |   TITULOS    |     TEMPORADAS    |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "| Copa Suruga Bank                      1          2009             |" << endl;
    cout << "+---------------------------CONTINENTAIS----------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "|           COMPETICAO           |   TITULOS    |     TEMPORADAS    |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "| Copa Lbertadores da America           2          2006 e 2010      |" << endl;
    cout << "| Copa Sul Americana                    1          2008             |" << endl;
    cout << "| Recopa Sul-americana                  2          2007 e 2011      |" << endl;
    cout << "| Copa Sul Americana                    1          2008             |" << endl;
    cout << "+-----------------------------NACIONAIS-----------------------------+" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "|           COMPETICAO           |   TITULOS    |     TEMPORADAS    |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    cout << "| Campeonato Brasileiro                 3        1975, 1976 e 1979  |" << endl;
    cout << "| Copa do Brasil                        1          1992             |" << endl;
    cout << "| Torneio Heleno Nunes                  1          1984             |" << endl;
    cout << "+-------------------------------------------------------------------+" << endl;
    setConsoleColor(LIGHT_GRAY);
}

void menu(int highlight) {
    string options[6] = {"Jogadores", "Galeria", "Historia", "Partidas", "Tabela", "Sair"};
    setConsoleColor(RED);
    cout << "+-----------------------------------------+" << endl;
    cout << "|      ";
    setConsoleColor(DARK_GREEN);
    cout << "SPORT";
    setConsoleColor(DARK_RED);
    cout << " CLUBE";
    setConsoleColor(DARK_YELLOW);
    cout << " INTERNACIONAL";
    setConsoleColor(RED);
    cout << "          |" << endl;
    cout << "+-----------------------------------------+" << endl;
    setConsoleColor(LIGHT_GRAY);
    
    for (int i = 0; i < 6; i++) {
        if (i == highlight) {
            setConsoleColor(YELLOW);
            cout << "           > " << options[i] << " <" << endl;
            setConsoleColor(LIGHT_GRAY);
        } else {
            cout << "             " << options[i] << "  " << endl;
        }
    }
    setConsoleColor(RED);
    cout << "+-----------------------------------------+" << endl;
    setConsoleColor(LIGHT_GRAY);
}

void menuJogadores(int highlightJogadores, vector<Jogador>& jogadores, int nmr) {
    vector<string> optionsJogadores(nmr);
    for (int i = 0; i < nmr; i++) {
        optionsJogadores[i] = jogadores[i].nome;
    }

    while (true) {
        system("cls");
        setConsoleColor(WHITE);
        cout << "+-----------------------------------------+" << endl;
        cout << "|               JOGADORES                 |" << endl;
        cout << "+-----------------------------------------+" << endl;

        // Exibe o menu de jogadores, com o jogador destacado
        for (int i = 0; i < nmr; i++) {
            if (i == highlightJogadores) {
                setConsoleColor(YELLOW);  // Destaca o jogador selecionado
                cout << "           > " << optionsJogadores[i] << " <" << endl;
                setConsoleColor(LIGHT_GRAY);
            } else {
                cout << "             " << optionsJogadores[i] << "  " << endl;
            }
        }
        
        cout << "+-----------------------------------------+" << endl;
        setConsoleColor(DARK_GRAY);
        cout<< "Pressione Esc para voltar ao menu principal..." << endl;
        setConsoleColor(LIGHT_GRAY);

        // Captura a entrada do teclado
        int key = _getch();
        if (key == 224) {
            key = _getch();
            switch (key) {
                case 72:  // Tecla para cima
                    highlightJogadores--;
                    if (highlightJogadores < 0) highlightJogadores = nmr - 1;
                    break;
                case 80:  // Tecla para baixo
                    highlightJogadores++;
                    if (highlightJogadores >= nmr) highlightJogadores = 0;
                    break;
            }
        } else if (key == 13) {  // Enter
            system("cls");
            mostrarEstatisticas(jogadores[highlightJogadores]);  // Exibe as estatísticas do jogador
            setConsoleColor(DARK_GRAY);
            cout << "Pressione qualquer tecla para voltar ao menu de jogadores..." << endl;
            setConsoleColor(LIGHT_GRAY);
            _getch();  // Espera o usuário pressionar uma tecla para voltar
        } else if (key == 27) {  // ESC para voltar ao menu principal
            break;
        }
    }
}

void mostrarEstatisticas(const Jogador& jogador) {
    cout << "Jogador: " << jogador.nome << endl;
    cout << "Posicao: " << jogador.pos << endl;
    cout << "Idade: " << jogador.idade << endl;
    cout << "Gols: " << jogador.desempenho.gols << endl;
    cout << "Assistencias: " << jogador.desempenho.assis << endl;
    cout << "Partidas: " << jogador.desempenho.partidas << endl;
    cout << "Vitorias: " << jogador.desempenho.vitorias << endl;
    cout << "Derrotas: " << jogador.desempenho.derrotas << endl;
    cout << "Empates: " << jogador.desempenho.empates << endl;
    cout << "+--------------------+" << endl;
}

void desempenhoTime(vector<Jogador>& jogadores) {
    // usar locação dinamica e aritmetica de ponteiros aqui
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

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void mostrarHistoria() {
    cout << "+-----------------------------------------+" << endl;
    cout << "|                 HISTORIA                |" << endl;
    cout << "+-----------------------------------------+" << endl;
}