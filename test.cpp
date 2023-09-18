// Nicolas Jao 400450151
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <memory>
#include <ostream>
using namespace std;

struct pieceimages {
	string blackpawnimage;
	string whitepawnimage;
	string blackrookimage;
	string whiterookimage;
	string blackknightimage;
	string whiteknightimage;
	string blackbishopimage;
	string whitebishopimage;
	string blackqueenimage;
	string whitequeenimage;
	string blackkingimage;
	string whitekingimage;
};
class piece {
protected:
	string team;
	string image;
	int x;
	int y;
public:
	void setx(int px) {
		x = px;
	}
	void sety(int py) {
		y = py;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	string getimage() {
		return image;
	}
	string getteam() {
		return team;
	}
};
class pawn: public piece {
public:
	pawn(string t, int px, int py, string pblackpawnimage, string pwhitepawnimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackpawnimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhitepawnimage;
		}
	}
	bool checkvalidmove(int newxpieceposition, int newypieceposition, piece pieces[]) {
		if (team == "white") {

		}
		else if (team == "black") {
			
		}



		






		int validtiles[] = {
			
		};
		//checking if the new piece position is one of the valid tiles to move it to
		for (int i = 0; i < (sizeof(validtiles)/sizeof(*validtiles)); i++) {
			if (validtiles[i] == newpieceposition) {
				return true;
			}
		}
		//if the new piece position is not one of any of the valid tiles it can move to, it invalidates the move and returns false
		return false;
	}
};
class rook: public piece {
public:
	rook(string t, int px, int py, string pblackrookimage, string pwhiterookimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackrookimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhiterookimage;
		}
	}
};
class knight: public piece {
public:
	knight(string t, int px, int py, string pblackknightimage, string pwhiteknightimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackknightimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhiteknightimage;
		}
	}
};
class bishop: public piece {
public:
	bishop(string t, int px, int py, string pblackbishopimage, string pwhitebishopimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackbishopimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhitebishopimage;
		}
	}
};
class queen: public piece {
public:
	queen(string t, int px, int py, string pblackqueenimage, string pwhitequeenimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackqueenimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhitequeenimage;
		}
	}
};
class king: public piece {
public:
	king(string t, int px, int py, string pblackkingimage, string pwhitekingimage) {
		x = px;
		y = py;
		if (t == "black") {
			team = "black";
			image = pblackkingimage;
		}
		else if (t == "white") {
			team = "white";
			image = pwhitekingimage;
		}
	}
};
void displayboard(piece pieces[]) {
	bool pieceontile = false;
	string pieceimage;
	for (int y = 0; y < 8; y++) {
		cout << y + 1;
		for (int x = 0; x < 8; x++) {
			if (x == 7) {
				for (int i = 0; i < 32; i++) {
					if (pieces[i].getx() == (x + 1) && pieces[i].gety() == (y + 1)) {
						pieceontile = true;
						pieceimage = pieces[i].getimage();
					}
				}
				if (pieceontile == true) {
					cout << "|" << pieceimage << "|" << endl;
					pieceontile = false;
				}
				else {
					cout << "|_|" << endl;
				}
			}
			else {
				for (int i = 0; i < 32; i++) {
					if (pieces[i].getx() == (x + 1) && pieces[i].gety() == (y + 1)) {
						pieceontile = true;
						pieceimage = pieces[i].getimage();
					}
				}
				if (pieceontile == true) {
					cout << "|" << pieceimage << "|";
					pieceontile = false;
				}
				else {
					cout << "|_|";
				}
			}
		}
	}
	cout << "  1  2  3  4  5  6  7  8" << endl;
}

