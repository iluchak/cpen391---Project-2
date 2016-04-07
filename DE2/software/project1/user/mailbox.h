#ifndef MAILBOX_H_
#define MAILBOX_H_

#include "user.h"
#define MAILBOX_SIZE 293

typedef struct Mailbox{
	char* msg;
	int blk_mult;
	char* key;
	char* iv;
	char sender;
	char receiver;
} Mailbox;

Mailbox* new_mailbox();
void init_mailbox(char receiver, char sender, char* msg, char* key, char* iv, int blk_mult, Mailbox* mailbox);
void check_mailbox(int user_id);
void send_mail(char receiver, char sender, char* msg, char* key, char* iv, int blk_mult);
void read_mail(Mailbox mailbox);
void clear_mail(int user_id);
void print_message(int user_id);

#endif /* MAILBOX_H_ */
