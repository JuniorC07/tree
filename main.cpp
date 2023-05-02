#include <iostream>
#include <stdlib.h>
//Fila Criada por Junior
/*OBS: Compila e executa no terminal linux, peço que corrija usando linux,
pois os testes foram feitos no terminal e todas as funções estão funcionado.*/
using namespace std;

class cidade{
	public:
		string nome;
		int nhab;
		int cod;
		float disprox;
		float disant;
		cidade *prox;
		cidade *ant;

		cidade(){						//Método Construtor, já setando a Capital
			nhab = 477789;
            disprox = 138;
            disant = 150;
            cod = 0;
			nome = "Florianopolis";
			prox = NULL;
			ant = NULL;
		}

		~cidade(){									//Método Destrutor
			cout << "Objeto Destruido" << endl;
		}

		cidade *tail(cidade *no){ 	 //Método responsável por encontrar a "cauda" da fila
			cidade *t;
			while(no != NULL){
				if(no->prox == NULL)
					t = no;
				no = no->prox;
			}
			return t;
		}

		cidade *head(cidade *no){		//Método responsável por encontrar a "cabeça" da fila
			cidade *h;
			while(no != NULL){
				if(no->ant == NULL)
					h = no;
				no = no->ant;
			}
				return h;
		}

		void criacity(cidade *no){		//Método responsável pela criação das cidades a direita;
			int i;
			i=0;
			while(i < 2){
				cidade *ultimo = tail(no);
				cidade *novo = (cidade*) malloc(sizeof(cidade));
				if(i == 0){
					novo->nome = "Tubarao";
					novo->cod = 1;
					novo->nhab = 103674;
					novo->disant = 138;
					novo->disprox = 62;
				}
				else if(i == 1){
					novo->nome = "Criciuma";
					novo->cod = 2;
					novo->nhab = 209153;
					novo->disant = 62;
					novo->disprox = 0;
				}
				novo->prox = NULL;
				novo->ant = ultimo;
				ultimo->prox = novo;
				i++;
			}
		}

        int tamanho(cidade *no){		//Método que retorna o tamanho da lista
            int cont = 0;
            no = no->head(no);
            while(no != NULL){
                cont++;
                no = no->prox;
            }
            return cont;
        }

		void criaant(cidade *no){		//Método responsável por criar cidades a esquerda
			int i;
			i = 0;
		    while(i < 2){
				cidade *primeiro = head(no);
				cidade *novo = (cidade*) malloc(sizeof(cidade));
				if(i == 0){
					novo->nome = "Blumenau";
					novo->cod = 3;
					novo->nhab = 343745;
					novo->disant = 119;
					novo->disprox = 150;
				}
				else if(i == 1){
					novo->nome = "Joinville";
					novo->cod = 4;
					novo->nhab = 569645;
					novo->disant = 0;
					novo->disprox = 119;
				}
				novo->ant = NULL;
				novo->prox = primeiro;
				primeiro->ant = novo;
				i++;
			}

		}

 		void mostra(cidade *no){ 		//Método somente de exibição
			int i = 1;
			cidade *aux = head(no);
			while(aux != NULL){
				cout << "\t\t Cidade: " << i << "\n\nNome: "<< aux->nome <<" \tNumero de Habitantes: " << aux->nhab << "\n\n" << endl;
				/*<<"\nAtual: "<< aux << "\tAnterior: " << aux->ant << "\tProximo: "<< aux->prox << "\n\n" << endl;*/
				aux = aux->prox;
				i++;
			}
		}

		void del_tail(cidade *no){			//Método que deleta o ultimo elemento da lista
			cidade *ultimo = tail(no);
			while(no != ultimo){
				if(no->prox == ultimo){
					no->prox = NULL;
					break;
				}
				no = no->prox;
			}
		}

		void del_head(cidade *no){			//Método que deleta o primeiro elemento da lista
			cidade *primeiro = head(no);
			while(no != NULL){
				if(no->ant == primeiro){
					no->ant = NULL;
					break;
				}
				no = no->ant;
			}
		}

		cidade *ender(cidade *no){			//Método que busca uma cidade(endereço de memoria)
			cidade *aux1, *aux= head(no);
			string s;
			int i;
			i = 0;
			cout << "Digite o nome da cidade que procura:" << endl;
			while(i != 5 ){
				if(i == 1)
					cout << "Digite o nome correto da cidade:(Sem acentos ou caracteres especiais)" << endl;
				cin >> s;
				i = 1;
				aux= head(no);
				while (aux != NULL){
					if(aux->nome == s){
						i = 5;
						aux1 = aux;
					}
					aux = aux->prox;
				}
			}
			return aux1;
		}

		void atualizahab(cidade *no){		//Método que atualiza o numero de habitantes
			int i;
			cidade *aux = ender(no);
			cout << "Digite o numero de habitantes atualizado:" << endl;
			cin >> i;
			aux->nhab = i;
		}

