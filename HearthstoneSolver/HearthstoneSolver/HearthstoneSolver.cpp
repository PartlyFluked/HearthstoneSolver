#include "initializeData.h"
#include <omp.h>

string Places[4] = { "BOARD","HAND","DECK","GRAVEYARD" };

vector<TimeTravel> nodes;
TimeTravel currNode;
GameSpace *Player;
playInfo currPlay;
size_t globID;
int moveSet = -1, skipSet = 0;
double wrSet = 0;
size_t cMove = 0;
int thread;

vector <vector<int>> moves;
vector <vector<int>> moveSort;
vector<int> skip;
vector<vector<bool>> kin;

int playNum = 0, turnNum = 1;

bool placeActivity[4] = {  true, true, true, true };

vector<size_t> changeFlags;

#pragma omp threadprivate(currNode, Player, currPlay, globID, moveSet, skipSet, wrSet, cMove, thread, moveSort, skip, kin, playNum, turnNum, placeActivity, changeFlags, pCards, AGame, BGame, historyData, pMods, unusedMod, triggers, turnpoints, auras)

using namespace std;

void initializeCards();
vector< vector<string> > convertCode(string line);
void createTestGamespace();
void fullGame();
void flattenMod(size_t Card);
void initDecks();
int game();
void checkDead();
bool checkTrig(playInfo *play, string trig);
void syncAura();
void activateCard(Card card);
void deactivateCard(Card card, int x = -1);
bool affect(int trig, size_t mPlay, playInfo *play, size_t skip = NULL);
string simplify(size_t cPlay, string expression, vector<playHistory> *pHist = NULL);
bool play(size_t cPlay);
int turnTr(int loc);
vector<size_t> draw(int n, GameSpace *Player);

#include <windows.h>
#include <commctrl.h>
#include "resource.h"

const char g_szClassName[] = "myWindowClass";
const char g_boardClassName[] = "myBoardClass";

#define IDC_MAIN_BOARD	101
#define IDC_MAIN_TOOL	102
#define IDC_MAIN_STATUS	103
#define IDC_MAIN_HISTORY 104
#define IDC_GAME_PHAND 200
#define IDC_GAME_PBOARD 210
#define IDC_GAME_OHAND 220
#define IDC_GAME_OBOARD 230
#define IDC_GAME_PDECK 240
#define IDC_GAME_PSECRETS 300
#define IDC_GAME_PTRIGGERS 310
#define IDC_GAME_PDELAYED 340
#define IDC_GAME_PAURAS 370
#define IDC_GAME_PGRAVE 400
#define IDC_GAME_ODECK 490
#define IDC_GAME_OSECRETS 550
#define IDC_GAME_OTRIGGERS 560
#define IDC_GAME_ODELAYED 590
#define IDC_GAME_OAURAS 620
#define IDC_GAME_OGRAVE 650
#define IDC_GAME_CARDS 1000
#define IDC_GAME_PCARDS 2000


ofstream myfile, movefile, moveSorted, winSorted;
HFONT g_hfFont = NULL;
BOOL g_bOpaque = TRUE;
COLORREF g_rgbText = RGB(0, 0, 0);
COLORREF g_rgbBackground = RGB(255, 255, 255);

COLORREF g_rgbCustom[16] = { 0 };

HWND globHwnd;
Card tempView;
Card* cardView;

void DoFileSave(HWND hwnd) //serialises all data needed onto a file
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "Data Files (*.dat)\0*.dat\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "dat";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&ofn))
	{
		ofstream ofs(szFileName, ofstream::binary);
		size_t buf = 0;

		//	AGAME VVV
		ofs.write((char*)&AGame.side, sizeof(size_t));

		ofs.write((char*)&AGame.hero, sizeof(size_t));


		ofs.write((char*)&(buf = sizeof(char)*pCards[AGame.hero].name.size()), sizeof(size_t));
		ofs.write(pCards[AGame.hero].name.c_str(), buf);
		ofs.write((char*)&pCards[AGame.hero].cost, sizeof(int));
		ofs.write((char*)&pCards[AGame.hero].hpc, sizeof(int));
		ofs.write((char*)&pCards[AGame.hero].hpm, sizeof(int));
		ofs.write((char*)&pCards[AGame.hero].modsFx, sizeof(pCards[AGame.hero].modsFx));
		ofs.write((char*)&pCards[AGame.hero].ready, sizeof(int));

		ofs.write((char*)&AGame.hPwr, sizeof(size_t));
		ofs.write((char*)&AGame.pReady, sizeof(int));
		ofs.write((char*)&AGame.pwrCost, sizeof(int));
		ofs.write((char*)&AGame.weapon, sizeof(size_t));

		ofs.write((char*)&AGame.fatigue, sizeof(int));

		ofs.write((char*)&AGame.spDam, sizeof(int));

		ofs.write((char*)&(buf = AGame.deck.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&AGame.deck[i], sizeof(size_t));
		}
		ofs.write((char*)&AGame.drawn, sizeof(int));
		ofs.write((char*)&(buf = AGame.hand.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&AGame.hand[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = AGame.secrets.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&AGame.secrets[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = AGame.grave.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&AGame.grave[i], sizeof(size_t));
		}
		ofs.write((char*)&AGame.cMana, sizeof(int));
		ofs.write((char*)&AGame.mMana, sizeof(int));
		ofs.write((char*)&AGame.o1Mana, sizeof(int));
		ofs.write((char*)&AGame.o2Mana, sizeof(int));
		ofs.write((char*)&(buf = AGame.board.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&AGame.board[i], sizeof(size_t));
		}

		// BGAME VVV
		ofs.write((char*)&BGame.side, sizeof(int));

		ofs.write((char*)&BGame.hero, sizeof(int));

		ofs.write((char*)&(buf = sizeof(char)*pCards[BGame.hero].name.size()), sizeof(size_t));
		ofs.write(pCards[BGame.hero].name.c_str(), buf);
		ofs.write((char*)&pCards[BGame.hero].cost, sizeof(int));
		ofs.write((char*)&pCards[BGame.hero].hpc, sizeof(int));
		ofs.write((char*)&pCards[BGame.hero].hpm, sizeof(int));
		ofs.write((char*)&pCards[BGame.hero].modsFx, sizeof(pCards[BGame.hero].modsFx));
		ofs.write((char*)&pCards[BGame.hero].ready, sizeof(int));

		ofs.write((char*)&BGame.hPwr, sizeof(size_t));
		ofs.write((char*)&BGame.pwrCost, sizeof(int));
		ofs.write((char*)&BGame.weapon, sizeof(size_t));
		ofs.write((char*)&BGame.pReady, sizeof(int));

		ofs.write((char*)&BGame.fatigue, sizeof(int));

		ofs.write((char*)&BGame.spDam, sizeof(int));

		ofs.write((char*)&(buf = BGame.deck.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&BGame.deck[i], sizeof(size_t));
		}
		ofs.write((char*)&BGame.drawn, sizeof(int));
		ofs.write((char*)&(buf = BGame.hand.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&BGame.hand[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = BGame.secrets.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&BGame.secrets[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = BGame.grave.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&BGame.grave[i], sizeof(size_t));
		}
		ofs.write((char*)&BGame.cMana, sizeof(int));
		ofs.write((char*)&BGame.mMana, sizeof(int));
		ofs.write((char*)&BGame.o1Mana, sizeof(int));
		ofs.write((char*)&BGame.o2Mana, sizeof(int));
		ofs.write((char*)&(buf = BGame.board.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&BGame.board[i], sizeof(size_t));
		}

		// GLOBALS VVV
		ofs.write((char*)&(buf = historyData.size()), sizeof(size_t));
		ofs.write((char*)&(buf = pCards.size()), sizeof(size_t));

		for (size_t i = 0; i < historyData.size(); i++) {
			ofs.write((char*)&(buf = sizeof(char)*historyData[i].name.size()), sizeof(size_t));
			ofs.write(historyData[i].name.c_str(), buf);
			ofs.write((char*)&(buf = sizeof(char)*historyData[i].flavour.size()), sizeof(size_t));
			ofs.write(historyData[i].flavour.c_str(), buf);
			ofs.write((char*)&(buf = sizeof(char)*historyData[i].from1.size()), sizeof(size_t));
			ofs.write(historyData[i].from1.c_str(), buf);
			ofs.write((char*)&(buf = sizeof(char)*historyData[i].to1.size()), sizeof(size_t));
			ofs.write(historyData[i].to1.c_str(), buf);
			ofs.write((char*)&historyData[i].side1, sizeof(int));
			ofs.write((char*)&historyData[i].from2, sizeof(int));
			ofs.write((char*)&(buf = historyData[i].to2.size()), sizeof(size_t));
			for (size_t j = 0; j < buf; j++) {
				ofs.write((char*)&historyData[i].to2[j], sizeof(int));
			}
		}
		for (size_t i = 0; i < pCards.size(); i++) {
			ofs.write((char*)&(buf = sizeof(char)*pCards[i].name.size()), sizeof(size_t));
			ofs.write(pCards[i].name.c_str(), buf);
			ofs.write((char*)&(buf = sizeof(char)*pCards[i].id.size()), sizeof(size_t));
			ofs.write(pCards[i].id.c_str(), buf);
			ofs.write((char*)&(buf = sizeof(char)*pCards[i].rarity.size()), sizeof(size_t));
			ofs.write(pCards[i].rarity.c_str(), buf);
			ofs.write((char*)&pCards[i].collect, sizeof(bool));
			ofs.write((char*)&pCards[i].cType, sizeof(size_t));
			ofs.write((char*)&pCards[i].cRole, sizeof(size_t));
			ofs.write((char*)&pCards[i].cRace, sizeof(size_t));
			ofs.write((char*)&pCards[i].cost, sizeof(int));
			ofs.write((char*)&pCards[i].atk, sizeof(int));
			ofs.write((char*)&pCards[i].hpc, sizeof(int));
			ofs.write((char*)&pCards[i].hpm, sizeof(int));
			ofs.write((char*)&pCards[i].mods, sizeof(pCards[i].mods));
			ofs.write((char*)&pCards[i].modsFx, sizeof(pCards[i].modsFx));
			ofs.write((char*)&(buf = sizeof(char)*pCards[i].cMods[0].size()), sizeof(size_t));
			for (size_t j = 0; j < pCards[i].cMods[0].size(); j++) {
				ofs.write((char*)&pCards[i].cMods[j], sizeof(size_t));
			}
			//ofs.write((char*)&(buf = sizeof(char)*pCards[i].slaves.size()), sizeof(size_t));
			//for (size_t j = 0; j < pCards[i].slaves.size(); j++) {
			//	ofs.write((char*)&pCards[i].slaves[j], sizeof(size_t));
			//}
			ofs.write((char*)&pCards[i].playNum, sizeof(int));

			ofs.write((char*)&(buf = sizeof(char)*pCards[i].flavour.size()), sizeof(size_t));
			ofs.write(pCards[i].flavour.c_str(), buf);

			ofs.write((char*)&pCards[i].modsFx, sizeof(pCards[i].modsFx));
			/*
			for (size_t j = 0; j < 19; j++) {

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].prearg[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].prearg[j].size(); k++) {
					ofs.write((char*)&(buf = sizeof(char)*pCards[i].prearg[j][k].size()), sizeof(size_t));
					for (size_t l = 0; l < pCards[i].prearg[j][k].size(); l++) {
						ofs.write((char*)&(buf = sizeof(char)*pCards[i].prearg[j][k][l].size()), sizeof(size_t));
						ofs.write(pCards[i].prearg[j][k][l].c_str(), buf);
					}
				}

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].postarg[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].postarg[j].size(); k++) {
					ofs.write((char*)&(buf = sizeof(char)*pCards[i].postarg[j][k].size()), sizeof(size_t));
					for (size_t l = 0; l < pCards[i].postarg[j][k].size(); l++) {
						ofs.write((char*)&(buf = sizeof(char)*pCards[i].postarg[j][k][l].size()), sizeof(size_t));
						ofs.write(pCards[i].postarg[j][k][l].c_str(), buf);
					}
				}

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].cTarAr[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].cTarAr[j].size(); k++) { 
					for (size_t l = 0; l < pCards[i].cTarAr[j][k].size(); l++) { //always 11 //make error check for not 11?
						ofs.write((char*)&pCards[i].cTarAr[j][k][l], sizeof(bool));
					}
				}

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].cTarTy[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].cTarTy[j].size(); k++) { 
					for (size_t l = 0; l < pCards[i].cTarTy[j][k].size(); l++) { //always 15
						ofs.write((char*)&pCards[i].cTarTy[j][k][l], sizeof(bool));
					}
				}

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].target[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].target[j].size(); k++) {
					ofs.write((char*)&(buf = sizeof(char)*pCards[i].target[j][k].size()), sizeof(size_t));
					ofs.write(pCards[i].target[j][k].c_str(), buf);
				}

				ofs.write((char*)&(buf = sizeof(char)*pCards[i].effect[j].size()), sizeof(size_t));
				for (size_t k = 0; k < pCards[i].effect[j].size(); k++) {
					ofs.write((char*)&(buf = sizeof(char)*pCards[i].effect[j][k].size()), sizeof(size_t));
					for (size_t l = 0; l < pCards[i].effect[j][k].size(); l++) {
						ofs.write((char*)&(buf = sizeof(char)*pCards[i].effect[j][k][l].size()), sizeof(size_t));
						ofs.write(pCards[i].effect[j][k][l].c_str(), buf);
					}
				}
			}
			*/
			ofs.write((char*)&pCards[i].ready, sizeof(int));
			ofs.write((char*)&pCards[i].place, sizeof(int));
			ofs.write((char*)&pCards[i].side, sizeof(int));
		}

		ofs.write((char*)&(buf = pMods.size()), sizeof(size_t));
		for (size_t i = 0; i < pMods.size(); i++) {
			ofs.write((char*)&pMods[i].master, sizeof(size_t));
			ofs.write((char*)&pMods[i].fx, sizeof(pMods[i].fx));
			ofs.write((char*)&pMods[i].mods, sizeof(pMods[i].mods));
			ofs.write((char*)&pMods[i].timer, sizeof(int));
			ofs.write((char*)&pMods[i].targ, sizeof(size_t));
		}

		ofs.write((char*)&(buf = triggers.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&triggers[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = turnpoints.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&turnpoints[i], sizeof(size_t));
		}
		ofs.write((char*)&(buf = auras.size()), sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			ofs.write((char*)&auras[i], sizeof(size_t));
		}

		ofs.write((char*)&playNum, sizeof(int));
		ofs.write((char*)&Player->side, sizeof(int));

		ofs.close();

		SetWindowText(hwnd, szFileName);
	}
}

void DoFileOpen(HWND hwnd)
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "Data Files (*.dat)\0*.dat\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "dat";

	if (GetOpenFileName(&ofn))
	{
		ifstream ifs(szFileName, ifstream::binary);

		//ifs.read((char*)&x, sizeof(long));

		size_t buf = 0;
		AGame = {};
		BGame = {};
		pCards.clear();
		historyData.clear();
		ifs.read((char*)&AGame.side, sizeof(size_t));

		ifs.read((char*)&AGame.hero, sizeof(size_t)); //no str id?
		ifs.read((char*)&buf, sizeof(size_t));
		char* temp2 = new char[buf + 1];
		ifs.read(temp2, buf); temp2[buf] = '\0'; pCards[AGame.hero].name = temp2; delete[] temp2;
		ifs.read((char*)&pCards[AGame.hero].cost, sizeof(int));
		ifs.read((char*)&pCards[AGame.hero].hpc, sizeof(int));
		ifs.read((char*)&pCards[AGame.hero].hpm, sizeof(int));
		ifs.read((char*)&pCards[AGame.hero].modsFx, sizeof(pCards[AGame.hero].modsFx));
		ifs.read((char*)&pCards[AGame.hero].ready, sizeof(int));

		ifs.read((char*)&AGame.hPwr, sizeof(size_t));
		ifs.read((char*)&AGame.pReady, sizeof(size_t));
		ifs.read((char*)&AGame.pwrCost, sizeof(size_t));
		ifs.read((char*)&AGame.weapon, sizeof(size_t));

		ifs.read((char*)&AGame.fatigue, sizeof(size_t));
		ifs.read((char*)&AGame.spDam, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			AGame.deck.push_back(NULL);
			ifs.read((char*)&AGame.deck[i], sizeof(size_t));
		}
		ifs.read((char*)&AGame.drawn, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			AGame.hand.push_back(NULL);
			ifs.read((char*)&AGame.hand[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			AGame.secrets.push_back(NULL);
			ifs.read((char*)&AGame.secrets[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			AGame.grave.push_back(NULL);
			ifs.read((char*)&AGame.grave[i], sizeof(size_t));
		}
		ifs.read((char*)&AGame.cMana, sizeof(size_t));
		ifs.read((char*)&AGame.mMana, sizeof(size_t));
		ifs.read((char*)&AGame.o1Mana, sizeof(size_t));
		ifs.read((char*)&AGame.o2Mana, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			AGame.board.push_back(NULL);
			ifs.read((char*)&AGame.board[i], sizeof(size_t));
		}


		ifs.read((char*)&BGame.side, sizeof(size_t));

		ifs.read((char*)&BGame.hero, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		temp2 = new char[buf + 1];
		ifs.read(temp2, buf); temp2[buf] = '\0'; pCards[BGame.hero].name = temp2; delete[] temp2;
		ifs.read((char*)&pCards[BGame.hero].cost, sizeof(int));
		ifs.read((char*)&pCards[BGame.hero].hpc, sizeof(int));
		ifs.read((char*)&pCards[BGame.hero].hpm, sizeof(int));
		ifs.read((char*)&pCards[BGame.hero].modsFx, sizeof(pCards[BGame.hero].modsFx));
		ifs.read((char*)&pCards[BGame.hero].ready, sizeof(int));

		ifs.read((char*)&BGame.hPwr, sizeof(size_t));
		ifs.read((char*)&BGame.pReady, sizeof(size_t));
		ifs.read((char*)&BGame.pwrCost, sizeof(size_t));
		ifs.read((char*)&BGame.weapon, sizeof(size_t));

		ifs.read((char*)&BGame.fatigue, sizeof(size_t));
		ifs.read((char*)&BGame.spDam, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			BGame.deck.push_back(NULL);
			ifs.read((char*)&BGame.deck[i], sizeof(size_t));
		}
		ifs.read((char*)&BGame.drawn, sizeof(size_t));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			BGame.hand.push_back(NULL);
			ifs.read((char*)&BGame.hand[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			BGame.secrets.push_back(NULL);
			ifs.read((char*)&BGame.secrets[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			BGame.grave.push_back(NULL);
			ifs.read((char*)&BGame.grave[i], sizeof(size_t));
		}
		ifs.read((char*)&BGame.cMana, sizeof(int));
		ifs.read((char*)&BGame.mMana, sizeof(int));
		ifs.read((char*)&BGame.o1Mana, sizeof(int));
		ifs.read((char*)&BGame.o2Mana, sizeof(int));
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			BGame.board.push_back(NULL);
			ifs.read((char*)&BGame.board[i], sizeof(size_t));
		}

		size_t hDs = 0, pCs = 0;
		ifs.read((char*)&hDs, sizeof(size_t));
		ifs.read((char*)&pCs, sizeof(size_t));

		for (size_t i = 0; i < hDs; i++) {
			playData temp;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.name = temp2; delete[] temp2;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.flavour = temp2; delete[] temp2;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.from1 = temp2; delete[] temp2;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.to1 = temp2; delete[] temp2;
			ifs.read((char*)&temp.side1, sizeof(int));
			ifs.read((char*)&temp.from2, sizeof(int));
			ifs.read((char*)&buf, sizeof(size_t));
			for (size_t j = 0; j < buf; j++) {
				temp.to2.push_back(NULL);
				ifs.read((char*)&temp.to2[j], sizeof(int));
			}
			historyData.push_back(temp);
		}
		for (size_t i = 0; i < pCs; i++) {
			Card temp;
			ifs.read((char*)&buf, sizeof(size_t));
			char* temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.name = temp2; delete[] temp2;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.id = temp2; delete[] temp2;
			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.rarity = temp2; delete[] temp2;
			ifs.read((char*)&temp.collect, sizeof(bool));
			ifs.read((char*)&temp.cType, sizeof(size_t));
			ifs.read((char*)&temp.cRole, sizeof(size_t));
			ifs.read((char*)&temp.cRace, sizeof(size_t));
			ifs.read((char*)&temp.cost, sizeof(int));
			ifs.read((char*)&temp.atk, sizeof(int));
			ifs.read((char*)&temp.hpc, sizeof(int));
			ifs.read((char*)&temp.hpm, sizeof(int));
			ifs.read((char*)&temp.mods, sizeof(temp.mods));
			ifs.read((char*)&temp.modsFx, sizeof(temp.modsFx));
			/*
			ifs.read((char*)&buf, sizeof(size_t));
			for (size_t j = 0; j < buf; j++) {
				temp.cMods.push_back(NULL);
				ifs.read((char*)&temp.cMods[j], sizeof(size_t));
			}
			ifs.read((char*)&buf, sizeof(size_t));
			for (size_t j = 0; j < buf; j++) {
				temp.slaves.push_back(NULL);
				ifs.read((char*)&temp.slaves[j], sizeof(size_t));
			}
			ifs.read((char*)&temp.playNum, sizeof(size_t));

			ifs.read((char*)&buf, sizeof(size_t));
			temp2 = new char[buf + 1];
			ifs.read(temp2, buf); temp2[buf] = '\0'; temp.flavour = temp2; delete[] temp2;

			ifs.read((char*)&temp.fx, sizeof(temp.fx));

			for (size_t j = 0; j < 19; j++) {

				size_t buf2, buf3;
				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					temp.prearg[j].push_back({});
					ifs.read((char*)&buf2, sizeof(size_t));
					for (size_t l = 0; l < buf2; l++) {
						ifs.read((char*)&buf, sizeof(size_t));
						temp2 = new char[buf + 1];
						ifs.read(temp2, buf); temp2[buf] = '\0';
						temp.prearg[j][k].push_back(temp2);
						delete[] temp2;
					}
				}

				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					temp.postarg[j].push_back({});
					ifs.read((char*)&buf2, sizeof(size_t));
					for (size_t l = 0; l < buf2; l++) {
						ifs.read((char*)&buf, sizeof(size_t));
						temp2 = new char[buf + 1];
						ifs.read(temp2, buf); temp2[buf] = '\0';
						temp.postarg[j][k].push_back(temp2);
						delete[] temp2;
					}
				}

				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					vector <bool> cTarAr(11);
					for (size_t l = 0; l < 11; l++) {
						ifs.read((char*)&cTarAr[l], sizeof(bool));
					}
					temp.cTarAr[j].push_back(cTarAr);
				}

				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					vector <bool> cTarTy(15);
					for (size_t l = 0; l < 15; l++) {
						ifs.read((char*)&cTarTy[l], sizeof(bool));
					}
					temp.cTarTy[j].push_back(cTarTy);
				}

				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					ifs.read((char*)&buf2, sizeof(size_t));
					temp2 = new char[buf2 + 1];
					ifs.read(temp2, buf2); temp2[buf2] = '\0';
					temp.target[j].push_back(temp2);
					delete[] temp2;
				}

				ifs.read((char*)&buf3, sizeof(size_t));
				for (size_t k = 0; k < buf3; k++) {
					temp.effect[j].push_back({});
					ifs.read((char*)&buf2, sizeof(size_t));
					for (size_t l = 0; l < buf2; l++) {
						ifs.read((char*)&buf, sizeof(size_t));
						temp2 = new char[buf + 1];
						ifs.read(temp2, buf); temp2[buf] = '\0';
						temp.effect[j][k].push_back(temp2);
						delete[] temp2;
					}
				}

			}
			*/
			ifs.read((char*)&temp.ready, sizeof(int));
			ifs.read((char*)&temp.place, sizeof(int));
			ifs.read((char*)&temp.side, sizeof(int));
			pCards.push_back(temp);
		}

		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			Effect temp;
			ifs.read((char*)&temp.master, sizeof(size_t));
			ifs.read((char*)&temp.fx, sizeof(temp.fx));
			ifs.read((char*)&temp.mods, sizeof(temp.mods));
			ifs.read((char*)&temp.timer, sizeof(int));
			ifs.read((char*)&temp.targ, sizeof(size_t));
			pMods.push_back(temp);
		}

		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			triggers.push_back(NULL);
			ifs.read((char*)&triggers[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			turnpoints.push_back(NULL);
			ifs.read((char*)&turnpoints[i], sizeof(size_t));
		}
		ifs.read((char*)&buf, sizeof(size_t));
		for (size_t i = 0; i < buf; i++) {
			auras.push_back(NULL);
			ifs.read((char*)&auras[i], sizeof(size_t));
		}

		ifs.read((char*)&playNum, sizeof(int));
		int buf2 = 0;

		ifs.read((char*)&buf2, sizeof(int));
		if (buf2 == 1) { Player = &AGame; }
		else { Player = &BGame; }
		AGame.Ogame = &BGame;
		BGame.Ogame = &AGame;

		SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_RESETCONTENT, NULL, NULL);
		for (size_t i = SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_GETCOUNT, NULL, NULL); i < historyData.size(); i++) {
			int pos = SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_ADDSTRING, 0, (LPARAM)historyData[i].name.c_str());
			SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_SETITEMDATA, pos, (LPARAM)playNum);
		}
		SendDlgItemMessage(hwnd, IDC_MAIN_HISTORY, LB_SETCURSEL, historyData.size() - 1, 0);
		InvalidateRect(NULL, NULL, FALSE);
		SetWindowText(hwnd, szFileName);
	}
}

BOOL CALLBACK clearChildren(HWND hwnd, LPARAM lParam)
{
	DestroyWindow(hwnd);
	return TRUE;
}

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
		int i = LOWORD(lParam);
		if (i < 210 && i>199) { cardView = &pCards[AGame.hand[i - 200]]; }
		else if (i < 220) { cardView = &pCards[AGame.board[i - 210]]; }
		else if (i < 230) { cardView = &pCards[BGame.hand[i - 220]]; }
		else if (i < 240) { cardView = &pCards[BGame.board[i - 230]]; }

		else if (i < 300) { cardView = &pCards[AGame.deck[i - 240]]; }
		else if (i < 310) { cardView = &pCards[pMods[AGame.secrets[i - 300]].targ]; }
		else if (i < 340) { cardView = &pCards[pMods[triggers[i - 310]].targ]; }
		else if (i < 370) { cardView = &pCards[pMods[turnpoints[i - 340]].targ]; }
		else if (i < 400) { cardView = &pCards[pMods[auras[i - 370]].targ]; } //aura trigger turnpoints in twice why \\  cuase theres 2 comboboxes of it u dip
		else if (i < 490) { cardView = &pCards[AGame.grave[i - 400]]; }
		else if (i < 550) { cardView = &pCards[BGame.deck[i - 490]]; }
		else if (i < 560) { cardView = &pCards[pMods[BGame.secrets[i - 550]].targ]; }
		else if (i < 590) { cardView = &pCards[pMods[triggers[i - 560]].targ]; }
		else if (i < 620) { cardView = &pCards[pMods[turnpoints[i - 590]].targ]; }
		else if (i < 650) { cardView = &pCards[pMods[auras[i - 620]].targ]; }
		else if (i < 1000) { cardView = &pCards[BGame.grave[i - 650]]; }
		else if (i < 2000){ cardView = &Cards[i - 1000]; }
		else if (i > 1999) { cardView = &pCards[i - 2000];
		}
		tempView = *cardView;
		SendDlgItemMessage(hDlg, IDC_NAME_EDIT, WM_SETTEXT, NULL, (LPARAM)tempView.name.c_str());
		SendDlgItemMessage(hDlg, IDC_FLAVOUR_EDIT, WM_SETTEXT, NULL, (LPARAM)tempView.flavour.c_str());
		SendDlgItemMessage(hDlg, IDC_COST_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.cost).c_str());
		SendDlgItemMessage(hDlg, IDC_ATK_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.atk).c_str());
		SendDlgItemMessage(hDlg, IDC_HEALTH_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.hpc).c_str());
		SendDlgItemMessage(hDlg, IDC_MAX_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.hpm).c_str());
		SendDlgItemMessage(hDlg, IDC_MODS0_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.mods[0]).c_str());
		SendDlgItemMessage(hDlg, IDC_MODS1_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.mods[1]).c_str());
		SendDlgItemMessage(hDlg, IDC_MODS2_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.mods[2]).c_str());
		for (int j = 0; j < FXCOUNT; j++) {
			SendDlgItemMessage(hDlg, IDC_FX_COMBO, CB_ADDSTRING, NULL, (LPARAM)to_string(j).c_str());
		}
		SendDlgItemMessage(hDlg, IDC_FX_COMBO, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendDlgItemMessage(hDlg, IDC_FX_CHECK, BM_SETCHECK, tempView.modsFx[0] ? BST_CHECKED : BST_UNCHECKED, NULL);
		string temp = ""; 
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].prearg.size(); j++) {
				for (size_t k = 0; k < pMods[tempView.cMods[0][l]].prearg[j].size(); k++) {
					temp += pMods[tempView.cMods[0][l]].prearg[j][k] + "|";
				}
				temp = temp.substr(0, temp.length() - 1);
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_PREARG_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		temp = "";
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].postarg.size(); j++) {
				for (size_t k = 0; k < pMods[tempView.cMods[0][l]].postarg[j].size(); k++) {
					temp += pMods[tempView.cMods[0][l]].postarg[j][k] + "|";
				}
				temp = temp.substr(0, temp.length() - 1);
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_POSTARG_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		temp = "";
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].cTarAr.size(); j++) {
				if (pMods[tempView.cMods[0][l]].cTarAr[j][AREA]) { temp += "|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][PBOARD]) { temp += "PBOARD|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][OBOARD]) { temp += "OBOARD|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][PHAND]) { temp += "PHAND|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][OHAND]) { temp += "OHAND|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][PDECK]) { temp += "PDECK|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][ODECK]) { temp += "ODECK|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][PGRAVE]) { temp += "PGRAVE|"; }
				if (pMods[tempView.cMods[0][l]].cTarAr[j][OGRAVE]) { temp += "OGRAVE|"; }
				temp = temp.substr(0, temp.length() - 1);
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_AREA_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		temp = "";
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].cTarTy.size(); j++) {
				if (pMods[tempView.cMods[0][l]].cTarTy[j][TYPE]) { temp += "|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][HERO]) { temp += "HERO|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][MINION]) { temp += "MINION|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][SPELL]) { temp += "SPELL|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][SECRET]) { temp += "SECRET|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][WEAPON]) { temp += "WEAPON|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][HEROPWR]) { temp += "HEROPWR|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][BEAST]) { temp += "BEAST|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][DEMON]) { temp += "DEMON|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][MECHANICAL]) { temp += "MECHANICAL|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][MURLOC]) { temp += "MURLOC|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][PIRATE]) { temp += "PIRATE|"; }
				if (pMods[tempView.cMods[0][l]].cTarTy[j][TOTEM]) { temp += "TOTEM|"; }
				temp = temp.substr(0, temp.length() - 1);
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_TARTY_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		temp = "";
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].target.size(); j++) {
				temp += pMods[tempView.cMods[0][l]].target[j];
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_TARGET_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		temp = "";
		for (size_t l = 0; l < tempView.cMods[0].size(); l++) {
			for (size_t j = 0; j < pMods[tempView.cMods[0][l]].effect.size(); j++) {
				for (size_t k = 0; k < pMods[tempView.cMods[0][l]].effect[j].size(); k++) {
					temp += pMods[tempView.cMods[0][l]].effect[j][k] + "|";
				}
				temp = temp.substr(0, temp.length() - 1);
				temp += "?";
			}
		}
		temp = temp.substr(0, temp.length() - 1);
		SendDlgItemMessage(hDlg, IDC_EFFECT_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
		SendDlgItemMessage(hDlg, IDC_PLACE_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.place).c_str());
		SendDlgItemMessage(hDlg, IDC_SIDE_EDIT, WM_SETTEXT, NULL, (LPARAM)to_string(tempView.side).c_str());
		return TRUE;
		}
	case WM_COMMAND:
		if (LOWORD(wParam)>1000 && LOWORD(wParam)<1028 && LOWORD(wParam)!=IDC_FX_CHECK && LOWORD(wParam)!=IDC_FX_COMBO) {
			if (HIWORD(wParam) == EN_KILLFOCUS) {
				char text1[256] = { 0 };
				int length = SendDlgItemMessage(hDlg, LOWORD(wParam), WM_GETTEXTLENGTH, 0, 0);
				if ( length == 0 ) { break; }
				SendDlgItemMessage(hDlg, LOWORD(wParam), WM_GETTEXT, length+1, (LPARAM)text1);
				int k = SendDlgItemMessage(hDlg, IDC_FX_COMBO, CB_GETCURSEL, NULL, NULL);
				string text(text1);
				vector < vector <string> > cStrings;
				vector < vector<bool> > cTarAr;
				vector < vector<bool> > cTarTy;

				if (LOWORD(wParam) == IDC_PREARG_EDIT || LOWORD(wParam) == IDC_POSTARG_EDIT || LOWORD(wParam) == IDC_AREA_EDIT || LOWORD(wParam) == IDC_TARTY_EDIT || LOWORD(wParam) == IDC_TARGET_EDIT || LOWORD(wParam) == IDC_EFFECT_EDIT) {
					cStrings = convertCode(text);
				}
				if (LOWORD(wParam) == IDC_AREA_EDIT) {
					for (size_t i = 0; i < cStrings.size(); i++) {
						vector<bool> temp(ARCOUNT, false);
						cTarAr.push_back(temp);
						for (size_t j = 0; j < cStrings[i].size(); j++) {
							if (cStrings[i][j] == "") { cTarAr[i][AREA] = true; }
							if (cStrings[i][j] == "PBOARD") { cTarAr[i][PBOARD] = true; }
							if (cStrings[i][j] == "OBOARD") { cTarAr[i][OBOARD] = true; }
							if (cStrings[i][j] == "PHAND") { cTarAr[i][PHAND] = true; }
							if (cStrings[i][j] == "OHAND") { cTarAr[i][OHAND] = true; }
							if (cStrings[i][j] == "PDECK") { cTarAr[i][PDECK] = true; }
							if (cStrings[i][j] == "ODECK") { cTarAr[i][ODECK] = true; }
							if (cStrings[i][j] == "PGRAVE") { cTarAr[i][PGRAVE] = true; }
							if (cStrings[i][j] == "OGRAVE") { cTarAr[i][OGRAVE] = true; }
						}
					}
				}
				if (LOWORD(wParam) == IDC_TARTY_EDIT) {
					for (size_t i = 0; i < cStrings.size(); i++) {
						vector<bool> temp(TYCOUNT, false);
						cTarTy.push_back(temp);
						for (size_t j = 0; j < cStrings[i].size(); j++) {
							if (cStrings[i][j] == "") { cTarTy[i][TYPE] = true; }
							if (cStrings[i][j] == "HERO") { cTarTy[i][HERO] = true; }
							if (cStrings[i][j] == "MINION") { cTarTy[i][MINION] = true; }
							if (cStrings[i][j] == "SPELL") { cTarTy[i][SPELL] = true; }
							if (cStrings[i][j] == "SECRET") { cTarTy[i][SECRET] = true; }
							if (cStrings[i][j] == "WEAPON") { cTarTy[i][WEAPON] = true; }
							if (cStrings[i][j] == "HEROPWR") { cTarTy[i][HEROPWR] = true; }
							if (cStrings[i][j] == "BEAST") { cTarTy[i][BEAST] = true; }
							if (cStrings[i][j] == "DEMON") { cTarTy[i][DEMON] = true; }
							if (cStrings[i][j] == "DRAGON") { cTarTy[i][DRAGON] = true; }
							if (cStrings[i][j] == "MECHANICAL") { cTarTy[i][MECHANICAL] = true; }
							if (cStrings[i][j] == "MURLOC") { cTarTy[i][MURLOC] = true; }
							if (cStrings[i][j] == "PIRATE") { cTarTy[i][PIRATE] = true; }
							if (cStrings[i][j] == "TOTEM") { cTarTy[i][TOTEM] = true; }
						}
					}
				}

				switch (LOWORD(wParam))
				{
				case IDC_NAME_EDIT: tempView.name = text; break;
				case IDC_FLAVOUR_EDIT : tempView.flavour = text; break;
				case IDC_TYPE_EDIT: tempView.cType = stoi(text); break;
				case IDC_RACE_EDIT: tempView.cRace = stoi(text); break;
				case IDC_HERO_EDIT: tempView.cRole = stoi(text); break;

				case IDC_PREARG_EDIT: pMods[tempView.cMods[k][0]].prearg = cStrings; break;
				case IDC_POSTARG_EDIT: pMods[tempView.cMods[k][0]].postarg = cStrings; break;
				case IDC_AREA_EDIT: pMods[tempView.cMods[k][0]].cTarAr = cTarAr; break;
				case IDC_TARTY_EDIT: pMods[tempView.cMods[k][0]].cTarTy = cTarTy; break;
				case IDC_TARGET_EDIT: 
					for (size_t i = 0; i < cStrings.size(); i++) {
						pMods[tempView.cMods[k][0]].target.push_back(cStrings[i][0]);
					}
					break; //is this even right
				case IDC_EFFECT_EDIT: pMods[tempView.cMods[k][0]].effect = cStrings; break;

				case IDC_COST_EDIT: tempView.cost = stoi(text); break;
				case IDC_ATK_EDIT: tempView.atk = stoi(text); break;
				case IDC_HEALTH_EDIT: tempView.hpc = stoi(text); break;
				case IDC_MAX_EDIT: tempView.hpm = stoi(text); break;
				case IDC_MODS0_EDIT: tempView.mods[0] = stoi(text); break;
				case IDC_MODS1_EDIT: tempView.mods[1] = stoi(text); break;
				case IDC_MODS2_EDIT: tempView.mods[2] = stoi(text); break;
				case IDC_READY_EDIT: tempView.ready = stoi(text); break;
				case IDC_PLACE_EDIT: tempView.place = stoi(text); break;
				case IDC_SIDE_EDIT: tempView.side = stoi(text); break;
				}
				return TRUE;
			}
		}
		switch (LOWORD(wParam))
		{
		case IDC_FX_COMBO:
			if (HIWORD(wParam) == CBN_SELENDOK) {
				int i = SendDlgItemMessage(hDlg, IDC_FX_COMBO, CB_GETCURSEL, NULL, NULL);
				SendDlgItemMessage(hDlg, IDC_FX_CHECK, BM_SETCHECK, tempView.modsFx[i] ? BST_CHECKED : BST_UNCHECKED, NULL);
				string temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].prearg.size(); j++) {
						for (size_t k = 0; k < pMods[tempView.cMods[i][l]].prearg[j].size(); k++) {
							temp += pMods[tempView.cMods[i][l]].prearg[j][k] + "|";
						}
						temp = temp.substr(0, temp.length() - 1);
						temp += "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_PREARG_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
				temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].postarg.size(); j++) {
						for (size_t k = 0; k < pMods[tempView.cMods[i][l]].postarg[j].size(); k++) {
							temp += pMods[tempView.cMods[i][l]].postarg[j][k] + "|";
						}
						temp = temp.substr(0, temp.length() - 1);
						temp += "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_POSTARG_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
				temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].cTarAr.size(); j++) {
						if (pMods[tempView.cMods[i][l]].cTarAr[j][AREA]) { temp += "|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][PBOARD]) { temp += "PBOARD|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][OBOARD]) { temp += "OBOARD|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][PHAND]) { temp += "PHAND|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][OHAND]) { temp += "OHAND|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][PDECK]) { temp += "PDECK|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][ODECK]) { temp += "ODECK|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][PGRAVE]) { temp += "PGRAVE|"; }
						if (pMods[tempView.cMods[i][l]].cTarAr[j][OGRAVE]) { temp += "OGRAVE|"; }
						temp = temp.substr(0, temp.length() - 1);
						temp += "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_AREA_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
				temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].cTarTy.size(); j++) {
						if (pMods[tempView.cMods[i][l]].cTarTy[j][TYPE]) { temp += "|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][HERO]) { temp += "HERO|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][MINION]) { temp += "MINION|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][SPELL]) { temp += "SPELL|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][SECRET]) { temp += "SECRET|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][WEAPON]) { temp += "WEAPON|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][HEROPWR]) { temp += "HEROPWR|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][BEAST]) { temp += "BEAST|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][DEMON]) { temp += "DEMON|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][MECHANICAL]) { temp += "MECHANICAL|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][MURLOC]) { temp += "MURLOC|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][PIRATE]) { temp += "PIRATE|"; }
						if (pMods[tempView.cMods[i][l]].cTarTy[j][TOTEM]) { temp += "TOTEM|"; }
						temp = temp.substr(0, temp.length() - 1);
						temp += "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_TARTY_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
				temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].target.size(); j++) {
						temp += pMods[tempView.cMods[i][l]].target[j] + "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_TARGET_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
				temp = "";
				for (size_t l = 0; l < tempView.cMods[i].size(); l++) {
					for (size_t j = 0; j < pMods[tempView.cMods[i][l]].effect.size(); j++) {
						for (size_t k = 0; k < pMods[tempView.cMods[i][l]].effect[j].size(); k++) {
							temp += pMods[tempView.cMods[i][l]].effect[j][k] + "|";
						}
						temp = temp.substr(0, temp.length() - 1);
						temp += "?";
					}
				}
				temp = temp.substr(0, temp.length() - 1);
				SendDlgItemMessage(hDlg, IDC_EFFECT_EDIT, WM_SETTEXT, NULL, (LPARAM)temp.c_str());
			}
			return TRUE;
		case IDC_FX_CHECK:
			if (HIWORD(wParam) == BN_CLICKED) {
				int i = SendDlgItemMessage(hDlg, IDC_FX_COMBO, CB_GETCURSEL, NULL, NULL);
				tempView.modsFx[i] = !tempView.modsFx[i];
			}
			return TRUE;
		case IDOK:
			*cardView = tempView;
			//return TRUE;
		case IDCANCEL:
			SendMessage(hDlg, WM_CLOSE, 0, 0);
			return TRUE;
		}
		break;

	case WM_CLOSE:
		if (MessageBox(hDlg, TEXT("Stop Editing?"), TEXT("Close"),
			MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			InvalidateRect(globHwnd, NULL, FALSE);
			DestroyWindow(hDlg);
		}
		return TRUE;

	case WM_DESTROY:
		//PostQuitMessage(0);
		return TRUE;
	}
	return FALSE;
}

