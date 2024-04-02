
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

	// se a lista j� possuir elementos
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

    // Verifica se o elemento j� existe na lista
    if (posicaoElemento(elemento) != NULL) {
        cout << "O elemento j� est� na lista. \n";
        cout << endl;
        return;
    }

    // separa um espaco na mem�ria para o novo n�
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        cout << "Erro ao alocar mem�ria.\n";
        return;
    }

    // aqui o programa preenche os dados do novo n�
    novo->valor = elemento;
    novo->prox = NULL;

    // verificar se a lista est� vazia
    if (primeiro == NULL) {
        primeiro = novo;
    } else {
        // encontrar o �ltimo n� e adicionar o novo n� ap�s ele
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

    //solicita ao usu�rio que digite o n�mero do elemento a ser excluido
    cout << "Digite o elemento a ser exclu�do: ";
    cin >> excluirNumero;

    //verifica se a lista est� vazia. Se estiver, exibe uma mensagem e retorna.
    if (primeiro == NULL) {
        cout << "A lista est� vazia.\n";
        return;
    }
    //Inicializa dois ponteiros para nos (atual e anterior) para percorrer a lista. O ponteiro atual come�a no primeiro no da lista.
    NO* atual = primeiro;
    NO* anterior = NULL;

    //percorremos a lista at� encontrar o elemento a ser excluido ou ate o final da lista
    while (atual != NULL) {
        if (atual->valor == excluirNumero) {
            if (anterior == NULL) { // Se o elemento a ser exclu�do � o primeiro da lista
                primeiro = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual); //Aqui o no esta sendo excluido usando a funcao free
            cout << "Elemento exclu�do com sucesso. \n";
            deletarNumero = true;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    //Se o deletarNumero for verdadeiro entao mostra essa mensagem
    if (!deletarNumero) {
        cout << "Elemento n�o encontrado.\n";
    }
}


void buscarElemento() {
    int buscarNum;

    if (primeiro != NULL) {
        cout << "Digite o elemento que est� procurando: ";
        cin >> buscarNum;

        NO* posicao = posicaoElemento(buscarNum); // Localiza o elemento

        if (posicao != NULL) {
            cout << "Elemento Encontrado\n";
            cout << "A posi��o que ele se encontra atualmente �: ";
            cout << posicao << endl;
        } else {
            cout << "Elemento n�o encontrado. \n";
        }
    } else {
        cout << "A lista est� vazia. \n";
    }
}


// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
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
