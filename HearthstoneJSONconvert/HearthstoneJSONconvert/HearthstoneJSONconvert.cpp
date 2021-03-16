// basic file operations
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	typedef istreambuf_iterator<char> buf_iter;

	fstream fileIn("allcards.txt");
	ofstream fileOut("converted.txt");
	string line;

	fileOut << "{\n\t{\n\
		\"UNARMED\",				//name\n\
		\"LUKETEST\",				//id\n\
		\"Common\",				//rarity\n\
		false,				//collect\n\
		\"Weapon\",				//type\n\
		0,				//cost\n\
		0,				//atk\n\
		0,				//hp\n\
		\"NO WEAPON\",\
		\"\",				//race\n\
		\"\"				//hero\n\
	}\n\
}\n";

	if (fileIn.is_open())
	{
		//fileOut << "{\n";
		bool flag = false;
		vector<string> lines;

		while (getline(fileIn, line))
		{
			string id, name, rarity, durability, collect, type, cost="0", attack="0", health="0", text, flavor, race, playerclass, mechanics, mechanics2;

			size_t Nid = line.find("id\":\"");
			if (Nid != string::npos) {
				Nid += 5;
				size_t Nid2 = line.find("\"", Nid);
				id = line.substr(Nid, Nid2 - Nid);
			}

			size_t Nname = line.find("name\":\"");
			if (Nname != string::npos) {
				Nname += 7;
				size_t Nname2 = line.find("\"", Nname);
				name = line.substr(Nname, Nname2 - Nname);
			}

			replace(name.begin(), name.end(), ' ', '_');
			replace(name.begin(), name.end(), '-', '_');
			replace(name.begin(), name.end(), ':', '_');
			replace(name.begin(), name.end(), '/', '_');
			name.erase(remove(name.begin(), name.end(), '\''), name.end());
			name.erase(remove(name.begin(), name.end(), '.'), name.end());
			name.erase(remove(name.begin(), name.end(), '!'), name.end());
			name.erase(remove(name.begin(), name.end(), ','), name.end());

			size_t Nrarity = line.find("rarity\":\"");
			if (Nrarity != string::npos) {
				Nrarity += 9;
				size_t Nrarity2 = line.find("\"", Nrarity);
				rarity = line.substr(Nrarity, Nrarity2 - Nrarity);
			}

			size_t Ncollect = line.find("collectible\":");
			if (Ncollect != string::npos) {
				Ncollect += 13;
				size_t Ncollect2 = line.find(",", Ncollect);
				collect = line.substr(Ncollect, Ncollect2 - Ncollect);
			}
			else {
				collect = "false";
			}

			size_t Ntype = line.find("type\":\"");
			if (Ntype != string::npos) {
				Ntype += 7;
				size_t Ntype2 = line.find("\"", Ntype);
				type = line.substr(Ntype, Ntype2 - Ntype);
			}

			size_t Ncost = line.find("cost\":");
			if (Ncost != string::npos) {
				Ncost += 6;
				size_t Ncost2 = line.find(",", Ncost);
				size_t temp = line.find("}", Ncost);
				if (temp < Ncost2) { Ncost2 = temp; }
				cost = line.substr(Ncost, Ncost2 - Ncost);
			}

			size_t Nattack = line.find("attack\":");
			if (Nattack != string::npos) {
				Nattack += 8;
				size_t Nattack2 = line.find(",", Nattack);
				size_t temp = line.find("}", Nattack);
				if (temp < Nattack2) { Nattack2 = temp; }
				attack = line.substr(Nattack, Nattack2 - Nattack);
			}

			size_t Nhealth = line.find("health\":");
			if (Nhealth != string::npos) {
				Nhealth += 8;
				size_t Nhealth2 = line.find(",", Nhealth);
				size_t temp = line.find("}", Nhealth);
				if (temp < Nhealth2) { Nhealth2 = temp; }
				health = line.substr(Nhealth, Nhealth2 - Nhealth);
			}

			size_t Ndurability = line.find("durability\":");
			if (Ndurability != string::npos) {
				Ndurability += 12;
				size_t Ndurability2 = line.find("\"", Ndurability);
				health = line.substr(Ndurability, Ndurability2 - Ndurability);
			}

			size_t Ntext = line.find("text\":\"");
			if (Ntext != string::npos) {
				Ntext += 7;
				size_t Ntext2 = line.find("\",\"", Ntext);
				size_t temp = line.find("\"}", Ntext);
				if (temp < Ntext2) { Ntext2 = temp; }
				text = line.substr(Ntext, Ntext2 - Ntext);
			}

			size_t Nflavor = line.find("flavor\":\"");
			if (Nflavor != string::npos) {
				Nflavor += 9;
				size_t Nflavor2 = line.find("\",\"", Nflavor);
				size_t temp = line.find("\"}", Nflavor);
				if (temp < Nflavor2) { Nflavor2 = temp; }
				flavor = line.substr(Nflavor, Nflavor2 - Nflavor);
			}

			size_t Nrace = line.find("race\":\"");
			if (Nrace != string::npos) {
				Nrace += 7;
				size_t Nrace2 = line.find("\"", Nrace);
				race = line.substr(Nrace, Nrace2 - Nrace);
			}

			size_t Nplayerclass = line.find("playerClass\":\"");
			if (Nplayerclass != string::npos) {
				Nplayerclass += 14;
				size_t Nplayerclass2 = line.find("\"", Nplayerclass);
				playerclass = line.substr(Nplayerclass, Nplayerclass2 - Nplayerclass);
			}

			bool secretFlag = false;

			size_t Nmechanics = line.find("mechanics\":[");
			if (Nmechanics != string::npos) {
				Nmechanics += 12;
				size_t Nmechanics2 = line.find("]", Nmechanics);
				mechanics = line.substr(Nmechanics, Nmechanics2 - Nmechanics);

				mechanics2 = "";

				if (mechanics.find("BATTLECRY") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "0,\t\t\t//Battlecry\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("CHARGE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "1,\t\t\t//Charge\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("DEATHRATTLE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "2,\t\t\t//Deathrattle\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("DIVINE_SHIELD") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "3,\t\t\t//Divine Shield\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("ENRAGED") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "4,\t\t\t//Enrage\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("FREEZE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "5,\t\t\t//Frozen\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (text.find("OVERLOAD") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "6,\t\t\t//Overload\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("POISONOUS") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "7,\t\t\t//Poison\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("SECRET") != string::npos) {
					secretFlag = true;
					mechanics2 += string() + "\t[\n\t\t"
						+ "8,\t\t\t//Secret\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("SILENCE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "9,\t\t\t//Silence\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("STEALTH") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "10,\t\t\t//Stealth\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("TAUNT") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "11,\t\t\t//Taunt\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
				if (mechanics.find("WINDFURY") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "12,\t\t\t//Windfury\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}

				if (mechanics.find("INSPIRE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "13,\t\t\t//Inspire\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}

				if (mechanics.find("AURA") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "15,\t\t\t//Aura\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}

				if (mechanics.find("CHOOSE_ONE") != string::npos) {
					mechanics2 += string() + "\t[\n\t\t"
						+ "18,\t\t\t//Choose one\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
				}
			}

			if (text!=""&&flavor!="") { text += string() + " " + flavor; }
			else if (text == "" && flavor != "") { text += string() + flavor; }

			if (type=="SPELL") {
				mechanics2 += string() + "\t[\n\t\t"
						+ "0,\t\t\t//Spell AKA battlecry\n\t\t"
						+ "\"\",\t\t\t\t//prearg\n\t\t"
						+ "\"\",\t\t\t\t//prearg2\n\t\t"
						+ "\"\",\t\t\t\t//area\n\t\t"
						+ "\"\",\t\t\t\t//tarTy\n\t\t"
						+ "\"\",\t\t\t\t//target\n\t\t"
						+ "\"\"\t\t\t\t//effect\n\t]\n";
			}

			if (secretFlag) { type = "Secret"; }

			if (type!="ENCHANTMENT" && type!="HERO" && type!="HERO_POWER" ) {
				fileOut << "{\n\t{\n\t\t\""
					+ name + "\",\t\t\t\t//name\n\t\t\""
					+ id + "\",\t\t\t\t//id\n\t\t\""
					+ rarity + "\",\t\t\t\t//rarity\n\t\t"
					+ collect + ",\t\t\t\t//collect\n\t\t\""
					+ type + "\",\t\t\t\t//type\n\t\t"
					+ cost + ",\t\t\t\t//cost\n\t\t"
					+ attack + ",\t\t\t\t//atk\n\t\t"
					+ health + ",\t\t\t\t//hp\n\t\t\""
					+ text + "\",\n\t\t\""
					+ race + "\",\t\t\t\t//race\n\t\t\""
					+ playerclass + "\"\t\t\t\t//hero\n\t}\n"
					+ mechanics2 + "}\n";
			}
		}
		fileIn.close();
	}
	return 0;
}