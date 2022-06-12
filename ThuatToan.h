#include "Queue.h"
#include "Stack.h"
#include "DoHoa.h"
int cnt=0,scc=0;// dem so lan dfs, so lien thong manh
int *low,*num;	//mang low va mang num
bool *deleted;//danh dau dinh
Queue dske[NODE_MAX+1];	//danh sach ke
Stack st;	//luu thanh phan lien thong
int hangY=580;
int *hamilton;
bool *check;
bool flag=false;
int yHang = 555;
int maxHang=-10;
int newColumn=90; 
int kc=100;
void DFS (int u)
{
	if(dt.stt_Node==-1)	
		return;
		
	bool mark[dt.stt_Node+1];
	for(int i=0; i<=dt.stt_Node; ++i)	
		mark[i]=0;
		
	Queue ke[dt.stt_Node+1];
	for(int i=0;i<=dt.stt_Node;++i)
	{
		for(int j=0;j<=dt.stt_Node;++j)
		{
			if(dt.MT[i][j] != 0)
				ke[i].push(j);
		}
	}				
	Stack stack;
	stack.push(u);
	int kc = 100;
	int xuongHang=580;
	int previ=-1;
	mark[u]=true;	//node dau tien
	highlight(dt.node[u]);
	delay(500);
	outtextxy(100 , xuongHang, dt.node[u].name);
	previ=u; // Canh vi tri printDemo
	while(!stack.empty()){
		int s;
		stack.pop(s);
		while(!ke[s].empty())
		{ // neu ke[s] khac rong
			int i ; ke[s].pop(i); // i la gia tri lay trong hang doi
			if(!mark[i])
			{
				stack.push(s); // dua s vao lai stack
				stack.push(i); // dua i vao stack
				mark[i] = true;
				// draw node
				kc+=(nameLength(dt.node[previ]));
				link cung(dt.node[s], dt.node[i]);
				if(isCungCong(s, i)) 
					cung.highlightReversedLink(dt.MT[s][i]);
				else 
					cung.highlightLink(dt.MT[s][i]);
				if(kc+nameLength(dt.node[i])>getmaxx()){
					xuongHang+=25;
					kc=100;
				}
				outtextxy(kc,xuongHang,"=>");
				kc+=textwidth("=>");
				delay(500);
				highlight(dt.node[i]);
				outtextxy(kc,xuongHang,dt.node[i].name);
				delay(500);
				previ=i;
				break;
			}
		}
	}
}
void bfs(int u){
	int textpos=40; 
	int arrow=textwidth("=>");
	int xuongHang=580;
	Queue queue;
	bool visit[dt.stt_Node+1]={0};
	int truoc[dt.stt_Node+1];
	for(int i=0;i<=dt.stt_Node;i++)	
		visit[i]=0;
	queue.push(u);
	visit[u]=1;
	highlight(dt.node[u]);
	delay(500);
	while(!queue.empty()){
		int s;
		queue.pop(s);
		delay(500);
		if(s!=u){
			link cung(dt.node[truoc[s]], dt.node[s]); // Khoi Tao Cung Co Trong So
			if(isCungCong(truoc[s],s)) 
				cung.highlightReversedLink(cung.trongSo);
			else 
				cung.highlightLink(cung.trongSo);
			highlight(dt.node[truoc[s]]);
			if(textpos+arrow>getmaxx()){
				xuongHang+=25;
				textpos=40;
			}
			outtextxy(textpos,xuongHang,"=> ");
			textpos+=arrow;
		}
		delay(500);
		highlight(dt.node[s]);
		if(nameLength(dt.node[s])+textpos>=getmaxx()){
			xuongHang+=25;
			textpos=40;
		}
		outtextxy(textpos,xuongHang,dt.node[s].name);
		textpos+= nameLength(dt.node[s]);
		for(int i=0;i<=dt.stt_Node;i++){
			if(visit[i]==0&&dt.MT[s][i]!=0){
				queue.push(i);
				visit[i]=true;
				truoc[i]=s;
			}
		}
	}
}
void Tarjan(int u, int &kc, bool in =1) // KC Vi tri in tplt
{		//DFS CHO THANH PHAN LIEN THONG MANH
	num[u]=low[u]=++cnt;
	st.push(u);
	while(!dske[u].empty())
	{
		int v;
		dske[u].pop(v);
		if(deleted[v])	
		continue;
		if(num[v]==0)
		{
			Tarjan(v, kc, in);
			if(in){
				if(kc+5>=getmaxx()){
					hangY+=25;
            		kc=getmaxx()/2+30;
				}
				outtextxy(kc, hangY, "(");
			}
			low[u]=min(low[v],low[u]);
		}
		else 
			low[u]=min(low[u],num[v]);
	}
	if (low[u] == num[u]) {
        scc++;
        int v;
       	kc+=3;
        do 
		{
            st.pop(v);
            char a[10];
            kc += 5; // cach dau ngoac
            if(kc+nameLength(dt.node[v])>getmaxx()){
            	hangY+=25;
            	kc=getmaxx()/2+30;
			}
			if (in){
				outtextxy(kc, hangY, dt.node[v].name);
				kc+= nameLength(dt.node[v]); // cach so
				if(v!=u){
	            	outtextxy(kc, hangY,",");
					kc+=textwidth(",");
				}
			}
            deleted[v] = true;
        }
        while (v != u);
        if (in)	outtextxy(kc, hangY, ")");
        kc+=5;
    }
}
int TPLT_manh(bool in=1)
{
	cnt=0;
	scc=0;
	int kc = getmaxx()/2+30; // Khoang cach in
	num=new int[NODE_MAX+2];
	low=new int[NODE_MAX+2];
	deleted=new bool[NODE_MAX+2];
	//danh sach ke
	for(int i=0;i<=dt.stt_Node;++i)
		for(int j=0;j<=dt.stt_Node;++j)
			if(dt.MT[i][j]>0)
				dske[i].push(j);
	//reset gia tri
	for(int i=0;i<NODE_MAX+1;++i){
		num[i]=low[i]=0;
		deleted[i]=false;
	}
	// thuat toan tarjan
	for(int i=0;i<=dt.stt_Node;++i)
		if(num[i]==0)
		{	
			if(in){
				if(kc+5>=getmaxx()){
					hangY+=25;
            		kc=getmaxx()/2+30;
				}
				outtextxy(kc, hangY, "(");
			}
			Tarjan(i, kc,in);
		}
		hangY=580;
		return scc;
	// output ra
}
int TPLTVoHuong()
{
	int **MT_tmp = new int *[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		MT_tmp[i] = new int[dt.stt_Node+1];
	
	for(int i=0;i<=dt.stt_Node;++i)
			for(int j=0;j<=dt.stt_Node;++j) 			
				MT_tmp[i][j]=0;
				
	for(int i=0;i<=dt.stt_Node;++i){
		for(int j=0;j<=dt.stt_Node;++j){
			if(dt.MT[i][j]!=0||dt.MT[j][i]!=0){
				MT_tmp[i][j]=1;
				MT_tmp[j][i]=1;
			}
		}
	}
	bool *visit = new bool[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		visit[i] = false;
	int stplt=0;
	int kc = 0;
	int xuongHang=580;
	int prevNode=-1;

	for(int i=0;i<=dt.stt_Node;++i)
	{
		if(visit[i]==0)
		{
			Queue queue;
			queue.push(i);
			visit[i]=1;
			if(kc+nameLength(dt.node[i])>getmaxx()/2){
				xuongHang+=25;
				kc=0;
			}
			outtextxy(5+kc, xuongHang, "(");
			outtextxy(15+kc, xuongHang, dt.node[i].name);
			kc+=15;
			prevNode=i;
			kc+=nameLength(dt.node[prevNode]);
			while(!queue.empty())
			{
				int s;
				queue.pop(s);	
				for(int v=0; v<=dt.stt_Node;++v)
				{
					if(!visit[v] && MT_tmp[s][v] != 0)
					{
						queue.push(v);
						visit[v] = true;
						if(kc+nameLength(dt.node[v])>getmaxx()/2){
							xuongHang+=25;
							kc=0;
						}
						if(!queue.empty()){
					outtextxy(5 + kc, xuongHang,",");
					kc+=textwidth(",");
				}
						outtextxy(5 + kc, xuongHang, dt.node[v].name);
						prevNode=v;
						kc+=nameLength(dt.node[prevNode]);
					}
				}
			}
			outtextxy(5+ kc, xuongHang, ")");
			kc+=5;
			stplt++;
		}
	}
	char a[10];
	itoa(stplt, a, 10);
	outtextxy(10, 555, "Do Thi Vo Huong");
	outtextxy(200, 555, "TPLT:");
	outtextxy(260, 555, a);
	return stplt;
}

void Dijkstra(int src, int des)
{
	int A[dt.stt_Node+1][dt.stt_Node+1];
	int d[dt.stt_Node+1];
	int truoc[dt.stt_Node+1];
	bool check[dt.stt_Node+1];
	for(int i=0;i<=dt.stt_Node;++i)	check[i]=0;
	check[src]=1;
	//khoi tao A
	for(int i=0;i<=dt.stt_Node;++i)
		for(int j=0;j<=dt.stt_Node;++j)
			A[i][j]=dt.MT[i][j]>0?dt.MT[i][j]:1000;
	d[src]=0;	//dan nhan v
	for(int i=0;i<=dt.stt_Node;++i){
		if(i==src)
			continue;
		d[i]=A[src][i];//source toi dinh ke
		truoc[i]=src;	//luu duong di
	}
	int k=1;
	int cnt=0;	//so luong dinh da duoc dan nhan
	while(k<=dt.stt_Node){
		//tim u thuoc tap dinh sao cho d[u] min
		int u=0,min=1000;
		for(int i=0;i<=dt.stt_Node;++i){
			if(!check[i]){
				if(min>d[i]){
					min=d[i];
					u=i;	//chon u
				}
			}
		}
		if(u==des)
			break;	//da toi dinh can tim
		check[u]=1;
		k++;
		for(int i=0;i<=dt.stt_Node;++i){
			if(!check[i]){
				if(d[i]>d[u]+A[u][i]){
					d[i]=d[u]+A[u][i];
					truoc[i]=u;
				}
			}
		}
	}
	//truy hoi duong di
	Stack st;
	int x=des;
	st.push(des);
	while(x!=src){
		x=truoc[x];
		st.push(x);
	}
	//in duong bang stack
	int pre=-1;
	int a;
	int textpos=40; 
	int xuongHang=580;
	int khoangCach=d[des];
	if(d[des]==1000){
		outtextxy(100,600,"Khong co duong di.");
		return;
	}
	while(!st.empty()){
		st.pop(a);
		if(pre!=-1){
			link temp(dt.node[pre],dt.node[a]);
			if(isCungCong(pre,a)) temp.highlightReversedLink(dt.MT[pre][a]);
			else temp.highlightLink(dt.MT[pre][a]);
			if(textwidth("=>")+textpos>getmaxx()){
				xuongHang+=25;
				textpos=40;
			}
			outtextxy(textpos,xuongHang,"=>");
			textpos+=textwidth("=>");
			delay(500);
		}
		highlight(dt.node[a]);
		if(nameLength(dt.node[a])+textpos>=getmaxx()){
			xuongHang+=25;
			textpos=40;
		}
		outtextxy(textpos,xuongHang,dt.node[a].name);
		delay(500);
		textpos+=nameLength(dt.node[a]);
		pre=a;
	}
	char KhoangCach[3]={};
	itoa(khoangCach,KhoangCach,10);
	outtextxy(100,xuongHang+25,"Khoang cach la: ");
	outtextxy(100+textwidth("Khoang cach la: "),xuongHang+25,KhoangCach);
}

/////////////////////////////////////////////////Dinh Tru///////////////////////
void CoLapDinh(int vt)
{
	for(int i = 0; i<=dt.stt_Node; i++)
	{
		dt.MT[i][vt] = 0;
		dt.MT[vt][i] = 0;
	}
}

void BoCoLapDinh(int **tmp)
{
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			dt.MT[i][j] = tmp[i][j];
		}
	}
}