LRESULT CALLBACK ChildWndProc(HWND hBoard, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//myfile << hBoard << "\t" << msg << "\t" << HIWORD(wParam) << " " << LOWORD(wParam) << " " << wParam << "\t" << HIWORD(lParam) << " " << LOWORD(lParam) << " " << lParam << endl;
	switch (msg)
	{
	case WM_CREATE:
	{
		SetWindowLong(hBoard, 0, 0);       // on/off flag         
		return 0;
	}
	case WM_PAINT:
	{
		EnumChildWindows(hBoard, clearChildren, 0);

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hBoard, &ps);

		HFONT hfOld = (HFONT)SelectObject(hdc, g_hfFont);

		SetBkColor(hdc, g_rgbBackground);
		SetTextColor(hdc, g_rgbText);

		if (g_bOpaque)
		{
			SetBkMode(hdc, OPAQUE);
		}
		else
		{
			SetBkMode(hdc, TRANSPARENT);
		}

		RECT rcBoard;
		GetClientRect(hBoard, &rcBoard);
		string tempSize;

		HWND hWndComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 160, rcBoard.top + 20, 150, 200, hBoard, (HMENU)IDC_GAME_PDECK, GetModuleHandle(NULL),
			NULL); 
		tempSize = "DECK - " + to_string(AGame.deck.size()); SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = AGame.deck.size()-1; i >= 0; i--) { SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[AGame.deck[i]].name.c_str()); }
		
		HWND hWndComboBox2 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.top + 20, 150, 200, hBoard, (HMENU)IDC_GAME_PSECRETS, GetModuleHandle(NULL),
			NULL);
		tempSize = "SECRETS - " + to_string(AGame.secrets.size());
		SendMessage(hWndComboBox2, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = AGame.secrets.size()-1; i >= 0; i--) { SendMessage(hWndComboBox2, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[AGame.secrets[i]].name.c_str()); }

		HWND hWndComboBox3 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.top + 50, 150, 200, hBoard, (HMENU)IDC_GAME_PTRIGGERS, GetModuleHandle(NULL),
			NULL); 
		tempSize = "TRIGGERS - " + to_string(triggers.size()); SendMessage(hWndComboBox3, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = triggers.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox3, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[triggers[i]].targ].name.c_str()); }

		HWND hWndComboBox4 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.top + 80, 150, 200, hBoard, (HMENU)IDC_GAME_PDELAYED, GetModuleHandle(NULL),
			NULL); 
		tempSize = "DELAYED - " + to_string(turnpoints.size()); SendMessage(hWndComboBox4, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = turnpoints.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox4, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[turnpoints[i]].targ].name.c_str()); }

		HWND hWndComboBox5 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.top + 110, 150, 200, hBoard, (HMENU)IDC_GAME_PAURAS, GetModuleHandle(NULL),
			NULL);
		tempSize = "AURAS - " + to_string(auras.size()); SendMessage(hWndComboBox5, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = auras.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox5, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[auras[i]].targ].name.c_str()); }

		HWND hWndComboBox6 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 160, rcBoard.top + 50, 150, 200, hBoard, (HMENU)IDC_GAME_PGRAVE, GetModuleHandle(NULL),
			NULL);
		tempSize = "GRAVE - " + to_string(AGame.grave.size()); SendMessage(hWndComboBox6, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = AGame.grave.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox6, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[AGame.grave[i]].name.c_str()); }



		HWND hWndCards = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, (rcBoard.bottom - rcBoard.top) / 2 - 40, 150, 200, hBoard, (HMENU)IDC_GAME_CARDS, GetModuleHandle(NULL),
			NULL);
		tempSize = "CARDS - " + to_string(Cards.size()); SendMessage(hWndCards, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = Cards.size() - 1; i >= 0; i--) { SendMessage(hWndCards, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)Cards[i].name.c_str()); }

		HWND hWndpCards = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, 20 + (rcBoard.bottom - rcBoard.top) / 2, 150, 200, hBoard, (HMENU)IDC_GAME_PCARDS, GetModuleHandle(NULL),
			NULL);
		tempSize = "pCARDS - " + to_string(pCards.size()); SendMessage(hWndpCards, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = pCards.size() - 1; i >= 0; i--) { SendMessage(hWndpCards, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[i].name.c_str()); }



		HWND hWndComboBox7 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 160, rcBoard.bottom - 40, 150, 200, hBoard, (HMENU)IDC_GAME_ODECK, GetModuleHandle(NULL),
			NULL); 
		tempSize = "DECK - " + to_string(BGame.deck.size()); SendMessage(hWndComboBox7, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = BGame.deck.size()-1; i >= 0; i--) { SendMessage(hWndComboBox7, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[BGame.deck[i]].name.c_str()); }

		HWND hWndComboBox8 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.bottom - 40, 150, 200, hBoard, (HMENU)IDC_GAME_OSECRETS, GetModuleHandle(NULL),
			NULL); 
		tempSize = "SECRETS - " + to_string(BGame.secrets.size()); SendMessage(hWndComboBox8, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = BGame.secrets.size()-1; i >= 0; i--) { SendMessage(hWndComboBox8, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[BGame.secrets[i]].name.c_str()); }

		HWND hWndComboBox9 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.bottom - 70, 150, 200, hBoard, (HMENU)IDC_GAME_OTRIGGERS, GetModuleHandle(NULL),
			NULL); 
		tempSize = "TRIGGERS - " + to_string(triggers.size()); SendMessage(hWndComboBox9, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = triggers.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox9, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[triggers[i]].targ].name.c_str()); }

		HWND hWndComboBox10 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.bottom - 100, 150, 200, hBoard, (HMENU)IDC_GAME_ODELAYED, GetModuleHandle(NULL),
			NULL); 
		tempSize = "DELAYED - " + to_string(turnpoints.size()); SendMessage(hWndComboBox10, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = turnpoints.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox10, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[turnpoints[i]].targ].name.c_str()); } //fix here, doesn't need to be AGame and BGame

		HWND hWndComboBox11 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 320, rcBoard.bottom - 130, 150, 200, hBoard, (HMENU)IDC_GAME_OAURAS, GetModuleHandle(NULL),
			NULL); 
		tempSize = "AURAS - " + to_string(auras.size()); SendMessage(hWndComboBox11, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = auras.size() - 1; i >= 0; i--) { SendMessage(hWndComboBox11, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[pMods[auras[i]].targ].name.c_str()); }

		HWND hWndComboBox12 = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
			rcBoard.right - 160, rcBoard.bottom - 70, 150, 200, hBoard, (HMENU)IDC_GAME_OGRAVE, GetModuleHandle(NULL),
			NULL); 
		tempSize = "GRAVE - " + to_string(BGame.grave.size()); SendMessage(hWndComboBox12, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tempSize.c_str());
		for (int i = BGame.grave.size()-1; i >= 0; i--) { SendMessage(hWndComboBox12, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)pCards[BGame.grave[i]].name.c_str()); }

		SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox2, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox3, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox4, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox5, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox6, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox7, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox8, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox9, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox10, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox11, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndComboBox12, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndpCards, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(hWndCards, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

		DrawText(hdc, (
			"Atk: " + to_string(pCards[AGame.hero].getAtk()) + "        Health: " + to_string(pCards[AGame.hero].getHpc()) + " / " + to_string(pCards[AGame.hero].getHpm()) + "        Armor: " + to_string(pCards[AGame.hero].getCost()) + "        Mana: " + to_string(AGame.cMana) + " / " + to_string(AGame.mMana) + "    Over: " + to_string(AGame.o1Mana) + " / " + to_string(AGame.o2Mana) + "    "
			).c_str(), -1, &rcBoard, DT_WORDBREAK | DT_RIGHT | DT_SINGLELINE);

		DrawText(hdc, (
			"Atk: " + to_string(pCards[BGame.hero].getAtk()) + "        Health: " + to_string(pCards[BGame.hero].getHpc()) + " / " + to_string(pCards[BGame.hero].getHpm()) + "        Armor: " + to_string(pCards[BGame.hero].getCost()) + "        Mana: " + to_string(BGame.cMana) + " / " + to_string(BGame.mMana) + "    Over: " + to_string(BGame.o1Mana) + " / " + to_string(BGame.o2Mana) + "    "
			).c_str(), -1, &rcBoard, DT_WORDBREAK | DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

		RECT handR[7], handFl[7];
		SetRect(&handR[0], rcBoard.left + 20, rcBoard.top + 20, rcBoard.left + 170, rcBoard.top + 150);
		for (int i = 0; i < 7; i++) {
			if (i != 0) { SetRect(&handR[i], handR[i - 1].right + 20, handR[0].top, handR[i - 1].right + 170, handR[0].bottom); }
			SetRect(&handFl[i], handR[i].left, handR[i].top + 40, handR[i].right, handR[i].bottom);
		}
		SelectObject(hdc, GetStockObject(DC_PEN));
		SelectObject(hdc, GetStockObject(DC_BRUSH));

		for (size_t i = 0; i < AGame.hand.size(); i++) {
			HWND hwndButton = CreateWindowEx(WS_EX_CLIENTEDGE, "Button", NULL,
				WS_VISIBLE | WS_CHILD,  // Styles
				handR[i].left + 75,         // x position 
				handR[i].top - 9,         // y position 
				10,        // Button width
				10,        // Button height
				hBoard,     // Parent window
				(HMENU)(IDC_GAME_PHAND + i),       // No menu.
				GetModuleHandle(NULL),
				NULL);      // Pointer not needed.
			SetDCPenColor(hdc, RGB(200, 200, 100));
			SetDCBrushColor(hdc, RGB(200, 200, 100));
			if (pCards[AGame.hand[i]].modsFx[DIVINESHIELD]) { Rectangle(hdc, handR[i].left - 10, handR[i].top - 10, handR[i].right + 10, handR[i].bottom + 10); }
			SetDCPenColor(hdc, RGB(30, 30, 255));
			SetDCBrushColor(hdc, RGB(30, 30, 255));
			if (pCards[AGame.hand[i]].modsFx[FROZEN]) { Rectangle(hdc, handR[i].left - 9, handR[i].top - 9, handR[i].right + 9, handR[i].bottom + 9); }
			SetDCPenColor(hdc, RGB(100, 255, 100));
			SetDCBrushColor(hdc, RGB(100, 255, 100));
			if (pCards[AGame.hand[i]].ready > 0) { Rectangle(hdc, handR[i].left - 8, handR[i].top - 8, handR[i].right + 8, handR[i].bottom + 8); }
			SetDCPenColor(hdc, RGB(0, 0, 0));
			SetDCBrushColor(hdc, RGB(100, 100, 100));
			if (pCards[AGame.hand[i]].modsFx[TAUNT]) { Rectangle(hdc, handR[i].left - 7, handR[i].top - 7, handR[i].right + 7, handR[i].bottom + 7); }
			SetDCPenColor(hdc, RGB(255, 100, 0));
			SetDCBrushColor(hdc, RGB(255, 200, 200));
			Rectangle(hdc, handR[i].left - 5, handR[i].top - 5, handR[i].right + 5, handR[i].bottom + 5);
			DrawText(hdc, pCards[AGame.hand[i]].name.c_str(), -1, &handR[i], DT_WORDBREAK);
			DrawText(hdc, pCards[AGame.hand[i]].flavour.c_str(), -1, &handFl[i], DT_WORDBREAK);
			DrawText(hdc, to_string(pCards[AGame.hand[i]].getCost()).c_str(), -1, &handR[i], DT_WORDBREAK | DT_RIGHT | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[AGame.hand[i]].getAtk()).c_str(), -1, &handR[i], DT_WORDBREAK | DT_LEFT | DT_BOTTOM | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[AGame.hand[i]].getHpc()).c_str(), -1, &handR[i], DT_WORDBREAK | DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);
		}

		RECT boardR[7], boardFl[7];
		SetRect(&boardR[0], handR[0].left, handR[0].bottom + 20, handR[0].right, handR[0].bottom + 150);
		for (int i = 0; i < 7; i++) {
			if (i != 0) { SetRect(&boardR[i], boardR[i - 1].right + 20, boardR[0].top, boardR[i - 1].right + 170, boardR[0].bottom); }
			SetRect(&boardFl[i], boardR[i].left, boardR[i].top + 40, boardR[i].right, boardR[i].bottom);
		}
		SetDCPenColor(hdc, RGB(255, 100, 0));
		SetDCBrushColor(hdc, RGB(255, 250, 250));
		for (size_t i = 0; i < AGame.board.size(); i++) {
			HWND hwndButton = CreateWindowEx(WS_EX_CLIENTEDGE, "Button", NULL,
				WS_VISIBLE | WS_CHILD,  // Styles
				boardR[i].left + 75,         // x position 
				boardR[i].top - 9,         // y position 
				10,        // Button width
				10,        // Button height
				hBoard,     // Parent window
				(HMENU)(IDC_GAME_PBOARD + i),       // No menu.
				GetModuleHandle(NULL),
				NULL);      // Pointer not needed.
			SetDCPenColor(hdc, RGB(200, 200, 100));
			SetDCBrushColor(hdc, RGB(200, 200, 100));
			if (pCards[AGame.board[i]].modsFx[DIVINESHIELD]) { Rectangle(hdc, boardR[i].left - 10, boardR[i].top - 10, boardR[i].right + 10, boardR[i].bottom + 10); }
			SetDCPenColor(hdc, RGB(30, 30, 255));
			SetDCBrushColor(hdc, RGB(30, 30, 255));
			if (pCards[AGame.board[i]].modsFx[FROZEN]) { Rectangle(hdc, boardR[i].left - 9, boardR[i].top - 9, boardR[i].right + 9, boardR[i].bottom + 9); }
			SetDCPenColor(hdc, RGB(100, 255, 100));
			SetDCBrushColor(hdc, RGB(100, 255, 100));
			if (pCards[AGame.board[i]].ready > 0) { Rectangle(hdc, boardR[i].left - 8, boardR[i].top - 8, boardR[i].right + 8, boardR[i].bottom + 8); }
			SetDCPenColor(hdc, RGB(0, 0, 0));
			SetDCBrushColor(hdc, RGB(100, 100, 100));
			if (pCards[AGame.board[i]].modsFx[TAUNT]) { Rectangle(hdc, boardR[i].left - 7, boardR[i].top - 7, boardR[i].right + 7, boardR[i].bottom + 7); }
			SetDCPenColor(hdc, RGB(50, 50, 50));
			SetDCBrushColor(hdc, RGB(50, 50, 50));
			if (pCards[AGame.board[i]].modsFx[WINDFURY]) { Rectangle(hdc, boardR[i].left - 6, boardR[i].top - 6, boardR[i].right + 6, boardR[i].bottom + 6); }
			SetDCPenColor(hdc, RGB(255, 100, 0));
			SetDCBrushColor(hdc, RGB(255, 250, 250));
			Rectangle(hdc, boardR[i].left - 5, boardR[i].top - 5, boardR[i].right + 5, boardR[i].bottom + 5);
			DrawText(hdc, pCards[AGame.board[i]].name.c_str(), -1, &boardR[i], DT_WORDBREAK);
			DrawText(hdc, pCards[AGame.board[i]].flavour.c_str(), -1, &boardFl[i], DT_WORDBREAK);
			DrawText(hdc, to_string(pCards[AGame.board[i]].getCost()).c_str(), -1, &boardR[i], DT_WORDBREAK | DT_RIGHT | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[AGame.board[i]].getAtk()).c_str(), -1, &boardR[i], DT_WORDBREAK | DT_LEFT | DT_BOTTOM | DT_SINGLELINE);
			string health = to_string(pCards[AGame.board[i]].getHpc()) + " / " + to_string(pCards[AGame.board[i]].getHpm());
			DrawText(hdc, health.c_str(), -1, &boardR[i], DT_WORDBREAK | DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);
		}

		///////////////////////////////////////////

		RECT OhandR[7], OhandFl[7];
		SetRect(&OhandR[0], rcBoard.left + 20, rcBoard.bottom - 150, rcBoard.left + 170, rcBoard.bottom - 20);
		for (int i = 0; i < 7; i++) {
			if (i != 0) { SetRect(&OhandR[i], OhandR[i - 1].right + 20, OhandR[0].top, OhandR[i - 1].right + 170, OhandR[0].bottom); }
			SetRect(&OhandFl[i], OhandR[i].left, OhandR[i].top + 40, OhandR[i].right, OhandR[i].bottom);
		}
		for (size_t i = 0; i < BGame.hand.size(); i++) {
			HWND hwndButton = CreateWindowEx(WS_EX_CLIENTEDGE, "Button", NULL,
				WS_VISIBLE | WS_CHILD,  // Styles
				OhandR[i].left + 75,         // x position 
				OhandR[i].top - 9,         // y position 
				10,        // Button width
				10,        // Button height
				hBoard,     // Parent window
				(HMENU)(IDC_GAME_OHAND + i),       // No menu.
				GetModuleHandle(NULL),
				NULL);      // Pointer not needed.
			SetDCPenColor(hdc, RGB(200, 200, 100));
			SetDCBrushColor(hdc, RGB(200, 200, 100));
			if (pCards[BGame.hand[i]].modsFx[DIVINESHIELD]) { Rectangle(hdc, OhandR[i].left - 10, OhandR[i].top - 10, OhandR[i].right + 10, OhandR[i].bottom + 10); }
			SetDCPenColor(hdc, RGB(30, 30, 255));
			SetDCBrushColor(hdc, RGB(30, 30, 255));
			if (pCards[BGame.hand[i]].modsFx[FROZEN]) { Rectangle(hdc, OhandR[i].left - 9, OhandR[i].top - 9, OhandR[i].right + 9, OhandR[i].bottom + 9); }
			SetDCPenColor(hdc, RGB(100, 255, 100));
			SetDCBrushColor(hdc, RGB(100, 255, 100));
			if (pCards[BGame.hand[i]].ready > 0) { Rectangle(hdc, OhandR[i].left - 8, OhandR[i].top - 8, OhandR[i].right + 8, OhandR[i].bottom + 8); }
			SetDCPenColor(hdc, RGB(0, 0, 0));
			SetDCBrushColor(hdc, RGB(100, 100, 100));
			if (pCards[BGame.hand[i]].modsFx[TAUNT]) { Rectangle(hdc, OhandR[i].left - 7, OhandR[i].top - 7, OhandR[i].right + 7, OhandR[i].bottom + 7); }
			SetDCPenColor(hdc, RGB(0, 100, 255));
			SetDCBrushColor(hdc, RGB(200, 200, 255));
			Rectangle(hdc, OhandR[i].left - 5, OhandR[i].top - 5, OhandR[i].right + 5, OhandR[i].bottom + 5);
			DrawText(hdc, pCards[BGame.hand[i]].name.c_str(), -1, &OhandR[i], DT_WORDBREAK);
			DrawText(hdc, pCards[BGame.hand[i]].flavour.c_str(), -1, &OhandFl[i], DT_WORDBREAK);
			DrawText(hdc, to_string(pCards[BGame.hand[i]].getCost()).c_str(), -1, &OhandR[i], DT_WORDBREAK | DT_RIGHT | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[BGame.hand[i]].getAtk()).c_str(), -1, &OhandR[i], DT_WORDBREAK | DT_LEFT | DT_BOTTOM | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[BGame.hand[i]].getHpc()).c_str(), -1, &OhandR[i], DT_WORDBREAK | DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);
		}

		RECT OboardR[7], OboardFl[7];
		SetRect(&OboardR[0], OhandR[0].left, OhandR[0].top - 150, OhandR[0].right, OhandR[0].top - 20);
		for (int i = 0; i < 7; i++) {
			if (i != 0) { SetRect(&OboardR[i], OboardR[i - 1].right + 20, OboardR[0].top, OboardR[i - 1].right + 170, OboardR[0].bottom); }
			SetRect(&OboardFl[i], OboardR[i].left, OboardR[i].top + 40, OboardR[i].right, OboardR[i].bottom);
		}
		for (size_t i = 0; i < BGame.board.size(); i++) {
			HWND hwndButton = CreateWindowEx(WS_EX_CLIENTEDGE, "Button", NULL,
				WS_VISIBLE | WS_CHILD,  // Styles
				OboardR[i].left + 75,         // x position 
				OboardR[i].top - 9,         // y position 
				10,        // Button width
				10,        // Button height
				hBoard,
				(HMENU)(IDC_GAME_OBOARD + i),       // No menu.
				GetModuleHandle(NULL),
				NULL);      // Pointer not needed.
			SetDCPenColor(hdc, RGB(200, 200, 100));
			SetDCBrushColor(hdc, RGB(200, 200, 100));
			if (pCards[BGame.board[i]].modsFx[DIVINESHIELD]) { Rectangle(hdc, OboardR[i].left - 10, OboardR[i].top - 10, OboardR[i].right + 10, OboardR[i].bottom + 10); }
			SetDCPenColor(hdc, RGB(30, 30, 255));
			SetDCBrushColor(hdc, RGB(30, 30, 255));
			if (pCards[BGame.board[i]].modsFx[FROZEN]) { Rectangle(hdc, OboardR[i].left - 9, OboardR[i].top - 9, OboardR[i].right + 9, OboardR[i].bottom + 9); }
			SetDCPenColor(hdc, RGB(100, 255, 100));
			SetDCBrushColor(hdc, RGB(100, 255, 100));
			if (pCards[BGame.board[i]].ready > 0) { Rectangle(hdc, OboardR[i].left - 8, OboardR[i].top - 8, OboardR[i].right + 8, OboardR[i].bottom + 8); }
			SetDCPenColor(hdc, RGB(0, 0, 0));
			SetDCBrushColor(hdc, RGB(100, 100, 100));
			if (pCards[BGame.board[i]].modsFx[TAUNT]) { Rectangle(hdc, OboardR[i].left - 7, OboardR[i].top - 7, OboardR[i].right + 7, OboardR[i].bottom + 7); }
			SetDCPenColor(hdc, RGB(50, 50, 50));
			SetDCBrushColor(hdc, RGB(50, 50, 50));
			if (pCards[BGame.board[i]].modsFx[WINDFURY]) { Rectangle(hdc, OboardR[i].left - 6, OboardR[i].top - 6, OboardR[i].right + 6, OboardR[i].bottom + 6); }
			SetDCPenColor(hdc, RGB(0, 100, 255));
			SetDCBrushColor(hdc, RGB(250, 250, 255));
			Rectangle(hdc, OboardR[i].left - 5, OboardR[i].top - 5, OboardR[i].right + 5, OboardR[i].bottom + 5);
			DrawText(hdc, pCards[BGame.board[i]].name.c_str(), -1, &OboardR[i], DT_WORDBREAK);
			DrawText(hdc, pCards[BGame.board[i]].flavour.c_str(), -1, &OboardFl[i], DT_WORDBREAK);
			DrawText(hdc, to_string(pCards[BGame.board[i]].getCost()).c_str(), -1, &OboardR[i], DT_WORDBREAK | DT_RIGHT | DT_SINGLELINE);
			DrawText(hdc, to_string(pCards[BGame.board[i]].getAtk()).c_str(), -1, &OboardR[i], DT_WORDBREAK | DT_LEFT | DT_BOTTOM | DT_SINGLELINE);
			string health = to_string(pCards[BGame.board[i]].getHpc()) + " / " + to_string(pCards[BGame.board[i]].getHpm());
			DrawText(hdc, health.c_str(), -1, &OboardR[i], DT_WORDBREAK | DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);
		}

		char szSize[100];
		char szTitle[] = "SALT OF THE HEARTH";
		DrawText(hdc, szTitle, -1, &rcBoard, DT_WORDBREAK);
		wsprintf(szSize, "PLAYER %d's TURN                ", Player->side);
		DrawText(hdc, szSize, -1, &rcBoard, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

		SelectObject(hdc, hfOld);

		EndPaint(hBoard, &ps);
	}
	case WM_COMMAND:
		if (LOWORD(wParam)>199 && LOWORD(wParam)<240) {
			HWND hDlg;
			hDlg = CreateDialogParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogProc, wParam);
			ShowWindow(hDlg, SW_SHOW);
		}
		if (LOWORD(wParam) > 239) {			
			if (HIWORD(wParam) == CBN_SELENDOK) {
				int mes = SendDlgItemMessage(hBoard, LOWORD(wParam), CB_GETCURSEL, NULL, NULL);
				if (mes == 0) { break; }
				else { mes = SendDlgItemMessage(hBoard, LOWORD(wParam), CB_GETCOUNT, NULL, NULL) - mes - 1; }
				mes += LOWORD(wParam);
				HWND hDlg;
				hDlg = CreateDialogParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogProc, mes);
				ShowWindow(hDlg, SW_SHOW);
			}
		}
	default:
		return DefWindowProc(hBoard, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
		case WM_CREATE:
		{
			g_hfFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

			HWND hBoard;

			HWND hHistory;

			HWND hTool;
			TBBUTTON tbb[4];
			TBADDBITMAP tbab;

			HWND hStatus;
			int statwidths[] = {50, 250, 650, 750, 800, 900, -1};

			// Create Board section
			
			hBoard = CreateWindowEx(WS_EX_CLIENTEDGE, g_boardClassName, NULL,
				WS_CHILD | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				hwnd, (HMENU)IDC_MAIN_BOARD, GetModuleHandle(NULL), NULL);
			if(hBoard == NULL)
				MessageBox(hwnd, "Could not create board box.", "Error", MB_OK | MB_ICONERROR);

			// Create card history section

			hHistory = CreateWindowEx(WS_EX_CLIENTEDGE, "Listbox", NULL,
				WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | LBS_NOTIFY,
				CW_USEDEFAULT, CW_USEDEFAULT, 100, CW_USEDEFAULT,
				hwnd, (HMENU)IDC_MAIN_HISTORY, GetModuleHandle(NULL), NULL);
			if (hHistory == NULL)
				MessageBox(hwnd, "Could not create history box.", "Error", MB_OK | MB_ICONERROR);

			// Create Toolbar

			hTool = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, 
				WS_CHILD | WS_VISIBLE,
				0, 0, 0, 0,
				hwnd, (HMENU)IDC_MAIN_TOOL, GetModuleHandle(NULL), NULL);
			if(hTool == NULL)
				MessageBox(hwnd, "Could not create tool bar.", "Error", MB_OK | MB_ICONERROR);

			// Send the TB_BUTTONSTRUCTSIZE message, which is required for
			// backward compatibility.
			SendMessage(hTool, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
			
			tbab.hInst = HINST_COMMCTRL;
			tbab.nID = IDB_STD_SMALL_COLOR;
			SendMessage(hTool, TB_ADDBITMAP, 0, (LPARAM)&tbab);

			ZeroMemory(tbb, sizeof(tbb));
			tbb[0].iBitmap = STD_FILENEW;
			tbb[0].fsState = TBSTATE_ENABLED;
			tbb[0].fsStyle = TBSTYLE_BUTTON;
			tbb[0].idCommand = ID_FILE_NEW;

			tbb[1].iBitmap = STD_FILEOPEN;
			tbb[1].fsState = TBSTATE_ENABLED;
			tbb[1].fsStyle = TBSTYLE_BUTTON;
			tbb[1].idCommand = ID_FILE_OPEN;

			tbb[2].iBitmap = STD_FILESAVE;
			tbb[2].fsState = TBSTATE_ENABLED;
			tbb[2].fsStyle = TBSTYLE_BUTTON;
			tbb[2].idCommand = ID_FILE_SAVEAS;

			tbb[3].iBitmap = STD_REDOW;
			tbb[3].fsState = TBSTATE_ENABLED;
			tbb[3].fsStyle = TBSTYLE_BUTTON;
			tbb[3].idCommand = ID_NEXTTURN;

			SendMessage(hTool, TB_ADDBUTTONS, sizeof(tbb)/sizeof(TBBUTTON), (LPARAM)&tbb);

			// Create Status bar

			hStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL,
				WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 
				0, 0, 0, 0,
				hwnd, (HMENU)IDC_MAIN_STATUS, GetModuleHandle(NULL), NULL);

			SendMessage(hStatus, SB_SETPARTS, sizeof(statwidths)/sizeof(int), (LPARAM)statwidths);
			SendMessage(hStatus, SB_SETTEXT, 0, (LPARAM)"Hi there :)");
			SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)"Howdy ho!");
		}
		break;
		case WM_SIZE:
		{
			HWND hTool;
			RECT rcTool;
			int iToolHeight;

			HWND hStatus;
			RECT rcStatus;
			int iStatusHeight;
			
			HWND hBoard;

			HWND hHistory;
			RECT rcHistory;

			int iBoardHeight;
			RECT rcClient;

			// Size toolbar and get height

			hTool = GetDlgItem(hwnd, IDC_MAIN_TOOL);
			SendMessage(hTool, TB_AUTOSIZE, 0, 0);

			GetWindowRect(hTool, &rcTool);
			iToolHeight = rcTool.bottom - rcTool.top;

			// Size status bar and get height

			hStatus = GetDlgItem(hwnd, IDC_MAIN_STATUS);
			SendMessage(hStatus, WM_SIZE, 0, 0);
			//SendMessage(hStatus, SB_SETTEXT, 1, (LPARAM)"size me up!");

			GetWindowRect(hStatus, &rcStatus);
			iStatusHeight = rcStatus.bottom - rcStatus.top;

			// Calculate remaining height and size edit

			GetClientRect(hwnd, &rcClient);

			iBoardHeight = rcClient.bottom - iStatusHeight - iToolHeight;

			hHistory = GetDlgItem(hwnd, IDC_MAIN_HISTORY);
			GetWindowRect(hHistory, &rcHistory);
			int iHistoryWidth = rcHistory.right - rcHistory.left;
			SetWindowPos(hHistory, NULL, 0, iToolHeight, iHistoryWidth, iBoardHeight, SWP_NOOWNERZORDER);

			hBoard = GetDlgItem(hwnd, IDC_MAIN_BOARD);
			SetWindowPos(hBoard, NULL, iHistoryWidth, iToolHeight, rcClient.right - iHistoryWidth, iBoardHeight, SWP_NOOWNERZORDER);
		}
		break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDC_MAIN_HISTORY:
				switch (HIWORD(wParam))
				{
				case LBN_SELCHANGE:
				{
					int histnum = SendDlgItemMessage(hwnd, IDC_MAIN_HISTORY, LB_GETCURSEL, 0, 0);
					char buffer[16] = "";
					sprintf_s(buffer, "%ld", histnum);
					if (histnum != -1) {
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 0, (LPARAM)("Side: "+static_cast<ostringstream*>(&(ostringstream() << historyData[histnum].side1))->str()).c_str());
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 1, (LPARAM)("Name: "+historyData[histnum].name).c_str());
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 2, (LPARAM)("Flav: "+historyData[histnum].flavour).c_str());
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 3, (LPARAM)("From: "+static_cast<ostringstream*>(&(ostringstream() << historyData[histnum].from1))->str()).c_str());
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 4, (LPARAM)(static_cast<ostringstream*>(&(ostringstream() << historyData[histnum].from2))->str()).c_str());
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 5, (LPARAM)("Target(s): "+static_cast<ostringstream*>(&(ostringstream() << historyData[histnum].to1))->str()).c_str());
						stringstream targets; copy(historyData[histnum].to2.begin(), historyData[histnum].to2.end(), ostream_iterator<int>(targets, " "));
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 6, (LPARAM)(""+targets.str()).c_str());
					}
					else {
						SendDlgItemMessage(hwnd, IDC_MAIN_STATUS, SB_SETTEXT, 1, (LPARAM)("it got -1"));
					}
					InvalidateRect(hwnd, NULL, FALSE);
					UpdateWindow(hwnd);
					break;
				}
				}
				break;
			case ID_NEXTTURN:
			{
				SetWindowText(globHwnd, ("HEARTHSTONE BLEARTHSTONE - Turn " + to_string(turnNum)).c_str() );
				game();
				for (size_t i = SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_GETCOUNT, NULL, NULL); i < historyData.size(); i++) {
					int pos = SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_ADDSTRING, 0, (LPARAM)historyData[i].name.c_str());
					SendMessage(GetDlgItem(hwnd, IDC_MAIN_HISTORY), LB_SETITEMDATA, pos, (LPARAM)playNum);
				}
				SendDlgItemMessage(hwnd, IDC_MAIN_HISTORY, LB_SETCURSEL, historyData.size()-1, 0);
				InvalidateRect(NULL, NULL, FALSE);
				break;
			}
			case ID_FILE_SAVEAS:
				DoFileSave(hwnd);
				break;
			case ID_FILE_OPEN:
				DoFileOpen(hwnd);
				break;
			case ID_FILE_EXIT:
				PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
			}
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
			case VK_F5:
				fullGame();
				break;
			}
			break;
		case WM_INITMENUPOPUP:
			CheckMenuItem((HMENU)wParam, ID_FORMAT_OPAQUE, MF_BYCOMMAND | (g_bOpaque ? MF_CHECKED : MF_UNCHECKED));
			break;
		case WM_DESTROY:
			DeleteObject(g_hfFont);

			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));
	initializeCards();
	createTestGamespace();
	moveSorted.open("moveSorted.txt");
	winSorted.open("winSorted.txt");

	currNode.seedA = AGame;
	currNode.seedB = BGame;
	currNode.s_historyData = historyData;
	currNode.s_pCards = pCards; //cards imported for game from Cards //can be modified //nothing is ever removed
	currNode.s_pMods = pMods; //all current effects on cards in game //nothing is ever removed
	currNode.s_unusedMod = unusedMod;
	currNode.s_triggers = triggers; //triggerable effects to be checked during play //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
	currNode.s_turnpoints = turnpoints; //effects to be checked between plays
	currNode.s_auras = auras;
	currNode.s_currPlay;
	currNode.s_globID;
	currNode.s_playNum;
	currNode.s_turnNum;
	
	movefile.open("movefile.txt");

	WNDCLASSEX wc;
	MSG Msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	wc.lpfnWndProc = ChildWndProc;
	wc.cbWndExtra = sizeof(long);
	wc.hIcon = NULL;
	wc.lpszClassName = g_boardClassName;

	RegisterClassEx(&wc);

	globHwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"HEARTHSTONE BLEARTHSTONE",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 1800, 900,
		NULL, NULL, hInstance, NULL);

	if (globHwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(globHwnd, nCmdShow);
	UpdateWindow(globHwnd);



    	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	movefile.close();
	moveSorted.close();
	winSorted.close();
	return Msg.wParam;
}

