#include "dados.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
    clearScreen();
    Time clube = {};
    vector<Jogador> jogadores;
    preencheJogadores(jogadores);
    preencheTime(clube);

   int op = 0;
    
    while (op != 8) {
        cout << "1. Titulos" << endl;
        cout << "2. Desempenho" << endl;
        cout << "3. Artilharia" << endl;
        cout << "4. Listar Jogadores" << endl;
        cout << "5. Buscar Jogador" << endl;
        cout << "6. Gerenciar jogadores" << endl;
        cout << "7. Gerar relatorio" << endl;
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
                mostrarDesempenho(clube);
                break;
            case 3:
                mostrarArtilharia(jogadores);
                break;
            case 4:
                listarJogadores(jogadores);
                break;
            case 5:
                buscarJogador(jogadores);
                break;
            case 6:
                gerencia(jogadores);
                break;
            case 7:
                lista(jogadores, clube);
                break;
            case 8:
                cout << "Programa finalizado." << endl;
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}