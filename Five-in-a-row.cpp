#include<iostream>
#include<string>//getline
using namespace std;

class CGobang
{
private:
	char chSort;//�������    okay
	int nWin;//Ӯ�����    okay
	int nLose;//�������    okay
	static int nDraw;//ƽ��    okay
	static char achBoard[9][9];//����    okay
	//static int nSize;//���̳ߴ�
public:
	CGobang(char chSort, int nWin = 0, int nLose = 0);//���캯��������һ���������    okay
	~CGobang() {}
	void PlayTurn(void);//��һ����  
	int Judge();//�ж��Ƿ����ߣ��Ƿ���1�����Ƿ���0
	void Win(void);//Ӯ��   okay
	void Lose(void);//����    okay
	static void Draw(void);//ƽ��    okay
	void PrintInfo(void);//��ӡ�������(��Ϸ��ʾ��Ϣ)    okay
	static void PrintBoard(void);//��ӡ����    okay
	static int GetFull(void);//�ж��Ƿ���    okay
	static void InitialBoard(void);//��ʼ������     okay
	static int Compare(int x, int y, char temp);
	static void Locate(int x, int y, char temp);
};
const int N = 5;
int CGobang::nDraw = 0;
char CGobang::achBoard[9][9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',\
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',\
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ',' ',' ',' ',' ',' ',\
' ',' ',' ',' ',' ',' ',' ',' ',' ' };

int main()
{
	CGobang c1('O'), c2('X'),c3('J');
	char Choice = 'Y';
	int t;

	while (Choice == 'Y')
	{
		cout << "                           1.0������" << endl;
		cout << "1.two on two" << endl << "2.three on three" << endl;
		cout << "input your choice:";
		cin >> t;

		if (t == 1)
		{
			cout << "2v2������begined" << endl;
			CGobang::InitialBoard();
			CGobang::PrintBoard();

			while (CGobang::GetFull() == 0)
			{
				cout << "1th Player:" << endl;
				c1.PlayTurn();
				CGobang::PrintBoard();
				if (CGobang::GetFull())
				{
					CGobang::Draw();
					cout << "Draw" << endl;
					break;
				}
				else
				{
					if (c1.Judge())
					{
						c1.Win();
						c2.Lose();
						c1.PrintInfo();
						c2.PrintInfo();
						break;
					}
				}

				cout << "2th Player:" << endl;
				c2.PlayTurn();
				CGobang::PrintBoard();
				if (CGobang::GetFull())
				{
					CGobang::Draw();
					cout << "Draw" << endl;
					break;
				}
				else
				{
					if (c2.Judge())
					{
						c2.Win();
						c1.Lose();
						c1.PrintInfo();
						c2.PrintInfo();
						break;
					}
				}
			}
		}
		else if (t == 2)
		{
			cout << "3v3������begined" << endl;
			CGobang::InitialBoard();
			CGobang::PrintBoard();

			while (CGobang::GetFull() == 0)
			{
				cout << "1th Player:" << endl;
				c1.PlayTurn();
				CGobang::PrintBoard();
				if (CGobang::GetFull())
				{
					CGobang::Draw();
					cout << "Draw" << endl;
					break;
				}
				else
				{
					if (c1.Judge())
					{
						c1.Win();
						c2.Lose();
						c3.Lose();
						c1.PrintInfo();
						c2.PrintInfo();
						c3.PrintInfo();
						break;
					}
				}

				cout << "2th Player:" << endl;
				c2.PlayTurn();
				CGobang::PrintBoard();
				if (CGobang::GetFull())
				{
					CGobang::Draw();
					cout << "Draw" << endl;
					break;
				}
				else
				{
					if (c2.Judge())
					{
						c2.Win();
						c1.Lose();
						c3.Lose();
						c2.PrintInfo();
						c1.PrintInfo();
						c3.PrintInfo();
						break;
					}
				}

				cout << "3th Player:" << endl;
				c3.PlayTurn();
				CGobang::PrintBoard();
				if (CGobang::GetFull())
				{
					CGobang::Draw();
					cout << "Draw" << endl;
					break;
				}
				else
				{
					if (c3.Judge())
					{
						c3.Win();
						c1.Lose();
						c2.Lose();
						c3.PrintInfo();
						c1.PrintInfo();
						c2.PrintInfo();
						break;
					}
				}
			}
		}
		else
		{
			cout << "input error" << endl;
			continue;
		}
		
		
		cout << "Game over" << endl;

		cout << "Do you want to play it again?(Y or N)" << endl;
		cin >> Choice;
	}
	
	cout << "exit successfully" << endl;

	system("pause");

	return 0;
}

CGobang::CGobang(char chSort, int nWin, int nLose) :chSort(chSort), nWin(nWin), nLose(nLose)
{
}

void CGobang::Win()
{
	nWin++;
}
void CGobang::Lose()
{
	nLose++;
}
void CGobang::Draw()//static
{
	nDraw++;
}

void CGobang::PrintInfo()
{
	cout << "Player:" << chSort << endl;
	cout << "Win:" << nWin << endl;
	cout << "Lose:" << nLose << endl;
}

void CGobang::PrintBoard()//static
{
	cout << endl;
	cout << "  1  2  3  4  5  6  7  8  9" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << '|';
		for (int j = 0; j < 9; j++)
		{
			cout << achBoard[i][j] << " |";
		}
		cout << endl;
		cout << "-|--|--|--|--|--|--|--|--|--|" << endl;
	}
}