void fullGame() {
	omp_get_num_threads();
	omp_get_thread_num();
	omp_get_max_threads();
	omp_set_num_threads(2);
	vector<int> test;
	#pragma omp parallel for
	for (int q = 0; q < 100; q++) {
		#pragma omp critical
		test.push_back(q);
		#pragma omp critical
		test.push_back(omp_get_thread_num());
	}
	for (int z = 0; z < 100; z++) {
		for (int j = 0; j < 100; j++) {


#pragma omp parallel shared(moves) firstprivate(currNode, Player, currPlay, globID, moveSet, skipSet, wrSet, cMove, thread, moveSort, skip, kin, playNum, turnNum, placeActivity, changeFlags, pCards, AGame, BGame, historyData, pMods, unusedMod, triggers, turnpoints, auras) 
			{

				AGame = currNode.seedA;
				BGame = currNode.seedB;
				historyData = currNode.s_historyData;
				pCards = currNode.s_pCards;
				pMods = currNode.s_pMods;
				unusedMod = currNode.s_unusedMod;
				triggers = currNode.s_triggers;
				turnpoints = currNode.s_turnpoints;
				auras = currNode.s_auras;
				currPlay = currNode.s_currPlay;
				globID = currNode.s_globID;
				playNum = currNode.s_playNum;
				turnNum = currNode.s_turnNum;

				AGame.Ogame = &BGame; BGame.Ogame = &AGame;
				Player = new GameSpace;
				Player = &AGame;

				cMove = 0;
				omp_get_num_threads();
				thread = omp_get_thread_num();
				omp_get_max_threads();

				while (true) {
					//SetWindowText(globHwnd, ("HEARTHSTONE BLEARTHSTONE - Turn " + to_string(turnNum)).c_str());
					int res = game();
					if (res == 1) {
						cout << "error";
					}
					if (res > 0) { currNode.currMoves.push_back(res); break; }
					//for (size_t i = SendMessage(GetDlgItem(globHwnd, IDC_MAIN_HISTORY), LB_GETCOUNT, NULL, NULL); i < historyData.size(); i++) {
					//	int pos = SendMessage(GetDlgItem(globHwnd, IDC_MAIN_HISTORY), LB_ADDSTRING, 0, (LPARAM)historyData[i].name.c_str());
					//	SendMessage(GetDlgItem(globHwnd, IDC_MAIN_HISTORY), LB_SETITEMDATA, pos, (LPARAM)playNum);
					//}
					//SendDlgItemMessage(globHwnd, IDC_MAIN_HISTORY, LB_SETCURSEL, historyData.size() - 1, 0);
					//InvalidateRect(NULL, NULL, FALSE);
				}

#pragma omp critical(o)
				{
					moves.push_back(currNode.currMoves);
				}
				//for (auto i : currNode.currMoves) {
				//	movefile << i << '.';
				//}
				//movefile << endl;
			}
				currNode.currMoves.clear();
			/*currNode.nodeA = AGame;
			currNode.nodeB = BGame;
			currNode.n_historyData = historyData;
			currNode.n_pCards = pCards; //cards imported for game from Cards //can be modified //nothing is ever removed
			currNode.n_pMods = pMods; //all current effects on cards in game //nothing is ever removed
			currNode.n_unusedMod = unusedMod;
			currNode.n_triggers = triggers; //triggerable effects to be checked during play //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
			currNode.n_turnpoints = turnpoints; //effects to be checked between plays
			currNode.n_auras = auras;
			currNode.n_currPlay = currPlay;
			currNode.n_globID = globID;
			currNode.n_playNum = playNum;
			currNode.n_turnNum = turnNum;
			nodes.push_back(currNode);
			currNode = TimeTravel();*/

			//SendMessage(GetDlgItem(globHwnd, IDC_MAIN_HISTORY), LB_RESETCONTENT, 0, 0);
			//InvalidateRect(NULL, NULL, FALSE);
			//UpdateWindow(globHwnd);
		}

		for (int i = moves.size() - 1; i < moves.size(); i++) {
			int place = 0; bool go = false; int digit = 0;
			for (int j = 0; j < moveSort.size(); j++) {
				digit = 0;
				while (true) {
					if (moves[i][digit] < moveSort[j][digit]) { go = true; break; }
					else if (moves[i][digit] == moveSort[j][digit]) {
						digit++;
					}
					else {
						break;
					}
				}
				if (go) {
					break;
				}
				place++;
			}
			kin.insert(kin.begin() + place, vector<bool>());
			moveSort.insert(moveSort.begin() + place, moves[i]);
			skip.insert(skip.begin() + place, 0);
			int o = 0;
			while (true && place > 0) {
				if (moveSort[place][o] == moveSort[place - 1][o]) { o++; skip[place]++; }
				else { break; }
			}
			if (place < moveSort.size() - 1) {
				kin[place + 1].clear();
				skip[place + 1] = digit;
				bool son = true, dad = true; int l = 1;
				while (true) {
					if (dad && skip[place + l] > skip[place]) { kin[place].push_back(moveSort[place + l].back() - 1); } //todo seperate first and second rekin
					else { dad = false; }
					if (l + place + 1 >= moveSort.size()) { break; }
					if (son && skip[place + l + 1] > skip[place + 1]) { kin[place + 1].push_back(moveSort[place + l + 1].back() - 1); }
					else { son = false; }
					if (!dad && !son) { break; }
					l++;
				}
			}
			int m = 1, n = skip[place];
			while (true) {
				if (place - m < 0 || n < 0) { break; }
				if (skip[place - m] < n) { n = skip[place - m]; kin[place - m].push_back(moveSort[place].back() - 1); }
				m++;
			}
		}

		for (int i = 0; i < moveSort.size(); i++) {
			int wins = 0;
			for (auto j : kin[i]) { if (!j) { wins++; } }
			if (kin[i].size() > 0) {
				double wr = (double)(-1 * moveSort[i].back() + 2 + wins) / (1 + kin[i].size());
				if (wr > wrSet) {
					moveSet = i; wrSet = wr; skipSet = skip[i];
				}
			}
		}
		wrSet = 0;
	}
	for (int i = 0; i < moves.size(); i++) {
		movefile << "   ";
		for (int j = 0; j < moves[i].size(); j++) {
			if (moves[i][j] < 10) { movefile << " " << moves[i][j] << "."; }
			else { movefile << moves[i][j] << "."; }
		}
		movefile << endl;
	}

	for (int i = 0; i < moveSort.size(); i++) {
		winSorted << "   ";
		for (int j = 0; j < moveSort[i].size(); j++) {
			if (moveSort[i][j] < 10) { winSorted << " " << moveSort[i][j] << "."; }
			else { winSorted << moveSort[i][j] << "."; }
		}
		winSorted << endl;
	}

	for (int i = 0; i < moveSort.size(); i++) {
		for (int j = 0; j < skip[i]; j++) {
			moveSorted << "   ";
		}
		int wins = 0;
		for (auto j : kin[i]) { if (!j) { wins++; } }
		if (kin[i].size() > 0) {
			double wr = (double)(-1 * moveSort[i].back() + 2 + wins) / (1 + kin[i].size());
			if (wr > wrSet) {
				moveSet = i; wrSet = wr; skipSet = skip[i];
			}
			if (kin[i].size() < 10) { moveSorted << " "; }
			moveSorted << kin[i].size() << "   " << setprecision(2) << fixed << wr << "   ";
		}
		else { moveSorted << "            "; }
		moveSorted << -1 * moveSort[i].back() + 2 << "   ";
		for (int j = skip[i]; j < moveSort[i].size(); j++) {
			if (moveSort[i][j] < 10) { moveSorted << " " << moveSort[i][j] << "."; }
			else { moveSorted << moveSort[i][j] << "."; }
		}
		moveSorted << endl;
	}
}

