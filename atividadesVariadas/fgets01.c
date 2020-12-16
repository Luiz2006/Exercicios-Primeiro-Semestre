#include <stdio.h>
#include <string.h>

/* Atua como se fosse a fgets sendo chamada com o fluxo da entrada padr�o, stdin,
   mas n�o inclui a nova linha na string */
char* lerStringSeguramente(char* string, int tamanho) {
	if(fgets(string, tamanho, stdin) != NULL) {
		/* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
		int indiceUltimoCaractere = strlen(string) - 1;
		if(string[indiceUltimoCaractere] == '\n') {
			string[indiceUltimoCaractere] = '\0';
		}
		return string;
	}

	return NULL;
}

int main() {
	char string[1024]; /* uma linha � representada, normalmente, por 1024 caracteres */

	printf("Nome: ");

	/* N�o existe a possibilidade de buffer overflows utilizando esse c�digo */
	lerStringSeguramente(string, sizeof(string));
	if(lerStringSeguramente(string, sizeof(string)) != NULL) {
		printf("Seu nome � %s\n", string);
	} else {
		puts("Erro ao ler da entrada padr�o.");
	}

	return 0;
}
