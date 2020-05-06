#include <iostream>
#include "Hangman.h"
#include <conio.h>
#include <string>
#include <fstream>

#include <iomanip>

#define underline "\033[4m"
#define stopUnderline "\033[0m"
#define strike "\033[9m"
#define stopStrike "\033[0m"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13


using namespace std;


void menu();
void randomGame();
void customGame();
void game(string subSTR, string guess);
void drawHang(int stage);

int x = 132 / 2, y = 41 / 2;
int main() {
	short x, y = 36;


	window(132, 41, 1200, 800, FALSE);
	/*	system("chcp 1255");
		string k = "щеп";
		char temp[100];
		int in;
		int i = 0;
		int tempX = 50;
		while (1) {
			Position(tempX--, 3); in = _getch();
			temp[i] = (char) in;
			cout << temp[i];
			i++;
			if (in == ENTER)
				break;
		}
		cout << i;
		_getch();
		tempX = 10;
		for (int s = 0; s < i; s++) {
			Position(tempX--, 5); cout << temp[s];
		}
		cout << endl << "DONE!";
		_getch();*/
//	drawHang(0);
	cout << _getch();
	_getch();
	menu();
}


void menu() {

	int selection = 1, kbInput;

	system("cls");
	Color(7);
	Cube(x - 10, y - 5, 20, 10, TRUE);
	Position(x - 4, y - 4); cout << underline << "Hangman:" << stopUnderline;
	Color(2); Position(x - 5, y - 1); cout << "Random Word";
	Color(7); Position(x - 5, y + 1); cout << "Custom Word";
	Position(x - 2, y + 4); cout << "Exit";

	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN && selection != 3)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		else if (kbInput == ENTER) {
			if (selection == 1) {
				randomGame();
			}
			else if (selection == 2) {
				customGame();
			}
			else if (selection == 3) {
				PostMessage(GetConsoleWindow(), WM_CLOSE, NULL, NULL);
			}
		}

		if (selection == 1) {
			Color(2); Position(x - 5, y - 1); cout << "Random Word";
			Color(7); Position(x - 5, y + 1); cout << "Custom Word";
		}
		else if (selection == 2) {
			Color(7); Position(x - 5, y - 1); cout << "Random Word";
			Color(2); Position(x - 5, y + 1); cout << "Custom Word";
			Color(7); Position(x - 2, y + 4); cout << "Exit";
		}
		else if (selection == 3) {
			Color(7); Position(x - 5, y + 1); cout << "Custom Word";
			Color(2); Position(x - 2, y + 4); cout << "Exit";
		}
	}
}
void randomGame() {

	system("cls");
	Color(7);

	int selection = 1, kbInput, subject = 1, maxCat = 5;
	string subSTR, guess = " ";

	Cube(x - 13, y - 5, 26, 10, TRUE);
	Position(x - 5, y - 4); cout << underline << "Random word:" << stopUnderline;
	Color(2); Position(x - 11, y - 1); cout << "Subject:";
	Color(7); Position(x - 2, y + 1); cout << "Start";
	Position(x - 2, y + 3); cout << "Back";
	Position(x - 1, y - 1); cout << "   ANIMALS  >";

	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN && selection != 3)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		else if (kbInput == RIGHT && selection == 1 && subject != maxCat)
			subject++;
		else if (kbInput == LEFT && selection == 1 && subject != 1)
			subject--;
		else if (kbInput == ENTER) {
			if (selection == 2) {
				ifstream file("Subjects/" + subSTR + ".dll", ifstream::in || ifstream::app);
				int r = random(0, checkLines(file));
				
					guess = getLine(file, r);				

				game(subSTR, guess);
				break;
			}
			else if (selection == 3) {
				menu();
				break;
			}
		}

		if (selection == 1) {
			Color(2); Position(x - 11, y - 1); cout << "Subject:";
			Color(7); Position(x - 2, y + 1); cout << "Start";
		}
		else if (selection == 2) {
			Color(7); Position(x - 11, y - 1); cout << "Subject:";
			Color(2); Position(x - 2, y + 1); cout << "Start";
			Color(7); Position(x - 2, y + 3); cout << "Back";
		}
		else if (selection == 3) {
			Color(7); Position(x - 2, y + 1); cout << "Start";
			Color(2); Position(x - 2, y + 3); cout << "Back";
		}

		if (subject == 1) {
			Color(7); Position(x - 1, y - 1); cout << "   ANIMALS  >";
			subSTR = "animals";
		}
		else if (subject == 2) {
			Color(7); Position(x - 1, y - 1); cout << "< COUNTRIES >";
			subSTR = "countries";
		}
		else if (subject == 3) {
			Color(7); Position(x - 1, y - 1); cout << "<   FOOD    >";
			subSTR = "food";
		}
		else if (subject == 4) {
			Color(7); Position(x - 1, y - 1); cout << "<  MOVIES   >";
			subSTR = "movies";
		}
		else if (subject == 5) {
			Color(7); Position(x - 1, y - 1); cout << "<  TV SHOW   ";
			subSTR = "TV-shows";
		}
	}

}
void customGame() {

	system("cls");
	Color(7);

	int selection = 1, kbInput, subject = 1, maxCat = 5;
	string subSTR, guess;

	Cube(x - 13, y - 5, 26, 10, TRUE);
	Position(x - 5, y - 4); cout << underline << "Random word:" << stopUnderline;
	Color(2); Position(x - 11, y - 1); cout << "Subject:";
	Color(7); Position(x - 11, y); cout << "Word:";
	Position(x - 2, y + 2); cout << "Start";
	Position(x - 2, y + 3); cout << "Back";


	while (1) {

		kbInput = _getch();

		if (kbInput == DOWN && selection != 4)
			selection++;
		else if (kbInput == UP && selection != 1)
			selection--;
		else if (kbInput == ENTER) {
			if (selection == 1) {
				Color(7); Position(x - 11, y - 1); cout << "Subject:               ";
				Color(2); Position(x - 11 + 8, y - 1); getline(cin, subSTR);
				Color(7); Position(x - 11 + 8, y - 1); cout << subSTR;
				Color(2); Position(x - 11, y - 1); cout << "Subject:";
			}
			else if (selection == 2) {
				Color(7); Position(x - 11, y); cout << "Word:               ";
				Color(2); Position(x - 11 + 5, y); getline(cin, guess);
				Color(7); Position(x - 11 + 5, y); cout << guess;
				Color(2); Position(x - 11, y); cout << "Word:";
			}
			else if (selection == 3) {
				ifstream file("Subjects/" + subSTR + ".dll");
				if (!file)
				{
					fstream temp("Subjects/" + subSTR + ".dll", fstream::out | fstream::app);
					temp.close();
				}

				if (checkWord(file, guess) == FALSE) {
					fstream file1("Subjects/" + subSTR + ".dll", fstream::out | fstream::app);
					file1 << "\n" << guess;
					file1.close();
				}
				game(subSTR, guess);

			}
			else if (selection == 4) {
				menu();
				break;
			}
		}

		if (selection == 1) {
			Color(2); Position(x - 11, y - 1); cout << "Subject:";
			Color(7); Position(x - 11, y); cout << "Word:";
		}
		else if (selection == 2) {
			Color(7); Position(x - 11, y - 1); cout << "Subject:";
			Color(2); Position(x - 11, y); cout << "Word:";
			Color(7); Position(x - 2, y + 2); cout << "Start";
		}
		else if (selection == 3) {
			Color(7); Position(x - 11, y); cout << "Word:";
			Color(2); Position(x - 2, y + 2); cout << "Start";
			Color(7); Position(x - 2, y + 3); cout << "Back";
		}
		else if (selection == 4) {
			Color(7); Position(x - 2, y + 2); cout << "Start";
			Color(2); Position(x - 2, y + 3); cout << "Back";
		}
	
	}
}

