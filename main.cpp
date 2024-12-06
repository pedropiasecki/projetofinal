#include "dados.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    system("cls");
    vector<Jogador> jogadores;
    preencheJogadores(jogadores); // Preenche a lista de jogadores

   int op = 0;
    
    while (op != 8) {
        cout << "1. Titulos" << endl;
        cout << "2. Tabela" << endl;
        cout << "3. Proximos jogos" << endl;
        cout << "4. Desempenho" << endl;
        cout << "5. Artilharia" << endl;
        cout << "6. Listar Jogadores" << endl;
        cout << "7. Buscar Jogador" << endl;
        cout << "8. Sair" << endl;
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
                mostrarTitulos();
                break;
            case 2:
                mostrarTabelas();
                break;
            case 3:
                mostrarJogos();
                break;
            case 4:
                mostrarDesempenho(jogadores);
                break;
            case 5:
                mostrarArtilharia(jogadores);
                break;
            case 6:
                listarJogadores(jogadores);
                break;
            case 7:
                buscarJogador(jogadores);
                break;
            case 8:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}