#include "dados.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void preencheJogadores(vector<Jogador>& jogadores) {
    jogadores = {
        {"Fernandao", "Atacante", 28, {20, 10, 50, 30, 10, 10}},  
        {"Iarley", "Atacante", 32, {15, 8, 45, 20, 15, 10}},
        {"Sandro", "Meio-campo", 22, {5, 7, 40, 25, 10, 5}},
        {"Alex", "Meio-campo", 25, {12, 15, 48, 28, 10, 10}},
        {"Robson de Souza", "Zagueiro", 28, {1, 0, 50, 25, 15, 10}},
        {"Tinga", "Meio-campo", 30, {8, 6, 45, 25, 15, 5}},
        {"Clemer", "Goleiro", 35, {0, 0, 45, 25, 15, 5}},
        {"Nilson", "Zagueiro", 31, {2, 1, 45, 25, 15, 5}},
        {"Ricardinho", "Meio-campo", 28, {2, 10, 50, 27, 15, 8}},
        {"Edu", "Atacante", 28, {10, 5, 40, 20, 15, 5}},
        {"Luizao", "Zagueiro", 30, {0, 0, 45, 25, 15, 5}},
        {"Marcelo", "Lateral-esquerdo", 26, {1, 3, 30, 15, 10, 5}},
        {"Chicao", "Meio-campo", 27, {4, 5, 35, 18, 12, 5}},
        {"Fabio Santos", "Lateral-direito", 23, {2, 1, 25, 12, 8, 5}},
        {"Vitor", "Goleiro", 29, {0, 0, 5, 3, 2, 0}},
        {"Eduardo Costa", "Meio-campo", 29, {1, 3, 35, 18, 12, 5}},
        {"Gabriel", "Lateral-direito", 25, {0, 2, 30, 18, 10, 5}},
        {"Dalessandro", "Meio-campo", 25, {8, 9, 43, 22, 15, 6}},
        {"Sergio", "Atacante", 24, {7, 2, 25, 12, 8, 5}},
        {"Daniel", "Zagueiro", 29, {0, 0, 20, 10, 7, 3}},
        {"Cesar", "Zagueiro", 25, {0, 0, 15, 7, 5, 3}},
        {"Junior", "Lateral-esquerdo", 27, {0, 2, 20, 10, 5, 5}},
        {"Leandro", "Meio-campo", 30, {2, 4, 28, 14, 8, 6}},
        {"Edson", "Atacante", 26, {6, 3, 20, 10, 7, 3}},
        {"Patric", "Zagueiro", 23, {1, 0, 15, 5, 6, 4}}
    };
}

void preencheTime(Time& clube) {
    clube = {"Internacional", 90, 40, 28, 12, 8, 3};
}

// comparação para ordenar jogadores pelo nome
bool compareNome(const Jogador& a, const Jogador& b) {
    return a.nome < b.nome;
}

// busca para Aa
string toLower(const string& str) {
    string lowerStr;
    for (char c : str) {
        lowerStr += tolower(c);
    }
    return lowerStr;
}

int buscaBinaria(const vector<Jogador>& jogadores, const string& nome, int esquerda, int direita) {
    // se o intervalo for inválido, o jogador não foi encontrado
    if (esquerda > direita) {
        return -1;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    // verifica se o nome do jogador no meio corresponde ao nome procurado
    if (toLower(jogadores[meio].nome) == toLower(nome)) {
        return meio; // Retorna o índice do jogador encontrado
    }

    // se o nome no meio é menor que o nome procurado, busca na metade direita
    if (toLower(jogadores[meio].nome) < toLower(nome)) {
        return buscaBinaria(jogadores, nome, meio + 1, direita);
    } else {
        // caso contrário, busca na metade esquerda
        return buscaBinaria(jogadores, nome, esquerda, meio - 1);
    }
}

// buscar jogador e exibir suas estatísticas
void buscarJogador(vector<Jogador>& jogadores) {
    cout << "\033[2J\033[1;1H";
    string nome;
    cout << "Digite o nome do jogador que deseja buscar (ou parte do nome): ";
    cin.ignore();
    getline(cin, nome);

    // Ordenar o vetor de jogadores pelo nome
    sort(jogadores.begin(), jogadores.end(), compareNome);

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
        cout << endl << "Nenhum jogador encontrado com esse nome." << endl << endl;
    } else {
        cout << endl << "Digite o nome exato do jogador para ver suas estatisticas: ";
        getline(cin, nome);
        int indice = buscaBinaria(jogadores, nome, 0, jogadores.size() - 1);

        if (indice != -1) {
            cout<<endl;
            desempenhoJogador(jogadores, indice);
        } else {
            cout << "Jogador nao encontrado." << endl << endl;
        }
    }
}

void listarJogadores(const vector<Jogador>& jogadores) {
    cout << "\033[2J\033[1;1H";
    cout << endl << "Jogadores:" << endl;
    for (const auto& jogador : jogadores) {
        cout << "- " << jogador.nome << endl;
    }
    cout<<endl;
}

