#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Define a structure for linked list node
struct nodes {
    struct nodes* next;
    int data;
}; 
//Define a structure for student
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};
//parameters
void listShow(node* head);
node* addEvenOdd(node* head);
void getInfo(node* temp);
node* addRandom(node* head);
student* listCreate3(student* head2);
void listShow3(student* node);
void getInfo3(student* temp);
void searchStudent(student *head2,char wanted[]);
void dellNext(student *head2,char wanted[]);

int main() {
    node* head = NULL;
    student* head2 = NULL;
    char c;
    char aranan[30];
    printf("select one (1, 2, 3, 4, 5 or 6): "); //You can choose the procedure you want to have done
    c = getchar();
    switch (c) {
        case '1':
            head = addEvenOdd(head);
            listShow(head);
            break;
        case '2':
            head = addRandom(head);
            listShow(head);
            break;
        case '3':
            head2 = listCreate3(head2);
            listShow3(head2);
            break;
        case '4':
        	head2 = listCreate3(head2);
        	fflush(stdin);
        	gets(wanted);
        	ogrenciAra(head2,wanted);
            break;
        case '5':
        	head2 = listCreate3(head2);
        	fflush(stdin);
        	gets(wanted);
        	dellNext(head2,wanted);
        	listShow3(head2);
            break;
        case '6':
            break;
        default:
            printf("Invalid selection!");
            break;
    }
    return 0;
}

void dellNext(student *head2,char wanted[]){ //This function allows us to delete name from the list.
	while(head2!=NULL&&strcmp(head2->name,wanted)!=0)
		head2=head2->next;
	if(head2==NULL)
		printf("The name you are looking for is not on the list");
	else if(head2->next==NULL){
		printf("Next node is null");
	}
	else{
		student *willDell;
		willDell=head2->next;
		head2->next=willDell->next;
		free(willDell);
	}
}

void searchStudent(student *head2,char wanted[]){ //This function allows us to find the name we are looking for in the list.
	while(head2!=NULL&&strcmp(head2->name,wanted)!=0)
		head2=head2->next;
	if(head2==NULL)
		printf("The name you are looking for is not on the list\n");
	else{
		printf("%s %d %d\n", head2->name, head2->age, head2->no);
	}
}

student* listCreate3(student* head2) { //
    int numberOfStudents, i;
    student* temphead;
    printf("Please enter student's number: ");
    scanf("%d", &numberOfStudents);
    for (i = 0; i < numberOfStudents; i++) {
        if (head2 == NULL) {
            head2 = (student*)malloc(sizeof(student));
            getInfo3(head2);
            head2->next = NULL;
            temphead = head2;
        } else {
            temphead->next = (student*)malloc(sizeof(student));
            temphead = temphead->next;
            getInfo3(temphead);
            temphead->next = NULL;
        }
    }
    return head2;
}

node* addRandom(node* head) { //With this function we added 100 random numbers to the list
    srand(time(NULL));
    head = (node*)malloc(sizeof(node));
    node* temphead = head;
    int i1, i2, i3;
    for (i1 = 0; i1 < 100; i1++) {
        temphead->data = rand();
        if (i1 == 99) {
            temphead->next = NULL;
        } else {
            temphead->next = (node*)malloc(sizeof(node));
            temphead = temphead->next;
        }
    }
    temphead = head;
    for (i1 = 0; i1 < 99; i1++) {
        for (i2 = 0; i2 + i1 < 99; i2++) {
            if (temphead->data < temphead->next->data) {
                node* temp;
                temp = temphead->next;
                temphead->next = temphead->next->next;
                temp->next = temphead;
                if (i2 == 0) {
                    head = temp;
                } else {
                    node* temp2 = head;
                    for (i3 = 0; i3 < i2 - 1; i3++)
                        temp2 = temp2->next;
                    temp2->next = temp;
                }
            }
            temphead = temphead->next;
        }
        temphead = head;
    }
    return head;
}

node* addEvenOdd(node* head) { //With this function, we add all odd numbers to do beginning of the list and all even numbers to the end of the list
    node* temp = (node*)malloc(sizeof(node));
    getInfo(temp);
    while (temp->data != -1) {
        if (head == NULL) {
            temp->next = NULL;
            head = temp;
        } else if (temp->data % 2 != 0) {
            temp->next = head;
            head = temp;
        } else {
            temp->next = NULL;
            node* temphead = head;
            while (temphead->next != NULL)
                temphead = temphead->next;
            temphead->next = temp;
        }
        temp = (node*)malloc(sizeof(node));
        getInfo(temp);
    }
    free(temp);
    return head;
}

void listShow(node* head) { 
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void listShow3(student* node) {
    int i = 1;
    while (node != NULL) {
        printf("%d - %s %d %d\n", i++, node->name, node->age, node->no);
        node = node->next;
    }
}

void getInfo(node* temp) {
    printf("Please enter data: ");
    scanf("%d", &temp->data);
}

void getInfo3(student* temp) { //With this function, we add data in the student list
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", temp->name);
    printf("Enter age: ");
    scanf("%d", &temp->age);
    printf("Enter student number: ");
    scanf("%d", &temp->no);
}
