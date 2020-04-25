#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define INIT_STR_MAX 100000
#define CMD_LEN 1

typedef struct _node {
	char c;
	_node *prev;
	_node *next;

	_node() : c('\0'), prev(NULL), next(NULL) {};
	_node(char _c, _node *_prev, _node *_next) : c(_c), prev(_prev), next(_next) {};
} Node;

class CharList {
private:


private:
	Node *head;
	Node *tail;
	Node *cursor;

public: 
	CharList();
	CharList(char init_str[INIT_STR_MAX + 1]);
	void moveLeft();
	void moveRight();
	void deleteLeft();
	void addChar(char c);
	void print();
};

int main() {
	char init_str[INIT_STR_MAX + 1];
	scanf("%s ", init_str);

	CharList char_list(init_str);

	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		char cmd[CMD_LEN + 1];
		scanf("%s", cmd);

		if (strncmp(cmd, "L", CMD_LEN) == 0) {
			char_list.moveLeft();
		} else if (strncmp(cmd, "D", CMD_LEN) == 0) {
			char_list.moveRight();
		} else if (strncmp(cmd, "B", CMD_LEN) == 0) {
			char_list.deleteLeft();
		} else if (strncmp(cmd, "P", CMD_LEN) == 0) {
			getchar();
			char c;
			scanf("%c", &c);
			char_list.addChar(c);
		}
	}

	char_list.print();
	return 0;
}

CharList::CharList() {
	this->head = new Node;
	this->tail = new Node;
	
	this->head->next = this->tail;
	this->tail->prev = this->head;
	this->cursor = this->head;
}
	
CharList::CharList(char init_str[INIT_STR_MAX + 1]) {
	this->head = new Node;
	this->tail = new Node;
	
	this->head->next = this->tail;
	this->tail->prev = this->head;
	this->cursor = this->head;

	for (int i = 0; init_str[i] != '\0'; i++) {
		addChar(init_str[i]);
	}	
}

void CharList::moveLeft() {
	if (this->cursor == this->head) {
		return;
	}

	this->cursor = this->cursor->prev;
}

void CharList::moveRight() {
	if (this->cursor->next == this->tail) {
		return;
	}

	this->cursor = this->cursor->next;
}

void CharList::deleteLeft() {
	if (this->cursor == this->head) {
		return;
	}

	this->cursor->prev->next = this->cursor->next;
	this->cursor->next->prev = this->cursor->prev;

	Node *r_node = this->cursor;
	this->cursor = this->cursor->prev;
	delete(r_node);
}

void CharList::addChar(char c) {
	Node *new_node = new Node(c, this->cursor, this->cursor->next);
	this->cursor->next->prev = new_node;
	this->cursor->next = new_node;
	this->cursor = new_node;
}

void CharList::print() {
	Node *iter = this->head->next;

	while (iter != this->tail) {
		printf("%c", iter->c);
		iter = iter->next;
	}
	printf("\n");
}