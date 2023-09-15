#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string.h>
using namespace std;

// Indice
struct Indice {
        int codigo;
        int ender;
};

// Idioma = 0
struct Idiomas {
	int codigo;
	string descricao;
	bool status;
};

// Li��es = 1
struct Licoes {
	int codigo;
	int cod_Idioma;
	int total_Niveis;
	bool status;
};

// Exercicios = 2
struct Exercicios {
	int codigo;
	int codigo_Idioma;
	int nivel_Dificuldade;
	string descricao;
	string resposta_Correta;
	int pontuacao;
	bool status;
};

// Usuario = 3
struct Usuarios {
	int codigo;
	string nome;
	int cod_Idioma;
	int nivel_Atual;
	int total_Pontuacao;
	bool status;
};

//1-2-3 - Leitura de Dados
void gerar_dados(struct Idiomas idioma[], struct Licoes licoes[], struct Exercicios exercicios[], struct Usuarios usuario[], struct Indice iId[], struct Indice iLi[], struct Indice iEx[], struct Indice iUsu[], int cont[]){
	//Idiomas
	idioma[0].codigo = 9;
	idioma[0].descricao = "Ingl�s";
	idioma[0].status = true;
	
	idioma[1].codigo = 5;
	idioma[1].descricao = "Espanhol";
	idioma[1].status = true;
	
	idioma[2].codigo = 6;
	idioma[2].descricao = "Japon�s";
	idioma[2].status = true;
	
	iId[0].codigo = 5;
	iId[0].ender = 1;
	
	iId[1].codigo = 6;
	iId[1].ender = 2;
	
	iId[2].codigo = 9;
	iId[2].ender = 0;
	
	//Li��es
	licoes[0].codigo = 1;
	licoes[0].cod_Idioma = 9;
	licoes[0].total_Niveis = 2;
	licoes[0].status = true;
	
	licoes[1].codigo = 5;
	licoes[1].cod_Idioma = 5;
	licoes[1].total_Niveis = 5;
	licoes[1].status = true;
	
	licoes[2].codigo = 2;
	licoes[2].cod_Idioma = 6;
	licoes[2].total_Niveis = 1;
	licoes[2].status = true;
	
	iLi[0].codigo = 1;
	iLi[0].ender = 0;
	
	iLi[1].codigo = 2;
	iLi[1].ender = 2;
	
	iLi[2].codigo = 5;
	iLi[2].ender = 1;
	
	//Exerc�cios
	exercicios[0].codigo = 9;
	exercicios[0].codigo_Idioma = 9;
	exercicios[0].nivel_Dificuldade = 1;
	exercicios[0].descricao = "I will win the bike ___! 1-'race' 2-'sun'";
	exercicios[0].resposta_Correta = '1';
	exercicios[0].pontuacao = 25;
	exercicios[0].status = true;
	
	exercicios[1].codigo = 5;
	exercicios[1].codigo_Idioma = 5;
	exercicios[1].nivel_Dificuldade = 1;
	exercicios[1].descricao = "Essa frase est� correta (S/N) 'soy piloto de avion'";
	exercicios[1].resposta_Correta = 'S';
	exercicios[1].pontuacao = 50;
	exercicios[1].status = true;
		
	exercicios[2].codigo = 6;
	exercicios[2].codigo_Idioma = 6;
	exercicios[2].nivel_Dificuldade = 1;
	exercicios[2].descricao = "Qual a maneira certa de escrever 'cachorro' \n 1- Welpe \n 2-Katze";
	exercicios[2].resposta_Correta = '1';
	exercicios[2].pontuacao = 15;
	exercicios[2].status = true;
	
	iEx[0].codigo = 9;
	iEx[0].ender = 2;
	
	iEx[1].codigo = 5;
	iEx[1].ender = 0;
	
	iEx[2].codigo = 6;
	iEx[2].ender = 1;
	
	//Usu�rio
	usuario[0].codigo = 9;
	usuario[0].nome = "Gustavo";
	usuario[0].cod_Idioma = 5;
	usuario[0].nivel_Atual = 1;
	usuario[0].total_Pontuacao = 50;
	usuario[0].status = true;
	
	usuario[1].codigo = 5;
	usuario[1].nome = "Guilherme";
	usuario[1].cod_Idioma = 9;
	usuario[1].nivel_Atual = 1;
	usuario[1].total_Pontuacao = 25;
	usuario[1].status = true;
	
	usuario[2].codigo = 6;
	usuario[2].nome = "Begosso";
	usuario[2].cod_Idioma = 6;
	usuario[2].nivel_Atual = 1;
	usuario[2].total_Pontuacao = 10;
	usuario[2].status = true;
	
	iUsu[0].codigo = 5;
	iUsu[0].ender = 1;
	
	iUsu[1].codigo = 6;
	iUsu[1].ender = 2;
	
	iUsu[2].codigo = 9;
	iUsu[2].ender = 0;
	
	cont[0] = 3;
	cont[1] = 3;
	cont[2] = 3;
	cont[3] = 3;
}