void game(string subSTR, string guess) {

	system("cls");
	Color(7);

	int place = 0, kbInput, setter = 0;
	string temp;
	char word[20];
	bool flag = FALSE;

	for (int i = 0; i < guess.length(); i++) {
		Position(x - 7 - (guess.length() / 2 * 7) + place, 18);
		temp = guess.at(i);
		if (temp == "-")
			Word(temp, x - 7 - (guess.length() / 2 * 7) + place, 18 - 8);
		else {
			cout << "#######";
			setter++;
		}
		word[i] = guess.at(i);
		place += 9;

	}
	//Position(0, 0); cout << guess;
	Word(subSTR, x - 7 - (subSTR.length() / 2 * 7), 1);
	Position(5, 30); cout << "[  A  ]  " << "[  B  ]  " << "[  C  ]  " << "[  D  ]  " << "[  E  ]  " << "[  F  ]";
	Position(5, 32); cout << "[  G  ]  " << "[  H  ]  " << "[  I  ]  " << "[  J  ]  " << "[  K  ]  " << "[  L  ]";
	Position(5, 34); cout << "[  M  ]  " << "[  N  ]  " << "[  O  ]  " << "[  P  ]  " << "[  Q  ]  " << "[  R  ]";
	Position(5, 36); cout << "[  S  ]  " << "[  T  ]  " << "[  V  ]  " << "[  U  ]  " << "[  W  ]  " << "[  X  ]";
	Position(5 + 18, 38); cout << "[  Y  ]  " << "[  Z  ] ";

	place = 1;
	int filled = 0;
	int stage = 0;

	Position(0, 1); cout << guess.length();
	while (1) {
		kbInput = _getch();

		if (kbInput == 97) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'a') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5, 30); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5, 30); cout << "         ";
					stage++;
					break;
				}
				
			}

		}
		else if (kbInput == 98) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'b') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9, 30); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9, 30); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 99) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'c') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 2, 30); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 2, 30); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 100) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'd') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 3, 30); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 3, 30); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 101) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'e') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 4, 30); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 4, 30); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 102) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'f') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 5, 30); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 5, 30); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 103) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'g') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 0, 32); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 0, 32); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 104) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'h') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 1, 32); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 1, 32); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 105) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'i') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 2, 32); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 2, 32); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 106) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'j') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 3, 32); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 3, 32); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 107) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'k') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 4, 32); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 4, 32); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 108) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'l') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 5, 32); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 5, 32); cout << "         ";
					stage++;
			
				}
			}
		}
		else if (kbInput == 109) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'm') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 0, 34); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 0, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 110) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'n') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 1, 34); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 1, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 111) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'o') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 2, 34); cout << "         ";
					filled++;
					flag = TRUE;
					
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 2, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 112) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'p') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 3, 34); cout << "         ";
					filled++;
					flag = TRUE;
				
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 3, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 113) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'q') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 4, 34); cout << "         ";
					filled++;
					flag = TRUE;
			
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 4, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 114) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'r') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 5, 34); cout << "         ";
					filled++;
					flag = TRUE;
		
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 5, 34); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 115) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 's') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 0, 36); cout << "         ";
					filled++;
					flag = TRUE;
			
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 0, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 116) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 't') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 1, 36); cout << "         ";
					filled++;
					flag = TRUE;

				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 1, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 117) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'u') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 2, 36); cout << "         ";
					filled++;
					flag = TRUE;
	
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 2, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 118) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'v') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 3, 36); cout << "         ";
					filled++;
					flag = TRUE;
			
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 3, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 119) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'w') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 4, 36); cout << "         ";
					filled++;
					flag = TRUE;
			
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 4, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 120) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'x') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 0, 36); cout << "         ";
					filled++;
					flag = TRUE;
		
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 0, 36); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 121) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 'y') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 2, 38); cout << "         ";
					filled++;
					flag = TRUE;
		
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 2, 38); cout << "         ";
					stage++;
					break;
				}
			}
		}
		else if (kbInput == 122) {
			for (int i = 0; i < guess.length(); i++) {
				if (guess.at(i) == 's') {
					temp = guess.at(i);
					Word(temp, x - 7 - (guess.length() / 2 * 7) + (i * 9), 10);
					Position(5 + 9 * 3, 38); cout << "         ";
					filled++;
					flag = TRUE;
		
				}
				if (i == guess.length() - 1 && flag == FALSE) {
					drawHang(stage);
					Position(5 + 9 * 3, 38); cout << "         ";
					stage++;
					break;
				}
			}
		}

		if (stage == 8) {
			Cube(x - 15, y - 5, 30, 10, FALSE);
			Position(x - 2, y); cout << "LOSE";
		}
		else if (filled == setter) {
			Cube(x - 15,y-5,30,10,FALSE); 
			Position(x - 2, y); cout << "WIN";
		}
		Position(0, 0); cout << filled;
		flag = FALSE;
	}

	menu();
}

