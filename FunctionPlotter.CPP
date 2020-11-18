#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<dos.h>
#include "z:input_st.cpp"

float slope=0,constant=0,dm=0.1,count=0,j=0,end=1,kama=0,minus_counter_of_m=0,x=0,y=0,xco=0,yco=0,minus_indicator_of_c=0;
int gd=DETECT,gmode,fam;
char inp_str[5];
float function_type=0;
float solution_x_coordinate[20],solution_y_coordinate[20];
float fam_slope[10],fam_constant[10],fam_y[10];
char funct[30],family[10][30],ch;
class function
{ protected:
  int flag,f,i,k,lb,mc,mnc,convert_first_root_value,xcounter,check,dc,quadfunct,minus_indicator_of_c,minus_counter_of_x_square;
  float vm,m,a,b,c,convertm,valuecounter,convert_constant_value,complex,c_quad,convertc,decivalue,roll,c_of_quad,y_coordinate,x_coordinate,finalx,finaly,firstroot,secondroot,convert_second_root_value;
 public:

 float slopecalculator(char funct[]);
 float constantcalculator(char funct[]);
 void initialize(void);
 void linearfunction(void);
 void quadraticfunction(void);
 float a_for_quad_calculator(char funct[]);
 float b_for_quad_calculator(char funct[]);
 float c_for_quad_calculator(char funct[]);
 void graphdisplay(void);
 void lineargraphplotter(float m,float c);
 void quadraticgraphplotter(float,float,float);

