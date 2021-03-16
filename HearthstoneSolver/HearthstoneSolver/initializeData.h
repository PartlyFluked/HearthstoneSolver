#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include <sstream>

#define BOARD 0
#define HAND 1
#define DECK 2
#define GRAVEYARD 3

#define AGAME 1
#define BGAME 2

#define GROUPSIZE 4

#define DECKSIZE 30
//bool type[15] {TYPE, HERO, MINION, SPELL, SECRET, WEAPON, HEROPWR, RACE, BEAST, DEMON, DRAGON, MECHANICAL, MURLOC, PIRATE, TOTEM}
#define TYPE 0
#define HERO 1
#define MINION 2
#define SPELL 3
#define SECRET 4
#define WEAPON 5
#define HEROPWR 6
#define RACE 7
#define BEAST 8
#define DEMON 9
#define DRAGON 10
#define MECHANICAL 11
#define MURLOC 12
#define PIRATE 13
#define TOTEM 14
#define CTHUN 15

#define TYCOUNT 16
//role{ ROLE, DRUID, HUNTER, MAGE, PALADIN, PRIEST, ROGUE, SHAMAN, WARLOCK, WARRIOR };
#define ROLE 0
#define DRUID 1
#define HUNTER 2
#define MAGE 3
#define PALADIN 4
#define PRIEST 5
#define ROGUE 6
#define SHAMAN 7
#define WARLOCK 8
#define WARRIOR 9
//bool area[9] {AREA, PBOARD, OBOARD, PHAND, OHAND, PDECK, ODECK, PGRAVE, OGRAVE}
#define AREA 0
#define PBOARD 1
#define OBOARD 2
#define PHAND 3
#define OHAND 4
#define PDECK 5
#define ODECK 6
#define PGRAVE 7
#define OGRAVE 8

#define ARCOUNT 9
//first 6 cards in pCards are always the same
#define Ahero 0
#define Bhero 1
#define Awep 2
#define Bwep 3
#define Ahpwr 4
#define Bhpwr 5
//bool fx[21] {BATTLECRY, CHARGE, DEATHRATTLE, DIVINESHIELD, ENRAGE, FROZEN, OVERLOAD, THORNS, CONFUSED, SILENCE, STEALTH, TAUNT, WINDFURY, INSPIRE, TURNPOINT, AURA, TRIGGER, 
			// INVULNERABLE, CHOOSEONE, SPELLSCREEN, PACIFIST}
#define BATTLECRY 0
#define CHARGE 1
#define DEATHRATTLE 2
#define DIVINESHIELD 3
#define ENRAGE 4
#define FROZEN 5
#define OVERLOAD 6
#define COMBO 7
#define CONFUSED 8
#define SILENCE 9
#define STEALTH 10
#define TAUNT 11
#define WINDFURY 12
#define INSPIRE 13
#define TURNPOINT 14
#define AURA 15
#define TRIGGER 16
#define INVULNERABLE 17
#define CHOOSEONE 18
#define SPELLSCREEN 19
#define PACIFIST 20
#define MOD 21
#define CURSE 22

#define FXCOUNT 23

using namespace std;

class Card
{
public:
	string name; //card name
	string id; //card id //unused
	string rarity; //card rarity
	bool collect; //collectibility
	size_t cType = 0; //bool cTarTy[15] {TYPE, HERO, MINION, SPELL, SECRET, WEAPON, HEROPWR, RACE, BEAST, DEMON, DRAGON, MECHANICAL, MURLOC, PIRATE, TOTEM};
	size_t cRole = 0; //bool cRole[10] {ROLE, DRUID, HUNTER, MAGE, PALADIN, PRIEST, ROGUE, SHAMAN, WARLOCK, WARRIOR };
	size_t cRace = 0; //same as cTarTy
	//bool cTarAr[9] {AREA, PBOARD, OBOARD, PHAND, OHAND, PDECK, ODECK, PGRAVE, OGRAVE};
	int cost; //card cost //will be used as armr if hero?
	int atk; //card atk
	int hpc, hpm; //current,max health, hps affects both
	int mods[3] = { 0,0,0 }; //cost, atk, hps
	bool modsFx[FXCOUNT] = { false };
	vector < size_t > cMods[FXCOUNT]; //list of all effect id's on this card //0 is initial effect //but maybe it has multiple effects?
	size_t playNum; //Place is gameplay history

	string flavour; //card flavourText

	size_t ready = 0; //1 for ready, 2 windfury
	size_t place = 0; //AREA, PBOARD, OBOARD, PHAND, OHAND, PDECK, ODECK, PGRAVE, OGRAVE} board, hand, deck, grave
	size_t side = 0; //1 for AGame, 2 for BGame
	size_t placement;

