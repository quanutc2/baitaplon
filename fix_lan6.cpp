#include <iostream>
#include <vector>
#include<ctime>
#include "myLib.h"

using namespace std;

void ve_tuong();

class Snake {
	protected:
		vector<int> toa_do_x;
		vector<int> toa_do_y;
		int so_luong; // ====== do dai cua ran ========
		int derection; // ====== huong di chuyen =======
	public:
		Snake();
		void tao_ran();
		void ve_ran();
		void dieu_khien();
		void huong_di_chuyen(int &x, int &y);
		void di_chuyen(int x, int y);
		bool kiemtra_ran_cham_tuong();
		bool kiemtra_ran_cham_than();
		bool gameOver();
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

void Snake::huong_di_chuyen(int &x, int &y)
{
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
	if(toa_do_x[0] == 10 || toa_do_x[0] == 95 || toa_do_y[0] == 1 || toa_do_y[0] == 25)
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
	if (kiemtra_ran_cham_tuong() == false || kiemtra_ran_cham_than() == false)
		return false;
	return true;
}

void Snake::run()
{
	int x = toa_do_x[0], y = toa_do_y[0];
	Food food;
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
		
		food.xu_ly_an_qua();
	}
}

class Food:public Snake{
	private:
		int toa_do_xqua;
		int toa_do_yqua;
	public:
		Food();
		bool kiemtra_ran_de_qua();
		void tao_qua();
		void ve_qua();
		bool kiemta_ran_an_qua();
		void xu_ly_an_qua();
};

Food::Food()
{
	toa_do_xqua = 0;
	toa_do_yqua = 0;
}

bool Food:: kiemtra_ran_de_qua()
{
	for(int i = 0; i < so_luong; i++)
	{
		if(this->toa_do_xqua == toa_do_x[i] && this->toa_do_yqua == toa_do_y[i]) 
			return true;
	}
	return false;
}

void Food::tao_qua() 
{
	srand(time(NULL));
	do
	{
	toa_do_xqua = rand() % (99 - 11 + 1) + 11;
	toa_do_yqua = rand() % (25 - 2 + 1) + 2;
	} while(kiemtra_ran_de_qua());
}

void Food::ve_qua() 
{
	gotoXY(toa_do_xqua, toa_do_yqua);
	cout << "@";
}

bool Food::kiemta_ran_an_qua()
{
	return (toa_do_x[0] == this->toa_do_xqua && toa_do_y[0] == this->toa_do_yqua);
}

void Food::xu_ly_an_qua()
{
	if(kiemta_ran_an_qua())
	{
		so_luong++;
		tao_qua();
		ve_qua();
	}
}


int main()
{
	ve_tuong();
	Snake snake;
	Food food;
	snake.tao_ran();
	snake.run();
	_getch();
}

void ve_tuong()
{
	for(int x = 10; x <= 95; x++)
	{
		gotoXY(x, 1);
		cout << "+";
		gotoXY(x, 25);
		cout << "+";
	}
	for(int y = 1; y <= 25; y++)
	{
		gotoXY(10, y);
		cout << "+";
		gotoXY(95, y);
		cout << "+";
	}
}
