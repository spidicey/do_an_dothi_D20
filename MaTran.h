#include"DoThi.h"

void resetchar(char s[])
{
	for(int i = 0; i<strlen(s); i++)
		s[i] = '\0';
}

void chonNew()
{
	if(dt.stt_Node >=0)
	{
		for(int i = 0; i<= dt.stt_Node; i++)
		{
			resetchar(dt.node[i].name);
			resetchar(dt.node[i].tenMonHoc);
		}
		dt.reset_MT(dt.MT);
		dt.stt_Node = -1;
	}
}

void recreate(Node temp)
{
	if(dt.stt_Node >= 0)
	{
		setcolor(15);
		setbkcolor(15);
		for(int i=0;i<=20;i++) circle(temp.x,temp.y, i);
		setcolor(BLACK);
		for(int i=20;i<=22;i++) circle(temp.x,temp.y, i);
		if(temp.name[1]=='\0'||temp.name[2]=='\0'){
			settextjustify(1, 1);
			settextstyle(1,0,0);
			setusercharsize(3,10,2,3);
			outtextxy(temp.x,temp.y+7,temp.name);
		}
		else if(temp.name[3]=='\0'){
			settextjustify(1, 1);
			settextstyle(0,0,0);
			setusercharsize(11,10,11,4);
			outtextxy(temp.x,temp.y+7,temp.name);
		}
		else{
			char a[3],b[3];
			a[0]=temp.name[0]; a[1]=temp.name[1]; b[0]=temp.name[2]; b[1]=temp.name[3];
			a[2]='\0'; b[2]='\0';
			settextjustify(1, 1);
			settextstyle(1,0,0);
			setusercharsize(3,10,11,30);
			outtextxy(temp.x,temp.y-2,a);
			outtextxy(temp.x,temp.y+10,b);
		}
		settextjustify(0,2);
		settextstyle(3,0,2);
	}
}

void VeNode(int x, int y)
{
	for(int i=20;i<=22;i++) 
		circle(x, y, i);
}

void CapNhatNode()
{
	clearMainScreen();
	if(dt.stt_Node>=0)
	{
		for(int i = 0; i<=dt.stt_Node; i++)
		{
			setcolor(BLACK);
			settextstyle(1,0,0);
			setusercharsize(3,10,2,3);
				recreate(dt.node[i]);
		}
	}
}


void VeMaTran()
{
	ManHinh_MaTran();
	if(dt.stt_Node>=0)
	{
		int a = 11<dt.stt_Node?11:dt.stt_Node;
		setcolor(4);
		settextstyle(0, 0, 1);
		for(int i = 0; i<=dt.stt_Node; i++)
		{
			for(int j = 0; j<= dt.stt_Node; j++)
			{
				if(dt.MT[i][j] != 0)
				{
					char a[10];
					itoa(dt.MT[i][j], a, 10);
					if(strlen(a)==1)
						outtextxy(5 + 27*(j+1) + 9, 270 + 25*(i+1)+7, a); // trong so
					else
						outtextxy(5 + 27*(j+1) + 3, 270 + 25*(i+1)+7, a);
				}
			}
		}
		
		for(int i = 0; i<=dt.stt_Node+1; i++)
		{
			setcolor(2);
			line(1+27*i, 270, 1+27*i, 270+25*(a+2));  // Ve Duong Doc
			line(1+27*(i+1), 270, 1+27*(i+1), 270+25*(a+2));
		}
		
		
		for(int i = 0; i<=dt.stt_Node+1; i++)	 
		{
			setcolor(2);
			line(1, 270+25*i, 1+27*(a+2), 270+25*i); // Ve Duong Ngang
			line(1, 270+25*(i+1), 1+27*(a+2), 270+25*(i+1));
		}
		for(int i = 0; i<=dt.stt_Node; i++)
		{
			setcolor(4);
			
			settextstyle(2, 0, 1);
			setusercharsize(2, 2, 1, 1);
			 //Hien Thi Gia Tri Node Hang Ngang
			if(strlen(dt.node[i].name)<= 2)
				outtextxy(5+27*(i+1)+1, 270+3, dt.node[i].name); 
			else
					outtextxy(2+27*(i+1)+1, 270+3, dt.node[i].name);
			settextstyle(3, 0, 1);
		}	
		
		for(int i = 0; i<= dt.stt_Node; i++)
		{
			setcolor(4);
			settextstyle(2, 0, 1);
			setusercharsize(2, 2, 1, 1);
			if(strlen(dt.node[i].name)<= 2)
				outtextxy(7, 270+25*(i+1)+1, dt.node[i].name); // Hien Thi Gia Tri Node Hang Doc
			else
				outtextxy(2, 270+25*(i+1)+1, dt.node[i].name);
			settextstyle(3, 0, 1);
			setcolor(BLACK);
		}		
	}	
}


