#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int count = 0;
int i, j, x1, y1;
int s = 0;
int arr[15][15];
void intimap();
void create_white_piece(int x, int y);
void create_black_piece(int x, int y);
void gameing();
void judgeWin();
int main();
void initmap()
{
	int x, y;

	setbkcolor(RGB(207, 164, 132));
	cleardevice();
	setcolor(BLACK);
	for (y = 44; y <= 436; y += 28)
	{
		line(124, y, 516, y);
	}
	for (x = 124; x <= 516; x += 28)
	{
		line(x, 44, x, 436);
	}
	for (int i = 124 + 3 * 28 - 2; i <= 124 + 3 * 28 + 2; i++)
	{
		for (int j = 44 + 3 * 28 - 2; j <= 44 + 3 * 28 + 2; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	for (int i = 516 - 3 * 28 - 2; i <= 516 - 3 * 28 + 2; i++)
	{
		for (int j = 44 + 3 * 28 - 2; j <= 44 + 3 * 28 + 2; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	for (int i = 124 + 3 * 28 - 2; i <= 124 + 3 * 28 + 2; i++)
	{
		for (int j = 436 - 3 * 28 - 2; j <= 436 - 3 * 28 + 2; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	for (int i = 516 - 3 * 28 - 2; i <= 516 - 3 * 28 + 2; i++)
	{
		for (int j = 436 - 3 * 28 - 2; j <= 436 - 3 * 28 + 2; j++)
		{
			putpixel(i, j, BLACK);
		}
	}
	RECT r = { 175,2,461,40 };
	drawtext(_T("五子棋 by 胡军奎"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	create_black_piece(16, 5.3);
	RECT a = { 513,154,636,294 };
	drawtext(_T("黑方下棋"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT c = { 0,138,120,268 };
	drawtext(_T("鼠标右键重玩"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void welcomegame()
{

}
void create_white_piece(int x, int y)
{
	setcolor(RGB(250, 250, 250));
	setfillcolor(RGB(255, 255, 255));
	circle(124 + 28 * x, 44 + 28 * y, 12);
	fillcircle(124 + 28 * x, 44 + 28 * y, 12);
}
void create_black_piece(int x, int y)
{
	setcolor(RGB(0, 0, 0));
	setfillcolor(RGB(5, 5, 5));
	circle(124 + 28 * x, 44 + 28 * y, 12);
	fillcircle(124 + 28 * x, 44 + 28 * y, 12);
}
void judgeWin()
{
	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
		{
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i + 2][j] == 1 && arr[i + 3][j] == 1 && arr[i + 4][j] == 1)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("黑方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i][j + 2] == 1 && arr[i][j + 3] == 1 && arr[i][j + 4] == 1)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("黑方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 1 && arr[i + 3][j + 3] == 1 && arr[i + 4][j + 4] == 1)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("黑方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 1 && arr[i - 1][j + 1] == 1 && arr[i - 2][j + 2] == 1 && arr[i - 3][j + 3] == 1 && arr[i - 4][j + 4] == 1)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("黑方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 2 && arr[i + 1][j] == 2 && arr[i + 2][j] == 2 && arr[i + 3][j] == 2 && arr[i + 4][j] == 2)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("白方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 2 && arr[i][j + 1] == 2 && arr[i][j + 2] == 2 && arr[i][j + 3] == 2 && arr[i][j + 4] == 2)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("白方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 2 && arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 2 && arr[i + 3][j + 3] == 2 && arr[i + 4][j + 4] == 2)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("白方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
			if (arr[i][j] == 2 && arr[i - 1][j + 1] == 2 && arr[i - 2][j + 2] == 2 && arr[i - 3][j + 3] == 2 && arr[i - 4][j + 4] == 2)
			{
				setcolor(RED);
				RECT r = { 250,200,400,300 };
				drawtext(_T("白方胜出！"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				s = 1;
				break;
			}
		}
}
void gaming()
{
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			arr[i][j] = 0;
		}
	}
	MOUSEMSG m;
	while (s!=2)
	{
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (s == 1)
				break;
			if (m.x < 112 || m.x>528 || m.y < 28 || m.y>448)
				break;
			else
				count++;

			if (((m.x - 124) % 28) <= 12)
				x1 = (m.x - 124) / 28;
			if (((m.x - 124) % 28) >= 16)
				x1 = (m.x - 124) / 28 + 1;
			if (((m.y - 44) % 28) <= 12)
				y1 = (m.y - 44) / 28;
			if (((m.y - 44) % 28) >= 16)
				y1 = (m.y - 44) / 28 + 1;
			if (count % 2 == 0)
			{
				if (arr[x1][y1] != 0)
				{
					count--;
				}
				else
				{
					create_white_piece(x1, y1);
					arr[x1][y1] = 2;
					judgeWin();
					create_black_piece(16, 5.3);
					RECT a = { 513,154,636,294 };
					drawtext(_T("黑方下棋"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
			else
			{
				if (arr[x1][y1] != 0)
				{
					count--;
				}
				else
				{
					create_black_piece(x1, y1);
					arr[x1][y1] = 1;
					judgeWin();
					create_white_piece(16, 5.3);
					RECT a = { 513,154,636,294 };
					drawtext(_T("白方下棋"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
			}
			break;
		case WM_RBUTTONDOWN:
			s = 0;
			main();
			break;
		}
	}
}
int main()
{
	initgraph(640, 480);
	initmap();
	gaming();
	getch();
	closegraph();
	return 0;
}