void DinhTru()
{
	int **tmp = new int*[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		tmp[i] = new int[dt.stt_Node+1];
	
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			tmp[i][j] = dt.MT[i][j];
		}
	}
	
	int TempLTM = TPLT_manh(0);
	int res = 0; // Dem So Dinh Tru
	int kc=100;
	int xuongHang=580;
	for(int i = 0; i<= dt.stt_Node; i++)
	{	
		CoLapDinh(i);
		int NewTplt = TPLT_manh(0);
		if(NewTplt -1 > TempLTM)
		{
			res++;
			highlight(dt.node[i]);
			outtextxy(kc,xuongHang,dt.node[i].name);
			kc+=nameLength(dt.node[i])+10;
			if(kc>=getmaxx()){
				xuongHang+=25;
				kc=100;
			}
		}
		BoCoLapDinh(tmp);
	}
	outtextxy(100, 555, "Dinh Tru: ");
	char a[3];
	itoa(res, a, 10);
	outtextxy(250, 555, a);
	for(int i = 0; i<= dt.stt_Node; i++)
		delete []tmp[i];
	delete []tmp;
}

//////////////////////////////////////////////////////
bool LienThongUvaV(int u, int v)
{
	int *mark = new int[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		mark[i] = 0;
	
	Queue q;
	q.push(u);
	
	while(!q.empty())
	{
		int s;
		q.pop(s);
		for(int i = 0; i<= dt.stt_Node; i++)
		{
			if(dt.MT[s][i] != 0 && mark[i] == 0)
			{
				q.push(i);
				mark[i] = 1;
				if(i==v)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void DinhThat(int u, int v)
{
	int **tmp = new int*[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		tmp[i] = new int[dt.stt_Node+1];
	
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			tmp[i][j] = dt.MT[i][j];
		}
	}
	
	int DuongDiLucDau = LienThongUvaV(u,v);
	int kc = 0;
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		CoLapDinh(i);
		
		if(DuongDiLucDau && !LienThongUvaV(u,v) && i != u && i != v) // Khong Phai Bo Dinh Bat Dau Va Cuoi
		{
			outtextxy(150 + 30*kc, 580, dt.node[i].name);
			highlight(dt.node[i]);
			delay(1000);
			kc++;
		}
		
		BoCoLapDinh(tmp);
	}
	if(kc==0)
	{
		outtextxy(150 + 30*kc, 580, "Khong Co");
	}
	
	for(int i = 0; i<= dt.stt_Node; i++)
		delete []tmp[i];
	delete []tmp;
}

///////////////////////////////////////////////////////
void CoLapCanh(int i, int j)
{
	dt.MT[i][j] = 0;
}

void BoXoaCanh(int **tmp, int i, int j)
{
	dt.MT[i][j] = tmp[i][j];
}

void CanhCau()
{
	int **tmp = new int*[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
		tmp[i] = new int[dt.stt_Node+1];
	
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			tmp[i][j] = dt.MT[i][j];
		}
	}
	
	
	int Tplt = TPLT_manh(0);
	int res = 0;
	int kc = 10;
	int xuongHang=580;
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			CoLapCanh(i, j);
			int Newtplt = TPLT_manh(0);;
			if(Newtplt > Tplt)
			{
				res++;
				if(kc+30+nameLength(dt.node[i])+nameLength(dt.node[j])>getmaxx()){
					xuongHang+=25;
					kc=10;
				}
				outtextxy(kc, xuongHang, "(");
				kc+=10;
				outtextxy(kc, xuongHang, dt.node[i].name);
				kc+=nameLength(dt.node[i]);
				outtextxy(kc, xuongHang,", ");
				kc+=textwidth(", ");
				outtextxy(kc, xuongHang, dt.node[j].name);
				kc+=nameLength(dt.node[j]);
				outtextxy(kc, xuongHang, ")");
				kc+=20;
				link temp(dt.node[i], dt.node[j]);
				if(isCungCong(i, j))
					temp.highlightReversedLink(tmp[i][j]);
				else
					temp.highlightLink(tmp[i][j]);
						
			}
			BoXoaCanh(tmp, i, j);
		}
	}
	char a[3];
	itoa(res, a, 10);
	outtextxy(10, 555, "Canh Cau:");
	outtextxy(150, 555, a);
	
	for(int i = 0; i<= dt.stt_Node; i++)
		delete []tmp[i];
	delete []tmp;
	
}
//////////////////////////////////////////////////
void print_Hamilton()
{
	int previ=-1; 
	flag=true;
	//outext
	//dao nguoc mang hamilton
	for(int i = 0; i<=dt.stt_Node+1; i++)
	{	
		outtextxy(kc, yHang, dt.node[hamilton[i]].name);
		kc+=nameLength(dt.node[hamilton[i]])+10;
		if(previ!=-1)
		{
			link temp(dt.node[previ],dt.node[hamilton[i]]);
			if(isCungCong(previ,hamilton[i])) temp.highlightReversedLink(dt.MT[previ][hamilton[i]]);
			else temp.highlightLink(dt.MT[previ][hamilton[i]]);
			delay(50); 
		} 
		highlight(dt.node[hamilton[i]]);
		delay(50);
		previ=hamilton[i];
	}
	if(kc>maxHang){
		maxHang=kc;
	}
	yHang+=25;
	if(yHang>=getmaxy()-50){
		yHang=555;
		newColumn=maxHang;
		line(newColumn,555,newColumn,getmaxy()-25);
	}
	kc=newColumn+10;	
}
void ct_hamilton(int i)
{
	for(int j=0;j<=dt.stt_Node;++j)
	{
		if(dt.MT[hamilton[i-1]][j]>0&&check[j]==0){
			hamilton[i]=j;	check[j]=1;
			if(i<=dt.stt_Node)
				ct_hamilton(i+1);
			else if(hamilton[i]==hamilton[0])
			{   
				if(newColumn+maxHang>=getmaxx()&&yHang==555){
					outtextxy(550,getmaxy()-25,"Khong con man hinh de output.");
					return;
				}
				VeCung();
				for(int j=0;j<=dt.stt_Node;j++){
					recreate(dt.node[j]);
				}
				print_Hamilton();
			}
			check[j]=0;
		}
	}
}
void hamilton_solution(int src)
{
	hamilton = new int[dt.stt_Node+2];
	check =new bool[dt.stt_Node+1];
	for(int i=0;i<=dt.stt_Node;++i)	
		check[i]=0;
	flag=0;
	hamilton[0]=src;
//	che;
	ct_hamilton(1);
	if(flag==0)
	{
		outtextxy(100, 555, "Khong Co Hamilton");
	}
	yHang = 555;
	maxHang=-10;
 	newColumn=100; 
	kc=100;
	delete[] hamilton;
	delete[] check;
}