void importCard(Card temp) {
	for (int i = 0; i < FXCOUNT; i++) {
		for (int j = 0; j < temp.cMods[i].size(); j++) {
			pMods.push_back(Mods[temp.cMods[i][j]]);
			pMods.back().targ = pCards.size();
			temp.cMods[i][j] = pMods.size() - 1;
		}
	}
	pCards.push_back(temp);
	flattenMod(pCards.size() - 1);
}

//greg egan
void createTestGamespace() {
	AGame.Ogame = &BGame;
	BGame.Ogame = &AGame;
	importCard(Cards[2]); //mage
	pCards.back().side = 1;
	pCards.back().place = BOARD;
	importCard(Cards[2]);
	pCards.back().side = 2;
	pCards.back().place = BOARD;
	importCard(Cards[11]); //unarmed
	pCards.back().side = 1;
	pCards.back().place = BOARD;
	importCard(Cards[11]);
	pCards.back().side = 2;
	pCards.back().place = BOARD;
	importCard(Cards[14]); //fireblast
	pCards.back().side = 1;
	pCards.back().place = BOARD;
	importCard(Cards[14]);
	pCards.back().side = 2;
	pCards.back().place = BOARD;
	AGame.hero = Ahero;
	BGame.hero = Bhero;
	AGame.weapon = Awep;
	BGame.weapon = Bwep;
	AGame.hPwr = Ahpwr;
	BGame.hPwr = Bhpwr;
	AGame.side = 1;
	BGame.side = 2;
	initDecks();
	int first = rand() % 2; //coin flip
	//currNode.currMoves.push_back(first);
	cout << "Player " << first + 1 << " goes first." << endl;
	bool playing = true;
	if (first == 0) { Player = &AGame; }
	else { Player = &BGame; }

	//todo add mulligans //choice made here
	size_t mull[4];
	bool mullCho[4] = { true, true, true, true };
	int choice, num = 0;
	int flag = 0;

	while (flag < 2) {
		for (size_t i = 0; i < sizeof(mullCho) - 1 + flag; i++) {
			mull[i] = Player->deck.back();
			Player->deck.pop_back();
		}
		choice = rand() % (sizeof(mullCho) + flag);
		//currNode.currMoves.push_back(choice);
		while (choice < sizeof(mullCho) - 1 + flag) {
			mullCho[choice] = false;
			choice = rand() % (sizeof(mullCho) + flag);
			//currNode.currMoves.push_back(choice);
		}
		for (size_t i = 0; i < sizeof(mullCho) - 1 + flag; i++) {
			if (mullCho[i]) {
				Player->hand.push_back(mull[i]);
				pCards[Player->hand.back()].place = HAND;
				pCards[Player->hand.back()].placement = Player->hand.size()-1;

			}
			else {
				choice = rand() % (Player->deck.size() + 1);
				//currNode.currMoves.push_back(choice);
				if (choice == Player->deck.size()) { Player->deck.push_back(mull[i]); }
				else { Player->deck.insert(Player->deck.begin() + choice, mull[i]); }
				num++;
			}
		}
		draw(num, Player);
		Player = Player->Ogame;
		for (size_t i = 0; i < sizeof(mullCho); i++) { mullCho[i] = true; }
		num = 0;
		flag++;
	}

	for (size_t k = 0; k < Cards.size(); k++) {
		if (Cards[k].name == "The_Coin") {
			importCard(Cards[k]);
			Player->hand.push_back(pCards.size() - 1);
			pCards[Player->hand.back()].side = Player->side;
			pCards[Player->hand.back()].place = HAND;
			pCards[Player->hand.back()].placement = Player->hand.size()-1;
			break;
		}
	}
}

void initDecks() {
	int size = Cards.size();

	vector<int> chosen(size, 0);
	int i = 0;
	cout << "B Deck List:" << endl;
	while (i < DECKSIZE) { //generates decklist, with no more than 2 of any card
		//TODO check for card that adds 5 legendaries, apply reno flag if no duplicates of any card--still works if no duplicated LEFT in deck, check if any cards have triggers while in deck for when drawn
		int choice = rand() % size;
		//currNode.currMoves.push_back(choice);
		Card test = Cards[choice];
		if ((test.cRole == pCards[BGame.hero].cRole || test.cRole == ROLE) && test.collect && chosen[choice] < 2) {
			cout << "\t\t" << test.name << endl;
			importCard(test);
			if (test.cRace == CTHUN) { BGame.cthun = pCards.size() - 1; }
			pCards.back().place = DECK;
			pCards.back().side = 2;
			BGame.deck.push_back(pCards.size() - 1);
			chosen[choice]++;
			i++;
		}
	}

	cout << endl << endl;

	fill(chosen.begin(), chosen.end(), 0);
	int j = 0;
	cout << "A Deck List:" << endl;
	while (j < DECKSIZE) {
		int choice = rand() % size;
		//currNode.currMoves.push_back(choice);
		Card test = Cards[choice];
		if ((test.cRole == pCards[AGame.hero].cRole || test.cRole == ROLE) && test.collect && chosen[choice] < 2) {
			cout << "\t\t" << test.name << endl;
			importCard(test);
			if (test.cRace == CTHUN) { AGame.cthun = pCards.size() - 1; }
			pCards.back().place = DECK;
			pCards.back().side = 1;
			AGame.deck.push_back(pCards.size() - 1);
			chosen[choice]++;
			j++;
		}
	}
}

int game() {
	turnNum++;
	bool turn = true;
	draw(1, Player);
	int res = turnTr(0);
	if (res == 1) { return 1; }; //end of turn conditions
	if (res == 2) { return 2; }; //end of turn conditions
	while (turn) {
		vector<size_t> plays;
		vector<int> placement;
		for (size_t i = 0; i < Player->board.size(); i++) {
			if (pCards[Player->board[i]].ready != 0 && pCards[Player->board[i]].getAtk() > 0 && !pCards[Player->board[i]].modsFx[20]) { //add minions on board optn
				plays.push_back(Player->board[i]);
				placement.push_back(i);
			}
		}
		if (pCards[Player->weapon].getAtk() + pCards[Player->hero].getAtk() > 0 && pCards[Player->hero].ready>0) { plays.push_back(Player->hero); placement.push_back(-1); } //add hero optn
		if (Player->cMana >= Player->pwrCost && (Player->pReady > 0 || Player->HeroFury )) { plays.push_back(Player->hPwr); placement.push_back(-2); } //add hpwr
		for (size_t i = 0; i < Player->hand.size(); i++) {
			if (pCards[Player->hand[i]].getCost() <= Player->cMana) { //add cards in hand you can afford to play
				plays.push_back(Player->hand[i]);
				placement.push_back(i);
			}
		}
		while (true) {
			int eotchance = rand() % (plays.size() * 3 + 1);
			if (moveSet != -1 && cMove < skipSet) { eotchance = moveSort[moveSet][cMove++]; }
			currNode.currMoves.push_back(eotchance);
			if (eotchance == 0) {
				eotchance = turnTr(2);
				if (eotchance == 1) { return 1; }; //end of turn conditions
				if (eotchance == 2) { return 2; }; //end of turn conditions
				turn = false;	//END TURN //todo check if immediately goes out of turn loop or finishes before leaving
				break;
			}
			int pla = rand() % plays.size(); //todo is it possible for no value of pla to work
			if (moveSet != -1 && cMove < skipSet) { pla = moveSort[moveSet][cMove++]; }
			currNode.currMoves.push_back(pla);
			playData hPlay; hPlay.name = pCards[plays[pla]].name; hPlay.flavour = pCards[plays[pla]].flavour; hPlay.side1 = pCards[plays[pla]].side; hPlay.from1 = Places[pCards[plays[pla]].place]; hPlay.from2 = placement[pla]; //fill historydata with card about to play
			historyData.push_back(hPlay);
			if (play(plays[pla])) {
				break;
			}
			else {
				cout << "err" << endl;
			}
		}
		if (turn) {
			res = turnTr(1);
			if (res == 1) { return 1; }; //end of turn conditions
			if (res == 2) { return 2; }; //end of turn conditions }//end of play conditions
		}
	}
	Player = Player->Ogame;
	return 0;
}

