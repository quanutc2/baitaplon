#include<iostream>
#include<iostream>
#include"conio.h"
#include "Header.h"

#define MAUNEN 176
#define MAUCHU 7

using namespace std;

typedef char str[15];

str thaotac[4] = {"NEW GAME","HIGH SCORE","SPEED","EXIT"};

enum TRANGTHAI{UP, DOWN, LEFT, RIGHT, ENTER, BACK};

TRANGTHAI key(int z){
	if(z==224){
		char c = _getch();
		if (c==72 )
		return UP;
		if (c==80)
		return DOWN;
		if(c==77)
		return RIGHT;
		if(c==75)
		return LEFT;
	}
	else if(z==13)
	return ENTER;
}
int menu(str thaotac[4], int n){
	int tt=0;//bien cho biet dango thao tac thu may
	int *mau = new int[n];
	for(int i=0;i<n;i++)
		mau[i]= MAUCHU;
	mau[0]= MAUNEN;
	gotoXY(50,15);
	while(1){
		clrscr();
		for(int i=0;i<n; i++){
			textcolor(mau[i]);
			cout<< thaotac[i] <<endl;
		}
		int z= _getch();
		TRANGTHAI trangthai = key(z);
		switch(trangthai){
			case UP:
				{
				    if(tt==0){
				    	tt=n-1;
					}
					else 
					tt--;
				    break;
				}
			case DOWN:
				{
					if(tt==n-1){
				    	tt=0;
					}
					else 
					tt++;
				    break;
				}
			case ENTER:return tt;
        }
    for(int i=0;i<n;i++)
    {
        mau[i]= MAUCHU;
    }
	mau[tt]= MAUNEN;
    }

}
int main(){

	menu(thaotac,4);
	system("pause");
	return 0;
}