// Buscas Bin�rias
int buscaBi(struct Indice idx[], int cod, int cont){
	int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo){
            i = m + 1;
        }
        else{
            f = m - 1;
        }
    }
    if (cod == idx[m].codigo){
        return idx[m].ender;
    }
    else{
        return -1;
    }
}

// Inclus�o
void inclusao_Idiomas (struct Indice idx[], struct Idiomas idioma[], int &cont){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo do Idioma a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		idioma[cont].codigo = cod;
    		cout<<"Idioma: ";
    		cin>> idioma[cont].descricao;
    		idioma[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclus�o realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont, struct Idiomas idioma[], struct Indice indIdioma[], int contIdioma){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo da Li��o a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		licoes[cont].codigo = cod;
    		cout<<"Codigo Idioma: ";
    		cin>> licoes[cont].cod_Idioma;
    		
    		int teste = buscaBi(indIdioma, licoes[cont].cod_Idioma, contIdioma);
    		while(teste == -1 || idioma[teste].status == false){
    			cout<<"Idioma n�o encontrado..."<<endl;
    			cout<<"Digite novamente o codigo do Idioma: ";
    			cin>>licoes[cont].cod_Idioma;
    			teste = buscaBi(indIdioma, licoes[cont].cod_Idioma, contIdioma);
			}
    		
    		cout<<"Idioma: "<<idioma[teste].descricao<<endl;
    		
    		cout<<"Total de n�veis: ";
    		cin>>licoes[cont].total_Niveis;
    		licoes[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclus�o realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont, struct Idiomas idioma[], struct Indice indIdioma[], int contIdioma){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo do Exerc�cio a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		exercicio[cont].codigo = cod;
    		cout<<"N�vel de dificuldade: ";
    		cin>> exercicio[cont].nivel_Dificuldade;
			cout<<"Codigo Idioma: ";
    		cin>> exercicio[cont].codigo_Idioma;
    		
    		int teste = buscaBi(indIdioma, exercicio[cont].codigo_Idioma, contIdioma);
    		while(teste == -1 || idioma[teste].status == false){
    			cout<<"Idioma n�o encontrado..."<<endl;
    			cout<<"Digite novamente o codigo do Idioma: ";
    			cin>>exercicio[cont].codigo_Idioma;
    			teste = buscaBi(indIdioma, exercicio[cont].codigo_Idioma, contIdioma);
			}
    		
    		cout<<"Idioma: "<<idioma[teste].descricao<<endl;
    		cout<<"Descri��o: ";
    		cin>> exercicio[cont].descricao;
    		cout<<"Resposta: ";
    		cin>> exercicio[cont].resposta_Correta;
    		cout<<"Pontua��o: ";
    		cin>> exercicio[cont].pontuacao;
    		exercicio[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclus�o realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Usuarios (struct Indice idx[], struct Usuarios usuario[], int &cont, struct Idiomas idioma[], struct Indice indIdioma[], int contIdioma){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo do Usu�rio a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		usuario[cont].codigo = cod;
    		cout<<"Nome: ";
    		cin>> usuario[cont].nome;
    		cout<<"Codigo Idioma: ";
    		cin>>usuario[cont].cod_Idioma;
    		
    		int teste = buscaBi(indIdioma, usuario[cont].cod_Idioma, contIdioma);
    		while(teste == -1 || idioma[teste].status == false){
    			cout<<"Idioma n�o encontrado..."<<endl;
    			cout<<"Digite novamente o codigo do Idioma: ";
    			cin>>usuario[cont].cod_Idioma;
    			teste = buscaBi(indIdioma, usuario[cont].cod_Idioma, contIdioma);
			}
    		
    		cout<<"Idioma: "<<idioma[teste].descricao<<endl;
    		
    		cout<<"N�vel Atual: ";
    		cin>>usuario[cont].nivel_Atual;
    		cout<<"Pontua�o Total: ";
    		cin>>usuario[cont].total_Pontuacao;
    		usuario[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclus�o realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

// Exclus�o
void desabilitar_Idiomas (struct Indice idx[], struct Idiomas idioma[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Idioma (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && idioma[ender].status == true){
				cout<<"Lingua "<<idioma[ender].descricao<<" excluido...";
				idioma[ender].status = false;
			}
			else{
				cout<<"Lingua n�o encontrada...";
			}
			getch();
		}
	}
}

void desabilitar_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo da Li��o (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && licoes[ender].status == true){
				cout<<"Li��o "<<licoes[ender].codigo<<" excluido...";
				licoes[ender].status = false;
			}
			else{
				cout<<"Li��o n�o encontrada...";
			}
			getch();
		}
	}
}

void desabilitar_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Exerc�cio (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && exercicio[ender].status == true){
				cout<<"Exerc�cio "<<exercicio[ender].codigo<<" excluido...";
				exercicio[ender].status = false;
			}
			else{
				cout<<"Exerc�cio n�o encontrado...";
			}
			getch();
		}
	}
}

