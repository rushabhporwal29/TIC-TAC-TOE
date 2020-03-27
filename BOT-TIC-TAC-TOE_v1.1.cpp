#include<iostream>
using namespace std;

class ttt
{
	char a[3][3];
	int r,c;
	char player,comp;
	string name,winner;
	public:
			ttt()
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
						a[i][j]='-';
				}
				winner="NONE";
			}
			void playground();
			void start();
			void input();
			void display();
			string condition();
			void bot();
};

int main()
{
	ttt t;
	t.start();
	t.playground();
	return 0;
}

void ttt::start()
{
	cout<<"\n Enter Your Name : ";
	cin>>name;
	cout<<"\n Select Your Character (X / O): ";
	cin>>player;
	if(player=='x'||player=='X')
	{
		player='X';
		comp='O';
	}
	else
	{
		player='O';
		comp='X';
	}
}

void ttt::display()
{
	cout<<"\n  \t1 \t2 \t3";
	for(int i=0;i<3;i++)
	{
		cout<<"\n "<<i+1;
		for(int j=0;j<3;j++)
		{
			cout<<"\t"<<a[i][j]<<" ";
		}
	}
}

void ttt::input()
{
	cout<<"\n Enter Row    : ";
	cin>>r;
	cout<<"\n Enter Column : ";
	cin>>c;
	a[r-1][c-1]=player;
}

void ttt::playground()
{
	display();
	int x=0;
	do
	{
		input();
		x++;
		if(x==9||!(condition()=="NONE"))
		{
			display();
			break;
		}
		bot();
		display();
		if(condition()!="NONE")
			break;
		x++;
	}while(x<=9);
	cout<<"\n Winner : "<<winner;
}

void ttt::bot()
{
	char x;
	for(int k=0;k<2;k++)
	{
		if(k=0)
			x=player;
		else
			x=comp;
		for(int i=0;i<3;i++)
		{
				if(a[i][1]==a[i][0]||a[i][0]==a[i][2]||a[i][1]==a[i][2])
				{
					if(a[i][1]==a[i][2]&&a[i][0]!=player)
					{	a[i][0]=comp;
						return;
					}
					if(a[i][1]==a[i][0]&&a[i][2]!=player)
					{	a[i][2]=comp;
						return;
					}
					if(a[i][0]==a[i][2]&&a[i][1]!=player)
					{	a[i][1]=comp;
						return;
					}
				}
				else if(a[0][i]==a[1][i]||a[0][i]==a[2][i]||a[1][i]==a[2][i])
				{
						if(a[1][i]==a[2][i]&&a[0][i]!=player)
						{				
							a[0][i]=comp;
							return;
						}
						if(a[1][i]==a[0][i]&&a[2][i]!=player)
						{				
							a[2][i]=comp;
							return;
						}
						if(a[0][i]==a[2][i]&&a[1][i]!=player)
						{				
							a[1][i]=comp;
							return;
						}
				}
		}
		if(a[0][0]==a[1][1]||a[0][0]==a[2][2]||a[1][1]==a[2][2])
		{
				if(a[1][1]==a[2][2]&&a[0][0]!=player)
				{
					a[0][0]=comp;
					return;
				}
				if(a[0][0]==a[2][2]&&a[0][0]!=player)
				{
					a[1][1]=comp;
					return;
				}
				if(a[1][1]==a[0][0]&&a[2][2]!=player)
				{
					a[2][2]=comp;
					return;
				}
		}
		else if(a[0][2]==a[1][1]||a[0][2]==a[2][0]||a[1][1]==a[2][0])
		{
				if(a[1][1]==a[2][0]&&a[0][2]!=player)
				{
					a[0][2]=comp;
					return;
				}
				if(a[0][2]==a[2][0]&&a[1][1]!=player)
				{
					a[1][1]=comp;
					return;
				}
				if(a[1][1]==a[0][2]&&a[2][0]!=player)
				{
					a[2][0]=comp;
					return;
				}
		}
	}
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(a[i][j]=='-')
					{
						a[i][j]=comp;
						return;
					}
				}
			}
}

string ttt::condition()
{
	int flag=0;
	char x;
	for(int i=0;i<3;i++)
	{
			if(a[i][1]==a[i][0])
			{
				if(a[i][1]==a[i][2])
				{				
					flag=1;
					x=a[i][0];
					break;
				}
			}
			else if(a[0][i]==a[1][i])
			{
					if(a[1][i]==a[2][i])
					{				
						flag=1;
						x=a[0][i];
						break;
					}
			}
	}
	if(a[0][0]==a[1][1])
	{
			if(a[1][1]==a[2][2])
			{
				flag=1;
				x=a[0][0];
			}
	}
	else if(a[0][2]==a[1][1])
	{
		if(a[1][1]==a[2][0])
		{
			flag=1;
			x=a[2][0];
		}
	}
	if(flag==1)
	{
		if(x==player)
			winner=name;
		else if(x==comp)
			winner="BOT";
	}
	return winner;
}
