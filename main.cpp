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
        cout << "1. Buscar Jogador" << endl;
        cout << "2. Listar Todos os Jogadores" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";

        // Ler a entrada do usuário como string
        string input;
        cin >> input;

        // Tentar converter a entrada para um número inteiro
        try {
            op = stoi(input);
        } catch (invalid_argument&) {
            cout << endl << "Entrada invalida. Por favor, insira um numero inteiro." << endl;
            continue; // Voltar para o início do loop
        } catch (out_of_range&) {
            cout << endl << "Numero fora do intervalo permitido. Tente novamente." << endl;
            continue; // Voltar para o início do loop
        }

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

    return 0;
}