#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<string>
#include<fstream>
#include <chrono>
//This game name is Candy Crush and it is made by Hamza Shabbir and Muhammad Hassan. In this game we have 60 sec timer in easy and 40 sec in hard. In this game you make pair of candies by swapping them. After pairing of candies the candies from the top drop smoothly which make this game smooth for user. After the timer ran out user will get out of the game.
using namespace std;
#define KEY_UP 72        // Defining Keys UP
#define KEY_DOWN 80      // Down key    
#define KEY_LEFT 75      // Left key
#define KEY_RIGHT 77     // Right key
#define key_ESC 27      // ESC key 
//Displaying Menu
void menu() {
	system("cls");
	cout << "\n \n \n \n " << endl;
	system("Color E");
	cout << setw(31) << "\t\t\t\t|-----------------------------|\n";
	cout << setw(30) << "\t\t\t\t|  Welcome! To Candy Crush !  |\n";
	cout << setw(30) << "\t\t\t\t|    1) Start                 |\n";
	cout << setw(30) << "\t\t\t\t|    2)Instructions           |\n";
	cout << setw(30) << "\t\t\t\t|    3)Score                  |\n";
	cout << setw(30) << "\t\t\t\t|    4)Credit                 |\n";
	cout << setw(30) << "\t\t\t\t|    5)Exit                   |\n";
	cout << setw(31) << "\t\t\t\t|-----------------------------|\n\n";
}// Asking for game Mode
void mode() {
	system("cls");
	system("Color B");
	cout << "\n\n\n\n " << endl;
	cout << "\t\t\t\t 1) Easy Mode " << endl;
	cout << "\t\t\t\t 2) Hard Mode " << endl;
}
//function to Credit 
void credit() {
	system("cls");
	cout << "\n\n\n" << endl;
	cout << setw(31) << "\t\t\t\t |---------------------------|\n";
	cout << setw(31) << "\t\t\t\t |Game created by :          |\n";
	cout << setw(31) << "\t\t\t\t |  23F-0676  Muhammad Hassan|\n";
	cout << setw(31) << "\t\t\t\t |  23F-0546  Hamza Shabbir  |\n";
	cout << setw(31) << "\t\t\t\t |ID:                        |\n";
	cout << setw(31) << "\t\t\t\t |    F230676@cfd.nu.edu.pk  |\n";
	cout << setw(31) << "\t\t\t\t |    F230546@cfd.nu.edu.pk  |\n";
	cout << setw(31) << "\t\t\t\t |Organization:              |\n";
	cout << setw(31) << "\t\t\t\t |    Fast-Nuces CFD Campus  |\n";
	cout << setw(31) << "\t\t\t\t |---------------------------|\n";
}
//Creating Function For Instruction
void instruction() {
	cout << setw(15) << " Welcome ! To Game " << endl;
	cout << "Here's are some instruction to play this game :\n";
	cout << "You will be Given 2 choices : \n\n";
	cout << "Easy Mode: \n";
	cout << "1) You will be given 15 moves and time of 60 seconds\n";
	cout << "2) Board will Contain 5 different Candies\n";
	cout << "Hard Mode: \n";
	cout << "1) You will be given 15 moves and 40 seconds\n";
	cout << "2) Board will contain 7 diiferent Candies\n\n";
	cout << "\t\t\tHere are some general instructions\n";
	cout << "1) Horizontal and vertically (both) match gets 10 points \n";
	cout << "2) Diagonls (both) match get 20 points \n";
	cout << "3) L-shape match get 25 points \n";
	cout << "4) First of all you have to enter desired row and column\n";
	cout << "   and then press UP or RIGH or D0WN or LEFT key to move candy\n\n";
	cout << " Thanks For Playing \n";
}
char e_candy_maker(char candy)//for making candies randomly in easy mode
{
	int ran;
	ran = rand() % 5 + 1;
	switch (ran)
	{
	case 1:
		candy = '@';
		break;
	case 2:
		candy = '#';
		break;
	case 3:
		candy = '&';
		break;
	case 4:
		candy = '$';
		break;
	case 5:
		candy = '%';
		break;
	}
	return candy;
}
char h_candy_maker(char candy)//for making candies randomly in easy mode
{
	int ran;
	ran = rand() % 7 + 1;
	switch (ran)
	{
	case 1:
		candy = '@';
		break;
	case 2:
		candy = '#';
		break;
	case 3:
		candy = '&';
		break;
	case 4:
		candy = '$';
		break;
	case 5:
		candy = '%';
		break;
	case 6:
		candy = '?';
		break;
	case 7:
		candy = '>';
		break;
	}
	return candy;
}
void e_candy_filler(char arr[8][8])//replacing spaceing in arrays with candies
{
	char space_candy = ' ';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = e_candy_maker(space_candy);
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
					arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
					arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1] || //anti_diagonal
					arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1])  // main diagonal
				{
					char space_candy1 = ' ';
					arr[i][j] = e_candy_maker(space_candy);
				}
			}
		}
	}
}
void h_candy_filler(char arr[10][10])//replacing spaceing in arrays with candies
{
	char space_candy = ' ';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = h_candy_maker(space_candy);
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
					arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
					arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1] || //anti_diagonal
					arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1])  // main diagonal
				{
					char space_candy1 = ' ';
					arr[i][j] = h_candy_maker(space_candy);
				}
			}
		}
	}
}
void e_first_time_filler(char arr[8][8])// fill random cadies in table for 1st time easy mode
{
	char cand = ' ';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = e_candy_maker(cand);
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1] || //anti_diagonal
						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1])  // main diagonal
					{
						char candy = ' ';
						arr[i][j] = e_candy_maker(candy);
					}
				}
			}
		}
	}
}
void h_first_time_filler(char arr[10][10])// fill random cadies in table for 1st time easy mode
{
	char cand = ' ';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = h_candy_maker(cand);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1] || //anti_diagonal
						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1])  // main diagonal
					{
						char candy = ' ';
						arr[i][j] = h_candy_maker(candy);
					}
				}
			}
		}
	}
}
void swap(char& x, char& y)//For swapping
{
	char temp = x;
	x = y;
	y = temp;
}
void e_board_printer(char arr[8][8])//for printing easy board where candies are destroying
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
	cout << "\t\t_________________________________________________" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "\t     " << i << "  | ";
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '@')
				SetConsoleTextAttribute(color, 3);//colouring symbols
			else if (arr[i][j] == '#')
				SetConsoleTextAttribute(color, 2);//colouring symbols
			else if (arr[i][j] == '%')
				SetConsoleTextAttribute(color, 4);//colouring symbols
			else if (arr[i][j] == '&')
				SetConsoleTextAttribute(color, 5);//colouring symbols
			else if (arr[i][j] == '$')
				SetConsoleTextAttribute(color, 6);//colouring symbols
			cout << " " << arr[i][j] << "  | ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(color, 7);
}
void h_board_printer(char arr[10][10])//for printing easy board where candies are destroying
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;
	cout << "\t\t_____________________________________________________________" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "\t     " << i << "  | ";
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == '@')
				SetConsoleTextAttribute(color, 3);//colouring symbols
			else if (arr[i][j] == '#')
				SetConsoleTextAttribute(color, 2);//colouring symbols
			else if (arr[i][j] == '%')
				SetConsoleTextAttribute(color, 4);//colouring symbols
			else if (arr[i][j] == '&')
				SetConsoleTextAttribute(color, 5);//colouring symbols
			else if (arr[i][j] == '$')
				SetConsoleTextAttribute(color, 6);//colouring symbols
			else if (arr[i][j] == '!')
				SetConsoleTextAttribute(color, 1);//colouring symbols
			else if (arr[i][j] == '>')
				SetConsoleTextAttribute(color, 8);//colouring symbols
			cout << " " << arr[i][j] << "  | ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(color, 7);
}
void e_fil_space_top(char arr[8][8])//dropping candies from top to bottom and also if row 0 have no candie then it will print some random candies that will go down also
{
	int first_row = 0;
	char new_candy = ' ';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == ' ')
			{

				if (arr[first_row][j] == ' ') {
					arr[first_row][j] = e_candy_maker(new_candy);
					e_board_printer(arr);
					Sleep(50);
					system("cls");
				}
				else if (i>0){
					int row = i;
					while (row > 0)
					{
						arr[row][j] = arr[row - 1][j];
						arr[row - 1][j] = ' ';
						row--;
						e_board_printer(arr);
						Sleep(50);
						system("cls");
					}
					arr[first_row][j] = ' ';
					i = 0; j = 0;
				}
			}
		}
	}
}
void h_fil_space_top(char arr[10][10])//dropping candies from top to bottom and also if row 0 have no candie then it will print some random candies that will go down also
{
	int first_row = 0;
	char new_candy = ' ';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == ' ')
			{
				if (arr[first_row][j] == ' ') {
					arr[first_row][j] = h_candy_maker(new_candy);
					h_board_printer(arr);
					Sleep(70);
					system("cls");
				}
				else if (i > 0) {
					int row = i;
					while (row > 0)
					{
						arr[row][j] = arr[row - 1][j];
						row--;
						h_board_printer(arr);
						Sleep(70);
						system("cls");
					}
					arr[first_row][j] = ' ';
					i = 0; j = 0;
				}
			}
		}
	}
}
void gamedata(string name, int scr);
void previousgames();
double getSecondsDuration(chrono::system_clock::time_point time2,
	chrono::system_clock::time_point time1) {
	return chrono::duration_cast<chrono::seconds>(time2 - time1).count();
}
int main() {
	srand(time(0));
	int score;
	int game_starting = 5;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	char character;
	char e_board[8][8];
	int choice, game_mode;
	string name;
	/* Entering to Selected Option */
	while (true) {
		menu();
		cout << "Enter Choice: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 5) {
			cin.clear();
			cin.ignore();
			cout << "Inavlid, Again: ";
			cin >> choice;
		}

		if (choice == 1) {
			mode();
			int moves = 15;
			cout << "\n Enter Difficulty type or 0 to quit : ";
			cin >> game_mode;
			while (cin.fail() || game_mode < 0 || game_mode > 2) {
				cin.clear();
				cin.ignore();
				cout << "Inavlid, Again: ";
				cin >> game_mode;
			}
			system("cls");
			cout << " Enter Name : ";
			cin >> name;
			if (game_mode == 1) {
				score = 0;
				int stopwatch = 64;
				char arr[8][8];
				char c;
				auto time = chrono::system_clock::now();
				bool timeRanOut = true;
				int count = 0;//counter for first time table print
				system("cls");
				while (game_starting > 0)
				{
					system("Color B");
					cout << "\n\n\n\n\t\t\t\tGame stating in : " << game_starting;
					Sleep(600);
					system("cls");
					game_starting--;
				}
				cout << "\n\n\n\n\t\t\t\tLetsssss goooooooooooo!";
				Sleep(500);
				system("cls");
				if (count == 0)
				{
					e_first_time_filler(arr);//filling table for first time
					count++;
				}
				while (moves > 0 && stopwatch >= getSecondsDuration(chrono::system_clock::now(), time))
				{
					int again_chaning_candies_count = 0;
					SetConsoleTextAttribute(color, 7);
					cout << "\tMoves : " << moves << endl;
					cout << "\tScore : " << score << endl;
					cout << "\tTimer : 00:" << stopwatch - getSecondsDuration(chrono::system_clock::now(), time) << endl;
					Sleep(40);
					cout << "\t\t|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
					cout << "\t\t_________________________________________________" << endl;
					for (int i = 0; i < 8; i++)
					{
						cout << "\t     " << i << "  | ";
						for (int j = 0; j < 8; j++)
						{
							if (arr[i][j] == '@')
								SetConsoleTextAttribute(color, 3);//colouring symbols
							else if (arr[i][j] == '#')
								SetConsoleTextAttribute(color, 2);//colouring symbols
							else if (arr[i][j] == '%')
								SetConsoleTextAttribute(color, 8);//colouring symbols
							else if (arr[i][j] == '&')
								SetConsoleTextAttribute(color, 5);//colouring symbols
							else if (arr[i][j] == '$')
								SetConsoleTextAttribute(color, 6);//colouring symbols
							cout << " " << arr[i][j] << "  | ";
						}
						cout << endl;
					}
					SetConsoleTextAttribute(color, 7);
					int i, j;
					bool swaping_valid = 1;
					while (swaping_valid == 1)
					{
						cout << "Enter which candy you want to swap." << endl;
						cout << "Enter row :";
						cin >> i;
						while (cin.fail() || i < 0 || i > 7) {
							cin.clear();
							cin.ignore();
							cout << "Inavlid, Again: ";
							cin >> i;
						}
						cout << "Enter column :";
						cin >> j;
						while (cin.fail() || j < 0 || j > 7) {
							cin.clear();
							cin.ignore();
							cout << "Inavlid, Again: ";
							cin >> j;
						}
						if (i >= 0 && i < 8 && j >= 0 && j < 8)// input validation
						{
							swaping_valid = 0;
						}
						else
							cout << "Error ! Invalid Input" << endl;

					}
					bool swap_arrow_valid = 1;
					int arrow;
					while (swap_arrow_valid == 1)
					{
						cout << "Press Arrow key to swipe left, right, up and down" << endl;
						arrow = _getch();
						switch (arrow)
						{
						case KEY_UP:
							if (i == 0)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else {
								swap(arr[i][j], arr[i - 1][j]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_DOWN:
							if (i == 7)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i + 1][j]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_LEFT:
							if (j == 0)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i][j - 1]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_RIGHT:
							if (j == 7)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i][j + 1]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						}
					}
					bool match = true;
					while (match)
					{
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
							{
								if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 2][j] = ' ';
									arr[i + 2][j + 1] = ' ';
									arr[i + 2][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j] && arr[i + 1][j + 1] == arr[i + 1][j + 2]) {

									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 1][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 1][j + 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 1][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 1])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i - 2][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 1])
								{
									arr[i][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j - 1] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i - 2][j - 1] = ' ';
									score = +25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i - 1][j - 2] && arr[i][j] == arr[i - 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j - 2] = ' ';
									arr[i - 1][j - 2] = ' ';
									arr[i - 2][j - 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
								{
									arr[i][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 2][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i - 2][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
								{
									arr[i][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j + 2] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j + 1])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j + 1] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j - 2] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])
								{
									arr[i][j] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i + 1][j + 1] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 2][j + 2] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i - 2][j - 2] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j + 1] = ' ';
									arr[i - 2][j + 2] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i - 1][j + 1])
								{
									arr[i][j] = ' ';
									arr[i + 1][j - 1] = ' ';
									arr[i - 1][j + 1] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j - 1] = ' ';
									arr[i + 2][j - 2] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									e_fil_space_top(arr);
									e_board_printer(arr);
									i = 0; j = 0;
								}
								else
									match = false;
							}
						}
					}
					system("cls");
					Sleep(400);
				}
				cout << "You Score: " << score << endl;
				cout << "Press ESC key to continue " << endl;
				do {
					character = _getch();
				} while (character != key_ESC);
			}
			else if (game_mode == 2)
			{
				char c;
				auto time = chrono::system_clock::now();
				int stopwatch = 45;
				score = 0;
				char arr[10][10];
				int count = 0;//counter for first time table print
				while (game_starting > 0)
				{
					system("cls");
					system("Color B");
					cout << "\n\n\n\n\t\t\t\tGame starting in : " << game_starting;
					Sleep(600);
					system("cls");
					game_starting--;
				}
				cout << "\n\n\n\n\t\t\t\tLetsssss goooooooooooo!";
				Sleep(500);
				system("cls");
				if (count == 0)
				{
					h_first_time_filler(arr);//filling table for first time
					count++;
				}
				while (moves > 0 && stopwatch >= getSecondsDuration(chrono::system_clock::now(), time))
				{
					SetConsoleTextAttribute(color, 7);
					cout << "\tMoves : " << moves << endl;
					cout << "\tScore : " << score << endl;
					cout << "\tTimer : 00:" << stopwatch - getSecondsDuration(chrono::system_clock::now(), time) << endl;
					Sleep(400);
					cout << "\t\t|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;
					cout << "\t\t_____________________________________________________________" << endl;
					for (int i = 0; i < 10; i++)
					{
						cout << "\t     " << i << "  | ";
						for (int j = 0; j < 10; j++)
						{
							if (arr[i][j] == '@')
								SetConsoleTextAttribute(color, 3);//colouring symbols
							else if (arr[i][j] == '#')
								SetConsoleTextAttribute(color, 2);//colouring symbols
							else if (arr[i][j] == '%')
								SetConsoleTextAttribute(color, 8);//colouring symbols
							else if (arr[i][j] == '&')
								SetConsoleTextAttribute(color, 5);//colouring symbols
							else if (arr[i][j] == '$')
								SetConsoleTextAttribute(color, 6);//colouring symbols
							else if (arr[i][j] == '!')
								SetConsoleTextAttribute(color, 3);//colouring symbols
							else if (arr[i][j] == '>')
								SetConsoleTextAttribute(color, 4);//colouring symbols
							cout << " " << arr[i][j] << "  | ";
						}
						cout << endl;
					}
					SetConsoleTextAttribute(color, 7);
					int i, j;
					bool swaping_valid = 1;
					while (swaping_valid == 1)
					{
						cout << "Enter which candy you want to swap." << endl;
						cout << "Enter row :";
						cin >> i;
						while (cin.fail() || i < 0 || i > 9) {
							cin.clear();
							cin.ignore();
							cout << "Inavlid, Again: ";
							cin >> i;
						}
						cout << "Enter column :";
						cin >> j;
						while (cin.fail() || j < 0 || j > 9) {
							cin.clear();
							cin.ignore();
							cout << "Inavlid, Again: ";
							cin >> j;
						}
						if (i >= 0 && i < 10 && j >= 0 && j < 10)// input validation
						{
							swaping_valid = 0;
						}
						else
							cout << "Error ! Invalid Input" << endl;

					}
					bool swap_arrow_valid = 1;
					int arrow;
					while (swap_arrow_valid == 1)
					{
						cout << "Press Arrow key to swipe left, right, up and down" << endl;
						arrow = _getch();
						switch (arrow)
						{
						case KEY_UP:
							if (i == 0)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else {
								swap(arr[i][j], arr[i - 1][j]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_DOWN:
							if (i == 9)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i + 1][j]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_LEFT:
							if (j == 0)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i][j - 1]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						case KEY_RIGHT:
							if (j == 9)
							{
								cout << "Error! You are going out of boundry" << endl;
							}
							else
							{
								swap(arr[i][j], arr[i][j + 1]);
								swap_arrow_valid = 0;
								moves--;
							}
							break;
						}
					}
					bool match = true;
					while (match)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 2][j] = ' ';
									arr[i + 2][j + 1] = ' ';
									arr[i + 2][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j] && arr[i + 1][j + 1] == arr[i + 1][j + 2]) {

									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 1][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 1][j + 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 1][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 1])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i - 2][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j + 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 1])
								{
									arr[i][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j - 1] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i - 2][j - 1] = ' ';
									score = +25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i - 1][j - 2] && arr[i][j] == arr[i - 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j - 2] = ' ';
									arr[i - 1][j - 2] = ' ';
									arr[i - 2][j - 2] = ' ';
									score += 25;
									cout << "Excellent! You founded L-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
								{
									arr[i][j] = ' ';
									arr[i + 1][j] = ' ';
									arr[i + 2][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i + 1][j])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i + 1][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j])
								{
									arr[i][j] = ' ';
									arr[i - 1][j] = ' ';
									arr[i - 2][j] = ' ';
									score += 10;
									cout << "WOW! You founded Vert-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
								{
									arr[i][j] = ' ';
									arr[i][j + 1] = ' ';
									arr[i][j + 2] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j + 1])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j + 1] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2])
								{
									arr[i][j] = ' ';
									arr[i][j - 1] = ' ';
									arr[i][j - 2] = ' ';
									score += 10;
									cout << "WOW! You founded Hori-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])
								{
									arr[i][j] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i + 1][j + 1] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j + 1] = ' ';
									arr[i + 2][j + 2] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j - 1] = ' ';
									arr[i - 2][j - 2] = ' ';
									score += 10;
									cout << "Great! You founded Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2])
								{
									arr[i][j] = ' ';
									arr[i - 1][j + 1] = ' ';
									arr[i - 2][j + 2] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i - 1][j + 1])
								{
									arr[i][j] = ' ';
									arr[i + 1][j - 1] = ' ';
									arr[i - 1][j + 1] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2])
								{
									arr[i][j] = ' ';
									arr[i + 1][j - 1] = ' ';
									arr[i + 2][j - 2] = ' ';
									score += 10;
									cout << "Great! You founded Anti-Diagonal-shape" << endl;
									Sleep(400);
									system("cls");
									h_fil_space_top(arr);
									h_board_printer(arr);
									i = 0; j = 0;
								}
								else
									match = false;
							}
						}
					}
					system("cls");
					Sleep(400);
				}
				cout << "You Score: " << score << endl;
				cout << "Press ESC key to continue " << endl;
				do {
					character = _getch();
				} while (character != key_ESC);
			}
			else
				continue;
			///filing proccess//
			gamedata(name, score);
			cout << "\n\n";
			system("pause");
			system("cls");
			continue;
		}
		else if (choice == 2) {
			system("cls");
			system("Color 9");
			instruction();
			cout << " Press ESC to go out.";
			do {
				character = _getch();
			} while (character != key_ESC);
			continue;
		}
		else if (choice == 3) {
			system("cls");
			cout << "Here's the list of top 3 Best players and their highest scores:" << endl;
			cout << "\n\n";
			previousgames();
			cout << "\n\n";
			cout << " Press ESC to go out.";
			do {
				character = _getch();
			} while (character != key_ESC);
			continue;
		}
		else if (choice == 4) {
			system("Color 2");
			credit();
			cout << " Press ESC to go out.";
			do {
				character = _getch();
			} while (character != key_ESC);
			continue;
		}
		else if (choice == 5) {
			system("Color 3");
			system("cls");
			cout << " Goood Byeeeeeeeee ! " << endl;
			break;
		}

	}
	return 0;
}
// Defining Function for score
void gamedata(string name, int scr) 
{
	fstream file;
	int sco[10];
	string names[10];
	int games = 0;
	file.open("highestScore.txt", ios::app);
	if (file)
		file << name << endl << scr << endl;
	file.close();
	file.open("highestScore.txt", ios::in);
	if (file) {
		while (file >> names[games])
		{
			file >> sco[games];
			games++;
		}
		file.close();
	}
	else
		cout << "file is not oppened\n";
	//sort data with respect to points//
	for (int i = 0; i < games - 1; i++)
	{
		for (int j = i + 1; j < games; j++)
		{
			if (sco[i] < sco[j])
			{
				swap(sco[i], sco[j]);
				swap(names[i], names[j]);
			}
		}
	}
	//sort data with respect to points//
	file.open("highestScore.txt", ios::out);
	if (file) {
		for (int i = 0; i < games; i++)
		{
			file << names[i] << endl << sco[i] << endl;
		}
		file.close();
	}
	else
		cout << "file is not oppened\n";
}
void previousgames() 
{
	fstream file;
	string name;
	int score;
	int game = 0;
	int i = 0;
	file.open("highestScore.txt", ios::in);
	if (file) 
	{
		while (file >> name >> score && game < 3)
		{
			cout << "\n\nGames : " << game++ << endl;
			cout << "Name of players : " << name << endl;
			cout << "\tPlayers points : " << score << endl;
		}
		file.close();
	}
	else {
		cout << "file is not opened\n";
	}
}