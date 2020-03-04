#include<stdio.h>
#include<stdlib.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

void setMatrix(int matrix[][4])
{
    int source[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxindex=15,index;
    srand(time(NULL));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(maxindex){
                index=rand()%maxindex;
                matrix[i][j]=source[index];
                source[index] = source[maxindex-1];
                maxindex--;
            }
            else
                matrix[i][j]=0;
        }
    }
}

void displayMatrix(int matrix[][4],int totalMove)
{
    printf("Total Move: 100\n");
    printf("Move Remaining: %d",totalMove);
    printf("\n---------------------\n|");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j])
                printf(" %-2d |",matrix[i][j]);
            else
                printf("    |");
        }
        printf("\n---------------------\n");
        if(i!=3)
            printf("|");
    }
}
int input()
{
    int c;
    if((c=getch())==224){
        switch(getch()){
          case RIGHT:
              return RIGHT;
          case LEFT:
              return LEFT;
          case UP:
              return UP;
          case DOWN:
              return DOWN;
          default:
            return 0;
        }
    }
}
void main()
{
    int matrix[4][4];
    int totalMove=100;
    int win=0;
    system("color 2");
    setMatrix(matrix);
    while(totalMove && !win){
        displayMatrix(matrix,totalMove);
        printf("\nEnter your move");
        switch(input()){
           case LEFT:
              win=moveLEFT(matrix,&totalMove);
              break;
           case RIGHT:
              win=moveRIGHT(matrix,&totalMove);
              break;
           case UP:
              win=moveUP(matrix,&totalMove);
              break;
           case DOWN:
              win=moveDOWN(matrix,&totalMove);
              break;
           case 0:
               printf("Invalid Move");
        }
    }
    system("cls");
    system("color 4");
    if(win)
        printf("You win!!!\n");
    else
        printf("Game Over\n");
    printf("Press Any key to exit");
    getch();
}
int moveLEFT(int matrix[][4],int *totalMove){
    int done=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                if(j>=0 && j<3){
                    matrix[i][j]=matrix[i][j+1];
                    matrix[i][j+1]=0;
                    (*totalMove)--;
                }
                done=1;
                break;
            }
        }
        if(done){
            system("cls");
            break;
        }
    }
    return(checkWin(matrix));
}
int moveRIGHT(int matrix[][4],int *totalMove){
    int done=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                if(j<=3 && j>0){
                    matrix[i][j]=matrix[i][j-1];
                    matrix[i][j-1]=0;
                    (*totalMove)--;
                }
                done=1;
                break;
            }
        }
        if(done){
            system("cls");
            break;
        }
    }
    return(checkWin(matrix));
}
int moveUP(int matrix[][4],int *totalMove){
    int done=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                if(i>=0 && i<3){
                    matrix[i][j]=matrix[i+1][j];
                    matrix[i+1][j]=0;
                    (*totalMove)--;
                }
                done=1;
                break;
            }
        }
        if(done){
            system("cls");
            break;
        }
    }
    return(checkWin(matrix));
}
int moveDOWN(int matrix[][4],int *totalMove){
    int done=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==0){
                if(i<=3 && i>0){
                    matrix[i][j]=matrix[i-1][j];
                    matrix[i-1][j]=0;
                    (*totalMove)--;
                }
                done=1;
                break;
            }
        }
        if(done){
            system("cls");
            break;
        }
    }
    return(checkWin(matrix));
}
int checkWin(int matrix[][4])
{
    int count=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(count==16)
                break;
            if(matrix[i][j]!=count)
                return 0;
            count++;
        }
    }
    return 1;
}
