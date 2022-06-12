#include<cstring>
using namespace std;
bool modeMon= false;
string chuanHoa(string s)
{
	string temp=s;
	while(temp[0]==32) temp.erase(0,1);
	for(int i=0;i<temp.length();i++){
		if(temp[i]==temp[i-1]&&temp[i-1]==' '){
			temp.erase(i,1);
			i--;
		}
	}
	if(temp[temp.length()-1]==' ') temp.erase(temp.length()-1,1);
	return temp;
}
string vietHoa(string s){
	string temp=s;
	for(int i=0;i<temp.length();i++){
		if(temp[i]>=97&&temp[i]<=122){
			temp[i]-=32;
		}
	}
	return temp;
}
string KiTuDau(string s){
	string temp;
	temp.push_back(s[0]);
	for(int i=1;i<s.length()&&temp.length()<4;i++){
		if(s[i-1]==' '){
			temp.push_back(s[i]);
		}
	}
	return vietHoa(temp);
}
void updateCusor(int length, char s[])
{
	for(;length<10;length++) s[length]='\0';
}

string cusorMon(string &tenMon){
	outtextxy(100, getmaxy()-30, "Bam esc de thoat.");
	char temp;
	string a;
	while(kbhit()){
		char b= getch();
	}
	while(1){
		if(GetAsyncKeyState(0x01))
		{
			continue;
		} 
		temp=getch();
		if(int (temp)==27)			//Bam esc
		{
			clearThongBao();
			clearmouseclick(WM_LBUTTONDBLCLK);
			clearmouseclick(WM_RBUTTONDBLCLK);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDOWN);
			return "!" ;
		}
		if(int (temp)==13&&chuanHoa(a)[0]== '\0') //Enter string rong
		{
			outtextxy(100, 580, "Chua Nhap Ten Mon Hoc");
			delay(1000);
			bar(100,580,900,620);
			continue;
		}
		if(int (temp)==13&&a[0]!=NULL)		//Trung ten mon & enter de nhan
		{
			bool kt = false;
			for(int i = 0; i<= dt.stt_Node; i++)
			{
				if(vietHoa(dt.node[i].tenMonHoc)== vietHoa(chuanHoa(a)))
				{
					outtextxy(100, 580, "Mon Hoc Da Ton Tai");
					delay(1000);
					bar(100,580,900,605);
					kt = true;
					continue;
				}
			}
			if(kt == false){
				chuanHoa(a);
				break;
			}
		}
		if(int(temp)==8){	//Bam backspace
			if(!a.empty()){
				bar(10,605,9999,630);
				a.erase(a.length() - 1,1);
				outtextxy(100,605,&a[0]);
				continue;
			}
		}
		if((temp>=97&&temp<=122)||(temp>=65&&temp<=90)||(temp>=48&&temp<=57)||temp==32){
			if(a.length()>=100) {
				a.erase(100,1);
				bar(10,605,9999,630);
			}
			bar(10,605,9999,630);
			a.push_back(temp);
			outtextxy(100,605,&a[0]);
		}
	}
	if(tenMon[0]!='\0')
		tenMon.erase(0,tenMon.length()-1);
	for(int i=0;i<chuanHoa(a).length();i++){
		tenMon.push_back(chuanHoa(a)[i]);
	}
	return KiTuDau(chuanHoa(a));
}
string cusor(int x,int y,int maxLength, int mode) // mode = 1 khong duoc trung | mode = 0 co the trung
{
	outtextxy(100, 625, "Bam esc de thoat.");
	settextjustify(1, 1);
	settextstyle(1,0,0);
	setusercharsize(3,10,2,3);
	char a[maxLength+10]={};
	int length=-1;
	char temp='\0';
	while(kbhit()){
		char b= getch();
	}
	while(1){
		if(GetAsyncKeyState(0x01)){
			continue;
		}
		temp=getch();
		if(int (temp)==27)
		{
			clearThongBao();
			clearmouseclick(WM_LBUTTONDBLCLK);
			clearmouseclick(WM_RBUTTONDBLCLK);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDOWN);
			settextjustify(0,2);
			settextstyle(3,0,2);
			return "-1";
		}
		if(int (temp)==13&&a[0]== '\0')
		{
			settextjustify(0,2);
			settextstyle(3,0,2);
			outtextxy(100, 590, "Chua Nhap Gia Tri");
			settextjustify(1, 1);
			settextstyle(1,0,0);
			setusercharsize(3,10,2,3);
			delay(1000);
			bar(100,590,900,620);
			continue;
		}
		if(int (temp)==13&&a[0]!=NULL)
		{
			bool kt = false;
			for(int i = 0; i<= dt.stt_Node; i++)
			{
				if(strcmp(dt.node[i].name, a)==0 && mode == 1)
				{
					settextjustify(0,2);
					settextstyle(3,0,2);
					outtextxy(100, 590, "Node Da Ton Tai");
					delay(1000);
					settextjustify(1, 1);
					settextstyle(1,0,0);
					setusercharsize(3,10,2,3);
					bar(100,590,900,620);
					kt = true;
					continue;
				}
			}
			if(kt == false)
				break;
		}
		if(int(temp)==8){
			updateCusor(length,a);
			if(length==0){
				bar(x-1,y+4,x+12,y+20);
			}
			else if(length==1){
				bar(x-5,y+4,x+17,y+20);
				outtextxy(x+6,y+18,a);
			}
			length--;
			if (length<0){
				length =-1;
			}
			continue;
		}
		if(int (temp)>57||int (temp)<48||(int (temp)==48&&length==-1)){
			continue;
		}
		if (length==maxLength){
			a[length]=temp;
			outtextxy(x+6,y+18,a);
			continue;
		}
		if(length==-1){
			length++;
			a[length]=temp;
			outtextxy(x+6,y+18,a);
		}
		else {
			length++;
			a[length]=temp;
			outtextxy(x+6,y+18,a);
		}
}
	string temp1 = "";
	for(int i=0;i<=maxLength;i++){
		temp1+=a[i];
	}
	cin.clear();
	settextjustify(0,2);
	settextstyle(3,0,2);
	return temp1;
}
void createTriangle(int xEnd, int yEnd, int xStart, int yStart){
		int xa=xEnd;
		int ya=yEnd;
		int xb=xStart;
		int yb=yStart;
		double d=sqrt(pow(xa-xb,2)+pow(ya-yb,2))/20;
		int tdx = xa+(xb-xa)/d;
		int tdy = ya+(yb-ya)/d;
		int daux=(xb>xa)?1:-1;
		int dauy=(yb>ya)?1:-1;
		int vectorx=(xb>xa)?1:-1;
		int vectory=0;
		int vectorABx=xb-xa;
		int vectorABy=yb-ya;
		double angle= acos((vectorx*vectorABx+vectory*vectorABy)/(sqrt(pow(vectorx,2)+pow(vectory,2))*sqrt(pow(vectorABx,2)+pow(vectorABy,2))))*180/3.14;
		double realAngle=(angle - 26.6)*3.14/180;
		int deltaX= cos(realAngle)*10*sqrt(5);
		int deltaY= sin(realAngle)*10*sqrt(5);
		int x1= xa+ daux*deltaX;
		int y1= ya+ dauy*deltaY;
		int x2= 2*tdx-x1;
		int y2=2*tdy-y1;
		int arr[8]={xa,ya,x1,y1,x2,y2,xa,ya};
		fillpoly(4,arr);
}  
void create(Node &temp){
	int x = 0;
	int y = 0;
	getmouseclick(WM_LBUTTONDOWN, x, y);
	temp.x = x;
	temp.y = y;
  	if(x>= 321 && x<= getmaxx()-20 && y>= 46 && y<= 540)
  	{
  		for(int i=20;i<=22;i++) circle(x, y, i);
  		if(modeMon==0){
		  	string str=cusor(x-6,y-11,1, 1);
			for(int i=0;i<=str.length();i++){
				temp.name[i]=str[i];
			}
		}
		if(modeMon==1){
			string tenMon;
			string name=cusorMon(tenMon);
			for(int i=0;i<=name.length();i++){
				temp.name[i]=name[i];
			}
			for(int i=0;i<=tenMon.length();i++){
				temp.tenMonHoc[i]=tenMon[i];
			}
		}
	}
}
bool hover(Node temp){
   	if (sqrt(pow((mousex()-temp.x),2)+pow((mousey()-temp.y),2))<=20)
   		return true;
	else
	   	return false;
}	
bool hover40(Node temp){
   	if (sqrt(pow((mousex()-temp.x),2)+pow((mousey()-temp.y),2))<=50)
   		return true;
	else
	   	return false;
}	