void flattenMod(size_t Card) { //flattens all values in cMods into the mods and modsfx arrays.
	pCards[Card].mods[0] = 0; pCards[Card].mods[1] = 0; pCards[Card].mods[2] = 0;
	for (size_t i = 0; i < FXCOUNT; i++) { pCards[Card].modsFx[i] = false; }
	for (int i = 0; i < FXCOUNT; i++) {
		for (auto j : pCards[Card].cMods[i]) {
			pCards[Card].mods[0] += pMods[j].mods[0];
			pCards[Card].mods[1] += pMods[j].mods[1];
			pCards[Card].mods[2] += pMods[j].mods[2];
			pCards[Card].modsFx[ i ] = true;
		}
	}
}

void removeAura(size_t Effect) { //removes all effects from cards given as an aura from a dying card
	for (auto i : pMods[Effect].slaves) {
		if (pMods[i].master == Effect) { //should always be true
			size_t k = pMods[i].targ;
			for (int l = pCards[k].cMods[MOD].size() - 1; l >= 0; l--) {
				if (pCards[k].cMods[MOD][l] == i) { pCards[k].cMods[MOD].erase(pCards[k].cMods[MOD].begin() + l); }
			}
			unusedMod.push_back(i);
		}
		else {
			cout << "error" << endl;
		}
	}
	pMods[Effect].slaves.clear();
}

bool evalDomain(Effect activatedEffect, int targs, int targetCard) { //finds out if targetCard is indeed in target domain of activatedEffect
	if (activatedEffect.target[targs] == "SELF") { if (targetCard == activatedEffect.targ) { return true; } else { return false; } }
	if (targetCard < 0 && activatedEffect.cTarTy[targs][TYPE]) {
		if (activatedEffect.cTarAr[targs][AREA]) { return true; }
		if (targetCard == -1) { if ((pCards[activatedEffect.targ].side == 1 && activatedEffect.cTarAr[targs][PBOARD]) || (pCards[activatedEffect.targ].side == 2 && activatedEffect.cTarAr[targs][OBOARD])) { return true; } }
		else if (targetCard == -2) { if ((pCards[activatedEffect.targ].side == 2 && activatedEffect.cTarAr[targs][PBOARD]) || (pCards[activatedEffect.targ].side == 1 && activatedEffect.cTarAr[targs][OBOARD])) { return true; } }
	}
	else if(targetCard > -1) {
		if (pCards[activatedEffect.targ].side == pCards[targetCard].side) {
			if ((activatedEffect.cTarTy[targs][TYPE] || activatedEffect.cTarTy[targs][pCards[targetCard].cRace] || activatedEffect.cTarTy[targs][pCards[targetCard].cType] ) && ( activatedEffect.cTarAr[targs][(pCards[targetCard].place * 2) + 1] || activatedEffect.cTarAr[targs][AREA] ) ){
				return true;
			}
		}
		else {
			if ((activatedEffect.cTarTy[targs][TYPE] || activatedEffect.cTarTy[targs][pCards[targetCard].cRace] || activatedEffect.cTarTy[targs][pCards[targetCard].cType] ) && ( activatedEffect.cTarAr[targs][(pCards[targetCard].place * 2) + 2] || activatedEffect.cTarAr[targs][AREA] ) ){
				return true;
			}
		}
	}
	return false;
}

string simplify(size_t cPlay, string expression, vector<playHistory> *pHist) { //this is called postfix or something
	if (expression == "") { return "true"; }
	int i, chance;
	if ( (i = expression.find("tarNum")) != string::npos) { expression.replace(i, 7, to_string((*pHist)[expression[i + 6] - '0'].tarNum)); }
	if ( (i = expression.find("PHAND_SIZE")) != string::npos) { expression.replace(i, 10, to_string(Player->hand.size())); }
	if ( (i = expression.find("OHAND_SIZE")) != string::npos) { expression.replace(i, 10, to_string(Player->Ogame->hand.size())); }
	if ( (i = expression.find("SPDAM")) != string::npos) { expression.replace(i, 5, to_string(Player->spDam)); }
	if ( (i = expression.find("COST")) != string::npos) { expression.replace(i, 5, to_string((*pHist)[expression[i + 4] - '0'].cost)); }
	if ( (i = expression.find("ATK")) != string::npos) { expression.replace(i, 4, to_string((*pHist)[expression[i + 3] - '0'].atk)); }
	if ( (i = expression.find("HPC")) != string::npos) { expression.replace(i, 4, to_string((*pHist)[expression[i + 3] - '0'].hpc)); }
	if ( (i = expression.find("HPM")) != string::npos) { expression.replace(i, 4, to_string((*pHist)[expression[i + 3] - '0'].hpm)); }
	if ( (i = expression.find("FX")) != string::npos) {
		if (expression[i + 5] == ']') { 
			pCards[(*pHist)[expression[i+2]-'0'].tar].modsFx[expression[i+4]-'0'] ? expression.replace(i, 6, "true") : expression.replace(i, 6, "false"); }
		else { 
			pCards[(*pHist)[expression[i+2]-'0'].tar].modsFx[10*(expression[i+4]-'0') + (expression[i+5]-'0')] ? expression.replace(i, 7, "true") : expression.replace(i, 7, "false"); }
	}
	if ( (i = expression.find("cost")) != string::npos) { expression.replace(i, 4, to_string(pCards[cPlay].getCost())); }
	if ( (i = expression.find("atk")) != string::npos) { expression.replace(i, 3, to_string(pCards[cPlay].getAtk())); }
	if ( (i = expression.find("hpc")) != string::npos) { expression.replace(i, 3, to_string(pCards[cPlay].getHpc())); }
	if ( (i = expression.find("hpm")) != string::npos) { expression.replace(i, 3, to_string(pCards[cPlay].getHpm())); }
	if ( (i = expression.find("fx")) != string::npos) { 
		if (expression[i + 4] == ']') {	pCards[cPlay].modsFx[expression[i+3]-'0'] ? expression.replace(i, 5, "true") : expression.replace(i, 5, "false"); }
		else { pCards[cPlay].modsFx[10*(expression[i + 2] - '0')+(expression[i+3]-'0')] ? expression.replace(i, 6, "true") : expression.replace(i, 6, "false"); }
	}
	if ( (i = expression.find("cMana")) != string::npos) { expression.replace(i, 5, to_string(Player->cMana)); }
	if ( (i = expression.find("mMana")) != string::npos) { expression.replace(i, 5, to_string(Player->mMana)); }
	if ((i = expression.find("RAND")) != string::npos) { chance = rand() % (expression[i + 5] - '0'); if (moveSet != -1 && cMove < skipSet) { chance = moveSort[moveSet][cMove++]; } currNode.currMoves.push_back(chance); expression.replace(i, 5, to_string(chance)); }
	if ( (i = expression.find("DAM")) != string::npos) { expression.replace(i, 4, to_string((*pHist)[expression[i + 3] - '0'].dam)); }
	if ( (i = expression.find("SIDE")) != string::npos) { expression.replace(i, 5, to_string(pCards[(*pHist)[expression[i + 4] - '0'].tar].side)); }
	if ( (i = expression.find("RACE")) != string::npos) { expression.replace(i, 5, to_string(pCards[(*pHist)[expression[i + 4] - '0'].tar].cRace)); }
	if ( (i = expression.find("BEAST")) != string::npos) { expression.replace(i, 5, to_string(BEAST)); }
	if ((i = expression.find("globID")) != string::npos) { expression.replace(i, 6, to_string(globID)); }
	if ((i = expression.find("PROLE")) != string::npos) { expression.replace(i, 5, "role" + to_string(pCards[Player->hero].cRole)); }

	if ((i = expression.find("true")) != string::npos) {
		return "true";
	}
	if ((i = expression.find("false")) != string::npos) {
		return "false";
	}
	//todo more than two expressions

	stringstream ss;
	ss.str(expression);
	string item;
	bool first = true;
	int ans = 0;
	if (expression.length() < 3) { ans = stoi(expression); }
	else {
		if ((i = expression.find("<")) != string::npos) {
			if (stoi(expression.substr(0, i)) < stoi(expression.substr(i + 1))) {
				return "true";
			}
			else {
				return "false";
			}
		}
		if ((i = expression.find(">")) != string::npos) {
			if (stoi(expression.substr(0, i)) > stoi(expression.substr(i + 1))) {
				return "true";
			}
			else {
				return "false";
			}
		}
		if ((i = expression.find("==")) != string::npos) {
			if (stoi(expression.substr(0, i)) == stoi(expression.substr(i + 2))) {
				return "true";
			}
			else {
				return "false";
			}
		}
		if ((i = expression.find("+")) != string::npos) {
			while (getline(ss, item, '+')) {
				if (first) { ans = stoi(item); }
				else { ans += stoi(item); }
				first = false;
			}
		}
		else if ((i = expression.find("-")) != string::npos) {
			while (getline(ss, item, '-')) {
				if (first) { ans = stoi(item); }
				else { ans -= stoi(item); }
				first = false;
			}
		}
		else if ((i = expression.find("*")) != string::npos) {
			while (getline(ss, item, '*')) {
				if (first) { ans = stoi(item); }
				else { ans *= stoi(item); }
				first = false;
			}
		}
	}
	return to_string(ans);
}

void checkDead() {
	size_t cPlay;
	int checking = 2;
	vector <size_t> fxQ;
	vector <size_t> deaths;
	//vector <size_t> places[2];
	bool changeflag = false;
	for (auto i : changeFlags) {
		flattenMod(i);
	}
	while (checking > 0) {
		if (pCards[Player->weapon].getHpc() <= 0 && Player->weapon > Bwep) { //remove wep with no dur
			for (auto i : pCards[Player->weapon].cMods[DEATHRATTLE]) {
				fxQ.push_back(i);
			}
			Player->grave.push_back(Player->weapon);
			deactivateCard(pCards[Player->weapon], 0);
			Player->side == 1 ? Player->weapon = Awep : Player->weapon = Bwep;
			deaths.push_back(Player->weapon); 
			bool changeflag = true;
		}
		for (int i = 0; i < Player->board.size(); i++) {  //remove minions with no health
			cPlay = Player->board[i];
			pCards[cPlay].placement = i;
			if (pCards[cPlay].getHpc() <= 0) {
				Player->grave.push_back(cPlay);
				Player->board.erase(Player->board.begin() + i);
				i--;
				for (auto j : pCards[cPlay].cMods[DEATHRATTLE]) { fxQ.push_back(j); } //places[checking-1].push_back(i);
				deactivateCard(pCards[cPlay], 0);
				deaths.push_back(cPlay);
				placeActivity[Player->side - 1] = true;
				bool changeflag = true;
			}
		}

		Player = Player->Ogame; checking--;
	}

	if (changeFlags.size() > 0) { syncAura(); } //shouldn't kill anything
	changeFlags.clear();

	playInfo temp; temp.cTarget = -3;
	for (auto i : fxQ) {
		//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = 88; //fill historydata with card about to play
		//historyData.push_back(hPlay);
		//historyData.back().to1 = "X";
		temp.cPlay = pMods[i].targ;
		affect(DEATHRATTLE, i, &temp);//applies all deathrattles
	}/*
	for (auto i : places[1]) {
		Player->board.erase(Player->board.begin() + i);
	}
	for (auto i : places[0]) {
		Player->Ogame->board.erase(Player->Ogame->board.begin() + i); //needed for ADJ but thats the only reason
	}*/
	for (auto k : deaths) {
		temp.cPlay = k;
		checkTrig(&temp, "DIES");
		deactivateCard(pCards[k],3);
		pCards[k].place = GRAVEYARD; 
	}
	if (changeflag) { checkDead(); }
}

void syncAura() {
	AGame.spDam = 0;
	BGame.spDam = 0;
	vector <size_t> temp = auras;
	for (auto i : temp) {
		bool go = false;
		for (int targs = 0; targs < pMods[i].cTarAr.size(); targs++) {
			if ((pMods[i].cTarAr[targs][PBOARD] && pCards[pMods[i].targ].side == 1) || (pMods[i].cTarAr[targs][OBOARD] && pCards[pMods[i].targ].side == 2)) { if (placeActivity[0]) { go = true; break; } }
			if ((pMods[i].cTarAr[targs][OBOARD] && pCards[pMods[i].targ].side == 1) || (pMods[i].cTarAr[targs][PBOARD] && pCards[pMods[i].targ].side == 2)) { if (placeActivity[1]) { go = true; break; } }
			if ((pMods[i].cTarAr[targs][PHAND] && pCards[pMods[i].targ].side == 1) || (pMods[i].cTarAr[targs][OHAND] && pCards[pMods[i].targ].side == 2)) { if (placeActivity[2]) { go = true; break; } }
			if ((pMods[i].cTarAr[targs][OHAND] && pCards[pMods[i].targ].side == 1) || (pMods[i].cTarAr[targs][PHAND] && pCards[pMods[i].targ].side == 2)) { if (placeActivity[3]) { go = true; break; } }
		}
		if (!go) { continue; }
		removeAura(i);
		//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = pCards[pMods[i].targ].placement; //fill historydata with card about to play
		//historyData.push_back(hPlay);
		//historyData.back().to1 = "X";
		playInfo play; play.cPlay = pMods[i].targ; play.cTarget = -1 * pCards[pMods[i].targ].side;
		affect(AURA, i, &play);
	}
	placeActivity[0] = false; placeActivity[1] = false; placeActivity[2] = false; placeActivity[3] = false;
}

bool checkTrig(playInfo *play, string trig) {
	bool trigFlag = false;
	vector<size_t> trigged;
	for (auto i : triggers) {
		for (int j = 0; j < pMods[i].prearg.size(); j++) {
			if (pMods[i].prearg[j][0].find(trig) != string::npos) {
				if (pMods[i].postarg[j][0] != "") { if (simplify(play->cTarget, pMods[i].postarg[j][0]) != "true") { break; } }
				if (evalDomain(pMods[i], j, play->cPlay) && evalDomain(pMods[i], j + 1, play->cTarget)) { //if i triggers when cPlay targets cTarget
					//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = 66; //fill historydata with card about to play
					//historyData.push_back(hPlay);
					//historyData.back().to1 = "X";
					affect(TRIGGER, i, play, j + 2); trigFlag = true; trigged.push_back(pMods[i].targ);
				}
			}
		}
	}
	if(trigFlag){
		for (auto i : trigged) {
			if (pCards[i].cType == SECRET) { //removes secret after triggered
				for (int j = Player->secrets.size() - 1; j >= 0; j--) {
					if (Player->secrets[j] == i) { Player->secrets.erase(Player->secrets.begin() + j); break; }
				}
				for (int j = triggers.size() - 1; j >= 0; j--) {
					if (triggers[j] == pCards[i].cMods[TRIGGER][0]) { triggers.erase(triggers.begin() + j); break; }
				}
			}
		}
	}
	return trigFlag;
}

