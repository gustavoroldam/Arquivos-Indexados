#include <iostream>
#include <conio.h>
#include<locale.h>
using namespace std;

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
// Lições = 1
struct Licoes {
	int codigo;
	int cod_Idioma;
	int total_Niveis;
	bool status;
};
// Exercicios = 2
struct Exercicios {
	int codigo;
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
	idioma[0].descricao = "Inglês";
	idioma[0].status = true;
	
	idioma[1].codigo = 5;
	idioma[1].descricao = "Espanhol";
	idioma[1].status = true;
	
	idioma[2].codigo = 6;
	idioma[2].descricao = "Japonês";
	idioma[2].status = true;
	
	iId[0].codigo = 5;
	iId[0].ender = 1;
	
	iId[1].codigo = 6;
	iId[1].ender = 2;
	
	iId[2].codigo = 9;
	iId[2].ender = 0;
	
	//Lições
	licoes[0].codigo = 1;
	licoes[0].cod_Idioma = 9;
	licoes[0].total_Niveis = 100;
	licoes[0].status = true;
	
	licoes[1].codigo = 5;
	licoes[1].cod_Idioma = 5;
	licoes[1].total_Niveis = 100;
	licoes[1].status = true;
	
	licoes[2].codigo = 2;
	licoes[2].cod_Idioma = 6;
	licoes[2].total_Niveis = 100;
	licoes[2].status = true;
	
	iLi[0].codigo = 1;
	iLi[0].ender = 0;
	
	iLi[1].codigo = 2;
	iLi[1].ender = 2;
	
	iLi[2].codigo = 5;
	iLi[2].ender = 1;
	
	//Exercícios
	exercicios[0].codigo = 9;
	exercicios[0].nivel_Dificuldade = 1;
	exercicios[0].descricao = "I will win the bike ___!";
	exercicios[0].resposta_Correta = 'race';
	exercicios[0].pontuacao = 25;
	exercicios[0].status = true;
	
	exercicios[1].codigo = 5;
	exercicios[1].nivel_Dificuldade = 1;
	exercicios[1].descricao = "Está frase está correta (S/N) 'soy piloto de avion'";
	exercicios[1].resposta_Correta = 'S';
	exercicios[1].pontuacao = 50;
	exercicios[1].status = true;
		
	exercicios[2].codigo = 6;
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
	
	//Usuario
	usuario[0].codigo = 9;
	usuario[0].cod_Idioma = 5;
	usuario[0].nivel_Atual = 1;
	usuario[0].total_Pontuacao = 50;
	usuario[0].status = true;
	
	usuario[1].codigo = 5;
	usuario[1].cod_Idioma = 9;
	usuario[1].nivel_Atual = 1;
	usuario[1].total_Pontuacao = 50;
	usuario[1].status = true;
	
	usuario[2].codigo = 6;
	usuario[2].cod_Idioma = 6;
	usuario[2].nivel_Atual = 1;
	usuario[2].total_Pontuacao = 0;
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

// Buscas Binárias
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

// Inclusões
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
    		cout << "\n\nInclusao realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont, struct Idiomas idioma[], struct Indice indIdioma[], int contIdioma){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo da Lição a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		licoes[cont].codigo = cod;
    		cout<<"Codigo Idioma: ";
    		cin>> licoes[cont].cod_Idioma;
    		
    		licoes[cont].cod_Idioma = buscaBi(indIdioma, licoes[cont].cod_Idioma, contIdioma);
    		while(licoes[cont].cod_Idioma == -1){
    			cout<<"Idioma não encontrado..."<<endl;
    			cout<<"Digite novamente o codigo do Idioma: ";
    			cin>>licoes[cont].cod_Idioma;
    			licoes[cont].cod_Idioma = buscaBi(indIdioma, licoes[cont].cod_Idioma, contIdioma);
			}
    		
    		cout<<"Idioma: "<<idioma[licoes[cont].cod_Idioma].descricao<<endl;
    		
    		cout<<"Total de níveis: ";
    		cin>>licoes[cont].total_Niveis;
    		licoes[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusao realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo do Exercício a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		exercicio[cont].codigo = cod;
    		cout<<"Nível de dificuldade: ";
    		cin>> exercicio[cont].nivel_Dificuldade;
    		cout<"Descrição: ";
    		cin>> exercicio[cont].descricao;
    		cout<<"Resposta: ";
    		cin>> exercicio[cont].resposta_Correta;
    		cout<<"Ponuação: ";
    		cin>> exercicio[cont].pontuacao;
    		exercicio[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusao realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

void inclusao_Usuarios (struct Indice idx[], struct Usuarios usuario[], int &cont, struct Idiomas idioma[], struct Indice indIdioma[], int contIdioma){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o Codigo do Usuário a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		usuario[cont].codigo = cod;
    		cout<<"Nome: ";
    		cin>> usuario[cont].nome;
    		cout<<"Codigo Idioma: ";
    		cin>>usuario[cont].cod_Idioma;
    		
    		usuario[cont].cod_Idioma = buscaBi(indIdioma, usuario[cont].cod_Idioma, contIdioma);
    		while(usuario[cont].cod_Idioma == -1){
    			cout<<"Idioma não encontrado..."<<endl;
    			cout<<"Digite novamente o codigo do Idioma: ";
    			cin>>usuario[cont].cod_Idioma;
    			usuario[cont].cod_Idioma = buscaBi(indIdioma, usuario[cont].cod_Idioma, contIdioma);
			}
    		
    		cout<<"Idioma: "<<idioma[usuario[cont].cod_Idioma].descricao<<endl;
    		
    		cout<<"Nível Atual: ";
    		cin>>usuario[cont].nivel_Atual;
    		cout<<"Pontuação Total: ";
    		cin>>usuario[cont].total_Pontuacao;
    		usuario[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusao realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

// Exclusão
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
				cout<<"Lingua não encontrada...";
			}
			getch();
		}
	}
}

void desabilitar_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo da Lição (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && licoes[ender].status == true){
				cout<<"Liçao "<<licoes[ender].codigo<<" excluido...";
				licoes[ender].status = false;
			}
			else{
				cout<<"lição não encontrada...";
			}
			getch();
		}
	}
}

