
// TAO RA HAI QUA CHO RAN AN CÙNG LUC, KHI GAME OVER HIEN LÊN GAME OVER (hom em co dua code len githup roi a)
// NHOM 6
// TRAN THIEN PHU - 6151071083
// NGUYEN MINH QUAN - 6151071087
// TRAN VAN QUANG - 6151071086

#include <iostream>
#include <vector>
#include <ctime>
#include "myLib.h"
#include"conio.h"
#include <fstream>

#define MAUNEN 45
#define MAUCHU 7
#define max 100


using namespace std;

typedef char str[15];

int s;
int d = 0;
int speed =100;
str thaotac[4] = {" NEW GAME","HIGH SCORE","  SPEED","  EXIT"};

enum TRANGTHAI{UP, DOWN, LEFT, RIGHT, ENTER, BACK};


TRANGTHAI key(int z);
void score(int a[],int d);
int menu(str thaotac[4], int n);
void run2();
int a[max];
int main()
{
	for(int i=0;i<100;i++){
  	a[i]=0;
  };
  run2();
}

TRANGTHAI key(int z){
	if(z==224){
		char c =_getch();
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
	ShowCur(0);
	int tt=0;//bien cho biet dango thao tac thu may
	int *mau = new int[n];
	for(int i=0;i<n;i++)
		mau[i]= MAUCHU;
	mau[0]= MAUNEN;
	while(1){
		clrscr();
		for(int i=0;i<n; i++){
			textcolor(mau[i]);
			cout<<"\n\n\n"<<"\t\t\t\t\t\t"<<thaotac[i] <<"\t\t\t\t\t\t\t"<<endl;
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
			case ENTER:
			{
				s = tt;
				return s;
			}
        }
    for(int i=0;i<n;i++)
    {
        mau[i]= MAUCHU;
    }
	mau[tt]= MAUNEN;
    }
}

void ve_tuong();

class Snake{
	int toa_do_xqua[2];		// gia han so luong qua hien ra 
	int toa_do_yqua[2];		// gia han so luong qua hien ra 	
	vector<int> toa_do_x;
	vector<int> toa_do_y;
	int so_luong; // ====== do dai cua ran ========
	int derection; // ====== huong di chuyen =======
public:
	Snake();
	void tao_ran();
	void ve_ran();
	void dieu_khien();
	void huong_di_chuyen(int& x, int& y);
	void di_chuyen(int x, int y);
	bool kiemtra_ran_cham_tuong();
	bool kiemtra_ran_cham_than();
	bool gameOver();
	void run();
	bool kiemtra_ran_de_qua();
	void tao_qua();
	void ve_qua();
	bool kiemta_ran_an_qua();
	void xu_ly_an_qua();
	
};

Snake::Snake()
{
	toa_do_x = vector<int>();
	toa_do_y = vector<int>();
	so_luong = 5;
	derection = 4;
}

void Snake::tao_ran()
{
	int x_khoi_tao = 50;
	int y_khoi_tao = 15;
	for (int i = 0; i < so_luong; i++)
	{
		toa_do_x.push_back(x_khoi_tao);
		toa_do_y.push_back(y_khoi_tao);
		x_khoi_tao--;
	}
}

void Snake::ve_ran()
{
	gotoXY(toa_do_x[so_luong], toa_do_y[so_luong]);
	cout << " ";
	char c = { '0' };
	for (int i = 0; i < so_luong; i++)
	{
		SetColor(11);
		gotoXY(toa_do_x[i], toa_do_y[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else {
			cout << "o";
		}
	}
}

void Snake::dieu_khien()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == 72 && derection != 2)
		{
			derection = 1;
		}
		else if (c == 80 && derection != 1)
		{
			derection = 2;
		}
		else if (c == 75 && derection != 4)
		{
			derection = 3;
		}
		else if (c == 77 && derection != 3)
		{
			derection = 4;
		}
	}
}

void Snake::huong_di_chuyen(int& x, int& y)
{
	if (derection == 1)
	{
		y--; Sleep(speed+50);
	}
	else if (derection == 2)
	{
		y++; Sleep(speed+50);
	}
	else if (derection == 3)
	{
		x--; Sleep(speed);
	}
	else if (derection == 4)
	{
		x++; Sleep(speed);
	}
}

void Snake::di_chuyen(int x, int y)
{
	for (int i = so_luong; i > 0; i--)
	{
		toa_do_x[i] = toa_do_x[i - 1];
		toa_do_y[i] = toa_do_y[i - 1];
	}
	toa_do_x[0] = x;
	toa_do_y[0] = y;
}

bool Snake::kiemtra_ran_cham_tuong()
{
	if (toa_do_x[0] == 10 || toa_do_x[0] == 95 || toa_do_y[0] == 1 || toa_do_y[0] == 25)
		return false;
	return true;
}

