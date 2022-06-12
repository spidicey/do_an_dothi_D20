#define NODE_MAX 10 
#define filex1 0
#define filey1 0
#define filex2 47
#define filey2 25
#define algox1 48
#define algoy1 0
#define algox2 92
#define algoy2 25
#define fileMenux1 0
#define fileMenux2 100
#define newy1 26
#define newy2 54
#define openy1 55
#define openy2 83
#define savey1 84
#define savey2 108
#define algoMenux1 47
#define algoMenux2 150
#define DFSy1 30
#define DFSy2 54
#define BFSy1 55
#define BFSy2 79
#define TPLTy1 80
#define TPLTy2 104
#define timDuongy1 105
#define timDuongy2 133
#define dinhTruy1 134
#define dinhTruy2 162
#define dinhThaty1 163
#define dinhThaty2 187
#define canhCauy1 188
#define canhCauy2 212
#define hamiltony1 213
#define hamiltony2 237
#define eulery1 238
#define eulery2 262
#define topoSorty1 263
#define topoSorty2 287
#include "ThuatToan.h"
#include "DocFile.h"
int chonMotNode(int a =-1)
{
	int hoveredNode=-1;
	while(1)
	{
		if(kbhit()){
			char temp= getch();
			if(temp!=27) continue; 
			else {
				return -1;
			}
		} 
		for(int i=0;i<=dt.stt_Node;i++)
		{
			if(i==a) continue;
			if(hover(dt.node[i])){
				if(hoveredNode!=i){
					highlight(dt.node[i]);
					if(hoveredNode!=-1)
					recreate(dt.node[hoveredNode]);
					hoveredNode=i;
				}
				if(ismouseclick(WM_LBUTTONDOWN))
				{
					clearmouseclick(WM_LBUTTONDOWN);
					recreate(dt.node[i]);
					return i;
				}
			}
			if(hoveredNode!=-1&&!hover(dt.node[hoveredNode])){
				recreate(dt.node[hoveredNode]);
				hoveredNode=-1;
			}
		}
	}
}