void desabilitar_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Exercícios (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && exercicio[ender].status == true){
				cout<<"Exercício "<<exercicio[ender].codigo<<" excluido...";
				exercicio[ender].status = false;
			}
			else{
				cout<<"Exercício não encontrado...";
			}
			getch();
		}
	}
}

void desabilitar_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Usuário (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && usuario[ender].status == true){
				cout<<"Usuário "<<usuario[ender].nome<<" excluido...";
				usuario[ender].status = false;
			}
			else{
				cout<<"Usuário não encontrado...";
			}
			getch();
		}
	}
}

// Recuperação
void recuperar_Idiomas (struct Indice idx[], struct Idiomas idioma[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Idioma (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && idioma[ender].status != true){
				cout<<"Lingua "<<idioma[ender].descricao<<" recuperada...";
				idioma[ender].status = false;
			}
			else{
				cout<<"Lingua não encontrada...";
			}
			getch();
		}
	}
}

void recuperar_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo da Lição (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && licoes[ender].status != true){
				cout<<"Liçao "<<licoes[ender].codigo<<" recuperado...";
				licoes[ender].status = false;
			}
			else{
				cout<<"lição não encontrada...";
			}
			getch();
		}
	}
}

void recuperar_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Exercícios (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && exercicio[ender].status != true){
				cout<<"Exercício "<<exercicio[ender].codigo<<" recuperado...";
				exercicio[ender].status = false;
			}
			else{
				cout<<"Exercício não encontrado...";
			}
			getch();
		}
	}
}

void recuperar_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o Codigo do Usuário (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi(idx, cod, cont);

			if(ender != -1 && usuario[ender].status != true){
				cout<<"Usuário "<<usuario[ender].nome<<" recuperado...";
				usuario[ender].status = false;
			}
			else{
				cout<<"Usuário não encontrado...";
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
		cout<<"Descrição: "<<idioma[aux].descricao<<endl;
	}
}

void leitura_Licoes (struct Indice idx[], struct Licoes licoes[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<licoes[aux].codigo<<endl;
		cout<<"Codigo do Idioma: "<<licoes[aux].cod_Idioma<<endl;
		cout<<"Total de Níveis: "<<licoes[aux].total_Niveis<<endl;
	}
}

void leitura_Exercicios (struct Indice idx[], struct Exercicios exercicio[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<exercicio[aux].codigo<<endl;
		cout<<"Nível de Dificuldade: "<<exercicio[aux].nivel_Dificuldade<<endl;
		cout<<"Descricao: "<<exercicio[aux].descricao<<endl;
		cout<<"Resposta: "<<exercicio[aux].resposta_Correta<<endl;
		cout<<"Pontuação: "<<exercicio[aux].pontuacao<<endl;
		
	}
}

void leitura_Usuario (struct Indice idx[], struct Usuarios usuario[], int &cont){
	for(int i = 0; i < cont; i++){
		int aux = idx[i].ender;
		cout<<"==================================="<<endl;
		cout<<"Codigo: "<<usuario[aux].codigo<<endl;
		cout<<"Nome: "<<usuario[aux].nome<<endl;
		cout<<"Idioma: "<<usuario[aux].cod_Idioma<<endl;
		cout<<"Nivel Atual: "<<usuario[aux].nivel_Atual<<endl;
		cout<<"Total_Pontuação: "<<usuario[aux].total_Pontuacao<<endl;
		
	}
}

// Reorganização
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



int main(){
	setlocale(LC_ALL,"");
	struct Idiomas idioma[30];
	struct Indice indIdioma[30];
	struct Licoes licoes[30];
	struct Indice indLicoes[30];
	struct Exercicios exercicios[30];
	struct Indice indExercicios[30];
	struct Usuarios usuario[30];
	struct Indice indUsuario[30];
	int cont[4];
	
	gerar_dados(idioma, licoes, exercicios, usuario, indIdioma, indLicoes, indExercicios, indUsuario, cont);
}
