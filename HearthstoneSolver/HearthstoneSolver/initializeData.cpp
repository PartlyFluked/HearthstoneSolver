#include "initializeData.h"

using namespace std;

vector<Card> Cards;
vector<Card> pCards;

vector<string> cGroups[GROUPSIZE] = {	{ "Totem1","Healing_Totem","Searing_Totem","Wrath_of_Air_Totem","Stoneclaw_Totem" },
								{ "Totem2","Healing_Totem","Searing_Totem","Wrath_of_Air_Totem","Stoneclaw_Totem" },
								{ "Spare_Part","Armor_Plating", "Emergency_Coolant", "Finicky_Cloakfield", "Reversing_Switch", "Rusty_Horn", "Time_Rewinder", "Whirling_Blades" },
								{ "HEROPWR","Shapeshift","Steady_Shot","Fireblast","Reinforce","Lesser_Heal","Dagger_Mastery","Totemic_Call","Life_Tap","Armor_Up"}
};

GameSpace AGame;
GameSpace BGame;

vector<playData> historyData;
vector<Effect> Mods;
vector<Effect> pMods;
vector<size_t> unusedMod;
vector<size_t> triggers; //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
vector<size_t> turnpoints;
vector<size_t> auras;

int  Card::getAtk(void) {
	if (cType == HERO) {
		if (side == 1) { return atk + mods[1] + pCards[AGame.weapon].atk + pCards[AGame.weapon].mods[1]; }
		else { return atk + mods[1] + pCards[BGame.weapon].atk + pCards[BGame.weapon].mods[1]; }
	}
	else { return atk + mods[1]; }
}

Card temp;

void initCard(Card *xyz, string name, string id, string rarity, bool collect, size_t type, int cost, int atk, int hp, string flavour, size_t race, size_t role) {
	xyz->name = name;
	xyz->id = id;
	xyz->rarity = rarity;
	xyz->collect = collect;
	xyz->cType = type;
	xyz->cRole = role;
	xyz->cRace = race;
	xyz->cost = cost;
	xyz->atk = atk;
	xyz->hpc = hp;
	xyz->hpm = hp;
	xyz->flavour = flavour;
	Cards.push_back(*xyz);
}

void initFX(Card *xyz, int n, vector< vector<string> > *cCode, vector< vector<bool> > cTarAr, vector< vector<bool> > cTarTy, vector<string> target) {
	Effect baseFX;
	baseFX.fx = n;
	size_t size = cCode[0].size();
	if (cCode[1].size() > size) { size = cCode[1].size(); }
	if (cCode[3].size() > size) { size = cCode[3].size(); }
	if (cTarAr.size() > size) { size = cTarAr.size(); }
	if (cTarTy.size() > size) { size = cTarTy.size(); }
	if (target.size() > size) { size = target.size(); }
	while (true) {
		if (cCode[0].size() < size) { cCode[0].push_back( vector<string>() ); cCode[0].back().push_back(""); }
		if (cCode[0].size() == size) { break; }
	}
	while (true) {
		if (cCode[1].size() < size) { cCode[1].push_back( vector<string>() ); cCode[1].back().push_back(""); }
		if (cCode[1].size() == size) { break; }
	}
	while (true) {
		if (cCode[3].size() < size) { cCode[3].push_back( vector<string>() ); cCode[3].back().push_back(""); }
		if (cCode[3].size() == size) { break; }
	}
	while (true) {
		if (cTarAr.size() < size) { cTarAr.push_back( vector<bool>(ARCOUNT,false) ); }
		if (cTarAr.size() == size) { break; }
	}
	while (true) {
		if (cTarTy.size() < size) { cTarTy.push_back(vector<bool>(TYCOUNT, false)); }
		if (cTarTy.size() == size) { break; }
	}
	while (true) {
		if (target.size() < size) { target.push_back(""); }
		if (target.size() == size) { break; }
	}
	baseFX.prearg = cCode[0];
	baseFX.postarg = cCode[1];
	baseFX.cTarAr = cTarAr;
	baseFX.cTarTy = cTarTy;
	baseFX.target = target;
	baseFX.effect = cCode[3];
	baseFX.targ = Cards.size(); //ID of card about to be added
	Mods.push_back(baseFX);
	xyz->cMods[n].push_back(Mods.size()-1);
}