void highlight(Node temp){
	setcolor(3);
	for(int i=0;i<=19;i++)
		 circle(temp.x,temp.y, i);
	setcolor(9);
	for(int i=19;i<=20;i++)
		 circle(temp.x,temp.y, i);
	setcolor(0);
	for(int i=20;i<=22;i++)
		 circle(temp.x,temp.y, i);
	setbkcolor(3);
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
	settextjustify(0, 2);
	settextstyle(3,0,2);
	setbkcolor(15);
}

void deleteNode(Node temp){
	setcolor(WHITE);
	for(int i=0;i<=23;i++){
		circle(temp.x,temp.y,i);
	}
	bar(temp.x-14,temp.y-10,temp.x+13,temp.y+11);
	setcolor(BLACK);
	settextjustify(0, 2);
	settextstyle(3,0,2);
}
void rename(Node &temp){
	setcolor(WHITE);
	bar(temp.x-14,temp.y-10,temp.x+14,temp.y+11);
	setcolor(BLACK);
  	for(int i=20;i<=22;i++) circle(temp.x, temp.y, i);
  	if(modeMon==0){
	  	string str=cusor(temp.x-6,temp.y-11,1, 1);
		for(int i=0;i<=str.length();i++){
			temp.name[i]=str[i];
		}
	}
	if(modeMon==1){
		string tenMon;
		string name=cusorMon(tenMon);
		if(name[0]=='!') return;
		for(int i=0;i<=name.length();i++){
			temp.name[i]=name[i];
		}
		for(int i=0;i<=tenMon.length();i++){
			temp.tenMonHoc[i]=tenMon[i];
		}
	}
}

