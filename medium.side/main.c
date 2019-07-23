#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 12
#define ROW 12

void ShipVertical(int ship[ROW][COL],int,int,int);
void ShipHorizontal(int ship[ROW][COL],int,int,int);
void Step1_4(int ship[ROW][COL],int*,int*,int*,int*,int*,int*);
void Step5_6(int ship[ROW][COL],int*,int*,int*,int*);
void Step7_10(int ship[ROW][COL]);
void Debuger(int ship[ROW][COL],int*,int*,int*,int*);
void Counter(int ship[ROW][COL],int*,int*,int*,int*);
int* NumGen(int*);


int main()
{
	int i, j, ship[ROW][COL];
	int num[10];
	int shN[6]={4,3,3,2,2,2};
	int side1[6]={1,10,0,0,0,0};
	int side2[6]={1,10,0,0,0,0};
	int side3[6]={1,10,0,0,0,0};
	int side4[6]={1,10,0,0,0,0};
	
	//----field----------—
	//  MakeNullField
	//----field----------—

	for(i=0;i<COL;i++)
		for(j=0;j<ROW;j++) ship[i][j]=0;
	
	//-----Genhips--—
	//
	//-----Genhips--—
	
	NumGen(num);
	Step1_4(ship,num,shN,side1,side2,side3,side4);
	Debuger(ship,side1,side2,side3,side4);
	Counter(ship,side1,side2,side3,side4);
	Step5_6(ship,side1,side2,side3,side4);
	Counter(ship,side1,side2,side3,side4);
	Step5_6(ship,side1,side2,side3,side4);
	Step7_10(ship);
	
	//--------print------—
	//  BattleField
	//--------print------—
	for(i=1;i<COL-1;i++)
		for(j=1;j<ROW-1;j++)
		{
			if((ship[i][j]==1) || (ship[i][j]==0)) ship[i][j] = '.';
			if((ship[i][j]==2) || (ship[i][j]==3) || (ship[i][j]==4) || (ship[i][j]==5)) ship[i][j]= 'X';
			printf("%c ",ship[i][j]);
			if(j==ROW-2) printf ("\n");
		}

	return 0;
}