		void inserem(cidade *no){			//Método que insere uma cidade onde o usuário desejar
			cidade *e, *n, *aux, *aux1;
			e = no->ender(no);
			aux = e;
			aux1 = (cidade*) malloc(sizeof(cidade));
			aux1 = e->prox;
			n = (cidade*) malloc(sizeof(cidade));
			string s;
			int i,co,da,dae;
			cout << "Digite o nome da nova cidade: " << endl;
			cin >> s;
			cout << "Digite numero de habitantes da nova cidade: " << endl;
			cin >> i;
			cout << "Digite o codigo da nova cidade: " << endl;
			cin >> co;
			cout << "Digite a distancia entre a cidade de " << (aux->prox)->nome << "e a nova cidade:(disprox) " << endl;
			cin >> da;
			cout << "Digite a distancia entre a nova cidade  e a cidade de " << (aux->nome) <<":(disant) " << endl;
			cin >> dae;
			n->nome = s;
			n->nhab = i;
			n->cod = co;
			n->disprox = da;
			n->disant = dae;

			aux->disprox = n->disant;
			aux->prox = n;
			n->ant = aux;
			aux1->disant = n->disprox;
			if(aux->prox == NULL)
				n->prox = NULL;
			else{
				n->prox = aux1;
				aux1->ant = n;
			}
		}

		void ordenar_lista(cidade *no){ 		//Método que ordena a lista pelo numero de habitantes
			cidade *inicio,*inicio2,*ax = head(no);
			cidade *aux =(cidade*) malloc(sizeof(cidade));
			inicio = ax;
			while (inicio != NULL){
				inicio2 = inicio->prox;
					while (inicio2 != NULL){
						if(inicio->nhab > inicio2->nhab){

							aux->nhab = inicio->nhab;
							aux->nome = inicio->nome;
							aux->cod = inicio->cod;
							aux->disprox = inicio->cod;
							aux->disant = inicio->disant;

							inicio->nhab = inicio2->nhab;
							inicio->nome = inicio2->nome;
							inicio->cod = inicio2->cod;
							inicio->disprox = inicio2->disprox;
							inicio->disant = inicio2->disant;

							inicio2->nhab = aux->nhab;
							inicio2->nome = aux->nome;
							inicio2->cod = aux->cod;
							inicio2->disprox = aux-> disprox;
							inicio2->disant = aux->disant;
						}
						inicio2 = inicio2->prox;
					}
				inicio = inicio->prox;
			}
		}

		void distancia(cidade *no){		//Método que obtem e exibe a distancia entre 2 cidades escolhidas
			cidade *cid, *cid1, *a, *b;
			int i = 0, n = 0;
			float soma=0;
			i = 0;
			n = 0;
			soma = 0;
			cout << "Escolha a primeira cidade" << endl;
			cid = ender(no);
			a = cid;
			cout << "Escolha segunda cidade" << endl;
			cid1 = ender(no);
			b = cid1;
			while(cid != NULL){
				if(cid->nome == a->nome){
						a = cid;
				}
				i++;
				cid =cid->prox;
			}
			while(cid1 != NULL){
				if(cid1->nome == b->nome){
					b = cid1;
				}
				n++;
				cid1 = cid1->prox;
			}
			if(i > n){
				while(a != b){
					soma = soma + a->disprox;
					a = a->prox;
				}
			}
			else if(i < n){
				while(b != a){
					soma = soma + b->disprox;
					b = b->prox;
				}
			}
			cout << "A distancia e de " << soma << " kms" << endl;
		}

	};

int main(){
		cidade *elm = new cidade();
		int i,aux;
		elm->criaant(elm);
		elm->criacity(elm);
		while(i != 9){
			cout << "\t\t\t Escolha uma das opções abaixo" << endl;
			cout << "\t\t 1 ===> Exibir lista" << endl;
			cout << "\t\t 2 ===> Atualiza a quantidade de habitantes de uma cidade" << endl;
			cout << "\t\t 3 ===> Inserir uma cidade na Lista" << endl;
			cout << "\t\t 4 ===> Obter distancia entre duas cidades" << endl;
			cout << "\t\t 5 ===> Ordenar e exibir lista" << endl;
			cout << "\t\t 9 ===> Finalizar Programa" << endl;
			cin >> i;
			switch(i){
				case 1:
					system("clear");
					elm->mostra(elm);
					break;

				case 2:
					elm->atualizahab(elm);
					break;

				case 3:
					cout << "Escolha uma cidade, entre a escolhida e a proxima sera inserida a nova cidade." << endl;
					elm->inserem(elm);
					break;

				case 4:
					system("clear");
					elm->distancia(elm);
					break;

				case 5:
					cout << "Caso Utilize esta função o metodo de descobrir e"
					" mostrar a distancia das cidades será comprometido:\n\t\t\t1 === Continuar\n\t\t\t2 === Voltar ao menu principal" << endl;
					cin >> aux;
					if(aux == 1){
						elm->ordenar_lista(elm);
						elm->mostra(elm);
					}
					break;

				case 9:
					system("clear");
					break;

				default:
					system("clear");
					cout << "Opção invalida, por favor escolha um valida" << endl;
					break;
			}
		}

		return 0;
}