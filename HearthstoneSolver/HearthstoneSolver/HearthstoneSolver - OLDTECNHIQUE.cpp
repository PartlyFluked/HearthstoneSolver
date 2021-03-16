#include <iostream>
#include "initializeData.h"
#include "initializeData.cpp"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));
	initializeHeroes();
	initializeCards();
	createTestGamespace();
}

void createTestGamespace() {
	GameSpace tGame;
	tGame.Phero = Mage;
	tGame.Ohero = Mage;
	initDecks(tGame);
	while (true) {
		game(tGame);
	}
}

void initDecks(GameSpace tGame) {
	int size = Cards.size();
	int i = 0;
	while(i<30) {
		Card test = Cards[rand() % size];
		if (test.hero != tGame.Ohero.name && test.hero != "" && test.collect) {
			tGame.Odeck[i] = test; //	todo remove dupes
			i++;
		}
	}

	int j = 0;
	while (j<30) {
		Card test = Cards[rand() % size];
		if (test.hero != tGame.Phero.name && test.hero != "" && test.collect) {
			tGame.Pdeck[j] = test; //	todo remove dupes
			j++;
		}
	}
}

void game(GameSpace tGame) {
	int first = rand() % 2;
	bool playing = true;

	if (first == 0) { draw(0, 3); draw(1, 4); }
	else { draw(1, 3); draw(0, 4); }

	int turn = first;

	while (playing) {
		while (turn == 0) {
			//target choices 9<x<25 //play choices 17<x<36
			int plaNumish = 0;
			vector<int> playBoard, playHand;
			for (int i = 0; i < tGame.Pboard.size(); i++) {
				if (tGame.Pboard[i].ready) { playBoard.push_back(i+18); plaNumish++; }
			}
			for (int i = 0; i < tGame.Phand.size(); i++) {
				if (tGame.Phand[i].cost <= tGame.PCmana) { playHand.push_back(i+26); plaNumish++; }
			}
			double eotchance = 2/(5*plaNumish);
			if (rand() < eotchance) {turn=1;}//END TURN
			int tar = rand() % 26 + 10, cho = rand() % 2, pla;
			while (true) {
				pla = rand() % 36 + 18; 
				if (find(playHand.begin(), playHand.end(), pla) != playHand.end() || find(playBoard.begin(), playBoard.end(), pla) != playBoard.end()) { break; }
			}
			if (playable(turn, pla, tar, cho, tGame)) {
				play(turn, pla, tar, cho, tGame);
			}
		}
		while (turn == 1) {

		}
	}
}

bool playable(int turn, int p, int t, int c, GameSpace tGame) {
	if (turn == 0){
		if (p>25) { //playing card from hand
			if (tGame.Phand[p - 26].type == "Spell") {
				string function = tGame.Phand[p - 26].fx2[0];
				size_t pos = function.find(":");
				string prearg = function.substr(0, pos), prearg2 = NULL;
				function = function.substr(pos+1);
				pos = function.find(":");
				if (pos != string::npos) {
					prearg2 = function.substr(0, pos);
					function = function.substr(pos + 1);
				}
				vector<string> args;
				stringstream ss(function);
				string item;
				while (getline(ss, item, '|')) {
					args.push_back(item);
				}
				vector<string> area;
				stringstream ss(args[0]);
				while (getline(ss, item, ',')) {
					area.push_back(item);
				}
				vector<string> type;
				stringstream ss(args[1]);
				while (getline(ss, item, ',')) {
					type.push_back(item);
				}
				vector<string> target;
				stringstream ss(args[2]);
				while (getline(ss, item, ',')) {
					target.push_back(item);
				}
				vector<string> effect;
				stringstream ss(args[3]);
				while (getline(ss, item, ',')) {
					effect.push_back(item);
				}

				Card * cTarget;
				if (t<10) {
					cTarget = &tGame.Ohand[t];
				}
				else if (t<18) {
					cTarget = &tGame.Oboard[t - 10];
				}
				else if (t<26) {
					cTarget = &tGame.Pboard[t - 18];
				}
				else{
					cTarget = &tGame.Phand[t - 26];
				}

				if (area[0] == "board") {
					if(t < 10 || t > 25) { return false; }
				}
				if (area[0] == "Oboard") {
					if(t < 10 || t > 17) { return false; }
				}
				if (area[0] == "Pboard") {
					if (t < 18 || t > 25) { return false; }
				}
				if (area[0] == "Phand") {
					if (t < 26) { return false; }
				}
				if (area[0] == "Ohand") {
					if (t > 9) { return false; }
				}
				if (type[0] != "nan") {
					if (type[0] != (*cTarget).type) { return false; }
				}
				if (target[0] != "nan") {
					if (target[0] == "self") {
						cTarget = &tGame.Phand[p - 26];
					}
					else if (target[0] == "cho") {

					}
					else if (target[0] == "all") {

					}
				}
				if (effect[0] != "nan") {
					if (effect[0] == "Destroy") {
						if (t<10) {
							tGame.Ohand.erase(tGame.Ohand.begin()+t);
						}
						else if (t<18) {
							tGame.Oboard.erase(tGame.Oboard.begin() + t - 10);
						}
						else if (t<26) {
							tGame.Pboard.erase(tGame.Pboard.begin() + t - 18);
						}
						else {
							tGame.Phand.erase(tGame.Phand.begin() + t - 26);
						}
					}
					if (effect[0].find("transform") != string::npos) {

					}
					if (effect[0].find("summon") != string::npos) {

					}
					string oper[3];
					if (effect[0].find("dam") != string::npos) {
						oper[0] = "dam";
					}
					if (effect[0].find("hp") != string::npos) {
						oper[0] = "hp";
					}
					if (effect[0].find("atk") != string::npos) {
						oper[0] = "atk";
					}
					if (effect[0].find("dur") != string::npos) {
						oper[0] = "dur";
					}
					if (effect[0].find("cost") != string::npos) {
						oper[0] = "cost";
					}
				}

				tGame.Oboard[p - 26].
			}
			if (tGame.Phand[p - 26].type == "Minion") {
				for (int i = 0; i < 18; i++) {
					if (tGame.Phand[p - 26].fx[i] && i == 0) {

					}
				}
			}
		}
		else if (p>17) { //playing card on board 
			if (tGame.Pboard[p - 18].type == "Spell") {
			
			}
		}
	}
	if (false) { return true; }
	return true;
}

bool play(int turn, int p, int t, int c, GameSpace tGame) {
	tGame.Phand[n];
	bool possible = true;



	return possible;
}

void draw(int p, int n) {
	if (p == 0) {}
	else {}
}