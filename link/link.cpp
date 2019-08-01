
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 100

typedef struct Node *Link;
struct Node {
	char c;
	Link next;
};

Link createLink(char *str) {
	Link head, p, q;
	int i = 0;
	int len = strlen(str);
	for(; i < len; ++i) {
		if (i == 0) {
			head = (Link)malloc(sizeof(Node));
			head->c = str[i];
			head->next = NULL;
			p = head;
		} else {
			q = (Link)malloc(sizeof(Node));
			q->c = str[i];
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}
	return head;
}

void deleteLink(Link head) {
    //todo
}

bool judge(Link head, int len) {
	bool flag = false;
	Link slow = head;
	Link fast = head;
	Link p, q;
	q = NULL;
	/* 快慢指针，慢指针执行链表反转操作*/
	while (NULL != slow && NULL != fast && NULL != fast->next) {
		fast = fast->next->next;
		p = slow->next;
		slow->next = q;
		q = slow;
		slow = p;	
	}
	
	if (len%2 != 0) {
		slow = slow->next;
	}
	while (NULL != slow && NULL != q) {
		if (slow->c != q->c) {
			flag = false;
			break;
		}
		slow = slow->next;
		q = q->next;
	}
	if (NULL == slow && NULL == q) {
		flag = true;
	}
	return flag;
}

int main() {
	char str[MAXCHAR];
	scanf("%s",str);
	Link head = createLink(str);
	
	int len = strlen(str);
	bool flag = judge(head, len);
	
	if(flag) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
}
