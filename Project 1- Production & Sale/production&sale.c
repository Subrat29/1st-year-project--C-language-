#include<stdio.h>
#include<stdlib.h>
int main(){
    int m[4][5];
    int s[4][5];
    int c[5]={10,20,30,15,25};
    int Mprice[4][5],Sprice[4][5];
    int Mweek[4],Sweek[4];
    int Mproduct[5],Sproduct[5];
    int Mtotal=0,Stotal=0;
    int i,j,key,button;

    //products manufactured in 4 week
    printf("\nEnter products manufactured week_wise\n\n");
    for(i=0;i<4;i++){
        printf("Week-%d\n",i+1);
        for(j=0;j<5;j++){
            printf("Product-%d: ",j+1);
            scanf("%d",&m[i][j]);
        }
    }
    //products sold in 4 week
    printf("\nEnter products sold week_wise\n\n");
    for(i=0;i<4;i++){
        printf("Week-%d\n",i+1);
        for(j=0;j<5;j++){
            printf("Product-%d: ",j+1);
            scanf("%d",&s[i][j]);
        }
    }
    //Each products cost
    printf("\nEnter Price of products\n");
    for(j=0;j<5;j++){
        printf("Product-%d: ",j+1);
        scanf("%d",&c[j]);
    }

    //manufactured & Sold cost in 4 week
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            Mprice[i][j]=m[i][j]*c[j];
            Sprice[i][j]=s[i][j]*c[j];
        }
    }

    //Manufactured & Sold Cost week_wise
    for(i=0;i<4;i++){
        Mweek[i]=0;
        Sweek[i]=0;
        for(j=0;j<5;j++){
            Mweek[i]+=Mprice[i][j];
            Sweek[i]+=Sprice[i][j];
        }
    }
    //Manufactured & Sold Cost product_wise
    for(j=0;j<5;j++){
        Mproduct[j]=0;
        Sproduct[j]=0;
        for(i=0;i<4;i++){
            Mproduct[j]+=Mprice[i][j];
            Sproduct[j]+=Sprice[i][j];
        }
    }
    //Grand total of Manufacture & sold
    for (j=0;j<5;j++){
        Mtotal+= Mproduct[j];
        Stotal+= Sproduct[j];
    }
    //-------------------------------------NOW PRINT ALL THE OPTIONS----------------------------------------------------
    do{
        printf("\nFOLLOWING IS THE LIST OF THINGS YOU REQUEST FOR\n\n");
        printf("1. Cost matrices of production and sale\n2. Total Cost of weekly production & sale\n");
        printf("3. Product_wise monthly cost of products & sales\n4. Grand total cost of production & sales\n5. Product manufactured and sold week_wise\n6. Exit");
        printf("\n\nEnter a key: ");
        scanf("%d",&key);
switch(key) {
    case 1:
    //print manufactured cost in 4 week
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\nMANUFACTURED COST OF PRODUCT\n\n");
    for (j = 0; j < 5; j++) {
        printf("\t    Product %d ",j + 1);
    }
    for (i = 0; i < 4; i++) {
        printf("\nWeek-%d: ",i + 1);
        for (j = 0; j < 5; j++) {
            printf("\t%d\t", Mprice[i][j]);
        }
    }
        //print sold cost in 4 week
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
        printf("\nSOLD COST OF PRODUCT\n\n");
        for (j = 0; j < 5; j++) {
            printf("\t    Product %d ",j + 1);
        }
        for (i = 0; i < 4; i++) {
            printf("\nWeek-%d: ",i + 1);
            for (j = 0; j < 5; j++) {
                printf("\t%d\t",Sprice[i][j]);
            }
        }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    break;
    case 2:
    //Print Manufactured & Sold Cost per week
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\nMANUFACTURED & SOLD COST PER WEEK\n\n");
    printf("\t    Production\t                Sale");
    for (i = 0; i < 4; i++) {
        printf("\nWeek-%d: ", i + 1);
        printf("\t%d            \t%d", Mweek[i],Sweek[i]);
    }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
        break;
    case 3:
    //Print Manufactured Cost per Products
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\nMANUFACTURED & SOLD COST PER PRODUCTS\n\n");
    printf("\t    Production\t       Sale");
    for (j = 0; j < 5; j++) {
        printf("\nProduct-%d: ", j + 1);
        printf("\t%d            \t%d", Mproduct[j], Sproduct[j]);
    }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
        break;
    case 4:
    //Print Grand total of Manufacture & sold
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\nGRAND TOTAL OF PRODUCTION & SALE\n\n");
    printf("Total Production: %d\nTotal Sold: %d", Mtotal, Stotal);
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
        break;
    case 5:
        printf("\nPRODUCTS MANUFACTURED  WEEK_WISE\n\n");
        for (j = 0; j < 5; j++) {
            printf("\t    Product %d ",j + 1);
        }
        for(i=0;i<4;i++){
            printf("\nWeek-%d\t",i+1);
            for(j=0;j<5;j++){
                printf("\t%d\t",m[i][j]);
            }
        }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");

        //products sold in 4 week
        printf("\n\nPRODUCTS SOLD WEEK_WISE\n\n");
        for (j = 0; j < 5; j++) {
            printf("\t    Product %d ",j + 1);
        }
        for(i=0;i<4;i++){
            printf("\nWeek-%d\t",i+1);
            for(j=0;j<5;j++){
                printf("\t%d\t",s[i][j]);
            }
        }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");

        //Each product cost
        printf("\n\nPrice of products\n\n");
        for(j=0;j<5;j++){
            printf("Product-%d: ",j+1);
            printf("%d\n",c[j]);
        }
        printf("\n\n-----------------------------------------------------------------------------------------------------------\n");

        break;
    case 6:
        printf("Exit from the program");
        exit(0);

    default:
        printf("Wrong choice,select again\n\n");
        break;
}
        printf("\n\nDo you want to enter again?\nPress 1 to continue: ");
        scanf("%d",&button);
    }while(button==1);
    printf("\n\nExit from the Program");
    return 0;
    }
