#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
	char *name;
	char *opens;
	char *closes;
	struct island * next;
} island;



void display(island *start){ /*вывод на экран */
	island *i = start;
	for ( ; i != NULL; i=i->next){ /* i=(*i).next */
		printf("Name %s, open %s, close %s\n", i->name, i->opens, i->closes);
	}
}

island *create (char *name){ /*новый остров в конец списка + первый остров*/
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "9-00";
	i->closes = "18-00";
	i->next = NULL;
	return i;
}

void search(island *start,char *name){

    int p = strcmp(start->name,name);
    island *i = start;
	while(p!=0 && i->next != NULL) /*нужна проверка строк на равенство*/
        {
            i = i->next;
            p = strcmp(i->name,name);


        }
    if(p!=0)
         printf("No element with such name\n");


    else
        printf("Name %s, open %s, close %s\n", i->name, i->opens, i->closes);

}

void release(island *start){ /*очищение памяти */

	island *i = start;
	island *next = NULL;
	for ( ; i != NULL ; i = next){
		next = i->next;
		free(i->name);
		free(i);
	}
}

island *releaselast(island *start,island *end){

	island *i = start;


    while(i->next != end)
        i = i->next;
    free(end->name);
    free(end);
    i->next = NULL;
    return i;



}



int main(){
    int i,c=1;
    island *start = NULL;/*указатель на первый остров*/
    island *end = NULL;/*указатель на последний остров*/
    island *curr = NULL;/*указатель на вновь создаваемый,удаляемый остров*/
    char name[80];
    while(i!=7 && c==1)
    {
        printf("Menu:\n1) Create first element\n2) Append element\n3) Remove element\n4) Display\n5) Delete\n6) Search\n7) Exit\n");
        c=scanf("%d",&i);

        if(i==1)
        {
            if(start == NULL)
            {
                scanf("%s",name);
                start = create(name);
                end = start;
            }
            else
                printf("First element already exists\n");
        }
        if(i==2)
        {
            if(start == NULL)
                printf("First element is not created yet\n");
            else
                {
                    scanf("%s",name);
                    curr = create(name);
                    end->next = curr;
                    end = curr;
                }
            }
        if(i==3)
        {
            if(start == NULL)
                printf("First element is not created yet\n");
            else
            {
                if(start->next == NULL)
                    {
                        start=NULL;
                        end = NULL;
                    }
                else
                    end = releaselast(start,end);
            }

        }
        if(i==4)
        {
            display(start);
        }
        if(i==5)
        {
                release(start);
                start = NULL;
                end = NULL;
        }
        if(i==6)
        {

            if(start==NULL)
                printf("First element is not created yet\n");
            else
                {
                    scanf("%s",name);
                    search(start,name);
                }
        }
        if(i==7)
        {
            if(start!=NULL)
                printf("You forgot to clean memory...");
            release(start);
            exit(0);

        }

    }




    return 0;

}
