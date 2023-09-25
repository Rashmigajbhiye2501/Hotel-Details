#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//-------------------------------------------------------------------------//

int sR=10, kR=20, tR=30, totRes=0;

struct Reservation
{
   char custName[30], roomType;
   int dD,dM,dY, perDay, noOfPer, resId, noOfRoom;
   float billAmt;
}sRes[90];

//-------------------------------------------------------------------------//

void headerFooter()
{
gotoxy(5,2);
printf("+========================================+");
gotoxy(5,3);
printf("|              HOTEL Chaitali            |");
gotoxy(5,4);
printf("+========================================+");
gotoxy(1,24);
printf("__________________________________________");
gotoxy(15,25);
printf("Visit us at: rashmigajbhiye.com");
}
char menu()
{
   clrscr();
   headerFooter();
	gotoxy(23,8);  printf("+------------------------+");
	gotoxy(23,9);  printf("|  D: Data               |");
	gotoxy(23,10); printf("|------------------------|");
	gotoxy(23,11); printf("|  H: Hotel Information  |");
	gotoxy(23,12); printf("|------------------------|");
	gotoxy(23,13); printf("|  A: Availability       |");
	gotoxy(23,14); printf("|------------------------|");
	gotoxy(23,15); printf("|  R: Reservation        |");
	gotoxy(23,16); printf("|------------------------|");
	gotoxy(23,17); printf("|  E: Exit               |");
	gotoxy(23,18); printf("|------------------------|");
	gotoxy(23,20); printf("Enter the choice:");
	gotoxy(43,20); return(getche());
}
void report()
{
int i;
  clrscr();
  headerFooter();
  gotoxy(10,5);
  if(totRes==0)
  {
      printf("\n No Info to Display");
  }
  else
  {
      for(i=0;i<totRes;i++)
      {
	printf("\n ID:%4d    Name:%s", sRes[i].resId, sRes[i].custName);
	printf("\n Date:%d-%d  Days:%d  Room:%c", sRes[i].dD, sRes[i].dM, sRes[i].perDay, sRes[i].roomType);
	printf("\n Person:%d  No of Room:%d Amt:%6.Of", sRes[i].noOfPer, sRes[i].noOfRoom, sRes[i].billAmt);
	printf("\n+----------------------------------------------------+\n");
      }
  }
}
void roomAvi()
{
  clrscr();
    headerFooter();
    gotoxy(5,5);  printf("Room Information:");
    gotoxy(3,7);  printf("SUIT:Total=%d",sR);
    gotoxy(3,8);  printf("King:Total=%d",kR);
    gotoxy(3,9);  printf("Travel:Total=%d",tR);
}
void hotelinfo()
{
  clrscr();
    headerFooter();
    gotoxy(3,6);   printf("It is 15-story Hotel, Which is completely Air-condition, Spacious");
    gotoxy(3,7);   printf("There are total 2 Restaurants and 1 Bar and total 60 rooms");
    gotoxy(3,9);   printf("Amenities");
    gotoxy(15,9);  printf("WIFI, Telephone, 24 Hours Bar & Restaurant and Room Service.");
    gotoxy(3,10);  printf("Near By:");
    gotoxy(15,10); printf("Railway station @ 50Mtr.");
    gotoxy(40,10); printf("SUMMATION Education office @ 100Mtr.");
    gotoxy(3,13);  printf("Room Information:");
    gotoxy(3,14);  printf("+---------------------------------------------------+---------+");
    gotoxy(3,15);  printf("| Room Type | Information                           | Price   |");
    gotoxy(3,16);  printf("|-----------|---------------------------------------|---------|");
    gotoxy(3,17);  printf("| SUIT      | 2 Rooms, 120Sq-Mtr, Sofa and King Bed | 10000/- |");
    gotoxy(3,18);  printf("|-----------|---------------------------------------|---------|");
    gotoxy(3,19);  printf("| KING      | 60sQ-Meter, Sofa, Table and King Bed  | 5000/-  |");
    gotoxy(3,20);  printf("|-----------|---------------------------------------|---------|");
    gotoxy(3,21);  printf("| Travel    | 40Sq-Meter, Table, Queen Bed          | 2500/-  |");
    gotoxy(3,22);  printf("|-----------|---------------------------------------|---------|");
}
void res()
{
  clrscr();
  headerFooter();
  gotoxy(3,6);   printf("Enter Your Name:");
  gotoxy(21,6);  gets(strR[totRes].custName);  fflush(stdin);
  gotoxy(3,7);   printf("Enter Date:dd/mm/yy");
  gotoxy(16,7);  scanf("%d",&strR[totRes].dD); fflush(stdin);
  gotoxy(19,7);  scanf("%d",&strR[totRes].dM); fflush(stdin);
  gotoxy(22,7);  scanf("%d",&strR[totRes].dY); fflush(stdin);
  gotoxy(3,8);   printf("Enter No days:");
  gotoxy(19,8);  scanf("%d",&strR[totRes].perDay);  fflush(stdin);
  gotoxy(3,9);   printf("Enter Room Type(S/K/T):");
  gotoxy(29,9);  scanf("%c",&strR[totRes].roomType);  fflush(stdin);
  gotoxy(3,10);  printf("Enter No of Persons:");
  gotoxy(25,10); scanf("%d",&strR[totRes].noOfPer);  fflush(stdin);

  strR[totRes].noRoom=1;
  if(strR[totRes].noPer>3)
  {
    strR[totRes].noRoom=0;
    strR[totRes].noRoom+=(strR[totRes].noPer/3);
    if(strR[totRes].noPer%3!=0)
       strR[totRes].noRoom++;
  }

}
void bill()
{
  float damt;
  char ty[10];
  switch(strR[totRes])
  {
	case's':case'S':
	    strcpy(ty,"SUIT");   damt=10000;
	    sR=sR-(strR[totRes].perDay*strR[totRes].noOfRoom);
	    break;
	case'k':case'K':
	    strcpy(ty,"KING");   damt=5000;
	    kR=kR-(strR[totRes].perDay*strR[totRes].noOfRoom);
	    break;
	case't':case'T':
	    strcpy(ty,"Travle"); damt=2500;
	    tR=tR-strR[totRes].perDay*strR[totRes].noOfRoom);
	    break;
  }
  strR[totRes].billAmt=strR[totRes].perDay*damt*strR[totRes].noOfRoom;

  gotoxy(3,13); printf("Bill:");
  gotoxy(3,14); printf("+--------------------------------------------------------+");
  gotoxy(3,15); printf("| Room Type | Total Days | Per day | No of Rooms | Price |");
  gotoxy(3,16); printf("+-----------+------------+---------+-------------+-------|");
  gotoxy(3,17); printf("|    %8s    |   %10d     |   %5.Of |   %5.Od     | %8.Of |",
			     ty, strR[totRes].perDay, damt, strR[totRes].noOfRoom,  strR[totRes].billAmt);
  gotoxy(3,18); printf("+-----------+------------+---------+-------------|-------|");
  gotoxy(3,19); printf("| Total Bill:                                      %8.Of |",
									strR[totRes].billAmt);
  gotoxy(3,20); printf("|________________________________________________________|");
  randomize();  strR[totRes].resId=random(1000);
  gotoxy(3,22); printf("Your Reservation number=%d",strR[totRes].resId);
  totRes++;
}
void main()
{
  char option;
  do
  {
     option=menu();
     switch(option)
     {
       case'd':case'D':
	  report();
	  break;
       case'h':case'H':
	  hotelinfo();
	  break;
       case'a':case'A':
	  roomAvi();
	  break;
       case'r':case'R':
	  res();
	  break;
       case'e':case'E':
	  gotoxy(20,22);
	  printf("Thank You...Visit Again..%c",2);
	  break;
     }
     getch();
  }while(option!='e'&&option!='E');
}

