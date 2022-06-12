#include<fstream>
using namespace std;

void NhapTenFile(char fileName[20], bool &kt)
{
	for(int i = 0; i<=20; i++)
		fileName[i] = '\0';
		
	char pres;
	int vt = 0;
							
	while(kbhit())
	{
		char b= getch();
	}	
	while(true)
	{
		if(!kbhit())
		{
			int x = 0;
			int y = 0;
			if(ismouseclick(WM_LBUTTONDOWN)) // Kiem Tra Lien Tuc
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if(hoverRec(290,615, 350, 645, x, y))
				{
					clearThongBao();
					clearmouseclick(WM_LBUTTONDOWN);
					kt = false;
					return;
				}
				
			}	
		}
		if(kbhit())
		{
			pres = getch();
			if(pres == 13 && fileName[0] == '\0')
			{	
				clearThongBao();
				outtextxy(100, 555, "Chua Nhap Ten File");
				delay(1000);
				clearThongBao();
				ThongBaoFile();
				outtextxy(170, 560, "Nhap Ten File");
				continue;								
			}
			else if(pres == 13 && fileName[0]!='\0')
			{
				kt = true;
				break;
			}
			else if(pres== 8)
			{
				if(vt>=1)
				{
					fileName[--vt] = '\0';
				}
			}
			else
			{
				if(vt < 20)
				{
					if(pres == ' ') // Bo Qua Nhap Khoang Trang
						continue;
					if( 'A' <=pres && pres <= 'Z')
						pres += 32;
					fileName[vt++] = pres;
				}
				else
				{
					while(kbhit())
					{
						char temp = getch();
					}
				}
			}
			clearThongBao();
			outtextxy(170, 560, "Nhap Ten File");
			ThongBaoFile();
			outtextxy(95, 590, fileName);
		}
	}	
}

////////////////////////////////////////////////////////////////Ghi File//////////////////////////////////
void GhiFile(char name[27])
{
	ofstream ofs;
	ofs.open(name, ios::out);
							
	ofs<<dt.stt_Node<<"\n";
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		if(strlen(dt.node[i].tenMonHoc) != 0)
		{
			ofs<<dt.node[i].tenMonHoc<<", ";
			ofs<<dt.node[i].name<<" ";
		}
		else if(strlen(dt.node[i].tenMonHoc) == 0)
		{
			ofs<<"Khong co ten mon"<<", ";
			ofs<<dt.node[i].name<<" ";
		}
		ofs<<dt.node[i].x<<" "<<dt.node[i].y<<"\n";
	}
							
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			ofs<<dt.MT[i][j]<<" ";
		}
		ofs<<"\n";
	}
	ofs.close();
}

///////////////////////////////////////////////////Doc File/////////////////////////////////
void DocFile(ifstream &ifs)
{
	int so_node;
	ifs>>so_node;	
	for(int i = 0; i<=so_node; i++)
	{
		dt.stt_Node++;
		dt.them_node();
		dt.tang_MT();
									
		ifs.getline(dt.node[i].tenMonHoc, 100, ',');
		if(strcmp(dt.node[i].tenMonHoc, "Khong co ten mon")==0)
			resetchar(dt.node[i].tenMonHoc);
		ifs>>dt.node[i].name;
		ifs>>dt.node[i].x;
		ifs>>dt.node[i].y;
		ifs.ignore();
	}
	for(int i = 0; i<= so_node; i++)
	{
		for(int j = 0; j<= so_node; j++)
		{
			ifs>>dt.MT[i][j];
		}
	}
}