	int getFx(size_t i) {
		return (modsFx[i]);
	}
	int getCost(void) {
		return cost + mods[0];
	}
	int getAtk(void);
	int getHpc(void) {
		return hpc + mods[2]; //used to just be hpc, why?
	}
	int getHpm(void) {
		return hpm + mods[2];
	}
};

class Effect
{
public:
	size_t master = 0; //id of master effect if aura
	vector < size_t > slaves; //list of all effect id's this effect creates through aura, empty if not aura
	int fx;
	vector < vector<string> > prearg;
	vector < vector<string> > postarg;
	vector < vector<bool> > cTarAr;
	vector < vector<bool> > cTarTy;
	vector < string > target;
	vector < vector<string> > effect;
	int mods[3] = { 0,0,0 };
	int timer = 0; //how many turns this will continue to last for; 0 = forever; -2 = activate effect in 2 turns then remove; 2 = remove effect in 2 turn;
	size_t targ; //id of card effect is attached to
};

class GameSpace
{
public:
	GameSpace *Ogame; //pointer to opponent's board

	size_t side; //1 for AGame, 2 for BGame

	size_t hero; //id of player hero card
	size_t hPwr; //id of player heroPower card
	size_t pReady = 0; //how many more times player can use heroPower
	size_t pwrCost = 2;
	bool HeroFury = false; //can use heroPower as many times as player can afford
	bool comboflag = false;
	size_t weapon; //if of player weapon card

	size_t fatigue = 1; //damage incurred when drawing from empty deck

	size_t spDam = 0; //adds to effects of many spells

	vector<size_t> deck; //player's deck

	size_t drawn = 0; //cards drawn //needed for few card effects

	vector<size_t> hand; //contents of player's hand //max 10

	vector<size_t> secrets; //player's secrets //max 5

	vector<size_t> grave; //player's graveyard

	size_t cMana; //player current mana
	size_t mMana; //player max mana //max 10 //at 10, cards that increase this give a free coin
	size_t o1Mana = 0; //player overload //turns to 0 at end of turn
	size_t o2Mana = 0; //player overload //turns to o1Mana at end of turn

	vector<size_t> board; //players board
	size_t cthun = 0;
};

struct playData {
	string name, flavour, from1, to1;
	int side1, from2;
	vector<int> to2;
};

struct playInfo {
	int cPlay;
	int cTarget;
	int cDam;
};

struct playHistory {
	int cost = 0, atk = 0, hpc = 0, hpm = 0, dam = 0;
	size_t tar = 0, tarNum = 0;
};

extern GameSpace AGame; //side 1
extern GameSpace BGame; //side 2

extern vector<string> cGroups[GROUPSIZE]; //card groups

extern vector<Card> Cards; //all possible cards //cannot be modified while running
extern vector<Effect> Mods; //all base effects for cards

extern vector<playData> historyData;
extern vector<Card> pCards; //cards imported for game from Cards //can be modified //nothing is ever removed
extern vector<Effect> pMods; //all current effects on cards in game //nothing is ever removed
extern vector<size_t> unusedMod;
extern vector<size_t> triggers; //triggerable effects to be checked during play //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
extern vector<size_t> turnpoints; //effects to be checked between plays
extern vector<size_t> auras; //effects that affect other cards
//extern Hero Druid, Hunter, Mage, Paladin, Priest, Rogue, Shaman, Warlock, Warrior, Ragnaros_The_Firelord;

class TimeTravel
{
public:
	GameSpace seedA;
	GameSpace seedB;
	vector<playData> s_historyData;
	vector<Card> s_pCards; //cards imported for game from Cards //can be modified //nothing is ever removed
	vector<Effect> s_pMods; //all current effects on cards in game //nothing is ever removed
	vector<size_t> s_unusedMod;
	vector<size_t> s_triggers; //triggerable effects to be checked during play //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
	vector<size_t> s_turnpoints; //effects to be checked between plays
	vector<size_t> s_auras;
	playInfo s_currPlay;
	size_t s_globID;
	int s_playNum, s_turnNum;
	TimeTravel *prevNode;
	TimeTravel *nextNode;
	GameSpace nodeA;
	GameSpace nodeB;
	vector<playData> n_historyData;
	vector<Card> n_pCards; //cards imported for game from Cards //can be modified //nothing is ever removed
	vector<Effect> n_pMods; //all current effects on cards in game //nothing is ever removed
	vector<size_t> n_unusedMod;
	vector<size_t> n_triggers; //triggerable effects to be checked during play //PSUMMONS, OSUMMONS, ATTACKS, DAMAGES, PDRAW, ODRAW
	vector<size_t> n_turnpoints; //effects to be checked between plays
	vector<size_t> n_auras;
	playInfo n_currPlay;
	size_t n_globID;
	int n_playNum, n_turnNum;
	vector <int> currMoves;
};