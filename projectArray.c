#include<stdio.h>
#include<string.h>

void person(int n, char **name, int*relaVal, int*date, int*wishedYou, char**wishIdeas, int lenB){
    int bdaynum;
    char inputName[15];
    
    int ideaLevel[14][2] =  { {3, 0},
                              {3, 0},
                              {1, 0}, 
                              {2, 0}, 
                              {3, 0}, 
                              {1, 0}, 
                              {3, 0}, 
                              {3, 0},
                              {2, 0}, 
                              {1, 0}, 
                              {1, 0}, 
                              {2, 0}, 
                              {3, 0}, 
                              {2, 0} };

    int inputRelaVal, ppl, check, i;

    printf("How many people would you like to wish?");
    scanf(" %d", &ppl);
    for (int k = 0; k < ppl; k++){
        check = 0;
        i = 0;
        printf("Which person do you want to wish? ");
        scanf("%s", inputName);
        while (check == 0){
            if (i == n){
                printf("No information on this person is found. Make sure the name is spelt correctly and has proper capitalization.\n");
                check = 1;
                break;
            }
            if (strcmp(name[i], inputName) == 0){
                //converting the integer value into a readable birthday value for the user
                printf("%s's birthday is ", inputName);
                bdaynum = date[i]/ 100;
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

                printf(" %d. \n", date[i] % 100);
                inputRelaVal = relaVal[i];
                if (wishedYou[i] == 0){
                    printf("%s did not wish you on your birthday, so there is no need to wish them. \n", inputName);
                    check = 1;
                    break;
                }
                for(int j = 0; j <= lenB; j++){
                    if(j == lenB){
                        printf("No unused ideas are avaliable. Reuse a previous idea.");
                        check = 1;
                        break;  
                    }
                    if(ideaLevel[j][0] == inputRelaVal){
                        if(ideaLevel[j][1] == 0){
                            printf("You can %s for them. \n", wishIdeas[j]);
                            ideaLevel[j][1] = 1;
                            check = 1;
                            break;}
                    }
                }  
            }
        i++;        // incrementing counter
        }
    }
}

void main(){
    int num = 10;
    char *n[] = {"Diya", "PJ", "Jack", "Aly", "Yukta", "Wei", "Krish", "Jay", "Gia", "Zoya"};
    int relaVal[] = {3, 3, 3, 1, 2, 1, 2, 2, 1, 1};
    int date[] = { 114,   222,   223,    430,   929,     930,   1006,    1111,  1122,  1212};
    int wish[] =    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1};

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
    
    int len = 14;

    person(num, n, relaVal, date, wish, ideasToWish, len);
}