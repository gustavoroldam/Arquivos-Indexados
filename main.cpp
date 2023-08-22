#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct indice {
        int codigo;
        int ender;
};
//0
struct paciente {
	int cpf;
	string nome;
	int idade;
	char sexo;
	int telefone;
	string endereco;
	string cidade;
	char uf[2];
};
//1
struct especializacao {
	int id;
	string nome;
};
//2
struct medico {
	int crm;
	string nome;
	int idade;
	char sexo;
	int telefone;
	int codEspecializacao;
	float valorConsulta;
};
//3
struct consulta {
	int cpfPaciente;
	int crmMedico;
	string data;
	string horario;
};

void gerar_dados(paciente, especializacao, medico, consulta, indice, int);

int main(){
	
}

void gerar_dados(paciente p[], especializacao e[], medico m[], consulta c[], indice i[][], int cont[]){
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
	
	i[0][0].codigo = 5;
	i[0][0].ender = 1;
	
	i[1][0].codigo = 6;
	i[1][0].ender = 2;
	
	i[2][0].codigo = 9;
	i[2][0].ender = 0;
	
	//Especialidade
	e[0].id = 1;
	e[0].nome = "Cardiologista";
	
	e[1].id = 5;
	e[1].nome = "Pediatra";
	
	e[2].id = 2;
	e[2].nome = "Ortopedista";
	
	i[0][1].codigo = 1;
	i[0][1].ender = 0;
	
	i[1][1].codigo = 2;
	i[1][1].ender = 2;
	
	i[2][1].codigo = 5;
	i[2][1].ender = 1;
	
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
	
	i[0][2].codigo = 4;
	i[0][2].ender = 2;
	
	i[1][2].codigo = 5;
	i[1][2].ender = 0;
	
	i[2][2].codigo = 10;
	i[2][2].ender = 1;
	
	//Consulta
	c[0].cpfPaciente = 9;
	c[0].crmMedico = 5;
	c[0].data = "29/06/2024";
	c[0].horario = "19:00";
}
