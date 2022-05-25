#include <stdio.h>
#include <stdlib.h>
#define max 40
void create_list(int x,int []);
void bastir_list();
void seviye_olustur(int dizi2[],int *x,int adres[]);
void eleman_arama(int eleman);
void random_eleman(int dizi2[],int *x,int *seviye);
void ekle(int data);


struct n{
 int data;
 struct n *next;
 struct n *next2;
}*head;
typedef struct n node;
 
int main(void){
	int i;
    int x;
    int eleman;
    int seviye=2;
    int adres[max];
    int dizi2[max];
    srand(time(0));
    printf("ne kadarlik linked list:");
    scanf("%d",&x);
    printf("aradiginiz eleman:");
    scanf("%d",&eleman);
    create_list(x,adres);
    eleman_arama(eleman);
    array_yazdir(adres,x);
    printf("\n\n");
    bastir_list();
   	ekle(75);
    printf("\n\n");
    random_eleman(dizi2,&x,&seviye);
    printf("\n\n");
    array_yazdir(dizi2);
    seviye_olustur(dizi2,x,adres);
   
    
    
    
    
}
//linli liste olusturup adresleri diziye atma fonk.
void create_list(int x, int adres[]){
    int num,i;
    node *fn,*tmp;
    head=(node *)malloc(sizeof(node));
    adres[0]=head;
    printf("1. node input degeri:");
    scanf("%d",&num);
    head->data=num;
    head->next=NULL;
    tmp=head;
    for(i=1;i<x;i++){
        fn=(node *)malloc(sizeof(node));
        adres[i]=fn;
        printf("%d. node input degeri:",i+1);
        scanf("%d",&fn->data);
        fn->next=NULL;
        tmp->next=fn;
        tmp=tmp->next;
    }
}
//seviye guncellemesi ardindan adres dizisi yazdirma fonk.
void array_yazdir(int adres[],int x){
	int i;
	for(i=0;i<x;i++){
		printf("%d\n",adres[i]);
	}
}
//tum link listi bastirma
void bastir_list(){
    node *tmp;
    if(head==NULL){
        printf("bu liste bos\n");
    }
    else{
        tmp=head;
        while(tmp!=NULL){
            printf("%d\n",tmp->data);
            tmp=tmp->next;
        }
    }
}
//random eleman secme fonk.
void random_eleman(int dizi2[],int *x,int *seviye){
		int i;
		if(*seviye==2){
			for(i=0;i<6;i++){
				dizi2[i]= rand() % *x;
			}
			*x=6;
		}
}

void seviye_olustur(int dizi2[],int *x,int adres[]){
	int i;
	node *tmp,*fn;
	tmp=head;
	for(i=1;i<*x;i++){
		fn=(node *)adres[dizi2[i]];
		fn->next=NULL;
		tmp->next=fn;
        tmp=tmp->next;
	}

	
}

void eleman_arama(int eleman){
	int count=0;
	node *tmp,*fn;
	tmp=head;
	while(tmp->next!=NULL && tmp->data!=eleman){
		count++;
		tmp=tmp->next;
	}
	printf("\naradiginiz eleman %d. sirada\n",count+1);
	
}

   void ekle(int data){
	int key;
	node *tmp;
	node *yeni=(node *)malloc(sizeof(node));
	yeni->data=data;
	yeni->next=NULL;
	key=data;
	if(head==NULL || key<head->data){
		yeni->next=head;
		head=yeni;
	}
	else{
		tmp=head;
		while(tmp->next!=NULL && tmp->next->data<key){
			tmp=tmp->next;
			yeni->next=tmp->next;
			tmp->next=yeni;
		}
		return head;
	}
}
	





