#include "dados.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    vector<Jogador> jogadores;

    preencheJogadores(jogadores);

    int nmrJogadores = jogadores.size();
    int highlightJogadores = 0;
    int highlight = 0;
    int choice = 0;

    while (true) {
        menu(highlight);

        int key = _getch();

        if (key == 224) {
            key = _getch();
            switch (key) {
                case 72:
                    highlight--;
                    if (highlight < 0) highlight = 3;
                    break;
                case 80:
                    highlight++;
                    if (highlight > 6) highlight = 0;
                    break;
            }
        } else if (key == 13) {
            choice = highlight;
            switch (choice) {
                case 0:
                    system("cls");
                    menuJogadores(highlightJogadores, jogadores, nmrJogadores);
                    break;
                case 1:
                    galeria();
                    break;
                case 2:
                    system("cls");
                    mostrarHistoria();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    cout << "Finalizado" << endl;
                    return 0;
                default:
                    break;
            }
            system("pause");
        }
        system("cls"); // Limpa a tela
    }

    return 0;
}