vector< vector<string> > convertCode(string line) {
	int nChar = 0, nChar2 = 0;
	size_t temp, fake = 0;
	vector<string> temp2, temp3;
	vector< vector<string> > cCode;
	while (true) {
		temp = line.find("?", nChar + fake);
		fake = line.find("}", nChar + fake);
		if (line.find("{", nChar) < temp && temp < fake) { fake -= nChar2; continue; }
		if (temp != string::npos) {
			temp2.push_back(line.substr(nChar, temp - nChar));
			nChar = temp + 1;
			fake = 0;
		}
		else {
			temp2.push_back(line.substr(nChar, line.length() - nChar + 1));
			fake = 0;
			break;
		}
	}
	for (size_t i = 0; i < temp2.size(); i++) {
		temp3.clear();
		while (true) {
			temp = temp2[i].find("|", nChar2 + fake);
			fake = temp2[i].find("}", nChar2 + fake);
			if (temp2[i].find("{", nChar2) < temp && temp < fake) { fake -= nChar2; continue; }
			if (temp != string::npos) {
				temp3.push_back(temp2[i].substr(nChar2, temp - nChar2));
				nChar2 = temp + 1;
				fake = 0;
			}
			else {
				temp3.push_back(temp2[i].substr(nChar2, temp2[i].length() - nChar2 + 1));
				cCode.push_back(temp3);
				fake = 0;
				nChar2 = 0;
				break;
			}
		}
	}
	return cCode;
}