       function()
	{
		flag=1;
		f=1;j=i=k=mnc=count=roll=xcounter=m=c=x=y=a=b=mc=convertm=convertc=decivalue=dc=xco=yco=0;
		vm=0.1;convert_constant_value=0;c_quad=0;
		firstroot=quadfunct=valuecounter=c_of_quad=0;
		secondroot=0;
		c_quad=0;
		minus_indicator_of_c=0;
		 y_coordinate=0,x_coordinate=-15;
		 finalx=finaly=0;
		 minus_counter_of_x_square=0;
		 convert_second_root_value=0;
	}
 }start;
 class graphics : public function
 { int col,posx,posy,stch,stchcount;
	float bk;
  public:
  void bkcolour(void);
  void intro(void);
  void detail(void);
  void finish(void);

 }grph;

 void graphics :: intro(void)
 {
 initgraph(&gd,&gmode,"C:\\TC\\BGI");

  settextstyle(4,0,4);
  setcolor(WHITE);
  outtextxy(125,150,"WELCOME TO");
  settextstyle(3,0,4);
  outtextxy(50,250,"*****FUNCTY-FUNCT*****");
	getch();
  closegraph();
 }

 void graphics :: finish(void)
 {
  initgraph(&gd,&gmode,"C:\\TC\\BGI");

	for( col=0;col<=getmaxcolor();col++)
	  {
		  settextstyle(4,0,0);
		  setcolor(col);
		  outtextxy(125,200," Thank You for Choosing");
		  delay(200);
	  }
  getch();
  closegraph();
 }

 void graphics :: detail(void)
 {
  clrscr();
  initgraph(&gd,&gmode,"C:\\TC\\BGI");

  setcolor(GREEN);
  settextstyle(4,0,5);
  outtextxy(180,15,"WELCOME TO");
  settextstyle(3,0,5);
  outtextxy(100,70,"****Functy-Funct****");
  settextstyle(2,0,5);
  setcolor(WHITE);
  outtextxy(30,130,"This software has been developed to plot functions on graphs");
  outtextxy(400,150,"POWERED BY- Parinav.Tech");
  outtextxy(30,160,"Enter (1) to perform Linear Programming");
  outtextxy(30,180,"Enter (2) for Quadratic function of the type(y=ax^2+bx+c)");
  outtextxy(30,200,"Enter (3) for linear function of the type(y=mx+c)");
  outtextxy(30,220,"If you do not follow the specified instruction you might get absurd results");
  settextstyle(4,0,0);
  setcolor(GREEN);
  outtextxy(50,252,"Choice:");
  gotoxy(20,18);
  input_str(150,260,50,inp_str); //need to change to inp_str in all places

 closegraph();
 }
 class lineaprog: public function
 {
  int nfunct,eq,eqcheck,fc,fci,myc,g,fend,yfinder,ycounter,no_of_simultaneous_eq;
  char error_choice;
  public:
 lineaprog()
 {
 yfinder=myc=ycounter=error_choice=0;
 eqcheck=0;eq=1;
 }            //<----- constructor here
 void famoflines(void);
 void info_prog(void);
 void entry_error_display(void);
 void entry_error_check(void);
 void solution_set_detector(float fam_slope[10],float fam_constant[10],float fam_y[10],float solution_x_coordinate[20],float solution_y_coordinate[20]);
 float fam_slopecalculator(char family[10][30]);
 float fam_constantcalculator(char family[10][30]);
 float fam_b_calculator(char family[10][30]);
 void familygraphplotter(float fam_slope[],float fam_constant[]);
 }linea;

 class option : public lineaprog, public graphics
 {public:
  void descrp(void);
 }choice;

 void option :: descrp(void)
 {
 do
 {
   grph.initialize();
   grph.detail();
	if(inp_str[0]=='1')
	{
	 linea.famoflines();
	}
	if(inp_str[0]=='2')
	{
	start.quadraticfunction();
	}
	if(inp_str[0]=='3')
	{
	 start.linearfunction();
	}
	else
	break;
	initgraph(&gd,&gmode,"C:\\TC\\BGI");
	setcolor(GREEN);
	settextstyle(3,0,2);
	outtextxy(30,50," Do you want to enter any more functions?");
	outtextxy(40,70," Y(to continue) and N(to exit):");
	gotoxy(45,6);
	input_str(355,70,5,inp_str);
	closegraph();
    }while(inp_str[0]=='y'||inp_str[0]=='Y');

 }

 void lineaprog :: solution_set_detector(float fam_slope[10],float fam_constant[10],float fam_y[10],float solution_x_coordinate[20],float solution_y_coordinate[20])
 { int nf=nfunct,coordl=0;
 float fmslp1[10],fmct1[10],fmy1[10],fmslp2[10],fmct2[10],fmy2[10];
  int sl=1;
	 for(int gl=0;gl<10;gl++)
	  {
	   fmslp1[gl]=fmslp2[gl]=fam_slope[gl];
	   fmct1[gl]=fmct2[gl]=fam_constant[gl];
	   fmy1[gl]=fmy2[gl]=fam_y[gl];
	  }
	 for(int sol=0;sol<nfunct;++sol)
	  {
		  for(int bkc=0;sl<nf;bkc++,sl++,coordl++)
		    { fmslp1[sol]*=fam_slope[sl];      //values of slp,ct and y are changing, cannot be used for solving multiple simultaneous equations
		      fmslp2[sl]*=fam_slope[sol];
		      fmct1[sol]*=fam_slope[sl];
		      fmct2[sl]*=fam_slope[sol];
		      fmy1[sol]*=fam_slope[sl];
		      fmy2[sl]*=fam_slope[sol];
		       if(fmy1[sol]-fmy2[sl]==0)
		       { bkc++;
			 if(bkc>=3)
			 break;
			 else
			 {
			  coordl--;
			  continue;
			 }
		       }
		       else
		       {
			solution_y_coordinate[coordl]=(((-1)*fmct1[sol])+fmct2[sl])/(fmy1[sol]-fmy2[sl]);
			solution_x_coordinate[coordl]=((((-1)*fmct1[sol])-(fmy1[sol]*solution_y_coordinate[coordl]))/fmslp1[sol]);
			solution_x_coordinate[coordl]=319.5+(20*solution_x_coordinate[coordl]);
			solution_y_coordinate[coordl]=239.5-(20*solution_y_coordinate[coordl]);

		       for(int gl=0;gl<10;gl++)                    //changes made here
			 {
			   fmslp1[gl]=fmslp2[gl]=fam_slope[gl];
			   fmct1[gl]=fmct2[gl]=fam_constant[gl];
			   fmy1[gl]=fmy2[gl]=fam_y[gl];
			 }
		      }
		    }
		    sl--;
       }
  int point[20];
   int c_coordl=0;
  for(int pnt=0;pnt<2*coordl;pnt++,c_coordl++)
  {
    if(pnt%2==0)
    {
    point[pnt]=solution_x_coordinate[c_coordl];
    c_coordl--;
    }
    else
     point[pnt]=solution_y_coordinate[c_coordl];
  }
  point[pnt]=point[0];
  point[pnt+1]=point[1];
  setfillstyle(2,GREEN);
  fillpoly(coordl+1,point);
  getch();
 }

 void lineaprog :: entry_error_display(void)
 { cout<<"The Entered function does not have any inequality sign(s)\n"
       <<"Press (1) to edit or change the entered function\n"
       <<"Press (x) to exit\n";
   cin>>error_choice;
 }

 void lineaprog :: entry_error_check(void)
 {     for(eq=1;family[fc][eq]!='\0';eq++)
       { if(family[fc][eq]=='>'||family[fc][eq]=='<')
	 { eqcheck++;
	 }
       }
	if(eqcheck==0)
		 {
		 linea.entry_error_display();
		 }
	  eqcheck=0;
 }

 void lineaprog :: info_prog(void)
 {clrscr();
  cout<<"\n\nThis branch of the software enales you to perform linear programming on the\n graph"
       <<"\nThe Inequality must be converted to the simplest form, for eg:- {ax+by+c<=0}\n"
       <<"\nThe entered linear inequality must contain any of the following:-\n\n"
       <<"\t'<=' : {Less Than Equal To}\n\t'>=' : {Greater Than Equal To}\n\t'>'  : {Greater Than}\n\t'<'  : {Less Than}\n"
       <<"\n\nEnter the No. of function You would like to plot:";
   cin>>nfunct;
   cout<<"Enter the Functions:";
   gets(family[0]);linea.entry_error_check();
 }

 void lineaprog:: famoflines(void)
 {
   fam=1;
   linea.info_prog();
   for(fc=1;fc<nfunct;fc++)
   {
    cout<<"\t\t    ";gets(family[fc]); linea.entry_error_check();
    if(error_choice=='1')
    {
     fc--;error_choice='0';
     continue;
    }
    else if (error_choice=='x')
    {
     grph.finish();
     getch();
     exit(0);
    }
   }
    for(g=0;g<nfunct;g++)
 {start.initialize();
	for(end=1;family[g][end]!='>'&&family[g][end]!='<';end++)
	{}
	kama=end+2;
	family[g][kama]=family[g][end];
	end=end-1;
 if(family[g][0]=='-')
	{
	j++;myc++;
	if(family[g][j]=='x')
	fam_slope[g]=1;
	if(family[g][j]=='y')
	fam_y[g]=-1;
	}
 if(family[g][j]=='x')
 {fam_slope[g]=1;}
 if(family[g][j]=='y'||family[g][j+2]=='y')
 {fam_y[g]=1;}
 for(;family[g][j]!=family[g][kama];j++)
 {
  count++;
	if(family[g][j]==120)
	{
		fam_slope[g]+=linea.fam_slopecalculator(family);
		if(family[g][0]=='-')
		{
		 fam_slope[g]=(fam_slope[g]*(-1));
		}
	}
	if(family[g][j]=='+')
	{      for(int yfinder=j;family[g][yfinder]!='\0';yfinder++)
	      {  if(family[g][yfinder]==121)
		      {
			ycounter++;
			break;
		      }
	      }
	      if(ycounter!=0)
	      {
		fam_y[g]+=linea.fam_b_calculator(family);
	      }
	      if(ycounter==0)
	      {
	      fam_y[g]=0;
	      }
	      if(family[g][j]=='+')
	       {
	       fam_constant[g]+=linea.fam_constantcalculator(family);
	       }
			if(count<=j)
			{
			  count=j;
			}
			if(family[g][j]=='+')
			{
			fam_constant[g]=linea.fam_constantcalculator(family);
			}
			if(family[g][j]=='-')
			{
			 minus_indicator_of_c++;
			}

	     else if(family[g][j]=='-')
	     {fam_constant[g]-=linea.fam_constantcalculator(family);
			if(count<=j)
			{
			  count=j;
			}
			if(family[g][j]=='+')
			{
			fam_constant[g]=linea.fam_constantcalculator(family);
			}
			if(family[g][j]=='-')
			{
			 minus_indicator_of_c++;
			}

	     }
	}
	if(family[g][j]=='-')
	{   for(int yfinder=j;family[g][yfinder]!='\0';yfinder++)
	      {  if(family[g][yfinder]==121)
		      {
			ycounter=5;  //random number
			break;
		      }
	      }
	      if(ycounter==5)
	      {
		fam_y[g]-=linea.fam_b_calculator(family);
	      }
	      if(ycounter==0)
	      {
	      fam_y[g]=0;
	      }
		 if(family[g][j]=='+')
		  {
		  fam_constant[g]+=linea.fam_constantcalculator(family);
			 if(count<=j)
			  {
			  count=j;
			  }
			if(family[g][j]=='-')
			{
			fam_constant[g]+=linea.fam_constantcalculator(family);
			}
	  }
	  else if(family[g][j]=='-')
	  { fam_constant[g]-=linea.fam_constantcalculator(family);
		 if(count<=j)
			{
			  count=j;
			}
		 if(family[g][j]=='-')
		 {
		  fam_constant[g]-=linea.fam_constantcalculator(family);
		 }
	  }
	}
      }
 }
 start.graphdisplay();
 }
 float lineaprog :: fam_slopecalculator(char family[10][30])
 {
 vm=0.1;
    k=j-count+1;
	i=0;
	for(i;i<count-1;i++)
	{
		if(family[g][i]=='.')
		{for(dc=i;family[g][dc+1]!='x';)
		 {dc++;
		 decivalue+=((int)family[g][dc]-48)*dm;
		 if(decivalue==-4.8)
		 {decivalue=0;}
		 dm=dm/10;
		 }
		 break;
		}
		vm*=10;
	}
	if(dc!=0)
	{
	 count=count-dc; dc--;
	}
	i=0;
	m=0;
	for(;i<count-1;i++)
	{
	convertm=(int)family[g][i+k]-48;
	m+=(convertm*vm);
	vm=(vm/10);
	}       if(dc!=0)
		{
		 count=count+2;
		}
		j=j+1;
		clrscr();
		m+=decivalue;
		decivalue=0;
    return m;

 }

 float lineaprog :: fam_b_calculator(char family[10][30])
 { vm=0.1;
    k=j-count+3;
	if(count>=3)
    {count=count-2;
     k=k+count;
     valuecounter=count;
    }  count=1;
	i=0;
	dm=0.1;
	check=k;
	 for(;(family[g][check]!=family[g][kama])&&(family[g][check]!='y');check++)		       //for decimal 2.5x+5
	 {
	 if(family[g][check]=='.')
		{for(;family[g][check+1]!='y';)
		 {check++;
		 decivalue+=((int)family[g][check]-48)*dm;
		 if(decivalue==-4.8)
		 {decivalue=0;}
		 dm=dm/10;
		 }
		 break;
		}
		count++;
	 }

	for(i;i<count-1;i++)
	{
		vm*=10;
	}
	i=0;
	m=0;

	for(;i<count-1;i++)
	{
	convertm=(int)family[g][i+k]-48;
	m+=(convertm*vm);
	vm=(vm/10);
	}       if(dc!=0)
		{
		 count=count+2;
		 j=j+count+dc-1;
		}
		else
		{
		j=j+count+1;
		}
		clrscr();
		m+=decivalue;
		decivalue=0;
    return m;
 }
 float lineaprog :: fam_constantcalculator(char family[10][30])
 {               k=j-count+3;
    if(count>=3)
    {
     count=count-2;
     k=(k+count);
    }
    count=0;	vm=0.1;
    check=j;
     for(;(family[g][check]!=family[g][kama]);check++)
    {
     if(family[g][check]=='.')
		{
		 decivalue=((int)family[g][check+1]-48)*0.1;
		 dc++;continue;
		}
		count++;
	}
	check=k;
	for(i=0;i<count-1;i++)
	{
		if(family[g][check]=='.')
		{
		 decivalue=((int)family[g][check+1]-48)*0.1;
		 dc++;break;
		}
		vm*=10;
	}
    if(dc!=0)
    {
     j=j+1;
    }
     c=0;
	for(i=0;i<count-1;i++)
	{
		convertc=(int)family[g][i+k]-48;
		c+=(convertc*vm);
		vm=(vm/10);
	}
	 if(dc!=0)
		{
		 count=count+2;
		}
       j=j+3;
       c+=decivalue;
 return c;
 }

 void lineaprog :: familygraphplotter(float fam_slope[],float fam_constant[])
{
 for(g=0;g<nfunct;g++)
 {      start.initialize();
	x_coordinate=-16;roll=0;
	 if(fam_y[g]==0)
	  {
	   x_coordinate=(((-1)*fam_constant[g])/(fam_slope[g]));
	   y_coordinate=-16;
	   for(;roll<350;roll=roll+0.1)
	   {finalx=319.5+(20*x_coordinate);
	    finaly=239.5-(20*y_coordinate);
	    putpixel(finalx,finaly,GREEN);
	    y_coordinate=y_coordinate+0.01;
	    delay(1);
	   }
	  }
      else
      {
	for(;roll<350;roll=roll+0.1)
	{
	  y_coordinate=((-1)*((fam_slope[g]*x_coordinate)+fam_constant[g]))/(fam_y[g]);
	  finalx=319.5+(20*x_coordinate);
	  finaly=239.5-(20*y_coordinate);
	  putpixel(finalx,finaly,GREEN);
	  x_coordinate=x_coordinate+0.01;
	  delay(2);
	 }
       }
 }

 linea.solution_set_detector(fam_slope,fam_constant,fam_y,solution_x_coordinate,solution_y_coordinate);
 getch();
 closegraph();
 getch();
}
 void function :: initialize(void)
 {
  slope=0,constant=0,count=0,j=0,end=1,kama=0,function_type=0,minus_counter_of_m=0,x=0,y=0,xco=0,yco=0,minus_indicator_of_c=0;
  flag=1;
		f=1;j=i=k=mnc=count=roll=xcounter=m=c=x=y=a=b=mc=convertm=convertc=decivalue=dc=xco=yco=0;
		vm=0.1;convert_constant_value=0;c_quad=0;
		firstroot=quadfunct=valuecounter=c_of_quad=0;
		secondroot=0;
		c_quad=0;
		minus_indicator_of_c=0;
		 y_coordinate=0,x_coordinate=-15;
		 finalx=finaly=0;
		 minus_counter_of_x_square=0;
		 convert_second_root_value=0;
 }

 void function :: quadraticgraphplotter(float firstroot,float secondroot,float c_of_quad)
 {
 float ystart=0,xstart=-16;
 for(roll=0;roll<350;roll=roll+0.1)
 {
  y_coordinate=(firstroot*(x_coordinate*x_coordinate))+(secondroot*x_coordinate)+c_of_quad;
  finalx=319.5+(20*x_coordinate);
  finaly=239.5-(20*y_coordinate);
  putpixel(finalx,finaly,GREEN);
  x_coordinate=x_coordinate+0.01;
  delay(2);
 }
 getch();
 closegraph();
 getch();
 }

 void function :: graphdisplay(void)
 {
   clrscr();

 float yaxis=239.5,xaxis=319.5,max;

 initgraph(&gd,&gmode,"C:\\TC\\BGI");

 line(0,yaxis,639,yaxis);   //x axis 639 and y axis 479
 line(xaxis,0,xaxis,479);

 int pixel=314.5,pixely=238;
 // for axis
 putpixel(319.5,yaxis,RED); //centre co-ordinate of the graph is (319,240)
 settextstyle(2,0,3);
 outtextxy(311,yaxis,"(0,0)");
 outtextxy(xaxis+20,yaxis,"1");
 outtextxy(xaxis+40,yaxis,"2");
 outtextxy(xaxis+60,yaxis,"3");
 outtextxy(xaxis+80,yaxis,"4");
 outtextxy(xaxis+100,yaxis,"5");
 outtextxy(xaxis+120,yaxis,"6");
 outtextxy(xaxis+140,yaxis,"7");
 outtextxy(xaxis+160,yaxis,"8");
 outtextxy(xaxis+180,yaxis,"9");
 outtextxy(xaxis+200,yaxis,"10");
 outtextxy(xaxis+220,yaxis,"11");
 outtextxy(xaxis+240,yaxis,"12");
 outtextxy(xaxis+260,yaxis,"13");
 outtextxy(xaxis+280,yaxis,"14");
 outtextxy(xaxis+300,yaxis,"15");
 outtextxy(xaxis+320,yaxis,"16");

 outtextxy(xaxis-20,yaxis,"-1");
 outtextxy(xaxis-40,yaxis,"-2");
 outtextxy(xaxis-60,yaxis,"-3");
 outtextxy(xaxis-80,yaxis,"-4");
 outtextxy(xaxis-100,yaxis,"-5");
 outtextxy(xaxis-120,yaxis,"-6");
 outtextxy(xaxis-140,yaxis,"-7");
 outtextxy(xaxis-160,yaxis,"-8");
 outtextxy(xaxis-180,yaxis,"-9");
 outtextxy(xaxis-200,yaxis,"-10");
 outtextxy(xaxis-220,yaxis,"-11");
 outtextxy(xaxis-240,yaxis,"-12");
 outtextxy(xaxis-260,yaxis,"-13");
 outtextxy(xaxis-280,yaxis,"-14");
 outtextxy(xaxis-300,yaxis,"-15");
 outtextxy(xaxis-320,yaxis,"16");

 //for y-axis

 outtextxy(xaxis+2,yaxis-20,"1");
 outtextxy(xaxis+2,yaxis-40,"2");
 outtextxy(xaxis+2,yaxis-60,"3");
 outtextxy(xaxis+2,yaxis-80,"4");
 outtextxy(xaxis+2,yaxis-100,"5");
 outtextxy(xaxis+2,yaxis-120,"6");
 outtextxy(xaxis+2,yaxis-140,"7");
 outtextxy(xaxis+2,yaxis-160,"8");
 outtextxy(xaxis+2,yaxis-180,"9");
 outtextxy(xaxis+2,yaxis-200,"10");
 outtextxy(xaxis+2,yaxis-220,"11");
 outtextxy(xaxis+2,yaxis-240,"12");
 outtextxy(xaxis+2,yaxis-260,"13");
 outtextxy(xaxis+2,yaxis-280,"14");
 outtextxy(xaxis+2,yaxis-300,"15");
 outtextxy(xaxis+2,yaxis-320,"16");

 outtextxy(xaxis+2,yaxis+20,"-1");
 outtextxy(xaxis+2,yaxis+40,"-2");
 outtextxy(xaxis+2,yaxis+60,"-3");
 outtextxy(xaxis+2,yaxis+80,"-4");
 outtextxy(xaxis+2,yaxis+100,"-5");
 outtextxy(xaxis+2,yaxis+120,"-6");
 outtextxy(xaxis+2,yaxis+140,"-7");
 outtextxy(xaxis+2,yaxis+160,"-8");
 outtextxy(xaxis+2,yaxis+180,"-9");
 outtextxy(xaxis+2,yaxis+200,"-10");
 outtextxy(xaxis+2,yaxis+220,"-11");
 outtextxy(xaxis+2,yaxis+240,"-12");
 outtextxy(xaxis+2,yaxis+260,"-13");
 outtextxy(xaxis+2,yaxis+280,"-14");
 outtextxy(xaxis+2,yaxis+300,"-15");
 outtextxy(xaxis+2,yaxis+320,"-16");


	if(quadfunct!=0)
	{
	  start.quadraticgraphplotter(firstroot,secondroot,c_of_quad);
	}
		 else if(fam==1)
	 {
	  linea.familygraphplotter(fam_slope,fam_constant);
	 }
	 else if(fam==0)
	 {
	   start.lineargraphplotter(slope,constant);
	 }
	 fam=0;
 }

 void function:: quadraticfunction(void)
{
 clrscr();
 cout<<"\t\n\n\n\n\n\n\n\n\n\nEnter the Function: y=";
   gets(funct);
   quadfunct++;
   j=0;count=0;end=1;
   for(end; funct[end]!='\0';end++)
 {}
 kama=end+2;
 funct[kama]=funct[end];
 end=end-1;
 if(funct[0]=='-')
	{
		j++;mnc++;
		if(funct[1]=='x'&&funct[2]=='^'&&funct[3]=='2')
		{
		 firstroot=-1;
		}
		minus_counter_of_x_square++;
	}

	 if(funct[0]=='x'&&funct[1]=='^'&&funct[2]=='2')
	 {
	  firstroot=1;
	 }
	 else if(funct[0]=='x'&&funct[1]=='\0')
	 {
	  secondroot=1;
	}
 for(;funct[j]!='\0'||funct[j]!=funct[kama];j++)
 {
  count++;
	if(funct[j]==120&&funct[j+1]==94&&funct[j+2]=='2')
	{
		firstroot+=start.a_for_quad_calculator(funct);
		if(funct[0]=='-')
		{
		 firstroot=(firstroot*(-1));
		}
	}
	if(funct[j]=='+')
	{     for(int xfinder=j;funct[xfinder]!='\0';xfinder++)
	      {  if(funct[xfinder]==120)
		      {
			xcounter++;
			break;
		      }
	      }
	      if(xcounter!=0)
	      {
		secondroot+=start.b_for_quad_calculator(funct);
		xcounter=0;
	      }
		if(xcounter==0)
		{ if(funct[j]=='+')
			{
			  c_of_quad+=start.c_for_quad_calculator(funct);
			}
			else if(funct[j]=='-')
			{
			 c_of_quad-=start.c_for_quad_calculator(funct);
			 mc++;
			}
			if(count<=j)
			{
			  count=j;
			}

		   }
	}
	if(funct[j]=='-')
	{  xcounter=0;
	   for(int xfinder=j;funct[xfinder]!='\0';xfinder++)
	      {  if(funct[xfinder]==120)
		      {
			xcounter++;
		      }
	      }
	      if(xcounter!=0)
	      {
	       secondroot-=start.b_for_quad_calculator(funct);mc++;
	       xcounter=0;
	      }
	      if(xcounter==0)
	      { if(funct[j]=='+')
			{
			  c_of_quad+=start.c_for_quad_calculator(funct);
			}
			else if(funct[j]=='-')
			{
			 c_of_quad-=start.c_for_quad_calculator(funct);
			}
			if(count<=j)
			{
			  count=j;
			}

		   }
	}
 }
 complex=(secondroot*secondroot)-(4*(firstroot*c_of_quad));
 if(complex<0)
 { clrscr();
  cout<<"\n\n\n\t\t\tThe entered function has complex roots\n"
      <<"\nThus can't be plotted on the X-Y graph\n";
      getch();
      return;
 }
 start.graphdisplay();


}
float function :: a_for_quad_calculator(char funct[30])
{
	vm=0.1;
    k=j-count+1;
    i=0;
    if(mnc!=0)
    {
     i=i+1;
    }
	for(;i<count-1;i++)
	{
		if(funct[i]=='.')
		{
		 decivalue=((int)funct[i+1]-48)*0.1;
		 dc++;break;
			}
		vm*=10;
	}
	if(dc!=0)
	{
	 count=count-2;
	}
	for(i=0;i<count-1;i++)
	{
	convert_first_root_value=(int)funct[i+k]-48;
	a+=(convert_first_root_value*vm);
	vm=(vm/10);
	}       if(dc!=0)
		{
		 count=count+2;
		}
		j=j+3;
		clrscr();
		a+=decivalue;
		decivalue=0;
    return a;
}
float function :: b_for_quad_calculator(char funct[30])
{
	vm=0.1;
    k=j-count+3;
    if(count>=3)
    {count=count-2;
     k=k+count;
     valuecounter=count;
    }
    count=0;
    check=j;
    for(;(funct[check]!=funct[kama])&&(funct[check]!='x');check++)		       //for decimal 2.5x+5
    {
     if(funct[check]=='.')
		{
		 decivalue=((int)funct[check+1]-48)*0.1;
		 dc++;continue;
		}
		count++;
	}
    if(dc!=0)
    {
     j=j+2;
    }
       check=k;
	for(i=0;i<count-1;i++,check++)
	{
		if(funct[check]=='.')
		{
		 decivalue=((int)funct[check+1]-48)*0.1;
		 dc++;break;
		}
		vm*=10;
	}
	if(dc!=0)
	{
	 count=count-1;
	}
	for(i=0;i<count-1;i++)
	{
	convert_second_root_value=((int)funct[i+k]-48);
	b+=(convert_second_root_value*vm);
	vm=(vm/10);
	}
		j=j+count+1;
		clrscr();
		b+=decivalue;
		decivalue=0;
    return b;
}
float function :: c_for_quad_calculator(char funct[30])
{
	vm=0.1;
    k=j-count+3;
    if(count>=3)
    {
     count=count-2;
     k=(k+count);
    }
    if(dc!=0)
    {
     j=j+1;
    }
    count=0;
    check=j;
     for(;(funct[check]!=funct[kama]);check++)
    {
     if(funct[check]=='.')
		{
		 decivalue=((int)funct[check+1]-48)*0.1;
		 dc++;continue;
		}
		count++;
	}
	check=k;
	for(i=0;i<count-1;i++)
	{
		if(funct[check]=='.')
		{
		 decivalue=((int)funct[check+1]-48)*0.1;
		 dc++;break;
		}
		vm*=10;
	}
	for(i=0;i<count-1;i++)
	{
	convert_constant_value=(int)funct[i+k]-48;
	c_quad+=(convert_constant_value*vm);
	vm=(vm/10);
	}       if(dc!=0)
		{
		 count=count+2;
		}
		j=j+2;
		clrscr();
		c_quad+=decivalue;
		decivalue=0;
    return c_quad;
}
 float function :: slopecalculator(char funct[30])
{
	vm=0.1;
    k=j-count+1;
    if(quadfunct!=0)
    { j=j+2;
      k=k+2;
    }
	i=0;
	for(i;i<count-1;i++)
	{
		if(funct[i]=='.')
		{
		 decivalue=((int)funct[i+1]-48)*0.1;
		 dc++;
		 break;
		}
		vm*=10;
	}
	if(dc!=0)
	{
	 count=count-2;
	}
	i=0;
	for(;i<count-1;i++)
	{
	convertm=(int)funct[i+k]-48;
	m+=(convertm*vm);
	vm=(vm/10);
	}       if(dc!=0)
		{
		 count=count+2;
		}
		j=j+1;
		clrscr();
		m+=decivalue;
		decivalue=0;
    return m;
 }
 float function :: constantcalculator(char funct[30])
 {
		 j=count+1;

		if(minus_counter_of_m!=0)
		{
		 j++;
		}
		count=0;	vm=0.1;

	check=j;
      for(;(funct[check]!=funct[kama])&&(funct[check]!='+')&&(funct[check]!='-');check++)
	{       if(funct[check]=='.')
		{
		 decivalue=((int)funct[check+1]-48)*0.1;
		 dc++;break;
		}
		count++;
	}

    k=j;
    if(dc!=0)
    {
     j=j+1;
    }
     c=0;

	for(i=0;i<count;i++)
	{
		vm*=10;
	}
	for(i=0;i<count;i++)
	{
		convertc=(int)funct[i+k]-48;
		c+=(convertc*vm);
		vm=(vm/10);
	}

       j=j+2;
       c+=decivalue;
 return c;
 }