void desabilitar_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Usu�rio (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && usuario[ender].status == true){
				cout<<"Usu�rio "<<usuario[ender].nome<<" excluido...";
				usuario[ender].status = false;
			}
			else{
				cout<<"Usu�rio n�o encontrado...";
			}
			getch();
		}
	}
}

// Recupera��o
void recuperar_Idiomas (struct Indice idx[], struct Idiomas idioma[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Idioma (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && idioma[ender].status != true){
				cout<<"Lingua "<<idioma[ender].descricao<<" recuperada...";
				idioma[ender].status = true;
			}
			else{
				cout<<"Lingua n�o encontrada...";
			}
			getch();
		}
	}
}

void recuperar_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo da Li��o (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && licoes[ender].status != true){
				cout<<"Li��o "<<licoes[ender].codigo<<" recuperado...";
				licoes[ender].status = true;
			}
			else{
				cout<<"Li��o n�o encontrada...";
			}
			getch();
		}
	}
}

void recuperar_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Exerc�cio (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && exercicio[ender].status != true){
				cout<<"Exerc�cio "<<exercicio[ender].codigo<<" recuperado...";
				exercicio[ender].status = true;
			}
			else{
				cout<<"Exerc�cio n�o encontrado...";
			}
			getch();
		}
	}
}

void recuperar_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Usu�rio (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && usuario[ender].status != true){
				cout<<"Usu�rio "<<usuario[ender].nome<<" recuperado...";
				usuario[ender].status = true;
			}
			else{
				cout<<"Usu�rio n�o encontrado...";
			}
			getch();
		}
	}
}

// Leitura Exaustiva
void leitura_Idioma (struct Indice idx[], struct Idiomas idioma[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<idioma[aux].codigo<<endl;
		cout<<"Descri��o: "<<idioma[aux].descricao<<endl;
		cout<<"Status: "<<idioma[aux].status<<endl;
	}
	cout<<"==================================="<<endl;
	getch();
}

void leitura_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<licoes[aux].codigo<<endl;
		cout<<"Codigo do Idioma: "<<licoes[aux].cod_Idioma<<endl;
		cout<<"Total de N�veis: "<<licoes[aux].total_Niveis<<endl;
		cout<<"Status: "<<licoes[aux].status<<endl;
	}
	cout<<"==================================="<<endl;
	getch();
}

