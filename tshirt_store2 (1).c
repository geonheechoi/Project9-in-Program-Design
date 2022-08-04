#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
Author:Geonhee Choi project9-> This program's read_line function read
 the student organization,size->and then, add node as inventory parameter as ordered linkedlist->  search tshirt by name of organization,size
and then print the organization's name,size,t-shirt price, quantity-> clear inventory (list)



*/


//////////////////////
// data definitions //
//////////////////////

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt {
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;



	struct tshirt *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

struct tshirt *add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);


void help();

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() {
	char code;

	struct tshirt *inventory = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		printf("%c",code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);

				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':

				print_inventory(inventory);

				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}



//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}

struct tshirt *add_to_inventory(struct tshirt *inventory) {
//add to inventory
  struct tshirt *cur, *prev, *new_node;
//make 3 pointers
  new_node = malloc(sizeof(struct tshirt));    //allocate memory
  if (new_node == NULL) {
    printf("Database is full; malloc failed.\n");
    return inventory;  //check is it null
  }


  //read elements whatever to execute program
  printf("Student organization");
read_line(new_node->org_name,ORG_NAME_LEN);

  printf("%s",new_node->org_name);
   printf("Enter size  ");
  read_line(new_node->size, SIZE_LEN);

    printf("%s",new_node->size );

  printf("%s",new_node->size);

   printf("Enter the price");
  scanf("%lf",&new_node->price);
  printf("%g",new_node->price);
  printf("Enter quantity on hand: ");

  scanf("%d", &new_node->quantity);
  printf("%d",new_node->quantity );

    cur = inventory;// ,make oredered linkedlist
     prev=NULL;   //initialize prev

 while( cur != NULL){

   if(strcmp(new_node->org_name,cur->org_name)<0)
   {  //compare organization does not match
  break;

   }
     else if(strcmp(new_node->org_name,cur->org_name)==0){
       if(strcmp(new_node->size,cur->size)<0){
      break;  // if size does not order list
         }
       }
       prev = cur;
      cur= cur->next;    //update node
   }
  new_node->next=cur;
  if(prev==NULL)
    return new_node;   //if prev null,return new_node
    else {

    prev->next=new_node;
    return inventory;   //update all and return to inventory

    }
  }

void search_by_organization(struct tshirt *inventory) {

   struct tshirt *temp; //make pointer
    char search_a[ORG_NAME_LEN];//search t shirt array

  int flag = 0; //flag=0

  for (temp = inventory; temp != NULL; temp = temp->next)//iterate
  {
    if (strcmp(temp->org_name, search_a) == 0)//find if org_name alredy exits
    {
      flag = 1;


        printf("|----------------------------------------------------|-----|-------|------|\n");
        printf("| Student organization                               | Sz. | Price | Qty. |\n");
        printf("|----------------------------------------------------|-----|-------|------|\n");
        printf("| %-50s | %-3s | %5.2f | %4d |\n", temp->org_name, temp->size,temp->price,temp->quantity);
        printf("|----------------------------------------------------|-----|-------|------|\n");


    //print them all

    }
  }

  if (flag  == 0)  //if flag is 0 print no tshirt
  {
    printf(" No t-shirt found!\n");
  }


  }



void search_by_size(struct tshirt *inventory) {

  char search_t[SIZE_LEN];

  struct tshirt *tem;//make pointer to find tshirt



  int exists = 0;//flag as exits

  for (tem = inventory; tem != NULL; tem = tem->next)
  {
    if (strcmp( search_t,tem->size) == 0)  //find if size is same
    {
      exists = 1;
        printf("|----------------------------------------------------|-----|-------|------|\n");
        printf("| Student organization                               | Sz. | Price | Qty. |\n");
        printf("|----------------------------------------------------|-----|-------|------|\n");
        printf("| %-50s | %-3s | %5.2f | %4d |\n", tem->org_name, tem->size,tem->price,tem->quantity);
        printf("|----------------------------------------------------|-----|-------|------|\n");


   //print them all

    }
  }

  if (exists == 0) //if flag=0
  {
    printf("No t-shirt found!\n");
  } //no tshirt find




}
//print all student organization,size, price,quantity
void print_inventory(struct tshirt *inventory) {

   struct tshirt *p;



  for (p = inventory; p != NULL; p = p->next)
  {






	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| Student organization                               | Sz. | Price | Qty. |\n");
	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size,p->price,p->quantity);
	printf("|----------------------------------------------------|-----|-------|------|\n");
}
}


void clear_inventory(struct tshirt *inventory) {
//clear the inventory list

  struct tshirt *p;
  while(inventory!= NULL)
  {
	    p = inventory;
      inventory = inventory->next;
      if( p!= NULL)
           free(p);
  }



}
//read all
int read_line(char str[], int n) {
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

