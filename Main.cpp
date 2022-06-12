#include<iostream>
#include"GiaoDien.h"
#include"MaTran.h"
#include<windows.h>
#include<cmath> 
#include<string>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include "Menu.h"
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
using namespace std;
int main(){
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
    initwindow(1250, 700,"");
	floodfill(2,2,15);
    Node *arr[15]={};
    int arrPointer=0;	//dem so luong Node ton tai
    bool fileHovered=0, algoHovered=0, modeHovered=0;
	int chosenNode=-1, hoveredNode=-1;
	int hoveredLink[2]={-1,-1};
    button file[3]={
	button(fileMenux1,30,fileMenux2,newy2,7,"New"),
	button(fileMenux1,openy1,fileMenux2,openy2,7,"Open"),
	button(fileMenux1,savey1,fileMenux2,savey2+1,7,"Save")
	};
	button algo[10]={
		button(algoMenux1,DFSy1,algoMenux2,DFSy2,50,"DFS"),
		button(algoMenux1,BFSy1,algoMenux2,BFSy2,50,"BFS"),
		button(algoMenux1,TPLTy1,algoMenux2,TPLTy2,50,"TPLT"),
		button(algoMenux1,timDuongy1,algoMenux2,timDuongy2,50,"Tim duong"),
		button(algoMenux1,dinhTruy1,algoMenux2,dinhTruy2,50,"Dinh tru"),
		button(algoMenux1,dinhThaty1,algoMenux2,dinhThaty2,50,"Dinh that"),
		button(algoMenux1,canhCauy1,algoMenux2,canhCauy2,50,"Canh cau"),
		button(algoMenux1,hamiltony1,algoMenux2,hamiltony2,50,"Hamilton"),
		button(algoMenux1,eulery1,algoMenux2,eulery2,50,"Euler"),
		button(algoMenux1,topoSorty1,algoMenux2,topoSorty2,50,"Topo Sort"),
	};
	button mode[2]={
		button(93,30,192,54,95,"Dinh"),
		button(93,55,192,79,95,"Mon hoc"),
	};
	
////////////////////////////////Khai Bao///////////////////////////////////////////////////////

bool veNode = true;
bool xoaCung = false;
bool xoaNode = false;
int tam = -1;
int tam1 = -1;
int tam2 = -1;

int page=0;
dt.stt_Node = -1;

//////////////////////////////////////////////////////////////////////////////////////////////////	
	createFile();
	createAlgo();
	createMode();
	createInfoScreen();
	createMatrix();
	ManHinh_HuongDan();
	MaTranTrongSo();
	while(1)
	{	
		if((mousey()>0&& mousey()<25&& mousex()>0&&mousex()<140)||fileHovered||algoHovered||modeHovered)
		{		//Lam viec voi menu
			menuInteraction(file,algo,mode,fileHovered,algoHovered,modeHovered);
		}
		else if(mousey()>= 15&&mousey()<=580 && mousex()>=290 && mousex()<getmaxx()+1&&!xoaCung&&!xoaNode)
		{	//Lam viec voi Node trong khung chinh

			bool check40=0; // kiem tra gan nhau qua hay khong
			bool highlightLink=0; //kiem tra xem co cung nao dang duoc hover khong
			for(int i=0;i<=dt.stt_Node;i++) // chay tung node
			{		// check Node hover
				if(hover(dt.node[i])){
					//highlight Node
					if(hoveredNode!=i&&chosenNode!=i){
						highlight(dt.node[i]);
						if(hoveredNode!=-1)
							recreate(dt.node[hoveredNode]);
						hoveredNode=i;
					}
					// Nhan  dup chuot trai de di chuyen 	
					if(ismouseclick(WM_LBUTTONDBLCLK))
					{
						int timer=0; //Tinh thoi gian hien thi thong bao
						// Di chuyen chuot
						while(ismouseclick(WM_MOUSEMOVE))
						{
							int x=mousex();
							if(x<322) x=322;
							if(x>getmaxx()-20) x=getmaxx()-20;
							int y=mousey();
							if(y>529)y=529;
							else if( y<47) y=47;
							setactivepage(page);
							setvisualpage(1-page);
							timer++;
							if(timer==40){
								setactivepage(1-page);
								setvisualpage(page);
								bar(100,555,99999,585);
								setactivepage(page);
								setvisualpage(1-page);
								bar(100,555,99999,585);
								timer=0;
							}
							bar(0,0,getmaxx()+1,560);
							bar(0,580,getmaxx()+1,getmaxy()+1);
							deleteNode(dt.node[i]);
							dt.node[i].x=x;
							dt.node[i].y=y;
							recreate(dt.node[i]);
							VeCung();
							for(int k=0;k<=dt.stt_Node;k++) 
								recreate(dt.node[k]);
							delay(20);
							createFile();
							createAlgo();
							createMode();
							createInfoScreen();
							MaTranTrongSo();
							createMatrix();
							ManHinh_MaTran();
							ManHinh_HuongDan();
							VeMaTran();
							page=1-page;
							if(ismouseclick(WM_LBUTTONDOWN)) // Trong Khi Di Chuyen Neu Nhan Chuot Trai
							{
								clearmouseclick(WM_LBUTTONDOWN);
							}
							if(ismouseclick(WM_RBUTTONDOWN))
							{
								bool  temp=0; // temp de bat node trung
								for(int j=0;j<=dt.stt_Node;j++)  //Neu dang trung node thi khong cho thoat di chuyen
								{ 
									if(hover40(dt.node[j]) && j!=i) 
									{
										setactivepage(1-page);
										setvisualpage(page);
										bar(100,555,99999,585);
										outtextxy(125, 555, "Node qua gan node khac");
										setactivepage(page);
										bar(100,555,99999,585);
										outtextxy(125, 555, "Node qua gan node khac");
										clearmouseclick(WM_RBUTTONDOWN);
										timer=0;
										temp=1;
							    	}
								}
								for(int j=0;j<=dt.stt_Node;j++)  //Neu dang trung cung thi khong cho thoat di chuyen
								{
									if(j==i) continue;
									for(int k=0;k<=dt.stt_Node;k++){
										if(k==i) continue;
										if(dt.MT[j][k]!=0)
											{
												link temp1(dt.node[j],dt.node[k]);
												if(j>k&&dt.MT[k][j]!=0)
												{
													if(temp1.hoverReversedLink())
													{
														setactivepage(1-page);
														setvisualpage(page);
														bar(100,555,99999,585);
														outtextxy(125, 555, "Node qua gan cung");
														setactivepage(page);
														setvisualpage(1-page);
														bar(100,555,99999,585);
														outtextxy(125, 555, "Node qua gan cung");
														clearmouseclick(WM_RBUTTONDOWN);
														timer=0;
														temp=1;
													}
												}
												else if(temp1.hoverLink())
												{
													setactivepage(1-page);
													setvisualpage(page);
													bar(100,555,99999,585);
													outtextxy(125, 555, "Node qua gan cung");
													setactivepage(page);
													setvisualpage(1-page);
													bar(100,555,99999,585);
													outtextxy(125, 555, "Node qua gan cung");
													clearmouseclick(WM_RBUTTONDOWN);
													timer=0;
													temp=1;
												}
											}
										}
								}
								if(temp==0)
								{
									clearmouseclick(WM_RBUTTONDOWN);
									break;
								}
							}
						}
						setactivepage(1-page);
						bar(301,26,getmaxx()+1,550);
						setactivepage(page);
						bar(301,26,getmaxx()+1,550);
						VeCung();
						for(int i=0;i<=dt.stt_Node;i++){
							recreate(dt.node[i]);
						}
						setvisualpage(page);
						clearmouseclick(WM_LBUTTONDBLCLK);
						chosenNode=-1;
					}
/////////////////////////////////////Chon Node////////////////////////////////////////				
					if(ismouseclick(WM_LBUTTONDOWN))
					{		//neu Node duoc chon
						if(chosenNode!=-1&&chosenNode!=i&&dt.MT[i][chosenNode]>0&&dt.MT[chosenNode][i]==0){
							outtextxy(100, 555, "Nhap trong so. Bam Enter de xac nhan.");
							if(i>chosenNode){		
								link temp(dt.node[chosenNode],dt.node[i]);
								link temp1(dt.node[i],dt.node[chosenNode]);
								temp1.eraseLink(dt.MT[i][chosenNode]);
								temp1.recreateReversedLink(dt.MT[i][chosenNode]);
								dt.MT[chosenNode][i]=temp.createLink();
								if(dt.MT[chosenNode][i]==-1) 	//Neu nhan esc
								{
									temp.eraseLink(dt.MT[chosenNode][i]);
									temp1.eraseReversedLink(dt.MT[i][chosenNode]);
									temp1.recreateLink(dt.MT[i][chosenNode]);
									dt.MT[chosenNode][i]=0;
								}
								recreate(dt.node[chosenNode]);
								VeMaTran();
								clearThongBao();
								chosenNode=-1;
							}
							else {
								link temp(dt.node[chosenNode],dt.node[i]);
								dt.MT[chosenNode][i]=temp.reversedLink();
								if(dt.MT[chosenNode][i]==-1) 	//Neu nhan esc
								{
									temp.eraseReversedLink(dt.MT[chosenNode][i]);
									dt.MT[chosenNode][i]=0;
								}
								recreate(dt.node[chosenNode]);
								VeMaTran();
								clearThongBao();
								chosenNode=-1;
							}
						}
						else if(chosenNode!=-1&&chosenNode!=i&&dt.MT[chosenNode][i]==0){
							outtextxy(100, 555, "Nhap trong so. Bam Enter de xac nhan.");
							link temp(dt.node[chosenNode],dt.node[i]);
							dt.MT[chosenNode][i]=temp.createLink();
							if(dt.MT[chosenNode][i]==-1) 	//Neu nhan esc
								{
									temp.eraseLink(dt.MT[chosenNode][i]);
									dt.MT[chosenNode][i]=0;
								}
							VeMaTran();
							recreate(dt.node[chosenNode]);
							chosenNode=-1;
							clearThongBao();
						}
						else if(chosenNode!=-1&&chosenNode!=i&&dt.MT[chosenNode][i]!=0){ //Neu cung da ton tai
							outtextxy(100, 555, "Cung da ton tai");
							recreate(dt.node[chosenNode]);
							recreate(dt.node[i]);
							chosenNode=-1;
							delay(1000);
							clearThongBao();
						}
						else if(chosenNode==-1){
						highlight(dt.node[i]);
						hoveredNode=-1;
						chosenNode=i;
					}	
						clearmouseclick(WM_LBUTTONDOWN);
					}
					// Nhan chuot phai
					if(ismouseclick(WM_RBUTTONDOWN)&&chosenNode!=-1){		//neu Node duoc huy chon
						recreate(dt.node[i]);
						chosenNode=-1;
						clearmouseclick(WM_RBUTTONDOWN);
						continue;
					}
///////////////////////////Xoa Node Dang Highlight/////////////////////////////////			
					
					if(ismouseclick(WM_RBUTTONDOWN)){
						clearmouseclick(WM_RBUTTONDOWN);
						delay(300);
						if(ismouseclick(WM_RBUTTONDBLCLK)){
						outtextxy(100,555,"Hay nhap ten moi. Bam Enter de xac nhan.");
							{
							recreate(dt.node[i]);
							string temp=dt.node[i].name;
							rename(dt.node[i]);
							if(dt.node[i].name[0]=='-'){
								for(int j=0;j<=temp.length();j++){
									dt.node[i].name[j]=temp[j];
								}
								recreate(dt.node[i]);
							}
							clearmouseclick(WM_RBUTTONDBLCLK);
							clearmouseclick(WM_RBUTTONDOWN);
							clearThongBao();
							VeMaTran();
							continue; 
						}
					}		
						xoaNode = true;
						veNode = false;
						tam = i;
						outtextxy(125, 555, "Ban Muon Xoa Node");
						rectangle(190, 590, 235, 630);
						outtextxy(200, 600, "Co");
						rectangle(240, 590, 310, 630);
						outtextxy(250, 600, "Khong");
						clearmouseclick(WM_RBUTTONDOWN);
					}
				}
				if(hover40(dt.node[i])){
					check40=1;
				}
			}	

////////////////////Xoa Cung Lien Quan Den Node/////////////////////////////////////////////////////////////////////////////
			for(int i=0;i<=dt.stt_Node;i++)
			{
				for(int j=0;j<=dt.stt_Node;j++)
					if(dt.MT[i][j]!=0&&((hoveredLink[0]==-1&&hoveredLink[1]==-1)||(i==hoveredLink[0]&&j==hoveredLink[1])))
					{
						link temp(dt.node[i],dt.node[j]);
						if(i>j&&dt.MT[j][i]!=0)
						{
							if(temp.hoverReversedLink()&&hoveredNode==-1)
							{
								temp.highlightReversedLink(dt.MT[i][j]); // HighLight cung cong
								highlightLink=1; 
								hoveredLink[0]=i;
								hoveredLink[1]=j;
								if(ismouseclick(WM_RBUTTONDOWN)) // Xoa Cung Cong
								{
									clearmouseclick(WM_RBUTTONDOWN);
									delay(300);
									if(ismouseclick(WM_RBUTTONDBLCLK)) // Chinh Sua Trong So
									{
										outtextxy(100,555,"Hay nhap trong so moi. Bam Enter de xac nhan.");
										int store= dt.MT[i][j];
										dt.MT[i][j]=temp.renameReversedLink();
										if(dt.MT[i][j]<0){
											temp.recreateReversedLink(store);
											dt.MT[i][j]=store;
										}
										clearThongBao();
										clearmouseclick(WM_RBUTTONDBLCLK);
										clearmouseclick(WM_RBUTTONDOWN);
										continue;
									}
									xoaCung = true;
									veNode = false;
									tam1 = i;
									tam2 = j;
									outtextxy(100, 555, "Ban Muon Xoa Cung Cong");
									rectangle(190, 590, 235, 630);
									outtextxy(200, 600, "Co");
									rectangle(240, 590, 310, 630);
									outtextxy(250, 600, "Khong");
									clearmouseclick(WM_RBUTTONDOWN);
								}
							}
						}
						else{
							if(temp.hoverLink()&&hoveredNode==-1){
								temp.highlightLink(dt.MT[i][j]);
								hoveredLink[0]=i;
								hoveredLink[1]=j;
								highlightLink=1;
								if(ismouseclick(WM_RBUTTONDOWN))
								{
									clearmouseclick(WM_RBUTTONDOWN);
									delay(300);
									if(ismouseclick(WM_RBUTTONDBLCLK)){
									outtextxy(100,555,"Hay nhap trong so moi. Bam Enter de xac nhan.");
									clearmouseclick(WM_RBUTTONDBLCLK);
									clearmouseclick(WM_RBUTTONDOWN);	 
									int store= dt.MT[i][j];
									dt.MT[i][j]=temp.renameLink();
									if(dt.MT[i][j]<0)
									{
										temp.recreateLink(store);
										dt.MT[i][j]=store;
									}
									clearThongBao();
									continue;
								}
									if(dt.MT[j][i]!=0) // Xoa Cung Thang
									{
										xoaCung = true;
										veNode = false;
										tam1 = i;
										tam2 = j;
										outtextxy(100, 555, "Ban Muon Xoa Cung Khong?");
										rectangle(190, 590, 235, 630);
										outtextxy(200, 600, "Co");
										rectangle(240, 590, 310, 630);
										outtextxy(250, 600, "Khong");
										clearmouseclick(WM_RBUTTONDOWN);
									}
									else // Truong Hop Chi Co Mot Cung
									{
										xoaCung = true;
										veNode = false;
										tam1 = i;
										tam2 = j;
										outtextxy(100, 555, "Ban Muon Xoa Cung Cong");
										rectangle(190, 590, 235, 630);
										outtextxy(200, 600, "Co");
										rectangle(240, 590, 310, 630);
										outtextxy(250, 600, "Khong");
										clearmouseclick(WM_RBUTTONDOWN); // Neu Khong co trong so
									}
								}
							}
						}
				}
			}
			if(hoveredLink[0]!=-1&&hoveredLink[1]!=-1){
				link temp(dt.node[hoveredLink[0]],dt.node[hoveredLink[1]]);
				if(isCungCong(hoveredLink[0],hoveredLink[1])){
					if(!temp.hoverReversedLink()){
						temp.recreateReversedLink(dt.MT[hoveredLink[0]][hoveredLink[1]]);
						hoveredLink[0]=-1;
						hoveredLink[1]=-1;
					}
				}
				else{
					if(!temp.hoverLink()){
						temp.recreateLink(dt.MT[hoveredLink[0]][hoveredLink[1]]);
						hoveredLink[0]=-1;
						hoveredLink[1]=-1;
					}
				}
			}
//////////////////////Thao Tac Nhan Chuot Tao Node//////////////////////////////
			if(ismouseclick(WM_LBUTTONDOWN)&&chosenNode==-1&& veNode == true)
			{		//tao Node khi khong co nut dang hover
				if(mousex()<300||mousey()<25||mousey()>550){}
				else if(dt.stt_Node>8){
					outtextxy(100, 555, "So node khong duoc vuot qua 10!");
					delay(1000);
					clearThongBao();
				}
				else if(mousex()<320||mousey()<45||mousey()>530||mousex()>getmaxx()-20){
					outtextxy(100, 555, "Tao node qua gan vien man hinh");
					delay(1000);
					clearThongBao();
				}
				else if(highlightLink==1){
					outtextxy(100, 555, "Tao node qua gan cung");
					delay(1000);
					clearThongBao();
				}
				else if(check40==1)
				{
					outtextxy(100, 555, "Tao node qua gan node khac");
					delay(1000);
					clearThongBao();
				}
				else if(highlightLink==0&&check40==0)
				{
					outtextxy(100, 555, "Nhap ten dinh. Bam Enter de xac nhan.");
					Node Node1;
					create(Node1); // co learmouseclick()
					if(modeMon==0){
						if(Node1.name[0]=='-'){
							deleteNode(Node1);
							clearThongBao();
							continue;
						}
						if(Node1.x >= 321 && Node1.x <= getmaxx()-20 && Node1.y>= 46 && Node1.y<= 540)
						{
							dt.stt_Node++;
							dt.them_node();
							dt.tang_MT();
							dt.node[dt.stt_Node].x=Node1.x;
							dt.node[dt.stt_Node].y=Node1.y;
							dt.node[dt.stt_Node].name[0]=Node1.name[0];
							dt.node[dt.stt_Node].name[1]=Node1.name[1];
							dt.node[dt.stt_Node].name[2]='\0';
							//them vao danh sach tat ca Node
							recreate(dt.node[dt.stt_Node]);
							VeMaTran();
							clearThongBao();
						}
					}
					else {
						if(Node1.name[0]=='!'){
							deleteNode(Node1);
							clearThongBao();
							continue;
						}
						if(Node1.x >= 321 && Node1.x <= getmaxx()-20 && Node1.y>= 46 && Node1.y<= 540)
						{
							dt.stt_Node++;
							dt.them_node();
							dt.tang_MT();
							dt.node[dt.stt_Node].x=Node1.x;
							dt.node[dt.stt_Node].y=Node1.y;
							int i=0;
							for(;i<4;i++){
								if(Node1.name[i]!='\0'){
									dt.node[dt.stt_Node].name[i]=Node1.name[i];
								}
								else{
									 dt.node[dt.stt_Node].name[i]='\0';
									 break;
								}
							}
							dt.node[dt.stt_Node].name[4]='\0';
							i=0;
							while(Node1.tenMonHoc[i]!='\0'){
								dt.node[dt.stt_Node].tenMonHoc[i]=Node1.tenMonHoc[i];
								i++;
							}
							dt.node[dt.stt_Node].tenMonHoc[i]='\0';
							//them vao danh sach tat ca Node
							recreate(dt.node[dt.stt_Node]);
							VeMaTran();
							clearThongBao();
						}
					}
				}
				clearmouseclick(WM_LBUTTONDOWN);
			}
			if(hoveredNode!=-1&&!hover(dt.node[hoveredNode])){
				recreate(dt.node[hoveredNode]);
				hoveredNode=-1;
			}

		}
///////////////////////////////////////////Thong Bao///////////////////////////////////////////////////////////
else if(mousex()>1 && mousex() < 1250 &&mousey()> 500 &&mousey()<650)
		{
			while(xoaCung) 
			{	
				if(ismouseclick(WM_LBUTTONDOWN))
				{
					int x = 0, y = 0;
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(hoverRec(190, 590, 235, 630, x, y))
					{
						hoveredLink[0]=-1;
						hoveredLink[1]=-1; 
						clearMainScreen();
						dt.MT[tam1][tam2]=0;
						CapNhatNode();
						VeCung();
						VeMaTran();
						clearThongBao();
						xoaCung = false;
						veNode = true;
						clearmouseclick(WM_LBUTTONDOWN);
					}
					else
					{
						link temp(dt.node[tam1],dt.node[tam2]);
						if(isCungCong(tam1,tam2)) temp.recreateReversedLink(dt.MT[tam1][tam2]);
						else temp.recreateLink(dt.MT[tam1][tam2]);
						xoaCung = false;
						veNode = true;
						clearThongBao();
						clearmouseclick(WM_LBUTTONDOWN);
					}	
				}
				delay(20);
			}
/////////////////////////////////////Xoa Node//////////////////////////////////////////////////////					
			while(xoaNode == true)
			{
				if(ismouseclick(WM_LBUTTONDOWN))
				{
					int x = 0, y = 0;
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if(hoverRec(190, 590, 235, 630, x, y))
					{
						for(int j=0;j<=dt.stt_Node;j++){
							link temp(dt.node[tam],dt.node[j]);
							link temp1(dt.node[j],dt.node[tam]);
							if(tam>j){
								if(dt.MT[j][tam]>0&&dt.MT[tam][j]>0){
									temp.eraseReversedLink(dt.MT[tam][j]);
									temp1.eraseLink(dt.MT[j][tam]);
								}
								else if(dt.MT[j][tam]>0&&dt.MT[tam][j]==0){
									temp1.eraseLink(dt.MT[j][tam]);
								}
								else temp.eraseLink(dt.MT[tam][j]);
							}
							else
							{
								if(dt.MT[j][tam]>0&&dt.MT[tam][j]>0)
								{
									temp.eraseLink(dt.MT[tam][j]);
									temp1.eraseReversedLink(dt.MT[j][tam]);
								}
								else if(dt.MT[j][tam]>0&&dt.MT[tam][j]==0){
									temp1.eraseLink(dt.MT[j][tam]);
								}
								else temp.eraseLink(dt.MT[tam][j]);
							}
						}
						deleteNode(dt.node[tam]);
						dt.stt_Node--;
						dt.giam_node(tam);
						dt.Giam_MT(tam);
						VeMaTran();
						clearThongBao();
						xoaNode = false;
						veNode = true;
					}
					else if(hoverRec(240, 590, 310, 630, x, y))
					{
						recreate(dt.node[tam]);
						xoaNode = false;
						veNode = true;
						clearThongBao();
					}
				}
				clearmouseclick(WM_LBUTTONDOWN);
				delay(20);
			}			
		} //  Dieu Kien Bao Quat
		clearmouseclick(WM_LBUTTONDBLCLK);
		clearmouseclick(WM_RBUTTONDBLCLK);
		clearmouseclick(WM_RBUTTONDOWN);
		clearmouseclick(WM_LBUTTONDOWN);
		while(kbhit()){char temp = getch();
						 }
		delay(10);
	}
    closegraph();
}

