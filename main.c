#include <stdio.h>
#include <string.h>

// variabel dfa menggambarkan string berakhir di state mana.
int dfa = 0;

// fungsi ini merupakan bentuk dari state Q0
void start(char c) {
	if (c == '0') {
		dfa = 2;
	} else if (c == '1') {
		dfa = 1;
	} else {
		dfa = -1;
	}
}

// fungsi ini merupakan bentuk dari state Q1
void state1(char c) {
	if (c == '0') {
		dfa = 3;
	} else if (c == '1') {
		dfa = 0;
	} else {
		dfa = -1;
	}
}

// fungsi ini merupakan bentuk dari state Q2
void state2(char c) {
	if (c == '0') {
		dfa = 0;
	} else if (c == '1') {
		dfa = 3;
	} else {
		dfa = -1;
	}
}

// fungsi ini merupakan bentuk dari state Q3
void state3(char c) {
	if (c == '0') {
		dfa = 1;
	} else if (c == '1') {
		dfa = 2;
	} else {
		dfa = -1;
	}
}

int isAccepted(char str[]) {
	int i, len = strlen(str);

	for (i = 0; i < len; i++) {
		if (dfa == 0) {
			start(str[i]);
		} else if (dfa == 1) {
			state1(str[i]);
		} else if (dfa == 2) {
			state2(str[i]);
		} else if (dfa == 3) {
			state3(str[i]);
		} else {
			return 0;
		}
	}
	
	if (dfa == 0) {
		return 1;	
	} else {
		return 0;	
	}
}

// main code
int main() {
	char str[20];
	
	printf("Input String : ");
  	scanf("%s", str);
 
	printf("\n");
	
	if (isAccepted(str)) {
		printf("INPUT DITERIMA");
	} else {
		printf("INPUT TIDAK DITERIMA");
	}
	
	printf("\n");
	printf("\n");
	
	printf("---Tekan Enter---");
	getch();
		
	return 0;
}
