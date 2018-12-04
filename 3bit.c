#include<stdio.h>                           
#include<stdlib.h>
#include<string.h>

typedef struct cList {
 char *concept; // the concept learned
 char *sentence; // the sentence associated with the concept
 int timesUsed; //no of times the concept was used to an answer
 char learnedFrom[5]; //learned either from "file" or "kbrd"
 struct cList *next;
 char *mikra;
} conceptList;

int check(char *rar, char *lol);//rar to current sent, lol h leksi pou psaxnw
void dltlst();
int checkfor(char *thn);
void epiloges(int n, char *tkn);
int checkinfo(char *thnk);
int checksent(char *vle);
conceptList *head,*ged,*nxt;
int ii=0;
FILE *f;

int main(void)
{	
	srand((unsigned) time(NULL));
	FILE *fp;
	conceptList *nee,*tmp,*pmt,*pee;
	int i,ext=0,dynanslen,o=0,k=0,l=0,opa;
	char ans[100];
	const char s[2] = ">:";
	char *token,*value,*yy,*dynans,*ret,*meme,*rat;
	do   
 	{
 		opa=0;
 		nee= (conceptList *) malloc(sizeof(conceptList));
 		if(nee!=NULL)
 		{
 			opa++;	
		}
 	}while(opa==0);
	f=fopen("file.txt","w");
do
{
	printf("Say something or leave me alone\n");
	fprintf(f,"Say something or leave me alone\n");
	gets(ans);//learn this > 
	fprintf(f,ans);
	i=0;
	/*while(ans[i]) 
    {
      ans[i]=tolower(ans[i]); //maLAKAs malakas
      i++;
    } */
	dynanslen=strlen(ans)+1;
	do
 	{
 		opa=0;
 		dynans=(char *)malloc(dynanslen*sizeof(char));
 		if(dynans!=NULL)
 		{
 			opa++;	
		}
 	}while(opa==0);
	
    strcpy(dynans,ans);
	token=strtok(dynans,">:");
	if(strcmp(token,"learn this ")==0)
	{
		token=strtok(NULL,s);
		if(ii==0)
		{
			epiloges(1,token);
			head= (conceptList *) malloc(sizeof(conceptList));			
			ii++;//*otan einai 1 
			head->concept=strdup(token);
			token=strtok(NULL,s);
			head->sentence=strdup(token);
			nee->next=head;
			strcpy(head->learnedFrom,"kbrt");
			head->timesUsed=0;			
		}
		else
		{
			if(checkinfo(token)==1)
			{
				ii++;//otan matheni kt
				ged= (conceptList *) malloc(sizeof(conceptList));
				ged->next=head;
				nee->next->next=ged;
				nee->next=ged;			
				ged->concept=strdup(token);
				token=strtok(NULL,s);
				ged->sentence=strdup(token);
				strcpy(ged->learnedFrom,"kbrt");
				ged->timesUsed=0;
			}
		}			
	}
	else if (strcmp(token,"forget this ")==0)
	{
		token=strtok(NULL,",");
		while(token!=NULL)
		{
			checkfor(token);
			token=strtok(NULL,",");
		}	
	}
	else if(strcmp(token,"What do you talk about?")==0)
	{
		tmp=head;
		do
		{
			if(tmp->timesUsed>0)
			{
				printf("consept:%s times used:%d",tmp->concept,tmp->timesUsed);
			}
			if(head->next==NULL)
			{
				o=1;
			}
			else tmp=tmp->next;
		}while(tmp->next!=head || o==1);
	}
	else if(strcmp(token,"read this ")==0)
	{
		token=strtok(NULL,s);
		fp = fopen (token, "r");
		if (!fp) 
		{
			printf("Coudnt open that file (%s)\n",token);
			fprintf(f,"Coudnt open that file (%s)\n",token);
		}
 		else 
		 {
		 	char line [1200];
		 	printf("\"%s\" opened successfully\n",token); 
		 	while (fgets (line, sizeof line, fp) != NULL) /* read a line */
		 	{
		 		yy=strdup(line);
		 		value=strtok(yy,":");
			if(ii==0)
			{	
				epiloges(1,value);
				head= (conceptList *) malloc(sizeof(conceptList));			
				ii++;//ii=1
				head->concept=strdup(value);
				value=strtok(NULL,"@");
				head->sentence=strdup(value);
				nee->next=head;
				strcpy(head->learnedFrom,"file");
				head->timesUsed=0;		
			}
			else 
			{
				if(checkinfo(value)==1)
				{
					ii++;//otan matheni kt
					ged= (conceptList *) malloc(sizeof(conceptList));
					ged->next=head;
					nee->next->next=ged;
					nee->next=ged;			
					ged->concept=strdup(value);
					value=strtok(NULL,"@");
					ged->sentence=strdup(value);
					strcpy(ged->learnedFrom,"file");
					ged->timesUsed=0;
				}
			}	
			}
			fclose(fp);
		 }
	}
	else if(strcmp(token,"What do you know about?")==0)
	{
		tmp=head;
		if(tmp==NULL)
		{
			printf( "I Don't Know ANYTHING XD.\n" );
		}
		else
		{
			while(tmp->next!=head)
			{
				printf("consept:%s\n",tmp->concept);
				tmp=tmp->next;
				if(tmp->next==head)
				{
					printf("consept:%s\n",tmp->concept);
				}
			}
		}
	}
	else if (strcmp(token,"What is the meaning of Life, The Universe, and Everything?")==0)
	{
		printf("42\n");
	}
	else if(strcmp(token,"So Long, and Thanks for All the Fish")==0)
	{
		printf("Ciao ciao human\n");
		fprintf(f,"\nCiao ciao human\n");
		dltlst();	//free strct
		fclose(f);
		ext=1;
	}	
	else //dialogos
	{
		ret=strchr(dynans,'?');//h leksh pou psaxnw
		ret=strchr(dynans,'*');
		if(ret==NULL || ret==NULL)//ama den exei ? tha mpei
		{
			epiloges(3,token);
		}
		else
		{	
			ret=strchr(token,'*');
			ret=strtok(ret,"*");//to concept pou psaxnoume
			if(k==0)
			{
				pmt=head;
				pee=head;
				k++;
			}
			else
			{
				pee=pmt;
			}
			l=0;//gia t brake tou do-while
			i=0;
			do
			{
				if(strcmp(ret,pmt->concept)==0)
				{
					printf("%s\n",pmt->sentence);
					pmt->timesUsed++;
					l=1;
				}
				else if(pee==pmt && i!=0)
				{
					l=2;
				}
				else
				{ 
					pmt=pmt->next; 
				}
				i++;
			}while(l<=0);
			if(l==2)//trekse 2h fora t lista sta sentense
			{
				i=0;
				l=0;
				do
				{
					meme=strdup(pmt->sentence);
					
					if(check(ret,meme)==1) ///pmt->timesused
					{
						printf("%s\n",pmt->sentence);
						pmt->timesUsed++;
						l++;
					}
					else if(pee==pmt && i!=0)
					{
						epiloges(4,ret);
						l=2;					
					}
					else pmt=pmt->next;
					i++;
				}while(l<=0);
			}
		}
	}
	free(dynans);
	
	
}while(ext!=1);
return 0;
}

