
#include <iostream>

#include "Node.h"
#include "BinaryTree.h"

using namespace std;

void menuOpcoes() {
    cout << "\n\t\t-------------------------------" << endl;
    cout << "\t\t             Menu               " << endl;
    cout << "\t\t1 - Inserir " << endl;
    cout << "\t\t2 - Remover " << endl << endl;
    cout << "\t\t-------------------------------  " << endl;
    cout << "\t\ti - Imprimir (em-ordem)" << endl;
    cout << "\t\ts - Salvar " << endl;
    cout << "\t\tq - Quit " << endl;
    cout << "\t\t-------------------------------  " << endl;
    cout << "\t\tEscolhar uma opcao:";
}

int main() {
    int id;
    Market p;
    char opcao = 's';
    BinaryTree tree;
    tree.loadProducts();

    do {
        menuOpcoes();
        cin >> opcao;
        cout << "\t\t----------------------------\n";

        switch (opcao) {
            case '1':
                p.fill_data();
                tree.insert(p);
                break;
            case '2':
                cout << endl << endl << "*** Remoção de nó ***"<<endl;
                cout << "Informe o id:";
                cin >> id;
                p.setId(id);
                tree.remove(p);
                cout << "*** Remoção feita com sucesso."<< endl<< endl;
                break;
            case 'i':
                cout << endl << endl << "*** Percurso na arvore ***"<<endl;
                tree.inOrder(tree.getRoot());
                cout << endl << "*** Percurso feito."<<endl << endl;
                break;

            case 's':
                cout << endl << endl << "*** Salvando no arquivo..."<<endl;
                tree.saveProductsInFile();
                cout << "*** Salvo com sucesso."<< endl<< endl;
                break;
            default:
                break;
        }
    } while (opcao != 'q' && opcao != 'Q');

    return 0;
}
//
// Created by Admin on 18/10/2023.
//
