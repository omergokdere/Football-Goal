#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 100


typedef struct{
  char name[20];
  char team[20];
  int goal;
}soccer;



void saveFile(void);
void loadFile(void);
void addPlayer(void);
void displaySoccer(void);
void updateSoccer(void);

int main()
{

	loadFile();
	displayMenu();
	printf(" \n\n\n\n"
	      "	                                                    *****************\n"
          "			                                    * OMER GOKDERE  *\n"
          "	                                                    *****************\n");
	return 0;


  return 0;
}


soccer soccers[SIZE];
int soccerNum = 0;

void saveFile() {
  FILE *soccerFile;

  if((soccerFile=fopen("Soccers", "wb")) == NULL) {
    printf("FILE CANNOT OPEN!!\n");
  }

  if(fwrite (soccers, sizeof(soccer), SIZE, soccerFile) != SIZE)
    printf("ERROR WHILE READING FILE.");

  fwrite(&soccerNum, sizeof(int), 1, soccerFile);

  fclose(soccerFile);
}

void loadFile() {
  FILE *soccerFile;

  if((soccerFile = fopen("Soccers", "rb")) == NULL) {
    return;
  }

  if(fread(soccers, sizeof(soccer), SIZE, soccerFile) != SIZE)
    printf("ERROR WHILE READING FILE.");

  fread(&soccerNum, sizeof(int), 1, soccerFile);

  fclose(soccerFile);
}


void addPlayer() {
  fflush(stdin);

  printf("Enter Soccer Name: ");
  gets(soccers[soccerNum].name);

  printf("Enter Football Team: ");
  gets(soccers[soccerNum].team);

  printf("Enter the number of Goals: ");
  scanf("%d", &soccers[soccerNum].goal);

  soccerNum++;
  printf("Player information has been added .. \n\n");
}

void displaySoccer() {
  int i;

  printf("Name                Team       Goals\n");
  printf("------              ------     -------\n");

  for (i=0; i<soccerNum; i++) {
    printf("%s%20s%10d \n", soccers[i].name, soccers[i].team, soccers[i].goal);
  }
}

void updateSoccer() {
  int i;
  int ans = 0;
  char arrName[20];

  displaySoccer();


  while (ans == 0) {
    printf("Type the name of player to update (type 'BACK' to move main menu): ");
    fflush(stdin);
    gets(arrName);

    if (strcmp(arrName, "BACK") == 0) return;

    for (i=0; i<soccerNum; i++) {
      if (strcmp(soccers[i].name, arrName) == 0) {
        ans = 1;
        break;
      }
    }

    if (ans == 0) printf("Soccer is NOT FOUND !, Please Try another names...  \n\n");
  }


  printf("Enter Soccer Name:  ");
  gets(soccers[i].name);

  printf("Enter Soccer Team: ");
  gets(soccers[i].team);

  printf("Enter Number of Goal Scored: ");
  scanf("%d", &soccers[i].goal);

  printf("Soccer information has been updated \n\n");
}

int displayMenu() {
  int choice;

  while (1) {

	  system("cls");
	  printf("\n             ---------------");
	  printf("\n             FOOTBALL SYSTEM");
	  printf("\n             ---------------");
	  printf("\n");
      printf("\n1=> Enter information on all football players \n");
      printf("\n2=> Display table for all football players \n");
      printf("\n3=> Update specific football players goal tally \n");
      printf("\n4=> Exit the program. \n\n");
	  printf("Your choise => ");
      scanf("%d", &choice);

    switch(choice) {
      case 1:
        system("cls");
        addPlayer();
        break;

      case 2:
        system("cls");
        displaySoccer();
        system("pause");
        break;

      case 3:
        system("cls");
        updateSoccer();
        system("pause");
        break;

      case 4:
        saveFile();
        exit(0);
        break;

      default:
        printf("Please type a number from 1 to 4. \n\n");

        break;
    }
  }
}

