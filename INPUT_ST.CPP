void input_str(int x,int y,int size,char *p)
{
	int z=0;
	int ct=0;
	char a;
	setfillstyle(1,0);
	while(z!=1)
	{
		a=getch();
		if(a==13)
		{
			p[ct]='\0';
			z++;
		}
		else
		if(a==8)   //back space
		{
			if(p[0]!='\0')
			{
				setcolor(0);
				bar3d(x,y,x+textwidth(p)+5,y+textheight(p)+5,0,0);
				ct--;
				p[ct]='\0';
			}
			else
				cout<<"\a";
		}
		else
		if(ct<=size)
		{
			p[ct]=a;
			ct++;
			p[ct]='\0';
		}
		else
			cout<<"\a";
		setcolor(0);
		bar3d(x,y,x+textwidth(p),y+textheight(p),0,0);
		setcolor(WHITE);
		settextstyle(3,0,2);
		outtextxy(x,y,p);
	}
}
