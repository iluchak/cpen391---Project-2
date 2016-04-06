#include "user.h"
#include "mailbox.h"
#include <stdlib.h>
#include <stdbool.h>

void init_users(){
	users = malloc(MAX_USERS*sizeof(User));

	for(int i = 1; i <= MAX_USERS; i++){
		users[i].id = i;
		users[i].logged_in = false;
		users[i].mailbox = new_mailbox();
		users[i].has_mail = false;
	}
}

int log_in(int user_id){
	if(user_id < 1 || user_id > MAX_USERS){
		printf("Reject invalid ID\n");
		return REJECT;
	}
	else if(users[user_id].logged_in){
		printf("Reject because logged in\n");
		return REJECT;
	}
	else{
		printf("Accept\n");
		users[user_id].logged_in = true;
		return ACCEPT;
	}
}

void log_out(int user_id){
	users[user_id].logged_in = false;
}