void leitura_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<exercicio[aux].codigo<<endl;
		cout<<"N�vel de Dificuldade: "<<exercicio[aux].nivel_Dificuldade<<endl;
		cout<<"Descricao: "<<exercicio[aux].descricao<<endl;
		cout<<"Resposta: "<<exercicio[aux].resposta_Correta<<endl;
		cout<<"Pontua��o: "<<exercicio[aux].pontuacao<<endl;
		cout<<"Status: "<<exercicio[aux].status<<endl;
	}
	cout<<"==================================="<<endl;
	getch();
}

void leitura_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<usuario[aux].codigo<<endl;
		cout<<"Nome: "<<usuario[aux].nome<<endl;
		cout<<"Idioma: "<<usuario[aux].cod_Idioma<<endl;
		cout<<"N�vel Atual: "<<usuario[aux].nivel_Atual<<endl;
		cout<<"Total_Pontua��o: "<<usuario[aux].total_Pontuacao<<endl;
		cout<<"Status: "<<usuario[aux].status<<endl;
	}
	cout<<"==================================="<<endl;
}

// Reorganiza��o
void reorganizacao_Idioma (struct Indice idx[], struct Idiomas idioma[], int &cont){
	struct Idiomas aux[30];
	int cont2 = 0;

	for(int j= 0; j<cont; j++){
		int i = idx[j].ender;
        if(idioma[i].status == true){
            idx[cont2].codigo = idioma[i].codigo;
            idx[cont2].ender = cont2;
            aux[cont2] = idioma[i];

            cont2++;
        }
    }
    
	for(int i= 0; i<cont2; i++){
		int ender = idx[i].ender;
		idioma[ender] = aux[ender];
	}
	cont = cont2;
	
	cout<<"Tabela Reorganizada...";
	getch();
}

void reorganizacao_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	struct Licoes aux[30];
	int cont2 = 0;

	for(int j= 0; j<cont; j++){
		int i = idx[j].ender;
        if(licoes[i].status == true){
            idx[cont2].codigo = licoes[i].codigo;
            idx[cont2].ender = cont2;
            aux[cont2] = licoes[i];

            cont2++;
        }
    }
    
	for(int i= 0; i<cont2; i++){
		int ender = idx[i].ender;
		licoes[ender] = aux[ender];
	}
	cont = cont2;
	
	cout<<"Tabela Reorganizada...";
	getch();
}

void reorganizacao_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	struct Exercicios aux[30];
	int cont2 = 0;

	for(int j= 0; j<cont; j++){
		int i = idx[j].ender;
        if(exercicio[i].status == true){
            idx[cont2].codigo = exercicio[i].codigo;
            idx[cont2].ender = cont2;
            aux[cont2] = exercicio[i];

            cont2++;
        }
    }
    
	for(int i= 0; i<cont2; i++){
		int ender = idx[i].ender;
		exercicio[ender] = aux[ender];
	}
	cont = cont2;
	
	cout<<"Tabela Reorganizada...";
	getch();
}

void reorganizacao_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	struct Usuarios aux[30];
	int cont2 = 0;

	for(int j= 0; j<cont; j++){
		int i = idx[j].ender;
        if(usuario[i].status == true){
            idx[cont2].codigo = usuario[i].codigo;
            idx[cont2].ender = cont2;
            aux[cont2] = usuario[i];

            cont2++;
        }
    }
    
	for(int i= 0; i<cont2; i++){
		int ender = idx[i].ender;
		usuario[ender] = aux[ender];
	}
	cont = cont2;
	
	cout<<"Tabela Reorganizada...";
	getch();
}

// Realizar Perguntas
int buscaBi_Licoes (struct Indice idx[], struct Licoes licoes[], int cod, int cont){
	int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != licoes[idx[m].ender].cod_Idioma; m = (i + f) / 2){
        if (cod > idx[m].codigo){
            i = m + 1;
        }
        else{
            f = m - 1;
        }
    }
    if (cod == licoes[idx[m].ender].cod_Idioma && licoes[idx[m].ender].status == true){
        return idx[m].ender;
    }
    else{
        return -1;
    }
}

