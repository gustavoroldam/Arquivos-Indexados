#include <iostream>
#include <conio.h>
#include<locale.h>
using namespace std;

struct indice {
        int codigo;
        int ender;
};
//Paciente = 0
struct paciente {
	int cpf;
	string nome;
	int idade;
	char sexo;
	int telefone;
	string endereco;
	string cidade;
	string uf;
};
//Especialização = 1
struct especializacao {
	int id;
	string nome;
};
//Médico = 2
struct medico {
	int crm;
	string nome;
	int idade;
	char sexo;
	int telefone;
	int codEspecializacao;
	float valorConsulta;
	bool status;
};
//Consulta = 3
struct consulta {
	int cpfPaciente;
	int crmMedico;
	string data;
	string horario;
};
//1 - Leitura de Dados
void gerar_dados(struct paciente p[], struct especializacao e[], struct medico m[], struct consulta c[], struct indice iPa[], struct indice iEsp[], struct indice iMed[], struct indice iCon[], int cont[]){
	//Paciente
	p[0].cpf = 9;
	p[0].nome = "Gustavo";
	p[0].idade = 19;
	p[0].sexo = 'M';
	p[0].telefone = 11111111111;
	p[0].endereco = "Rua_A";
	p[0].cidade = "Assis";
	p[0].uf = "SP";
	
	p[1].cpf = 5;
	p[1].nome = "Gui";
	p[1].idade = 20;
	p[1].sexo = 'M';
	p[1].telefone = 123456789;
	p[1].endereco = "Rua_B";
	p[1].cidade = "Assis";
	p[1].uf = "SP";
	
	p[2].cpf = 6;
	p[2].nome = "Karol";
	p[2].idade = 22;
	p[2].sexo = 'F';
	p[2].telefone = 987654321;
	p[2].endereco = "Rua_C";
	p[2].cidade = "Londrina";
	p[2].uf = "PR";
	
	iPa[0].codigo = 5;
	iPa[0].ender = 1;
	
	iPa[1].codigo = 6;
	iPa[1].ender = 2;
	
	iPa[2].codigo = 9;
	iPa[2].ender = 0;
	
	//Especialidade
	e[0].id = 1;
	e[0].nome = "Cardiologista";
	
	e[1].id = 5;
	e[1].nome = "Pediatra";
	
	e[2].id = 2;
	e[2].nome = "Ortopedista";
	
	iEsp[0].codigo = 1;
	iEsp[0].ender = 0;
	
	iEsp[1].codigo = 2;
	iEsp[1].ender = 2;
	
	iEsp[2].codigo = 5;
	iEsp[2].ender = 1;
	
	//Medico
	m[0].crm = 5;
	m[0].nome = "Dr.Cardio";
	m[0].idade = 45;
	m[0].sexo = 'M';
	m[0].telefone = 22222222222;
	m[0].codEspecializacao = 1;
	m[0].valorConsulta = 100;
	m[0].status = true;
	
	m[1].crm = 10;
	m[1].nome = "Dr.Orto";
	m[1].idade = 58;
	m[1].sexo = 'M';
	m[1].telefone = 852147963;
	m[1].codEspecializacao = 2;
	m[1].valorConsulta = 200;
	m[1].status = true;
	
	m[2].crm = 4;
	m[2].nome = "Dr.Pediatra";
	m[2].idade = 38;
	m[2].sexo = 'F';
	m[2].telefone = 369847521;
	m[2].codEspecializacao = 5;
	m[2].valorConsulta = 500;
	m[2].status = true;
	
	iMed[0].codigo = 4;
	iMed[0].ender = 2;
	
	iMed[1].codigo = 5;
	iMed[1].ender = 0;
	
	iMed[2].codigo = 10;
	iMed[2].ender = 1;
	
	//Consulta
	c[0].cpfPaciente = 9;
	c[0].crmMedico = 5;
	c[0].data = "29/06/2024";
	c[0].horario = "19:00";
	
	c[1].cpfPaciente = 5;
	c[1].crmMedico = 10;
	c[1].data = "27/09/2024";
	c[1].horario = "15:00";
	
	c[2].cpfPaciente = 6;
	c[2].crmMedico = 4;
	c[2].data = "08/11/2024";
	c[2].horario = "09:00";
	
	iCon[0].codigo = 5;
	iCon[0].ender = 1;
	
	iCon[1].codigo = 6;
	iCon[1].ender = 2;
	
	iCon[2].codigo = 9;
	iCon[2].ender = 0;
	
	cont[0] = 3;
	cont[1] = 3;
	cont[2] = 3;
	cont[3] = 3;
}

