#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//0 means x, 1 means o, 2 means empty

void dataRow(char matrix[]){
    printf(" %c | %c | %c \n",matrix[0],matrix[1],matrix[2]);
}

void baseRow(){
    printf("---|---|---\n");
}

void convert(int array[],char matrix[]){
    for (int i = 0; i < 3; i++)
    {
        if(array[i]==1) matrix[i] = 'o';
        if(array[i]==0) matrix[i] = 'x';
        if(array[i]==2) matrix[i] = ' ';
    }
}

void initial(int array[]){
    char matrix[3];
    convert(array,matrix);    
    dataRow(matrix);
    baseRow();
    dataRow(matrix);
    baseRow();
    dataRow(matrix);
}

void display(int dataArray[3][3]){
    printf("\n");
    char matrix[3]={' ',' ',' '};
    for(int i = 0;i<3;i++){
            convert(dataArray[i],matrix);
            dataRow(matrix);
        if(i==0 || i ==1)baseRow();
    }
}

int isWin(int dataArray[3][3],int n){
    int check=0;
    //checking row
    for(int i = 0;i<3;i++){
        check = 0;
        for (int j = 0; j < 3; j++)
        {
            if(dataArray[i][j]==n) check++;
        }
        if(check==3) return 1;
    }
    //checking columns
    for(int i = 0;i<3;i++){
        check = 0;
        for (int j = 0; j < 3; j++)
        {
            if(dataArray[j][i]==n) check++;
        }
        if(check==3) return 1;
    }
    //checking diagnols
    check = 0;
    for (int i = 0; i < 3; i++)
    {
        if (dataArray[i][i]==n) check++;
    }
    if(check==3) return 1;
    check=0;
    for (int i = 0; i < 3; i++)
    {
        if (dataArray[i][2-i]==n) check++;
    }
    if(check==3) return 1;
    return 0;
}

int main(){
    printf("\t\t---Instructions---\t\nYou have to enter place where you want to mark in number form.\nFor e.g 11 mean 1st row and 1st column.\n\n\n");
    char player1[100],player2[100];
    printf("=> Enter Player 1 name: ");
    scanf("%s",player1);
    printf("=> Enter Player 2 name: ");
    scanf("%s",player2);
    int data[3][3]={{2,2,2},{2,2,2},{2,2,2}};
    int row,col;
    int init[3] = {2,2,2};
    display(data);
    char enter[3000];
    int alternate = 0,i=1;
   while(!(isWin(data,1) || isWin(data,0))){
    printf("\n=> %s's Turn: ",alternate==0?player1:player2);
    scanf("%s",enter);
    row = enter[0]-'1';col = enter[1] - '1';
    if((data[row][col]==2)&&(row>=0 && row<3)&&(col>=0 && col<3)&&(strlen(enter)==2)){data[row][col] = alternate;
    alternate = !alternate;} else {printf("\nInvalid Move\n");continue;}
    display(data);
    if(i==9) break;
    i++;
   }
   if(isWin(data,0)) printf("\n %s Wins\n",player1);
   else if(isWin(data,1)) printf("\n %s Wins\n",player2);
   else printf("Draw");
   return 0;
}