void realizar_perguntas(struct Indice idx[], struct Usuarios usuario[], int &cont, struct Exercicios exercicio[], struct Indice indExercicio[], int &contExercicio, struct Indice indLicoes[], struct Licoes licoes[], int &contLicoes){
	for(int aux = 1; aux != 0;){
		system("cls");
		leitura_Usuario(idx, usuario, cont);
		cout<<"\nDigite o c�digo do Usu�rio que vai realizar a lista de perguntas: ";
		cin>> aux;
		if(aux != 0){
			aux = buscaBi(idx, aux, cont);
			if(aux != -1){
				for(int i = 0; i < contExercicio; i++){
					int j = indExercicio[i].ender;
					if(exercicio[j].nivel_Dificuldade <= usuario[aux].nivel_Atual and exercicio[j].codigo_Idioma == usuario[aux].cod_Idioma){
						string resposta;
						cout<<"\nPergunta: "<<exercicio[j].descricao<<endl;
						cout<<"Resposta: ";
						cin>> resposta;
						int resultado = exercicio[j].resposta_Correta.compare(resposta);
						if( resultado == 0){
							cout<<"CORRETO!"<<endl;
							getch();
							usuario[aux].total_Pontuacao += exercicio[j].pontuacao;
							if(usuario[aux].total_Pontuacao >= 100){
								usuario[aux].nivel_Atual++;
								usuario[aux].total_Pontuacao = 0;
								cout<<"N�vel Aumentado!"<<endl;
								getch();
							}
						}
						else{
							cout<<"ERRADO!"<<endl;
							getch();
							usuario[aux].total_Pontuacao -= exercicio[j].pontuacao*0.1;
						}
					}		
				}
				int endLicao = buscaBi_Licoes(indLicoes, licoes, usuario[aux].cod_Idioma, contLicoes);
				if(usuario[aux].nivel_Atual > licoes[endLicao].total_Niveis){
					cout<<"VAI PEGAR O SEU CERTIFICADO!"<<endl;
					getch();
				}
			}
			else{
				cout<<"Usu�rio incorreto..."<<endl;
				getch();
			}
		}
	}
}

// Realizare Ranqueamento
void leitura_Pontos (struct Indice idx[], struct Usuarios usuario[], int &cont){
	struct Usuarios V[30];
	
	for(int i = 0; i < cont; i++){
		V[i] = usuario[i];
	}
	
	int i, j, h;
	struct Usuarios aux;
	h = 1;
	while(h < cont/3){
		h = 3 * h + 1;
	}
	while( h > 0){
		for(i = h; i < cont; i++){
			aux = V[i];
			j = i;
			while(j >= h && aux.total_Pontuacao < V[ j - h].total_Pontuacao){
				V[j] = V[ j - h];
				j = j - h;
			}
			V[j] = aux;
		}
		h = (h - 1)/3;
	}
	
	int posicao=1;
	for(int i = cont - 1; i >= 0; i--){
		cout<<"==============="<<posicao<<"�LUGAR==============="<<endl;
		cout<<"Codigo: "<<V[i].codigo<<endl;
		cout<<"Nome: "<<V[i].nome<<endl;
		cout<<"Idioma: "<<V[i].cod_Idioma<<endl;
		cout<<"Nivel Atual: "<<V[i].nivel_Atual<<endl;
		cout<<"Total_Pontua��o: "<<V[i].total_Pontuacao<<endl;
		posicao++;
	}
	cout<<"=====================================";
	getch();
}