bool Snake::kiemtra_ran_cham_than()
{
	for (int i = 1; i < so_luong; i++)
	{
		if (toa_do_x[0] == toa_do_x[i] && toa_do_y[0] == toa_do_y[i])
			return false;
	}
	return true;

}

bool Snake::gameOver()
{
	if (kiemtra_ran_cham_tuong() == false || kiemtra_ran_cham_than() == false){
		score(a,d);
		d=0;
		return false;
	}
	return true;
}

void Snake::run()
{
	int x = toa_do_x[0], y = toa_do_y[0];
	tao_qua();
	ShowCur(0);
	while (gameOver())
	{
		//=========== ve ran ===========
		ve_ran();

		//========== dieu khien =======
		dieu_khien();

		//=========== huong di chuyen ========
		huong_di_chuyen(x, y);

		//========== di chuyen =======
		di_chuyen(x, y);

		xu_ly_an_qua();
	}
	system("cls");
	gotoXY(45, 5);
	cout << "GAME OVER" << endl;		// khi ket thuc game se hien ra man hinh GAME OVER
}


bool Snake::kiemtra_ran_de_qua()
{
	for (int i = 0; i < so_luong; i++)
	{
		for(int j = 0; j < 2; j++)		// them mot vong lap de thuc hien thuat toan
		{
			if (this->toa_do_xqua[i] == toa_do_x[i] && this->toa_do_yqua[i] == toa_do_y[i])
				return true;
		}
	}
	return false;
}

void Snake::tao_qua()
{
	srand(time(NULL));
	do
	{
		for(int i = 0; i < 2; i++)		//them vong lap de thưc hien thuat toan
		{
			toa_do_xqua[i] = rand() % (90 - 11 + 1) + 11;
			toa_do_yqua[i] = rand() % (23 - 2 + 1) + 2;
		}
		ve_qua();
	} while (kiemtra_ran_de_qua());
}

void Snake::ve_qua()
{
	for(int i = 0; i < 2; i++)		// them vong lap de thuc hien thuat toan
	{
		gotoXY(toa_do_xqua[i], toa_do_yqua[i]);
		cout << "@";
	}
}

bool Snake::kiemta_ran_an_qua()
{
	for(int i = 0; i < 2; i++)		// them vong lap de thuc hien thuat toan
	{
		if(toa_do_x[0] == this->toa_do_xqua[i] && toa_do_y[0] == this->toa_do_yqua[i])
		{
			d++;
			return true;
		}
	}
}

void Snake::xu_ly_an_qua()
{
	if (kiemta_ran_an_qua())
	{
		so_luong++;
		if(d % 2 == 0)		// them dieu kien de khi ran an du het 2 qua tao ra thi moi xuat hien 2 qua tiep theo
		{
			tao_qua();
			ve_qua();	
		}
		gotoXY(1,1);
		cout << "Diem:" << d;
	}
}

void score(int a[],int d)
{
	
	int t=1,i=0;
	while(t==1)
	{
		if(a[i]==0&&i<100)
		{
			a[i]=d;
			t=0;
		}
	i++;
	}
	
}

void sort(int a[])
{
	int tg;
    for(int i = 0; i < 100 - 1; i++)
    {
        for(int j = i + 1; j < 100; j++)
	{
            if(a[i] < a[j])
	    {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
	
    for(int i = 0;i<100;i++)
    {
		if(a[i]!=0)
		{
			cout << "Top "<<i+1<<": "<< a[i]<<endl;
		}
    }
}

void run2(){
	int flat = 1;
	while(flat == 1)
	{
		menu(thaotac,4);
		system("cls");
		gotoXY(1,1);
		cout << "Diem:" << d;
		switch(s)
		{
			case 0:
				{
	               		ve_tuong();
	               		Snake snake;
	               		snake.tao_ran();
	               		snake.run();
	                	_getch();
				    break;
				}
			case 1:
				{
				system("cls");
				sort(a);
				getch();
				    break;
				}
			case 2:
			{
				clrscr();
				int chon;
				gotoXY(1,5);
				cout << "chose level:"<<endl;
				cout << "1- Hard"<<endl;
				cout << "2- Medium"<<endl;
				cout << "3- Normal"<<endl;
                		cin >> chon;
				if(chon==1)
							speed = 50;
							
				if(chon==2)
							speed = 200;
						
				if(chon==3)
							speed = 500;
				clrscr();
					break;
			}
			case 3:
			{
				flat=0;
					break;
			}
        	}
	}
	
}

void ve_tuong()
{
	SetColor(2);
	for (int x = 10; x <= 95; x++)
	{
		gotoXY(x, 1);
		cout << "-";
		gotoXY(x, 25);
		cout << "-";
	}
	for (int y = 1; y <= 25; y++)
	{
		gotoXY(10, y);
		cout << "|";
		gotoXY(95, y);
		cout << "|";
	}
}
