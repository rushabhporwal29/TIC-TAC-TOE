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
	if(a[1][1]=='-')
	{
		a[1][1]=comp;
	}
	else if(a[0][0]=='-')
	{
		a[0][0]=comp;
	}
	else if(a[2][2]=='-')
	{
		a[2][2]=comp;
	}
	else if(a[0][2]=='-')
	{
		a[0][2]=comp;
	}
	else if(a[2][0]=='-')
	{
		a[2][0]=comp;
	}
	else if(a[0][1]=='-')
	{
		a[0][1]=comp;
	}
	else if(a[1][0]=='-')
	{
		a[1][0]=comp;
	}
	else if(a[1][2]=='-')
	{
		a[1][2]=comp;
	}
	else
		a[2][1]=comp;
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
