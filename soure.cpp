#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

bool game_over;
const int width = 45;
const int height = 25;
int speed;
int x, y, Fx, Fy, score;
int tx[100], ty[100];
int nT;
enum eDir {STOP = 0,LEFT, RIGHT, UP, DOWN };
eDir dir;
void setup()
{
	game_over = false;
	dir = STOP;
	x = width / 2;
		y = height / 2;
		Fx = rand() % width;
		Fy = rand() % height;
		score = 0;

}

void input()
{
	if (_kbhit())
	{
		switch(_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			game_over = true;
			break;
		}
	}

}

void draw()
{
	system("cls");
	for (int i = 0; i < width+2; i++)
	{
		cout << "\xB2";
	}
	cout << endl;

	

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "\xB2";
			if (i == y && j == x)
				cout << "X";
			else if (i == Fy && j == Fx)
				cout << "\xFE";
			else {
				bool print = false;
				for (int k = 0; k < nT; k++)
				{
				if (tx[k] == j && ty[k]==i)
					{
						cout << "x";
						print = true;
					}
				}
				if(!print)
				cout << " ";
			}
			if (j == width - 1)
				cout << "\xB2";
		}
		cout << endl;
		}
	for (int i = 0; i < width+2; i++)
	{
		cout << "\xB2";
	}
	cout << endl;
	cout << "Score:" << score << endl;

}

void logic() 
{
	int prevX = tx[0];
	int prevY = ty[0];
	int prev2X, prev2Y;
	tx[0] = x;
	ty[0] = y;
	for (int i=1; i<nT; i++) 
	{
		prev2X = tx[i];
		prev2Y = ty[i];
		tx[i] = prevX;
		ty[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
		
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		
	
	}
	if (x > width || x < 0 || y > height-1 || y < 0)
	{
		game_over = true;
	}
	for (int i = 0; i < nT; i++)
	{
		if (tx[i] == x && ty[i] == y)
			game_over = true;
	}
	if (x == Fx && y == Fy)
	{
		
		score += 10;
		Fx = rand() % width;
		Fy = rand() % height;
		nT++;

	}
}

void Pre_start()
{
	system("color 04");
	cout << "Chose speed :\t"<< endl;
	cin >> speed;
	system("color 34");
		system("cls");
}


int main()
{
	Pre_start();
	setup();
	while (!game_over)
	{
		draw();
		input();
		logic();
		Sleep(speed);
	}

return 0;
}