void function :: lineargraphplotter(float m,float c)
{
 float ystart=0,xstart=-16;
 for(roll=0;roll<350;roll=roll+0.1)
 {
  y_coordinate=(slope*x_coordinate)+constant;
  finalx=319.5+(20*x_coordinate);
  finaly=239.5-(20*y_coordinate);
  putpixel(finalx,finaly,GREEN);
  x_coordinate=x_coordinate+0.01;
  delay(2);
 }
 getch();
 closegraph();
 getch();
}

void function::linearfunction()
{
clrscr();
 cout<<"\t\n\n\n\n\n\n\n\n\n\nEnter the Function: y=";
   gets(funct);

  for(end; funct[end]!='\0';end++)
 {}
 kama=end+2;
 funct[kama]=funct[end];
 end=end-1;
 if(funct[0]=='-')
	{
	j++;
	minus_counter_of_m++;
	}
 if(funct[0]=='x')
 {
  slope=1;
 }

 for(;funct[j]!='\0'||funct[j]!=funct[kama];j++)
 {
  count++;
	if(funct[j]==120)
	{
		slope+=start.slopecalculator(funct);
		if(funct[0]=='-')
		{
		 slope=(slope*(-1));
		}
	}

	if(funct[j]=='+')
	{
		constant+=start.constantcalculator(funct);
			if(count<=j)
			{
			  count=j;
			}
			if(funct[j]=='+')
			{
			constant=start.constantcalculator(funct);
			}
			if(funct[j]='-')
			{
			 minus_indicator_of_c++;
			}
	}
	if(funct[j]=='-')
	{
	  constant-=start.constantcalculator(funct);
		 if(count<=j)
			{
			  count=j;
			}
		 if(funct[j]=='-')
		 {
		  constant+=start.constantcalculator(funct);
		 }
		 if(funct[j]=='+')
		 {
		  slope+=start.slopecalculator(funct);
		 }
	}
 }

 start.graphdisplay();
}

void main()
{
clrscr();
choice.descrp();
grph.finish();
getch();
}
