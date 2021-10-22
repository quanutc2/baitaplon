#include <iostream>
#include <vector>
#include<ctime>
#include "myLib.h"
using namespace std;
class Snake {
private:
	vector<int> toa_do_x;
	vector<int> toa_do_y;
	int so_luong; // ====== do dai cua ran ========
	int derection; // ====== huong di chuyen =======
public:
	Snake();
	void vetuongtren();
	void vetuongduoi();
	void vetuongphai();
	void vetuongtrai();
	void tao_ran();
	void ve_ran();
	void dieu_khien();
	void di_chuyen(int x, int y,int xqua,int yqua);
	bool kiemtra_ran_cham_tuong();
	bool kiemtra_ran_cham_than();
	bool gameOver();
	void tao_qua(int& xqua, int& yqua);
	bool kiemtra_ran_dequa(int xqua,int yqua);
	bool kiemtra_ran_anqua(int xqua,int yqua);
	void run();
};

Snake::Snake()
{
	toa_do_x = vector<int>();
	toa_do_y = vector<int>();
	so_luong = 6;
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
		if (c == 'w' && derection != 2)
		{
			derection = 1;
		}
		else if (c == 's' && derection != 1)
		{
			derection = 2;
		}
		else if (c == 'a' && derection != 4)
		{
			derection = 3;
		}
		else if (c == 'd' && derection != 3)
		{
			derection = 4;
		}
	}
}

void Snake::di_chuyen(int x, int y,int xqua,int yqua)
{
	for (int i = so_luong; i > 0; i--)
	
	{
		if(kiemtra_ran_anqua( xqua ,yqua)==false){
		
		toa_do_x[i] = toa_do_x[i - 1];
		toa_do_y[i] = toa_do_y[i - 1];
	}else{
	
	toa_do_x[0] = x;
	toa_do_y[0] = y;
	}
	}
}

bool Snake::kiemtra_ran_cham_tuong()
{
	if (toa_do_x[0] == 10 || toa_do_x[0] == 100 || toa_do_y[0] == 1 || toa_do_y[0] == 26)
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
bool Snake:: kiemtra_ran_dequa(int xqua,int yqua){
	for(int i=0;i<so_luong;i++){
		if(xqua==toa_do_x[i]&&yqua==toa_do_y[i]) return true;
		}
		return false;
		}
		
bool Snake:: kiemtra_ran_anqua(int xqua,int yqua){
		if(toa_do_x[0]==xqua&&toa_do_y[0]==yqua){
			return true;
			}
			return false;
			}
bool Snake::gameOver()
{
	if (kiemtra_ran_cham_tuong() == false || kiemtra_ran_cham_than() == false)
		return false;
	return true;
}

void Snake::vetuongtren()
{
	int x = 10, y = 1;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}

}
void Snake::vetuongphai()
{
	int x = 100, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void Snake::vetuongduoi()
{
	int x = 10, y = 26;;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;

	}
}
void Snake::vetuongtrai()
{
	int x = 10, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void Snake::tao_qua(int& xqua, int& yqua)
{
	do{
	
	xqua = rand() % (99 - 11 + 1) + 11;
	yqua = rand() % (25 - 2 + 1) + 2;
	gotoXY(xqua, yqua);
	cout<<"@";
	
	}while(kiemtra_ran_dequa(xqua,yqua)==true);
}

void Snake::run()
{
	vetuongtren();
	vetuongduoi();
	vetuongphai();
	vetuongtrai();
	int xqua = 0; int yqua = 0;
	srand(time(NULL));
	tao_qua(xqua, xqua);
	int x = toa_do_x[0], y = toa_do_y[0];

	ShowCur(0);
	while (gameOver())
	{
		gotoXY(toa_do_x[so_luong], toa_do_y[so_luong]);
		cout << " ";

		//=========== ve ran ===========
		ve_ran();

		//========== dieu khien =======
		dieu_khien();

		//=========== chay ran ========
		if (derection == 1)
		{
			y--; Sleep(150);
		}
		else if (derection == 2)
		{
			y++; Sleep(150);
		}
		else if (derection == 3)
		{
			x--; Sleep(100);
		}
		else if (derection == 4)
		{
			x++; Sleep(100);
		}
		//========== di chuyen =======
		di_chuyen(x, y,xqua,yqua);
	}
}

int main()
{
	Snake snk = Snake();
	snk.tao_ran();
	snk.run();
	_getch();
}
