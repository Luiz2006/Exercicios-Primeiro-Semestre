#include <time.h>

struct rgData {
	int dia;
	int mes;
	int ano;
};

struct rgData dataNova(int d, int m, int a){
	struct rgData dt;
	
	dt.dia = d;
	dt.mes = m;
	dt.ano = a;
	return (dt);
}

struct rgData dataHoje(void) {
	struct rgData dt;
	
	time_t tempo;
	struct tm *hj;
	tempo = time(NULL);
	hj = localtime(&tempo);
	dt.dia = hj->tm_mday;
	dt.mes = hj->tm_mon + 1;
	dt.ano = hj->tm_year + 1900;
	
	return (dt);
}

int calculaIdade(struct rgData dt){
	struct rgData hj = dataHoje();
	
	int id = hj.ano - dt.ano;
	if((hj.mes < dt.mes) || ((hj.mes == dt.mes) && (hj.dia < dt.dia))){
		id = id - 1;
	}
	
	return (id);
}