bool affect(int trig, size_t mPlay, playInfo *play, size_t skip) {
	size_t cPlay = pMods[mPlay].targ;
	bool swapflag = false;
	if (pCards[cPlay].side != Player->side) { Player = Player->Ogame; swapflag = true; }
	//playInfo spellPlay; spellPlay.cPlay = cPlay, spellPlay.cTarget = -1 * pCards[cPlay].side;
	vector < vector<size_t> > vTars;
	vTars.push_back(vector<size_t>());
	vTars[0].push_back(cPlay);
	vector < vector<int> > vPlacement;
	vPlacement.push_back(vector<int>());

	vector <playHistory> pHist; pHist.push_back(playHistory()); 
	if (play!=NULL && play->cPlay>=0) {
		pHist[0].dam = play->cDam; pHist[0].tar = play->cPlay;
		pHist[0].atk = pCards[play->cPlay].getAtk(); pHist[0].hpc = pCards[play->cPlay].getHpc(); pHist[0].hpm = pCards[play->cPlay].getHpm(); pHist[0].cost = pCards[play->cPlay].getCost();
	}
	vector <string> tempStrings;
	vector<size_t> stringPlaceTargs, stringPlacei, stringPlaceVec;
	bool duelFlag = false;
	bool ifeFlag = false;
	size_t targs = 0;
	for (size_t i = 0; i < skip; i++) {
		targs++; vTars.push_back(vector<size_t>()); vPlacement.push_back(vector<int>());
		if (i == 0) { vTars[0][0] = play->cPlay; vTars[1].push_back(play->cTarget); }
		if (i == 1) { vTars[0][0] = cPlay; vTars[1][0] = play->cPlay; vTars[2].push_back(play->cTarget); }
	}
	for (targs; targs < pMods[mPlay].prearg.size(); targs++) {
		pHist.push_back(playHistory());
		vTars.push_back(vector<size_t>());
		vPlacement.push_back(vector<int>());
		vector <size_t> tars;
		vector <size_t> tars2;
		vector <int> placement, placement2;
		int tarHero = 0, timeFlag = 0, tarNum = 0;
		size_t j, k;

		if (trig == CHOOSEONE) {
			int temp = rand() % 2; //choice
			if (moveSet != -1 && cMove < skipSet) { temp = moveSort[moveSet][cMove++]; }
			currNode.currMoves.push_back(temp);
			if (temp == 1) { continue; }
		}
		if (trig == COMBO) {
			if (!Player->comboflag) { continue; }
		}

		//do preproccesses here, replace all tarnum in this targs with number of tar from previous targs //TODO replace back with initial strings after targs loop
		for (int i = 0; i < pMods[mPlay].prearg[targs].size(); i++) {
			if ( (j = pMods[mPlay].prearg[targs][i].find("%")) != string::npos) {
				k = pMods[mPlay].prearg[targs][i].find("%", j + 1);
				tempStrings.push_back(pMods[mPlay].prearg[targs][i]); stringPlaceTargs.push_back(targs); stringPlacei.push_back(i); stringPlaceVec.push_back(0);
				pMods[mPlay].prearg[targs][i].replace(j, k - j + 1, simplify(cPlay, pMods[mPlay].prearg[targs][i].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
			}
		}
		for (int i = 0; i < pMods[mPlay].postarg[targs].size(); i++) {
			if ( (j = pMods[mPlay].postarg[targs][i].find("%")) != string::npos) {
				size_t k = pMods[mPlay].postarg[targs][i].find("%", j + 1);
				tempStrings.push_back(pMods[mPlay].postarg[targs][i]); stringPlaceTargs.push_back(targs); stringPlacei.push_back(i); stringPlaceVec.push_back(1);
				pMods[mPlay].postarg[targs][i].replace(j, k - j + 1, simplify(cPlay, pMods[mPlay].postarg[targs][i].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
			}
		}
		if ( (j = pMods[mPlay].target[targs].find("%")) != string::npos) {
			size_t k = pMods[mPlay].target[targs].find("%", j + 1);
			tempStrings.push_back(pMods[mPlay].target[targs]); stringPlaceTargs.push_back(targs); stringPlacei.push_back(0); stringPlaceVec.push_back(2);
			pMods[mPlay].target[targs].replace(j, k - j + 1, simplify(cPlay, pMods[mPlay].target[targs].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
		}
		for (int i = 0; i < pMods[mPlay].effect[targs].size(); i++) {
			if ( (j = pMods[mPlay].effect[targs][i].find("%")) != string::npos) {
				size_t k = pMods[mPlay].effect[targs][i].find("%", j + 1);
				tempStrings.push_back(pMods[mPlay].effect[targs][i]); stringPlaceTargs.push_back(targs); stringPlacei.push_back(i); stringPlaceVec.push_back(3);
				pMods[mPlay].effect[targs][i].replace(j, k - j + 1, simplify(cPlay, pMods[mPlay].effect[targs][i].substr(j + 1, k - j - 1), &pHist));
			}
		}

		//e.g. replace ATK2 with the atk of tar from targs2, HPC1 with the atk of tar from targs1

		if (pMods[mPlay].prearg[targs][0] == "" || trig == TURNPOINT) { //no prearg condition //or turnpoints trigger, prearg already met??

		}
		else {
			bool failFlag = false;
			for (auto i : pMods[mPlay].prearg[targs]) {
				if (i == "unarmed") {
					if (pMods[mPlay].cTarAr[targs][PBOARD] && !(Player->weapon > Bwep)) {}
					else if (pMods[mPlay].cTarAr[targs][OBOARD] && !(Player->Ogame->weapon > Bwep)) {}
					else { failFlag = true; } //failed prearg
				}
				if (i == "duel") {
					bool go = false, go2 = false;
					for (auto j : Player->deck) {
						if (pCards[j].cType == MINION) { go = true; break; }
					}
					for (auto j : Player->Ogame->deck) {
						if (pCards[j].cType == MINION) { go2 = true; break; }
					}
					if (!go) { failFlag = true; continue; }
					if (go2) {
						duelFlag = true;
						size_t sCard1 = rand() % Player->deck.size(), sCard2 = rand() % Player->Ogame->deck.size();
						if (moveSet != -1 && cMove < skipSet) { sCard1 = moveSort[moveSet][cMove++]; sCard2 = moveSort[moveSet][cMove++]; }
						currNode.currMoves.push_back(sCard1); currNode.currMoves.push_back(sCard2);
						if (pCards[Player->deck[sCard1]].getCost() > pCards[Player->Ogame->deck[sCard2]].getCost()) {

						}
						else if (pCards[Player->deck[sCard1]].getCost() < pCards[Player->Ogame->deck[sCard2]].getCost()) {
							failFlag = true;
						}
					}
				}
				if (i == "reno") {
					vector <string> tempDeck;
					for (auto i : Player->deck) {
						for (auto j : tempDeck) {
							if (pCards[i].name == j) { failFlag = true; break; }
						}
						tempDeck.push_back(pCards[i].name);
						if (failFlag) { break; }
					}
				}
				if(i == "ife"){
					ifeFlag = true;
				}
				else if (i == "true") {
					//passed
				}
				else if (i == "false") {
					failFlag = true;
				}
			}
			if (failFlag) { continue; }
		}

		//effects that don't require targets //maybe put a ~ in prearg to say to skip tars;
		if (pMods[mPlay].cTarTy[targs][TYPE] == true && pMods[mPlay].target[targs] == "") {
			if (pCards[cPlay].cType == SPELL) {
				checkTrig(play, "HEXES");
			}
			for (auto i : pMods[mPlay].effect[targs]) {
				if (i.find("spDam") != string::npos) {
					if (pCards[cPlay].side == 1) { AGame.spDam += i[6] - '0'; }
					else { BGame.spDam += i[6] - '0'; }
				}
				else if (i.find("HeroFury") != string::npos) {
					if (pCards[cPlay].side == 1) { AGame.HeroFury = true; }
					else { BGame.HeroFury = true; }
				}
				else if (i.find("retarget") != string::npos) {
					play->cTarget = vTars[i[12] - '0'][0]; //TODO assumes always TAR#
					tars2.push_back(play->cTarget);
					placement2.push_back(999);
					//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(play->cTarget);}
					continue;
				}
				else if (i.find("draw") != string::npos) {
					if (pMods[mPlay].cTarAr[targs][PHAND]) {
						tars2 = draw(i[5] - '0', Player);
						for (auto j : tars2) {
							placement2.push_back(Player->hand.size() - 1);
						}
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->side);}
					}
					if (pMods[mPlay].cTarAr[targs][OHAND]) {
						tars2 = draw(i[5] - '0', Player->Ogame); //todo replaces one above does that even matter?
						for (auto j : tars2) {
							placement2.push_back(Player->Ogame->hand.size() - 1);
						}
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->Ogame->side);}
					}
					continue;
				}
				else if (i.find("cMana") != string::npos) {
					if (pMods[mPlay].cTarAr[targs][PBOARD]) {
						if (i[5] == '+') { Player->cMana += i[6] - '0'; }
						if (i[5] == '-') { Player->cMana -= i[6] - '0'; }
						if (i[5] == '=') { Player->cMana = i[6] - '0'; }
						tars2.push_back(Player->side - 1);
						placement2.push_back(999);
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->side);	}
					}
					if (pMods[mPlay].cTarAr[targs][OBOARD]) {
						if (i[5] == '+') { Player->Ogame->cMana += i[6] - '0'; }
						if (i[5] == '-') { Player->Ogame->cMana -= i[6] - '0'; }
						if (i[5] == '=') { Player->Ogame->cMana = i[6] - '0'; }
						tars2.push_back(Player->Ogame->side - 1);
						placement2.push_back(999);
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->Ogame->side);}
					}
					continue;
				}
				else if (i.find("mMana") != string::npos) {
					if (pMods[mPlay].cTarAr[targs][PBOARD]) {
						if (i[5] == '+') { Player->mMana += i[6] - '0'; }
						if (i[5] == '-') { Player->mMana -= i[6] - '0'; }
						if (i[5] == '=') { Player->mMana = i[6] - '0'; }
						tars2.push_back(Player->side - 1);
						placement2.push_back(999);
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->side);}
					}
					if (pMods[mPlay].cTarAr[targs][OBOARD]) {
						if (i[5] == '+') { Player->Ogame->mMana += i[6] - '0'; }
						if (i[5] == '-') { Player->Ogame->mMana -= i[6] - '0'; }
						if (i[5] == '=') { Player->Ogame->mMana = i[6] - '0'; }
						tars2.push_back(Player->Ogame->side - 1);
						placement2.push_back(999);
						//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(0 - Player->Ogame->side);}
					}
					continue;
				}
				else if (i.find("summon") != string::npos) {
					string name = i.substr(9, i.length() - 12);
					if (name.find("TAR") != string::npos) { 
						size_t k = name[3] - '0';
						name = pCards[vTars[k][0]].name;
					}
					size_t sCard = 0;
					if (name == "RAND") {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect) { break; }
						}
					}
					else if (name == "SPELL") {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect && Cards[sCard].cType == SPELL) { break; }
						}
					}
					else if (name == "OCLASS") {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect && Cards[sCard].cRole == pCards[Player->Ogame->hero].cRole) { break; }
						}
					}
					else if (name == "BEAST") {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect && Cards[sCard].cRace == BEAST) { break; }
						}
					}
					else if (name == "LEGENDARY") {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect && Cards[sCard].rarity == "LEGENDARY") { break; }
						}
					}
					else if (name.find("COST")!=string::npos) {
						while (true) {
							sCard = rand() % Cards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							if (Cards[sCard].collect && Cards[sCard].getCost() == name[0] - '0') { break; }
						}
					}
					else if (i[7] == 'N') { //named card
						for (size_t k = 0; k < Cards.size(); k++) {
							if (Cards[k].name == name) { sCard = k; break; }
						}
					}
					else if (i[7] == 'G') {//card in a group
						for (size_t k = 0; k < GROUPSIZE; k++) {
							if (cGroups[k][0] == name) {
								int choice = rand() % (cGroups[k].size() - 1) + 1;
								if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
								currNode.currMoves.push_back(choice);
								for (size_t l = 0; l < Cards.size(); l++) {
									if (Cards[l].name == cGroups[k][choice]) { sCard = l; break; }
								}
								break;
							}
						}
					}
					else { cout << "error" << endl; }
					for (int l = 0; l < i[i.length() - 2] - '0'; l++) { //summon(S,Slime,2) should summon 2 slimes, l=2
						if (pMods[mPlay].cTarAr[targs][PBOARD] && Player->board.size() < 7) {
							importCard(Cards[sCard]);
							playInfo play; play.cPlay = pCards.size()-1; play.cTarget = -1 * Player->side;
							Player->board.push_back(pCards.size() - 1);
							pCards.back().side = Player->side;
							pCards.back().place = BOARD;
							pCards.back().placement = Player->board.size() - 1;
							placeActivity[Player->side - 1] = true;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->board.size() - 1);}
							tars2.push_back(pCards.size()-1);
							placement2.push_back(999);
							checkTrig(&play, "SUMMON");
						}
						if (pMods[mPlay].cTarAr[targs][OBOARD] && Player->Ogame->board.size() < 7) {
							importCard(Cards[sCard]);
							playInfo play; play.cPlay = pCards.size()-1; play.cTarget = -1 * Player->Ogame->side;
							Player->Ogame->board.push_back(pCards.size() - 1);
							pCards.back().side = Player->Ogame->side;
							pCards.back().place = BOARD;
							pCards.back().placement = Player->Ogame->board.size()-1;
							placeActivity[Player->Ogame->side - 1] = true;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->Ogame->board.size() - 1);}
							tars2.push_back(pCards.size() - 1);
							placement2.push_back(999);
							checkTrig(&play, "SUMMON");
						}
						if (pMods[mPlay].cTarAr[targs][PHAND] && Player->hand.size() < 10) {
							importCard(Cards[sCard]);
							Player->hand.push_back(pCards.size() - 1);
							pCards.back().side = Player->side;
							pCards.back().place = HAND;
							pCards.back().placement = Player->hand.size();
							placeActivity[Player->side + 1] = true;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->hand.size() - 1);}
							tars2.push_back(pCards.size() - 1);
							placement2.push_back(999);
						}
						if (pMods[mPlay].cTarAr[targs][OHAND] && Player->Ogame->hand.size() < 10) {
							importCard(Cards[sCard]);
							Player->Ogame->hand.push_back(pCards.size() - 1);
							pCards.back().side = Player->Ogame->side;
							pCards.back().place = HAND;
							pCards.back().placement = Player->Ogame->hand.size();
							placeActivity[Player->Ogame->side + 1] = true;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->Ogame->hand.size() - 1);}
							tars2.push_back(pCards.size() - 1);
							placement2.push_back(999);
						}							
					}
					continue;
				}
				else if (i.find("ressurect")!=string::npos) { //TODO
					string name = i.substr(10, i.length() - 11);
					if (name == "MURLOC") {
						vector<size_t> sCards;
						for (auto j : Player->grave) {
							if (pCards[j].cType == MURLOC) { sCards.push_back(j); }
						}
						size_t num = i[i.length() - 2] - '0';
						if (sCards.size() < num) { num = sCards.size(); }
						while (num > 0) {
							size_t sCard = rand() % sCards.size();
							if (moveSet != -1 && cMove < skipSet) { sCard = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(sCard);
							importCard(Cards[sCard]);
							playInfo play; play.cPlay = -3; play.cTarget = pCards.size() - 1;
						}
					}
				}
				else if (i.find("shuffle") != string::npos) {
					string name = i.substr(10, i.length() - 11);
					size_t sCard = 0;
					if (i[7] == 'N') { //single card
						for (size_t k = 0; k < Cards.size(); k++) {
							if (Cards[k].name == name) { sCard = k; break; }
						}
					}
					else if (i[7] == 'G') {//one of a group
						for (size_t k = 0; k < GROUPSIZE; k++) {
							if (cGroups[k][0] == name) {
								int choice = rand() % (cGroups[k].size() - 1) + 1;
								if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
								currNode.currMoves.push_back(choice);
								for (size_t k = 0; k < Cards.size(); k++) {
									if (Cards[k].name == cGroups[k][choice]) { sCard = k; break; }
								}
								break;
							}
						}
					}
					else {}//error
					for (int l = 0; l < i[i.length() - 2] - '0'; l++) { //summon(S,Slime,2) should summon 2 slimes, l=2
						if (pMods[mPlay].cTarAr[targs][ODECK]) {
							size_t place = rand() % Player->Ogame->deck.size();
							if (moveSet != -1 && cMove < skipSet) { place = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(place);
							importCard(Cards[sCard]);
							Player->Ogame->deck.insert(Player->Ogame->deck.begin() + place,pCards.size()-1);
							pCards.back().side = Player->Ogame->side;
							pCards.back().place = DECK;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->Ogame->board.size() - 1);}
							tars2.push_back(pCards.size() - 1);
							placement2.push_back(999);
						}
						if (pMods[mPlay].cTarAr[targs][PDECK]) {
							size_t place = rand() % Player->deck.size();
							if (moveSet != -1 && cMove < skipSet) { place = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(place);
							importCard(Cards[sCard]);
							Player->deck.insert(Player->deck.begin() + place, pCards.size() - 1);
							pCards.back().side = Player->side;
							pCards.back().place = DECK;
							//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(Player->board.size() - 1);}
							tars2.push_back(pCards.size()-1);
							placement2.push_back(999);
						}
					}
					//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(222);}
					continue;
				}
				else if (i.find("discover") != string::npos) { //TODO class cards are weighted 4 times the chance of neutral
					string name = i.substr(9, i.length() - 12);
					size_t dCards;
					for (size_t k = 0; k < GROUPSIZE; k++) {
						if (cGroups[k][0] == name) {
							dCards = k;
							break;
						}
					}
					size_t num = i[i.length() - 2] - '0';
					vector<Card> disc;
					//put all discovers here
					for (int k = 0; k < num; k++) {
						if (name == "DEATHRATTLE") {
							while (true) {
								int choice = rand() % Cards.size();
								if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
								currNode.currMoves.push_back(choice);
								if (Cards[choice].cMods[DEATHRATTLE].size() > 0 && Cards[choice].collect) { disc.push_back(Cards[choice]); break; }
							}
						}
						else if (name.find("COST")!=string::npos) {
							while (true) {
								int choice = rand() % Cards.size();
								if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
								currNode.currMoves.push_back(choice);
								if (Cards[choice].collect && Cards[choice].getCost() == name[0] - '0') { disc.push_back(Cards[choice]); break; }
							}
						}
						else {
							int choice = rand() % (cGroups[dCards].size() - 1) + 1;
							if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(choice);
							bool flag = true;
							for (auto j : disc) {
								if (j.name == cGroups[dCards][choice]) { k--; continue; }
							}
							if (flag) {
								for (auto l : Cards) {
									if (l.name == cGroups[dCards][choice]) { disc.push_back(l); break; }
								}
							}
						}
					}
					int choice = rand() % num;//player choice
					if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
					currNode.currMoves.push_back(choice);
					if (pMods[mPlay].cTarAr[targs][PHAND]) {
						if (Player->hand.size() < 10) {
							importCard(disc[choice]);
							pCards.back().side = Player->side;
							pCards.back().place = HAND;
							pCards.back().placement = Player->hand.size() - 1;
							placeActivity[Player->side + 1] = true;
							Player->hand.push_back(pCards.size() - 1);
							tars2.push_back(pCards.size() - 1);
							placement2.push_back(999);
						}
					}
					if (pMods[mPlay].cTarAr[targs][PBOARD]) {
						importCard(disc[choice]);
						pCards.back().side = Player->side;
						pCards.back().place = BOARD;
						pCards.back().placement = Player->board.size() - 1;
						placeActivity[Player->side - 1] = true;
						tars2.push_back(pCards.size() - 1);
						placement2.push_back(999);
						if (disc[choice].cType==HEROPWR) {
							Player->hPwr = pCards.size() - 1;
						}
						if (Player->board.size() < 7) {
							Player->board.push_back(pCards.size() - 1);
						}
					}
					//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(333);}
					continue;
				}
				else if (i.find("equip") != string::npos) {
					string name = i.substr(8, i.length() - 9);
					size_t eCard = 0;
					if (i[7] == 'N') { //named card
						for (size_t k = 0; k < Cards.size(); k++) {
							if (Cards[k].name == name) { eCard = k; break; }
						}
					}
					else if (i[7] == 'G') { //one of a group //todo
						for (size_t k = 0; k < sizeof(cGroups); k++) {
							if (cGroups[k][0] == name) {
								int choice = rand() % (sizeof(cGroups[k]) - 1) + 1;
								if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
								currNode.currMoves.push_back(choice);
								for (size_t k = 0; k < Cards.size(); k++) {
									if (Cards[k].name == cGroups[k][choice]) { eCard = k; break; }
								}
								break;
							}
						}
					}
					else {}//error
					if (pMods[mPlay].cTarAr[targs][PBOARD]) {
						playInfo play; play.cPlay = pCards.size(); play.cTarget = -1 * Player->side;
						importCard(Cards[eCard]);
						pCards.back().side = Player->side;
						pCards.back().place = BOARD;
						pCards.back().placement = Player->board.size()-1;
						placeActivity[Player->side - 1] = true;
						Player->weapon = pCards.size() - 1;
						tars2.push_back(pCards.size() - 1);
						placement2.push_back(999);
						checkTrig(&play, "EQUIP");
					}
					if (pMods[mPlay].cTarAr[targs][OBOARD]) {
						playInfo play; play.cPlay = pCards.size(); play.cTarget = -1 * Player->Ogame->side;
						importCard(Cards[eCard]);
						pCards.back().side = Player->Ogame->side;
						pCards.back().place = BOARD;
						pCards.back().placement = Player->Ogame->board.size() - 1;
						Player->Ogame->weapon = pCards.size() - 1;
						placeActivity[Player->Ogame->side - 1] = true;
						tars2.push_back(pCards.size() - 1);
						placement2.push_back(999);
						checkTrig(&play, "EQUIP");
					}
					//if (historyData.back().to1 == "X") {historyData.back().to2.push_back(444);}
					continue;
				}
			}
			tarNum = tars2.size();
			vTars[targs + 1] = tars2;
			vPlacement[targs + 1] = placement2;
			changeFlags.push_back(Player->side - 1);
		}
		else {
			for (size_t i = 1; i < TYCOUNT; i++) { //bool type[15] {TYPE, HERO, MINION, SPELL, SECRET, WEAPON, HEROPWR, RACE, BEAST, DEMON, DRAGON, MECHANICAL, MURLOC, PIRATE, TOTEM}
				if (pMods[mPlay].cTarTy[targs][i]) {
					if (pMods[mPlay].cTarAr[targs][PBOARD]) {
						if (i == HERO && (!pCards[Player->hero].modsFx[SPELLSCREEN] || (pCards[cPlay].cType != SPELL && pCards[cPlay].cType != HEROPWR))) { //if no spellscreen or if played card isnt spell or heropwr
							tars.push_back(Player->hero); placement.push_back(-1);
						}
						else if (i == WEAPON) { tars.push_back(Player->weapon); placement.push_back(-2); }
						else if (i == HEROPWR) { tars.push_back(Player->hPwr); placement.push_back(-3); }
						else if (i == SECRET) {
							int k = -4;
							for (auto j : Player->secrets) { tars.push_back(j); placement.push_back(k--); }
						}
						else {
							int k = 0;
							for (auto j : Player->board) {
								if ((pCards[j].cType == i || pCards[j].cRace == i) && (!pCards[j].modsFx[SPELLSCREEN] || (pCards[cPlay].cType != SPELL && pCards[cPlay].cType != HEROPWR))) {
									tars.push_back(j); placement.push_back(k);
								}
								k++;
							}
						}
					}
					if (pMods[mPlay].cTarAr[targs][OBOARD]) {
						if (i == HERO && (!pCards[Player->Ogame->hero].modsFx[SPELLSCREEN] || (pCards[cPlay].cType != SPELL && pCards[cPlay].cType != HEROPWR))) { tars.push_back(Player->Ogame->hero); placement.push_back(-11); }
						else if (i == WEAPON) { tars.push_back(Player->Ogame->weapon); placement.push_back(-12); }
						else if (i == HEROPWR) { tars.push_back(Player->Ogame->hPwr); placement.push_back(-13); }
						else if (i == SECRET) {
							int k = -4;
							for (auto j : Player->Ogame->secrets) { tars.push_back(j); placement.push_back(k--); }
						}
						else {
							int k = 0;
							for (auto j : Player->Ogame->board) {
								if ((pCards[j].cType == i || pCards[j].cRace == i) && (!pCards[j].modsFx[SPELLSCREEN] || (pCards[cPlay].cType != SPELL && pCards[cPlay].cType != HEROPWR))) {
									tars.push_back(j); placement.push_back(k);
								}
								k++;
							}
						}
					}
					if (pMods[mPlay].cTarAr[targs][PHAND]) {
						int k = 10;
						for (auto j : Player->hand) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
					if (pMods[mPlay].cTarAr[targs][OHAND]) {
						int k = 10;
						for (auto j : Player->Ogame->hand) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
					if (pMods[mPlay].cTarAr[targs][PDECK]) {
						int k = 20;
						for (auto j : Player->deck) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
					if (pMods[mPlay].cTarAr[targs][ODECK]) {
						int k = 20;
						for (auto j : Player->Ogame->deck) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
					if (pMods[mPlay].cTarAr[targs][PGRAVE]) {
						int k = 100;
						for (auto j : Player->grave) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
					if (pMods[mPlay].cTarAr[targs][OGRAVE]) {
						int k = 100;
						for (auto j : Player->Ogame->grave) {
							if (pCards[j].cType == i || pCards[j].cRace == i) { tars.push_back(j); placement.push_back(k); }
							k++;
						}
					}
				}
			}
			if (pMods[mPlay].postarg[targs].size() == 1 && pMods[mPlay].postarg[targs][0] == "") {} //skip this v
			else {
				vector<bool> bTars(tars.size(), true);
				for (auto i : pMods[mPlay].postarg[targs]) { //restrict tars based on the postarg
					size_t k = 0;
					for (auto j : tars) {
						if (i.find("cost") != string::npos) {
							if (i[4] == '=') {
								if (pCards[j].getCost() != i[5]) { bTars[k] = false; }
							}
							if (i[4] == '<') {
								if (pCards[j].getCost() >= i[5]) { bTars[k] = false; }
							}
							if (i[4] == '>') {
								if (pCards[j].getCost() <= i[5]) { bTars[k] = false; }
							}
						}
						if (i.find("atk") != string::npos) {
							if (i[3] == '=') {
								if (pCards[j].getAtk() != i[4]) { bTars[k] = false; }
							}
							if (i[3] == '<') {
								if (pCards[j].getAtk() >= i[4]) { bTars[k] = false; }
							}
							if (i[3] == '>') {
								if (pCards[j].getAtk() <= i[4]) { bTars[k] = false; }
							}
						}
						if (i.find("hpc") != string::npos) {
							if (i[3] == '=') {
								if (pCards[j].getHpc() != i[4]) { bTars[k] = false; }
							}
							if (i[3] == '<') {
								if (pCards[j].getHpc() >= i[4]) { bTars[k] = false; }
							}
							if (i[3] == '>') {
								if (pCards[j].getHpc() <= i[4]) { bTars[k] = false; }
							}
						}
						if (i.find("hpm") != string::npos) {
							if (i[3] == '=') {
								if (pCards[j].getHpm() != i[4]) { bTars[k] = false; }
							}
							if (i[3] == '<') {
								if (pCards[j].getHpm() >= i[4]) { bTars[k] = false; }
							}
							if (i[3] == '>') {
								if (pCards[j].getHpm() <= i[4]) { bTars[k] = false; }
							}
						}
						if (i.find("dam") != string::npos) {
							if (pCards[j].getHpm() == pCards[j].getHpc()) { bTars[k] = false; }
						}
						if (i.find("fx[") != string::npos) {
							size_t l;
							if (i[4] == ']') {
								l = i[3] - '0';
							}
							else {
								l = 10 * (i[3] - '0') + (i[4] - '0');
							}
							if (!pCards[j].modsFx[l]) { bTars[k] = false; }
						}
						if (i.find("false") != string::npos) {
							bTars[k] = false;
						}
						if (i.find("!DEMON") != string::npos) {
							if (pCards[j].cRace == DEMON) { bTars[k] = false; }
						}
						if (i.find("role") != string::npos) {
							if (pCards[j].cRole != i[4] - '0') { bTars[k] = false; }
						}
						k++;
					}
				}
				for (int i = tars.size() - 1; i >= 0; i--) {
					if (!bTars[i]) { tars.erase(tars.begin() + i); placement.erase(placement.begin() + i); }
				}
			}
			if (pMods[mPlay].target[targs] == "") { //effects all tar
				tars2 = tars;
				placement2 = placement;
			}
			else {
				int loc;
				bool adjflag = false;
				if (pMods[mPlay].target[targs].find("ADJ") != string::npos) {
					adjflag = true;
				}
				if (pMods[mPlay].target[targs].find("OTHER") != string::npos) {
					for (int i = tars.size() - 1; i >= 0; i--) {
						if (tars[i] == cPlay) { tars.erase(tars.begin() + i); placement.erase(placement.begin() + i); }
					}
				}
				if (pMods[mPlay].target[targs].find("SELF") != string::npos) {
					if (adjflag) {
						if (pCards[cPlay].place == BOARD) {
							if (pCards[cPlay].placement > 0) {
								tars2.push_back(Player->board[pCards[cPlay].placement-1]);
								placement2.push_back(pCards[cPlay].placement-1);
							}
							if (pCards[cPlay].placement < Player->board.size() - 1) {
								tars2.push_back(Player->board[pCards[cPlay].placement + 1]);
								placement2.push_back(pCards[cPlay].placement + 1);
							}
						}
						else if (pCards[cPlay].place == HAND) {
							if (pCards[cPlay].placement > 0) {
								tars2.push_back(Player->hand[pCards[cPlay].placement - 1]);
								placement2.push_back(pCards[cPlay].placement - 1);
							}
							if (pCards[cPlay].placement < Player->hand.size() - 1) {
								tars2.push_back(Player->hand[pCards[cPlay].placement + 1]);
								placement2.push_back(pCards[cPlay].placement + 1);
							}
						}
					}
					else {
						tars2.push_back(pMods[mPlay].targ);
						placement2.push_back(pCards[cPlay].placement);
					}
				}
				else if (pMods[mPlay].target[targs].find("TAR") != string::npos) {
					//tars2 = tars2 from targs X where X is next character, e.g. TAR3 is third tars2 from start;
					if (adjflag) {
						size_t j = pMods[mPlay].target[targs][3] - '0';
						if (pCards[vTars[j][0]].side == Player->side) {
							if (Player->board[vPlacement[j][0]] == vTars[j][0]) {
								if (vPlacement[j][0] > 0) {
									tars2.push_back(Player->board[vPlacement[j][0] - 1]);
									placement2.push_back(vPlacement[j][0] - 1);
								}
								if (vPlacement[j][0] < Player->board.size() - 1) {
									tars2.push_back(Player->board[vPlacement[j][0] + 1]);
									placement2.push_back(vPlacement[j][0] + 1);
								}
							}
						}
						else {
							if (Player->Ogame->board[vPlacement[j][0]] == vTars[j][0]) {
								if (k > 0) {
									tars2.push_back(Player->Ogame->board[vPlacement[j][0] - 1]);
									placement2.push_back(vPlacement[j][0] - 1);
								}
								if (k < Player->Ogame->board.size() - 1) {
									tars2.push_back(Player->Ogame->board[vPlacement[j][0] + 1]);
									placement2.push_back(vPlacement[j][0] + 1);
								}
							}
						}
					}
					else {
						size_t j = pMods[mPlay].target[targs][3] - '0';
						tars2 = vTars[j];
						placement2 = vPlacement[j];
					}
				}
				else if (pMods[mPlay].target[targs].find("CHO") != string::npos) {
					if (tars.size() == 0) {
						if (pCards[cPlay].cType == SPELL) {
							return false; //for when spells require a target? other things shouldn't return false? but aoe's with no target should still fire??
						} //not actually sure this is always a fail
						else {
							continue; //skips to next targ if battlecry needs to cho ?
						}
					}
					int count = tars.size();
					int choice = rand() % count; //player choice
					if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
					currNode.currMoves.push_back(choice);
					if (adjflag) {
						if (pCards[tars[choice]].side == Player->side) {
							for (int j = 0; j < Player->board.size(); j++) {
								if (Player->board[j] == tars[choice]) {
									if (j > 0) {
										tars2.push_back(Player->board[j - 1]);
										placement2.push_back(j - 1);
									}
									if (j < Player->board.size() - 1) {
										tars2.push_back(Player->board[j + 1]);
										placement2.push_back(j + 1);
									}
								}
							}
						}
						else {
							for (int j = 0; j < Player->Ogame->board.size(); j++) {
								if (Player->Ogame->board[j] == tars[choice]) {
									if (j > 0) {
										tars2.push_back(Player->Ogame->board[j - 1]);
										placement2.push_back(j - 1);
									}
									if (j < Player->Ogame->board.size() - 1) {
										tars2.push_back(Player->Ogame->board[j + 1]);
										placement2.push_back(j + 1);
									}
								}
							}
						}
					}
					else {
						if (pCards[cPlay].cType == SPELL) {
							play->cTarget = tars[choice];
							checkTrig(play, "HEXES");
							tars[choice] = play->cTarget; //exclusively needed for retarget //but then placement is wrong TODO
						}
						tars2.push_back(tars[choice]);
						placement2.push_back(placement[choice]);
					}
				}
				else if ( (loc = pMods[mPlay].target[targs].find("RND")) != string::npos) {
					int pre = 1;
					if (loc == 1) { pre = pMods[mPlay].target[targs][0] - '0'; }
					else if (loc == 2) { pre = 10 * (pMods[mPlay].target[targs][0] - '0') + (pMods[mPlay].target[targs][1] - '0'); }
					for (pre; pre > 0; pre--) {	//random in game
						int suff = 1;
						int count = tars.size();
						if (isdigit(pMods[mPlay].target[targs][pMods[mPlay].target[targs].length() - 1])) { suff = pMods[mPlay].target[targs][pMods[mPlay].target[targs].length() - 1] - '0'; }
						vector<int> tempTars;
						bool flag;
						while (suff > 0 && tempTars.size() < count) {
							int choice = (rand() % count);
							if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(choice);
							flag = true;
							for (size_t i = 0; i < tempTars.size(); i++) { if (tempTars[i] == choice) { flag = false; } }
							if (flag) {
								tars2.push_back(tars[choice]);
								placement2.push_back(placement[choice]);
								tempTars.push_back(choice);
								suff--;
							}
						}
					}
				}
				else if (pMods[mPlay].target[targs].find("UNIQUE") != string::npos) {
					for (int j = 0; j < tars.size(); j++) {
						bool uFlag = true;
						for (auto k : tars2) {
							if (k == tars[j]) { uFlag = false; }
						}
						if (uFlag) { tars2.push_back(tars[j]); placement2.push_back(placement[j]); }
					}
				}
				else if (pMods[mPlay].target[targs].find("HERO") != string::npos) {
					if (pMods[mPlay].target[targs][4] == '1') { tars2.push_back(AGame.hero);  placement2.push_back(-100); }
					if (pMods[mPlay].target[targs][4] == '2') { tars2.push_back(BGame.hero); placement2.push_back(-100); }
					if (pMods[mPlay].target[targs][0] == 'P') { tars2.push_back(Player->hero); placement2.push_back(-1); }
					if (pMods[mPlay].target[targs][0] == 'O') { tars2.push_back(Player->Ogame->hero); placement2.push_back(-11); }
				}
				else if (pMods[mPlay].target[targs].find("CTHUN") != string::npos) { //todo placement
					if (pMods[mPlay].target[targs][5] == '1') { tars2.push_back(AGame.cthun); placement2.push_back(-6);}
					if (pMods[mPlay].target[targs][5] == '2') { tars2.push_back(BGame.cthun); placement2.push_back(-6);}
					if (pMods[mPlay].target[targs][0] == 'P') { tars2.push_back(Player->cthun); placement2.push_back(-66);}
					if (pMods[mPlay].target[targs][0] == 'O') { tars2.push_back(Player->Ogame->cthun); placement2.push_back(-666);}
				}
				stringstream ss(pMods[mPlay].target[targs]); int test;
				if (ss >> test && !(ss >> pMods[mPlay].target[targs])) {
					if (stoi(pMods[mPlay].target[targs]) > 0 && stoi(pMods[mPlay].target[targs]) < pCards.size()) {
						size_t sCard = stoi(pMods[mPlay].target[targs]);
						tars2.push_back(sCard);
						placement2.push_back(-33);
					}
				}
				if (tars2.size() == 0) {
					tars2 = tars;
					placement2 = placement;
				}
			}
			tarNum = tars2.size();
			vTars[targs + 1] = tars2;
			vPlacement[targs + 1] = placement2;
			playInfo play; play.cPlay = cPlay;
			for (size_t i = 0; i < tars2.size(); i++) {
				changeFlags.push_back(i);
				Effect afx;
				size_t cTarget = tars2[i];
				play.cTarget = cTarget;
				afx.targ = cTarget;
				afx.fx = MOD;
				if (trig == AURA) { afx.master = mPlay; }
				bool modded = false;
				if (timeFlag < 0) { //what is timeflag
					modded = true;
					afx.fx = TURNPOINT;
					afx.prearg.push_back(pMods[mPlay].prearg[targs]);
					afx.postarg.push_back(pMods[mPlay].postarg[targs]);
					afx.cTarAr.push_back(pMods[mPlay].cTarAr[targs]);
					afx.cTarTy.push_back(pMods[mPlay].cTarTy[targs]);
					afx.target.push_back(pMods[mPlay].target[targs]);
					afx.effect.push_back(pMods[mPlay].effect[targs]);
					afx.timer = timeFlag;
				}
				else {
					for (auto j : pMods[mPlay].effect[targs]) {
						//if (historyData.back().to1 == "X") {
						//	historyData.back().to2.push_back(placement2[i]);
						//}
						if (j == "") { 
							continue; 
						} //skip this lot vvv if no effect
						else if (j.find("randEff(") != string::npos) {
							size_t temp1 = 8, temp2 = 0, temp3;
							vector<string> effects;
							while (true) {
								temp2 = j.find(",",temp1);
								if (temp2 != string::npos) {
									effects.push_back(j.substr(temp1, temp2 - temp1)); //todo test this
									temp1 = temp2+1;
								}
								else {
									effects.push_back(j.substr(temp1, j.length() - temp1 - 1));
									break;
								}
							}
							temp3 = rand() % effects.size();
							if (moveSet != -1 && cMove < skipSet) { temp3 = moveSort[moveSet][cMove++]; }
							currNode.currMoves.push_back(temp3);
							j = effects[temp3];
						}
						else if (j == "destroy") {
							pCards[cTarget].hpc = 0 - pCards[cTarget].mods[2];
						}
						else if (j.find("trigger(")!=string::npos) {
							size_t fxID;
							if (j[9] = ')') {fxID = j[8] - '0'; }
							else { fxID = 10 * (j[8] - '0') + (j[9] - '0'); }
							for (auto k : pCards[cTarget].cMods[fxID]) { 
								//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = 88; //fill historydata with card about to play
								//historyData.push_back(hPlay);
								//historyData.back().to1 = "X";
								affect(fxID, k, &play); 
							}
						}
						else if (j == "silence") {
							for (int k = 0; k < FXCOUNT; k++) {
								if (k == TRIGGER) { for (int l = triggers.size()-1; l >= 0; l--) { if (pMods[triggers[l]].targ == cTarget) { triggers.erase(triggers.begin() + l); } } }
								if (k == TURNPOINT) { for (int l = turnpoints.size()-1; l >= 0; l--) { if (pMods[turnpoints[l]].targ == cTarget) { turnpoints.erase(turnpoints.begin() + l); } } }
								if (k == AURA) {
									for (int l = auras.size()-1; l >= 0; l--) { if (pMods[auras[l]].targ == cTarget) { auras.erase(auras.begin() + l); } }
									for (int m = pCards[cTarget].cMods[k].size()-1; m >= 0; m--) {
										if (pMods[m].master == 0) { pCards[cTarget].cMods[k].erase(pCards[cTarget].cMods[k].begin() + m); }
									}
								}
								else { pCards[cTarget].cMods[k].clear(); }
							}
						}
						else if (j == "absorb") {
							pCards[cPlay].atk += pCards[cTarget].getAtk();
							pCards[cPlay].hpm += pCards[cTarget].getHpc();
							pCards[cPlay].hpc += pCards[cTarget].getHpc();
							pCards[cTarget].hpc = 0 - pCards[cTarget].mods[2];
						}
						else if (j.find("put(") != string::npos) { //TODO remove triggers auras if moved
							int place = -1, placement = -1;
							if (j.find("PHAND") != string::npos) {
								if (Player->hand.size() < 10) {
									Player->hand.push_back(cTarget);
									pCards[cTarget].side = Player->side;
									place = HAND;
									placement = Player->hand.size() - 1;
									placeActivity[Player->side + 1] = true;
								}
							}
							else if (j.find("PBOARD") != string::npos) {
								if (pCards[cTarget].cType == SECRET) {
									if (Player->secrets.size() < 5) {
										Player->secrets.push_back(cTarget);
										pCards[cTarget].side = Player->side;
										place = BOARD;
										placement = Player->board.size() - 1;
										placeActivity[Player->side - 1] = true;
									}
								}
								else {
									if (Player->board.size() < 7) {
										Player->board.push_back(cTarget);
										pCards[cTarget].side = Player->side;
										place = BOARD;
										placement = Player->board.size() - 1;
										placeActivity[Player->side - 1] = true;
									}
								}
							}
							else if (j == "HAND") {
								if (pCards[cTarget].side == Player->side) {
									if (Player->hand.size() < 10) {
										Player->hand.push_back(cTarget);
										pCards[cTarget].side = Player->side;
										place = HAND;
										placement = Player->hand.size() - 1;
										placeActivity[Player->side + 1] = true;
										for (int k = 0; k < Player->board.size(); k++) {
											if (Player->board[k] == cTarget) { Player->board.erase(Player->board.begin() + k); placeActivity[Player->side - 1] = true; }
										}
									}
								}
								else {
									if (Player->Ogame->hand.size() < 10) {
										Player->Ogame->hand.push_back(cTarget);
										pCards[cTarget].side = Player->Ogame->side;
										place = HAND;
										placement = Player->Ogame->hand.size() - 1;
										placeActivity[Player->Ogame->side + 1] = true;
										for (int k = 0; k < Player->Ogame->board.size(); k++) {
											if (Player->Ogame->board[k] == cTarget) { Player->Ogame->board.erase(Player->Ogame->board.begin() + k); placeActivity[Player->Ogame->side - 1] = true; }
										}
									}
								}
							}
							bool flipFlag2 = false;
							if (pCards[cTarget].side == Player->side) {}
							else { Player = Player->Ogame; flipFlag2 = true; }
							if (pCards[cTarget].cType == SECRET) { for (int k = 0; k < Player->secrets.size(); k++) { if (Player->secrets[k] == cTarget) { Player->secrets.erase(Player->secrets.begin() + k); placeActivity[Player->side - 1] = true; break; } } }
							else if (pCards[cTarget].place == BOARD) { for (int k = 0; k < Player->board.size(); k++) { if (Player->board[k] == cTarget) { Player->board.erase(Player->board.begin() + k); placeActivity[Player->side - 1] = true; break; } } }
							else if (pCards[cTarget].place == HAND) { for (int k = 0; k < Player->hand.size(); k++) { if (Player->hand[k] == cTarget) { Player->hand.erase(Player->hand.begin() + k); placeActivity[Player->side + 1] = true; break; } } }
							else if (pCards[cTarget].place == DECK) { for (int k = 0; k < Player->deck.size(); k++) { if (Player->deck[k] == cTarget) { Player->deck.erase(Player->deck.begin() + k); break; } } }
							else if (pCards[cTarget].place == GRAVEYARD) { for (int k = 0; k < Player->grave.size(); k++) { if (Player->grave[k] == cTarget) { Player->grave.erase(Player->grave.begin() + k); break; } } }
							if (flipFlag2) { Player = Player->Ogame; }
							pCards[cTarget].place = place;
						}
						else if (j == "globID") {
							globID = cTarget;
						}
						else if (j.find("swap(") != string::npos) {
							if (j.find("PHAND") != string::npos) {
								size_t src, dest, temp;
								for (int k = 0; k < Player->board.size(); k++) {
									if (Player->board[k] == cTarget) { src = k; break; }
								}
								bool optn = false;
								for (auto l : Player->hand) { if (pCards[l].cType == MINION) { optn = true; } }
								if (optn) {
									while (true) { //todo what if no minions
										dest = rand() % Player->hand.size();
										if (moveSet != -1 && cMove < skipSet) { dest = moveSort[moveSet][cMove++]; }
										currNode.currMoves.push_back(dest);
										if (pCards[Player->hand[dest]].cType == MINION) { break; }
									}
									Player->board[src] = Player->hand[dest];
									Player->hand[dest] = cTarget;
									temp = pCards[Player->board[src]].placement;
									pCards[Player->board[src]].place = BOARD;
									pCards[cTarget].place = HAND;
									pCards[Player->board[src]].placement = pCards[cTarget].placement;
									pCards[cTarget].placement = temp;
									deactivateCard(pCards[cTarget]);
									activateCard(pCards[Player->board[src]]);
									placeActivity[Player->side + 1] = true;
									placeActivity[Player->side - 1] = true;
								}
							}
						}
						else if (j.find("copy(") != string::npos) {
							if (j.find("PHAND") != string::npos) {
								if (Player->hand.size() < 10) {
									string name = pCards[cTarget].name; size_t sCard;
									for (size_t k = 0; k < Cards.size(); k++) {
										if (Cards[k].name == name) { sCard = k; break; }
									}
									importCard(Cards[sCard]);
									Player->hand.push_back(pCards.size() - 1);
									pCards.back().side = Player->side;
									pCards.back().place = HAND;
									pCards.back().placement = Player->hand.size() - 1;
									placeActivity[Player->side + 1] = true;
								}
							}
							else if (j.find("PBOARD") != string::npos) {
								string name = pCards[cTarget].name; size_t sCard;
								for (size_t k = 0; k < Cards.size(); k++) {
									if (Cards[k].name == name) { sCard = k; break; }
								}
								importCard(Cards[sCard]);
								if (pCards[cTarget].cType == SECRET) { Player->secrets.push_back(pCards.size() - 1); pCards.back().side = Player->side; pCards.back().place = BOARD; }
								else if (pCards[cTarget].cType == HEROPWR) { pCards.back().side = Player->side; Player->hPwr = pCards.size()-1; }
								else {
									if (Player->board.size() < 7) {
										Player->board.push_back(pCards.size() - 1);
										pCards.back().side = Player->side;
										pCards.back().place = BOARD;
										pCards.back().placement = Player->board.size() - 1;
										placeActivity[Player->side - 1] = true;
									}
								}
							}
							if (j.find("1/1") != string::npos) {
								pCards.back().atk = 1; pCards.back().hpm = 1;
							}
						}
						else if (j.find("transform(") != string::npos) {
							if (j.find("role") != string::npos) {
								while (true) {
									int choice = rand() % Cards.size();
									if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
									currNode.currMoves.push_back(choice);
									Card test = Cards[choice];
									if (test.cRole == j[4] - '0') {
										test.side = pCards[cTarget].side;
										test.place = pCards[cTarget].place;
										test.placement = pCards[cTarget].placement;
										pCards[cTarget] = test;
										break;
									}
								}
							} //todo maybe role is in a card name?
							else {
								string name = j.substr(10, j.length() - 11);

								for (size_t k = 0; k < Cards.size(); k++) {
									if (Cards[k].name == name) {
										importCard(Cards[k]);
										Card test = pCards.back();
										test.side = pCards[cTarget].side;
										test.place = pCards[cTarget].place;
										test.placement = pCards[cTarget].placement;
										pCards[cTarget] = test;
										break;
									}
								}
							}
						}
						else if (j.find("hpc") != string::npos || j.find("hps") != string::npos) {
							if (j[3] == '-') {
								if (pCards[cTarget].modsFx[INVULNERABLE]) {}
								else if (pCards[cTarget].modsFx[DIVINESHIELD]) { pCards[cTarget].cMods[DIVINESHIELD].clear(); pCards[cTarget].modsFx[DIVINESHIELD] = false; } //divine shield //if hps?
								else {
									if (pCards[cTarget].cType == HERO) {
										pCards[cTarget].cost -= j[4] - '0';
										if (pCards[cTarget].cost < 0) { pCards[cTarget].hpc += pCards[cTarget].cost; pCards[cTarget].cost = 0; }
									}
									else {
										pCards[cTarget].hpc -= j[4] - '0';
									}
									checkTrig(&play, "DAMAGED");
								}
							}
							if (j[3] == '+') {
								if (pCards[cTarget].getHpc() == pCards[cTarget].getHpm()) {}
								else {
									pCards[cTarget].hpc += j[4] - '0';
									if (pCards[cTarget].hpc > pCards[cTarget].hpm) { 
										pCards[cTarget].hpc = pCards[cTarget].hpm;
									}
									checkTrig(&play, "HEALED");
								}
							}
						}
						else if (j.find("curse(") != string::npos) {
							afx = pMods[pCards[cPlay].cMods[CURSE].back()];
							afx.targ = cTarget;
							modded = true;
							if (j[7] == ')') {
								afx.fx = j[6] - '0';
							}
							else {
								afx.fx = 10 * (j[6] - '0') + (j[7] - '0');
							}
							for (int i = 0; i < afx.prearg[targs].size(); i++) {
								if (size_t j = afx.prearg[targs][i].find("#") != string::npos) {
									size_t k = afx.prearg[targs][i].find("#", j + 1);
									afx.prearg[targs][i].replace(j, k - j + 1, simplify(cPlay, afx.prearg[targs][i].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
								}
							}
							for (int i = 0; i < afx.postarg[targs].size(); i++) {
								if (size_t j = afx.postarg[targs][i].find("#") != string::npos) {
									size_t k = afx.postarg[targs][i].find("#", j + 1);
									afx.postarg[targs][i].replace(j, k - j + 1, simplify(cPlay, afx.postarg[targs][i].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
								}
							}
							if (size_t j = afx.target[targs].find("#") != string::npos) {
								size_t k = afx.target[targs].find("#", j + 1);
								afx.target[targs].replace(j, k - j + 1, simplify(cPlay, afx.target[targs].substr(j + 1, k - j - 1), &pHist)); //should replace everything between %% with a single number or true/false
							}
							for (int i = 0; i < afx.effect[targs].size(); i++) {
								if (size_t j = afx.effect[targs][i].find("#") != string::npos) {
									size_t k = afx.effect[targs][i].find("#", j + 1);
									afx.effect[targs][i].replace(j, k - j + 1, simplify(cPlay, afx.effect[targs][i].substr(j + 1, k - j - 1), &pHist));
								}
							}
						}
						if (j.find("hpm") != string::npos || j.find("hps") != string::npos) { //TODO check if hpc is more than hpm now?
							modded = true;
							if (j[3] == '+') { afx.mods[2] += j[4] - '0'; }
							if (j[3] == '*') { afx.mods[2] = (j[4] - '0' - 1) * pCards[cTarget].getHpm(); }
							if (j[3] == '-') { afx.mods[2] -= j[4] - '0'; }
							if (j[3] == '=') { afx.mods[2] = j[4] - '0' - pCards[cTarget].getHpm(); }
						}
						else if (j.find("atk") != string::npos) { //todo multiple digits?
							modded = true;
							if (j[3] == '+') { afx.mods[1] += j[4] - '0'; }
							if (j[3] == '*') { afx.mods[1] = (j[4] - '0' - 1) * pCards[cTarget].getAtk(); }
							if (j[3] == '-') { afx.mods[1] -= j[4] - '0'; }
							if (j[3] == '=') { afx.mods[1] = j[4] - '0' - pCards[cTarget].getAtk(); }
						}
						else if (j.find("cost") != string::npos) {
							modded = true;
							if (j[4] == '+') { afx.mods[0] += j[5] - '0'; }
							if (j[4] == '*') { afx.mods[0] = (j[5] - '0' - 1) * pCards[cTarget].getCost(); }
							if (j[4] == '-') { afx.mods[0] -= j[5] - '0'; }
							if (j[4] == '=') { afx.mods[0] = j[5] - '0' - pCards[cTarget].getCost(); }
						}
						else if (j.find("fx[") != string::npos) {
							size_t fxID;
							if (j[5] == '=') {
								fxID = j[3] - '0';
							}
							else { //double digit fx
								fxID = 10 * (j[3] - '0') + (j[4] - '0');
							}
							if (j.find("false") != string::npos) {
								modded = true;
								if (fxID == AURA) { deactivateCard(pCards[cTarget], 0); }
								else if (fxID == TRIGGER) { for (int l = triggers.size()-1; l >= 0; l--) { if (pMods[triggers[l]].targ == cTarget) { triggers.erase(triggers.begin() + l); } } }
								else if (fxID == TURNPOINT) { for (int l = turnpoints.size()-1; l >= 0; l--) { if (pMods[turnpoints[l]].targ == cTarget) { turnpoints.erase(turnpoints.begin() + l); } } }
								pCards[cTarget].cMods[fxID].clear();
							}
							else {
								Effect afx2;
								afx2.targ = cTarget;
								if (trig == AURA) { afx2.master = mPlay; }
								afx2.fx = fxID;
								pMods.push_back(afx2);
								if (trig == AURA) { pMods[mPlay].slaves.push_back(pMods.size() - 1); }
								pCards[cTarget].cMods[fxID].push_back(pMods.size() - 1);
							}
						}
					}
					if (timeFlag > 0) {
						afx.fx = TURNPOINT;
						afx.timer = timeFlag;
					}
				}
				if (modded) {
					if (unusedMod.size() > 0) {
						pMods[unusedMod.back()] = afx;
						if (trig == AURA) { pMods[mPlay].slaves.push_back(unusedMod.back()); }
						pCards[cTarget].cMods[afx.fx].push_back(unusedMod.back());
						unusedMod.pop_back();
					}
					else {
						pMods.push_back(afx);
						if (trig == AURA) { pMods[mPlay].slaves.push_back(pMods.size() - 1); }
						pCards[cTarget].cMods[afx.fx].push_back(pMods.size() - 1);
					}
					activateCard(pCards[cTarget]);
					flattenMod(cTarget);
				}
			}
		}
		if (tarNum == 1) {
			pHist.back().tar = tars2[0];
			pHist.back().atk = pCards[pHist.back().tar].atk;
			pHist.back().cost = pCards[pHist.back().tar].cost;
			pHist.back().hpc = pCards[pHist.back().tar].hpc;
			pHist.back().hpm = pCards[pHist.back().tar].hpm;
		}
		pHist.back().tarNum = tarNum;
		if (pCards[cPlay].cType == SPELL) {
			checkTrig(play, "HEXED");
		}
		if (trig == CHOOSEONE) { targs++; }
		if (trig == COMBO) { targs++; }
		if (duelFlag) { targs++; }
		if (ifeFlag) { targs++; }
	}
	for (int i = 0; i < stringPlaceVec.size(); i++) {
		if (stringPlaceVec[i] == 0) { pMods[mPlay].prearg[stringPlaceTargs[i]][stringPlacei[i]] = tempStrings[i]; }
		if (stringPlaceVec[i] == 1) { pMods[mPlay].postarg[stringPlaceTargs[i]][stringPlacei[i]] = tempStrings[i]; }
		if (stringPlaceVec[i] == 2) { pMods[mPlay].target[stringPlaceTargs[i]] = tempStrings[i]; }
		if (stringPlaceVec[i] == 3) { pMods[mPlay].effect[stringPlaceTargs[i]][stringPlacei[i]] = tempStrings[i]; }
	}
	if (swapflag) { Player = Player->Ogame; }
	return true;
}

void activateCard(Card temp) { //TODO what if only need to activate one effect
	bool trig = false, aura = false, tpoint = false; 
	if (temp.cMods[AURA].size()>0) {
		for (auto j : temp.cMods[AURA]) {
			if (temp.place == BOARD) { //todo maybe if ~H~ dont aura while on board
				aura = true;
			}
			else if (temp.place == HAND) {
				if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
					aura = true;
				}
			}
			else if (temp.place == DECK) {
				if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
					aura = true;
				}
			}
		}
	}
	if (temp.cMods[TRIGGER].size()>0) {
		for (auto j : temp.cMods[TRIGGER]) {
			if (temp.place == BOARD) {
				trig = true;
			}
			else if (temp.place == HAND) {
				if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
					trig = true;
				}
			}
			else if (temp.place == DECK) {
				if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
					trig = true;
				}
			}
		}
	}
	if (temp.cMods[TURNPOINT].size()>0) {
		for (auto j : temp.cMods[TURNPOINT]) {
			if (temp.place == BOARD) {
				tpoint = true;
			}
			else if (temp.place == HAND) {
				if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
					tpoint = true;
				}
			}
			else if (temp.place == DECK) {
				if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
					tpoint = true;
				}
			}
		}
	}
	if (trig) {
		for (auto j : temp.cMods[TRIGGER]) {
			bool already = false;
			for (auto k : triggers) {
				if (k == j) { already = true; break; }
			}
			if (!already) { triggers.push_back(j); }
		}
	}
	if (tpoint) {
		for (auto j : temp.cMods[TURNPOINT]) {
			bool already = false;
			for (auto k : turnpoints) {
				if (k == j) { already = true; break; }
			}
			if (!already) { turnpoints.push_back(j); }
		}
	}
	if (aura) {
		for (auto j : temp.cMods[AURA]) {
			bool already = false;
			for (auto k : auras) {
				if (k == j) { already = true; break; }
			}
			if (!already) { auras.push_back(j); }
		}
	}
}

void deactivateCard(Card temp, int x) { //-1 default, 0,1,2, 3 is death
	bool trig = false, aura = false, tpoint = false;
	if (x == -1) {
		if (temp.cMods[AURA].size() > 0) {
			for (auto j : temp.cMods[AURA]) {
				if (temp.place == BOARD) { //todo maybe if ~H~ dont aura while on board
					aura = true;
				}
				else if (temp.place == HAND) {
					if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
						aura = true;
					}
				}
				else if (temp.place == DECK) {
					if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
						aura = true;
					}
				}
			}
		}
		if (temp.cMods[TRIGGER].size() > 0) {
			for (auto j : temp.cMods[TRIGGER]) {
				if (temp.place == BOARD) {
					trig = true;
				}
				else if (temp.place == HAND) {
					if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
						trig = true;
					}
				}
				else if (temp.place == DECK) {
					if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
						trig = true;
					}
				}
			}
		}
		if (temp.cMods[TURNPOINT].size() > 0) {
			for (auto j : temp.cMods[TURNPOINT]) {
				if (temp.place == BOARD) {
					tpoint = true;
				}
				else if (temp.place == HAND) {
					if (pMods[j].prearg[0][0].find("~H~") != string::npos) {
						tpoint = true;
					}
				}
				else if (temp.place == DECK) {
					if (pMods[j].prearg[0][0].find("~D~") != string::npos) {
						tpoint = true;
					}
				}
			}
		}
	}
	else {
		if (x == 0) {
			aura = false;
			trig = true;
			tpoint = true;
		}
		if (x == 1) {
			aura = true;
			trig = false;
			tpoint = true;
		}
		if (x == 2) {
			aura = true;
			trig = true;
			tpoint = false;
		}
		if (x == 3) {
			aura = false;
			trig = false;
			tpoint = false;
		}
	}
	if (!aura) {
		for (auto j : temp.cMods[AURA]) {
			bool already = false;
			for (int k = 0; k < auras.size(); k++) {
				if (auras[k] == j) { auras.erase(auras.begin() + k); removeAura(j); already = true; break; }
			}
			if (!already) { cout << "error" << endl; } //should happen when not master aura i think?
		}
	}
	if (!trig) {
		for (auto j : temp.cMods[TRIGGER]) {
			bool already = false;
			for (int k = 0; k < triggers.size(); k++) {
				if (triggers[k] == j) { triggers.erase(triggers.begin() + k); already = true; break; }
			}
			if (!already) { cout << "error" << endl; }
		}
	}
	if (!tpoint) {
		for (auto j : temp.cMods[TURNPOINT]) {
			bool already = false;
			for (int k = 0; k < turnpoints.size(); k++) {
				if (turnpoints[k] == j) { turnpoints.erase(turnpoints.begin() + k); already = true; break; }
			}
			if (!already) { 
				cout << "error" << endl; 
			}
		}
	}
}

