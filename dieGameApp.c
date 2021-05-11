#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dieGame.h"


//gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)
int main()
{
	srand(time(NULL));
    int playersPoints[5] = {0,0,0,0,0};
	char chr='n';
	char userName[20];
	char str1[6];
	int roundNum=0;

	printf("Please enter username: ");
	scanf("%s", userName);

	printf( "User registered as \"%s\" ",userName);

	printf("\nType \"start\" to begin the game: ");
	scanf("%s", str1);

	int check=strcmp("start", str1); // start[6]= = str1 ? Are they equal? so lets learn using-> strcmp(s1,s2) it returns 0 if s1 and s2 are the same
    if(check==0)
        chr='y';

    while(chr=='y'){
        roundNum++;
        printingRaund(roundNum);
		int i,j;
		int **users;
		users = generateRandoms();
		int **points;
		points= displayPoints(users);



		for (i= 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				printf("%d  ",users[i][j]);
            }
            if(i==0)
                printf("%s      :%d      \n",userName, points[i][0]);

            else if(i!=0)
                printf("Computer#%d  :%d  \n",i ,points[i][0] );

            playersPoints[i+1]+=points[i][0];  // because first element of the array is the address of the storred in array.

            printf("\n");

		}

		printf("Do you want to dice?:(y/n): ");
        scanf("%s", &chr);
		if(chr=='y')
		check=1;
		else
		check=1;


	}
				result(playersPoints,userName);



	return 0;
}