////////////////////////////////////////////////////////
void TinhBanBac(int vao[], int ra[])
{
	for(int i = 0; i<=dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			if(dt.MT[i][j] != 0)
			{
				vao[i]++;
			}
		}
	}
	
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			if(dt.MT[j][i] != 0)
			{
				ra[i]++;
			}
		}
	}
}

bool KiemTraBanBac(int vao[], int ra[])
{
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		if(vao[i] != ra[i])
			return false;
	}
	return true;
}

bool KiemTraEuler(int vao[], int ra[])
{
	if(KiemTraBanBac(vao, ra)==true)
	{	
		clearThongBao();
		return true;
	}
	else
	{
		clearThongBao();
		return false;	
	}
}

void chuTrinhEuler(int s)
{
	Stack st;
	Stack cE;
	st.push(s);
	
	Queue dsKe[dt.stt_Node+1];
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		for(int j = 0; j<= dt.stt_Node; j++)
		{
			if(dt.MT[i][j] != 0)
			{
				dsKe[i].push(j);
			}
		}
	}
	
	while(!st.empty())
	{
		int s = st.get();
		if(!dsKe[s].empty())
		{
			int t;
			dsKe[s].pop(t);
			st.push(t);
		}
		else
		{
			int tmp;
			st.pop(tmp);
			cE.push(tmp);	
		}
	}
	int kc = 10;
	int xuongdong=555;
	int temp = cE.get();
	while(!cE.empty())
	{
		int ce;
		cE.pop(ce);
		link cung(dt.node[temp], dt.node[ce]);
		if(temp!=ce){
			if(isCungCong(temp, ce)) 
				cung.highlightReversedLink(dt.MT[temp][ce]);
			else 
				cung.highlightLink(dt.MT[temp][ce]);
			if(kc+23>getmaxx()-15){
				xuongdong+=25;
				kc=10;
			}
		}
		if(kc!=10)
			outtextxy(kc,xuongdong, "=>");
		kc+=textwidth("=>");
		delay(500);
		temp = ce;
		if(kc+nameLength(dt.node[ce])>getmaxx()-15){
			xuongdong+=25;
			kc=10;
		}
		outtextxy(kc,xuongdong, dt.node[ce].name);
		highlight(dt.node[ce]);
		delay(500);
		kc+=nameLength(dt.node[ce]);
	}
}

