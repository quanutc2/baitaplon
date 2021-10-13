#include <iostream>
#include <vector>
#include "myLib.h"
using namespace std;
class Snake{
    private:
        vector<int> toa_do_x;
        vector<int> toa_do_y;
        int so_luong; // ====== do dai cua ran ========
        int derection; // ====== huong di chuyen =======
    public:
    	Snake();
        void tao_ran();
        void ve_ran();
        void dieu_khien();
        void di_chuyen(int x, int y);
        void run();
};

Snake::Snake()
{
	toa_do_x = vector<int>();
	toa_do_y = vector<int>();
	so_luong = 4;
	derection = 4;
}

void Snake::tao_ran()
{
    int x_khoi_tao = 50;
    int y_khoi_tao = 15;
    for(int i = 0; i < so_luong; i++)
    {
        toa_do_x.push_back(x_khoi_tao);
        toa_do_y.push_back(y_khoi_tao);
        x_khoi_tao--;
    }
}

void Snake::ve_ran()
{
	char c = {'0'};
	for(int i = 0; i < so_luong; i++)
	{
		SetColor(11);
		gotoXY(toa_do_x[i], toa_do_y[i]);
		if(i == 0)
		{
			cout << c;
		} else{
			cout << "o";
		}
	}
}

void Snake::dieu_khien()
{
	if(_kbhit())
	{
		char c = _getch();
		if(c == 'w' && derection != 2)
		{
			derection = 1;
		}
		else if(c == 's' && derection != 1)
		{
			derection = 2;
		}
		else if(c == 'a' && derection != 4)
		{
			derection = 3;
		}
		else if(c == 'd' && derection != 3)
		{
			derection = 4;
		}
	}
}

void Snake::di_chuyen(int x, int y)
{
	for(int i = so_luong; i > 0; i--)
	{
		toa_do_x[i] = toa_do_x[i - 1];
		toa_do_y[i] = toa_do_y[i - 1];
	}
	toa_do_x[0] = x;
	toa_do_y[0] = y;
}

void Snake::run()
{
	int x = toa_do_x[0], y = toa_do_y[0];
	ShowCur(0);
	while(true)
	{
		gotoXY(toa_do_x[so_luong], toa_do_y[so_luong]);
		cout << " ";
		
		//=========== ve ran ===========
		ve_ran();
		
		//========== dieu khien =======
		dieu_khien();
		
		//=========== chay ran ========
		if(derection == 1)
		{
			y--;Sleep(150);
		}
		else if(derection == 2)
		{
			y++;Sleep(150);
		}
		else if(derection == 3)
		{
			x--;Sleep(100);
		}
		else if(derection == 4)
		{
			x++;Sleep(100);
		}
		//========== di chuyen =======
		di_chuyen(x, y);
	}
}

int main()
{
    Snake snk = Snake();
    snk.tao_ran();
    snk.run();
    _getch();
}
