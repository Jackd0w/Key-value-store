#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const char X = 'X';
const char O = 'O';
const char Empty = ' ';
const char Tie = 'T';
const char No_one = 'N';

void instructions() {
	cout << "Get ready for ultimate man-machine showdown!" << endl;
	cout << "Where stupid meatbags try to beat an unbeatable piece of silicon!!!" << endl;
	cout << "Here's the rules:" << endl;
	cout << "Make your move by entering numbers 0-8" << endl;
	cout << "The number corresponds to the desired board position as it shows:" << endl;
	cout << "0 | 1 | 2 /n";
	cout << "---------/n";
	cout << "4 | 5 | 6/n";
	cout << "---------/n";
	cout << "7 | 8 | 9/n";
}

char Ask_Yes_No( string question) {
	char response;
	do {
		cout << "Do you want to play the game?" << "(y/n)" << endl;
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int Ask_Number(string question, int high, int low = 0) {
	int number;
	do {
		cout << question << "q" << low << "-" << high << ") ";
		cin >> number;
	} while (number < high || number > low);
	return number;
}

char HumanPiece() {
	char Go_First = Ask_Yes_No("Do You require the first move?");
	if (Go_First = 'y') {
		cout << "So be it" << endl;
		return 'X';
	}
	else {
		cout << "Fool!" << endl;
		return 'O';
	}
}

char OponentPiece(char Piece) {
	if (Piece == X) {
		return 0;
	}
	else {
		return X;
	}
}

void DisplayBoard(const vector<char>& board) {
	cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
	cout << "--------" << endl;
	cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
	cout << "--------" << endl;
	cout << board[6] << "|" << board[7] << "|" << board[8] << endl;

}

char winner(const vector<char>& board) {
	const int Winner_Rows[8][3] = { {0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6}
	};
	const int Total_Rows = 8;
	for (int row = 0; row < Total_Rows; ++row) {
		if ((board[Winner_Rows[row][0]] != Empty) && (board[Winner_Rows[row][0]] == board[Winner_Rows[row][1]]) && (board[Winner_Rows[row][1]] == board[Winner_Rows[row][2]])) {
			return board[Winner_Rows[row][0]];
		}
		
	}
}

bool IsLegal(const vector<char>& board, int move) {

}

int HumanMove(const vector<char>& board, char human) {

}

int computerMove(const vector<char>& board, char computer) {

}

void AnnounceWinner(char winner, char human, char computer) {

}

int main() {
	int move;
	int Num_spaces = 9;
	vector<char> board (Num_spaces, Empty);
	instructions();
	char human = HumanPiece();
	char oponent = OponentPiece(human);
	char turn = 'X';
	DisplayBoard(board);
	while (winner(board) == No_one) {
		if (turn == human) {
			move = HumanMove(board, human);
			board[move] = human;
		}
		else {
			move = computerMove(board, oponent);
			board[move] = oponent;
		}
		DisplayBoard(board);
		turn = OponentPiece(turn);
	}
	AnnounceWinner(winner(board), human, oponent);
		

	return 0;
}