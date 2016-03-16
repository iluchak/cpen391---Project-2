#include <stdio.h>

#include "control.h"
#include "bluetooth.h"

int main(void) {
	while (1){
		char c = getCharBluetooth();
		if (c != " "){
			printf("%c", c);
		}
	}
	while(1){
		unsigned length;
		char sender, receiver;
		char* msg = getMessage(&length, &receiver, &sender);
		printf("message from: %c \n", receiver);
		printf("message to: %c \n", sender);
		printf("message: %s \n", msg);
		sendMessage(length, receiver, sender, msg);
	}
	printf("\nDONE\n");
	return 0;
}