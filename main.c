#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char code[100];
    char name[100];
    int quantity;
    float price;
    float priceTax ;
    float priceQuantity;
    float profitGeneration;
    int day;
    int month;
    int year;

}products;

int main()
{
    int z = 0;
    products *data = malloc(z * sizeof(products));

    int choice;

////// functions ///////

void print(int i){
        printf("\nThe product code : %s\n",data[i].code);
        printf("The product name : %s\n",data[i].name);
        printf("The product quantity : %d\n",data[i].quantity);
        printf("The product price : %f\n",data[i].price);
        printf("The product price + Tax : %f\n",data[i].priceTax);
}
//////// add one product //////

void addOneProduct(){
        printf("entre product code : ");
        scanf("%s",&data[z].code);
        printf("entre product name : ");
        scanf("%s",&data[z].name);
        printf("entre product quantity : ");
        scanf("%d",&data[z].quantity);
        printf("entre product price : ");
        scanf("%f",&data[z].price);
        data[z].priceTax = data[z].price + data[z].price*data[z].price/100;
        data[z].profitGeneration = 0 ;
        z = z +1;
}
/////////  print data  ///////////

void printdata(){
    for(int i = 0;i<z;i++){
    print(i);
    }
}

//////  add more than one product  ////////

void addProducts(){
        int numberOfProducts;
        printf("enter the number of products you want to add : ");
        scanf("%d",&numberOfProducts);


        for (int i = z;i<z + numberOfProducts ;i++){
        printf("\nentre product code : ");
        scanf("%s",&data[i].code);
        printf("entre product name : ");
        scanf("%s",&data[i].name);
        printf("entre product quantity : ");

        scanf("%d",&data[i].quantity);

        printf("entre product price : ");

        scanf("%f",&data[i].price);
        data[i].priceTax = data[i].price + data[i].price*0.15;
        data[i].profitGeneration = 0 ;
        }

        z = z + numberOfProducts;
}

//////  list all products in descending order of price  //////

void ListByPrices(){
    float price;
    char code[100];
    char name[100];
    int quantity;
    float pricetax;
    float profitGeneration;
    int day,month,year;

    int opt;
    printf("\n1 - list all products in descending order of price :");
    printf("\n2 - list all products in alphabitic order :");
    printf("\n3 - GO back to Menu : ");
    printf("\nyour choice : ");
    scanf("%d",&opt);
        if(opt == 1){
            for(int i = 0;i<z;i++){
            for(int j = i+1;j<z;j++){

                if(data[i].price < data[j].price){
                    strcpy(code,data[i].code);
                    price = data[i].price;
                    strcpy(name,data[i].name);
                    quantity  = data[i].quantity;
                    pricetax = data[i].priceTax;
                    profitGeneration = data[i].profitGeneration;
                    day = data[i].day;
                    month = data[i].month;
                    year = data[i].year;

                    strcpy(data[i].code ,data[j].code);
                    data[i].price = data[j].price;
                    strcpy(data[i].name,data[j].name);
                    data[i].quantity  = data[j].quantity;
                    data[i].priceTax  = data[j].priceTax;
                    data[i].profitGeneration = data[j].profitGeneration;
                    data[i].day = data[j].day ;
                    data[i].month = data[j].month ;
                    data[i].year = data[j].year ;

                    strcpy( data[j].code,code);
                    data[j].price = price;
                    strcpy(data[j].name,name);
                    data[j].quantity = quantity;
                    data[j].priceTax = pricetax;
                    data[j].profitGeneration = profitGeneration;
                    data[j].day = day;
                    data[j].month = month;
                    data[j].year = year ;
            }
        }

    }
    printdata();
        }
    if(opt == 2){
        int j=0;

        do{
            for(int i=z-1; i>j; i--){
                if(strcmp(data[i].name,data[i-1].name) < 0){

                    strcpy(code,data[i].code);
                    price = data[i].price;
                    strcpy(name,data[i].name);
                    quantity  = data[i].quantity;
                    pricetax = data[i].priceTax;
                    profitGeneration = data[i].profitGeneration;
                    day = data[i].day;
                    month = data[i].month;
                    year = data[i].year;

                    strcpy(data[i].code ,data[i-1].code);
                    data[i].price = data[i-1].price;
                    strcpy(data[i].name,data[i-1].name);
                    data[i].quantity  = data[i-1].quantity;
                    data[i].priceTax  = data[i-1].priceTax;
                    data[i].profitGeneration = data[i-1].profitGeneration;
                    data[i].day = data[i-1].day ;
                    data[i].month = data[i-1].month ;
                    data[i].year = data[i-1].year ;

                                        strcpy( data[i-1].code,code);
                    data[i-1].price = price;
                    strcpy(data[i-1].name,name);
                    data[i-1].quantity = quantity;
                    data[i-1].priceTax = pricetax;
                    data[i-1].profitGeneration = profitGeneration;
                    data[i-1].day = day;
                    data[i-1].month = month;
                    data[i-1].year = year ;
                }
            }
            j++;
        }while(j<z);
        printdata();
        }
    }

///////  search for the product By ( code , quantity )  ////////

void SearchBy(){
    int opt;
    printf("\n1 - Serch by code :");
    printf("\n2 - Serch by quantity :");
    printf("\nyour choice : ");
    scanf("%d",&opt);

    if(opt == 1){
        printf("\nenter the product code : ");
        char code[50];
        scanf("%s",&code);
        for(int i = 0;i<z;i++){
            if(!strcmp(data[i].code,code)){
                print(i);
            }
        }
    }

    if(opt == 2){
        printf("\nenter the product quantity : ");
        int quantity;
        scanf("%d",&quantity);
        for(int i = 0;i<z;i++){
            if(data[i].quantity == quantity){
                print(i);
            }
        }
    }
}

///////  display products whose quantity is less than 3  /////////

void quantityLess(){
        for(int i = 0;i<z;i++){
            if(data[i].quantity <= 3){
                print(i);
            }
        }

}

////// add quantity to product  //////////////

void addQuantity(){
        printf("\nenter the product code : ");
        char code[50];
        int quantity;
        scanf("%s",&code);
        for(int i = 0;i<z;i++){
            if(!strcmp(data[i].code,code)){
                printf("\nenter the product quantity : ");
                scanf("%d",&quantity);
                data[i].quantity =  data[i].quantity  + quantity;

                print(i);

            }
        }
}

/////////  delete product   //////////

void deleteProduct(){
        int pos;
        char codeDP[20];
        printf("enter product code you want to delete : ");
        scanf("%s",&codeDP);
        for (int i = 0;i<z;i++){
            if (!strcmp(codeDP,data[i].code)){
                pos = i;
                for (int i = pos ; i<z ;i++){
                    strcpy(data[i].code ,data[i+1].code);
                    data[i].price = data[i+1].price;
                    strcpy(data[i].name,data[i+1].name);
                    data[i].quantity  = data[i+1].quantity;
                    data[i].priceTax  = data[i+1].priceTax;
                    data[i].profitGeneration = data[i+1].profitGeneration;
                    data[i].day = data[i+1].day;
                    data[i].month = data[i+1].month;
                    data[i].year = data[i+1].year ;
                }

            }
        }
        z = z-1;
        printdata();
}

////////  buy a Product  ///////////////////////////////////////////////////////////////////////////////////////

void buyProduct(){
    char buyByCode[50];
    int quantitySold;
        printf("\nenter the product code :  " );
        scanf("%s",&buyByCode);
         for(int i = 0;i<z;i++){
            if (!strcmp(data[i].code,buyByCode)){
                printf("\nenter the product quantity that got sold :  " );
                scanf("%d",&quantitySold);
                printf("\nenter the date of sell ( day month year ) :  " );
                scanf("%d %d %d",&data[i].day,&data[i].month,&data[i].year);

                data[i].quantity = data[i].quantity - quantitySold;

                data[i].profitGeneration = data[i].profitGeneration +  data[i].priceTax * quantitySold;
                data[i].priceQuantity = data[i].priceTax * quantitySold;
                printf("\n receipt \n");
                printf("\nProduct code : %s\n",data[i].code);
                printf("Product name : %s\n",data[i].name);
                printf("quantity : %d\n",quantitySold);
                printf("total price : %f\n",data[i].priceQuantity);
                printf("date : %d/%d/%d",data[i].day,data[i].month,data[i].year);
            }
         }
}
///////  the total and average prices of products sold in the current day ////////

void totalaveragesells(){
    int opt;
    printf("\n1 - the total sells in specific date :");
    printf("\n2 - the average sells in specific date:");
    printf("\n3 - GO back to Menu : ");
    printf("\nyour choice : ");
    scanf("%d",&opt);
    if(opt <= 3){
    int day;
    int month;
    int year;
    float totalSellsDate = 0;
    float averageSellsDate = 0;
                printf("\nenter the date to check the dayProfit ( day month year ) :  " );
                scanf("%d %d %d",&day,&month,&year);
                for(int i = 0;i<z;i++){
                    if(day == data[i].day && month == data[i].month && year == data[i].year){
                        totalSellsDate +=data[i].profitGeneration;
                    }
                }
                averageSellsDate = totalSellsDate / 2;
                if(opt == 1){
                printf("%f",totalSellsDate);
                }
                if(opt == 2 ){
                printf("%f",averageSellsDate);}

                }
}
//////// the max and min profit that product generate in specific day ////////

void minmax(){

    int opt;
    printf("\n1 - the max product that generate most specific date :");
    printf("\n2 - the min product that generate most specific date :");
    printf("\n3 - GO back to Menu : ");
    printf("\nyour choice : ");
    scanf("%d",&opt);
    if(opt <= 3){
    float minList[200];
    float max = 0;
    int c  = 0;
    int day;
    int month;
    int year;
        printf("\nenter the date to check the dayProfit ( day month year ) :  " );
        scanf("%d %d %d",&day,&month,&year);
                for(int i = 0;i<z;i++){
                    if(day == data[i].day && month == data[i].month && year == data[i].year){
                            if (max<data[i].profitGeneration){
                                max = data[i].profitGeneration;
                            }
                    minList[c] = data[i].profitGeneration;
                    c++;
                    }
                }
    float min = minList[0];
    for(int i = 1;i<c;i++){
            if (min>data[i].profitGeneration){
                min = data[i].profitGeneration;
            }
    }
    if(opt == 1){
        printf("%f",max);
        for(int i = 0;i<z;i++){
            if(max == data[i].profitGeneration){
                print(i);
            }
        }
    }
    if(opt == 2){
    printf("%f",min);
    }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n1 - add new product : ");
    printf("\n2 - add more than one product : ");
    printf("\n3 - list all products in descending order of price ");
    printf("\n4 - buy a product ");
    printf("\n5 - search for the product By ( code , quantity )");
    printf("\n6 - display products whose quantity is less than 3: ");
    printf("\n7 - add stock");
    printf("\n8 - delete product");
    printf("\n9 - the total and average prices of products sold in the current day ");
    printf("\n10 - the max and min profit that product generate in specific day");
    printf("\n11 - print data ");
    printf("\nyour choice : ");
    scanf("%d",&choice);

    while(choice != 14){
    if (choice == 1){
            addOneProduct();
    }
    if (choice == 2){
            addProducts();
    }
    if (choice == 3){
            ListByPrices();
    }
    if (choice == 4){
           buyProduct();
    }
    if (choice == 5){
            SearchBy();
    }
    if (choice == 6){
            quantityLess();
    }

    if (choice == 7){
            addQuantity();
    }
    if(choice == 8 ){
        deleteProduct();
    }
    if(choice == 9 ){
        totalaveragesells();
    }
    if(choice == 10){
        minmax();
    }



     if (choice == 11){
            printdata();
    }
    printf("\n\n1 - add new product : ");
    printf("\n2 - add more than one product : ");
    printf("\n3 - list all products in descending order of price ");
    printf("\n4 - buy a product ");
    printf("\n5 - search for the product By ( code , quantity )");
    printf("\n6 - display products whose quantity is less than 3: ");
    printf("\n7 - add stock");
    printf("\n8 - delete product");
    printf("\n9 - the total and average prices of products sold in the current day ");
    printf("\n10 - the max and min profit that product generate in specific day");
    printf("\n11 - print data ");

    printf("\nyour choice : ");
    scanf("%d",&choice);


}

    return 0;
}
