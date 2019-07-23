#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 12
#define ROW 12
#define RANDOM (rand() % 10 +1)
#define RANDOM_I (rand() % (10-(p-1)) +1)

void NewShipH(int m[COL][ROW],int);
void NewShipV(int m[COL][ROW],int);
void GenShip(int m[COL][ROW], int, int);
void BattleField(int m[COL][ROW]);

int main()
	{
	int i, j, battle [COL][ROW];
	
	//----field------------
	//	�������� ����
	//----field------------
	
	for(i=0;i<COL;i++)
	for(j=0;j<ROW;j++) battle[i][j]=0;
	
	//-----Genhips----
	//	��������� ������� �� ���� ���
	//-----Genhips----
	
	BattleField(battle);
	
	//--------print--------
	//	������������ �������� ������� ����
	//--------print--------
	for(i=1;i<COL-1;i++)
		for(j=1;j<ROW-1;j++)
			{ 
			if((battle[i][j]==1) || (battle[i][j]==0)) battle[i][j] = '.';
			printf("%c ",battle[i][j]);
			if(j==ROW-2) printf ("\n");
			}
	return 0;
	}


	//----------------------------
	//��������� �������������� ��������
	//----------------------------
void NewShipH(int m[COL][ROW],int p)
	{
	int i, j, r1, r2;
	
	srand(time(NULL));
	
	r1 = RANDOM;
	r2 = RANDOM_I;
	 
	//���������, �� ������ �� ���� ������ ��������
	while(!((m[r1][r2]==0)&&(m[r1][r2+(p-1)]==0)))
		{
		r1 = RANDOM;
		r2 = RANDOM_I;
		}
	
	//������ ������� � ������ ���-��� �����
	for(i=0;i<p;i++)
		{
		m[r1-1][r2+i-1] = 1;
		m[r1-1][r2+i] = 1;
		m[r1-1][r2+i+1] = 1;
		m[r1][r2-1] = 1;
		m[r1][r2+i] = 'X';
		m[r1][r2+i+1] = 1;
		m[r1+1][r2+i-1] = 1;
		m[r1+1][r2+i] = 1;
		m[r1+1][r2+i+1] = 1;
		}
	}
	
	//----------------------------
	//��������� ������������ ��������
	//----------------------------
void NewShipV(int m[COL][ROW],int p)
	{
	int i, j, r1, r2;
	
	srand(time(NULL));
	r1 = RANDOM_I;
	r2 = RANDOM;
	
	//���������, �� ������ �� ���� ������ ��������
	while(!((m[r1][r2]==0)&&(m[r1+(p-1)][r2]==0)))
		{
		r1 = RANDOM_I;
		r2 = RANDOM;
		}
	
	//������ ������� � ������ ���-��� �����
	for(i=0;i<p;i++)
		{
		m[r1+i-1][r2-1] = 1;
		m[r1+i-1][r2+1] = 1;
		m[r1-1][r2] = 1;
		m[r1+i][r2-1] = 1;
		m[r1+i][r2] = 'X';
		m[r1+i][r2+1] = 1;
		m[r1+i+1][r2-1] = 1;
		m[r1+i+1][r2] = 1;
		m[r1+i+1][r2+1] = 1;
		}
	}
	
	//----------------------------
	//��������� ��������� ��������
	//----------------------------
void GenShip(int m[COL][ROW], int p, int n)
	{
	int i, m1[10];
	
	//�������� ������ ��������� �����
	srand(time(NULL));
	for (i=0;i<10;i++)
	{
		m1[i] = RANDOM;
	}
	
	
	if (m1[n]%2==0)
		{
		NewShipH(m,p);
		}
	else
		{
		NewShipV(m,p);
		}
	}
	
	//----------------------------
	//������ ������������ ��������
	//----------------------------
void BattleField(int m[COL][ROW])
	{
	GenShip(m,4,1);
	GenShip(m,3,2);
	GenShip(m,3,3);
	GenShip(m,2,4);
	GenShip(m,2,5);
	GenShip(m,2,6);
	GenShip(m,1,7);
	GenShip(m,1,8);
	GenShip(m,1,9);
	GenShip(m,1,0);
	}