//2 - Inclusão Paciente
void inclusao_Paciente (struct indice idx[], struct paciente pa[], int &cont){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o CPF do Cliente a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
    		pa[cont].cpf = cod;
    		cout<<"Nome: ";
		    cin>>pa[cont].nome;
    		cout<<"Idade: ";
		    cin>>pa[cont].idade;
    		cout<<"Sexo: ";
		    cin>>pa[cont].sexo;
    		cout<<"Telefone: ";
    		cin>>pa[cont].telefone;
    		cout<<"Endereço: ";
    		cin>>pa[cont].endereco;
    		cout<<"Cidade: ";
    		cin>>pa[cont].cidade;
    		cout<<"Estado: ";
    		cin>>pa[cont].uf;
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

//3.1 / 3.2 - Busca Binária (Especialização)
int buscaBi_Especializacao (struct especializacao esp[], struct indice idx[], int cod, int cont){
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

//3 - Inclusão Medico
void inclusao_Medico (struct indice idx[], struct medico med[], struct indice idxEsp[], struct especializacao esp[], int &cont, int &contEsp){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o CRM do Médico a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
        	int endEsp=-1;
    		med[cont].crm = cod;
    		cout<<"Nome: ";
		    cin>>med[cont].nome;
    		cout<<"Idade: ";
		    cin>>med[cont].idade;
    		cout<<"Sexo: ";
		    cin>>med[cont].sexo;
    		cout<<"Telefone: ";
    		cin>>med[cont].telefone;
    		cout<<"Valor da consulta: ";
    		cin>>med[cont].valorConsulta;
    		cout<<"Especialidade(ID): ";
    		cin>>med[cont].codEspecializacao;
    		endEsp = buscaBi_Especializacao(esp, idxEsp, med[cont].codEspecializacao, contEsp);
    		while(endEsp == -1){
    			cout<<"Especialidade não encontrada..."<<endl;
    			cout<<"Digite novamente a especialidade: ";
    			cin>>med[cont].codEspecializacao;
    			endEsp = buscaBi_Especializacao(esp, idxEsp, med[cont].codEspecializacao, contEsp);
			}
			cout<<"Especialidade: "<<esp[endEsp].nome<<endl;
			med[cont].status = true;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod && i >= 0; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusão realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

//4 - Buscar Medico por Especialização
void buscaMed_Esp (struct indice idx[], struct medico med[], int &cont, struct especializacao esp[]){
	for(int codEsp = 9; codEsp != 0;){
		cout<<"Digite o código da Especialidade (0 para Encerrar): ";
		cin>>codEsp;
		if(codEsp != 0){
			cout<<"Especialização: "<< esp[codEsp].nome<<endl;
			for(int i=0; i<cont; i++){
				int end = idx[i].ender;
				if(codEsp == med[end].codEspecializacao){
					cout<<"============================="<<endl;
					cout<<"Nome: "<<med[end].nome<<endl;
					cout<<"CRM: "<<med[end].crm<<endl;
					cout<<"Valor da consulta: "<<med[end].valorConsulta<<endl;
				}
			}
			getch();
		}
	}
}

//5.3 / 6.2 - Buscar Nome do Méico
int buscaBi_Medico (struct medico med[], struct indice idx[], int cod, int cont){
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
    if (cod == idx[m].codigo && med[idx[m].ender].status == true){
        return idx[m].ender;
    }
    else{
        return -1;
    }
}

//5 - Gerar Consulta
void gerar_Consulta (struct indice idxMed[], struct medico med[], int &contMed, struct paciente pa[], struct consulta con[], struct indice idx[], int &cont){
	for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o CPF do Paciente a realizar a consulta (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
        	int endMed=-1;
    		con[cont].cpfPaciente = cod;
    		cout<<"Data: ";
    		cin>>con[cont].data;
    		cout<<"Horário: ";
    		cin>>con[cont].horario;
    		cout<<"CRM: ";
			cin>>con[cont].crmMedico;
    		endMed = buscaBi_Medico(med, idxMed, con[cont].crmMedico, contMed);
    		while(endMed == -1){
    			cout<<"Médico não encontrado..."<<endl;
    			cout<<"Digite novamente o CRM do médico: ";
    			cin>>con[cont].crmMedico;
    			endMed = buscaBi_Medico(med, idxMed, con[cont].crmMedico, contMed);
			}
			cout<<"Médico: "<<med[endMed].nome<<endl;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusão realizada com Sucesso";
    		cont++;
    		getch();
    	}
    }
}

//6 - Dasabilitar Médico
void desabilitar_Medico (struct indice idx[], struct medico med[], int &cont){
	for(int cod=9; cod != 0;){
		cout<<"\nDigite o CRM do médico (0 para Encerrar): ";
		cin>> cod;
		if(cod !=0 ){
			int ender;
			ender = buscaBi_Medico(med, idx, cod, cont);

			if(ender != -1){
				cout<<"Médico "<<med[ender].nome<<" excluido...";
				med[ender].status = false;
			}
			else{
				cout<<"Médico não encontrado...";
			}
			getch();
		}
	}
}

//7 - Reorganização Médico
void reorganizacao_Medico (struct indice idx[], struct medico med[], int &cont){
	struct medico aux[30];
	int cont2 = 0;

	for(int j= 0; j<cont; j++){
		int i = idx[j].ender;
        if(med[i].status == true){
            idx[cont2].codigo = med[i].crm;
            idx[cont2].ender = cont2;
            aux[cont2] = med[i];

            cont2++;
        }
    }
    
	for(int i= 0; i<cont2; i++){
		int ender = idx[i].ender;
		med[ender] = aux[ender];
	}
	cont = cont2;
	
	cout<<"Tabela Reorganizada...";
	getch();
}

//8 - Calculo de Faturamento da Clínica
void faturamento_Clinica (struct indice idx[], struct consulta con[], int &cont, struct indice idxMed[], struct medico med[], int &contMed){
	float fat=0;
	for(int i = 0; i < cont; i++){
		int ender;
		ender = buscaBi_Medico(med, idxMed, con[i].crmMedico, contMed);
		if(ender != -1){
			fat += med[ender].valorConsulta * 0.05;
		}
	}
	cout<<"A clínica faturou: "<<fat<<" reais...";
	getch();
}

//9 - Varificar o Mais Caro e o Mais Barato
void calculo_Preco(struct indice idx[], struct medico med[], int &cont){
	struct medico barato = med[0], caro = med[0];

	for(int i = 1; i < cont; i++){
		if(barato.valorConsulta > med[i].valorConsulta){
			barato = med[i];
		}
		if(caro.valorConsulta < med[i].valorConsulta){
			caro = med[i];
		}
	}

	cout<<"Médico que cobra mais barato:"<<endl;
	cout<<"Nome: "<<barato.nome<<endl;
	cout<<"Preço: "<<barato.valorConsulta<<endl;
	cout<<"Médico que cobra mais caro:"<<endl;
	cout<<"Nome: "<<caro.nome<<endl;
	cout<<"Preço: "<<caro.valorConsulta<<endl;
	getch();
}

//Bônus - Leitura Exestiva (Todos)
void leitura_Todos(struct paciente p[], struct especializacao e[], struct medico m[], struct consulta c[], struct indice iPa[], struct indice iEsp[], struct indice iMed[], struct indice iCon[], int cont[]){
	cout<<"==========PACIENTE=========="<<endl;
	for(int aux = 0; aux < cont[0]; aux++){
		int i = iPa[aux].ender;
		cout<<"CPF: "<<p[i].cpf<<endl;
		cout<<"Nome: "<<p[i].nome<<endl<<endl;
	}
	
	cout<<"\n===========MÉDICO==========="<<endl;
	for(int aux = 0; aux < cont[2]; aux++){
		int i = iMed[aux].ender;
		cout<<"CRM: "<<m[i].crm<<endl;
		cout<<"Nome: "<<m[i].nome<<endl;
		cout<<"Especialidade: "<<m[i].codEspecializacao<<endl;
		cout<<"Valor da Consulta: "<<m[i].valorConsulta<<endl;
		cout<<"Status: "<<m[i].status<<endl<<endl;
	}
	
	cout<<"\n=======ESPECIALIZAÇÃO======="<<endl;
	for(int aux = 0; aux < cont[1]; aux++){
   		int i = iEsp[aux].ender;
   		cout<<"Id: "<<e[i].id<<endl;
   		cout<<"Nome: "<<e[i].nome<<endl<<endl;
	}
	
	cout<<"\n==========CONSULTA=========="<<endl;
	for(int aux = 0; aux < cont[3]; aux++){
		int i = iCon[aux].ender;
		cout<<"CPF: "<<c[i].cpfPaciente<<endl;
		cout<<"CRM: "<<c[i].crmMedico<<endl;
		cout<<"Data: "<<c[i].data<<endl;
		cout<<"Horário: "<<c[i].horario<<endl<<endl;
	}
	
	getch();
}

int main(){
	//Configurações Iniciais
	setlocale(LC_ALL,"pt-br");
	struct paciente pa[30];
	struct indice indPa[30];
	struct especializacao esp[30];
	struct indice indEsp[30];
	struct medico med[30];
	struct indice indMed[30];
	struct consulta con[30];
	struct indice indCon[30];
	int cont[4];
	gerar_dados(pa, esp, med, con, indPa, indEsp, indMed, indCon, cont);
	
	
	for(bool sair = false; sair == false;){
		system("cls");
		int op;
		cout<<"\tBEM VINDO AO SAUDE+"<<endl;
		cout<<"\tEstas sao suas opcoes:"<<endl;
		cout<<"\t\t1- Incluir Paciente"<<endl;
		cout<<"\t\t2- Incluir Medico"<<endl;
		cout<<"\t\t3- Buscar Medico (Especialidade)"<<endl;
		cout<<"\t\t4- Gerar Consulta"<<endl;
		cout<<"\t\t5- Desabilitar Medico"<<endl;
		cout<<"\t\t6- Reorganizar Medicos"<<endl;
		cout<<"\t\t7- Consultar Faturamento da Clinica"<<endl;
		cout<<"\t\t8- Consultar Consultas (Caras/Baratas)"<<endl;
		cout<<"\t\t9- Consultar Tudo"<<endl;
		cout<<"\t\t10- Sair"<<endl;
		cout<<"\tDigite a opcao desejada: ";
		cin>>op;
		switch(op){
			case 1:{
				system("cls");
				inclusao_Paciente(indPa, pa, cont[0]);
				break;
			}
			
			case 2:{
				system("cls");
				inclusao_Medico(indMed, med, indEsp, esp, cont[2], cont[1]);
				break;
			}
			
			case 3:{
				system("cls");
				buscaMed_Esp(indMed, med, cont[2], esp);
				break;
			}
			
			case 4:{
				system("cls");
				gerar_Consulta(indMed, med, cont[2], pa, con, indCon, cont[3]);
				break;
			}
			
			case 5:{
				system("cls");
				desabilitar_Medico(indMed, med, cont[2]);
				break;
			}
			
			case 6:{
				system("cls");
				reorganizacao_Medico(indMed, med, cont[2]);
				break;
			}
			
			case 7:{
				system("cls");
				faturamento_Clinica(indCon, con, cont[3], indMed, med, cont[2]);
				break;
			}
			
			case 8:{
				system("cls");
				calculo_Preco(indMed, med, cont[2]);
				break;
			}
			
			case 9:{
				system("cls");
				leitura_Todos(pa, esp, med, con, indPa, indEsp, indMed, indCon, cont);
				break;
			}
			
			case 10:{
				system("cls");
				cout<<"Obrigado...";
				sair = true;
				getch();
				break;
			}
			
			default:{
				system("cls");
				cout<<"Opção invalida...";
				getch();
				break;
			}
		}
	}
}