void Step1_4(int ship[ROW][COL],int *num, int *shN, int *side1, int *side2, int *side3, int *side4)
{
	int side[4]={1,2,3,4};
	int i,tmp,swap;
	srand(time(NULL));

	for (i=0;i<4;i++)
	{
		swap = rand() % 4 +0;
		tmp = side[i];
		side[i] = side[swap];
		side[swap] = tmp;
	}
	
	for (i=0;i<4;i++)
	{
		swap = rand() % 4 +0;
		tmp = shN[i];
		shN[i] = shN[swap];
		shN[swap] = tmp;
	}
	

	for(i=0;i<4;i++)
	{
		if (*(side+i) == 1 || *(side+i) == 3)
		{
			if (*(side+i)==1)
			{
				if (ship[2][1]!=0 || ship[1][1]!=0)
				{
					if (side1[0]<3)side1[0]=3;
					if (side2[0]<3)side2[0]=3;
				}
				if (ship[9][1]!=0 || ship[10][1]!=0)
				{
					if (side1[1]>8) side1[1]=8;
					if (side4[0]<3) side4[0]=3;
				}
				if (((*(num+i)+*(shN+i))-1) > side1[1] || (*(num+i)<side1[0])) *(num+i) = rand() % ((side1[1] - *(shN+i))+1) +side1[0];
				(*(num+i)-(side1[0]+1))>(side1[1]-(*(num+i)+*(shN+i)))?(side1[1]=(*(num+i)-2)):(side1[0]=(*(num+i)+*(shN+i)+1));
				ShipVertical(ship, *(shN+i), *(num+i), 1);
			}
			if (*(side+i)==3)
			{
				if (ship[2][10]!=0 || ship[1][10]!=0)
				{
					if (side3[0]<3) side3[0]=3;
					if (side2[1]>8) side2[1]=8;
				}
				if (ship[9][10]!=0 || ship[10][10]!=0)
				{
					if (side3[1]>8) side3[1]=8;
					if (side4[1]>8) side4[1]=8;
				}
				if (((*(num+i)+*(shN+i))-1) > side3[1] || (*(num+i)<side3[0])) *(num+i) = rand() % ((side3[1] - *(shN+i))+1) +side3[0];
				(*(num+i)-(side3[0]+1))>(side3[1]-(*(num+i)+*(shN+i)))?(side3[1]=(*(num+i)-2)):(side3[0]=(*(num+i)+*(shN+i)+1));
				ShipVertical(ship, *(shN+i), *(num+i), 10);
			}
		} //if (*(side+i) == 1 || *(side+i) == 3)
		else
		{
			if (*(side+i)==2)
			{
				if (ship[1][2]!=0 || ship[1][1]!=0)
				{
					if (side1[0]<3)side1[0]=3;
					if (side2[0]<3)side2[0]=3;
				}
				if (ship[1][9]!=0 || ship[1][10]!=0)
				{
					if (side2[1]>8) side2[1]=8;
					if (side3[0]<3) side3[0]=3;
				}
				if (((*(num+i)+*(shN+i))-1) > side2[1]  || (*(num+i)<side2[0])) *(num+i) = rand() % (side2[1]-((*(shN+i))+1)) +side2[0];
				(*(num+i)-(side2[0]+1))>(side2[1]-(*(num+i)+*(shN+i)))?(side2[1]=(*(num+i)-2)):(side2[0]=(*(num+i)+*(shN+i)+1));
				ShipHorizontal(ship, *(shN+i), 1, *(num+i));
			}
			if (*(side+i)==4)
			{
				if (ship[10][1]!=0 || ship[10][2]!=0)
				{
					if (side4[0]<3) side4[0]=3;
					if (side1[1]>8) side1[1]=8;
				}
				if (ship[10][10]!=0 || ship[10][9]!=0)
				{
					if (side3[1]>8) side3[1]=8;
					if (side4[1]>8) side4[1]=8;
				}
				if (((*(num+i)+*(shN+i))-1) > side4[1] || (*(num+i)<side4[0])) *(num+i) = rand() % ((*(side4+1)-*(shN+i))+1) +side4[0];
				(*(num+i)-(side4[0]+1))>(side4[1]-(*(num+i)+*(shN+i)))?(side4[1]=(*(num+i)-2)):(side4[0]=(*(num+i)+*(shN+i)+1));
				ShipHorizontal(ship, *(shN+i), 10, *(num+i));
			}
		} //else ------ if (*(side+i) == 1 || *(side+i) == 3) 
	} //for(i=0;i<4;i++)	
}//void Step1_4();

void Step5_6(int ship[ROW][COL], int *side1, int *side2, int *side3, int *side4)
{
	int s1,s2,s3,s4, num;
	s1 = side1[1]-side1[0];
	s2 = side2[1]-side2[0];
	s3 = side3[1]-side3[0];
	s4 = side4[1]-side4[0];
	
	if (s1 > s2)
	{
		if (s3 > s4)
		{
			if (s1 > s3 )
			{
				num = side1[0] + s1/2;
				ShipVertical(ship, 2, num, 1);
			}
			else
			{
				num = side3[0] + s3/2;
				ShipVertical(ship, 2, num, 10);
			}
		}
		else
		{
			if (s1 > s4)
			{
				num = side1[0] + s1/2;
				ShipVertical(ship, 2, num, 1);
			}
			else
			{
				num = side4[0] + s4/2;
				ShipHorizontal(ship, 2, 10, num);
			}
		}
	}
	else
	{
		if (s3 > s4)
		{
			if (s2 > s3)
			{
				num = side2[0] + s2/2;
				ShipHorizontal(ship, 2, 1, num);
			}
			else
			{
				num = side3[0] + s3/2;
				ShipVertical(ship, 2, num, 10);
			}
		}
		else
		{
			if (s2 > s4)
			{
				num = side2[0] + s2/2;
				ShipHorizontal(ship, 2, 1, num);
			}
			else
			{
				num = side4[0] + s4/2;
				ShipHorizontal(ship,2,10,num);
			}
		}
	}
}

