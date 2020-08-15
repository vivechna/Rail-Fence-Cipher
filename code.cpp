#include<iostream>
#include<thread>
#include<bits/stdc++.h>
using namespace std;
#include<windows.h>
#include<bits/stdc++.h>
#include<math.h>
#include<queue>
#define M 5
#define V 5

int cars[V][3]={{0,0,-1},{1,0,-1},{2,0,-1},{3,0,-1},{4,0,-1}};
int path[M][M][M+1];
int cost[M][M];

typedef struct minvalue
{
    int i;
    int minimumdist;
}minvalue;

struct compareoperator{
bool operator()(minvalue const &M1,minvalue const &M2)
 {
  return M1.minimumdist>M2.minimumdist;
 }
};

priority_queue<minvalue,vector<minvalue>,compareoperator> p;

int graph[M][M]={
                   {0, 30, 13,90,100},
					{14,0, 120,22,20},
                    {120, 8, 0, 60,19},
                    {11,1,21,0,100},
                    {24,9,180,24,0},

                };


int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < M; v++)
if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}




int dijkstra(int src,int dest)
{
    if(cost[src][dest]!=0){
       return cost[src][dest];
        }
     int dist[M];
     int i;
     bool sptSet[M];


     int parent[M];
     for ( i = 0; i < M; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i]=-1;
     }


     dist[src] = 0;

     for (int count = 0; count < M-1; count++)
     {

       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < M; v++)
   {

         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
           {
               dist[v] = dist[u] + graph[u][v];
            //cost[u][v]=dist[v];
            parent[v]=u;
//            cout<<v<<" "<<parent[v]<<endl;

           }
     }

}


for ( i = 0; i < M; i++){
    cost[src][i]=dist[i];

    int p=i;
stack<int> po;
while(p!=src)
{
    po.push(p);
   // cout<<po.top()<<"r"<<endl;
    p=parent[p];
    //cout<<po.top()<<"t"<<endl;
}
po.push(src);
//cout<<po.top()<<"r"<<endl;
int j=0;
while(!po.empty())
{
    int x=po.top();
    path[src][i][j]=x;
    j++;
    po.pop();
}

}

return dist[dest];

}


void dijkstraa(int src,int dest,int c)
{

                    cars[c][2]=dest;
                    if(cars[c][0]!=src)
                    {
                        int i=0;
                        while(path[cars[c][0]][src][i+1]!=-1)
                        {
                            Sleep(graph[path[cars[c][0]][src][i]][path[cars[c][0]][src][i+1]]*(pow(10,3)));
                            cars[c][0]=path[cars[c][0]][src][i+1];

                            i++;
                        }
                    }

                    if(path[src][dest][1]==-1)
                        {
                        int u=dijkstra(src,dest);
                        }

                        int i=0;
                        while(path[src][dest][i+1]!=-1)
                        {




                            Sleep(graph[path[src][dest][i]][path[src][dest][i+1]]*(pow(10,3)));
                            cars[c][0]=path[src][dest][i+1];
                            i++;
                        }


                            cars[c][1]--;
                            cars[c][2]=-1;


}

int c(int i){
    int ci=cars[i][1];
        if(cars[i][1]==0){

        cars[i][1]++;
    }
    return ci;
}

int findcar(int a1, int a2,int cars[V][3]){
    minvalue temp;
    int v=0;
    while(!p.empty())
        p.pop();
    for(int i=0;i<V;i++){
       temp.i=i;
       temp.minimumdist=dijkstra(cars[i][0],a1);
       p.push(temp);
    }
    minvalue new1;
    for(int i=0;i<V;i++)
    {
         new1=p.top();
        if((c(new1.i))==0)
        {
          v=1;
          break;
        }

    else
            p.pop();

    }
    if(v==1)
        return new1.i;
    else
    return -1;
}

int main(){

    cout<<"                            BOOK YOUR CAB!                  \n";
    int i,j;
    for( i=0;i<M;i++)
    for(j=0;j<M;j++)
      for(int k=0;k<=M;k++)
       path[i][j][k]=-1;


    for(i=0;i<M;i++){
        for( j=0;j<M;j++){
            cost[i][j]=0;
        }
    }
    vector<string> locations(M);
    map<string,int> m;
    m.insert(pair<string, int>("Delhi", 0));
    m.insert(pair<string, int>("Pune", 1));
    m.insert(pair<string, int>("Bombay", 2));
    m.insert(pair<string, int>("Shimla", 3));
    m.insert(pair<string, int>("Noida", 4));

    map<int,string> mp;
    mp.insert(pair<int,string>(0, "Delhi"));
    mp.insert(pair<int,string>(1, "Pune"));
    mp.insert(pair<int,string>(2, "Bombay"));
    mp.insert(pair<int,string>(3, "Shimla"));
    mp.insert(pair<int,string>(4, "Noida"));

    map<int,string> cb;
    cb.insert(pair<int,string>(0, "001"));
    cb.insert(pair<int,string>(1, "002"));
    cb.insert(pair<int,string>(2, "003"));
    cb.insert(pair<int,string>(3, "004"));
    cb.insert(pair<int,string>(4, "005"));

for(int i=0;i<M;i++)
{
   locations[i]=mp.find(i)->second;
}
vector<string>::iterator it;
vector<thread> th4;
int b=1;
while(b!=-1)
    {
        cout<<"LOCATIONS-\n\n";
        for(int i=0;i<M;i++)
            cout<<"Location number:"<<i<<"  "<<"Name:"<<(mp.find(i))->second<<endl;
        cout<<endl<<"Cab Number"<<"    "<<"Current cab locations"<<endl;
        for(int i=0;i<M;i++){
            cout<<endl<<cb.find(i)->second<<" : "<<(mp.find(cars[i][0]))->second;
            if(cars[i][1]==1)
                cout<<"(Booked)";

        }
        cout<<endl<<endl;
     string ps,pd;
     cout<<"Pickup Location: ";
     cin>>ps;
     it=find(locations.begin(),locations.end(),ps);
     if(it==locations.end())
     {
         cout<<"Cant detect the Pickup location";
         break;
     }
     cout<<"Drop Location: ";
     cin>>pd;
     it=find(locations.begin(),locations.end(),pd);
     if(it==locations.end())
     {
         cout<<"Cant detect the Drop location";
         break;
     }
     if(ps.compare(pd)==0)
     {
         cout<<"Source and destination cannot be same!";
         break;
     }

     cout<<endl;
     int c = findcar((m.find(ps))->second,(m.find(pd))->second,cars);

     if(c==-1)
        {

            cout<<"Cab Not Available for user"<<endl;
        }
        else
        {
            cout<<"Cab for user is booked:"<<cb.find(c)->second<<endl;
            if(path[(m.find(ps))->second][(m.find(pd))->second][1]==-1){
                int u=dijkstra((m.find(ps))->second,(m.find(pd))->second);
            }
            cout<<"Your path is:";
            int k=0;
            while(path[(m.find(ps))->second][(m.find(pd))->second][k]!=-1){
                cout<<" "<<mp.find(path[(m.find(ps))->second][(m.find(pd))->second][k++])->second<<"->";
            }
            cout<<"END"<<endl;
            cout<<"Fare: "<<5*(cost[(m.find(ps))->second][(m.find(pd))->second])+35<<endl;

            th4.push_back(std::thread(dijkstraa,(m.find(ps))->second,(m.find(pd))->second,c));
        }


        cout<<"\nPRESS 1 TO BOOK MORE CABS \nPRESS -1 TO EXIT\n"<<endl;
        cin>>b;
    }



    for (thread &t : th4) {
        t.join();
    }


    return 0;

}
