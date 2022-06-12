#include<graphics.h>
void clearMainScreen()
{
	setfillstyle(1, 15);
	bar(301,26, 1250,550);
}
void createInfoScreen()
{
	line(0,550,1250,550);
}
void createMatrix()
{
	line (300,25,300,550);
}

void MaTranTrongSo()
{
	settextstyle(3,0,1);
	line(0, 240, 300, 240);
	line(0, 265, 300, 265);
	outtextxy(70, 241, "Ma Tran Trong So");
	settextstyle(3,0,2);
}

void ManHinh_MaTran()
{
	bar(1, 266, 300, 549);
}

void ThongBaoFile()
{
	setcolor(GREEN);
	rectangle(90, 555, 350, 645);
	line(90, 585, 350, 585);
	rectangle(290,615, 350, 645);
	outtextxy(295, 620, "Thoat");
}

void clearThongBao()
{
	setfillstyle(1, 15);
	bar(1, 551,99999, 700);
}
void ManHinh_HuongDan()
{
	settextstyle(3,0,1);
	outtextxy(5,26,"- Chuot trai: Tao, Chon dinh.");
	outtextxy(5,49,"( Chon 2 dinh de tao cung).");
	outtextxy(5,72,"- Nhay dup chuot phai: Thay doi");
	outtextxy(5,95," ten dinh, trong so cung.");
	outtextxy(5,118,"- Chuot phai: Xoa node, cung.");
	outtextxy(5,141,"- Nhay dup de di chuyen dinh.");
	outtextxy(5,164,"( Nhap chuot phai de ngung di");
	outtextxy(5,187,"chuyen dinh, huy chon dinh).");
	outtextxy(5,210,"Mode: chuyen giua dinh, mon hoc.");
}

bool hoverRec(int x1,int y1, int x2,int y2, int x, int y){
    if (x > x1 && x < x2 && y > y1 && y < y2)
        return 1;
	else
        return 0;
}