void desempenhoJogador(vector<Jogador>& jogadores, int indice) {
    cout << "\033[2J\033[1;1H";
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

void mostrarTitulos() {
    cout << "\033[2J\033[1;1H";
    cout << "Campeonato Brasileiro: 3 titulos (1975, 1976, 1979)" << endl;
    cout << "Copa do Brasil: 1 titulo (1992)" << endl;
    cout << "Copa Libertadores da America: 2 titulos (2006, 2010)" << endl;
    cout << "Recopa Sul-Americana: 2 titulos (2007, 2011)" << endl;
    cout << "Copa Sul-Americana: 1 titulo (2008)" << endl;
    cout << "Copa Suruga Bank: 1 titulo (2009)" << endl;
    cout << "Campeonato Gaucho: 45 titulos (1927, 1934, 1940, 1941, 1942, 1943, 1944, 1945, 1947, 1948, 1950, 1951, 1952, 1953, 1955, 1961, 1969, 1970, 1971, 1972, 1973, 1974, 1975, 1976, 1978, 1981, 1982, 1983, 1984, 1991, 1992, 1994, 1997, 2002, 2003, 2004, 2005, 2008, 2009, 2011, 2012, 2013, 2014, 2015, 2016)" << endl;
    cout << "Supercampeonato Gaucho: 1 titulo (2002)" << endl;
    cout << "Torneio Heleno Nunes: 1 titulo (1984)" << endl;
    cout << "Copa Federacao Gaucha de Futebol: 1 titulo (2009)" << endl << endl;
    
}

void mostrarTabelas() {
    cout << "\033[2J\033[1;1H";
    int op = 0;
    
    while (op != 5) {
        cout << "1. Brasileirao" << endl;
        cout << "2. Gaucho" << endl;
        cout << "3. Copa do Brasil" << endl;
        cout << "4. Libertadores" << endl;
        cout << "5. Voltar ao menu" << endl;
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
                brasileirao();
                break;
            case 2:
                gaucho();
                break;
            case 3:
                cdb();
                break;
            case 4:
                libertadores();
                break;
            case 5:
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
    cout << "\033[2J\033[1;1H";
}

void brasileirao() {
    cout << "\033[2J\033[1;1H";
    cout << "TESTE" << endl;

    cout << endl;

}

void gaucho() {
    cout << "\033[2J\033[1;1H";
    cout << "TESTE" << endl;

    cout << endl;

}

void cdb() {
    cout << "\033[2J\033[1;1H";
    cout << "TESTE" << endl;

    cout << endl;

}

void libertadores() {
    cout << "\033[2J\033[1;1H";
    cout << "TESTE" << endl;

    cout << endl;

}

void mostrarJogos() {
    cout << "\033[2J\033[1;1H";
    cout << "Proximos jogos: " << endl;

    cout << endl;
}

void mostrarDesempenho(Time& clube) { 
    cout << "\033[2J\033[1;1H";
    cout << "Desempenho Temporada 2024" << endl;

    int* desempenho = new int[6];

    desempenho[0] = clube.golsMarcados;
    desempenho[1] = clube.golsSofridos;
    desempenho[2] = clube.vitorias;
    desempenho[3] = clube.empates;
    desempenho[4] = clube.derrotas;
    desempenho[5] = clube.titulos;

    cout << "Time: " << clube.nomeTime << endl;
    cout << "Gols Marcados: " << *(desempenho + 0) << endl;
    cout << "Gols Sofridos: " << *(desempenho + 1) << endl;
    cout << "Vitorias: " << *(desempenho + 2) << endl;
    cout << "Empates: " << *(desempenho + 3) << endl;
    cout << "Derrotas: " << *(desempenho + 4) << endl;
    cout << "Titulos Conquistados: " << *(desempenho + 5) << endl;

    // saldo de gols
    int saldoGols = *(desempenho + 0) - *(desempenho + 1);
    cout << "Saldo de Gols: " << saldoGols << endl;

    // aproveitamento
    double aproveitamento = (double)*(desempenho + 2) / ( *(desempenho + 2) + *(desempenho + 3) + *(desempenho + 4) ) * 100;
    cout << "Indice de Aproveitamento: " << aproveitamento << "%" << endl;

    delete[] desempenho;

    cout << endl;
}


void insertionSort(vector<Jogador>& jogadores, int nmr) {
    for (size_t i = 1; i < jogadores.size(); ++i) {
        Jogador key = jogadores[i];
        int j = i - 1;
        
        // ordenamento para gols (1) e assistencias (0)
        if (nmr == 1) {
            while (j >= 0 && jogadores[j].desempenho.gols < key.desempenho.gols) {
                jogadores[j + 1] = jogadores[j];
                --j;
            }
        } else {
            while (j >= 0 && jogadores[j].desempenho.assis < key.desempenho.assis) {
                jogadores[j + 1] = jogadores[j];
                --j;
            }
        }
        jogadores[j + 1] = key;
    }
}

void mostrarArtilharia(const vector<Jogador>& jogadores) {
    cout << "\033[2J\033[1;1H";

    vector<Jogador> jogadoresPorGols = jogadores;
    vector<Jogador> jogadoresPorAssis = jogadores;

    insertionSort(jogadoresPorGols, 1);
    insertionSort(jogadoresPorAssis, 0);

    cout << "Artilheiros:" << endl;
    for (int i = 0; i < 3 && i < jogadoresPorGols.size(); ++i) {
        cout << i + 1 << ". " << jogadoresPorGols[i].nome << " - " << jogadoresPorGols[i].desempenho.gols << " gols" << endl;
    }

    cout << endl << "Lideres em Assistencias:" << endl;
    for (int i = 0; i < 3 && i < jogadoresPorAssis.size(); ++i) {
        cout << i + 1 << ". " << jogadoresPorAssis[i].nome << " - " << jogadoresPorAssis[i].desempenho.assis << " assistencias" << endl;
    }

    cout << endl;
}