#include <stdio.h>
#include <stdlib.h>
struct addbook
{
    int bookid;
    char bookname[50];
    char author[50];
    int price;
    int racknumber;
};
int main()
{
    char cha;
    int count = 0,count2, search, flag;
    char s, for_search[10], for_book_list[10];
    char response[10];

    //------------------------------------File Create & Open-----------------------------------
    FILE *fp = NULL;
    fp = fopen("addbook.txt", "r");
    if (fp == NULL)
    {
        printf("No File\n");
        exit(1);
    }
    fprintf(fp, "******************************** WELCOME TO LIBRARY MANAGMENT SYSTEM**********************************\n");
               fprintf(fp, "S.no    Book ID    Book Name    Author    price    Rack No\n");
    struct addbook books[100];
    printf("                          ******************************** WELCOME TO LIBRARY **********************************\n\n");
    do
    {
        printf("\n\t\t\t\----------------Add books-----------------\n");
        printf("ID: ");
        scanf("%d", &books[count].bookid);
        printf("Name: ");
        scanf("%s", books[count].bookname);
        printf("Author: ");
        scanf("%s", books[count].author);
        printf("Price: ");
        scanf("%d", &books[count].price);
        printf("Rack_No: ");
        scanf("%d", &books[count].racknumber);

        //----------------------------------------Print data to file-----------------------------
        fprintf(fp, "%d       %d       %s       %s       %d       %d\n", count + 1, books[count].bookid, books[count].bookname, books[count].author, books[count].price, books[count].racknumber);
        printf("Press 'y' to Add more: ");
        scanf("%s", response);
        count++;
    } while (response[0] == 'y' || response[0] == 'Y');
    fclose(fp);
    //---------------------------------------File Close------------------------------------------

    printf("\nData saved successfully\n");
    printf("------------------------------------------\n\n");

    //-------------------------------Search Book--------------------------------------------------
    printf("\nPress 'y' to search a book in library: ");
    scanf("%s", for_search);
    if (for_search[0] == 'y' || for_search[0] == 'Y')
    {
        do
        {
            printf("\n-------------Search Book------------------\n");
            printf("ID: ");
            scanf("%d", &search);
            count2=count-1;
            while (count2 >=0)
            {
                if (books[count2].bookid == search)
                {
                    printf("Book ID: %d \n", books[count2].bookid);
                    printf("Book Name: %s \n", books[count2].bookname);
                    printf("Author name: %s \n", books[count2].author);
                    printf("price: %d \n", books[count2].price);
                    printf("rack number: %d \n", books[count2].racknumber);
                    flag = 1;
                    break;
                }
                flag = 0;
                count2--;
            }
            if (flag == 0)
            {
                printf("This book is not available\n");
            }
            printf("Press 'y' to search more: ");
            scanf("%s", response);

        } while (response[0] == 'y' || response[0] == 'Y');
    }
        printf("\n------------------------------------------\n\n");
 //-------------------------------Search Book Close--------------------------------------------------

            //-------------------------------Book List--------------------------------------------------
    printf("Press 'y' to see book list: ");
    scanf("%s", for_book_list);
    printf("\n\n");
    if (for_book_list[0] == 'y' || for_book_list[0] == 'Y')
    {
        FILE *fb = NULL;
        fb = fopen("addbook.txt", "r");
        do
        {
            cha = fgetc(fb);
            printf("%c", cha);
        } while (cha != EOF);
        fclose(fb);
    }
    printf("\nThank you for using our service\n\n********Credits********\nWritten By: Gavnish Kumar\nBeutify By: Subrat");
    return 0;
}