class button{
		public:
		int x1,y1,x2,y2,textpos;
		char *name;
		button(int X1,int Y1,int X2,int Y2,int textPos,char* Name){
			x1=X1;
			y1=Y1;
			x2=X2;
			y2=Y2;
			textpos=textPos;
			name=Name;
		}
		create(){
			setfillstyle(1,WHITE);
			bar(x1,y1-2,x2,y2+1);
			outtextxy(textpos,y1-1,name);
		}
		highlight(){
			setfillstyle(1,LIGHTBLUE);
			bar(x1+2,y1-2,x2-1,y2);
			setbkcolor(LIGHTBLUE);
			setcolor(BLACK);
			outtextxy(textpos,y1-1,name);
			setbkcolor(WHITE);
		}
		deleteButton(){
			setfillstyle(1,WHITE);
			bar(x1+2,y1+1,x2-1,y2);
		}
		hover(){
			if (mousex() > x1 && mousex() < x2 && mousey() > y1 && mousey() < y2){
	            return 1;
	        }
	        else{
	            return 0;
	        }
		}
};
void createMode(){
	setfillstyle(1,WHITE);
	bar(93,0,152,25);
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(3,0,2);
	outtextxy(97,1,"Mode");
	setcolor(LIGHTGRAY);
	line(0,25,9999,25);
	setcolor(0);
}
void modeHighlight(){
	setfillstyle(1,LIGHTCYAN);
	bar(92,0,151,25);
	setcolor(LIGHTBLUE);
	rectangle(92,0,151,25);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	settextstyle(3,0,2);
	outtextxy(97,1,"Mode");
	setcolor(BLUE);
	line(92,25,151,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
}
void createModeMenu(button a[2]){
	setcolor(BLACK);
	rectangle(92,26,193,81);
	setcolor(LIGHTGRAY);
	rectangle(92,26,192,80);
	rectangle(92,26,194,82);
	setcolor(BLACK);
	line(92,26,92,82);
	for (int i =0;i<2;i++){
		a[i].create();
	}
}
void deleteModeMenu(){
	setfillstyle(1,WHITE);
	bar(92,26,195,59);
}
void createFile(){
	setfillstyle(1,WHITE);
	bar(0,0,47,25);
	setbkcolor(WHITE);
	setcolor(BLACK);
	settextstyle(3,0,2);
	outtextxy(7,1,"File");
	setcolor(LIGHTGRAY);
	line(0,25,getmaxx()+1,25);
	setcolor(0);
}
void fileHighlight(){
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
void createFileMenu(button a[3]){
	setcolor(BLACK);
	rectangle(-1,26,101,111);
	setcolor(LIGHTGRAY);
	rectangle(0,26,100,110);
	rectangle(0,26,102,112);
	setcolor(BLACK);
	for (int i =0;i<3;i++){
		a[i].create();
	}
}
void deleteFileMenu(){
	setfillstyle(1,WHITE);
	bar(0,26,103,114);
}
void createAlgo(){
	setfillstyle(1,15);
	bar(45,0,93,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(50,1,"Algo");
	setcolor(LIGHTGRAY);
	line(45,25,93,25);
	setcolor(BLACK);
}
void algoHighlight(){
	setfillstyle(1,LIGHTCYAN);
	bar(46,0,92,25);
	setcolor(LIGHTBLUE);
	rectangle(46,0,92,25);
	setcolor(BLACK);
	setbkcolor(LIGHTCYAN);
	settextstyle(3,0,1);
	outtextxy(50,1,"Algo");
	setcolor(BLUE);
	line(46,25,92,25);
	setcolor(BLACK);
	setbkcolor(WHITE);
}
void createAlgoMenu(button a[10]){
	setcolor(BLACK);
	rectangle(46,26,151,289);
	setcolor(LIGHTGRAY);
	rectangle(46,26,150,288);
	rectangle(46,26,152,290);
	setcolor(BLACK);
	line(46,26,46,290);
	for (int i =0;i<10;i++){
		a[i].create();
	}
}
void deleteAlgoMenu(){
	setfillstyle(1,WHITE);
	bar(45,26,153,291);
}
//Map
bool Hover(int x1,int y1, int x2,int y2){
if (mousex() > x1 && mousex() < x2 && mousey() > y1 && mousey() < y2)
        return 1;
	else
        return 0;
}
struct hoverMenu{
	int numer=-1;
	int buttonType=-1;
}hv;
void menuInteraction(button file[3],button algo[10],button mode[2],bool &fileHovered,bool &algoHovered, bool &modeHovered){
	while(1)
	{
		if(Hover(filex1,filey1,filex2,filey2)||fileHovered==1){
			fileHighlight();
			createFileMenu(file);
			fileHovered=1;
		for(int i=0;i<3;i++){
			if(file[i].hover()&&(hv.buttonType==-1||hv.buttonType==1)&&(hv.numer==-1||hv.numer==i))
			{
				file[i].highlight();
				hv.numer=i;
				hv.buttonType=1;
				if(ismouseclick(WM_LBUTTONDOWN))
				{
					int x = 0, y = 0;
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(hoverRec(fileMenux1, newy1, fileMenux2, newy2, x, y))
					{
						if(dt.stt_Node >= 0)
						{
							bool kt = true;
							clearThongBao();
							ThongBaoFile();
							outtextxy(170, 560, "Nhap Ten File");
							char fileName[20];
							NhapTenFile(fileName, kt);
							strcat(fileName, ".txt");
							clearThongBao();
							char name[27] = "File\\";
							strcat(name, fileName);
							if(kt == true)
								GhiFile(name);
						}
						chonNew();
						CapNhatNode();
						VeMaTran();
						clearMainScreen();
					}
///////////////////////////////////////OpenFile//////////////////////////////////////////////
					if(hoverRec(fileMenux1, openy1, fileMenux2, openy2, x, y))
					{
					bool kt = true;
						setcolor(GREEN);
						ThongBaoFile();
						outtextxy(170, 560, "Nhap Ten File");
						char fileName[20];
						for(int i = 0; i<=20; i++)
							fileName[i] = '\0';
							
						NhapTenFile(fileName, kt);					
						strcat(fileName, ".txt");
						clearThongBao();
						char name[27] = "File\\";
						strcat(name, fileName);
					
						if(kt == true)
						{
							dt.stt_Node = -1;
							clearMainScreen();	
											
							ifstream ifs;
							ifs.open(name, ios :: in);	
							
							if(!ifs)
							{
								outtextxy(100, 600, "Khong Co File: ");
								delay(1000);
								clearThongBao();
							}	
							else
							{
								DocFile(ifs);
								CapNhatNode();
								VeMaTran();
								VeCung();
							}
							ifs.close();
						}
					}
//////////////////////////////////////SaveFile///////////////////////////////////////////////////////////					
					if(hoverRec(fileMenux1, savey1, fileMenux2, savey2, x, y))
					{
							bool kt = true;
							ThongBaoFile();
							outtextxy(170, 560, "Nhap Ten File");
							char fileName[20];
							
							NhapTenFile(fileName, kt);
							
							strcat(fileName, ".txt");
							clearThongBao();
							char name[27] = "File\\";
							strcat(name, fileName);
							
							if(kt == true)
								GhiFile(name);

						}
					}
					clearmouseclick(WM_LBUTTONDOWN);
				}
			}	
		}
		if(!Hover(filex1,filey1,filex2,filey2)&&!Hover(fileMenux1,newy1,fileMenux2,savey2+2)&&fileHovered==1){
			createFile();
			deleteFileMenu();
			ManHinh_HuongDan();
			fileHovered=0;
		}
		if(hv.buttonType!=-1&&hv.numer!=-1){
		switch(hv.buttonType){
		case 1:{
			if(!file[hv.numer].hover()){
				file[hv.numer].create();
				hv.numer=-1;
				hv.buttonType=-1;
			}
			break;
		}
		case 2:{
			if(!algo[hv.numer].hover()){
				algo[hv.numer].create();
				hv.numer=-1;
				hv.buttonType=-1;
			}
			break;
		}
		case 3:{
			if(!mode[hv.numer].hover()){
				mode[hv.numer].create();
				hv.numer=-1;
				hv.buttonType=-1;
			}
			break;
		}
	}
	}
	if(Hover(algox1,algoy1,algox2,algoy2)||algoHovered==1){
			algoHighlight();
			createAlgoMenu(algo);
			algoHovered=1;
		for(int i=0;i<10;i++){
			if(algo[i].hover()&&(hv.buttonType==-1||hv.buttonType==2)&&(hv.numer==-1||hv.numer==i)){
				algo[i].highlight();
				hv.buttonType=2;
				hv.numer=i;
				if(ismouseclick(WM_LBUTTONDOWN)){
					int x = 0, y = 0;
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(dt.stt_Node==-1){
						outtextxy(100, 555, "Chua Co Do Thi");
						delay(1000);
						clearThongBao();
						continue;
					} 
					else if(hoverRec(47, 30, 150, 54, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						outtextxy(100, 600, "Chon Dinh Bat Dau");
						outtextxy(100, 625, "Nhan esc de thoat chon.");
						int temp=chonMotNode();
						if(temp == -1){
							clearThongBao();
							continue;
						}
						else
						{
							clearThongBao();
							outtextxy(100, 555, "DFS");
							DFS(temp);
						}
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 55, 150, 79, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						outtextxy(100, 600, "Chon Dinh Bat Dau");
						outtextxy(100, 625, "Nhan esc de thoat chon.");
						int temp=chonMotNode();
						if(temp == -1){
							clearThongBao();
							continue;
						}
						else
						{
							clearThongBao();
							outtextxy(100, 555, "BFS");
							bfs(temp);
						}
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 80, 150, 104, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						clearThongBao();
						TPLTVoHuong();
						int count=TPLT_manh();
						char a[10];
						itoa(count, a, 10);
						count=0;
						outtextxy(getmaxx()/2+30, 555, "Do Thi Co Huong");
						outtextxy(getmaxx()/2+200, 555, "TPLT:");
						outtextxy(getmaxx()/2+260, 555, a);
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 105, 150, 133, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						clearThongBao();
						outtextxy(100, 555, "Chon Dinh Bat Dau");
						outtextxy(100, 580, "Nhan esc de thoat chon.");
						int src=chonMotNode();
						clearThongBao();
						if(src == -1){
							continue;
						}
						highlight(dt.node[src]);
						outtextxy(100, 555, "Chon Dinh Ket Thuc");
						outtextxy(100, 580, "Nhan esc de thoat chon.");
						int des=chonMotNode(src);
						recreate(dt.node[src]);
						clearThongBao();
						if(des == -1){
							continue;
						}
						outtextxy(100, 555, "Tim Duong Di");
						Dijkstra(src,des);
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 134, 150, 162, x, y))
					{
						clearThongBao();
						outtextxy(100, 555, "Dinh Tru");
						DinhTru();
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 163, 150, 187, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						clearThongBao();
						outtextxy(100, 555, "Chon Dinh Bat Dau");
						outtextxy(100, 580, "Nhan esc de thoat chon.");
						int src=chonMotNode();
						clearThongBao();
						if(src == -1){
							continue;
						}
						highlight(dt.node[src]);
						outtextxy(100, 555, "Chon Dinh Ket Thuc");
						outtextxy(100, 580, "Nhan esc de thoat chon.");
						int des=chonMotNode(src);
						recreate(dt.node[src]);
						clearThongBao();
						if(des == -1){
							continue;
						}
						outtextxy(10, 555, "Dinh That Giua:");
						outtextxy(150, 555, dt.node[src].name);
						outtextxy(180, 555, ":");
						outtextxy(195, 555, dt.node[des].name);
						outtextxy(225, 555, "la");
						DinhThat(src, des);
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 188, 150, 212, x, y))
					{
						clearThongBao();
						CanhCau();
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 213, 150, 237, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						outtextxy(100, 600, "Chon Dinh Bat Dau");
						outtextxy(100, 625, "Nhan esc de thoat chon.");
						int temp=chonMotNode();
						if(temp == -1)
						{
							clearThongBao();
							continue;
						}
						else
						{
							clearThongBao();
							outtextxy(10, 555, "Hamilton");
							hamilton_solution(temp);
						}
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 238, 150, 262, x, y))
					{
						deleteAlgoMenu();
						ManHinh_HuongDan();
						algoHovered=0;
						MaTranTrongSo();
						VeMaTran();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						outtextxy(100, 600, "Chon Dinh Bat Dau");
						outtextxy(100, 625, "Nhan esc de thoat chon.");
						int temp=chonMotNode();
						if(temp == -1)
						{
							clearThongBao();
							continue;
						}
						else
						{
							clearThongBao();
							outtextxy(100, 555, "Euler");
							Euler(temp);
						}
						anyButtonToContinue();
						clearThongBao();
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++) 
							recreate(dt.node[i]);
						hv.numer=-1;
						hv.buttonType=-1;
					}
					else if(hoverRec(47, 263, 150, 287, x, y))
					{	
						Stack CT[dt.stt_Node+1];
						int color[dt.stt_Node+1];
						for(int i=0; i<=dt.stt_Node; ++i)	
							color[i] = 0;
						
						if(ChuTrinh(color, CT))
						{
							settextstyle(3, 0, 1);
							outtextxy(100, 555, "TopoSort");
							outtextxy(10, 580, "Ton Tai Chu Trinh");
							anyButtonToContinue();
							clearThongBao;
							return;
						}
						
						clearThongBao();
						
						for(int i = 0; i<= dt.stt_Node; i++)
						{
							resetchar(dt.DSDK[i].tenMonHoc);
							resetchar(dt.DSMDH[i].name);
							dt.DSVTMDH[i] = false;
						}
						
						Stack dstq[dt.stt_Node+1];
						Toposort(dstq);
						int kc = 0;
						int kctq = 0;
						bool dktc = true;
						
						settextstyle(3, 0, 1);
						outtextxy(10, 555, "Chon Mon Da Hoc");
						outtextxy(100,getmaxy()-25,"Nhan esc de thoat chon");
						int hoveredNode=-1;
						while(true)
						{
							if(kbhit()){
								char pres = getch();
								if(pres !=27) continue; 
								else {
									break;
								}
							} 
							for(int i=0;i<=dt.stt_Node;i++)
							{
								if(hover(dt.node[i]))
								{
									if(hoveredNode!=i)
									{
										highlight(dt.node[i]);
										if(hoveredNode!=-1)
										recreate(dt.node[hoveredNode]);
										hoveredNode=i;
									}
									
									if(ismouseclick(WM_LBUTTONDOWN)) // click chon node highlight
									{
										clearmouseclick(WM_LBUTTONDOWN);
										recreate(dt.node[i]);
										if(dt.DSVTMDH[i] == true) // Kiem Tra Xem Mon Do Duoc Dang Ky Chua
										{
											clearThongBao();
											outtextxy(10, 580, "Mon nay da hoc");
											anyButtonToContinue();
											clearThongBao();
											kc = 0;
											for(int i = 0; i< dt.soMonDahoc; i++)
											{					
												outtextxy(10 + 70*kc, 580, dt.DSMDH[i].name);
												kc++;												
											}
											outtextxy(10, 555, "Chon Mon Da Hoc");
											outtextxy(100,getmaxy()-25,"Nhan esc de thoat chon");
										}
										else // Neu Chua Hoc Kiem Tra Mon Tien Quyet
										{					
											sNode *cur = dstq[i].top;
											while(cur != NULL)
											{
												int vt = cur->data;
												
												if(dt.DSVTMDH[vt] == false)
												{
													if(kctq == 0)
														clearThongBao();
													outtextxy(10, 555, "Khong the da hoc mon nay vi chua hoan thanh mon tien quyet");
													outtextxy(10 +70*kctq, 580, dt.node[vt].name);
													kctq++;
													dktc = false;	
												}
												cur = cur->next;
											}// While Kiem Tra Mon Da Hoc
											
											
											if(dktc == true)
											{
												strcpy(dt.DSMDH[dt.soMonDahoc++].name, dt.node[i].name);
												outtextxy(10 + 70*kc, 580, dt.DSMDH[dt.soMonDahoc-1].name);
												dt.DSVTMDH[i] = true;
												kc++;
											}
											else
											{
												anyButtonToContinue();
												kctq = 0;
												clearThongBao();
												outtextxy(10, 555, "Chon Mon Da Hoc");
												outtextxy(100,getmaxy()-25,"Nhan esc de thoat chon");
												kc = 0;
												for(int i = 0; i< dt.soMonDahoc; i++)
												{
													outtextxy(10 + 70*kc, 580, dt.DSMDH[i].name);
													kc++;													
												}
											}
											dktc = true;
										}
									}//if click tron node
									
								}
							}
							if(!hover(dt.node[hoveredNode])&&hoveredNode!=-1){
								recreate(dt.node[hoveredNode]);
								hoveredNode=-1;
							}
						}
						outtextxy(555, 555, "Chon Mon Dang Ky");
						kc = 0;
						while(true)
						{
							if(kbhit()){
								char pres = getch();
								if(pres !=27) continue; 
								else {
									break;
								}
							} 
							for(int i=0;i<=dt.stt_Node;i++)
							{
								if(hover(dt.node[i])){
									if(hoveredNode!=i){
										highlight(dt.node[i]);
										if(hoveredNode!=-1)
										recreate(dt.node[hoveredNode]);
										hoveredNode=i;
									}
									if(ismouseclick(WM_LBUTTONDOWN))
									{
										clearmouseclick(WM_LBUTTONDOWN);
										recreate(dt.node[i]);
										if(strlen(dt.DSDK[i].tenMonHoc) != 0)
										{
											bar(555, 555, 1250, 650);
											outtextxy(555, 610, "Mon nay da chon");
											delay(1000);
											bar(555, 555, 1250, 650);
											kc = 0;
											outtextxy(555, 555, "Chon Mon Dang Ky");
											for(int i = 0; i<= dt.stt_Node; i++)
											{
												if(strlen(dt.DSDK[i].tenMonHoc) != 0)
												{
													outtextxy(555 + 70*kc, 580, dt.node[i].name);
													kc++;
												}
											}
										}
										else
										{
											outtextxy(555, 555, "Chon Mon Dang Ky");
											if(strlen(dt.node[i].tenMonHoc) == 0)
												strcpy(dt.DSDK[i].tenMonHoc, dt.node[i].name);
											else
												strcpy(dt.DSDK[i].tenMonHoc, dt.node[i].tenMonHoc);
											outtextxy(555 + 70*kc, 580, dt.node[i].name);
											kc++;
										}
									}
								}
							}
							if(!hover(dt.node[hoveredNode])&&hoveredNode!=-1){
								recreate(dt.node[hoveredNode]);
								hoveredNode=-1;
							}
						}

						int smIn = 0; // Nhan Biet Mon In Dau Va Mon Dang Ky Khong Thanh Cong
						int kcktc = 65;
						int kctc = 65;

						int daIn=0;
						string ketQuaThanhCong="";
						string ketQuaKhongThanhCong="";
						for(int i = 0; i<= dt.stt_Node; i++)
						{
							smIn = 0;
							if(strlen(dt.DSDK[i].tenMonHoc) != 0)
							{
								while(dstq[i].empty()==false)
								{
									int vt; dstq[i].pop(vt);
									if(dt.DSVTMDH[vt] == false)
									{
										if(daIn == 0||daIn==2){
											ketQuaKhongThanhCong+= "Khong Thanh Cong:\n";
											daIn ++;
										}
										if(smIn == 0)	// Nhan Biet Mon Dau In					
										{
											if(dt.node[i].tenMonHoc[0]!=NULL){
												ketQuaKhongThanhCong=ketQuaKhongThanhCong+"  - "+dt.node[i].tenMonHoc+". Ly do:";
												ketQuaKhongThanhCong+= "\n";
											}
											else{
												ketQuaKhongThanhCong=ketQuaKhongThanhCong+"  - "+dt.node[i].name+". Ly do:";
												ketQuaKhongThanhCong+= "\n";
											}
										}
										ketQuaKhongThanhCong += "    +Chua Hoc: ";
										if(dt.node[vt].tenMonHoc[0]!=NULL){
											ketQuaKhongThanhCong=ketQuaKhongThanhCong+"  - "+dt.node[vt].tenMonHoc;
											ketQuaKhongThanhCong+= "\n";
										}
										else{
											ketQuaKhongThanhCong=ketQuaKhongThanhCong+"  - "+dt.node[vt].name;
											ketQuaKhongThanhCong+= "\n";
										}
										smIn++;
									}
								}
								if(smIn == 0)
								{
									if(daIn == 1||daIn==0){
										ketQuaThanhCong +="Thanh Cong:\n";
										daIn+=2;
									}
									if(dt.node[i].tenMonHoc[0]!=NULL){
										ketQuaThanhCong=ketQuaThanhCong+"  - "+dt.node[i].tenMonHoc;
										ketQuaThanhCong+= "\n";
									}
									else{
										ketQuaThanhCong=ketQuaThanhCong+"  - "+dt.node[i].name;
										ketQuaThanhCong+= "\n";
									}
								}
							}
						}
						ketQuaThanhCong+=ketQuaKhongThanhCong;
						AllocConsole();
                        MessageBox(FindWindowA(NULL, "Window BGI"), &ketQuaThanhCong[0], "Ket qua", MB_OK);

						hv.numer=-1;
						hv.buttonType=-1;
					}
					clearmouseclick(WM_LBUTTONDOWN);
					clearThongBao();
				}
			}
		}
	}
	if(!Hover(algox1,algoy1,algox2,algoy2)&&!Hover(algoMenux1,DFSy1-10,algoMenux2,topoSorty2+2)&&algoHovered==1){
		createAlgo();
		deleteAlgoMenu();
		ManHinh_HuongDan();
		algoHovered=0;
		MaTranTrongSo();
		VeMaTran();
	}
	if(Hover(93,0,140,25)||modeHovered==1){
			modeHighlight();
			createModeMenu(mode);
			modeHovered=1;
		for(int i=0;i<2;i++){
			if(mode[i].hover()&&(hv.buttonType==-1||hv.buttonType==3)&&(hv.numer==-1||hv.numer==i)){
				mode[i].highlight();
				hv.buttonType=3;
				hv.numer=i;
				if(ismouseclick(WM_LBUTTONDOWN)&&i==0){
					clearMainScreen();
					clearThongBao();
					modeMon=0;
					outtextxy(10,555,"Da chuyen sang che do dinh");
					VeCung();
					for(int i=0;i<=dt.stt_Node;i++){
						recreate(dt.node[i]);
					}
					delay(1000);
					clearThongBao();
					clearmouseclick(WM_LBUTTONDOWN);
				}
				else if(ismouseclick(WM_LBUTTONDOWN)){
					clearMainScreen();
					clearThongBao();
					modeMon=1;
					outtextxy(10,555,"Da chuyen sang che do mon hoc");
					VeCung();
					for(int i=0;i<=dt.stt_Node;i++){
						recreate(dt.node[i]);
					}
					delay(1000);
					clearThongBao();
					clearmouseclick(WM_LBUTTONDOWN);
				}
			}
		}
	}
	if(!Hover(93,0,140,25)&&!Hover(93,26,193,81)&&modeHovered==1){
		deleteModeMenu();
		createMode();
		ManHinh_HuongDan();
		modeHovered=0;
	}
	if(algoHovered==0&&fileHovered==0&&modeHovered==0){
		createFile();
		createAlgo();
		createMode();
		ManHinh_HuongDan();
		VeMaTran();
		break;
	}
	delay(20);
}
}