void Step7_10(int ship[ROW][COL])
{
	int rw=0, cl=0, i;
	srand(time(NULL));
	
	rw = rand() % 6 +3;
	cl = rand() % 6 +3;
	
	for(i=0;i<4;i++)
	{
		
		while (ship[rw][cl]!=0)
		{
			rw = rand() % 6 +3;
			cl = rand() % 6 +3;
		}
		ship[rw-1][cl-1]=1;
		ship[rw-1][cl]=1;
		ship[rw-1][cl+1]=1;
		ship[rw][cl+1]=1;
		ship[rw][cl]=5;
		ship[rw][cl-1]=1;
		ship[rw+1][cl-1]=1;
		ship[rw+1][cl+1]=1;
		ship[rw+1][cl]=1;
	}
}//void Step7_10

void ShipVertical(int ship[ROW][COL], int shN, int rw, int cl)
{
	int i;
	for(i=0;i<shN;i++)
	{
		ship[rw+i-1][cl-1] = 1;
		ship[rw+i-1][cl+1] = 1;
		ship[rw-1][cl] = 1;
		ship[rw+i][cl-1] = 1;
		ship[rw+i][cl] = shN;
		ship[rw+i][cl+1] = 1;
		ship[rw+i+1][cl-1] = 1;
		ship[rw+i+1][cl] = 1;
		ship[rw+i+1][cl+1] = 1;
	}
}

void ShipHorizontal(int ship[ROW][COL], int shN, int rw, int cl)
{
	int i;
	for(i=0;i<shN;i++)
	{
		ship[rw-1][cl+i-1] = 1;
		ship[rw-1][cl+i] = 1;
		ship[rw-1][cl+i+1] = 1;
		ship[rw][cl-1] = 1;
		ship[rw][cl+i] = shN;
		ship[rw][cl+i+1] = 1;
		ship[rw+1][cl+i-1] = 1;
		ship[rw+1][cl+i] = 1;
		ship[rw+1][cl+i+1] = 1;
	}
}

int* NumGen(int *num)
{
	int i,swap,tmp;
	for(i=0;i<10;i++) num[i] = rand() % 10 +1;
	
	for(i=0;i<10;i++)
	{
		swap = rand() % 10 +1;
		tmp = num[i];
		num[i] = num[swap];
		num[swap] = tmp;
	}
	return num;
}

void Debuger(int ship[ROW][COL],int *side1, int *side2, int *side3, int *side4)
{
	
				if (ship[2][1]!=0 || ship[1][1]!=0)
				{
					if (side1[0]<3)side1[0]=3;
					if (side2[0]<3)side2[0]=3;
				}
				if (ship[9][1]!=0 || ship[10][1]!=0)
				{
					if (side1[1]>8) side1[1]=8;
					if (side4[0]<3) side4[0]=3;
				}
				if (ship[2][10]!=0 || ship[1][10]!=0)
				{
					if (side3[0]<3) side3[0]=3;
					if (side2[1]>8) side2[1]=8;
				}
				if (ship[9][10]!=0 || ship[10][10]!=0)
				{
					if (side3[1]>8) side3[1]=8;
					if (side4[1]>8) side4[1]=8;
				}
				if (ship[1][2]!=0 || ship[1][1]!=0)
				{
					if (side1[0]<3)side1[0]=3;
					if (side2[0]<3)side2[0]=3;
				}
				if (ship[1][9]!=0 || ship[1][10]!=0)
				{
					if (side2[1]>8) side2[1]=8;
					if (side3[0]<3) side3[0]=3;
				}
				if (ship[10][1]!=0 || ship[10][2]!=0)
				{
					if (side4[0]<3) side4[0]=3;
					if (side1[1]>8) side1[1]=8;
				}
				if (ship[10][10]!=0 || ship[10][9]!=0)
				{
					if (side3[1]>8) side3[1]=8;
					if (side4[1]>8) side4[1]=8;
				}
}

