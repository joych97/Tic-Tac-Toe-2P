#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

char matrix[3][3];
int count=0;

void init_matrix()
{
  int i,j;
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    matrix[i][j]=' ';
  }
  cout<<endl;
}

void move1()
{
  int a,b;
  cout<<"enter the address for X ";
  cin>>a>>b;
  if(matrix[a][b]!= ' ')
  {
    cout<<"enter a valid place ";
    move1();
  }
  else matrix[a][b]= 'X' ;
}


void move2()
{ 
  int c,d;
  cout<<"enter the adress for O ";
  cin>>c>>d;
  if(matrix[c][d]!= ' ')
  {
    cout<<"enter a valid place ";
    move1();
  }

  else matrix[c][d]= 'O' ;
}


void disp_matrix()
{
  int t,q;
  for(t=0;t<3;t++)
  {
    for(q=0;q<3;q++)
    {
       cout<<matrix[t][q]<<"("<<t<<","<<q<<")" ;
      if(q!=2)
       cout<<"|";

    }
      cout<<endl<<"------|------|------"<<endl;
  }

}


char check()
{ 
  int a=0;
   for(a=0;a<3;a++)
   {
    if(matrix[a][0]==matrix[a][1]&&matrix[a][1]==matrix[a][2])
    return matrix[a][0];
    else if(matrix[0][a]==matrix[1][a]&&matrix[1][a]==matrix[2][a])
     return matrix[0][a];
   }
    if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])
   return matrix[1][1];
    else  if(matrix[0][2]==matrix[1][1]&&matrix[1][1]==matrix[2][0])
   return matrix[0][2];
   else
   return ' ';
   
}

int main()
{
  char done;
  done=' ';

  init_matrix();
  do
  {
   count=count+1;
    disp_matrix();
    move1();
  disp_matrix();
  done=check();
  if(done!=' ')break;
  if (count<5)
  {
    move2();
    done=check();
    if(done!=' ')break;
  }
  }while(done==' '&&count<5);

  if(done=='X')
  cout<<"\n player1(X) wins\n Final positions \n" ;
  else if(done=='O')
  cout<<"\n player2(O) wins \n Final positions \n"  ;
  else
  cout<<"IT'S A DRAW\n";
  disp_matrix();
  cout<<"GAME CREATED BY JOY CHATTERJEE\n ";
  return 0;
}