void drawHang(int stage) {

	int xx = 100, yy = 25;
	Color(7);
	if (stage == 0) {
		Position(xx, yy - 5);  cout << "______________________";
		Position(xx, yy - 4);  cout << "                     |";
		Position(xx, yy - 3);  cout << "                     |";
		Position(xx, yy - 2);  cout << "                     |";
		Position(xx, yy - 1);  cout << "                     |";
		Position(xx, yy - 0);  cout << "                     |";
		Position(xx, yy + 1);  cout << "                     |";
		Position(xx, yy + 2);  cout << "                     |";
		Position(xx, yy + 3);  cout << "                     |";
		Position(xx, yy + 4);  cout << "                     |";
		Position(xx, yy + 5);  cout << "                     |";
		Position(xx, yy + 6);  cout << "                     |";
		Position(xx, yy + 7);  cout << "                     |";
		Position(xx, yy + 8);  cout << "                     |";
		Position(xx, yy + 9);  cout << "                     |";
		Position(xx, yy + 10); cout << "                     |";
		Position(xx, yy + 11); cout << "                     |";
		Position(xx, yy + 12); cout << "                     |" ;
		Position(xx, yy + 13); cout << "                     |";
		Position(xx, yy + 14); cout << "                     |";
		Position(xx, yy + 15); cout << "                     |";
	}
	if (stage == 1) {
		Position(xx, yy - 4);  cout << "       |             |";
		Position(xx, yy - 3);  cout << "       |             |";
		Position(xx, yy - 2);  cout << "       |             |";
		Position(xx, yy - 1);  cout << "       |             |";
	}

	if (stage == 2) {

		Position(xx, yy);   cout << "   ____!___   ";
		Position(xx, yy+1);	cout << "  /        \\ ";
		Position(xx, yy+2); cout << " ( (x)  (x) ) ";
		Position(xx, yy+3); cout << "  \\        / ";
		Position(xx, yy+4); cout << "   \\______/  ";

	}
	if (stage == 3) {
		Position(xx, yy + 5);   cout << "       |      ";
		Position(xx, yy + 6); cout << "       |      ";
		Position(xx, yy + 7); cout << "       |      ";
		Position(xx, yy + 8); cout << "       |      ";
		Position(xx, yy + 9); cout << "       |      ";
	}
	if (stage == 4) {

		Position(xx, yy + 10); cout << "      /";
		Position(xx, yy + 11); cout << "     / ";
		Position(xx, yy + 12); cout << "    /  ";
		Position(xx, yy + 13); cout << "   /   ";
		Position(xx, yy + 14); cout << "  /    ";
	}
	if (stage == 5) {

		Position(xx + 8, yy + 10); cout << "\\    ";
		Position(xx + 8, yy + 11); cout << " \\   ";
		Position(xx + 8, yy + 12); cout << "  \\  ";
		Position(xx + 8, yy + 13); cout << "   \\ ";
		Position(xx + 8, yy + 14); cout << "    \\";
	}
	if (stage == 6) {

		Position(xx, yy + 5); cout << "      /";
		Position(xx, yy + 6); cout << "     / ";
		Position(xx, yy + 7); cout << "    /  ";
		Position(xx, yy + 8); cout << "   /   ";
		Position(xx, yy + 9); cout << "  /    ";
	}
	if (stage == 7) {
		Position(xx + 8, yy + 5); cout << "\\    ";
		Position(xx + 8, yy + 6); cout << " \\   ";
		Position(xx + 8, yy + 7); cout << "  \\  ";
		Position(xx + 8, yy + 8); cout << "   \\ ";
		Position(xx + 8, yy + 9); cout << "    \\";
	}

}