bool play(size_t cPlay) {
	cout << "Playing " + pCards[cPlay].name << endl;
	playInfo play; play.cPlay = cPlay; play.cTarget = -1 * Player->side; currPlay = play;
	if (pCards[cPlay].place == HAND) { //playing card from hand
		if (pCards[cPlay].cType == MINION) {
			if (Player->board.size() == 7) { 
				cout << "Board too big for " + pCards[cPlay].name << endl; 
				//historyData.pop_back(); 
				return false; 
			}
			int placement = rand() % (Player->board.size() + 1); //choice
			if (moveSet != -1 && cMove < skipSet) { placement = moveSort[moveSet][cMove++]; }
			currNode.currMoves.push_back(placement);
			cout << "Placement " << placement << endl;
			historyData.back().to2.push_back(placement);
			historyData.back().to1 = "X";
			pCards[cPlay].playNum = ++playNum;
			pCards[cPlay].place = BOARD;
			pCards[cPlay].placement = placement;
			if (placement == Player->board.size()) { Player->board.push_back(cPlay); }
			else { Player->board.insert(Player->board.begin() + placement, cPlay); }
			placeActivity[Player->side - 1] = true;

			for (auto i : pCards[cPlay].cMods[BATTLECRY]) {
				affect(BATTLECRY, i, &play);
			}//activate battlecry

			checkTrig(&play, "SUMMON");

			for (auto i : pCards[cPlay].cMods[CHOOSEONE]) {
				affect(CHOOSEONE, i, &play);
			}
			historyData.back().to1 = Places[BOARD];
			if (pCards[cPlay].modsFx[CHARGE]) {
				pCards[cPlay].ready++;
			}//activate charge
			if (pCards[cPlay].modsFx[OVERLOAD]) {
				for (auto i : pCards[cPlay].cMods[OVERLOAD]) {
					Player->o1Mana += pMods[i].prearg[0][0][0] - '0';
				}
			}//add overload
		}
		else if (pCards[cPlay].cType == SPELL) {
			//historyData.back().to1 = "X";
			for (auto i : pCards[cPlay].cMods[BATTLECRY]) {
				if (!affect(BATTLECRY, i, &play)) {
					cout << "no targets" << endl; 
					//historyData.pop_back(); 
					return false;
				};
			}
			pCards[cPlay].place = GRAVEYARD;
			//historyData.back().to1 = Places[BOARD];
		}
		else if (pCards[cPlay].cType == SECRET) {
			if (Player->secrets.size() < 5) {
				checkTrig(&play, "HEXES");
				pCards[cPlay].playNum = ++playNum; Player->secrets.push_back(cPlay);
				pCards[cPlay].place = BOARD;
				//historyData.back().to1 = Places[BOARD];
				//historyData.back().to2.push_back(0 - Player->side);
				checkTrig(&play, "HEXED");
			}
			else { 
				historyData.pop_back(); 
				return false; }
		}
		else if (pCards[cPlay].cType == WEAPON) {
			pCards[cPlay].playNum = ++playNum;
			Player->weapon = cPlay;
			pCards[cPlay].place = BOARD;
			//historyData.back().to1 = Places[BOARD];
			//historyData.back().to2.push_back(0 - Player->side);
			checkTrig(&play, "EQUIP");
		}
		for (size_t i = 0; i < Player->hand.size(); i++) {
			if (Player->hand[i] == cPlay) { Player->hand.erase(Player->hand.begin() + i); i--; placeActivity[Player->side + 1] = true; }
			else { pCards[Player->hand[i]].placement = i; }
		}
		Player->cMana -= pCards[cPlay].cost;
		activateCard(pCards[cPlay]);
		checkTrig(&play, "PLAYED");
	}
	else if (pCards[cPlay].cType == HEROPWR) { //hero power
		if (Player->pwrCost > Player->cMana) { 
			//historyData.pop_back(); 
			return false; }
		//historyData.back().to1 = "X";
		for (auto i : pCards[cPlay].cMods[BATTLECRY]) {
			affect(BATTLECRY, i, &play);
		}
		if (!Player->HeroFury) { Player->pReady--; }
		Player->cMana -= Player->pwrCost;
		//historyData.back().to1 = Places[BOARD];
		for (auto i : Player->board) { for (auto j : pCards[i].cMods[INSPIRE]) { affect(INSPIRE, j, &play); } }
		for (auto i : pCards[Player->weapon].cMods[INSPIRE]) { affect(INSPIRE, i, &play); }
	}
	else {
		vector<size_t> tars;
		vector<int> placement;
		for (size_t i = 0; i < Player->Ogame->board.size(); i++) {
			if (pCards[Player->Ogame->board[i]].modsFx[11]) { tars.push_back(Player->Ogame->board[i]); placement.push_back(i); }
		}
		if (tars.size() == 0) {
			tars.push_back(Player->Ogame->hero);
			placement.push_back(0 - Player->Ogame->side);
			for (size_t i = 0; i < Player->Ogame->board.size(); i++) {
				if (!pCards[Player->Ogame->board[i]].modsFx[10]) {
					tars.push_back(Player->Ogame->board[i]);
					placement.push_back(i);
				}
			}
		}
		int choice = rand() % tars.size(); //player choice
		int chance = rand() % 100;
		if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; }
		currNode.currMoves.push_back(choice);
		if (moveSet != -1 && cMove < skipSet) { chance = moveSort[moveSet][cMove++]; }
		currNode.currMoves.push_back(chance);
		if (pCards[cPlay].modsFx[CONFUSED]) { int chance2 = stoi(pMods[pCards[cPlay].cMods[CONFUSED][0]].prearg[0][0]); if (chance < chance2) { choice = rand() % tars.size(); if (moveSet != -1 && cMove < skipSet) { choice = moveSort[moveSet][cMove++]; } currNode.currMoves.push_back(choice);
		} }
		playInfo play2; play.cTarget = tars[choice]; currPlay = play;
		play2.cPlay = tars[choice]; play2.cTarget = cPlay; play.cDam = pCards[cPlay].getAtk(); play2.cDam = pCards[tars[choice]].getAtk();
		if (pCards[cPlay].modsFx[5] || pCards[cPlay].getAtk() <= 0 || pCards[cPlay].ready == 0) { 
			//historyData.pop_back(); 
			return false; } //frozen or no atk or already attacked
		checkTrig(&play, "ATTACKS");
		if (pCards[tars[choice]].cType == HERO) { //attacking hero
			pCards[Player->Ogame->hero].cost -= pCards[cPlay].getAtk(); //hits armr
			if (pCards[Player->Ogame->hero].cost < 0) { pCards[Player->Ogame->hero].hpc += pCards[Player->Ogame->hero].cost; pCards[Player->Ogame->hero].cost = 0; checkTrig(&play, "DAMAGES"); } //if neg armr hurts health //TODO trigger damages
		}
		else {
			if (pCards[cPlay].modsFx[INVULNERABLE]) {}
			else if (pCards[cPlay].cType == HERO) {
				pCards[Player->hero].cost -= pCards[tars[choice]].getAtk();
				if (pCards[Player->hero].cost < 0) { pCards[Player->hero].hpc += pCards[Player->hero].cost; pCards[Player->hero].cost = 0; checkTrig(&play2, "DAMAGES"); }
			}
			else {
				if (pCards[cPlay].modsFx[DIVINESHIELD]) { if (pCards[tars[choice]].getAtk() > 0) { 
					pCards[cPlay].modsFx[DIVINESHIELD] = false; 
					pCards[cPlay].cMods[DIVINESHIELD].clear();
				} } //divine shield conditions
				else { 
					pCards[cPlay].hpc -= play2.cDam; if (play2.cDam > 0) { checkTrig(&play2, "DAMAGES"); }
					if (pCards[cPlay].getHpc() <= 0) { checkTrig(&play2, "KILLS"); }
				}
			}
			if (!pCards[tars[choice]].modsFx[DIVINESHIELD]) { 
				pCards[tars[choice]].hpc -= play.cDam; if (play.cDam > 0) { checkTrig(&play, "DAMAGES"); }
				if (pCards[tars[choice]].getHpc() <= 0) { checkTrig(&play, "KILLS"); }
			}
			else { 
				pCards[tars[choice]].modsFx[DIVINESHIELD] = false;
				pCards[tars[choice]].cMods[DIVINESHIELD].clear();
			} //divine shield
		}
		if (pCards[cPlay].cType == HERO) { pCards[Player->weapon].hpc--; } //loss of durability
		pCards[cPlay].ready--;
		//historyData.back().to1 = Places[BOARD];
		//historyData.back().to2.push_back(placement[choice]);
	}
	Player->comboflag = true;
	//InvalidateRect(globHwnd, NULL, FALSE);
	//UpdateWindow(globHwnd);
	return true;
}