int main()
{
    //the start of the game
    cout << "Welcome to Chess!" << endl;
	//setting the images for the pieces. you can set your own to whatever you want!
	pieceimages gamepieceimages;
	gamepieceimages.blackpawnimage = "♙";
	gamepieceimages.whitepawnimage = "♟️";
	gamepieceimages.blackrookimage = "♖";
	gamepieceimages.whiterookimage = "♜";
	gamepieceimages.blackknightimage = "♘";
	gamepieceimages.whiteknightimage = "♞";
	gamepieceimages.blackbishopimage = "♗";
	gamepieceimages.whitebishopimage = "♝";
	gamepieceimages.blackqueenimage = "♕";
	gamepieceimages.whitequeenimage = "♛";
	gamepieceimages.blackkingimage = "♔";
	gamepieceimages.whitekingimage = "♚";
	//creating the piece objects
	rook blackrook1("black", 1, 1, gamepieceimages.blackrookimage, gamepieceimages.whiterookimage);
	knight blackknight1("black", 2, 1, gamepieceimages.blackknightimage, gamepieceimages.whiteknightimage);
	bishop blackbishop1("black", 3, 1, gamepieceimages.blackbishopimage, gamepieceimages.whitebishopimage);
	queen blackqueen("black", 4, 1, gamepieceimages.blackqueenimage, gamepieceimages.whitequeenimage);
	king blackking("black", 5, 1, gamepieceimages.blackkingimage, gamepieceimages.whitekingimage);
	bishop blackbishop2("black", 6, 1, gamepieceimages.blackbishopimage, gamepieceimages.whitebishopimage);
	knight blackknight2("black", 7, 1, gamepieceimages.blackknightimage, gamepieceimages.whiteknightimage);
	rook blackrook2("black", 8, 1, gamepieceimages.blackrookimage, gamepieceimages.whiterookimage);
	pawn blackpawn1("black", 1, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn2("black", 2, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn3("black", 3, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn4("black", 4, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn5("black", 5, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn6("black", 6, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn7("black", 7, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn blackpawn8("black", 8, 2, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn1("white", 1, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn2("white", 2, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn3("white", 3, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn4("white", 4, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn5("white", 5, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn6("white", 6, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn7("white", 7, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	pawn whitepawn8("white", 8, 7, gamepieceimages.blackpawnimage, gamepieceimages.whitepawnimage);
	rook whiterook1("white", 1, 8, gamepieceimages.blackrookimage, gamepieceimages.whiterookimage);
	knight whiteknight1("white", 2, 8, gamepieceimages.blackknightimage, gamepieceimages.whiteknightimage);
	bishop whitebishop1("white", 3, 8, gamepieceimages.blackbishopimage, gamepieceimages.whitebishopimage);
	queen whitequeen("white", 4, 8, gamepieceimages.blackqueenimage, gamepieceimages.whitequeenimage);
	king whiteking("white", 5, 8, gamepieceimages.blackkingimage, gamepieceimages.whitekingimage);
	bishop whitebishop2("white", 6, 8, gamepieceimages.blackbishopimage, gamepieceimages.whitebishopimage);
	knight whiteknight2("white", 7, 8, gamepieceimages.blackknightimage, gamepieceimages.whiteknightimage);
	rook whiterook2("white", 8, 8, gamepieceimages.blackrookimage, gamepieceimages.whiterookimage);
	//creating the array of the piece objects
	piece pieces[] = {
		blackrook1,
		blackknight1,
		blackbishop1,
		blackqueen,
		blackking,
		blackbishop2,
		blackknight2,
		blackrook2,
		blackpawn1,
		blackpawn2,
		blackpawn3,
		blackpawn4,
		blackpawn5,
		blackpawn6,
		blackpawn7,
		blackpawn8,
		whitepawn1,
		whitepawn2,
		whitepawn3,
		whitepawn4,
		whitepawn5,
		whitepawn6,
		whitepawn7,
		whitepawn8,
		whiterook1,
		whiteknight1,
		whitebishop1,
		whitequeen,
		whiteking,
		whitebishop2,
		whiteknight2,
		whiterook2
	};
	bool whiteturn = true;
	//game starts
	while (true) {
		//saying who's turn it is
		if (whiteturn == true) {
			cout << "It's white's turn." << endl;
			whiteturn = false;
		}
		else if (whiteturn == false) {
			cout << "It's black's turn." << endl;
			whiteturn = true;
		}
		//displaying the board
		displayboard(pieces);
		//asking the coords of which piece they want to move.
		cout << "x position of piece you want to move?" << endl;
		int xchoice;
		cin >> xchoice;
		cout << "y position of piece you want to move?" << endl;
		int ychoice;
		cin >> ychoice;
		//getting the piece object they want to move. if they chose an empty tile or an enemy piece, nopiece will be true.
		piece movingpiece;
		bool nopiece = true;
		for (int i = 0; i < 32; i++) {
			if (pieces[i].getx() == xchoice && pieces[i].gety() == ychoice) {
				if (pieces[i].getteam() == "white" && whiteturn == true) {
					movingpiece = pieces[i];
					nopiece = false;
				}
				else if (pieces[i].getteam() == "black" && whiteturn == false) {
					movingpiece = pieces[i];
					nopiece = false;
				}
			}
		}
		//asking the coords of the tile they want to move the piece
		cout << "x position of the tile you want to move to?" << endl;
		int newxchoice;
		cin >> newxchoice;
		cout << "y position of the tile you want to move to?" << endl;
		int newychoice;
		cin >> newychoice;
		//check if position has a piece, is on the team of the person's turn, and if the move is legal. if not, loop again.
		if (movingpiece.checkvalidmove(newxchoice, newychoice, pieces) == false || nopiece == true) {
			cout << "Invalid move. Try again." << endl;
			//this is ensuring it's the same person's turn when it loops again
			if (whiteturn == true) {
				whiteturn = false;
			}
			else if (whiteturn == false) {
				whiteturn = true;
			}
			//this should loop back to a new turn attempt
			continue;
		}
		//if it passes all the move checks, then it actually moves the piece below
		for (int i = 0; i < 32; i++) {
			if (pieces[i].getx() == xchoice && pieces[i].gety() == ychoice) {
				pieces[i].setx(newxchoice);
				pieces[i].sety(newychoice);
			}
		}
	}
	//game ends
	cout << "Game over." << endl;
    return 0;
}

/*
♖♘♗♕♔♗♘♖
♙♙♙♙♙♙♙♙


♟️♟️♟️♟️♟️♟️♟️♟️
♜♞♝♚♛♝♞♜
*/

/*
things to figure out for the future:
-promotion
-castling
-check and checkmate
-error checking all user inputs
-error checking picking tiles off the board
-BUILDING YOUR OWN CHESS AI????
*/