void CGobang::InitialBoard()//static
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			achBoard[i][j] = ' ';
		}
	}

	nDraw = 0;
}

int CGobang::GetFull()//static
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (achBoard[i][j] == ' ')
				return 0;
			else
				continue;
		}
	}

	return 1;
}

void CGobang::PlayTurn()
{
	int row, column, n = 0;
	int i, j;
	cout << "enter row:";
	cin >> row;
	cout << "enter column:";
	cin >> column;

	for (; Compare(row - 1, column - 1, ' ');)
	{
		cout << "reinput row:";
		cin >> row;
		cout << "reinput column:";
		cin >> column;
	}
	
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i + 1 == row && j + 1 == column)
			{
				Locate(i, j, chSort);
				return;

			}
			else
				continue;
		}
	}
	

}

int CGobang::Judge()//�ж��Ƿ����ߣ��Ƿ���1�����Ƿ���0
{
	int i, j, k;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - N; j++)
		{
			if (achBoard[i][j] == chSort)
			{
				for (k = 1; k < N; k++)
				{
					if (Compare(i, j + k, chSort))
						break;
					if (k == N - 1)
						return 1;
				}
			}
		}
	}

	for (j = 0; j < 9; j++)
	{
		for (i = 0; i < 9 - N; i++)
		{
			if (achBoard[i][j] == chSort)
			{
				for (k = 1; k < N; k++)
				{
					if (Compare(i + k, j, chSort))
						break;
					if (k == N - 1)
						return 1;
				}
			}
		}
	}

	for (i = N; i < 9; i++)
	{
		for (j = 0; j < 9 - N; j++)
		{
			if (achBoard[i][j] == chSort)
			{
				for (k = 1; k < N; k++)
				{
					if (Compare(i - k, j + k, chSort))
						break;
					if (k == N - 1)
						return 1;
				}
			}
		}
	}

	for (i = 0; i < 9 - N; i++)
	{
		for (j = 0; j < 9 - N; j++)
		{
			{
				for (k = 1; k < N; k++)
				{
					if (Compare(i + k, j + k, chSort))
						break;
					if (k == N - 1)
						return 1;
				}
			}
		}
	}

	return 0;
}

int CGobang::Compare(int x, int y, char temp)//static
{
	if (achBoard[x][y] == temp)
		return 0;
	else
		return 1;
}

void CGobang::Locate(int x, int y, char temp)//static
{
	achBoard[x][y] = temp;
}

