#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dieGame.h"

void result(int results[5], char userName[20]){

    printf("\n");
    int x,y;

    x=results[1];
    y=0;
	for (int i= 1; i < 5; i++) {
            if(x>results[i]){
                x=results[i];// max point
             y=i+1;
            }
            if(i==1)
                printf("%s      : %d      \n",userName,  results[i]);
            else if(i!=0)
                printf("Computer#%d  : %d   \n",(i-1) ,  results[i] );



    }


    if(y!=0)
        printf("Congratulations! Player%s won the game %s points\n", y, x );
    else if(y==0)
        printf("Congratulations! %s won the game.\( %s points \) \n", y, x );


    else
        printf("There is no winner \n" );


}




int **generateRandoms(){
    srand(time(NULL));
    int min=1;
    int max=6;
    int i,j;
    int **numbers  =( int **)malloc(sizeof(int *)*4);

    for(i=0;i<4;i++){
        numbers[i]=(int *)malloc(sizeof(int)*3);
        for(j=0;j<3;j++){
            numbers[i][j]= rand()%((max+1)-min) + min;
        }
    }


    return numbers;
}


int **displayPoints(int **pointsUsers){
    int **pointsTable=(int **)malloc(sizeof(int *)*4);
    int i,j;

    for(i=0;i<4;i++){
        pointsTable[i]=(int *)malloc(sizeof(int)*1);
        for(j=0;j<1;j++){
            pointsTable[i][0]=0;
        }
    }

    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            if((pointsUsers[i][0]== pointsUsers[i][1])&& (pointsUsers[i][1] ==pointsUsers[i][2])){
                if(pointsUsers[i][j]==1){
                    pointsTable[i][0]+=-10;//10 points
                    break;
                }
                else if(pointsUsers[i][j]==6){
                    pointsTable[i][0]+=10;//10 points
                    break;
                }
                else{ pointsTable[i][0]+=5; //X-X-X  5 points
                    break;
                }
            }
            else if( pointsUsers[i][0]==pointsUsers[i][2] ){// Y-X-Y  +X points (if Y>3)
                    if(pointsUsers[i][0]>3){ // Y-X-Y  +X points (if Y>3)
                         pointsTable[i][0]+=pointsUsers[i][1];
                         break;
                    }
                    else {
                         pointsTable[i][0]-=pointsUsers[i][1];// Y-X-Y -X points(if Y<4)
                        break;
                    }
            }
            else if( pointsUsers[i][1]==pointsUsers[i][2] ){// X-Y-Y +X points (if Y>3)
                    if(pointsUsers[i][1]>3){
                         pointsTable[i][0]+=pointsUsers[i][0];
                         break;
                    }
                    else {
                         pointsTable[i][0]-=pointsUsers[i][0];// X-Y-Y - X points (if Y<4)
                        break;
                    }
            }
            else if( pointsUsers[i][0]==pointsUsers[i][1] ){
                    if(pointsUsers[i][0]>3){
                         pointsTable[i][0]+=pointsUsers[i][2];// Y-Y-X + X points (if Y>3)
                         break;
                    }
                    else {
                         pointsTable[i][0]-=pointsUsers[i][2];// Y-Y-X - X points (if Y<4)
                        break;
                    }
            }

            else if ((pointsUsers[i][0] == 4 && pointsUsers[i][1] == 5 && pointsUsers[i][2] ==6) ||
                     (pointsUsers[i][0] == 4 && pointsUsers[i][1] == 6 && pointsUsers[i][2] ==5) ||
                     (pointsUsers[i][0] == 5 && pointsUsers[i][1] == 4 && pointsUsers[i][2] ==6) ||
                     (pointsUsers[i][0] == 5 && pointsUsers[i][1] == 6 && pointsUsers[i][2] ==4) ||
                     (pointsUsers[i][0] == 6 && pointsUsers[i][1] == 4 && pointsUsers[i][2] ==5) ||
                     (pointsUsers[i][0] == 6 && pointsUsers[i][1] == 5 && pointsUsers[i][2] ==4)){
                      pointsTable[i][0]+=3;
                        break;
                }


            else if ((pointsUsers[i][0] == 1 && pointsUsers[i][1] == 2 && pointsUsers[i][2] ==3) ||
                     (pointsUsers[i][0] == 1 && pointsUsers[i][1] == 3 && pointsUsers[i][2] ==2) ||
                     (pointsUsers[i][0] == 2 && pointsUsers[i][1] == 1 && pointsUsers[i][2] ==3) ||
                     (pointsUsers[i][0] == 2 && pointsUsers[i][1] == 3 && pointsUsers[i][2] ==1) ||
                     (pointsUsers[i][0] == 3 && pointsUsers[i][1] == 2 && pointsUsers[i][2] ==1) ||
                     (pointsUsers[i][0] == 3 && pointsUsers[i][1] == 1 && pointsUsers[i][2] ==2)){
                      pointsTable[i][0]-=3;
                         break;


                     }

                     else pointsTable[i][0]+=0;











}
//*(*(users+i)+j)



    }
    return pointsTable;
}

void printingRaund(int roundNum){
     printf("\n");
	if(roundNum == 1)
		printf("%d st round \n", roundNum);

	else if(roundNum == 2)
		printf("%d nd round \n", roundNum);

	else if(roundNum == 3)
		printf("%d rd round \n", roundNum);
	else
		printf("%d th round \n", roundNum);

}


