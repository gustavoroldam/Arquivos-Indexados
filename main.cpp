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
	
	m[1].crm = 10;
	m[1].nome = "Dr.Orto";
	m[1].idade = 58;
	m[1].sexo = 'M';
	m[1].telefone = 852147963;
	m[1].codEspecializacao = 2;
	m[1].valorConsulta = 200;
	
	m[2].crm = 4;
	m[2].nome = "Dr.Pediatra";
	m[2].idade = 38;
	m[2].sexo = 'F';
	m[2].telefone = 369847521;
	m[2].codEspecializacao = 5;
	m[2].valorConsulta = 500;
	
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
void inclusao_cliente (struct indice idx[], struct paciente pa[], int &cont){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o CPF do Cliente a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
        	cont++;
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
    		for (i = cont - 1; idx[i].codigo > cod; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusao realizada com Sucesso";
    		getch();
    	}
    }
}
//3 - Inclusão Medico
void inclusao_medico (struct indice idx[], struct medico med[], int &cont){
    for (int cod = 9; cod != 0;){
        cout<<"\n\nInforme o CRM do Médico a ser Incluido (0 para Encerrar): ";
        cin>>cod;
        if (cod != 0){
        	cont++;
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
    		cout<<"Cidade: ";
    		cin>>med[cont].cidade;
    		cout<<"Estado: ";
    		cin>>med[cont].uf;
    		int i;
    		for (i = cont - 1; idx[i].codigo > cod; i--){
        		idx[i+1].codigo = idx[i].codigo;
        		idx[i+1].ender = idx[i].ender;
    		}
    		idx[i+1].codigo = cod;
    		idx[i+1].ender = cont;
    		cout << "\n\nInclusao realizada com Sucesso";
    		getch();
    	}
    }
}

int main(){
	//Configurações Iniciais
	setlocale(LC_ALL,"");
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
}
