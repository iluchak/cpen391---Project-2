#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "control.h"
#include "graphics.h"
#include "misc_helpers.h"
#include "button.h"
#include "search.h"
#include <string.h>
#include "graph.h"

// Reset the query string to be empty
void reset_query(){
	sel = 1;
	while(qs_length() > 0){
		del_letter();
	}
}

// Return the current length of the query string
int qs_length(){
	return strlen(query_string);
}

// Check if the query string has space to still add letters
bool has_space(){
	return(qs_length() < MAX_CHAR);
}

// adds a letter to the end of the query string
void add_letter(char letter){
	if(has_space())
		strncat(query_string, &letter, 1);
	draw_word();
}

// delete the end of the query string
void del_letter(){
    int back_index = qs_length()-1;
    OutGraphicsCharFont2a((X + back_index*INCR), Y, WHITE, WHITE, query_string[back_index], 0);
    query_string[back_index] = '\0';
}

// Draw the query string above the pop up keyboard
void draw_word(){
	int x = X;
	for (int i = 0; i < qs_length(); i++){
		OutGraphicsCharFont2a(x, Y, BLACK, WHITE, query_string[i], 0);
		x += INCR;
	}
}

// A match occurs when the string query maps to a name by substring
bool is_matched(char* name){
	bool matches = true;
	if(strstr(name, query_string) == NULL)
		matches = false;
	return matches;
}

void destroy_matches(){
	name_list* nl = matched_names.head;
	name_list* temp;
	while(nl != NULL){
		temp = nl->next;
		free(nl);
		nl = temp;
	}
}

// Search ready to be entered if we have at least one matching entry
bool ready(){
	return(MN_COUNT > 0);
}

// Return the number of names in the name list
int mn_count(name_list* nl){
	int count = 0;
	while(nl != NULL){
		nl = nl->next;
		count++;
	}
	return count;
}

