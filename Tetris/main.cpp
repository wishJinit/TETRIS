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
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 
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
bool blocks[][4][4] = {//테트리스에서 사용되는 블럭배열
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
	},//ㅇㅇㅇㅇ
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
		//ㅇㅇㅇ
		//ㅇ
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
		//  ㅇ
		//ㅇㅇㅇ
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
		//ㅇㅇ
		//ㅇㅇ

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
		//ㅇ
		//ㅇㅇㅇ
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
		//  ㅇㅇ
		//ㅇㅇ
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


		//ㅇㅇ
		//  ㅇㅇ
};
struct user{//사용자 정보
	char name[7];
	int score;
};
bool spacecheck[18][16] = { 0 };//어느위치에 블럭이 있는 지 체크하는 배열
user *me;//현재플레이어를 전역변수로 선언
int stage = 1;//현재 스테이지
void setcursortype(CURSOR_TYPE c){ //커서숨기는 함수 
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
void mainsquare(){//메인화면, 게임랭킹, 게임방법의 사각틀을 만드는 함수
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
	//틀만들기
}
void nameprint(){//화면마다 이니셜 넣는 함수
	gotoxy(63,25);
	cout << "2219 진유진";
}
void mainprint(){//메인화면을 프린트하는 함수
	system("cls");
	int x = 43, y = 13;
	textcolor(15);
	mainsquare();
	nameprint();
	gotoxy(1, 1);
	gotoxy(3, 4);
	textcolor(1);
	cout << "      ■■■■  ";
	textcolor(2);
	cout << "■■■■  ";
	textcolor(4);
	cout << "■■■■  ";
	textcolor(6);
	cout << "■■■■   ";
	textcolor(8);
	cout << "■■■   ";
	textcolor(5);
	cout << "■■■";

	gotoxy(3, 5);
	textcolor(1);
	cout << "         ■     ";
	textcolor(2);
	cout << "■           ";
	textcolor(4);
	cout << "■     ";
	textcolor(6);
	cout << "■     ■    ";
	textcolor(8);
	cout << "■    ";
	textcolor(5);
	cout << "■    ■";

	gotoxy(3, 6);
	textcolor(1);
	cout << "         ■     ";
	textcolor(2);
	cout << "■■■■     ";
	textcolor(4);
	cout << "■     ";
	textcolor(6);
	cout << "■■■■     ";
	textcolor(8);
	cout << "■     ";
	textcolor(5);
	cout << "■■■";

	gotoxy(3, 7);
	textcolor(1);
	cout << "         ■     ";
	textcolor(2);
	cout << "■           ";
	textcolor(4);
	cout << "■     ";
	textcolor(6);
	cout << "■    ■     ";
	textcolor(8);
	cout << "■          ";
	textcolor(5);
	cout << "■";

	gotoxy(3, 8);
	textcolor(1);
	cout << "         ■     ";
	textcolor(2);
	cout << "■■■■     ";
	textcolor(4);
	cout << "■     ";
	textcolor(6);
	cout << "■     ■  ";
	textcolor(8);
	cout << "■■■   ";
	textcolor(5);
	cout << "■■■ ";//메인화면의 로고출력

	textcolor(7);//색을 하얀색으로 초기화

	gotoxy(3, 13); 
	cout << "                              게임시작" << endl << endl;
	gotoxy(3, 15);
	cout << "                              게임방법" << endl << endl;
	gotoxy(3, 17);
	cout << "                              게임랭크" << endl << endl;
	gotoxy(x, y);
	cout << "◀";//메뉴 출력
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

	system("pause>null");//음악이 멈추지 않도록(계속~ 안내표시 없도록)


}
int select(int x, int y){//메인화면의 메뉴를 선택할 수 있게 하고 선택값을 리턴해주는 함수
	char key = 0;
	int select = 1;
	while (key != KEY_ENTER){
		key = _getch();
		if (key == KEY_UP && y>=15){
			gotoxy(x, y);
			cout << "  ";
			y -= 2;
			gotoxy(x, y);
			cout << "◀";
			select--;
		}
		else if (key == KEY_DOWN && y<=15){
			gotoxy(x, y);
			cout << "  ";
			y += 2;
			gotoxy(x, y);
			cout << "◀";
			select++;
		}
	}
	return select;//선택값 리턴

}
void drawsquare(){//게임화면 중 테트리스가 직접적으로 실행되는 곳의 사각틀
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
void drawnext(){//간단한 조작키설명과 다음에 나올 블럭을 보여주는 함수
	unsigned char b = 0xa6, dr[7];
	int i, j, x = 45, y = 3;
	gotoxy(x, y);
	cout << "        ← → : 좌우이동";
	gotoxy(x, ++y);
	cout << " ↓  : 아래이동   ↑ : 블럭회전";
	//간단한 조작키 설명
	y += 3;
	gotoxy(x, y);


	for (i = 1; i < 7; i++)
		dr[i] = 0xa0 + i;
	//다음블럭 출력
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
void drawscore(){//테트리스 게임화면의 이름, 점수 출력하는함수
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
	//틀만들기
	gotoxy(48, 18);
	cout << "  STAGE [ " << stage << " ]";//현재 스테이지 출력
	gotoxy(48, 20);
	cout << "NAME : " << me->name;//이름출력
	gotoxy(48, 22);
	cout << "SCORE : " << 0;//초기점수출력
	nameprint();
}
void inputranking(){//현재 플레이어의 점수 비교 후 파일처리하는 함수
	int index = 0 , x = 8, y = 5;
	string filename = "user_ranking.txt";
	char user_information[20], *now, user_tok[] = ",", *left = NULL;
	user ranking_user[5];
	ifstream ur;
	ofstream of;
	ur.open(filename.data());
	if (ur.is_open()){//파일열기
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
		if (ranking_user[i].name && (ranking_user[i].score < me->score)){//파일에 기록된 점수와 플레이어 점수 비교
			for (int j = 3; j >= i; j--){//배열 인덱스가 0~4까지이니 j는 3부터 시작
				strcpy_s(ranking_user[j + 1].name, ranking_user[j].name);
				ranking_user[j + i].score = ranking_user[j].score;
			}
			strcpy_s(ranking_user[i].name, me->name);
			ranking_user[i].score = me->score;
			//해당 순위에 현재플레이어 정보 카피
			break;
		}
	}
	of.open(filename);
	for (int i = 0; i <= index; i++){
		if (ranking_user[i].name){
			of << ranking_user[i].name << "," << ranking_user[i].score << endl;
		}
	}//파일에 새로운 랭킹 등록

	gotoxy(x, y);
	cout << "[ 랭킹 확인 - ENTER ]";
	delete me;
	_getch();
	char input = _getch();
	if (input == KEY_ENTER)
		gamerank();
	else return;
}
void setranking(){//메인화면에서 게임랭크을 선택했을 때 랭킹을 출력하는 함수
	int i = 0, x = 20, y = 6;
	string filename = "user_ranking.txt";
	char user_information[20], *now, user_tok[] = ",", *left = NULL;
	user ranking_user[5];
	ifstream ur;
	ur.open(filename.data());//파일열기
	if (ur.is_open()){
		while (ur.getline(user_information, sizeof(user_information)) && i < 5){
				x = 20;
				now = strtok_s(user_information, user_tok, &left);//','토큰을 기준으로 문자열 분리
				strcpy_s(ranking_user[i].name, now);
				now = strtok_s(NULL, user_tok,&left);
				ranking_user[i].score = atoi(now);
				//순서대로 랭킹배열에 플레이어 정보 등록
				//여기서부터 출력
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
void setscore(bool check){// 점수, 스테이지를 바꿔주는 함수
	if (check)
		me->score += 10;//블럭을 쌓았을 때
	else me->score += 50;//한 줄을 없앴을 때


	stage = (me->score/500)+1;//500점을 텀으로 스테이지 증가
	gotoxy(58, 18);
	cout << stage;//스테이지 출력
	if (stage == 10){//스테이지 10을 달성하면 보너스 1000점을 준 후 종료
		gotoxy(8, 5);
		cout << "★ 보너스 +1000 ★";
		me->score += 1000;
		system("pause>null");
		mainprint();
	}

	textcolor(7);
	gotoxy(56, 22);
	cout << me->score;//점수출력
}
void game(){//좌측 블럭에서 실행되는 테트리스 게임
	srand((unsigned)time(NULL));
	int nowblockrand, nextblockrand = rand() % 7, i, j, c, z, x = 15, y = 1, row = 0, col = 0, max = 25, nowcolor = 0, nextcolor = rand() % 14 + 1, plusx = 0, upkey = 0, blocksu = 0, nowy = 0, nowx = 0;
	bool contact = true, flagr, flagc, nextblock[4][4];
	bool  notover = true, nowblock[4][4];
	thread gamet([&](){//블럭에 관한 함수를 실행하는 스레드
		while (notover && stage < 10){//블럭이 한계선을 넘었는지, 스테이지가 10을 넘었는지 확인
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
			}//NEXT블럭 칸 지워주기
			for (i = 0; i < 4; i++){
				plusx = 0;
				for (j = 0; j < 4; j++){
					if (blocks[nextblockrand * 4][i][j]){
						gotoxy(52 + plusx, 10 + i);
						nextblock[i][j] = true;//현재의 블럭을 담아준다
						cout << "■";
					}
					plusx += 2;
				}
			}//다음 블럭 출력

			textcolor(nowcolor);
			for (i = 0; i < 4; i++){
				flagr = false;
				y++;
				for (j = 0; j < 4; j++){
					if (blocks[nowblockrand * 4][i][j]){
						nowblock[i][j] = true;
						gotoxy(x, y);
						cout << "■";
						flagr = true;
					}
					x += 2;
				}
				if (flagr) row++;//블럭의 세로길이가 어느정도인지 세줌
				flagc = false;
				for (j = 0; j < 4;  j++){
					if (blocks[nowblockrand * 4][j][i]){
						flagc = true;
					}
				}
				if (flagc) col++;//블럭의 가로 길이가 어느정도인지 세줌
				x -= 8;
			}//현재 블럭 출력

			y = (y - 3 + row);
			while (contact){//블럭이 바닥에 닿았는지 확인
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
						if (nowblock[i][j]) cout << "■";
						x += 2;
					}
					y++;
					x -= 8;//
				}
				Sleep(500-(stage*50));//떨어지는 속도 늦춰줌

				bool setcheck = false;
				for (int i = 0; i < row; i++){
					for (int j = 0; j < col; j++){
						if (nowblock[i][j] &&( y + 1 >= max || spacecheck[(y - 5) - (row - i)][(x / 2 - 1) + j])){//밑에 블럭있는 지 확인

							for (int z = 0; z < row; z++){
								for (int q = 0; q < col; q++){
									if (nowblock[z][q]){
										nowy = (y - 6) - (row - z);//배열에 체크할 행위치
										nowx = (x / 2 - 1) + q;//배열에 체크할 열위치
										if (nowy < 0){ notover = false; return; }//블럭이 한계치를 넘었을 경우
										spacecheck[nowy][nowx] = true;
									}
								}
							}
							setcheck = true;
							contact = false;
					}
				}

				}
				if (setcheck){//블럭이 안착했을 때
					y -= row;
					textcolor(15);//안착한 블럭은 흰색으로 변경해줌
					for (int z = 0; z < row; z++){
						for (int q = 0; q < col; q++){
							gotoxy(x, y);
							if (nowblock[z][q]) cout << "■";
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
								if (linecheck == 16){//한줄이 모두 채워졌을 때
									for (int iz =  z; iz > 0; iz--){
										for (int iq = 0; iq < 16; iq++){
											spacecheck[iz][iq] = spacecheck[iz-1][iq];
										}
									}//채워진 줄부터 한 줄씩 밑으로
									for (int iq = 0; iq < 16; iq++)
										spacecheck[0][iq] = 0;
									textcolor(15);
									x = 3; y = 6;
									for (int iz = 0; iz < 18; iz++){
										for (int iq = 0; iq < 16; iq++){
											gotoxy(x, y);
											if (spacecheck[iz][iq]){
												cout << "■";
											}
											else{
												cout << "  ";
											}
											x += 2;
										}
										y++;
										x -= 16 * 2;
									}//한줄 채워졌을 경우 새로 체크한 배열로 새로 출력
									setscore(false);//점수상승(50)
								}
							}
						}
					}
					setscore(true);//점수상승(10)
				}
			}
		}
	});
	thread controlt([&](){//조작키에 관한 함수를 실행하는 스레드
		while (notover && stage < 10){//블럭이 한계선을 넘었는지, 스테이지가 10을 넘었는지 확인
			char input = _getch();
			switch (input){
			case KEY_LEFT://블럭왼쪽이동
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
					}//블럭지우기
					x -= 2;
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "■";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//블럭출력
				}
				break;
			case KEY_RIGHT://블럭 오른쪽 이동
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
					//블럭지우기
					x += 2;
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "■";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//블럭 출력
				}
				break;

			case KEY_DOWN://블럭 아래로 이동
				if (y+3<max){//블럭이 게임틀을 벗어나지 않도록 체크
					y -= row;
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							cout << "  ";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//블럭지우기
					y -= (row - 2);
					for (i = 0; i < row; i++){
						for (j = 0; j < col; j++){
							gotoxy(x, y);
							if (nowblock[i][j]) cout << "■";
							x += 2;
						}
						y++;
						x -= col * 2;
					}//블럭출력
				}
				break;
			case KEY_UP://블럭 각도 변경
				int temp;
				for (i = 0; i < 4; i++){
					for (j = 0; j < col; j++){
						gotoxy(x, y-4);
						cout << "  ";
						x += 2;
					}
					y++;
					x -= col * 2;
				}//블럭 지우기
				y -= 4;
				upkey++;
				if (upkey > 3)
					upkey %= 4;
				//key의 변경범위를 0~3, 총 네가지로 제한
				y -= row;
				temp = col;
				col = row;
				row = temp;
				//가로, 세로 길이 바꿔줌
				if (x + col * 2 > 33)
					x -= (x + col * 2) - 33;//블럭을 돌렸는데 블럭이 틀밖으로 나온경우
				
				for (i = 0; i < 4; i++){
					for (j = 0; j < 4; j++){
						nowblock[i][j] = false;
						if (blocks[nowblockrand * 4+upkey][i][j]){
							nowblock[i][j] = true;
						}
					}
				}//현재 블록 모양 바꿔주기
				for (i = 0; i < row; i++){
					for (j = 0; j < col; j++){
						gotoxy(x, y);
						if (nowblock[i][j]) cout << "■";
						x += 2;
					}
					y++;
					x -= col * 2;
				}
				//블록 출력

				break;
			}
		}
	});
	gamet.join();
	controlt.join();
	//스레드를 이용하여 동시에 블럭 조작 가능
}
void gamestart(){//게임시작을 누른 후의 테트리스 화면구성
	PlaySound(NULL, 0, 0);//노래멈춤
	system("cls");//화면 비워줌
	me = new user;//현재 플레이어 동적할당
	me->name[0] = 0;
	me->score = 0;
	nameprint();
	gotoxy(1, 1);
	cout << " User Name (최대 6글자) : ";
	cin >> me->name;//사용자 이름 입력
	system("cls");
	drawsquare();//사각틀만들기
	drawnext();//다음블럭 및 간단한 조작키 출력
	drawscore();//사용자정보출력
	game();//게임시작
	inputranking();//플레이어 점수 확인 후 파일처리 & 랭킹확인 또는 메인이동 체크
}
void gamemethod(){//게임방법을 출력하는 함수
	int x = 4, y = 2;
	system("cls");
	mainsquare();
	gotoxy(30, y);
	cout << "[ T E T R I S ]";
	y += 3;
	gotoxy(x, y);
	cout << "- 조작법 : ← 왼쪽이동, → 오른쪽이동,";
	gotoxy(x, ++y);
	cout << "          ↑ 블럭회전, ↓ 아래쪽이동";
	y += 2;
	gotoxy(x, y);
	cout << "- 7가지 종류의 블럭이 랜덤으로 위에서 떨어진다.";
	y += 2;
	gotoxy(x, y);
	cout << "- 블럭은 시계반대방향으로 90도회전시킬 수 있으며 바닥의 수평선을";
	gotoxy(x, ++y);
	cout << "  빈틈없이 채워야한다.";
	y += 2;
	gotoxy(x, y);
	cout << "- 일정 점수를 채우게 되면 블럭이 떨어지는 속도가 빨라진다.";
	y += 2;
	gotoxy(x, y);
	cout << "- 블럭이 한계선(─)을 넘게 되면 게임이 종료된다.";
	y += 2;
	gotoxy(x, y);
	cout << "- 게임 플레이어 점수들 중 순위권(5위)안에 들게 되면 랭킹에 등록된다.";

	y += 3;
	gotoxy(++x, y);
	cout << "[ENTER을 누를 시 게임화면으로, 아무키나 누를 시 메인화면으로 이동]";
	nameprint();
	char input = _getch();

	if (input == KEY_ENTER)
		gamestart();
	else
		return;
}
void gamerank(){//랭킹을 보여주는 함수
	system("cls");
	textcolor(15);
	mainsquare();
	gotoxy(28,3);
	cout << "[ R A N K I N G ]";
	gotoxy(5,22);//임시
	cout << "[ENTER을 누를 시 게임화면으로, 아무키나 누를 시 메인화면으로 이동]";
	setranking();
	nameprint();
	char input = _getch();
	if (input == KEY_ENTER)
		gamestart();
	else
		return;
}
void gotoxy(int x, int y) {//좌표 이동하는 함수
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int color_number)//글자색 바꾸는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
int main(){//메인
	setcursortype(NOCURSOR);
//	sndPlaySoundA("E:\\tetris.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);//음악실행 / 실행 전 경로(F/E) 꼭확인!
	while (1){
		mainprint();
	}
	return 0;
}
//다음블럭 출력 , 파일, 아이템, 블럭 움3직일 수 있게 등등