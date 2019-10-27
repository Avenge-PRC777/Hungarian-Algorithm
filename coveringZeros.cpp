#include <iostream>
#include <vector>
using namespace std;

class Hungarian{
  public:
  vector<vector<int>> input,decision,lines;
  int N;
  
  Hungarian(vector<vector<int>> v1,int v1size)
  {
      input=v1;N=v1size;
      decision= vector<vector<int>>(N,vector <int> (N,0));
      lines= vector<vector<int>>(N,vector <int> (N,0));
  }
  
  void makeDecision()
  {
      int isize=input.size();
      for(int i=0;i<isize;i++)
      {
          for(int j=0;j<isize;j++)
          {
            if(input[i][j]==0){  
              int maxrow=0,maxcol=0;
              for(int k=0;k<isize;k++)
              {
                  if(input[i][k]==0)
                  {
                      maxrow++;
                  }
                  if(input[k][j]==0)
                  {
                      maxcol++;
                  }
              }
              if(maxrow>=maxcol)
              decision[i][j]=-maxrow;
              else
              decision[i][j]=maxcol;
            }
          }
      }
  }
  
  int getMinimumLines()
  {
      int solutions=0;
      makeDecision();
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<N;j++)
          {
              if(decision[i][j]<0&&lines[i][j]!=1)
              {
                  for(int k=0;k<N;k++)
                  lines[i][k]=1;
                  solutions++;
              }
              else if(decision[i][j]>0&&lines[i][j]!=1)
              {
                  for(int k=0;k<N;k++)
                  lines[k][j]=1;
                  solutions++;
              }
          }
      }
      return solutions;
  }
  
  vector<vector<int>> getCoveredMatrix()
  {
      return lines;
  }
  
};
void print(vector<vector<int>> l)
{
    for(int i=0;i<l.size();i++)
    {
        for(int j=0;j<l.size();j++)
        cout<<l[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int n=3;
    vector<vector<int>> v{{1,1,0},{0,0,0},{1,1,0}};
    //v[0].push_back(1);v[0].push_back(1);v[0].push_back(0);
    //v[1].push_back(0);v[1].push_back(0);v[1].push_back(0);
    //v[2].push_back(1);v[2].push_back(1);v[2].push_back(0);
    Hungarian* hr=new  Hungarian(v,n);
    cout<<hr->getMinimumLines()<<endl;
    vector<vector<int>> lines=hr->getCoveredMatrix();
    print(lines);
    delete hr;
    //row check
    //maybe rotate anticlockwise by 90 degree to get columns as rows
    //column check
    return 0;
}