void initializeCards() {

	// EFFECT CODING TECHNIQUE:		EFFECTTYPE=EFFECTMOD|TARLOCATION(Pboard/Oboard/Phand/Ohand/board/adj)|ALLOT(rnd/cho/all/nan +num)|TARTYPE(min/wep/sec/race/cha).
	//0 battlecry //1 charge //2 deathrattle //3 divine shield //4 enrage //5 frozen //6 overload //7 poison //8 secret //9 silence //10 stealth //11 taunt //12 windfury //13 thorn //14 turnpoint
	//15 aura //16 trigger //17 invulnerable

	fstream fileIn("carddata.txt");
	string line;

	if (fileIn.is_open())
	{
		bool flag = false;
		int bees = 0, beads = 0;
		size_t temp2;
		string temp3;
		string id, name, rarity, scollect, flavor;
		size_t cType = 0;
		size_t cRole = 0;
		size_t cRace = 0;
		vector< vector<string> > cCode[4];
		vector< vector<string> > temp5;
		vector<  vector<bool>  > cTarAr;
		vector<  vector<bool>  > cTarTy;
		vector< string > target;
		bool collect;
		int cost, attack, health, fx;
		while (getline(fileIn, line))
		{
			bees++; beads++;

			if (beads > 9048) { fileIn.close(); }
			if (line.find("/*") != string::npos) {
				while (getline(fileIn, line)) {
					if (line.find("*/") != string::npos) {
						break;
					}
				}
				bees = 0;
			}
			switch (bees) {

			case 3:
				temp = Card();

				temp2 = line.find("\",");
				name = line.substr(3, temp2 - 3);
				break;

			case 4:
				temp2 = line.find("\",");
				id = line.substr(3, temp2 - 3);
				break;

			case 5:
				temp2 = line.find("\",");
				rarity = line.substr(3, temp2 - 3);
				break;

			case 6:
				temp2 = line.find(",");
				scollect = line.substr(2, temp2 - 2);
				if (scollect == "true") { collect = true; }
				else { collect = false; }
				break;

			case 7:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				if (temp3 == "") { cType = TYPE; }
				if (temp3 == "HERO") { cType = HERO; }
				if (temp3 == "MINION") { cType = MINION; }
				if (temp3 == "SPELL") { cType = SPELL; }
				if (temp3 == "SECRET") { cType = SECRET; }
				if (temp3 == "WEAPON") { cType = WEAPON; }
				if (temp3 == "HEROPWR") { cType = HEROPWR; }

				break;

			case 8:
				temp2 = line.find(",");
				cost = stoi(line.substr(2, temp2 - 2));
				break;

			case 9:
				temp2 = line.find(",");
				attack = stoi(line.substr(2, temp2 - 2));
				break;

			case 10:
				temp2 = line.find(",");
				health = stoi(line.substr(2, temp2 - 2));
				break;

			case 11:
				temp2 = line.find("\",");
				flavor = line.substr(3, temp2 - 3);
				break;

			case 12:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				if (temp3 == "") { cRace = RACE; }
				else if (temp3 == "BEAST") { cRace = BEAST; }
				else if (temp3 == "DEMON") { cRace = DEMON; }
				else if (temp3 == "DRAGON") { cRace = DRAGON; }
				else if (temp3 == "MECHANICAL") { cRace = MECHANICAL; }
				else if (temp3 == "MURLOC") { cRace = MURLOC; }
				else if (temp3 == "PIRATE") { cRace = PIRATE; }
				else if (temp3 == "TOTEM") { cRace = TOTEM; }
				else if (temp3 == "CTHUN") { cRace = CTHUN; }
				break;

			case 13:
				temp2 = line.find("\"",3);
				temp3 = line.substr(3, temp2 - 3);
				if (temp3 == "") { 
					cRole = ROLE; 
				}
				else if (temp3 == "DRUID") { 
					cRole = DRUID;
					cout << "why" << endl;
				}
				else if (temp3 == "HUNTER") { 
					cRole = HUNTER; 
				}
				else if (temp3 == "MAGE") { 
					cRole = MAGE; 
				}
				else if (temp3 == "PALADIN") { cRole = PALADIN; }
				else if (temp3 == "PRIEST") { cRole = PRIEST; }
				else if (temp3 == "ROGUE") { cRole = ROGUE; }
				else if (temp3 == "SHAMAN") { cRole = SHAMAN; }
				else if (temp3 == "WARLOCK") { cRole = WARLOCK; }
				else if (temp3 == "WARRIOR") { cRole = WARRIOR; }
				break;

			case 15:
				temp2 = line.find("[");
				break;

			case 16:
				if (temp2 != string::npos) {
					temp2 = line.find(",");
					fx = stoi(line.substr(2, temp2 - 2));
					cCode[0].clear(); cCode[1].clear(); cCode[2].clear(); cCode[3].clear();
					temp5.clear();
					cTarAr.clear();
					cTarTy.clear();
					target.clear();
				}
				else {
					initCard(&temp, name, id, rarity, collect, cType, cost, attack, health, flavor, cRace, cRole);
					bees = 1;
				}
				break;

			case 17:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				cCode[0] = convertCode(temp3);
				break;

			case 18:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				cCode[1] = convertCode(temp3);
				break;

			case 19:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				temp5 = convertCode(temp3);
				for (size_t i = 0; i < temp5.size(); i++) {
					cTarAr.push_back(vector<bool>(ARCOUNT,false));
					for (size_t j = 0; j < temp5[i].size(); j++) {
						if (temp5[i][j] == "") { cTarAr[i][AREA] = true; }
						else if (temp5[i][j] == "PBOARD") { cTarAr[i][PBOARD] = true; }
						else if (temp5[i][j] == "OBOARD") { cTarAr[i][OBOARD] = true; }
						else if (temp5[i][j] == "PHAND") { cTarAr[i][PHAND] = true; }
						else if (temp5[i][j] == "OHAND") { cTarAr[i][OHAND] = true; }
						else if (temp5[i][j] == "PDECK") { cTarAr[i][PDECK] = true; }
						else if (temp5[i][j] == "ODECK") { cTarAr[i][ODECK] = true; }
						else if (temp5[i][j] == "PGRAVE") { cTarAr[i][PGRAVE] = true; }
						else if (temp5[i][j] == "OGRAVE") { cTarAr[i][OGRAVE] = true; }
						else if (temp5[i][j] == "BOARD") { cTarAr[i][OBOARD] = true; cTarAr[i][PBOARD] = true;}
						else if (temp5[i][j] == "HAND") { cTarAr[i][OHAND] = true; cTarAr[i][PHAND] = true; }
						else if (temp5[i][j] == "DECK") { cTarAr[i][ODECK] = true; cTarAr[i][PDECK] = true; }
						else if (temp5[i][j] == "GRAVE") { cTarAr[i][OGRAVE] = true; cTarAr[i][PGRAVE] = true; }
						else if (temp5[i][j] == "P") { cTarAr[i][PBOARD] = true; cTarAr[i][PHAND] = true; cTarAr[i][PDECK] = true; cTarAr[i][PGRAVE] = true; }
						else if (temp5[i][j] == "O") { cTarAr[i][OBOARD] = true; cTarAr[i][OHAND] = true; cTarAr[i][ODECK] = true; cTarAr[i][OGRAVE] = true; }

					}
				}
				break;

			case 20:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				temp5 = convertCode(temp3);
				for (size_t i = 0; i < temp5.size(); i++) {
					cTarTy.push_back(vector<bool>(TYCOUNT, false));
					for (size_t j = 0; j < temp5[i].size(); j++) {
						if (temp5[i][j] == "") { cTarTy[i][TYPE] = true; cTarTy[i][RACE] = true; }
						if (temp5[i][j] == "HERO") { cTarTy[i][HERO] = true; }
						if (temp5[i][j] == "MINION") { cTarTy[i][MINION] = true; }
						if (temp5[i][j] == "CHAR") { cTarTy[i][HERO] = true; cTarTy[i][MINION] = true; }
						if (temp5[i][j] == "CARD") { cTarTy[i][MINION] = true; cTarTy[i][SPELL] = true; cTarTy[i][SECRET] = true; cTarTy[i][WEAPON] = true; }
						if (temp5[i][j] == "SPELL") { cTarTy[i][SPELL] = true; }
						if (temp5[i][j] == "SECRET") { cTarTy[i][SECRET] = true; }
						if (temp5[i][j] == "WEAPON") { cTarTy[i][WEAPON] = true; }
						if (temp5[i][j] == "HEROPWR") { cTarTy[i][HEROPWR] = true; }
						if (temp5[i][j] == "BEAST") { cTarTy[i][BEAST] = true; }
						if (temp5[i][j] == "DEMON") { cTarTy[i][DEMON] = true; }
						if (temp5[i][j] == "DRAGON") { cTarTy[i][DRAGON] = true; }
						if (temp5[i][j] == "MECHANICAL") { cTarTy[i][MECHANICAL] = true; }
						if (temp5[i][j] == "MURLOC") { cTarTy[i][MURLOC] = true; }
						if (temp5[i][j] == "PIRATE") { cTarTy[i][PIRATE] = true; }
						if (temp5[i][j] == "TOTEM") { cTarTy[i][TOTEM] = true; }
						if (temp5[i][j] == "CTHUN") { cTarTy[i][CTHUN] = true; }
					}
				}
				break;

			case 21:
				temp2 = line.find("\",");
				temp3 = line.substr(3, temp2 - 3);
				cCode[2] = convertCode(temp3);
				for (size_t i = 0; i < cCode[2].size(); i++) {
					target.push_back(cCode[2][i][0]);
				}
				break;

			case 22:
				temp2 = line.find("\"", 3);
				temp3 = line.substr(3, temp2 - 3);
				cCode[3] = convertCode(temp3);
				break;

			case 23: {
				initFX(&temp, fx, cCode, cTarAr, cTarTy, target);
				break;
			}

			case 24:
				temp2 = line.find("[");
				bees = 15;
				break;

			default:
				break;
			}
		}
	}
}