void Euler(int s)
{
	int vao[dt.stt_Node+1];
	int ra[dt.stt_Node+1];
	
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		vao[i] = 0;
		ra[i] = 0;
	}
	
	TinhBanBac(vao, ra);
	
	if(KiemTraEuler(vao, ra))
	{
		chuTrinhEuler(s);
	}
	else
	{
		outtextxy(100, 555, "Khong Co Chu Trinh");
	}
}
//////////////////////////////////////////////////////////////////toposort////////////////////////////
//topo
// do thi
// danh sach cac mon da hoan thanh
// danh sach cac mon dang ky

// output
// cac mon da dang ky thanh cong
// cac mon dang ky khong duoc(ly do)
// Thuat Toan ToMau Kiem Tra Chu Trinh
bool ToMau(int u, int color[], Stack CT[]) // vtS vi tri bat dau push vo stack
{
	color[u] = 1;
	for(int v = 0; v <= dt.stt_Node; v++)
	{  
		if(dt.MT[u][v] != 0 && color[v] == 0)
		{
			if(ToMau(v, color, CT))
			{
				return true;
			} 		
		}
		else if(dt.MT[u][v] != 0 && color[v] == 1) 
		{
			return true;
		}
	}
	color[u] = 2;
	return false;
}

bool ChuTrinh(int color[], Stack CT[])
{
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		if(color[i] == 0)
		{
			if(ToMau(i, color, CT))
				return true;
		}
	}
	return false;
}

