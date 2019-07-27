#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<MMSystem.h>
#include<conio.h>
#include <fstream>
#include<string.h>
#include<thread>
#include<time.h>
#pragma comment(lib,"Winmm.lib")
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define block_cnt 28
using namespace std;
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ������� �Լ��� ���Ǵ� ������ 
void setcursortype(CURSOR_TYPE c);
void mainsquare();
void nameprint();
void mainprint();
int select(int x, int y);
void drawsquare();
void drawnext();
void drawscore();
void inputranking();
void setranking();
void setscore(bool check);
void game();
void gamestart();
void gamemethod();
void gamerank();
void gotoxy(int x, int y);
void textcolor(int color_number);
bool blocks[][4][4] = {//��Ʈ�������� ���Ǵ� ���迭
	{
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},//��������
	{
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1,0,  0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
		//������
		//��
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
		//  ��
		//������
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
		//����
		//����

	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
		//��
		//������
	{
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
		//  ����
		//����
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},


		//����
		//  ����
};
struct user{//����� ����
	char name[7];
	int score;
};
bool spacecheck[18][16] = { 0 };//�����ġ�� ���� �ִ� �� üũ�ϴ� �迭
user *me;//�����÷��̾ ���������� ����
int stage = 1;//���� ��������
void setcursortype(CURSOR_TYPE c){ //Ŀ������� �Լ� 
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void mainsquare(){//����ȭ��, ���ӷ�ŷ, ���ӹ���� �簢Ʋ�� ����� �Լ�
	int i, j;
	unsigned char b = 0xa6, dr[7];
	for (i = 1; i < 7; i++)
		dr[i] = 0xa0 + i;
	printf("%c%c", b, dr[3]);
	for (i = 0; i < 35; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[4]);
	cout << endl;
	for (i = 0; i < 22; i++){
		printf("%c%c", b, dr[2]);
		for (j = 0; j < 35; j++)
			printf("  ");
		printf("%c%c", b, dr[2]);
		cout << endl;
	}
	printf("%c%c", b, dr[6]);
	for (i = 0; i < 35; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[5]);
	//Ʋ�����
}
void nameprint(){//ȭ�鸶�� �̴ϼ� �ִ� �Լ�
	gotoxy(63,25);
	cout << "2219 ������";
}
void mainprint(){//����ȭ���� ����Ʈ�ϴ� �Լ�
	system("cls");
	int x = 43, y = 13;
	textcolor(15);
	mainsquare();
	nameprint();
	gotoxy(1, 1);
	gotoxy(3, 4);
	textcolor(1);
	cout << "      �����  ";
	textcolor(2);
	cout << "�����  ";
	textcolor(4);
	cout << "�����  ";
	textcolor(6);
	cout << "�����   ";
	textcolor(8);
	cout << "����   ";
	textcolor(5);
	cout << "����";

	gotoxy(3, 5);
	textcolor(1);
	cout << "         ��     ";
	textcolor(2);
	cout << "��           ";
	textcolor(4);
	cout << "��     ";
	textcolor(6);
	cout << "��     ��    ";
	textcolor(8);
	cout << "��    ";
	textcolor(5);
	cout << "��    ��";

	gotoxy(3, 6);
	textcolor(1);
	cout << "         ��     ";
	textcolor(2);
	cout << "�����     ";
	textcolor(4);
	cout << "��     ";
	textcolor(6);
	cout << "�����     ";
	textcolor(8);
	cout << "��     ";
	textcolor(5);
	cout << "����";

	gotoxy(3, 7);
	textcolor(1);
	cout << "         ��     ";
	textcolor(2);
	cout << "��           ";
	textcolor(4);
	cout << "��     ";
	textcolor(6);
	cout << "��    ��     ";
	textcolor(8);
	cout << "��          ";
	textcolor(5);
	cout << "��";

	gotoxy(3, 8);
	textcolor(1);
	cout << "         ��     ";
	textcolor(2);
	cout << "�����     ";
	textcolor(4);
	cout << "��     ";
	textcolor(6);
	cout << "��     ��  ";
	textcolor(8);
	cout << "����   ";
	textcolor(5);
	cout << "���� ";//����ȭ���� �ΰ����

	textcolor(7);//���� �Ͼ������ �ʱ�ȭ

	gotoxy(3, 13); 
	cout << "                              ���ӽ���" << endl << endl;
	gotoxy(3, 15);
	cout << "                              ���ӹ��" << endl << endl;
	gotoxy(3, 17);
	cout << "                              ���ӷ�ũ" << endl << endl;
	gotoxy(x, y);
	cout << "��";//�޴� ���
	int check = select(x,y);
	

	switch (check){
	case 1:
		gamestart();
		break;
	case 2:
		gamemethod();
		break;
	case 3:
		gamerank();
		break;
	}

	system("pause>null");//������ ������ �ʵ���(���~ �ȳ�ǥ�� ������)


}
int select(int x, int y){//����ȭ���� �޴��� ������ �� �ְ� �ϰ� ���ð��� �������ִ� �Լ�
	char key = 0;
	int select = 1;
	while (key != KEY_ENTER){
		key = _getch();
		if (key == KEY_UP && y>=15){
			gotoxy(x, y);
			cout << "  ";
			y -= 2;
			gotoxy(x, y);
			cout << "��";
			select--;
		}
		else if (key == KEY_DOWN && y<=15){
			gotoxy(x, y);
			cout << "  ";
			y += 2;
			gotoxy(x, y);
			cout << "��";
			select++;
		}
	}
	return select;//���ð� ����

}
void drawsquare(){//����ȭ�� �� ��Ʈ������ ���������� ����Ǵ� ���� �簢Ʋ
	unsigned char b = 0xa6, dr[7];
	int i, j;
	for (i = 1; i < 7; i++)
		dr[i] = 0xa0 + i;
	printf("%c%c", b, dr[3]);
	for (i = 0; i < 16; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[4]);
	cout << endl;
	for (i = 0; i < 22; i++){
		if (i == 3) printf("%c%c", b, dr[1]);
		else printf("%c%c", b, dr[2]);
		for (j = 0; j < 16; j++)
			printf("  ");
		if (i == 3) printf("%c%c", b, dr[1]);
		else printf("%c%c", b, dr[2]);
		cout << endl;
	}
	printf("%c%c", b, dr[6]);
	for (i = 0; i < 16; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[5]);
}
void drawnext(){//������ ����Ű����� ������ ���� ���� �����ִ� �Լ�
	unsigned char b = 0xa6, dr[7];
	int i, j, x = 45, y = 3;
	gotoxy(x, y);
	cout << "        �� �� : �¿��̵�";
	gotoxy(x, ++y);
	cout << " ��  : �Ʒ��̵�   �� : ��ȸ��";
	//������ ����Ű ����
	y += 3;
	gotoxy(x, y);


	for (i = 1; i < 7; i++)
		dr[i] = 0xa0 + i;
	//������ ���
	printf("%c%c", b, dr[3]);
	printf("%c%c", b, dr[1]);
	cout << "   N E X T  ";
	printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[4]);
	for (i = 0; i < 6; i++){
		gotoxy(x, ++y);
		printf("%c%c", b, dr[2]);
		for (j = 0; j < 8; j++)
			printf("  ");
		printf("%c%c", b, dr[2]);
	}
	gotoxy(x, ++y);
	printf("%c%c", b, dr[6]);
	for (i = 0; i < 8; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[5]);

}
void drawscore(){//��Ʈ���� ����ȭ���� �̸�, ���� ����ϴ��Լ�
	unsigned char b = 0xa6, dr[7];
	int i, j,x = 45,y=16;
	for (i = 1; i < 7; i++)
		dr[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", b, dr[3]);
	printf("%c%c", b, dr[1]);
	cout << "  S C O R E ";
	printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[4]);
	for (i = 0; i < 7; i++){
		gotoxy(x, ++y);
		printf("%c%c", b, dr[2]);
		for (j = 0; j < 8; j++)
			printf("  ");
		printf("%c%c", b, dr[2]);
	}
	gotoxy(x, ++y);
	printf("%c%c", b, dr[6]);
	for (i = 0; i < 8; i++)
		printf("%c%c", b, dr[1]);
	printf("%c%c", b, dr[5]);
	//Ʋ�����
	gotoxy(48, 18);
	cout << "  STAGE [ " << stage << " ]";//���� �������� ���
	gotoxy(48, 20);
	cout << "NAME : " << me->name;//�̸����
	gotoxy(48, 22);
	cout << "SCORE : " << 0;//�ʱ��������
	nameprint();
}
void inputranking(){//���� �÷��̾��� ���� �� �� ����ó���ϴ� �Լ�
	int index = 0 , x = 8, y = 5;
	string filename = "user_ranking.txt";
	char user_information[20], *now, user_tok[] = ",", *left = NULL;
	user ranking_user[5];
	ifstream ur;
	ofstream of;
	ur.open(filename.data());
	if (ur.is_open()){//���Ͽ���
		while (ur.getline(user_information, sizeof(user_information)) && index < 5){
			now = strtok_s(user_information, user_tok, &left);
			strcpy_s(ranking_user[index].name, now);
			now = strtok_s(NULL, user_tok, &left);
			ranking_user[index].score = atoi(now);
			index++;
		}
	}
	for (int i = index; i < 5; i++)
		ranking_user[i].name[0] = 0;
	for (int i = 0; i <= index; i++){
		if (ranking_user[i].name && (ranking_user[i].score < me->score)){//���Ͽ� ��ϵ� ������ �÷��̾� ���� ��
			for (int j = 3; j >= i; j--){//�迭 �ε����� 0~4�����̴� j�� 3���� ����
				strcpy_s(ranking_user[j + 1].name, ranking_user[j].name);
				ranking_user[j + i].score = ranking_user[j].score;
			}
			strcpy_s(ranking_user[i].name, me->name);
			ranking_user[i].score = me->score;
			//�ش� ������ �����÷��̾� ���� ī��
			break;
		}
	}
	of.open(filename);
	for (int i = 0; i <= index; i++){
		if (ranking_user[i].name){
			of << ranking_user[i].name << "," << ranking_user[i].score << endl;
		}
	}//���Ͽ� ���ο� ��ŷ ���

	gotoxy(x, y);
	cout << "[ ��ŷ Ȯ�� - ENTER ]";
	delete me;
	_getch();
	char input = _getch();
	if (input == KEY_ENTER)
		gamerank();
	else return;
}
void setranking(){//����ȭ�鿡�� ���ӷ�ũ�� �������� �� ��ŷ�� ����ϴ� �Լ�
	int i = 0, x = 20, y = 6;
	string filename = "user_ranking.txt";
	char user_information[20], *now, user_tok[] = ",", *left = NULL;
	user ranking_user[5];
	ifstream ur;
	ur.open(filename.data());//���Ͽ���
	if (ur.is_open()){
		while (ur.getline(user_information, sizeof(user_information)) && i < 5){
				x = 20;
				now = strtok_s(user_information, user_tok, &left);//','��ū�� �������� ���ڿ� �и�
				strcpy_s(ranking_user[i].name, now);
				now = strtok_s(NULL, user_tok,&left);
				ranking_user[i].score = atoi(now);
				//������� ��ŷ�迭�� �÷��̾� ���� ���
				//���⼭���� ���
				gotoxy(x, y);
				cout << "[" << i + 1 << "]";
				x += 5;
				gotoxy(x, y);
				cout << "name : " << ranking_user[i].name;
				x += 16;
				gotoxy(x, y);
				cout << "score : " << ranking_user[i].score;
				y += 3;
				i++;
		//	}
		}
	}

}
void setscore(bool check){// ����, ���������� �ٲ��ִ� �Լ�
	if (check)
		me->score += 10;//���� �׾��� ��
	else me->score += 50;//�� ���� ������ ��


	stage = (me->score/500)+1;//500���� ������ �������� ����
	gotoxy(58, 18);
	cout << stage;//�������� ���
	if (stage == 10){//�������� 10�� �޼��ϸ� ���ʽ� 1000���� �� �� ����
		gotoxy(8, 5);
		cout << "�� ���ʽ� +1000 ��";
		me->score += 1000;
		system("pause>null");
		mainprint();
	}

	textcolor(7);
	gotoxy(56, 22);
	cout << me->score;//�������
}
void game(){//���� ������ ����Ǵ� ��Ʈ���� ����
	srand((unsigned)time(NULL));
	int nowblockrand, nextblockrand = rand() % 7, i, j, c, z, x = 15, y = 1, row = 0, col = 0, max = 25, nowcolor = 0, nextcolor = rand() % 14 + 1, plusx = 0, upkey = 0, blocksu = 0, nowy = 0, nowx = 0;
	bool contact = true, flagr, flagc, nextblock[4][4];
	bool  notover = true, nowblock[4][4];
	thread gamet([&](){//���� ���� �Լ��� �����ϴ� ������
		while (notover && stage < 10){//���� �Ѱ輱�� �Ѿ�����, ���������� 10�� �Ѿ����� Ȯ��
			upkey = 0;
			contact = true;
			y = 1;
			x = 15;
			row = 0;
			col = 0;
			nowcolor = nextcolor;
			for (z = 0; z < 4; z++)
			for (c = 0; c < 4; c++){
				nowblock[z][c] = 0;
				nextblock[z][c] = 0;
			}
			nextcolor = rand() % 14 + 1;
			nowblockrand = nextblockrand;
			nextblockrand = rand() % 7;
			textcolor(nextcolor);
			for (i = 0; i < 4; i++){
				for (j = 0; j < 4; j++){
					gotoxy(52, 10 + i);
					cout << "        ";
				}
			}//NEXT�� ĭ �����ֱ�
			for (i = 0; i < 4; i++){
				plusx = 0;
				for (j = 0; j < 4; j++){
					if (blocks[nextblockrand * 4][i][j]){
						gotoxy(52 + plusx, 10 + i);
						nextblock[i][j] = true;//������ ���� ����ش�
						cout << "��";
					}
					plusx += 2;
				}
			}//���� �� ���

			textcolor(nowcolor);
			for (i = 0; i < 4; i++){
				flagr = false;
				y++;
				for (j = 0; j < 4; j++){
					if (blocks[nowblockrand * 4][i][j]){
						nowblock[i][j] = true;
						gotoxy(x, y);
						cout << "��";
						flagr = true;
					}
					x += 2;
				}
				if (flagr) row++;//���� ���α��̰� ����������� ����
				flagc = false;
				for (j = 0; j < 4;  j++){
					if (blocks[nowblockrand * 4][j][i]){
						flagc = true;
					}
				}
				if (flagc) col++;//���� ���� ���̰� ����������� ����
				x -= 8;
			}//���� �� ���

			y = (y - 3 + row);
			while (contact){//���� �ٴڿ� ��Ҵ��� Ȯ��
				blocksu = 0;
				y -= row;
				for (i = 0; i < row; i++){
					for (j = 0; j < 4; j++){
						gotoxy(x, y);
						if (nowblock[i][j]) cout << "  ";
						x += 2;
					}
					y++;
					x -= 8;
				}
				y -= (row - 1);
				for (i = 0; i < row; i++){
					for (j = 0; j < 4; j++){
						gotoxy(x, y);
						if (nowblock[i][j]) cout << "��";
						x += 2;
					}
					y++;
					x -= 8;//
				}
				Sleep(500-(stage*50));//�������� �ӵ� ������

				bool setcheck = false;
				for (int i = 0; i < row; i++){
					for (int j = 0; j < col; j++){
						if (nowblock[i][j] &&( y + 1 >= max || spacecheck[(y - 5) - (row - i)][(x / 2 - 1) + j])){//�ؿ� ���ִ� �� Ȯ��

							for (int z = 0; z < row; z++){
								for (int q = 0; q < col; q++){
									if (nowblock[z][q]){
										nowy = (y - 6) - (row - z);//�迭�� üũ�� ����ġ
										nowx = (x / 2 - 1) + q;//�迭�� üũ�� ����ġ
										if (nowy < 0){ notover = false; return; }//���� �Ѱ�ġ�� �Ѿ��� ���
										spacecheck[nowy][nowx] = true;
									}
								}
							}
							setcheck = true;
							contact = false;
					}
				}

				}
				if (setcheck){//���� �������� ��
					y -= row;
					textcolor(15);//������ ���� ������� ��������
					for (int z = 0; z < row; z++){
						for (int q = 0; q < col; q++){
							gotoxy(x, y);
							if (nowblock[z][q]) cout << "��";
							x += 2;
						}
						y++;
						x -= col * 2;
					}
					for (int z = 0; z < 18; z++){
						int linecheck = 0;
						for (int q = 0; q < 16; q++){
							if (spacecheck[z][q]){
								linecheck++;
								if (linecheck == 16){//������ ��� ä������ ��
									for (int iz =  z; iz > 0; iz--){
										for (int iq = 0; iq < 16; iq++){
											spacecheck[iz][iq] = spacecheck[iz-1][iq];
										}
									}//ä���� �ٺ��� �� �پ� ������
									for (int iq = 0; iq < 16; iq++)
										spacecheck[0][iq] = 0;
									textcolor(15);
									x = 3; y = 6;
									for (int iz = 0; iz < 18; iz++){
										for (int iq = 0; iq < 16; iq++){
											gotoxy(x, y);
											if (spacecheck[iz][iq]){
												cout << "��";
											}
											else{
												cout << "  ";
											}
											x += 2;
										}
										y++;
										x -= 16 * 2;
									}//���� ä������ ��� ���� üũ�� �迭�� ���� ���
									setscore(false);//�������(50)
								}
							}
						}
					}
					setscore(true);//�������(10)
				}
			}
		}
	});
	thread controlt([&](){//����Ű�� ���� �Լ��� �����ϴ� ������
		while (notover && stage < 10){//���� �Ѱ輱�� �Ѿ�����, ���������� 10�� �Ѿ����� Ȯ��
			char input = _getch();
			switch (input){
			case KEY_LEFT://�������̵�
				if (x > 3){
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							cout << "  ";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//�������
					x -= 2;
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "��";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//�����
				}
				break;
			case KEY_RIGHT://�� ������ �̵�
				if ((x + col * 2) <= 33){
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j <= col; j++){
							gotoxy(x, y);
							cout << "  ";
							x += 2;
						}
						y++;
						x -= (col+1) * 2;
					}
					//�������
					x += 2;
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "��";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//�� ���
				}
				break;

			case KEY_DOWN://�� �Ʒ��� �̵�
				if (y+3<max){//���� ����Ʋ�� ����� �ʵ��� üũ
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							cout << "  ";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//�������
					y -= (row - 2);
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "��";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//�����
				}
				break;
			case KEY_UP://�� ���� ����
				int temp;
				for (i = 0; i < 4; i++){
					for (j = 0; j < col; j++){
						gotoxy(x, y-4);
						cout << "  ";
						x += 2;
					}
					y++;
					x -= col * 2;
				}//�� �����
				y -= 4;
				upkey++;
				if (upkey > 3)
					upkey %= 4;
				//key�� ��������� 0~3, �� �װ����� ����
				y -= row;
				temp = col;
				col = row;
				row = temp;
				//����, ���� ���� �ٲ���
				if (x + col * 2 > 33)
					x -= (x + col * 2) - 33;//���� ���ȴµ� ���� Ʋ������ ���°��
				
				for (i = 0; i < 4; i++){
					for (j = 0; j < 4; j++){
						nowblock[i][j] = false;
						if (blocks[nowblockrand * 4+upkey][i][j]){
							nowblock[i][j] = true;
						}
					}
				}//���� ��� ��� �ٲ��ֱ�
				for (i = 0; i < row; i++){
					for (j = 0; j < col; j++){
						gotoxy(x, y);
						if (nowblock[i][j]) cout << "��";
						x += 2;
					}
					y++;
					x -= col * 2;
				}
				//��� ���

				break;
			}
		}
	});
	gamet.join();
	controlt.join();
	//�����带 �̿��Ͽ� ���ÿ� �� ���� ����
}
void gamestart(){//���ӽ����� ���� ���� ��Ʈ���� ȭ�鱸��
	PlaySound(NULL, 0, 0);//�뷡����
	system("cls");//ȭ�� �����
	me = new user;//���� �÷��̾� �����Ҵ�
	me->name[0] = 0;
	me->score = 0;
	nameprint();
	gotoxy(1, 1);
	cout << " User Name (�ִ� 6����) : ";
	cin >> me->name;//����� �̸� �Է�
	system("cls");
	drawsquare();//�簢Ʋ�����
	drawnext();//������ �� ������ ����Ű ���
	drawscore();//������������
	game();//���ӽ���
	inputranking();//�÷��̾� ���� Ȯ�� �� ����ó�� & ��ŷȮ�� �Ǵ� �����̵� üũ
}
void gamemethod(){//���ӹ���� ����ϴ� �Լ�
	int x = 4, y = 2;
	system("cls");
	mainsquare();
	gotoxy(30, y);
	cout << "[ T E T R I S ]";
	y += 3;
	gotoxy(x, y);
	cout << "- ���۹� : �� �����̵�, �� �������̵�,";
	gotoxy(x, ++y);
	cout << "          �� ��ȸ��, �� �Ʒ����̵�";
	y += 2;
	gotoxy(x, y);
	cout << "- 7���� ������ ���� �������� ������ ��������.";
	y += 2;
	gotoxy(x, y);
	cout << "- ���� �ð�ݴ�������� 90��ȸ����ų �� ������ �ٴ��� ������";
	gotoxy(x, ++y);
	cout << "  ��ƴ���� ä�����Ѵ�.";
	y += 2;
	gotoxy(x, y);
	cout << "- ���� ������ ä��� �Ǹ� ���� �������� �ӵ��� ��������.";
	y += 2;
	gotoxy(x, y);
	cout << "- ���� �Ѱ輱(��)�� �Ѱ� �Ǹ� ������ ����ȴ�.";
	y += 2;
	gotoxy(x, y);
	cout << "- ���� �÷��̾� ������ �� ������(5��)�ȿ� ��� �Ǹ� ��ŷ�� ��ϵȴ�.";

	y += 3;
	gotoxy(++x, y);
	cout << "[ENTER�� ���� �� ����ȭ������, �ƹ�Ű�� ���� �� ����ȭ������ �̵�]";
	nameprint();
	char input = _getch();

	if (input == KEY_ENTER)
		gamestart();
	else
		return;
}
void gamerank(){//��ŷ�� �����ִ� �Լ�
	system("cls");
	textcolor(15);
	mainsquare();
	gotoxy(28,3);
	cout << "[ R A N K I N G ]";
	gotoxy(5,22);//�ӽ�
	cout << "[ENTER�� ���� �� ����ȭ������, �ƹ�Ű�� ���� �� ����ȭ������ �̵�]";
	setranking();
	nameprint();
	char input = _getch();
	if (input == KEY_ENTER)
		gamestart();
	else
		return;
}
void gotoxy(int x, int y) {//��ǥ �̵��ϴ� �Լ�
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int color_number)//���ڻ� �ٲٴ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
int main(){//����
	setcursortype(NOCURSOR);
//	sndPlaySoundA("E:\\tetris.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);//���ǽ��� / ���� �� ���(F/E) ��Ȯ��!
	while (1){
		mainprint();
	}
	return 0;
}
//������ ��� , ����, ������, �� ��3���� �� �ְ� ���