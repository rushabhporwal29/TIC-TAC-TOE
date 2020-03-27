#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class tictactoe
{
    private: 
			string player1, player2;
    public: char a[3][3];
            int i,j;
            tictactoe()
            {
                player1="player1";
                player2="player2";
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        a[i][j]='-';
                    }
                }
            }
            void get();
            void play();
            void display();
            int check(char,char);

};
void tictactoe::get()
{
    cout<<"\n Enter Player 1 Name : ";
    cin>>player1;
    cout<<"\n Enter Player 2 Name : ";
    cin>>player2;
}
void tictactoe::display()
{
	cout<<"\n"<<"   "<<"0"<<"    "<<"1"<<"    "<<"2  ";
    for(i=0;i<3;i++)
    {
        cout<<"\n"<<i;
        for(j=0;j<3;j++)
        {
            cout<<"  "<<a[i][j]<<"  ";
        }
    }
}
void tictactoe::play()
{
    cout<<"\n NOTE : Player Should Enter The Position Where They Want To Place There Character ";
    char p1,p2;
    int r,c,ch,k=0;
    cout<<"\n Choose Your Characters:";
    cout<<"\n"<<player1<<" : ";
    cin>>p1;
    cout<<"\n"<<player2<<" : ";
    cin>>p2;
    system("CLS");
    cout<<"\n LET'S START THE GAME !!!!";
    display();
    do
    {
        cout<<"\n Enter The Positions ";
        cout<<"\n "<<player1<<" : ";
        cout<<"\n       Row Number :";
        cin>>r;
        cout<<"\n       Column Number :";
        cin>>c;
        a[r][c]=p1;
        display();
        ch=check(p1,p2);
        k++;
        cout<<"\n "<<player2<<" : ";
        cout<<"\n       Row Number :";
        cin>>r;
        cout<<"\n       Column Number :";
        cin>>c;
        a[r][c]=p2;
        display();
        ch=check(p1,p2);
        k++;
    }while(ch==1||k<9);
	if(k==9){cout<<"\n Match Is Tied !!!";};
    
}
int main()
{
    tictactoe t;
    t.get();
    t.play();
   // t.display();
   return 0;
}















int tictactoe::check(char p1,char p2)
{
    int flag=5,x=1;
    int j=0,b,c;
    for(i=0;i<3;i++)
    {
        b=a[i][0];
        for ( j = 0; j < 3; j++)
        {
            if(b==a[i][j])
            {
                flag=10;
                c=a[i][j];
            }
            else { flag=5;break;}
        }
        if(flag==10){break;}
    }
    if(flag==5)
    {
		for(i=0;i<3;i++)
	    {
	        b=a[0][i];
	        for ( j = 0; j < 3; j++)
	        {
	            if(b==a[j][i])
	            {
	                flag=10;
	                c=a[j][i];
	            }
	            else { flag=5;break;}
	        }
	        if(flag==10){break;}
	    }
	}
	if(flag==5)
	{
        b=a[0][0];
		for(i=0;i<3;i++)
        {
            if(b==a[i][i])
	            {
	                flag=10;
	                c=a[i][i];
	            }
	            else { flag=5;break;}
        }
    }
    if(flag==5)
	{
        b=a[0][2];
		for(i=0;i<3;i++)
        {
            if(b==a[i][2-i])
	            {
	                flag=10;
	                c=a[i][2-i];
	            }
	            else { flag=5;break;}
        }
    }

    if(flag==10)
    {
        if(c==p1){flag=1;}
        else if(c==p2){flag=0;} 
    }
    if(flag==1)
    {
        cout<<"\n "<<player1<<" is Winner. ";
        x=0;
    }
    else if (flag==0)
    {
        cout<<"\n "<<player2<<" is Winner. ";
        x=0;
    }
   return x;     
}
