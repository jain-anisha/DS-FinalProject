#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

struct node{
    char *name;
    int bday;
    // stored as mmdd (year not needed in this case)
    int wishYN;
    int levelOfRela;
    struct node *next;
    // creating the node
};

//need a head

struct node *head = NULL;       //making the head node as a global

void makelist(int n, char** person, int* relaVal, int* date, int * wish){
    int val;
    struct node *temp;                  // points to the 
    struct node *new;

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == NULL){return;}

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    head -> next = NULL;                // the next pointer points to a null val
    head -> levelOfRela = relaVal[0];   // the val in the node is the val inputed into function
    head -> bday = date[0];
    head -> wishYN = wish[0];
    head -> name = person[0];
    temp = head;                        // special condition for the first node, since we need to connect the head

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 1; i < n; i++){
        new = (struct node *)malloc(sizeof(struct node));
            // same the the previous print statement, no difference
            new -> next = NULL;                 // the next ptr of the new node is NULL
            new -> levelOfRela = relaVal[i];
            new -> bday = date[i];
            new -> wishYN = wish[i];
            new -> name = person[i];

            temp -> next = new;     //
            temp = temp -> next;
    }
}

struct other{
    int level;
    int doneBefore;
    char *idea; 
    struct other *next;
};

struct other *head2 = NULL;       //making the head node as a global

void ideas(int n, char ** ideaList, int * levelOfIdea){
    struct other *temp;                  // points to the 
    struct other *new;

    head2 = (struct other *)malloc(sizeof(struct other));      //making the head node

    if(n <= 0 || head2 == 0){
        return;
    }

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    head2 -> next = NULL;                // the next pointer points to a null val
    head2 -> level = levelOfIdea[0];     // the val in the node is the val inputed into function
    head2 -> doneBefore = 0;
    head2 -> idea = ideaList[0];
    temp = head2;                        // special condition for the first node, since we need to connect the head

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 1; i < n; i++){
        new = (struct other *)malloc(sizeof(struct other));
            // same the the previous print statement, no difference
            
            new -> next = NULL;     // the next ptr of the new node is NULL
            new -> level = levelOfIdea[i];       // the value of val in the new node is the inputted val
            new -> doneBefore = 0;
            new -> idea = ideaList[i];

            temp -> next = new;     //
            temp = temp -> next;
    }
}

void person(int n){
    /*
    inputs: a person

    From that person:
        - outputs birthdate 
        - Whether they wished you or not
        - if they wished you:
            - outputs an idea that has not been done before 
    */
    int bdaynum;
    int inputRelaLevel;
    int i = 0;

    char inputName[15];
    printf("Which person do you want to wish? ");
    scanf("%s", inputName);

    struct node * search = head;
    struct other * ideaptr = head2;
    while(i < n ){
        if (strcmp(search -> name, inputName) == 0){
            // conversion of the birthday stored value to a readable value for the user.
            printf("%s's birthday is ", inputName);
            bdaynum = (search -> bday)/ 100;
                if      (bdaynum == 1){  printf("January");}
                else if (bdaynum == 2){  printf("February");}
                else if (bdaynum == 3){  printf("March");}
                else if (bdaynum == 4){  printf("April");}
                else if (bdaynum == 5){  printf("May");}
                else if (bdaynum == 6){  printf("June");}
                else if (bdaynum == 7){  printf("July");}
                else if (bdaynum == 8){  printf("August");}
                else if (bdaynum == 9){  printf("September");}
                else if (bdaynum == 10){ printf("October");}
                else if (bdaynum == 11){ printf("November");}
                else if (bdaynum == 12){ printf("December");}
            printf(" %d. \n", (search -> bday) % 100);
            inputRelaLevel = search -> levelOfRela;
            if (search -> wishYN == 0){
                printf("%s did not wish you a happy birthday, so there is no need to wish them. \n", inputName);
                return;
            }
            while(ideaptr != NULL ){
                if (ideaptr -> level == inputRelaLevel && ideaptr -> doneBefore == 0){
                    printf("You can %s for them. \n", ideaptr -> idea);
                    ideaptr -> doneBefore = 1;
                    return; 
                }
                if (ideaptr -> next == NULL){
                    printf("No unused ideas are avaliable. Reuse a previous idea.");
                    return;
                }
                ideaptr = ideaptr -> next;
            }
        }
        if( search -> next == NULL) {
            printf("No information on this person is found. Make sure the name is spelt correctly and has proper capitalization. \n");
            return;
        }
        i++;
        search = search -> next;
    }
}


void main()
{
    clock_t start, stop; 

    start = clock();

    int num = 10;
    char *n[] = {"Diya", "PJ", "Jack", "Aly", "Yukta", "Wei", "Krish", "Jay", "Gia", "Zoya"};
    int relaVal[] = {3, 3, 3, 1, 2, 1, 2, 2, 1, 1};
    int date[] = {114,   222,   223,    430,   929,     930,   1006,    1111,  1122,  1212};
    int wish[] =    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1};
    // 1 is true, 0 is false

    makelist(num, n, relaVal, date, wish);

    char * ideasToWish[] = {"hold a surprise party", 
                            "make a collage with your memories", 
                            "send a birthday card", 
                            "gift simple jewerly",
                            "commission a painting of the two of you",
                            "text them happy birthday",
                            "plan a movie night together",
                            "write a poem",
                            "gift a gag gift",
                            "give a gift card to their favorite store",
                            "gift cheap chocolate",
                            "gift nice chocolate",
                            "make a bouquet of their favorite treats",
                            "gift tickets to a new movie"
                            };
        
    int ideaLevel[] = {3, 3, 1, 2, 3, 1, 3, 3, 2, 1, 1, 2, 3, 2};
    
    ideas(14, ideasToWish, ideaLevel);
    int numOfPpl;
    printf("How many people would you like to wish this year? ");
    scanf("%d", &numOfPpl);
    if (numOfPpl > num){
        return;
    }
    for(int i = 0; i < numOfPpl; i++){
        person(num);
    }
    stop = clock();

    double duration = ((double)stop - start)/CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f", duration);
    return;
}

/*
- hold a surprise party (3)
- make a collage with your memories (3)
- send them a birthday card (1)
- gift them simple jewerly (2)
- commission a painting of the two of you (3)
- text them happy birthday (1)
- plan a movie together (3)
- write a poem (3)
- gift them a gag gift (2)
- give them a gift card to their favorite store (1)
- gift them cheap chocolate (1)
- gift them nice chocolate (2)
- gift them their favorite chocolates & treats (3)
- gift tickets to a new movie (2)

14()

each node contains:
    - birthdate
    - name (up to 14 characters)
        - one is for the NULL value 
    - whether the wished or not (binary val)
    - next node
    - idea node (circular linked list)
    - depth of friendship
        - how to determine?
        have choice of relations:
            - family/close friend: 3
            - friend: 2
            - acquaintance/other: 1 

The linked list node contains:
    - ideas on what to do:
        - 

Or should it just be a stack??
- would make more sense, but is it practial??
- with the stack, we would need three different stacks, since we would need a different stack for every idea

- hardcoding the names & the levels of the relationships
    - say we have 10 people, 
    - what happened 
*/