int turnTr(int loc) {
	size_t cPlay;

	if (pCards[AGame.hero].hpc <= 0) { //check if Awin
		return 1;
	}
	if (pCards[BGame.hero].hpc <= 0) { //check if Bwin
		return 2;
	}

	if (loc == 0) { 		//turn start triggers;
		Player->comboflag = false;
		pCards[Player->hero].atk = 0;
		if (Player->mMana<10) { Player->mMana++; }
		Player->cMana = Player->mMana - Player->o2Mana;
		pCards[Player->hero].modsFx[WINDFURY] ? pCards[Player->hero].ready = 2 : pCards[Player->hero].ready = 1;
		Player->pReady = 1; //TODO check for that card that gives you multiple shots, might already be fixed during syncaura
		for (size_t i = 0; i < Player->board.size(); i++) {
			if (pCards[Player->board[i]].modsFx[WINDFURY]) { pCards[Player->board[i]].ready = 2; }
			else { pCards[Player->board[i]].ready = 1; }
		}
		vector<int> removes;
		for (int i = turnpoints.size() - 1; i >= 0; i--) {
			playInfo play; play.cPlay = pMods[turnpoints[i]].targ; play.cTarget = -1 * pCards[pMods[turnpoints[i]].targ].side;
			bool out = false;
			for (auto j : pMods[turnpoints[i]].prearg) {
				for (auto k : j) {
					if (k.find("time(S)")!=string::npos) {
						//playData hPlay; hPlay.name = pCards[pMods[turnpoints[i]].targ].name; hPlay.flavour = pCards[pMods[turnpoints[i]].targ].flavour; hPlay.side1 = pCards[pMods[turnpoints[i]].targ].side; hPlay.from1 = Places[pCards[pMods[turnpoints[i]].targ].place]; hPlay.from2 = 55; //fill historydata with card about to play
						//historyData.push_back(hPlay);
						//historyData.back().to1 = "X";
						affect(TURNPOINT, turnpoints[i], &play);
						out = true; break;
					}
					else if (k.find("time(PS)")!=string::npos && pCards[pMods[turnpoints[i]].targ].side == Player->side) {
						//playData hPlay; hPlay.name = pCards[pMods[turnpoints[i]].targ].name; hPlay.flavour = pCards[pMods[turnpoints[i]].targ].flavour; hPlay.side1 = pCards[pMods[turnpoints[i]].targ].side; hPlay.from1 = Places[pCards[pMods[turnpoints[i]].targ].place]; hPlay.from2 = 44; //fill historydata with card about to play
						//historyData.push_back(hPlay);
						//historyData.back().to1 = "X";
						affect(TURNPOINT, turnpoints[i], &play);
						out = true; break;
					}
				}
				if (out) { break; }
			}
			if (out) { continue; }
			if (pMods[turnpoints[i]].timer < 0) {
				pMods[turnpoints[i]].timer++;
				if (pMods[turnpoints[i]].timer == 0) {
					//playData hPlay; hPlay.name = pCards[pMods[turnpoints[i]].targ].name; hPlay.flavour = pCards[pMods[turnpoints[i]].targ].flavour; hPlay.side1 = pCards[pMods[turnpoints[i]].targ].side; hPlay.from1 = Places[pCards[pMods[turnpoints[i]].targ].place]; hPlay.from2 = 33; //fill historydata with card about to play
					//historyData.push_back(hPlay);
					//historyData.back().to1 = "X";
					affect(TURNPOINT, turnpoints[i], &play);
					for (int j = 0; j < FXCOUNT; j++) {
						for (int k = 0; k < pCards[pMods[turnpoints[i]].targ].cMods[j].size(); k++) {
							if (pCards[pMods[turnpoints[i]].targ].cMods[j][k] == turnpoints[i]) { pCards[pMods[turnpoints[i]].targ].cMods[j].erase(pCards[pMods[turnpoints[i]].targ].cMods[j].begin() + k); }; //ridiculously complex way to do this jfc
						}
					}
					turnpoints.erase(turnpoints.begin() + i);
					continue;
				}
			}
			if (pMods[turnpoints[i]].timer > 0) {
				pMods[turnpoints[i]].timer--;
				if (pMods[turnpoints[i]].timer == 0) {
					for (int j = 0; j < FXCOUNT; j++) {
						for (int k = 0; k < pCards[pMods[turnpoints[i]].targ].cMods[j].size(); k++) {
							if (pCards[pMods[turnpoints[i]].targ].cMods[j][k] == turnpoints[i]) { pCards[pMods[turnpoints[i]].targ].cMods[j].erase( pCards[pMods[turnpoints[i]].targ].cMods[j].begin() + k); }; //ridiculously complex way to do this jfc
						}
					}
					turnpoints.erase(turnpoints.begin() + i);
					continue;
				}
			}
		}
	}

	if (loc == 1) { //after play triggers
		cout << "nothing" << endl;
	}

	if (loc == 2) { 		//turn end triggers;
		for (auto i : turnpoints) {
			playInfo play; play.cPlay = pMods[i].targ; play.cTarget = -1 * pCards[pMods[i].targ].side;
			for (auto j : pMods[i].prearg) {
				for (auto k : j) {
					if (k.find("time(E)") != string::npos) {
						//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = 88; //fill historydata with card about to play
						//historyData.push_back(hPlay);
						//historyData.back().to1 = "X";
						affect(TURNPOINT, i, &play);
					}
					else if (k.find("time(PE)") != string::npos && pCards[pMods[i].targ].side == Player->side) {
						//playData hPlay; hPlay.name = pCards[pMods[i].targ].name; hPlay.flavour = pCards[pMods[i].targ].flavour; hPlay.side1 = pCards[pMods[i].targ].side; hPlay.from1 = Places[pCards[pMods[i].targ].place]; hPlay.from2 = 88; //fill historydata with card about to play
						//historyData.push_back(hPlay);
						//historyData.back().to1 = "X";
						affect(TURNPOINT, i, &play);
					}
				}
			}
		}
		for (size_t i = 0; i < Player->board.size(); i++) {
			if (pCards[Player->board[i]].modsFx[FROZEN] && pCards[Player->board[i]].ready > 0) { pCards[Player->board[i]].modsFx[FROZEN] = false; pCards[Player->board[i]].cMods[FROZEN].clear(); } //TODO don't think this is how frozen stops, also hero
		}
		Player->o2Mana = Player->o1Mana;
		Player->o1Mana = 0;
	}
	checkDead();
	return 0;
}

vector<size_t> draw(int n, GameSpace *Player) {
	vector<size_t> crds;
	for (int i = 0; i < n; i++) {
		if (Player->deck.empty()) {
			if (!pCards[Player->hero].modsFx[INVULNERABLE]) { pCards[Player->hero].hpc -= Player->fatigue; }
			Player->fatigue++;
		}
		else {
			crds.push_back(Player->deck.back());
			if (Player->hand.size() < 10) {
				Player->hand.push_back(Player->deck.back());
				pCards[Player->hand.back()].placement = Player->hand.size() - 1;
				pCards[Player->hand.back()].place = HAND;
				placeActivity[Player->side + 1] = true;
				Player->deck.pop_back();
				playInfo play; play.cPlay = Player->hand.back(); play.cTarget = -1 * Player->side;
				checkTrig(&play, "DRAW");
				activateCard(pCards[Player->hand.back()]);
			}
			else {
				Player->grave.push_back(Player->deck.back());
				pCards[Player->grave.back()].place = GRAVEYARD;
				Player->deck.pop_back();
			}
		}
	}
	return crds;
}