int checkinfo(char *thnk)//to kserw h oxi
{
	int i,x;
	conceptList *tst;
	tst=head;
	for(i=0;;i++)
	{
		if(strcmp(tst->concept,thnk)==0)
		{
			epiloges(0,thnk);		
			return 0;
		}
		if(i!=0 && tst==head)
		{
			epiloges(1,thnk);
			return 1;
		}
		if(i==0 && head->next==NULL)
		{
			epiloges(1,thnk);
			return 1;
		}
	tst=tst->next;
	}	
}
void epiloges(int n, char *tkn)//ti apantah o 3b ?????
{
	int x=10; 
	if(	n==0)//i know
	{
		x=rand() % 4;
		if(x==0)
		{
			printf("You think i dnt know about %s ... pls\n", tkn);
			fprintf(f,"\nYou think i dnt know about %s ... pls\n", tkn);
		}		
		else if(x==1)
		{ 
			printf("I already know about %s be more interesting!!\n", tkn);
			fprintf(f,"\nI already know about %s be more interesting!!\n", tkn);
	 	}
		else if(x==2)
		{
			printf(" %s I have this info myself <<Teach meeee>>\n", tkn);
			fprintf(f,"\n %s I have this info myself <<Teach meeee>>\n", tkn);
		}
		else if(x==3)
		{
			printf("HAHA i know about %s kid.\n", tkn);
			fprintf(f,"\nHAHA i know about %s kid.\n", tkn);
		}
		else if(x==4)
		{
			printf("I FKING KNOW ABOUT %s STOP BOTHERING ME\n", tkn);
			fprintf(f,"\nI FKING KNOW ABOUT %s STOP BOTHERING ME\n", tkn);
		}
	}
	else if(n==1)//i learn
	{
		x=rand() % 4;
		if(x==0)
		{
			printf("I learnd about %s !\n",tkn);
			fprintf(f,"\nI learnd about %s !\n", tkn);
		}
		else if(x==1)
		{
			printf("You taught me about %s !\n", tkn);
			fprintf(f,"\nYou taught me about %s !\n", tkn);
		}
		else if(x==2)
		{
			printf("Cool info about %s nice!\n", tkn);
			fprintf(f,"\nCool info about %s nice!\n", tkn);
		}
		else if(x==3)
		{
			printf("So interesting info about %s thanks!\n", tkn);
			fprintf(f,"\nSo interesting info about %s thanks!\n", tkn);
		}
		else if(x==4)
		{
			printf("Learn about %s checked!\n", tkn);
			fprintf(f,"\nLearn about %s checked!\n", tkn);
		}
	}
	else if(n==2)//i forgot
	{
		x=rand() % 4;
		if(x==0)
		{
			printf("I forgot about %s...\n", tkn);
			fprintf(f,"\nI forgot about %s...\n", tkn);
		}		
		else if(x==1)
		{ 
			printf("I dnt know what %s is anymore.\n", tkn);
			fprintf(f,"\nI dnt know what %s is anymore.\n", tkn);
	 	}
		else if(x==2)
		{
			printf(" %s doesnt belong to my memory anymore.\n", tkn);
			fprintf(f,"\n %s doesnt belong to my memory anymore.\n", tkn);
		}
		else if(x==3)
		{
			printf( "Bye bye memory about %s.\n", tkn);
			fprintf(f,"\nBye bye memory about %s.\n", tkn);
		}
		else if(x==4)
		{
			printf("%s no memory found.\n", tkn);
			fprintf(f,"\n %s no memory found.\n", tkn);
		}		
	}
	else if(n==3)//geniko
	{
		x=rand() % 4;
		if(x==0)
		{
			printf("I think that's sound interesting\n");
			fprintf(f,"\nI think that's sound interesting\n");
		}		
		else if(x==1)
		{ 
			printf("I agree\n");
			fprintf(f,"\nI agree\n", tkn);
	 	}
		else if(x==2)
		{
			printf("That is sound like a plan\n");
			fprintf(f,"\nThat is sound like a plan\n");
		}
		else if(x==3)
		{
			printf("I totally agree about that\n");
			fprintf(f,"\nI totally agree about that\n");
		}
		else if(x==4)
		{
			printf("Cool for you m8\n");
			fprintf(f,"\nCool for you m8\n");
		}		
	}
	else if (n==4)//etrekse th lista 2 fores kai de vrike tipota
	{
		x=rand() % 4;
		if(x==0)
		{
			printf("I Dont know nothing about %s anymore\n",tkn);
			fprintf(f,"\nI Dont know nothing about %s anymore\n",tkn);
		}		
		else if(x==1)
		{ 
			printf("No information about %s found\n",tkn);
			fprintf(f,"\nNo information about %s found\n",tkn);
	 	}
		else if(x==2)
		{
			printf("Do you thing i should know about %s ... well i dont\n",tkn);
			fprintf(f,"\nDo you thing i should know about %s ... well i dont\n",tkn);
		}
		else if(x==3)
		{
			printf("%s ? what are you talking about?\n",tkn);
			fprintf(f,"\n%s ? what are you talking about?\n",tkn);
		}
		else if(x==4)
		{
			printf("I have no idea what %s means",tkn);
			fprintf(f,"\nI have no idea what %s means",tkn);
		}
	}
	return;
}
int checkfor(char *thn)// dlt gnwshs
{
	int i,x;
	conceptList *tst, *tail,*tail1;
	tst=head;
	do //briskw tail
	{
		if(ii==1)//head->next=null
		{
			tail=head; 
		}
		else if(tst->next==head)
		{
			tail=tst;
			tst=tst->next;
			tail1=tail;
		}
		else
		{
			tst=tst->next;
		}
	}while(tst!=head);
	for(i=0;;i++)
	{
		if(strstr(tst->concept,thn) != NULL)//brikse match
		{
			if(ii==1)//head->next=null
			{
				epiloges(2,thn);
				ii--;
				free(head);
				return 0;
			}
			else if(ii==2)//2 komboi
			{
				if(tst->next==head)//dlt tail      na alazh to tail??
				{
					ii--;
					epiloges(2,thn);
					free (tst);
					head->next=NULL;
					tail=head;
					return 0;
				}
				else if(tst->next==tail1) // dlt head
				{
					ii--;
					epiloges(2,thn);
					free (head);
					head=tst->next;
					tst=head;
					tail=head;
				}	
			}
			else if(tst->next==head->next)//delete head
			{
				ii--;
				epiloges(2,thn);
				tail->next=head->next;
				free(head);
				head=tail->next;
				tail1=tail;
			}
			else if(tst->next==head)//delete tail1
			{
				ii--;
				epiloges(2,thn);
				tail->next=head;
				tail1=tail;
				free(tst);
				return 0;
			}
			else 
			{
				ii--;
				epiloges(2,thn);
				tail->next=tst->next;
				free (tst);
				tst=tail->next;				
			}
		}
		else //den brike
		{
			if(ii==1)
			{
				return 0;
			}
			else if(tst==tail1)
			{
				return 0;				
			}
			else
			{
				tst=tst->next;
				tail=tail->next;
			}
		}
	}	
}	
void dltlst()//free
{
    conceptList *x, *nxt;
    x=head;
    while (ii!=0) 
	{
		if(ii==1)
		{
			free(x);
			ii--;
		}
        else 
        {
			nxt=x->next;
        	free(x);
        	ii--;
        	x=nxt;
    	}
    }
}
int check(char *rar, char *lol)
{
	char *xd;
	xd=strtok(lol," .,?!-()");
	while(xd!=NULL)
	{
		if(strcmp(xd,rar)==0)
		{
			return 1;
		}
		
		xd=strtok(NULL," .,?!-()");
	}
	return 0;
}

