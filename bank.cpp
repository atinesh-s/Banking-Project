#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
int flag=0,count;
char ch;
FILE *fp,*fpt,*ft;
void load(int l)
 {
  clrscr();
  textcolor(6+128);
  cprintf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                        Loading Please Wait");
  for(int i=1;i<=7;i++)
   {
    delay(l);
    cout<<" .";
   }
  textcolor(11);
  clrscr();
 }
class bank
{
 int act_no;
 char cust_name[10];
 public:
 void get()
  {
   flag=0;
   cout<<"\nEnter Customer's Act. No. and Name :\n";
   cin>>act_no>>cust_name;
   fp=fopen("bankpro.txt","a+");
   ft=fopen("bankpro.txt","r");
    if(ft==NULL)
	{
	cout<<"\nUnable To Locate The File";
	}
   int cano;
   while(fscanf(ft,"%5d",&cano)!=EOF)
    {
       if(act_no==cano)
	{
	 flag=1;
	 cout<<"\nThis Account No. Is Already Registered Try Another One";
	 break;
	}
       fseek(ft,20,1);
    }
   if(flag!=1)
    fprintf(fp,"\n%5d%10s",act_no,cust_name);
  }
 void show()
  {
   cout<<"\n%%%Congratulation Account Created Successfully%%%\n";
   cout<<"\nAccount No. = "<<act_no<<"\nName = "<<cust_name;
  }
};
class saving : bank
{
 protected:
 int sav_amt;
 public:
 saving()
  {
   sav_amt=1000;
  }
 void get()
  {
   bank::get();
   if(flag!=1)
     {
      fprintf(fp,"%5s%5d","S",sav_amt);
      fclose(fp);
     }	
  }
 void show()
  {
   bank::show();
   cout<<"\nMain Balance = "<<sav_amt;
  }
};
class current : bank
{
 protected:
 int cur_amt;
 public:
  current()
  {
   cur_amt=0;
  }
  void get()
  {
   bank::get();
   if(flag!=1)
     {
      fprintf(fp,"%5s%5d","C",cur_amt);
      fclose(fp);	
     }
  }
 void show()
  {
   bank::show();
   cout<<"\nMain Balance = "<<cur_amt;
  }
};
void main()
{
 clrscr();
 load(500);
 clrscr();
 do
  {
   int cano,camt,actno;
   char cname[10],ctype[5];
   textcolor(9);cprintf("\n   $$$$ ");textcolor(14);cprintf("WELCOME TO THE ATI BANK");textcolor(9);cprintf(" $$$$");
   cout<<"\n\n\t";textcolor(2+128);cprintf("[1]");cout<<" Open Account";
   cout<<"\n\n\t";cprintf("[2]");cout<<" Update Account";
   cout<<"\n\n\t";cprintf("[3]");cout<<" Registered Users";
   cout<<"\n\n\t";cprintf("[4]");cout<<" Sorted List";
   cout<<"\n\n\t";cprintf("[5]");cout<<" Search";
   cout<<"\n\n\t";cprintf("[6]");cout<<" Encrypt The Data";
   cout<<"\n\n\t";cprintf("[7]");cout<<" See The Encrypted Data";
   cout<<"\n\n\t";cprintf("[8]");cout<<" Close Account";
   cout<<"\n\n\t";cprintf("[e]");cout<<" EXIT";
   cout<<"\n\n\n\tEnter Your Choice :\n";
   cout<<"\t";
   ch=getche();
   switch(ch)
    {
     case '1':load(250);
	      do
	       {
		cout<<"\n\t";textcolor(2+128);cprintf("[a]");cout<<" Append Account";
			cout<<"\n\t";cprintf("[i]");cout<<" Insert Account";
			cout<<"\n\t";cprintf("[p]");cout<<" Previous Menu";
			cout<<"\n\n\tEnter Your Choice :\n";
			cout<<"\t";
			ch=getche();
			switch(ch)
			{
			  case 'a':	cout<<"\n\t";textcolor(2+128);cprintf("[s]");cout<<" Saving Account";
				cout<<"\n\t";cprintf("[c]");cout<<" Current Account";
				cout<<"\n\t";cprintf("[p]");cout<<" Previous Menu";
				cout<<"\n\n\tEnter Your Choice :\n";
				cout<<"\t";
				ch=getche();
				switch(ch)
			 	 {
				  case 's':saving s1;
					s1.get();
					if(flag==0)
					s1.show();
					break;
				  case 'c':current c1;
					c1.get();
			   		if(flag==0)
			    		c1.show();
			   		break;
		  		  case 'p':break;
		 		}				
				   break;
			  case 'i':fp=fopen("bankpro.txt","r");
	      			if(fp==NULL)
	       			{
				cout<<"Unable To Locate The File";
				return;
	       			}
	      			fpt=fopen("temp.txt","a+");
				flag=0;
	      			int anum;
	      			cout<<"\nEnter The Account No. After Which You Want To Open The Account :\n";
	      			cin>>anum;
	      			while(fscanf(fp,"%5d%10s%5s%5d",&cano,cname,ctype,&camt)!=EOF)
	       			{
				fprintf(fpt,"\n%5d%10s%5s%5d",cano,cname,ctype,camt);
				if(cano==anum)
		 			{
					flag=1;
		     			do
					 {
					 cout<<"\n\t";textcolor(2+128);cprintf("[s]");cout<<" Saving Account";
					 cout<<"\n\t";cprintf("[c]");cout<<" Current Account";
					 cout<<"\n\t";cprintf("[p]");cout<<" Previous Menu";
					 cout<<"\n\n\tEnter Your Choice :\n";
					 cout<<"\t";
					 ch=getche();
					int cno;
					 switch(ch)
					  {
			  		  case 's':cout<<"\nEnter Customer's Act. No. and Name :\n";
						cin>>cano>>cname;
						ft=fopen("bankpro.txt","r");
						if(ft==NULL)
						{
						  cout<<"\nUnable To Locate The File";
						}
						   while(fscanf(ft,"%5d",&cno)!=EOF)
    							{
       							       if(cno==cano)
								{
	 							flag=2;
	 							break;
								}
       							       fseek(ft,20,1);
    							}
						if(flag!=2)
						  {
						    fprintf(fpt,"\n%5d%10s%5s%5s",cano,cname,"S","1000");
						    cout<<"\n%%%Congratulation Account Created Successfully%%%\n";
   						    cout<<"\nAccount No. = "<<cano<<"\nName = "<<cname;
						  }
				   		break;
			  		  case 'c':cout<<"\nEnter Customer's Act. No. and Name :\n";
						cin>>cano>>cname;
						ft=fopen("bankpro.txt","r");
						if(ft==NULL)
						{
						  cout<<"\nUnable To Locate The File";
						}
						   while(fscanf(ft,"%5d",&cno)!=EOF)
    							{
							if(cno==cano)
								{
	 							flag=2;
								cout<<"\nThis Account No. Is Already Registered Try Another One";
	 							break;
								}
       							       fseek(ft,20,1);
    							}
						if(flag!=2)
						  {
						    fprintf(fpt,"\n%5d%10s%5s%5s",cano,cname,"C","0");
						    cout<<"\n%%%Congratulation Account Created Successfully%%%\n";
   						    cout<<"\nAccount No. = "<<cano<<"\nName = "<<cname;
						  }
				   		break;
			  		  case 'p':break;
					  }
			 		}while(ch!='p');
		             		}
	      		 }
			fclose(fp);
			fclose(fpt);	
			remove("bankpro.txt");
			rename("temp.txt","bankpro.txt");
	      		if(flag==0)
	       		  cout<<"\nAccount No. Is Not Valid";
	      		else if(flag==2)
	       		  cout<<"";
			else
			  cout<<"\nAccount Inserted Successfully!!!";	
				   break;
			  case 'p':break;
			}
		 textcolor(11);
	       }while(ch!='p');
	       break;
     case '2':load(250);
	      int mamt,amt;
	      fp=fopen("bankpro.txt","r+");
	      if(fp==NULL)
	       {
		cout<<"\nUnable To Locate The File";
		return;
	       }
	      cout<<"\nEnter The Account No. :\n";
	      cin>>actno;
	      flag=0;
	      while(fscanf(fp,"%5d",&cano)!=EOF)
		  {
		   if(actno==cano)
		    {
		     flag=1;
		     fscanf(fp,"%10s",cname);
		     break;
		    }
		   fseek(fp,20,1);
		  }
		if(flag==0)
		 cout<<"\nNo Such Account Exist";
		else
		 {
		     cout<<"\nRecord Found";
		     cout<<"\nName = "<<cname;
		     cout<<"\n\n\tWhat Do You Want To Do";
		     do
			{
			 cout<<"\n\t";textcolor(2+128);cprintf("[d]");cout<<"Deposit";
			 cout<<"\n\t";cprintf("[w]");cout<<"Withdrawl";
			 cout<<"\n\t";cprintf("[p]");cout<<"Previous Menu";
			 cout<<"\n\n\tEnter Your Choice :\n";
			 cout<<"\t";
			 ch=getche();
			  switch(ch)
			   {
			    case 'd':fseek(fp,5,1);
				     cout<<"\nEnter The Deposit Amount :\n";
				     cin>>amt;
				     if(amt>5000)
				       cout<<"\nDeposit Amount Should Be Less Than 5000";
				     else
				      {
				       fscanf(fp,"%5d",&mamt);
				       mamt=mamt+amt;
				       fseek(fp,-5,1);
				       fprintf(fp,"%5d",mamt);
				       cout<<"\nAccount Updated";
				      }
				     break;
			    case 'w':fseek(fp,5,1);
				     cout<<"\nEnter The Withdrawal Amount :\n";
				     cin>>amt;
				     fscanf(fp,"%5d",&mamt);
				     fseek(fp,-5,1);
				     if(amt>mamt)
				      cout<<"You Can't Make Withdrawal Because Your Main Balance Is Less";
				     else
				      {
				       fscanf(fp,"%5d",&mamt);
				       mamt=mamt-amt;
				       fseek(fp,-5,1);
				       fprintf(fp,"%5d",mamt);
				       cout<<"\nAccount Updated";
				      }
				     break;
			    case 'p':
				     break;
			   }
		     }while(ch!='p');
		 }
		fclose(fp);
		textcolor(11);
	       break;
     case '3':load(250);
	      fp=fopen("bankpro.txt","r");
	      if(fp==NULL)
	       {
		cout<<"\nUnable To Locate The File";
		return;
	       }
	      do
	      {
	       cout<<"\n\t";textcolor(2+128);cprintf("[s]");cout<<" Users Having Saving Type Account";
	       cout<<"\n\t";cprintf("[c]");cout<<" Users Having Current Type Account";
	       cout<<"\n\t";cprintf("[b]");cout<<" Both";
	       cout<<"\n\t";cprintf("[p]");cout<<" Previous Menu";
	       cout<<"\n\n\tEnter Your Choice :\n";
	       cout<<"\t";
	       ch=getche();
	       switch(ch)
		{
		 case 's':count=0;
			  while(fscanf(fp,"%5d%10s%5s%5d",&cano,cname,ctype,&camt)!=EOF)
			   {
			    if(!strcmp(ctype,"S"))
			     {
			     cout<<"\n\tAccount No. :"<<cano<<" Name :";printf("%10s",cname);cout<<" Account Type :"<<ctype<<" Balance :"<<camt<<"\n";
			     count++;
			     }
			   }
			  cout<<"\n\n\tTotal No. Of Users Having Saving Type Account = "<<count;
			  fclose(fp);
			  break;
		 case 'c':count=0;
			  while(fscanf(fp,"%5d%10s%5s%5d",&cano,cname,ctype,&camt)!=EOF)
			   {
			    if(!strcmp(ctype,"C"))
			     {
			     cout<<"\n\tAccount No. :"<<cano<<" Name :";printf("%10s",cname);cout<<" Account Type :"<<ctype<<" Balance :"<<camt<<"\n";
			     count++;
			     }
			   }
			  cout<<"\n\n\tTotal No. Of Users Having Current Type Account = "<<count;
			  fclose(fp);
			  break;
		 case 'b':count=0;
			  while(fscanf(fp,"%5d%10s%5s%5d",&cano,cname,ctype,&camt)!=EOF)
			   {
			   cout<<"\n\tAccount No. :"<<cano<<" Name :";printf("%10s",cname);cout<<" Account Type :"<<ctype<<" Balance :"<<camt<<"\n";
			   count++;
			   }
			  cout<<"\n\n\tTotal No. Of Users = "<<count;
			  fclose(fp);
			  break;
		 case 'p':
			  break;
		}
	       textcolor(11);
	      }while(ch=='p');
		break;
     case '4':load(250);
	      struct temp
	       {
		int ano,amt;
		char name[10],type[5];
	       };
	      struct temp *p;
	      int i=0,t,u,c;
	      fp=fopen("bankpro.txt","r");
	      if(fp==NULL)
	       {
		cout<<"\nUnable To Locate The File";
		return;
	       }
	      while(fscanf(fp,"%5d%10s%5s%5d)",&cano,cname,ctype,&camt)!=EOF)
	       {
		(p+i)->ano=cano;
		strcpy((p+i)->name,cname);
		strcpy((p+i)->type,ctype);
		(p+i)->amt=camt;
		i++;
	       }
	      for(t=0;t<i;t++)
	       {
		for(u=t+1;u<i;u++)
		 {
		  c=strcmp((p+t)->name,(p+u)->name);
		  if(c>0)
		   {
		    struct temp *te;

		    te->ano=(p+t)->ano;
		    (p+t)->ano=(p+u)->ano;
		    (p+u)->ano=te->ano;

		    strcpy(te->name,(p+t)->name);
		    strcpy((p+t)->name,(p+u)->name);
		    strcpy((p+u)->name,te->name);

		    strcpy(te->type,(p+t)->type);
		    strcpy((p+t)->type,(p+u)->type);
		    strcpy((p+u)->type,te->type);

		    te->amt=(p+t)->amt;
		    (p+t)->amt=(p+u)->amt;
		    (p+u)->amt=te->amt;
		   }
		 }
	       }
	      for(t=0;t<i;t++)
	       {
		cout<<"\n"<<(p+t)->ano<<" ";printf("%10s",(p+t)->name);cout<<" "<<(p+t)->type<<" "<<(p+t)->amt;
	       }
	      fclose(fp);
	      break;
     case '5':load(250);
	      fp=fopen("bankpro.txt","r");
	      if(fp==NULL)
	       {
		cout<<"\nUnable To Locate The File";
		return;
	       }
		flag=0;
		cout<<"\nEnter The Users Account No. :\n";
		cin>>actno;
		while(fscanf(fp,"%5d",&cano)!=EOF)
		  {
		   if(actno==cano)
		    {
		     flag=1;
		     fscanf(fp,"%10s%5s%5d",cname,ctype,&camt);
		     cout<<"\nRecord Found";
		     cout<<"\n\nAccount No. :"<<cano<<" Name :"<<cname<<" Account Type :"<<ctype<<" Balance :"<<camt;
		     break;
		    }
		   fseek(fp,20,1);
		  }
		if(flag==0)
		 cout<<"\nNo Such Account Exist";
		fclose(fp);
		break;
     case '6':  load(250);
		fp=fopen("bankpro.txt","r");
		if(fp==NULL)
		 {
		  cout<<"\nUnable To Locate The File";
		  return;
		 }
		FILE *ft;
		ft=fopen("bankproe.txt","w");
		clrscr();
		while(ch!=EOF)
		 {
		  ch=getc(fp);
		  if(ch=='a')
			putc('!',ft);
		  else if(ch=='b')
			putc('@',ft);
		  else if(ch=='c')
			putc('#',ft);
		  else if(ch=='d')
			putc('$',ft);
		  else if(ch=='e')
			putc('%',ft);
		  else if(ch=='f')
			putc('^',ft);
		  else if(ch=='g')
			putc('&',ft);
		  else if(ch=='h')
			putc('*',ft);
		  else if(ch=='i')
			putc('(',ft);
		  else if(ch=='j')
			putc(')',ft);
		  else if(ch=='k')
			putc('-',ft);
		  else if(ch=='l')
			putc('+',ft);
		  else if(ch=='m')
			putc('_',ft);
		  else if(ch=='n')
			putc('=',ft);
		  else if(ch=='o')
			putc('1',ft);
		  else if(ch=='p')
			putc('2',ft);
		  else if(ch=='q')
			putc('3',ft);
		  else if(ch=='r')
			putc('4',ft);
		  else if(ch=='s')
			putc('5',ft);
		  else if(ch=='t')
			putc('6',ft);
		  else if(ch=='u')
			putc('7',ft);
		  else if(ch=='v')
			putc('8',ft);
		  else if(ch=='w')
			putc('9',ft);
		  else if(ch=='x')
			putc('0',ft);
		  else if(ch=='y')
			putc('~',ft);
		  else if(ch=='z')
			putc('?',ft);
		  else if(ch=='0')
			putc(';',ft);
		  else if(ch=='1')
			putc('s',ft);
		  else if(ch=='2')
			putc('f',ft);
		  else if(ch=='3')
			putc('<',ft);
		  else if(ch=='4')
			putc('"',ft);
		  else if(ch=='5')
			putc('{',ft);
		  else if(ch=='6')
			putc('|',ft);
		  else if(ch=='7')
			putc('n',ft);
		  else if(ch=='8')
			putc('e',ft);
		  else if(ch=='9')
			putc('z',ft);
		  else if(ch==32)
			putc(' ',ft);
		  else if(ch=='S')
			putc('g',ft);
		  else if(ch=='C')
			putc('v',ft);
		  else if(ch=='\n')
			putc('\n',ft);
		 }
		textcolor(6);
		cprintf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   Encrypting Data");
		textcolor(2);
		for(count=1;count<15;count++)
		 {
		  delay(300);
		  cprintf(" >");
		 }
		cout<<"\n";
		textcolor(11);
		cprintf("\n\n                   File Encrypted");
		fclose(ft);
		break;
     case '7':  load(250);
		fp=fopen("bankproe.txt","r");
		if(fp==NULL)
		 {
		  cout<<"\n\n\tUnable To Loacate The Encrypted File";
		  getch();
		  return;
		 }
		while(ch!=EOF)
		 {
		  ch=getc(fp);
		  if(ch=='!')
			cout<<'a';
		  else if(ch=='@')
			cout<<'b';
		  else if(ch=='#')
			cout<<'c';
		  else if(ch=='$')
			cout<<'d';
		  else if(ch=='%')
			cout<<'e';
		  else if(ch=='^')
			cout<<'f';
		  else if(ch=='&')
			cout<<'g';
		  else if(ch=='*')
			cout<<'h';
		  else if(ch=='(')
			cout<<'i';
		  else if(ch==')')
			cout<<'j';
		  else if(ch=='-')
			cout<<'k';
		  else if(ch=='+')
			cout<<'l';
		  else if(ch=='_')
			cout<<'m';
		  else if(ch=='=')
			cout<<'n';
		  else if(ch=='1')
			cout<<'o';
		  else if(ch=='2')
			cout<<'p';
		  else if(ch=='3')
			cout<<'q';
		  else if(ch=='4')
			cout<<'r';
		  else if(ch=='5')
			cout<<'s';
		  else if(ch=='6')
			cout<<'t';
		  else if(ch=='7')
			cout<<'u';
		  else if(ch=='8')
			cout<<'v';
		  else if(ch=='9')
			cout<<'w';
		  else if(ch=='0')
			cout<<'x';
		  else if(ch=='~')
			cout<<'y';
		  else if(ch=='?')
			cout<<'z';
		  else if(ch==';')
			cout<<'0';
		  else if(ch=='s')
			cout<<'1';
		  else if(ch=='f')
			cout<<'2';
		  else if(ch=='<')
			cout<<'3';
		  else if(ch=='"')
			cout<<'4';
		  else if(ch=='{')
			cout<<'5';
		  else if(ch=='|')
			cout<<'6';
		  else if(ch=='n')
			cout<<'7';
		  else if(ch=='e')
			cout<<'8';
		  else if(ch=='z')
			cout<<'9';
		  else if(ch==32)
			cout<<' ';
		  else if(ch=='g')
			cout<<'S';
		  else if(ch=='v')
			cout<<'C';
		  else if(ch=='\n')
			cout<<'\n';
		 }
		break;
     case '8':load(250);
	      fp=fopen("bankpro.txt","r");
	      if(fp==NULL)
	       {
		cout<<"\nUnable To Locate The File";
		return;
	       }
	      fpt=fopen("temp.txt","w");
	      cout<<"\nEnter The Account No. To Be Deleted :\n";
	      cin>>actno;
	      flag=0;
	      while(fscanf(fp,"%5d%10s%5s%5d",&cano,cname,ctype,&camt)!=EOF)
	       {
		if(actno!=cano)
		  fprintf(fpt,"\n%5d%10s%5s%5d",cano,cname,ctype,camt);
		else
		  flag=1;
	       }
	      if(flag==0)
	       cout<<"\nRecord Not Found";
	      else
	       cout<<"\nRecord Deleted";
	      fclose(fp);
	      fclose(fpt);
	      remove("bankpro.txt");
	      rename("temp.txt","bankpro.txt");
		break;
     case 'e':
		break;
    }
   cout<<"\n\n\tPress Any Key To Continue....";
   getch();
   clrscr();
  }while(ch!='e');
 getch();
}