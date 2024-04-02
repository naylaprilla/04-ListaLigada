
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento() {
    int elemento;
    cout << "Digite o elemento que deseja inserir: ";
    cin >> elemento;

    // Verifica se o elemento já existe na lista
    if (posicaoElemento(elemento) != NULL) {
        cout << "O elemento já está na lista. \n";
        cout << endl;
        return;
    }

    // separa um espaco na memória para o novo nó
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        cout << "Erro ao alocar memória.\n";
        return;
    }

    // aqui o programa preenche os dados do novo nó
    novo->valor = elemento;
    novo->prox = NULL;

    // verificar se a lista está vazia
    if (primeiro == NULL) {
        primeiro = novo;
    } else {
        // encontrar o último nó e adicionar o novo nó após ele
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}


void excluirElemento() {
    int excluirNumero;
    bool deletarNumero = false; //a variavel comeca com o valor falso

    //solicita ao usuário que digite o número do elemento a ser excluido
    cout << "Digite o elemento a ser excluído: ";
    cin >> excluirNumero;

    //verifica se a lista está vazia. Se estiver, exibe uma mensagem e retorna.
    if (primeiro == NULL) {
        cout << "A lista está vazia.\n";
        return;
    }
    //Inicializa dois ponteiros para nos (atual e anterior) para percorrer a lista. O ponteiro atual começa no primeiro no da lista.
    NO* atual = primeiro;
    NO* anterior = NULL;

    //percorremos a lista até encontrar o elemento a ser excluido ou ate o final da lista
    while (atual != NULL) {
        if (atual->valor == excluirNumero) {
            if (anterior == NULL) { // Se o elemento a ser excluído é o primeiro da lista
                primeiro = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual); //Aqui o no esta sendo excluido usando a funcao free
            cout << "Elemento excluído com sucesso. \n";
            deletarNumero = true;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    //Se o deletarNumero for verdadeiro entao mostra essa mensagem
    if (!deletarNumero) {
        cout << "Elemento não encontrado.\n";
    }
}


void buscarElemento() {
    int buscarNum;

    if (primeiro != NULL) {
        cout << "Digite o elemento que está procurando: ";
        cin >> buscarNum;

        NO* posicao = posicaoElemento(buscarNum); // Localiza o elemento

        if (posicao != NULL) {
            cout << "Elemento Encontrado\n";
            cout << "A posição que ele se encontra atualmente é: ";
            cout << posicao << endl;
        } else {
            cout << "Elemento não encontrado. \n";
        }
    } else {
        cout << "A lista está vazia. \n";
    }
}


// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