void calculateReversedLink(double &rx, double &ry, double &r, int &startAngle, int &endAngle, int &xEnd, int &yEnd, int &textPosx, int &textPosy, Node temp1, Node temp2){
	double tdx=(temp1.x+temp2.x)/2;
	double tdy=(temp1.y+temp2.y)/2;
	rx=tdx + (temp1.y-temp2.y)/(sqrt(2));
	ry=tdy +(temp2.x-temp1.x)/(sqrt(2));
	r= sqrt(pow(rx-temp1.x,2)+pow(ry-temp1.y,2));
	double hx= rx+(tdx-rx)/(sqrt(pow(rx-tdx,2)+pow(ry-tdy,2)))*r;
	double hy= ry+(tdy-ry)/(sqrt(pow(rx-tdx,2)+pow(ry-tdy,2)))*r;
	double alpha=acos((2*r*r-20*20)/(2*r*r));
	double xStart=(temp1.x-rx)*cos(alpha)-(temp1.y-ry)*sin(alpha)+rx;
	double yStart=(temp1.x-rx)*sin(alpha)+(temp1.y-ry)*cos(alpha)+ry;
	xEnd=(temp2.x-rx)*cos(-alpha)-(temp2.y-ry)*sin(-alpha)+rx;
	yEnd=(temp2.x-rx)*sin(-alpha)+(temp2.y-ry)*cos(-alpha)+ry;
	int reversedxr=tdx*2-rx;
	int reversedyr=tdy*2-ry;
	int vectorStartx=xStart-rx;
	int vectorStarty=yStart-ry;
	int vectorEndx=xEnd-rx;
	int vectorEndy=yEnd-ry;
	startAngle=acos(vectorStartx/sqrt(pow(vectorStartx,2)+pow(vectorStarty,2)))*180/3.14;
	endAngle=acos(vectorEndx/sqrt(pow(vectorEndx,2)+pow(vectorEndy,2)))*180/3.14;
	if(yStart>ry) startAngle=360-startAngle;
	if(yEnd>ry) endAngle=360-endAngle;
	if((hx<400&&rx>hx)||(hy>450&&ry<hy)||(hy<125&&ry>hy)||(hx>getmaxx()-100&&rx<hx)){
		int tempx=rx;
		int tempy=ry;
		rx=reversedxr;
		ry=reversedyr;
		reversedxr=tempx;
		reversedyr=tempy;
		if(yStart>ry)	endAngle=360-abs(180-endAngle);
		else	endAngle=abs(180-endAngle);
		if(yEnd>ry)	startAngle=360-abs(180-startAngle);
		else	startAngle=abs(180-startAngle);
		//Tim diem doi xung cua dau mui ten//
		double k=18/ sqrt(pow(temp1.x-temp2.x,2)+pow(temp1.y-temp2.y,2));
		int Hy= temp2.y+(temp1.y-temp2.y)*k;	
		int Hx= temp2.x+(temp1.x-temp2.x)*k;
		xEnd= 2*Hx -xEnd;
		yEnd= 2*Hy -yEnd;
	}
	//Tim text position
	double k1=(r+5)/sqrt(pow(tdx-rx,2)+pow(tdy-ry,2));
	textPosx=rx+(tdx-rx)*k1;
	textPosy=ry+(tdy-ry)*k1;
}
class link{
	public:
	Node temp1, temp2;
	int x1,y1,x2,y2,trongSo;
	link(Node Temp1,Node Temp2)
	{
		temp1=Temp1;
		temp2=Temp2;
		double deltax=(temp1.x>temp2.x)?1:-1;
		double deltay=(temp1.y>temp2.y)?1:-1;
		double degree=atan((abs(temp1.y-temp2.y)*1.0)/(abs(temp1.x-temp2.x)*1.0));
		x1=temp2.x+deltax*(cos(degree)* 20.0);
		y1=temp2.y+deltay*(sin(degree)* 20.0);
		double Deltax=(temp1.x<temp2.x)?1:-1;
		double Deltay=(temp1.y<temp2.y)?1:-1;
		double Degree=atan((abs(temp1.y-temp2.y)*1.0)/(abs(temp1.x-temp2.x)*1.0));
		x2=temp1.x+Deltax*(cos(Degree)* 20.0);
		y2=temp1.y+Deltay*(sin(Degree)* 20.0);
	}
    int createLink()
	{
		line(x2,y2,x1,y1);
		setfillstyle(1,0);
		createTriangle(x1,y1,x2,y2);
		setfillstyle(1,15);
		//tao trong so
		int intx=(temp1.x+x1)/2;
		int inty=(temp1.y+y1)/2;
		trongSo=atoi(&cusor(intx,inty,1, 0)[0]);
		return trongSo;
	}
	int renameLink(){
		line(x2,y2,x1,y1);
		setfillstyle(1,0);
		createTriangle(x1,y1,x2,y2);
		setfillstyle(1,15);
		//tao trong so
		int intx=(temp1.x+x1)/2;
		int inty=(temp1.y+y1)/2;
		bar(intx-3,inty+2,intx+15,inty+20);
		line(x2,y2,x1,y1);
		trongSo=atoi(&cusor(intx,inty,2, 0)[0]);
		return trongSo;
	}
	void recreateLink(int TrongSo){
		line(x2,y2,x1,y1);
		setfillstyle(1,0);
		createTriangle(x1,y1,x2,y2);
		setfillstyle(1,15);
		//tao trong so
		int intx=(temp1.x+x1)/2;
		int inty=(temp1.y+y1)/2;
		char a[3]={};
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(intx,inty,a);
		else
			outtextxy(intx-5,inty,a);
	}
	bool hoverLink(){
		double a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		double b=sqrt(pow(x1-mousex(),2)+pow(y1-mousey(),2));
		double c=sqrt(pow(x2-mousex(),2)+pow(y2-mousey(),2));
		double p=(a+b+c)/2;
		double degreeB=(acos((b*b+a*a-c*c)/(2*b*a))*180)/3.14;
		double degreeC=(acos((c*c+a*a-b*b)/(2*a*c))*180)/3.14;
		double h=(2*sqrt(p*(p-a)*(p-b)*(p-c)))/a;
		if(h<=15&&degreeB<=90&&degreeC<=90&&degreeB>0&&degreeC>0){
			return true;
		}
		else return false;
	}
	void highlightLink(int TrongSo){
		setcolor(BLUE);
		line(x2,y2,x1,y1);
		setcolor(BLACK);
		setfillstyle(1,BLUE);
		createTriangle(x1,y1,x2,y2);
		setfillstyle(1,15);
		//tao trong so
		int intx=(temp1.x+x1)/2;
		int inty=(temp1.y+y1)/2;
		setcolor(BLACK);
		char a[3];
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(intx,inty,a);
		else
			outtextxy(intx-5,inty,a);
	}
	void eraseLink(int TrongSo){
		setcolor(WHITE);
		line(x2,y2,x1,y1);
		setcolor(BLACK);
		recreate(temp1);
		setcolor(WHITE);
		createTriangle(x1,y1,x2,y2);
		setfillstyle(1,15);
		//tao trong so
		int intx=(temp1.x+x1)/2;
		int inty=(temp1.y+y1)/2;
		char a[3];
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(intx,inty,a);
		else
			outtextxy(intx-5,inty,a);
		setcolor(BLACK);
	}
	int reversedLink(){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		arc(rx,ry,endAngle,startAngle,r);
		createTriangle(xEnd,yEnd,textPosx,textPosy);
		trongSo=atoi(&cusor(textPosx,textPosy,1, 0)[0]);
		return trongSo;
	}
	void recreateReversedLink(int TrongSo){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		arc(rx,ry,endAngle,startAngle,r);
		createTriangle(xEnd,yEnd,textPosx,textPosy);
		char a[3]={};
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(textPosx,textPosy,a);
		else
			outtextxy(textPosx-5,textPosy,a);
	}
	bool hoverReversedLink(){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		int vectorMousex=mousex()-rx;
		int vectorMousey=mousey()-ry;
		int mouseAngle=acos(vectorMousex/sqrt(pow(vectorMousex,2)+pow(vectorMousey,2)))*180/3.14;
		if(mousey()>ry) mouseAngle=360-mouseAngle;
		int distance= sqrt(pow(mousex()-rx,2)+pow(mousey()-ry,2));
		if(mouseAngle<startAngle&&mouseAngle>endAngle&&distance<r+10&&distance>r-10)
			 return true;
		else if((mouseAngle>startAngle||mouseAngle<endAngle)&&distance<r+10&&distance>r-10&&startAngle<endAngle)
			return true;
		else return false;
	}
	void highlightReversedLink(int TrongSo){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		setcolor(BLUE);
		arc(rx,ry,endAngle,startAngle,r);
		createTriangle(xEnd,yEnd,textPosx,textPosy);
		setcolor(BLACK);
		char a[3]={};
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(textPosx,textPosy,a);
		else
			outtextxy(textPosx-5,textPosy,a);
	}
	int renameReversedLink(){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		arc(rx,ry,endAngle,startAngle,r);
		createTriangle(xEnd,yEnd,textPosx,textPosy);
		setfillstyle(1,15);
		bar(textPosx-4,textPosy,textPosx+15,textPosy+19);
		arc(rx,ry,endAngle,startAngle,r);
		trongSo=atoi(&cusor(textPosx,textPosy,1, 0)[0]);
		return trongSo;
	}
	void eraseReversedLink(int TrongSo){
		double rx, ry, r;
		int startAngle, endAngle, xEnd, yEnd, textPosx, textPosy;
		calculateReversedLink(rx, ry, r, startAngle, endAngle, xEnd, yEnd, textPosx, textPosy, temp1, temp2);
		setcolor(WHITE);
		arc(rx,ry,endAngle,startAngle,r);
		createTriangle(xEnd,yEnd,textPosx,textPosy);
		char a[3]={};
		trongSo=TrongSo;
		itoa(trongSo,a,10);
		if(a[1]==NULL)
			outtextxy(textPosx,textPosy,a);
		else
			outtextxy(textPosx-5,textPosy,a);
		setcolor(BLACK);
	}
};
bool isCungCong(int i,int j)
{
	if(i>j && dt.MT[j][i]!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int nameLength(Node a){
	return textwidth(a.name);
}

void VeCung()
{
	for(int i=0;i<=dt.stt_Node;i++){
		for(int j=0;j<=dt.stt_Node;j++){
			link temp(dt.node[i],dt.node[j]);
			link temp1(dt.node[j],dt.node[i]);
			if(dt.MT[i][j]==0&&dt.MT[j][i]==0) 
				continue;
			if(i>j)
			{
				if(dt.MT[j][i]>0&&dt.MT[i][j]>0){
					temp.recreateReversedLink(dt.MT[i][j]);
					temp1.recreateLink(dt.MT[j][i]);
				}
				else if(dt.MT[j][i]>0&&dt.MT[i][j]==0){
					temp1.recreateLink(dt.MT[j][i]);
				}
				else 
					temp.recreateLink(dt.MT[i][j]);
			}
			else
			{
				if(dt.MT[j][i]>0&&dt.MT[i][j]>0){
					temp.recreateLink(dt.MT[i][j]);
					temp1.recreateReversedLink(dt.MT[j][i]);
				}
				else if(dt.MT[j][i]>0&&dt.MT[i][j]==0){
					temp1.recreateLink(dt.MT[j][i]);
				}
				else temp.recreateLink(dt.MT[i][j]);
			}
		}
	}
}
void anyButtonToContinue(){
	outtextxy(100, 625,"Bam phim bat ki de tiep tuc.");
	while(!kbhit()){
		delay(1);
	}
	char temp=getch();
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_RBUTTONDOWN);
	clearThongBao();
}
//////////////////////////Menu//////////////////////////