void Counter(int ship[ROW][COL], int *side1, int *side2, int *side3, int *side4)
{
	int i=0,ctr=0,n=0;
	
	for (ctr=0, n=0, i=1;i<11;i++)
	{
		if (ship[i][1]==0) 
		{
			ctr++;
			if(ctr==1) n++;
				
			if (n==1) 
			{
				if(ctr==1) side1[0]=i;
				side1[1]=i;
			}
			
			if (n==2) 
			{
				if(ctr==1) side1[2]=i;
				side1[3]=i;
			}
			
			if (n==3)
			{
				if(ctr==1) side1[4]=i;
				side1[5]=i;
			}
		}
		else ctr=0;
	}
	
	for (ctr=0, n=0, i=1;i<11;i++)
	{
		if (ship[1][i]==0) 
		{
			ctr++;
			if(ctr==1) n++;
				
			if (n==1) 
			{
				if(ctr==1) side2[0]=i;
				side2[1]=i;
			}
			
			if (n==2) 
			{
				if(ctr==1) side2[2]=i;
				side2[3]=i;
			}
			if (n==3)
			{
				if(ctr==1) side2[4]=i;
				side2[5]=i;
			}
		}
		else ctr=0;
	}
	
	for (ctr=0, n=0, i=1;i<11;i++)
	{
		if (ship[i][10]==0) 
		{
			ctr++;
				if(ctr==1)
				 n++;
				
			if (n==1) 
			{
				if(ctr==1) side3[0]=i;
				side3[1]=i;
			}
			
			if (n==2) 
			{
				if(ctr==1) side3[2]=i;
				side3[3]=i;
			}
			if (n==3)
			{
				if(ctr==1) side3[4]=i;
				side3[5]=i;
			}
		}
		else ctr=0;
	}
	
	for (ctr=0, n=0, i=1;i<11;i++)
	{
		if (ship[10][i]==0) 
		{
			ctr++;
			if(ctr==1) n++;
				
			if (n==1) 
			{
				if(ctr==1) side4[0]=i;
				side4[1]=i;
			}
			
			if (n==2) 
			{
				if(ctr==1) side4[2]=i;
				side4[3]=i;
			}
			if (n==3)
			{
				if(ctr==1) side4[4]=i;
				side4[5]=i;
			}
		}
		else ctr=0;
	}
	
	if ((side1[1]-side1[0])<(side1[3]-side1[2]))
	{
		if((side1[3]-side1[2])<(side1[5]-side1[4]))
		{
			side1[0]=side1[4];
			side1[1]=side1[5];
		}
		else
		{
			side1[0]=side1[2];
			side1[1]=side1[3];
		}
	}
		
	if ((side2[1]-side2[0])<(side2[3]-side2[2]))
	{
		if((side2[3]-side2[2])<(side2[5]-side2[4]))
		{
			side2[0]=side2[4];
			side2[1]=side2[5];
		}
		else
		{
			side2[0]=side2[2];
			side2[1]=side2[3];
		}
	}
	
	if ((side3[1]-side3[0])<(side3[3]-side3[2]))
	{
		if((side3[3]-side3[2])<(side3[5]-side3[4]))
		{
			side3[0]=side3[4];
			side3[1]=side3[5];
		}
		else
		{
			side3[0]=side3[2];
			side3[1]=side3[3];
		}
	}
	
	if ((side4[1]-side4[0])<(side4[3]-side4[2]))
	{
		if((side4[3]-side4[2])<(side4[5]-side4[4]))
		{
			side4[0]=side4[4];
			side4[1]=side4[5];
		}
		else
		{
			side4[0]=side4[2];
			side4[1]=side4[3];
		}
	}
}
