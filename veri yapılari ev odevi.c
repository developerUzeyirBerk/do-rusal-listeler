#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Define a structure for linked list node
struct nodes {
    struct nodes* next;
    int data;
};
typedef struct nodes node;
//Define a structure for student
struct students {
    char name[30];
    int age;
    int no;
    struct students* next;
};
typedef struct students student;

//parameters
void listShow(node *head);
node* listCreate1(node *head);
void getInfo(node *temp);
node* listCreate2(node *head);
student* listCreateStudent(student *head2);
void listShowAllStd(student *node);
void getInfoStudent(student *temp);
void ogrenciAra(student *head2,char aranan[]);
void dellNext(student *head2,char aranan[]);
void longestName(student *head2);

int main() {
    node *head = NULL;
    student *head2 = NULL;
    char c;
    char aranan[30];
    printf("Secim yapin secimler 1/2/3/4/5/6 sorulari temsil etmektedir.\n"  //You can choose the procedure you want to have done
           "1-Klavyeden -1 girilinceye kadar, girilen tum tek sayilari listenin basina, cift sayilari listerin sonuna ekleyen fonksiyon\n"
           "2-Listeye rastgele uretilmis 100 sayi eklenir, girilen tum sayilari buyukten kucuge siralayan ve ekrana basan fonksiyon\n"
           "3-Ogrenci numarasi, isim ve yasinin sakli tutuldugu, listedeki tum dugumleri dolan, ogrenci bilgilerinin tumunu ekrana yazan ve sayan fonksiyon\n"
           "4-Listede ogrenci adina gore kayit arama yapan fonksiyon\n"
           "5-Listede aranan ogrenci adinin yer aldigi dugumden bir sonraki dugumu silen fonksiyon\n"
           "6-Listede en uzun ismin oldugu kayit\n");
    c = getchar();
    switch (c) {
        case '1':
            head = listCreate1(head);
            listShow(head);
            break;
        case '2':
            head = listCreate2(head);
            listShow(head);
            break;
        case '3':
            head2 = listCreateStudent(head2);
            listShowAllStd(head2);
            break;
        case '4':
        	head2 = listCreateStudent(head2);
        	fflush(stdin);
        	gets(aranan);
        	ogrenciAra(head2,aranan);
            break;
        case '5':
        	head2 = listCreateStudent(head2);
        	fflush(stdin);
        	gets(aranan);
        	dellNext(head2,aranan);
        	listShowAllStd(head2);
            break;
        case '6':
        	head2 = listCreateStudent(head2);
        	longestName(head2);
            break;
        default:
            printf("Gecersiz secim.");
            break;
    }
    return 0;
}

void longestName(student *head2){
	student longestN;
	longestN =* head2;
	head2 = head2 -> next;
	while(head2 != NULL){
		if(strlen(head2 -> name) > strlen(longestN. name)){
			longestN =* head2;
		}
		head2 = head2 -> next;
	}
	printf("%s %d %d\n", longestN.name, longestN.age, longestN.no);
}

void dellNext(student *head2,char aranan[]){  //This function allows us to delete name from the list.
	while(head2 != NULL && strcmp(head2 -> name, aranan) != 0)
		head2 = head2 -> next;
	if(head2 == NULL)
		printf("Aranan isim listede yok");
	else if(head2 -> next == NULL){
		printf("Aranan isimden sonraki dugum null");
	}
	else{
		student *willDell;
		willDell = head2 -> next;
		head2 -> next=willDell -> next;
		free(willDell);
	}
}

void ogrenciAra(student *head2,char aranan[]){ //This function allows us to find the name we are looking for in the list.
	while(head2 != NULL && strcmp(head2->name,aranan)!=0)
		head2=head2->next;
	if(head2 == NULL)
		printf("Aranan isim listede yok\n");
	else{
		printf("%s %d %d\n", head2->name, head2->age, head2->no);
	}
}

student* listCreateStudent(student* head2) {
    int numberOfStudents, i;
    student* temphead;
    printf("Lutfen ogrenci sayisini girin: ");
    scanf("%d", &numberOfStudents);
    for (i = 0; i < numberOfStudents; i++) {
        if (head2 == NULL) {
            head2 = (student*)malloc(sizeof(student));
            getInfoStudent(head2);
            head2->next = NULL;
            temphead = head2;
        } else {
            temphead->next = (student*)malloc(sizeof(student));
            temphead = temphead->next;
            getInfoStudent(temphead);
            temphead->next = NULL;
        }
    }
    return head2;
}

node* listCreate2(node* head) { //With this function we added 100 random numbers to the list
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

node* listCreate1(node* head) { //With this function, we add all odd numbers to do beginning of the list and all even numbers to the end of the list
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

void listShowAllStd(student* node) {
    int i = 1;
    while (node != NULL) {
        printf("%d - %s %d %d\n", i++, node->name, node->age, node->no);
        node = node->next;
    }
}

void getInfo(node* temp) {
    printf("Lutfen data girin: ");
    scanf("%d", &temp->data);
}

void getInfoStudent(student* temp) { //With this function, we add data in the student list
    printf("Isim girin: ");
    fflush(stdin);
    scanf("%s", temp->name);
    printf("Yas girin: ");
    scanf("%d", &temp->age);
    printf("No girin: ");
    scanf("%d", &temp->no);
}
