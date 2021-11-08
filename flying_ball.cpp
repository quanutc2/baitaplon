#include "winbgim.h"
#include <Math.h>
bool chonPlay = true, chonExit = false;

class toado
{
    // toa do x,y
public: int x;
public: int y;
};
class vienbi
{
public:
    bool goc25 = false, goc155 = false, goc90 = true, goc45 = false, goc135 = false, roi = true, bientrai = false, bienphai = false;

public:
    toado td;
public:
    int kichthuoc;
    vienbi()
    {
        td.x = 500;
        td.y = 0;
        kichthuoc = 10;
    }

public: void ve()
{
    setcolor(2); // mau xanh la
    arc(td.x, td.y, 0, 360, kichthuoc); // ve cung tron x,y , bat dau tu  ket thuc = 360 , ban kinh
    setfillstyle(1, 2);// mau, mau xanh la
    floodfill(td.x, td.y, 2); // to vien 

    setcolor(14);// mau vang
    // neu roi bang false thi bong di len 
    if (roi == false)
    {
        ellipse(td.x, td.y, 165, 375, kichthuoc * 1.3, kichthuoc * 0.4); // ve hinh ellip toa do x,y, chay tu 165 den 375 , ban kinh truc x,truc y      
    }
    // neu roi bang true thi bong di xuong
    if (roi == true)
    {
        ellipse(td.x, td.y, 165, 375, kichthuoc * 1.3, kichthuoc * 0.4);// vong ngang
        ellipse(td.x, td.y, 260, 465, kichthuoc * 0.4, kichthuoc * 1.3);// vong doc

    }
}


public:
    void vevjp()
    {
        setcolor(5);// mau do
        arc(td.x, td.y, 0, 360, kichthuoc);// ve hinh tron
        setfillstyle(1, 5); // mau, mau do
        floodfill(td.x, td.y, 5);
        setcolor(15);// trang
        if (roi == false)
        {
            ellipse(td.x, td.y, 165, 375, kichthuoc * 1.3, kichthuoc * 0.4); // ngang

        }
        if (roi == true)
        {
            ellipse(td.x, td.y, 165, 375, kichthuoc * 1.3, kichthuoc * 0.4);// ngang
            ellipse(td.x, td.y + 1, 260, 465, kichthuoc * 0.4, kichthuoc * 1.3);// doc
        }
    }
};
class thanhngang
{
public: toado td;
public: int chieudai;
public: int chieurong;

public:
    void vetn()
    {

        // ve thanh ngoai
        setcolor(3);// xanh duong lot
        rectangle(td.x, td.y, td.x + chieudai, td.y + chieurong);//ve hcn L,T,R,B
        setfillstyle(3, 3);// mau xoch, mau xanh
        floodfill(td.x + 75, td.y + 15, 3);// toa do, mau (3)

        // ve thanh trong
        setcolor(14);// vang 
        rectangle(td.x + 20, td.y + 5, td.x + chieudai - 20, td.y + chieurong - 5);//ve hcn L,T,R,B
        setfillstyle(1, 14);// mau,mau vang
        floodfill(td.x + 75, td.y + 15, 14);// tô mau vien
        // cung tron trong
        setcolor(14);
        for (int r = 10; r > 0; r--) { // ban kinh 10
            arc(td.x + 20, td.y + 15, 90, 270, r);
            arc(td.x + chieudai - 20, td.y + 15, 270, 450, r);
        }
        // cung tron ngoai
        setcolor(3);
        for (int r = 15; r > 0; r--)
        {
            arc(td.x, td.y + 15, 90, 270, r);
            arc(td.x + chieudai, td.y + 15, 270, 450, r);
        }
    }


};
void dkthanhngang(char key, thanhngang& TN)
{
    if (key == 75 && TN.td.x > 0)// trai 
        TN.td.x -= 40; // buoc nhay 
    if (key == 77 && (TN.td.x + TN.chieudai) < 1050)//phai
        TN.td.x += 40;
}
void xulyvacham(vienbi& vb, thanhngang tn, int& d)
{
    char* a[100] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    int i;
    int j = 1;
    int k = 0;
    if (d < 10)
    {
        outtextxy(900, 20, a[0]);
        outtextxy(920, 20, a[0]);
        outtextxy(940, 20, a[d]);
    }
    if (d > 9 && d < 100)
    {
        switch (d)
        {
        case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:i = d - 10; j = 1; break;
        case 20:case 21:case 22:case 23:case 24:case 25:case 26:case 27:case 28:case 29:i = d - 20; j = 2; break;
        case 30:case 31:case 32:case 33:case 34:case 35:case 36:case 37:case 38:case 39:i = d - 30; j = 3; break;
        case 40:case 41:case 42:case 43:case 44:case 45:case 46:case 47:case 48:case 49:i = d - 40; j = 4; break;
        case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 58:case 59:i = d - 50; j = 5; break;
        case 60:case 61:case 62:case 63:case 64:case 65:case 66:case 67:case 68:case 69:i = d - 60; j = 6; break;
        case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:i = d - 70; j = 7; break;
        case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:i = d - 80; j = 8; break;
        case 90:case 91:case 92:case 93:case 94:case 95:case 96:case 97:case 98:case 99:i = d - 90; j = 9; break;
        }

        outtextxy(900, 20, a[k]);
        outtextxy(920, 20, a[j]);
        outtextxy(940, 20, a[i]);
    }
    if (d > 99)
    {
        d = 10;
    }
    if (vb.td.y >= 530 && vb.td.y <= 550)
    {
        if (vb.td.x + 20 >= tn.td.x && vb.td.x - 20 <= tn.td.x + tn.chieudai)
        {
            if (vb.goc45 == true || vb.goc90 == true)
            {
                if (vb.bientrai == false && vb.bienphai == false)//2,8
                {

                    vb.goc155 = false;
                    vb.goc135 = false;
                    vb.goc45 = true;
                    vb.goc90 = false;
                    vb.goc25 = false;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
                else//5
                {
                    vb.goc155 = false;
                    vb.goc135 = true;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = false;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
            }
            if (vb.goc135 == true)
            {
                if (vb.bientrai == false && vb.bienphai == false)//5
                {

                    vb.goc155 = true;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = false;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
                else
                {
                    vb.goc155 = false;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = true;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
            }
            if (vb.goc25 == true)
            {
                if (vb.bientrai == false && vb.bienphai == false)
                {

                    vb.goc155 = false;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = true;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }

                else
                {
                    vb.goc155 = true;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = false;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
            }
            if (vb.goc155 == true)
            {
                if (vb.bientrai == false && vb.bienphai == false)//5
                {

                    vb.goc155 = true;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = false;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
                else//12
                {
                    vb.goc155 = false;
                    vb.goc135 = false;
                    vb.goc45 = false;
                    vb.goc90 = false;
                    vb.goc25 = true;
                    vb.roi = false;
                    vb.bientrai = false;
                    vb.bienphai = false;
                }
            }
            d++;
        }
    }
    if (vb.td.y <= vb.kichthuoc)//1,3,13
    {
        vb.roi = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bientrai == true && vb.goc135 == true)
    {
        vb.roi = true;
        vb.bientrai = false;
        vb.goc135 = false;
        vb.goc25 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bientrai == true && vb.goc155 == true)//7,17
    {
        vb.roi = true;
        vb.bientrai = false;
        vb.goc155 = false;
        vb.goc45 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bientrai == true && vb.goc25 == true)
    {
        vb.roi = true;
        vb.bientrai = false;
        vb.goc25 = false;
        vb.goc135 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bientrai == true && vb.goc45 == true)
    {
        vb.roi = true;
        vb.bientrai = false;
        vb.goc155 = true;
        vb.goc45 = false;
    }
    ///phai
    if (vb.td.y <= vb.kichthuoc && vb.bienphai == true && vb.goc135 == true)
    {
        vb.roi = true;
        vb.bienphai = false;
        vb.goc135 = false;
        vb.goc25 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bienphai == true && vb.goc155 == true)
    {
        vb.roi = true;
        vb.bienphai = false;
        vb.goc155 = false;
        vb.goc45 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bienphai == true && vb.goc25 == true)
    {
        vb.roi = true;
        vb.bienphai = false;
        vb.goc25 = false;
        vb.goc135 = true;
    }
    if (vb.td.y <= vb.kichthuoc && vb.bienphai == true && vb.goc45 == true)//10
    {
        vb.roi = true;
        vb.bienphai = false;
        vb.goc155 = true;
        vb.goc45 = false;
    }

    if (vb.td.x <= vb.kichthuoc)//6,11,16
    {
    
        vb.bientrai = true;
        vb.bienphai = false;
    }

    if (vb.td.x >= 1020 - vb.kichthuoc)//4,9,14
    {
       
        vb.bienphai = true;
        vb.bientrai = false;
    }
}
////
///

////
///
void chuyendong(vienbi& vb, int tocdo)
{
    double a = tocdo;
    double b = 2;
    if (vb.roi == false && vb.goc135 == true && vb.bientrai == false && vb.bienphai == false)
    {
        vb.td.x -= a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc155 == true && vb.bientrai == false && vb.bienphai == false)//5,15
    {
        vb.td.x -= b + a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc25 == true && vb.bientrai == false && vb.bienphai == false)//12
    {
        vb.td.x += b + a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc45 == true && vb.bientrai == false && vb.bienphai == false)//2,8
    {
        vb.td.x += a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc90 == true)
    {
        vb.td.y -= a;
    }

    if (vb.roi == true && vb.goc135 == true && vb.bientrai == false && vb.bienphai == false)
    {
        vb.td.x -= a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc155 == true && vb.bientrai == false && vb.bienphai == false)//10
    {
        vb.td.x -= b + a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc25 == true && vb.bientrai == false && vb.bienphai == false)//13
    {
        vb.td.x += b + a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc45 == true && vb.bientrai == false && vb.bienphai == false)//3,7//17
    {
        vb.td.x += a;
        vb.td.y += a;

    }
    if (vb.roi == true && vb.goc90 == true)//1
    {
        vb.td.y += a;
    }

    //cham bien
    if (vb.roi == false && vb.goc135 == true && vb.bientrai == true)
    {
        vb.td.x += a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc155 == true && vb.bientrai == true)//6,16
    {
        vb.td.x += b + a;
        vb.td.y -= a;
    }

    if (vb.roi == false && vb.goc45 == true && vb.bienphai == true)//9
    {
        vb.td.x -= a;
        vb.td.y -= a;
    }
    if (vb.roi == false && vb.goc25 == true && vb.bienphai == true)
    {
        vb.td.x -= a;
        vb.td.y -= a;
    }

    if (vb.roi == true && vb.goc135 == true && vb.bientrai == true)
    {
        vb.td.x += a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc155 == true && vb.bientrai == true)//11
    {
        vb.td.x += b + a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc45 == true && vb.bienphai == true)//4
    {
        vb.td.x -= a;
        vb.td.y += a;
    }
    if (vb.roi == true && vb.goc25 == true && vb.bienphai == true)//14
    {
        vb.td.x -= b + a;
        vb.td.y += a;
    }
}
////
void vechon(int x, int y)
{

    setcolor(14);
    int a[6] = { x, y, x, y - 50, x - 60, y - 25 };
    fillpoly(3, a); // ve tam giac
    int b[6] = { x + 290, y, x + 290, y - 50, x + 350, y - 25 };
    fillpoly(3, b);
}
///
void vebtn(int x, int y)
{
    moveto(x, y);// thay doi vi tri
    lineto(x, y - 50);
    lineto(x + 250, y - 50);
    lineto(x + 250, y);
    lineto(x, y);
}
void vemenu()
{
    vebtn(400, 250);
    settextstyle(3, 0, 4);// phong chu, phuong huong(trai sang phai or duoi di len ) ,kich co
    outtextxy(435, 207, "PLAY GAME");
    vebtn(400, 450);
    outtextxy(490, 407, "EXIT");

    if (chonPlay == true)
        vechon(380, 250);
    if (chonExit == true)
        vechon(380, 450);
}
////
///main

int main(int argc, char* argv[])
{
    initwindow(1000, 600);
choi:
    int x = 0;
    //vien bi
    vienbi VB;
    VB.td.x = 200;
    VB.td.y = 0;
    VB.kichthuoc = 20;
    // thanh ngang
    thanhngang TN;
    TN.td.x = 550;
    TN.td.y = 550;
    TN.chieudai = 150;
    TN.chieurong = 30;
    double tocdo = 3;
    int dem = 2000;
    int menu = 0;
    int diem = 0;
    vienbi vb;
    while (!menu)
    {

        cleardevice();
        vemenu();
        // CHON
        if (kbhit())
        {
            char key = getch();
            if (key == 72)// len 
            {
                chonPlay = true;
                chonExit = false;
            }
            if (key == 80)// xuong
            {
                chonExit = true;
                chonPlay = false;
            }
            if (key == 13 || key == 32)// enter, dau cach
            {
                if (chonPlay == true)
                {
                    goto Play;
                }
                else
                    goto Exit;
            }
        }
        delay(1);
    }
Play:;
    diem = 0;
    while (!menu)
    {
        dem++;//2000 +1
        cleardevice();
        settextstyle(2, 0, 8);
        outtextxy(800, 20, "Diem: ");
        if (VB.goc90 == true || VB.goc45 == true || VB.goc135 == true)
            VB.ve();
        else
            VB.vevjp();
        if (dem >= 3000)
        {
            if (dem % 3000 == 0 && dem != 0)
            {

                vb.td.x = 500;
                vb.td.y = 0;
                vb.kichthuoc = 10;
            }
            if (vb.goc90 == true || vb.goc45 == true || vb.goc135 == true)
                vb.ve();
            else
                vb.vevjp();
            xulyvacham(vb, TN, diem);
            chuyendong(vb, 2);
        }
        xulyvacham(VB, TN, diem);
        if (dem % 2000 == 0)
            tocdo += 0.5;
        chuyendong(VB, tocdo);
         TN.vetn();
        //dieu khien
        if (kbhit())
        {
            char ch = getch();
            dkthanhngang(ch, TN);
        }
        delay(1);
        if (VB.td.y > 600)
        {
            goto ra;
        }
    }
ra:
    {
        while (!menu)
        {
            cleardevice();
            outtextxy(400, 250, "GAME OVER");
            outtextxy(290, 300, "NHAN 'ENTER' HOAC 'SPACE'");
            char nut = getch();
            if (nut == 13 || nut == 32)
            {
                goto choi;
            }
            delay(10);
        }
    }
Exit:;
    return 0;

}
