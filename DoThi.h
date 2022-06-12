struct Node
{
	int x,y;
	char name[5] = {'\0'};
	char tenMonHoc[100]= {'\0'};
};
struct DoThi
{
	Node *node;
	int stt_Node;
	int soMonDahoc = 0;
	
	int **MT;	
	Node *DSMDH;
	bool *DSVTMDH;
	Node *DSDK;
	void delete_Data()
	{
		delete [] node;
		for(int i=0;i<=stt_Node;++i) delete[] MT[i];
		delete[] MT;
	}
	void them_node()
	{	//tang node
			Node *node2=new Node[stt_Node+1];
			Node * dsmh2 = new Node[stt_Node+1];
			bool *dsvtmdh22 = new bool[stt_Node+1];
			Node *dsdk2 = new Node[stt_Node+1];
			for(int i=0;i<=stt_Node-1;++i)
			{
				node2[i]=node[i];
				dsmh2[i] = DSMDH[i];
				dsvtmdh22[i] = DSVTMDH[i];
				dsdk2[i] = DSDK[i];
			}
			delete []node;
			delete []DSMDH;
			delete []DSDK;
			delete []DSVTMDH;

			node=node2;
			DSMDH = dsmh2;
			DSDK = dsdk2;
			DSVTMDH = dsvtmdh22;
	}
	void giam_node(int del_index){
			Node *node2=new Node[stt_Node+1];
			for(int i=0;i<=del_index-1;++i){
				node2[i]=node[i];
			}
			for(int i=del_index;i<=stt_Node;++i){
				node2[i]=node[i+1];
			}
			delete []node;
			node=node2;
	}	
	void reset_MT(int **MT1){
		for(int i=0;i<=stt_Node;++i)
			for(int j=0;j<=stt_Node;++j) 			
				MT1[i][j]=0;
	}
	void tang_MT(){
		//TANG MT LEN 1
			int **MT2=new int *[stt_Node+1];
			for(int i=0;i<=stt_Node;++i) MT2[i]=new int[stt_Node+1];
			reset_MT(MT2);
			for(int i=0;i<=stt_Node-1;++i)
				for(int j=0;j<=stt_Node-1;++j)
					MT2[i][j]=MT[i][j];
				
			for(int i=0;i<=stt_Node-1;++i) delete[] MT[i];
			delete[] MT;
			MT=MT2;
	}
	void Giam_MT(int ind){
		int **MT2=new int *[stt_Node+1];
			for(int i=0;i<=stt_Node;++i) MT2[i]=new int[stt_Node+1];
			
			for(int j=0;j<=stt_Node+1;++j) {
					MT[ind][j]=0;
					MT[j][ind]=0;
			}
			for(int l1=0;l1<=stt_Node+1;++l1){
				for(int l2=0;l2<=stt_Node+1;++l2) {
					if(MT[l1][l2]!=0){
						int t1,t2;
						t1=(l1>ind?l1-1:l1);
						t2=(l2>ind?l2-1:l2);
						if(l1>ind||l2>ind){
							MT[t1][t2]=MT[l1][l2];
							MT[l1][l2]=0;
						}
					}
				}
			}
			reset_MT(MT2);
			for(int i=0;i<=stt_Node;++i)
				for(int j=0;j<=stt_Node;++j) 
					MT2[i][j]=MT[i][j];
			for(int i=0;i<=stt_Node+1;++i) delete[] MT[i];
			delete[] MT;
			MT=MT2;
	}
	~DoThi(){
		delete [] node;
		for(int i=0;i<=stt_Node;++i) delete[] MT[i];
		delete[] MT;
	}
	
} dt;
