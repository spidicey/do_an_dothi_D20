#include<graphics.h>

class button
{
	public:
	int x1,y1,x2,y2,textpos;
	char *name;
	button(int X1,int Y1,int X2,int Y2,int textPos,char* Name)
	{
		x1=X1;
		y1=Y1;
		x2=X2;
		y2=Y2;
		textpos=textPos;
		name=Name;
	}
	create()
	{
		setfillstyle(1,WHITE);
		bar(x1+2, y1-2, x2-1, y2);
		outtextxy(textpos, y1-1, name);
	}
	highlight()
	{
		setfillstyle(1,LIGHTBLUE);
		bar(x1+2,y1-2,x2-1,y2);
		setbkcolor(LIGHTBLUE);
		setcolor(BLACK);
		outtextxy(textpos,y1-1,name);
		setbkcolor(WHITE);
	}
	deleteButton()
	{
		setfillstyle(1,WHITE);
		bar(x1+2,y1+1,x2-1,y2);
	}
	hover()
	{
		if (mousex() >= x1 && mousex() <= x2 && mousey() >= y1 && mousey() <= y2)
		{
       	    return 1;
       	}
	    else
		{
	        return 0;
	    }
	}
};



void createFile()
{
	setfillstyle(1,WHITE);
	bar(0,0,47,25);
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(3,0,2);
	outtextxy(7,1,"File");
	setcolor(LIGHTGRAY);
	line(0,25,1000,25);
	setcolor(0);
}
void fileHighlight()
{
	setfillstyle(1,LIGHTCYAN);
	bar(0,0,46,25);
	setcolor(LIGHTBLUE);
	rectangle(0,0,46,25);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	settextstyle(3,0,2);
	outtextxy(7,1,"File");
	setcolor(BLUE);
	line(0,25,46,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
}
void createFileMenu(button a[3])
{
	setcolor(BLACK);
	rectangle(0,26,101,111);
	setcolor(LIGHTGRAY);
	rectangle(0,26,100,110);
	rectangle(0,26,102,112);
	setcolor(BLACK);
	for(int i =0;i<3;i++)
	{
		a[i].create();
	}
}
void deleteFileMenu()
{
	setfillstyle(1,WHITE);
	bar(0,26,103,114);
}
void createTool()
{
	setfillstyle(1,15);
	bar(47,0,93,25);
	setcolor(LIGHTGRAY);
	line(47,25,1000,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(50,1,"Tool");
}
void ToolHighlight()
{
	setfillstyle(1,LIGHTCYAN);
	bar(46,0,92,25);
	setcolor(LIGHTBLUE);
	rectangle(46,0,92,25);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	settextstyle(3,0,1);
	outtextxy(50,1,"Tool");
	setcolor(BLUE);
	line(46,25,92,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
}
void createToolMenu(button a[10])
{
	setcolor(BLACK);
	rectangle(46,25,151,165);
	setcolor(LIGHTGRAY);
	rectangle(46,25,150,163);
	rectangle(46,25,152,164);
	setcolor(BLACK);
	line(46,26,46, 165);
	for (int i =0;i<5;i++){
		a[i].create();
	}
}
void deleteToolMenu()
{
	setfillstyle(1,WHITE);
	bar(45,26,153,291);
}
//////////////////////////////////////////////////////

void createAlgo()
{
	setfillstyle(1,15);
	bar(95, 0, 145, 25);
	setcolor(LIGHTGRAY);
	line(47, 25, 1000, 25);
	setcolor(BLACK);
	setbkcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(100,1,"Algo");
}
void algoHighlight()
{
	setfillstyle(1,LIGHTCYAN);
	bar(96, 0, 144, 25);
	setcolor(LIGHTBLUE);
	rectangle(96, 0, 144, 25);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	settextstyle(3,0,1);
	outtextxy(100,1,"Algo");
	setcolor(BLUE);
	line(96, 25, 144, 25);
	setcolor(BLACK);
	setbkcolor(WHITE);
}
void createAlgoMenu(button a[10])
{
	setcolor(BLACK);
	rectangle(95, 25, 199, 291);
	setcolor(LIGHTGRAY);
	rectangle(96, 26, 197, 289);
	rectangle(97, 27, 198, 290);
	setcolor(BLACK);
	line(95, 25, 192, 25);
	for (int i =0;i<10;i++){
		a[i].create();
	}
}
void deleteAlgoMenu()
{
	setfillstyle(1,WHITE);
	bar(95, 26, 207, 291);
}

/////////////////////////////////////////////////////////
bool Hover(int x1, int y1, int x2, int y2)
{
    if (mousex() >= x1 && mousex() <= x2 && mousey() >= y1 && mousey() <= y2)
        return 1;
	else
        return 0;
}

void clearMainScreen()
{
	bar(301,26,1000,550);
}

void clearThongBao()
{
	setfillstyle(1, 15);
	bar(1, 551, 1000, 700);
}

void createInfoScreen()
{
	line(0,550,1000,550);
}
void createMatrix()
{
	line (300,25,300,550);
}

void MaTranTrongSo()
{
	line(0, 240, 300, 240);
	line(0, 265, 300, 265);
	outtextxy(70, 241, "Ma Tran Trong So");
}

void ManHinh_MaTran()
{
	bar(1, 266, 300, 549);
}

//void CapNhatNode()
//{
//	bar(301, 26, 998, 549);
//	for(int i = 0; i<= dt.stt_Node; i++)
//	{
//		circle(dt.node[i].x, dt.node[i].y, 20);
//		outtextxy(dt.node[i].x, dt.node[i].y, dt.node[i].name);
//	}
//}


//void Ham()
//{
//		if(mousey()>46&&mousey()<570&&mousex()>321)
//		{	//Lam viec voi Node
//			bool check=0;
//			bool check40=0;
//			for(int i=0;i<=dt.stt_Node;i++)
//			{		// check Node hover
//				if(hover(dt.node[i]))
//				{
//					check=1;
//					highlight(dt.node[i]);		//highlight Node
//					if(GetAsyncKeyState(0x01)){		//neu Node duoc chon
//						if(chosenNode!=-1&&chosenNode!=i&&dt.MT[i][chosenNode]!=0){
//							link temp(dt.node[chosenNode],dt.node[i]);
//							dt.MT[chosenNode][i]=temp.reversedLink();
//							cout<<1;
//							VeMaTran();
//							chosenNode=-1;
//						}
//						else if(chosenNode!=-1&&chosenNode!=i){
//							link temp(dt.node[chosenNode],dt.node[i]);
//							dt.MT[chosenNode][i]=temp.createLink();
//							VeMaTran();
//							chosenNode=-1;
//						}
//						else if(chosenNode==-1){
//						highlight(dt.node[i]);
//						chosenNode=i;
//					}	
//					while(GetAsyncKeyState(0x01));
//					}
//					if(GetAsyncKeyState(0x0002)){		//neu Node duoc huy chon
//						recreate(dt.node[i]);
//						chosenNode=-1;
//					}
//					while(GetAsyncKeyState(0x0002));
//				}
//				if(hover40(dt.node[i])){
//					check40=1;
//				}
//			}	
//			for(int i=0;i<=dt.stt_Node;i++){
//				for(int j=0;j<=dt.stt_Node;j++)
//				if(dt.MT[i][j]!=0){
//					link temp(dt.node[i],dt.node[j]);
//					if(temp.hoverLink()){
//						temp.highlightLink(dt.MT[i][j]);
//					}
//					else{
//						//temp.recreateLink(dt.MT[i][j]);
//					}
//				}
//			}
//			if(GetAsyncKeyState(0x01)&&check40==0&&chosenNode==-1){		//tao Node khi khong co nut dang hover
//				Node Node1;
//				create(Node1);
//				dt.stt_Node++;
//				dt.init_node(1,1);
//				dt.init_MT(1,1);
//				dt.node[dt.stt_Node].x=Node1.x;dt.node[dt.stt_Node].y=Node1.y;
//				dt.node[dt.stt_Node].name[0]=Node1.name[0];
//				dt.node[dt.stt_Node].name[1]=Node1.name[1];
//				dt.node[dt.stt_Node].name[2]='\0';	//them vao danh sach tat ca Node
//				VeMaTran();
//			}
//			if(check==0&&chosenNode!=0)
//			{	//kiem tra co Node nao dang duoc hover khong
//				for(int j=0; j<=dt.stt_Node; j++){
//					if(j==chosenNode) continue;
//						recreate(dt.node[j]);
//					}	
//			}
//			else check =0;
//		}
//}
//


//void menuInteraction(button file[3],button Tool[5], button algo[10], bool &fileHovered,bool &ToolHovered, bool &algoHovered){
//	while(1)
//	{
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//		if(Hover(filex1, filey1, filex2, filey2)||fileHovered==1)
//		{
//			fileHighlight();
//			fileHovered=1;
//			createFileMenu(file);
//			for(int i=0;i<3;i++)
//			{
//				if(file[i].hover())
//				{
//					file[i].highlight();
//					if(ismouseclick(WM_LBUTTONDOWN))
//					{
//						getmouseclick(WM_LBUTTONDOWN, x, y);
//						if(hoverRec(fileMenux1, newy1, fileMenux2, newy2, x, y))
//						{
//							setTrue(New);
//							setcolor(GREEN);
//							outtextxy(100, 600, "Chon New");
//						}
//						else if(hoverRec(fileMenux1, openy1, fileMenux2, openy2, x, y))
//						{
//							setTrue(open);
//							setcolor(GREEN);
//							outtextxy(100, 600, "Chon open");
//						}
//						else if(hoverRec(fileMenux1, savey1, fileMenux2, savey2, x, y))
//						{
//							setTrue(save);
//							setcolor(GREEN);
//							outtextxy(100, 600, "Chon save");
//						}
//					}
//					clearmouseclick(WM_LBUTTONDOWN);
//				}
//			}
//		}
//		else
//		{
//			createFile();
//		}
//		if(!Hover(filex1,filey1,filex2,filey2)&&!Hover(fileMenux1,newy1,fileMenux2,savey2+2)&&fileHovered==1){
//			deleteFileMenu();
//			fileHovered=0;
//		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//		if(hoverRec(95, 0, 145, 47, mousex(), mousey()) || algoHovered==1)
//		{
//			algoHighlight();
////			algoHovered=1;
////			createAlgoMenu(algo);
//			outtextxy(100, 500, "Chon");
//		}
//		else
//		{
//			createAlgo();
//		}
////		if(!Hover(algox1, algoy1, algox2, algoy2)&&!Hover(algoMenux1,drawy1-10,algoMenux2,topoSorty2+2)&&algoHovered==1){
////			deleteAlgoMenu();
////			algoHovered=0;
////			MaTranTrongSo();
////		}		
//		
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if(Hover(Toolx1,Tooly1,Toolx2,Tooly2)||ToolHovered==1)
//	{
//		ToolHighlight();
//		createToolMenu(Tool);
//		ToolHovered=1;
//		for(int i=0;i<5;i++)
//		{
//			if(Tool[i].hover())
//			{
//				Tool[i].highlight();
//					
//				if(ismouseclick(WM_LBUTTONDOWN))
//				{
//					getmouseclick(WM_LBUTTONDOWN, x, y);
//					if(hoverRec(fileMenux1, drawy1, fileMenux2, drawy2, x, y) && New == false)
//					{
//						setcolor(GREEN);
//						outtextxy(100, 600, "Ban Phai Tao Moi");
//					}
//					else if(hoverRec(fileMenux1, drawy1, fileMenux2, drawy2, x, y) && New == true)
//					{
//						setTrue(draw);
//						setcolor(GREEN);
//						outtextxy(100, 600, "Chon DRAW");
//					}
//					else if(hoverRec(fileMenux1, renamey1, fileMenux2, renamey2, x, y))
//					{
//						setTrue(Rename);
//						setcolor(GREEN);
//						outtextxy(100, 600, "Chon RENAME");
//					}
//					else if(hoverRec(fileMenux1, movey1, fileMenux2, movey2, x, y))
//					{
//						setTrue(move);
//						setcolor(GREEN);
//						outtextxy(100, 600, "Chon Move");
//					}
//					else if(hoverRec(fileMenux1, deletey1, fileMenux2, deletey2, x, y))
//					{
//						setTrue(Delete);
//						setcolor(GREEN);
//						outtextxy(100, 600, "Chon Delete");
//					}
//					else if(hoverRec(fileMenux1, linky1, fileMenux2, linky2, x, y))
//					{
//						setTrue(link);
//						setcolor(GREEN);
//						outtextxy(100, 600, "Chon Link");
//					}
//				}
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//		}
//	}
//		else
//		{
//			createTool();
//		}
//		if(!Hover(Toolx1,Tooly1,Toolx2,Tooly2)&&!Hover(ToolMenux1,drawy1-10,ToolMenux2,topoSorty2+2)&&ToolHovered==1){
//			deleteToolMenu();
//			ToolHovered=0;
//			MaTranTrongSo();
//		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if(ToolHovered==0&&fileHovered==0&& algoHovered==0)
//	{
//		createFile();
//		createTool();
//		createAlgo();
//		VeMaTran();
//		//break;
//	}
//	}
//}