// DFS Tim Mon Tien Quyet Cho Mot Mon
void DFS_Topo(int u, Stack dstq[], int vt)
{
	bool mark[dt.stt_Node+1];
	for(int i=0; i<=dt.stt_Node; ++i)	
		mark[i]=0;
	
	Queue ke[dt.stt_Node+1];
	for(int i=0;i<=dt.stt_Node;++i)
	{
		for(int j=0;j<=dt.stt_Node;++j)
		{
			if(dt.MT[j][i] != 0)
				ke[i].push(j);
		}
	}
					
	Stack stack;
	stack.push(u);
	int kc = 0;
	mark[u]=true;	//node dau tien
	while(!stack.empty()){
		int s;
		stack.pop(s);
		while(!ke[s].empty())
		{ // neu ke[s] khac rong
			int i ; ke[s].pop(i); // i la gia tri lay trong hang doi
			if(!mark[i])
			{
				stack.push(s); // dua s vao lai stack
				stack.push(i); // dua i vao stack
				dstq[vt].push(i);
				mark[i] = true;
				break;
			}
		}
	}
}

// Tim Dieu Kien Tien Quyet Tat Ca Cac Mon Va Tim Chu Trinh
void Toposort(Stack dstq[])
{
	for(int i = 0; i<= dt.stt_Node; i++)
	{
		DFS_Topo(i, dstq, i);
	}	
}

