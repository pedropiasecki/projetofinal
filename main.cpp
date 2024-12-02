#include "dados.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    vector<Jogador> jogadores;
    preencheJogadores(jogadores); // Preenche a lista de jogadores

    int op = 0;
    while (op != 3) {
        cout << endl << "Menu:" << endl;
        cout << "1. Buscar Jogador" << endl;;
        cout << "2. Listar Todos os Jogadores" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        
        int op;
        cin >> op;

        switch (op) {
            case 1:
                buscarJogador(jogadores);
                break;
            case 2:
                listarJogadores(jogadores);
                break;
            case 3:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}