// Main
int main(){
	setlocale(LC_ALL,"");
	
	struct Idiomas idioma[30];
	struct Indice indIdioma[30];
	struct Licoes licoes[30];
	struct Indice indLicoes[30];
	struct Exercicios exercicio[30];
	struct Indice indExercicios[30];
	struct Usuarios usuario[30];
	struct Indice indUsuario[30];
	
	int cont[4];
	
	gerar_dados(idioma, licoes, exercicio, usuario, indIdioma, indLicoes, indExercicios, indUsuario, cont);
	
	for(bool sair = false; sair == false;){
		system("cls");
		int op;
		cout<<"\tBEM VINDO AO LingoMax"<<endl;
		cout<<"\tEstas s�o suas op��es:"<<endl;
		cout<<"\t\t1- Realizar Inclus�o"<<endl;
		cout<<"\t\t2- Realizar Exclus�o"<<endl;
		cout<<"\t\t3- Realizar Recupera��o"<<endl;
		cout<<"\t\t4- Realizar Leituras Exaustivas"<<endl;
		cout<<"\t\t5- Realizar Reorganiza��o"<<endl;
		cout<<"\t\t6- Exerc�cios"<<endl;
		cout<<"\t\t7- Ranqueamento dos Usu�rios"<<endl;
		cout<<"\t\t8- Sair"<<endl;
		cout<<"\tDigite a opcao desejada: ";
		cin>>op;
		switch(op){
			case 1:{
				for(bool sair = false; sair == false;){
					system("cls");
					int op;
					cout<<"\tINCLUS�O"<<endl;
					cout<<"\tEstas s�o suas op��es:"<<endl;
					cout<<"\t\t1- Incluir Idiomas"<<endl;
					cout<<"\t\t2- Incluir Li��es"<<endl;
					cout<<"\t\t3- Incluir Exerc�cios"<<endl;
					cout<<"\t\t4- Incluir Usu�rios"<<endl;
					cout<<"\t\t5- Voltar"<<endl;
					cout<<"\tDigite a opcao desejada: ";
					cin>>op;
					switch(op){
						case 1:{
							system("cls");
							inclusao_Idiomas(indIdioma, idioma, cont[0]);
							break;
						}
						
						case 2:{
							system("cls");
							inclusao_Licoes(indLicoes, licoes, cont[1], idioma, indIdioma, cont[0]);
							break;
						}
						
						case 3:{
							system("cls");
							inclusao_Exercicios(indExercicios, exercicio, cont[2], idioma, indIdioma, cont[0]);
							break;
						}
						
						case 4:{
							system("cls");
							inclusao_Usuarios(indUsuario, usuario, cont[3], idioma, indIdioma, cont[0]);
							break;
						}
						
						case 5:{
							sair = true;
							break;
						}
			
						default:{
						system("cls");
						cout<<"Op��o invalida...";
						getch();
						break;
						}
					}
				}
				break;
			}
			
			case 2:{
				for(bool sair = false; sair == false;){
					system("cls");
					int op;
					cout<<"\tEXCLUS�O"<<endl;
					cout<<"\tEstas s�o suas op��es:"<<endl;
					cout<<"\t\t1- Excluir Idiomas"<<endl;
					cout<<"\t\t2- Excluir Li��es"<<endl;
					cout<<"\t\t3- Excluir Exerc�cios"<<endl;
					cout<<"\t\t4- Excluir Usu�rios"<<endl;
					cout<<"\t\t5- Voltar"<<endl;
					cout<<"\tDigite a opcao desejada: ";
					cin>>op;
					switch(op){
						case 1:{
							system("cls");
							desabilitar_Idiomas(indIdioma, idioma, cont[0]);
							break;
						}
						
						case 2:{
							system("cls");
							desabilitar_Licoes(indLicoes, licoes, cont[1]);
							break;
						}
						
						case 3:{
							system("cls");
							desabilitar_Exercicios(indExercicios, exercicio, cont[2]);
							break;
						}
						
						case 4:{
							system("cls");
							desabilitar_Usuario(indUsuario, usuario, cont[3]);
							break;
						}
						
						case 5:{
							sair = true;
							break;
						}
			
						default:{
						system("cls");
						cout<<"Op��o invalida...";
						getch();
						break;
						}
					}
				}
				break;
			}
			
			case 3:{
				for(bool sair = false; sair == false;){
					system("cls");
					int op;
					cout<<"\tRECUPERA��O"<<endl;
					cout<<"\tEstas s�o suas op��es:"<<endl;
					cout<<"\t\t1- Recuperar Idiomas"<<endl;
					cout<<"\t\t2- Recuperar Li��es"<<endl;
					cout<<"\t\t3- Recuperar Exerc�cios"<<endl;
					cout<<"\t\t4- Recuperar Usu�rios"<<endl;
					cout<<"\t\t5- Voltar"<<endl;
					cout<<"\tDigite a opcao desejada: ";
					cin>>op;
					switch(op){
						case 1:{
							system("cls");
							recuperar_Idiomas(indIdioma, idioma, cont[0]);
							break;
						}
						
						case 2:{
							system("cls");
							recuperar_Licoes(indLicoes, licoes, cont[1]);
							break;
						}
						
						case 3:{
							system("cls");
							recuperar_Exercicios(indExercicios, exercicio, cont[2]);
							break;
						}
						
						case 4:{
							system("cls");
							recuperar_Usuario(indUsuario, usuario, cont[3]);
							break;
						}
						
						case 5:{
							sair = true;
							break;
						}
			
						default:{
						system("cls");
						cout<<"Op��o invalida...";
						getch();
						break;
						}
					}
				}
				break;
			}
			
			case 4:{
				for(bool sair = false; sair == false;){
					system("cls");
					int op;
					cout<<"\tLEITURA EXAUSTIVA"<<endl;
					cout<<"\tEstas s�o suas op��es:"<<endl;
					cout<<"\t\t1- Ler Idiomas"<<endl;
					cout<<"\t\t2- Ler Li��es"<<endl;
					cout<<"\t\t3- Ler Exerc�cios"<<endl;
					cout<<"\t\t4- Ler Usu�rios"<<endl;
					cout<<"\t\t5- Voltar"<<endl;
					cout<<"\tDigite a opcao desejada: ";
					cin>>op;
					switch(op){
						case 1:{
							system("cls");
							leitura_Idioma(indIdioma, idioma, cont[0]);
							break;
						}
						
						case 2:{
							system("cls");
							leitura_Licoes(indLicoes, licoes, cont[1]);
							break;
						}
						
						case 3:{
							system("cls");
							leitura_Exercicios(indExercicios, exercicio, cont[2]);
							break;
						}
						
						case 4:{
							system("cls");
							leitura_Usuario(indUsuario, usuario, cont[3]);
							getch();
							break;
						}
						
						case 5:{
							sair = true;
							break;
						}
			
						default:{
						system("cls");
						cout<<"Op��o invalida...";
						getch();
						break;
						}
					}
				}
				break;
			}
			
			case 5:{
				for(bool sair = false; sair == false;){
					system("cls");
					int op;
					cout<<"\tREORGANIZA��O"<<endl;
					cout<<"\tEstas s�o suas op��es:"<<endl;
					cout<<"\t\t1- Reorganizar Idiomas"<<endl;
					cout<<"\t\t2- Reorganizar Li��es"<<endl;
					cout<<"\t\t3- Reorganizar Exerc�cios"<<endl;
					cout<<"\t\t4- Reorganizar Usu�rios"<<endl;
					cout<<"\t\t5- Voltar"<<endl;
					cout<<"\tDigite a opcao desejada: ";
					cin>>op;
					switch(op){
						case 1:{
							system("cls");
							reorganizacao_Idioma(indIdioma, idioma, cont[0]);
							break;
						}
						
						case 2:{
							system("cls");
							reorganizacao_Licoes(indLicoes, licoes, cont[1]);
							break;
						}
						
						case 3:{
							system("cls");
							reorganizacao_Exercicios(indExercicios, exercicio, cont[2]);
							break;
						}
						
						case 4:{
							system("cls");
							reorganizacao_Usuario(indUsuario, usuario, cont[3]);
							break;
						}
						
						case 5:{
							sair = true;
							break;
						}
			
						default:{
						system("cls");
						cout<<"Op��o invalida...";
						getch();
						break;
						}
					}
				}
				break;
			}
			
			case 6:{
				system("cls");
				realizar_perguntas(indUsuario, usuario, cont[3], exercicio, indExercicios, cont[2], indLicoes, licoes, cont[1]);
				break;
			}
			
			case 7:{
				system("cls");
				leitura_Pontos(indUsuario, usuario, cont[3]);
				break;
			}
			
			case 8:{
				system("cls");
				cout<<"Obrigado...";
				sair = true;
				getch();
				break;
			}
			
			default:{
				system("cls");
				cout<<"Op��o invalida...";
				getch();
				break;
			}
		}
	}
}
