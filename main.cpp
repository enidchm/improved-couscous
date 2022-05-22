#include <stdio.h>

struct ranking
{
	char name[100];
	int gold;
	int sliver;
	int copper;
	int total;

};

void pailie(struct ranking country[],int n)
{

	for(int j=0;j<n;j++)
	{
	  for(int i=0;i<n;i++)
	  {
		 if(country[i].gold<country[i+1].gold)
		 {
			struct ranking hb=country[i];
			country[i]=country[i+1];
			country[i+1]=hb;		
		 }
	  }  
	
	}


};

void printfall(struct ranking country[],int i)
{
		
	for(int h=0;h<i;h++)
	{
		printf("%s %d %d %d %d\n",country[h].name,country[h].gold,country[h].sliver,country[h].copper,country[h].total);
	}
	
	
};

int main()
{
	FILE*fp1=fopen("D://national.txt","r");
	if(fp1==NULL)
	{
		printf("error!");
	}	

	struct ranking country[8];
	for(int i=0;i<8;i++)
	{
		fscanf(fp1,"%s %d %d %d %d\n",
			country[i].name,&country[i].gold,&country[i].sliver,&country[i].copper,&country[i].total);
	}
	fclose(fp1);
	pailie(country,8);

	FILE*fp2=fopen("D://nationahs_sort.txt","w");
	for(i=0;i<8;i++)
	{
	   fprintf(fp2,"%s\t%d\t%d\t%d\t%d\n",
		   country[i]. name,country[i].gold,country[i].sliver,country[i].copper,country[i].total);
	}
	

	printfall(country,i);
	

	
	fclose(fp2);
	
	
	return 0;
}
