#include <string>
#include "initializeData.h"
#include <vector>

using namespace std;

vector<Card> Cards;

//Heroes
Hero Druid;
Hero Hunter;
Hero Mage;
Hero Paladin;
Hero Priest;
Hero Rogue;
Hero Shaman;
Hero Warlock;
Hero Warrior;
Hero Ragnaros_The_Firelord;

void initializeHeroes() {
	{
		Druid.id = 1;
		Druid.name = "Druid";
		Druid.hp = 30;
		Druid.armr = 0;
		Druid.pwr = 0;
		Druid.wepId = 0;
		Druid.atk = 0;
		Druid.dur = 0;
	}
	{
		Hunter.id = 2;
		Hunter.name = "Hunter";
		Hunter.hp = 30;
		Hunter.armr = 0;
		Hunter.pwr = 1;
		Hunter.wepId = 0;
		Hunter.atk = 0;
		Hunter.dur = 0;
	}
	{
		Mage.id = 3;
		Mage.name = "Mage";
		Mage.hp = 30;
		Mage.armr = 0;
		Mage.pwr = 2;
		Mage.wepId = 0;
		Mage.atk = 0;
		Mage.dur = 0;
	}
	{
		Paladin.id = 4;
		Paladin.name = "Paladin";
		Paladin.hp = 30;
		Paladin.armr = 0;
		Paladin.pwr = 3;
		Paladin.wepId = 0;
		Paladin.atk = 0;
		Paladin.dur = 0;
	}
	{
		Priest.id = 5;
		Priest.name = "Priest";
		Priest.hp = 30;
		Priest.armr = 0;
		Priest.pwr = 4;
		Priest.wepId = 0;
		Priest.atk = 0;
		Priest.dur = 0;
	}
	{
		Rogue.id = 6;
		Rogue.name = "Rogue";
		Rogue.hp = 30;
		Rogue.armr = 0;
		Rogue.pwr = 6;
		Rogue.wepId = 0;
		Rogue.atk = 0;
		Rogue.dur = 0;
	}
	{
		Shaman.id = 7;
		Shaman.name = "Shaman";
		Shaman.hp = 30;
		Shaman.armr = 0;
		Shaman.pwr = 7;
		Shaman.wepId = 0;
		Shaman.atk = 0;
		Shaman.dur = 0;
	}
	{
		Warlock.id = 8;
		Warlock.name = "Warlock";
		Warlock.hp = 30;
		Warlock.armr = 0;
		Warlock.pwr = 8;
		Warlock.wepId = 0;
		Warlock.atk = 0;
		Warlock.dur = 0;
	}
	{
		Warrior.id = 9;
		Warrior.name = "Warrior";
		Warrior.hp = 30;
		Warrior.armr = 0;
		Warrior.pwr = 10;
		Warrior.wepId = 0;
		Warrior.atk = 0;
		Warrior.dur = 0;
	}
	{
		Ragnaros_The_Firelord.id = 10;
		Ragnaros_The_Firelord.name = "Ragnaros_The_Firelord";
		Ragnaros_The_Firelord.hp = 8;
		Ragnaros_The_Firelord.armr = 0;
		Ragnaros_The_Firelord.pwr = 11;
		Ragnaros_The_Firelord.wepId = 0;
		Ragnaros_The_Firelord.atk = 0;
		Ragnaros_The_Firelord.dur = 0;
	}
}

void initCard(Card xyz, string id, string rarity, bool collect, string type, int cost, int atk, int hp, string flavour, string race, string hero) {
	xyz.id = id;
	xyz.rarity = rarity;
	xyz.collect = collect;
	xyz.type = type;
	xyz.cost = cost;
	xyz.atk = atk;
	xyz.hp = hp;
	xyz.flavour = flavour;
	xyz.race = race;
	xyz.hero = hero;
	Cards.push_back(xyz);
}

void initializeCards() {

	// EFFECT CODING TECHNIQUE:		EFFECTTYPE=EFFECTMOD|TARLOCATION(Pboard/Oboard/Phand/Ohand/board/adj)|ALLOT(rnd/cho/all/nan +num)|TARTYPE(min/wep/sec/race/cha).
	//0 battlecry //1 charge //2 deathrattle //3 divine shield //4 enrage //5 frozen //6 overload //7 poison //8 secret //9 silence //10 stealth //11 taunt //12 windfury //13 thorn //14 turnpoint
	//15 aura //16 trigger //17 invulnerable
	{
		Card Acidic_Swamp_Ooze;
		Acidic_Swamp_Ooze.fx[0] = true;			//Battlecry
		Acidic_Swamp_Ooze.fx2[0] = "nan:Oboard|wep|nan|destroy";
		initCard(
			Acidic_Swamp_Ooze,				//card
			"EX1_066",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Destroy your opponent's weapon. Oozes love Flamenco.  Don't ask.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancestral_Healing;
		Ancestral_Healing.fx[0] = true;			//Spell AKA battlecry
		Ancestral_Healing.fx2[0] = "nan:board|min|cho1|dam=0,fx[11]=true";
		initCard(
			Ancestral_Healing,				//card
			"CS2_041",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore a minion to full Health and give it <b>Taunt</b>. I personally prefer some non-ancestral right-the-heck-now healing, but maybe that is just me.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Animal_Companion;
		Animal_Companion.fx[0] = true;			//Spell AKA battlecry
		Animal_Companion.fx2[0] = "nan:Pboard|nan|nan|summon1(Huffer=0.75,Leokk=0.2,Misha=0.05)";
		initCard(
			Animal_Companion,				//card
			"NEW1_031",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Summon a random Beast Companion. You could summon Misha, Leokk, or Huffer!  Huffer is more trouble than he's worth.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Explosion;
		Arcane_Explosion.fx[0] = true;			//Spell AKA battlecry
		Arcane_Explosion.fx2[0] = "nan:Oboard|min|all|dam+=1";
		initCard(
			Arcane_Explosion,				//card
			"CS2_025",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to all enemy minions. This spell is much better than Arcane Implosion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Intellect;
		Arcane_Intellect.fx[0] = true;			//Spell AKA battlecry
		Arcane_Intellect.fx2[0] = "nan:Phand|nan|nan|draw(1)";
		initCard(
			Arcane_Intellect,				//card
			"CS2_023",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Draw 2 cards. Playing this card makes you SMARTER.  And let's face it: we could all stand to be a little smarter.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Missiles;
		Arcane_Missiles.fx[0] = true;			//Spell AKA battlecry
		Arcane_Missiles.fx2[0] = "nan:Oboard|min|3rnd|dam+=1";
		initCard(
			Arcane_Missiles,				//card
			"EX1_277",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage randomly split among all enemies. You'd think you'd be able to control your missiles a little better since you're a powerful mage and all.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Shot;
		Arcane_Shot.fx[0] = true;			//Spell AKA battlecry
		Arcane_Shot.fx2[0] = "nan:board|cha|cho1|dam+=2";
		initCard(
			Arcane_Shot,				//card
			"DS1_185",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage. Magi conjured arcane arrows to sell to hunters, until hunters learned just enough magic to do it themselves.  The resulting loss of jobs sent Stormwind into a minor recession.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcanite_Reaper;
		initCard(
			Arcanite_Reaper,				//card
			"CS2_112",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			5,				//cost
			5,				//atk
			0,				//hp
			"No… actually you should fear the Reaper.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Archmage;
		Archmage.fx[15] = true;			//aura
		Archmage.fx2[15] = "nan:Pboard|nan|nan|spDam+=1";
		initCard(
			Archmage,				//card
			"CS2_155",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			7,				//hp
			"<b>Spell Damage +1</b> You earn the title of Archmage when you can destroy anyone who calls you on it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Assassins_Blade;
		initCard(
			Assassins_Blade,				//card
			"CS2_080",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			5,				//cost
			3,				//atk
			0,				//hp
			"Guaranteed to have been owned by a real assassin.   Certificate of authenticity included.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Assassinate;
		Assassinate.fx[0] = true;			//Spell AKA battlecry
		Assassinate.fx2[0] = "nan:Oboard|min|cho1|destroy";
		initCard(
			Assassinate,				//card
			"CS2_076",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Destroy an enemy minion. If you don't want to be assassinated, move to the Barrens and change your name. Good luck!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Avatar_of_the_Coin;
		initCard(
			Avatar_of_the_Coin,				//card
			"GAME_002",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"<i>You lost the coin flip, but gained a friend.</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Backstab;
		Backstab.fx[0] = true;			//Spell AKA battlecry
		Backstab.fx2[0] = "iff(!damaged):board|min|cho1,tar|nan,dam+=2";
		initCard(
			Backstab,				//card
			"CS2_072",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to an undamaged minion. It's funny how often yelling \"Look over there!\" gets your opponent to turn around.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blessing_of_Kings;
		Blessing_of_Kings.fx[0] = true;			//Spell AKA battlecry
		Blessing_of_Kings.fx2[0] = "nan:board|min|cho1|atk+=4,hp+=4";
		initCard(
			Blessing_of_Kings,				//card
			"CS2_092",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +4/+4. <i>(+4 Attack/+4 Health)</i> Given the number of kings who have been assassinated, are you sure you want their blessing?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blessing_of_Might;
		Blessing_of_Might.fx[0] = true;			//Spell AKA battlecry
		Blessing_of_Might.fx2[0] = "board|min|cho1|atk+=3";
		initCard(
			Blessing_of_Might,				//card
			"CS2_087",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +3 Attack. \"As in, you MIGHT want to get out of my way.\" - Toad Mackle, recently buffed.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bloodfen_Raptor;
		initCard(
			Bloodfen_Raptor,				//card
			"CS2_172",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"\"Kill 30 raptors.\" - Hemet Nesingwary",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Bloodlust;
		Bloodlust.fx[0] = true;			//Spell AKA battlecry
		Bloodlust.fx2[0] = "time(till,PE):Pboard|min|all|atk+=3";
		initCard(
			Bloodlust,				//card
			"CS2_046",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Give your minions +3 Attack this turn. blaarghghLLGHRHARAAHAHHH!!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bluegill_Warrior;
		Bluegill_Warrior.fx[1] = true;			//Charge
		initCard(
			Bluegill_Warrior,				//card
			"CS2_173",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Charge</b> He just wants a hug.   A sloppy... slimy... hug.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Boar;
		initCard(
			Boar,				//card
			"CS2_boar",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Booty_Bay_Bodyguard;
		Booty_Bay_Bodyguard.fx[10] = true;			//Taunt
		initCard(
			Booty_Bay_Bodyguard,				//card
			"CS2_187",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Taunt</b> You can hire him... until someone offers him enough gold to turn on you.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Boulderfist_Ogre;
		initCard(
			Boulderfist_Ogre,				//card
			"CS2_200",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			7,				//hp
			"\"ME HAVE GOOD STATS FOR THE COST\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Charge;
		Charge.fx[0] = true;			//Spell AKA battlecry
		Charge.fx2[0] = "nan:Pboard|min|cho1|atk+=2,fx[10]=true";
		initCard(
			Charge,				//card
			"CS2_103",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Give a friendly minion +2 Attack and <b>Charge</b>. \"Guys! Guys! Slow down!\" - some kind of non-warrior minion",
			"",				//race
			""				//hero
			);
	}
	{
		Card Chillwind_Yeti;
		initCard(
			Chillwind_Yeti,				//card
			"CS2_182",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			5,				//hp
			"He always dreamed of coming down from the mountains and opening a noodle shop, but he never got the nerve.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Claw;
		Claw.fx[0] = true;			//Spell AKA battlecry
		Claw.fx2[0] = "time(till,PE,0):Pboard|hero|nan|atk+=3,armr+=2";
		initCard(
			Claw,				//card
			"CS2_005",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give your hero +2 Attack this turn and 2 Armor. The claw decides who will stay and who will go.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cleave;
		Cleave.fx[0] = true;			//Spell AKA battlecry
		Cleave.fx2[0] = "nan:Oboard|min|rnd2|dam+=2";
		initCard(
			Cleave,				//card
			"CS2_114",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to two random enemy minions. Hey you two…could you stand next to each other for a second…",
			"",				//race
			""				//hero
			);
	}
	{
		Card Consecration;
		Consecration.fx[0] = true;			//Spell AKA battlecry
		Consecration.fx2[0] = "nan:Oboard|cha|all|dam+=2";
		initCard(
			Consecration,				//card
			"CS2_093",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hpb
			"Deal $2 damage to all enemies. Consecrated ground glows with Holy energy.  But it smells a little, too.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Core_Hound;
		initCard(
			Core_Hound,				//card
			"CS2_201",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			9,				//atk
			5,				//hp
			"You don’t tame a Core Hound. You just train it to eat someone else before it eats you.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Corruption;
		Corruption.fx[0] = true;			//Spell AKA battlecry
		Corruption.fx2[0] = "time(then,PS):Oboard|min|cho1|destroy";
		initCard(
			Corruption,				//card
			"CS2_063",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Choose an enemy minion. At the start of your turn, destroy it. It starts with stealing a pen from work, and before you know it, BOOM!  Corrupted!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dalaran_Mage;
		Dalaran_Mage.fx[15] = true;		//aura
		Dalaran_Mage.fx2[15] = "spDam+=1|Pboard|nan|nan|nan";

		initCard(
			Dalaran_Mage,				//card
			"EX1_582",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"<b>Spell Damage +1</b> You don't see a lot of Dalaran warriors.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Darkscale_Healer;
		Darkscale_Healer.fx[0] = true;			//Battlecry
		Darkscale_Healer.fx2[0] = "nan:Pboard|cha|all|hp+=2";
		initCard(
			Darkscale_Healer,				//card
			"DS1_055",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			5,				//hp
			"<b>Battlecry:</b> Restore 2 Health to all friendly characters. Healing is just something she does in her free time.  It's more of a hobby really.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deadly_Poison;
		Deadly_Poison.fx[0] = true;			//Spell AKA battlecry
		Deadly_Poison.fx2[0] = "nan:Pboard|wep|nan|atk+=2";
		initCard(
			Deadly_Poison,				//card
			"CS2_074",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give your weapon +2 Attack. Rogues guard the secrets to poison-making carefully, lest magi start incorporating poison into their spells.  Poisonbolt? Rain of Poison?  Poison Elemental?  Nobody wants that.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Divine_Spirit;
		Divine_Spirit.fx[0] = true;			//Spell AKA battlecry
		Divine_Spirit.fx2[0] = "nan:board|min|cho1|hp*=2";
		initCard(
			Divine_Spirit,				//card
			"CS2_236",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Double a minion's Health. Double the trouble. Double the fun!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragonling_Mechanic;
		Dragonling_Mechanic.fx[0] = true;			//Battlecry
		Dragonling_Mechanic.fx2[0] = "nan:Pboard|nan|nan|summon(Mehanical_Dragonling=1)";
		initCard(
			Dragonling_Mechanic,				//card
			"EX1_025",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> Summon a 2/1 Mechanical Dragonling. She is still working on installing the rocket launcher add-on for Mr. Bitey.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Drain_Life;
		Drain_Life.fx[0] = true;			//Spell AKA battlecry
		Drain_Life.fx2[0] = "nan:board,Pboard|cha,hero|cho1,nan|dam+=2,hp+=2";
		initCard(
			Drain_Life,				//card
			"CS2_061",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage. Restore #2 Health to your hero. \"I've just sucked one year of your life away.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dread_Infernal;
		Dread_Infernal.fx[0] = true;			//Battlecry
		Dread_Infernal.fx2[0] = "nan:board|cha|!self|dam+=1";
		initCard(
			Dread_Infernal,				//card
			"CS2_064",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"<b>Battlecry:</b> Deal 1 damage to ALL other characters. \"INFERNOOOOOOOOOO!\" - Jaraxxus, Eredar Lord of the Burning Legion",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Elven_Archer;
		Elven_Archer.fx[0] = true;			//Battlecry
		Elven_Archer.fx2[0] = "nan:board|cha|cho1|dam+=1";
		initCard(
			Elven_Archer,				//card
			"CS2_189",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Battlecry:</b> Deal 1 damage. Don't bother asking her out on a date.  She'll shoot you down.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Excess_Mana;
		Excess_Mana.fx[0] = true;			//Spell AKA battlecry
		Excess_Mana.fx2[0] = "nan:Phand|nan|nan|draw(1)";
		initCard(
			Excess_Mana,				//card
			"CS2_013t",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Draw a card. <i>(You can only have 10 Mana in your tray.)</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Execute;
		Execute.fx[0] = true;			//Spell AKA battlecry
		Execute.fx2[0] = "iff(damaged):min|cho1,tar|destroy";
		initCard(
			Execute,				//card
			"CS2_108",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Destroy a damaged enemy minion. It's okay, he deserved it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fan_of_Knives;
		Fan_of_Knives.fx[0] = true;			//Spell AKA battlecry
		Fan_of_Knives.fx2[0] = "nan:Oboard,Phand|min,nan|all,nan|dam+=1,draw(1)";
		initCard(
			Fan_of_Knives,				//card
			"EX1_129",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to all enemy minions. Draw a card. I wouldn't say I LOVE knives, but I'm definitely a fan.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fiery_War_Axe;
		initCard(
			Fiery_War_Axe,				//card
			"CS2_106",				//id
			"Free",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			3,				//atk
			0,				//hp
			"During times of tranquility and harmony, this weapon was called by its less popular name, Chilly Peace Axe.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fire_Elemental;
		Fire_Elemental.fx[0] = true;			//Battlecry
		Fire_Elemental.fx2[0] = "nan:board|cha|cho1|dam+=3";
		initCard(
			Fire_Elemental,				//card
			"CS2_042",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			5,				//hp
			"<b>Battlecry:</b> Deal 3 damage. He can never take a bath. Ewww.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fireball;
		Fireball.fx[0] = true;			//Spell AKA battlecry
		Fireball.fx2[0] = "nan:board|cha|cho1|dam+=6";
		initCard(
			Fireball,				//card
			"CS2_029",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $6 damage. This spell is useful for burning things.  If you're looking for spells that toast things, or just warm them a little, you're in the wrong place.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flamestrike;
		Flamestrike.fx[0] = true;			//Spell AKA battlecry
		Flamestrike.fx2[0] = "nan:Oboard|min|all|dam+=4";
		initCard(
			Flamestrike,				//card
			"CS2_032",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			7,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage to all enemy minions. When the ground is on fire, you should <i>not</i> stop, drop, and roll.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flametongue_Totem;
		Flametongue_Totem.fx[15] = true;	//aura
		Flametongue_Totem.fx2[15] = "nan:board|min|adj|atk+=2";
		initCard(
			Flametongue_Totem,				//card
			"EX1_565",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			3,				//hp
			"Adjacent minions have +2 Attack. Totemsmiths like to use the rarest woods for their totems.  There are even rumors of totems made of Ironbark Protectors.",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Frog;
		Frog.fx[10] = true;			//Taunt
		initCard(
			Frog,				//card
			"hexfrog",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			1,				//hp
			"<b>Taunt</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Frost_Nova;
		Frost_Nova.fx[5] = true;			//Freeze
		Frost_Nova.fx[0] = true;			//Spell AKA battlecry
		Frost_Nova.fx2[0] = "nan:Oboard|min|all|freeze";
		initCard(
			Frost_Nova,				//card
			"CS2_026",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Freeze</b> all enemy minions. Hey man, that's cold.  Literally and metaphorically.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frost_Shock;
		Frost_Shock.fx[5] = true;			//Freeze
		Frost_Shock.fx[0] = true;			//Spell AKA battlecry
		Frost_Shock.fx2[0] = "nan:Oboard|cha|cho1|dam+=1";
		initCard(
			Frost_Shock,				//card
			"CS2_037",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to an enemy character and <b>Freeze</b> it. FROST SHOCK!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frostbolt;
		Frostbolt.fx[5] = true;			//Freeze
		Frostbolt.fx[0] = true;			//Spell AKA battlecry
		Frostbolt.fx2[0] = "nan:board|cha|cho1,tar|dam+=3,freeze";
		initCard(
			Frostbolt,				//card
			"CS2_024",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to a character and <b>Freeze</b> it. It is customary to yell \"Chill out!\" or \"Freeze!\" or \"Ice ice, baby!\" when you play this card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frostwolf_Grunt;
		Frostwolf_Grunt.fx[10] = true;			//Taunt
		initCard(
			Frostwolf_Grunt,				//card
			"CS2_121",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Taunt</b> Grunting is what his father did and his father before that.   It's more than just a job.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frostwolf_Warlord;
		Frostwolf_Warlord.fx[0] = true;			//Battlecry
		Frostwolf_Warlord.fx2[0] = "nan:Pboard|nan|self|atk+=num(Pmin),hp+=num(Pmin)";
		initCard(
			Frostwolf_Warlord,				//card
			"CS2_226",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Gain +1/+1 for each other friendly minion on the battlefield. The Frostwolves are locked in combat with the Stormpike Expedition over control of Alterac Valley.  Every attempt at peace-talks has ended with Captain Galvangar killing the mediator.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gnomish_Inventor;
		Gnomish_Inventor.fx[0] = true;			//Battlecry
		Gnomish_Inventor.fx2[0] = "nan:Phand|nan|nan|draw(1)";
		initCard(
			Gnomish_Inventor,				//card
			"CS2_147",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> Draw a card. She's never quite sure what she's making, she just knows it's AWESOME!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Goldshire_Footman;
		Goldshire_Footman.fx[10] = true;			//Taunt
		initCard(
			Goldshire_Footman,				//card
			"CS1_042",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Taunt</b> If 1/2 minions are all that is defending Goldshire, you would think it would have been overrun years ago.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grimscale_Oracle;
		Grimscale_Oracle.fx[15] = true;		//aura
		Grimscale_Oracle.fx2[15] = "nan:board|murloc|!self|atk+=1";
		initCard(
			Grimscale_Oracle,				//card
			"EX1_508",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"ALL other Murlocs have +1 Attack. These are the brainy murlocs.  It turns out that doesn’t mean much.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Guardian_of_Kings;
		Guardian_of_Kings.fx[0] = true;			//Battlecry
		Guardian_of_Kings.fx2[0] = "nan:Pboard|hero|nan|dam-=6";
		initCard(
			Guardian_of_Kings,				//card
			"CS2_088",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			6,				//hp
			"<b>Battlecry:</b> Restore 6 Health to your hero. Holy beings from the beyond are so cliché!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gurubashi_Berserker;
		Gurubashi_Berserker.fx[16] = true;		//trigger
		Gurubashi_Berserker.fx2[16] = "ift(damaged):Pboard|nan|self|nan,atk+=3";
		initCard(
			Gurubashi_Berserker,				//card
			"EX1_399",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			2,				//atk
			7,				//hp
			"Whenever this minion takes damage, gain +3 Attack. No Pain, No Gain.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hammer_of_Wrath;
		Hammer_of_Wrath.fx[0] = true;			//Spell AKA battlecry
		Hammer_of_Wrath.fx2[0] = "nan:board,Phand|min,nan|cho1,nan|dam+=3,draw(1)";
		initCard(
			Hammer_of_Wrath,				//card
			"CS2_094",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage.\nDraw a card. A good paladin has many tools.  Hammer of Wrath, Pliers of Vengeance, Hacksaw of Justice, etc.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hand_of_Protection;
		Hand_of_Protection.fx[0] = true;			//Spell AKA battlecry
		Hand_of_Protection.fx2[0] = "nan:board|min|cho1|fx[3]=true";
		initCard(
			Hand_of_Protection,				//card
			"EX1_371",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion <b>Divine Shield</b>. This spell has been renamed so many times, even paladins don’t know what it should be called anymore.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Healing_Totem;
		Healing_Totem.fx2[14] = true;		//turnpoint
		Healing_Totem.fx[14] = "PE:Pboard|min|all|dam-=1";
		initCard(
			Healing_Totem,				//card
			"NEW1_009",				//id
			"Free",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			2,				//hp
			"At the end of your turn, restore 1 Health to all friendly minions.",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Healing_Touch;
		Healing_Touch.fx[0] = true;			//Spell AKA battlecry
		Healing_Touch.fx2[0] = "nan:board|cha|cho1|dam-=8";
		initCard(
			Healing_Touch,				//card
			"CS2_007",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Restore #8 Health. 8 Health, no waiting.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hellfire;
		Hellfire.fx[0] = true;			//Spell AKA battlecry
		Hellfire.fx2[0] = "nan:board|cha|all|dam+=3";
		initCard(
			Hellfire,				//card
			"CS2_062",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to ALL characters. It's spells like these that make it hard for Warlocks to get decent help.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Heroic_Strike;
		Heroic_Strike.fx[0] = true;			//Spell AKA battlecry
		Heroic_Strike.fx2[0] = "nan:time(till,PE):Pboard|hero|nan|atk+=4";
		initCard(
			Heroic_Strike,				//card
			"CS2_105",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give your hero +4 Attack this turn. Really, if you're a hero, this is <i>every</i> strike.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hex;
		Hex.fx[0] = true;			//Spell AKA battlecry
		Hex.fx2[0] = "nan:board|min|cho1|transform(Frog)";
		initCard(
			Hex,				//card
			"EX1_246",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Transform a minion into a 0/1 Frog with <b>Taunt</b>. If you Hex a Murloc... it really isn't much of a change, is it?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Light;
		Holy_Light.fx[0] = true;			//Spell AKA battlecry
		Holy_Light.fx2[0] = "nan:board|cha|cho1|dam-=6";
		initCard(
			Holy_Light,				//card
			"CS2_089",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Restore #6 Health. If you are often bathed in Holy Light, you should consider wearing sunscreen.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Nova;
		Holy_Nova.fx[0] = true;			//Spell AKA battlecry
		Holy_Nova.fx2[0] = "nan:Oboard|cha|all|dam+=2";
		initCard(
			Holy_Nova,				//card
			"CS1_112",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to all enemies. Restore #2 Health to all friendly characters. If the Holy Light forsakes you, good luck casting this spell.  Also, you're probably a jerk.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Smite;
		Holy_Smite.fx[0] = true;			//Spell AKA battlecry
		Holy_Smite.fx2[0] = "nan:board|min|cho1|dam+=2";
		initCard(
			Holy_Smite,				//card
			"CS1_130",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage. It doesn't matter how pious you are.  Everyone needs a good smiting now and again.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Houndmaster;
		Houndmaster.fx[0] = true;			//Battlecry
		Houndmaster.fx2[0] = "nan:Pboard|beast|cho1,tar,tar|atk+=2,hp+=2,fx[11]=true";
		initCard(
			Houndmaster,				//card
			"DS1_070",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> Give a friendly Beast +2/+2 and <b>Taunt</b>. \"Who let the dogs out?\" he asks.  It's rhetorical.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Huffer;
		Huffer.fx[1] = true;			//Charge
		initCard(
			Huffer,				//card
			"NEW1_034",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Charge</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Humility;
		Humility.fx[0] = true;			//Spell AKA battlecry
		Humility.fx2[0] = "nan:board|min|cho1|atk=1";
		initCard(
			Humility,				//card
			"EX1_360",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Change a minion's Attack to 1. This card makes something really damp.  Oh wait.  That's \"Humidity.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hunters_Mark;
		Hunters_Mark.fx[0] = true;			//Spell AKA battlecry
		Hunters_Mark.fx2[0] = "nan:board|min|cho1|hp=1";
		initCard(
			Hunters_Mark,				//card
			"CS2_084",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Change a minion's Health to 1. Never play 'Hide and Go Seek' with a Hunter.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Innervate;
		Innervate.fx[0] = true;			//Spell AKA battlecry
		Innervate.fx2[0] = "nan:time(till,PE):Pboard|nan|nan|PCMana+=2";
		initCard(
			Innervate,				//card
			"EX1_169",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Gain 2 Mana Crystals this turn only. Some druids still have flashbacks from strangers yelling \"Innervate me!!\" at them.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ironbark_Protector;
		Ironbark_Protector.fx[10] = true;			//Taunt
		initCard(
			Ironbark_Protector,				//card
			"CS2_232",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			8,				//atk
			8,				//hp
			"<b>Taunt</b> I <i>dare</i> you to attack Darnassus.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ironforge_Rifleman;
		Ironforge_Rifleman.fx[0] = true;			//Battlecry
		Ironforge_Rifleman.fx2[0] = "nan:board|cha|cho1|dam+=1";
		initCard(
			Ironforge_Rifleman,				//card
			"CS2_141",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 1 damage. \"Ready! Aim! Drink!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ironfur_Grizzly;
		Ironfur_Grizzly.fx[10] = true;			//Taunt
		initCard(
			Ironfur_Grizzly,				//card
			"CS2_125",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Taunt</b> \"Bear Carcass 1/10\"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Kill_Command;
		Kill_Command.fx[0] = true;			//Spell AKA battlecry
		Kill_Command.fx2[0] = "if(Pboard,num(PBbeast)>0):board|min|cho1|dam+=3,dam+=5";
		initCard(
			Kill_Command,				//card
			"EX1_539",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage. If you have a Beast, deal $5 damage instead. \"Kill!\", he commanded.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kobold_Geomancer;
		Kobold_Geomancer.fx[15] = true;		//aura
		Kobold_Geomancer.fx2[15] = "nan:Pboard|nan|nan|spDam+=1";
		initCard(
			Kobold_Geomancer,				//card
			"CS2_142",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Spell Damage +1</b> In the old days, Kobolds were the finest candle merchants in the land. Then they got pushed too far...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Korkron_Elite;
		Korkron_Elite.fx[1] = true;			//Charge
		initCard(
			Korkron_Elite,				//card
			"NEW1_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Charge</b> The Kor'kron are the elite forces of Garrosh Hellscream. Let's just say you don't want to run into these guys while wearing a blue tabard.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Leokk;
		Leokk.fx[15] = true;		//aura
		Leokk.fx2[15] = "nan:Pboard|min|!self|atk+=1";
		initCard(
			Leokk,				//card
			"NEW1_033",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Your other minions have +1 Attack.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Lights_Justice;
		initCard(
			Lights_Justice,				//card
			"CS2_091",				//id
			"Free",				//rarity
			true,					//Collect
			"Weapon",				//type
			1,				//cost
			1,				//atk
			0,				//hp
			"Prince Malchezaar was a collector of rare weapons. He'd animate them and have them dance for him.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lord_of_the_Arena;
		Lord_of_the_Arena.fx[10] = true;			//Taunt
		initCard(
			Lord_of_the_Arena,				//card
			"CS2_162",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			5,				//hp
			"<b>Taunt</b> He used to be a 2100+ rated arena player, but that was years ago and nobody can get him to shut up about it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Magma_Rager;
		initCard(
			Magma_Rager,				//card
			"CS2_118",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			5,				//atk
			1,				//hp
			"He likes to think he is powerful, but pretty much anyone can solo Molten Core now.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mark_of_the_Wild;
		Mark_of_the_Wild.fx[0] = true;			//Spell AKA battlecry
		Mark_of_the_Wild.fx2[0] = "nan:board|min|cho1|atk+=2,hp+=2,fx[11]=true";
		initCard(
			Mark_of_the_Wild,				//card
			"CS2_009",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give a minion <b>Taunt</b> and +2/+2.<i> (+2 Attack/+2 Health)</i> Not to be confused with Jim of the Wild.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mechanical_Dragonling;
		initCard(
			Mechanical_Dragonling,				//card
			"EX1_025t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mind_Blast;
		Mind_Blast.fx[0] = true;			//Spell AKA battlecry
		Mind_Blast.fx2[0] = "nan:Oboard|hero|nan|dam+=5";
		initCard(
			Mind_Blast,				//card
			"DS1_233",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage to the enemy hero. This spell blasts you directly in the MIND.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mind_Control;
		Mind_Control.fx[0] = true;			//Spell AKA battlecry
		Mind_Control.fx2[0] = "nan:Oboard|min|cho1|control";
		initCard(
			Mind_Control,				//card
			"CS1_113",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			10,				//cost
			0,				//atk
			0,				//hp
			"Take control of an enemy minion. Nominated as \"Spell Most Likely to Make Your Opponent Punch the Wall.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mind_Vision;
		Mind_Vision.fx[0] = true;			//Spell AKA battlecry
		Mind_Vision.fx2[0] = "nan:Phand|nan|nan|copy(rnd)";
		initCard(
			Mind_Vision,				//card
			"CS2_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Put a copy of a random card in your opponent's hand into your hand. I see what you did there.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mirror_Image;
		Mirror_Image.fx[10] = true;			//Taunt
		initCard(
			Mirror_Image,				//card
			"CS2_mirror",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mirror_Image;
		Mirror_Image.fx[0] = true;			//Spell AKA battlecry
		Mirror_Image.fx2[0] = "nan:Pboard|nan|nan|summon2(Mirror_Image)";
		initCard(
			Mirror_Image,				//card
			"CS2_027",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Summon two 0/2 minions with <b>Taunt</b>. Oh hey it's Mirror Image! !egamI rorriM s'ti yeh hO",
			"",				//race
			""				//hero
			);
	}
	{
		Card Misha;
		Misha.fx[10] = true;			//Taunt
		initCard(
			Misha,				//card
			"NEW1_032",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			4,				//hp
			"<b>Taunt</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Moonfire;
		Moonfire.fx[0] = true;			//Spell AKA battlecry
		Moonfire.fx2[0] = "nan:board|cha|cho1|dam+=1";
		initCard(
			Moonfire,				//card
			"CS2_008",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage. \"Cast Moonfire, and never stop.\" - How to Be a Druid, Chapter 5, Section 3",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mortal_Coil;
		Mortal_Coil.fx[0] = true;			//Spell AKA battlecry
		Mortal_Coil.fx2[0] = "ift(killed):board,Phand|min,nan|cho1,nan|dam+=1,draw(1)";
		initCard(
			Mortal_Coil,				//card
			"EX1_302",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to a minion. If that kills it, draw a card. If your spells look like horrifying skulls, let's be honest, you should get to draw some cards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Multi_Shot;
		Multi_Shot.fx[0] = true;			//Spell AKA battlecry
		Multi_Shot.fx2[0] = "nan:Oboard|min|rnd2|dam+=3";
		initCard(
			Multi_Shot,				//card
			"DS1_183",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to two random enemy minions. You see, it's all about <i>throughput</i>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Raider;
		initCard(
			Murloc_Raider,				//card
			"CS2_168",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"Mrrraggglhlhghghlgh, mrgaaag blarrghlgaahahl mrgggg glhalhah a bghhll graggmgmg Garrosh mglhlhlh mrghlhlhl!!",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Scout;
		initCard(
			Murloc_Scout,				//card
			"EX1_506a",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Tidehunter;
		Murloc_Tidehunter.fx[0] = true;			//Battlecry
		Murloc_Tidehunter.fx2[0] = "nan:Pboard|nan|nan|summon(Murloc_Scout=1)";
		initCard(
			Murloc_Tidehunter,				//card
			"EX1_506",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> Summon a 1/1 Murloc Scout. \"Death will rise, from the tides!\"",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card NOOOOOOOOOOOO;
		initCard(
			NOOOOOOOOOOOO,				//card
			"GAME_006",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Somehow, the card you USED to have has been deleted.  Here, have this one instead! Even your flavor text has been deleted. Dang.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nightblade;
		Nightblade.fx[0] = true;			//Battlecry
		Nightblade.fx2[0] = "nan:Oboard|hero|nan|dam+=3";
		initCard(
			Nightblade,				//card
			"EX1_593",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry: </b>Deal 3 damage to the enemy hero. Your face is the place you'd probably least like a dagger, and where rogues are most likely to deliver them.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Northshire_Cleric;
		Northshire_Cleric.fx[16] = true;		//trigger
		Northshire_Cleric.fx2[16] = "ift(healed):board|min|all|draw(1)";
		initCard(
			Northshire_Cleric,				//card
			"CS2_235",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			3,				//hp
			"Whenever a minion is healed, draw a card. They help the downtrodden and distressed.  Also they sell cookies.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Novice_Engineer;
		Novice_Engineer.fx[0] = true;			//Battlecry
		Novice_Engineer.fx2[0] = "nan:Phand|nan|nan|draw(1)";
		initCard(
			Novice_Engineer,				//card
			"EX1_015",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			1,				//hp
			"<b>Battlecry:</b> Draw a card. \"Half of this class will not graduate… since they'll have been turned to chickens.\" - Tinkmaster Overspark, teaching Gizmos 101.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Oasis_Snapjaw;
		initCard(
			Oasis_Snapjaw,				//card
			"CS2_119",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			7,				//hp
			"His dreams of flying and breathing fire like his idol will never be realized.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Ogre_Magi;
		Ogre_Magi.fx[15] = true;		//aura
		Ogre_Magi.fx2[15] = "nan:Pboard|nan|nan|spDam+=1";
		initCard(
			Ogre_Magi,				//card
			"CS2_197",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Spell Damage +1</b> Training Ogres in the art of spellcasting is a questionable decision.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Polymorph;
		Polymorph.fx[0] = true;			//Spell AKA battlecry
		Polymorph.fx2[0] = "nan:board|min|cho1|transform(Sheep)";
		initCard(
			Polymorph,				//card
			"CS2_022",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Transform a minion into a 1/1 Sheep. There was going to be a pun in this flavor text, but it just came out baa-d.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Power_Word__Shield;
		Power_Word__Shield.fx[0] = true;			//Spell AKA battlecry
		Power_Word__Shield.fx2[0] = "nan:board,Phand|min,nan|cho1,nan|hp+=2,draw(1)";
		initCard(
			Power_Word__Shield,				//card
			"CS2_004",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +2 Health.\nDraw a card. Sure the extra protection is nice, but the shield really reduces visibility.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Raid_Leader;
		Raid_Leader.fx[15] = true;		//aura
		Raid_Leader.fx2[15] = "nan:Pboard|min|!self|atk+=1";
		initCard(
			Raid_Leader,				//card
			"CS2_122",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"Your other minions have +1 Attack. \"That's a 50 DKP minus!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Razorfen_Hunter;
		Razorfen_Hunter.fx[0] = true;			//Battlecry
		Razorfen_Hunter.fx2[0] = "nan:Pboard|nan|nan|summon(Boar=1)";
		initCard(
			Razorfen_Hunter,				//card
			"CS2_196",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Summon a 1/1 Boar. Someone did mess with Tuskerr once.  ONCE.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Reckless_Rocketeer;
		Reckless_Rocketeer.fx[1] = true;			//Charge
		initCard(
			Reckless_Rocketeer,				//card
			"CS2_213",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			2,				//hp
			"<b>Charge</b> One Insane Rocketeer.   One Rocket full of Explosives.   Infinite Fun.",
			"",				//race
			""				//hero
			);
	}
	{
		Card River_Crocolisk;
		initCard(
			River_Crocolisk,				//card
			"CS2_120",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Edward \"Lefty\" Smith tried to make luggage out of a river crocolisk once.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Rockbiter_Weapon;
		Rockbiter_Weapon.fx[0] = true;			//Spell AKA battlecry
		Rockbiter_Weapon.fx2[0] = "time(till,PE):Pboard|cha|cho1|atk+=3";
		initCard(
			Rockbiter_Weapon,				//card
			"CS2_045",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a friendly character +3 Attack this turn. This would be real handy if your enemy is made of rock.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sacrificial_Pact;
		Sacrificial_Pact.fx[0] = true;			//Spell AKA battlecry
		Sacrificial_Pact.fx2[0] = "nan:board,Pboard|demon,hero|cho1,nan|destroy,dam-=5";
		initCard(
			Sacrificial_Pact,				//card
			"NEW1_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy a Demon. Restore #5 Health to your hero. This is the reason that Demons never really become friends with Warlocks.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sap;
		Sap.fx[0] = true;			//Spell AKA battlecry
		Sap.fx2[0] = "nan:Oboard|min|cho1|return";
		initCard(
			Sap,				//card
			"EX1_581",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Return an enemy minion to your opponent's hand. Rogues love sappy movies.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Savage_Roar;
		Savage_Roar.fx[0] = true;			//Spell AKA battlecry
		Savage_Roar.fx2[0] = "time(till,PE):board|cha|all|atk+=2";
		initCard(
			Savage_Roar,				//card
			"CS2_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Give your characters +2 Attack this turn. What do they roar? Nobody can quite tell, but it sounds like \"Elephant Macho Breeze\".  It's probably not that, though.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Searing_Totem;
		initCard(
			Searing_Totem,				//card
			"CS2_050",				//id
			"Free",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Senjin_Shieldmasta;
		Senjin_Shieldmasta.fx[10] = true;			//Taunt
		initCard(
			Senjin_Shieldmasta,				//card
			"CS2_179",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"<b>Taunt</b> Sen'jin Villiage is nice, if you like trolls and dust.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadow_Bolt;
		Shadow_Bolt.fx[0] = true;			//Spell AKA battlecry
		Shadow_Bolt.fx2[0] = "nan:board|min|cho1|dam+=4";
		initCard(
			Shadow_Bolt,				//card
			"CS2_057",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage to a minion. It’s a Bolt.   Its made out of Shadow.   What more do you need to know!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadow_Word__Death;
		Shadow_Word__Death.fx[0] = true;			//Spell AKA battlecry
		Shadow_Word__Death.fx2[0] = "ift(atk>=5):board|min|cho1|nan,destroy";
		initCard(
			Shadow_Word__Death,				//card
			"EX1_622",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion with an Attack of 5 or more. If you miss, it leaves a lightning-bolt-shaped scar on your target.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadow_Word__Pain;
		Shadow_Word__Pain.fx[0] = true;			//Spell AKA battlecry
		Shadow_Word__Pain.fx2[0] = "ift(atk<=3):board|min|cho1|nan,destroy";
		initCard(
			Shadow_Word__Pain,				//card
			"CS2_234",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion with 3 or less Attack. A step up from a spell cast by many beginning acolytes: \"Shadow Word: Annoy\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shattered_Sun_Cleric;
		Shattered_Sun_Cleric.fx[0] = true;			//Battlecry
		Shattered_Sun_Cleric.fx2[0] = "nan:Pboard|min|cho1,tar|atk+=1,hp+=1";
		initCard(
			Shattered_Sun_Cleric,				//card
			"EX1_019",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give a friendly minion +1/+1. They always have a spare flask of Sunwell Energy Drink™!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sheep;
		initCard(
			Sheep,				//card
			"CS2_tk1",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Shield_Block;
		Shield_Block.fx[0] = true;			//Spell AKA battlecry
		Shield_Block.fx2[0] = "nan:Pboard,Phand|hero,nan|nan|armr+=5,draw(1)";
		initCard(
			Shield_Block,				//card
			"EX1_606",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Gain 5 Armor.\nDraw a card. Shields were invented because Face Block is USELESS.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shiv;
		Shiv.fx[0] = true;			//Spell AKA battlecry
		Shiv.fx2[0] = "nan:board,Phand|cha,nan|cho1,nan|dam+=2,draw(1)";
		initCard(
			Shiv,				//card
			"EX1_278",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage. Draw a card. Rogues are experts at SHIV-al-ry.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silver_Hand_Recruit;
		initCard(
			Silver_Hand_Recruit,				//card
			"CS2_101t",				//id
			"Free",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silverback_Patriarch;
		Silverback_Patriarch.fx[10] = true;			//Taunt
		initCard(
			Silverback_Patriarch,				//card
			"CS2_127",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"<b>Taunt</b> He likes to act like he's in charge, but the silverback matriarch actually runs things.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Sinister_Strike;
		Sinister_Strike.fx[0] = true;			//Spell AKA battlecry
		Sinister_Strike.fx2[0] = "nan:Oboard|hero|nan|dam+=3";
		initCard(
			Sinister_Strike,				//card
			"CS2_075",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to the enemy hero. There's something about this strike that just feels off.  Sinister, even.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Skeleton;
		initCard(
			Skeleton,				//card
			"skele11",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b></b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Soulfire;
		Soulfire.fx[0] = true;			//Spell AKA battlecry
		Soulfire.fx2[0] = "nan:board,Phand|cha,nan|cho1,rnd1|dam+=4,discard";
		initCard(
			Soulfire,				//card
			"EX1_308",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage. Discard a random card. Are you lighting a soul on fire? Or burning someone with your OWN soul? This seems like an important distinction.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sprint;
		Sprint.fx[0] = true;			//Spell AKA battlecry
		Sprint.fx2[0] = "nan:Phand|nan|nan|draw(4)";
		initCard(
			Sprint,				//card
			"CS2_077",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			7,				//cost
			0,				//atk
			0,				//hp
			"Draw 4 cards. Rogues are not good joggers.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Starfire;
		Starfire.fx[0] = true;			//Spell AKA battlecry
		Starfire.fx2[0] = "nan:board,Phand|min,nan|cho1,nan|dam+=5,draw(1)";
		initCard(
			Starfire,				//card
			"EX1_173",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage.\nDraw a card. Balance is important to druids.  This card is perfectly balanced.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Starving_Buzzard;
		Starving_Buzzard.fx[16] = true;		//trigger
		Starving_Buzzard.fx2[16] = "ift(summoned):Pboard,Phand|beast,nan|nan|nan,draw(1)";
		initCard(
			Starving_Buzzard,				//card
			"CS2_237",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			2,				//hp
			"Whenever you summon a Beast, draw a card. If you feed him, he loses his whole <i>identity</i>.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Stoneclaw_Totem;
		Stoneclaw_Totem.fx[10] = true;			//Taunt
		initCard(
			Stoneclaw_Totem,				//card
			"CS2_051",				//id
			"Free",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Stonetusk_Boar;
		Stonetusk_Boar.fx[1] = true;			//Charge
		initCard(
			Stonetusk_Boar,				//card
			"CS2_171",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Charge</b> This card is boaring.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Stormpike_Commando;
		Stormpike_Commando.fx[0] = true;			//Battlecry
		Stormpike_Commando.fx2[0] = "nan:board|min|cho1|dam+=2";
		initCard(
			Stormpike_Commando,				//card
			"CS2_150",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 2 damage. The Stormpike Commandos are demolition experts.  They also bake a mean cupcake.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stormwind_Champion;
		Stormwind_Champion.fx[15] = true;		//aura
		Stormwind_Champion.fx2[15] = "Pboard|min|!self|atk+=1,hp+=1";
		initCard(
			Stormwind_Champion,				//card
			"CS2_222",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			6,				//hp
			"Your other minions have +1/+1. When Deathwing assaulted the capital, this soldier was the only member of his squad to survive. Now he's all bitter and stuff.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stormwind_Knight;
		Stormwind_Knight.fx[1] = true;			//Charge
		initCard(
			Stormwind_Knight,				//card
			"CS2_131",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"<b>Charge</b> They're still embarassed about \"The Deathwing Incident\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Succubus;
		Succubus.fx[0] = true;			//Battlecry
		Succubus.fx2[0] = "nan:Phand|nan|rnd1|discard";
		initCard(
			Succubus,				//card
			"EX1_306",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> Discard a random card. Warlocks have it pretty good.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Swipe;
		Swipe.fx[0] = true;			//Spell AKA battlecry
		Swipe.fx2[0] = "nan:Oboard|cha|cho1,!tar|dam+=4,dam+=1";
		initCard(
			Swipe,				//card
			"CS2_012",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage to an enemy and $1 damage to all other enemies. When a bear rears back and extends his arms, he's about to Swipe!  ... or hug.",
			"",				//race
			""				//hero
			);
	}
	{
		Card The_Coin;
		The_Coin.fx[0] = true;			//Spell AKA battlecry
		The_Coin.fx2[0] = "time(till,PE):Pboard|nan|nan|PCMana+=1";
		initCard(
			The_Coin,				//card
			"GAME_005",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Gain 1 Mana Crystal this turn only.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Timber_Wolf;
		Timber_Wolf.fx[15] = true;		//aura
		Timber_Wolf.fx2[15] = "Pboard|beast|!self|atk+=1";
		initCard(
			Timber_Wolf,				//card
			"DS1_175",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"Your other Beasts have +1 Attack. Other beasts totally dig hanging out with timber wolves.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Totemic_Might;
		Totemic_Might.fx[0] = true;			//Spell AKA battlecry
		Totemic_Might.fx2[0] = "nan:Pboard|totem|all|hp+=2";
		initCard(
			Totemic_Might,				//card
			"EX1_244",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give your Totems +2 Health. Totem-stomping is no longer recommended.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tracking;
		Tracking.fx[0] = true;			//Spell AKA battlecry
		Tracking.fx2[0] = "nan:Pboard|nan|nan|peek(3)";
		initCard(
			Tracking,				//card
			"DS1_184",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Look at the top three cards of your deck. Draw one and discard the others. For the person who just cannot decide what card to put into a deck!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Truesilver_Champion;
		Truesilver_Champion.fx[16] = true;		//aura
		Truesilver_Champion.fx2[16] = "ift(attacks):Pboard|hero|nan|nan,dam-=2";
		initCard(
			Truesilver_Champion,				//card
			"CS2_097",				//id
			"Common",				//rarity
			true,					/
			/Collect
			"Weapon",				//type
			4,				//cost
			4,				//atk
			0,				//hp
			"Whenever your hero attacks, restore 2 Health to it. It Slices, it Dices. You can cut a tin can with it. (But you wouldn't want to.)",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tundra_Rhino;
		Tundra_Rhino.fx[15] = true;			//aura
		Tundra_Rhino.fx2[15] = "nan:Pboard|beast|all|fx[1]=true";
		initCard(
			Tundra_Rhino,				//card
			"DS1_178",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			2,				//atk
			5,				//hp
			"Your Beasts have <b>Charge</b>. Tundra rhinos are often mistaken for kodos.  Or am I mistaken?",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Vanish;
		Vanish.fx[0] = true;			//Spell AKA battlecry
		Vanish.fx2[0] = "nan:board|min|all|return";
		initCard(
			Vanish,				//card
			"NEW1_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Return all minions to their owner's hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Voidwalker;
		Voidwalker.fx[10] = true;			//Taunt
		initCard(
			Voidwalker,				//card
			"CS2_065",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			3,				//hp
			"<b>Taunt</b> No relation to \"The Voidsteppers\", the popular Void-based dance troupe.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Voodoo_Doctor;
		Voodoo_Doctor.fx[0] = true;			//Battlecry
		Voodoo_Doctor.fx2[0] = "nan:board|cha|cho1|dam-=2";
		initCard(
			Voodoo_Doctor,				//card
			"EX1_011",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> Restore 2 Health. Voodoo is an oft-misunderstood art. But it <i>is</i> art.",
			"",				//race
			""				//hero
			);
	}
	{
		Card War_Golem;
		initCard(
			War_Golem,				//card
			"CS2_186",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			7,				//hp
			"Golems are not afraid, but for some reason they still run when you cast Fear on them.  Instinct, maybe?  A desire to blend in?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Warsong_Commander;
		Warsong_Commander.fx[16] = true;		//trigger
		Warsong_Commander.fx2[16] = "ift(summon,atk<=3):Pboard|min|nan,tar,tar|nan,nan,fx[1]=true";
		initCard(
			Warsong_Commander,				//card
			"EX1_084",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"Whenever you summon a minion with 3 or less Attack, give it <b>Charge</b>. The Warsong clan is <i>such drama</i>. It's really not worth it to become a commander.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Water_Elemental;
		Water_Elemental.fx[5] = true;			//Freeze
		Water_Elemental.fx[13] = true;			//thorns
		Water_Elemental.fx2[13] = "freeze";
		initCard(
			Water_Elemental,				//card
			"CS2_033",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			6,				//hp
			"<b>Freeze</b> any character damaged by this minion. Don't summon a water elemental at a party.  It'll dampen the mood.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Whirlwind;
		Whirlwind.fx[0] = true;			//Spell AKA battlecry
		Whirlwind.fx2[0] = "nan:board|min|all|dam+=1";
		initCard(
			Whirlwind,				//card
			"EX1_400",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to ALL minions. The way to tell seasoned warriors from novice ones: the novices yell \"wheeeee\" while whirlwinding.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wicked_Knife;
		initCard(
			Wicked_Knife,				//card
			"CS2_082",				//id
			"Free",				//rarity
			false,					//Collect
			"Weapon",				//type
			1,				//cost
			1,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wild_Growth;
		Wild_Growth.fx[0] = true;			//Spell AKA battlecry
		Wild_Growth.fx2[0] = "nan:Pboard|nan|nan|PMMana+=1";
		initCard(
			Wild_Growth,				//card
			"CS2_013",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Gain an empty Mana Crystal. Grow your own mana crystals with this Mana Crystal Growth Kit, only 39.99!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Windfury;
		Windfury.fx[0] = true;			//Spell AKA battlecry
		Windfury.fx2[0] = "nan:board|min|cho1|fx[12]=true";
		initCard(
			Windfury,				//card
			"CS2_039",				//id
			"Free",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give a minion <b>Windfury</b>. Windfury is like Earthfury and Firefury, but more light and airy.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Windspeaker;
		Windspeaker.fx[0] = true;			//Battlecry
		Windspeaker.fx2[0] = "nan:Pboard|min|cho1|fx[12]=true";
		initCard(
			Windspeaker,				//card
			"EX1_587",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Give a friendly minion <b>Windfury</b>. Is there anything worse than a Windspeaker with halitosis?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wolfrider;
		Wolfrider.fx[1] = true;			//Charge
		initCard(
			Wolfrider,				//card
			"CS2_124",				//id
			"Free",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			1,				//hp
			"<b>Charge</b> Orcish raiders ride wolves because they are well adapted to harsh environments, and because they are soft and cuddly.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wrath_of_Air_Totem;
		Wrath_of_Air_Totem.fx[15] = true;		//aura
		Wrath_of_Air_Totem.fx2[15] = "Pboard|nan|nan|spDam+=1";
		initCard(
			Wrath_of_Air_Totem,				//card
			"CS2_052",				//id
			"Free",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			2,				//hp
			"<b>Spell Damage +1</b>",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Arcanotron;
		Arcanotron.fx[15] = true;		//aura
		Arcanotron.fx2[15] = "board|nan|nan|spDam+=2";
		initCard(
			Arcanotron,				//card
			"BRMA14_3",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			2,				//atk
			2,				//hp
			"Both players have <b>Spell Damage +2</b>.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Axe_Flinger;
		Axe_Flinger.fx[16] = true;		//trigger
		Axe_Flinger.fx2[16] = "ift(damaged):Pboard,Oboard|nan,hero|self,nan|nan,dam+=2";
		initCard(
			Axe_Flinger,				//card
			"BRM_016",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"Whenever this minion takes damage, deal 2 damage to the enemy hero. Once a lowly \"Stick Flinger\", he's been relentless on the path to his ultimate dream: \"Tauren Flinger\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Black_Whelp;
		initCard(
			Black_Whelp,				//card
			"BRM_022t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Blackwing_Corruptor;
		Blackwing_Corruptor.fx[0] = true;			//Battlecry
		Blackwing_Corruptor.fx2[0] = "if(num(dragon)>0):Phand,board|nan,cha|nan,cho1|nan,dam+=3";
		initCard(
			Blackwing_Corruptor,				//card
			"BRM_034",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry</b>: If you're holding a Dragon, deal 3 damage. He got his name when he gave Blackwing some comic books and rock & roll records.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blackwing_Technician;
		Blackwing_Technician.fx[0] = true;			//Battlecry
		Blackwing_Technician.fx2[0] = "if(num(dragon)>0):Phand,Pboard,Pboard|nan|nan,self,self|nan,atk+=1,hp+=1";
		initCard(
			Blackwing_Technician,				//card
			"BRM_033",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, gain +1/+1. This is who you go to when your Blackwing needs a tune up. Don't go to a cut rate Blackwing tune up shop!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bone_Construct;
		initCard(
			Bone_Construct,				//card
			"BRMA17_6",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bone_Construct;
		initCard(
			Bone_Construct,				//card
			"BRMA17_6H",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			4,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Burning_Adrenaline;
		Burning_Adrenaline.fx[0] = true;			//Spell AKA battlecry
		Burning_Adrenaline.fx2[0] = "nan:Oboard|hero|nan|dam+=2";
		initCard(
			Burning_Adrenaline,				//card
			"BRMA11_3",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to the enemy hero.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Chromaggus;
		Chromaggus.fx[16] = true;		//trigger
		Chromaggus.fx2[16] = "draw(P):Phand|nan|nan|get(tar)";
		initCard(
			Chromaggus,				//card
			"BRM_031",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			6,				//atk
			8,				//hp
			"Whenever you draw a card, put another copy into your hand. Left head and right head can never agree about what to eat for dinner, so they always end up just eating ramen again.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Chromatic_Dragonkin;
		Chromatic_Dragonkin.fx[16] = true;		//trigger
		Chromatic_Dragonkin.fx2[16] = "cast(O):Pboard|nan|self|atk+=2,hp+=2";
		initCard(
			Chromatic_Dragonkin,				//card
			"BRMA12_8t",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Whenever your opponent casts a spell, gain +2/+2.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Chromatic_Mutation;
		Chromatic_Mutation.fx[0] = true;			//Spell AKA battlecry
		Chromatic_Mutation.fx2[0] = "nan:board|min|cho1|transform(Chromatic_Dragonkin)";
		initCard(
			Chromatic_Mutation,				//card
			"BRMA12_8",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Transform a minion into a 2/2 Chromatic Dragonkin.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Chromatic_Prototype;
		Chromatic_Prototype.fx[10] = true;			//Taunt
		initCard(
			Chromatic_Prototype,				//card
			"BRMA17_7",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			4,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Core_Rager;
		Core_Rager.fx[0] = true;			//Battlecry
		Core_Rager.fx2[0] = "ift(num(Phand)=0):Phand,Pboard|nan|nan,self,self|nan,atk+=3,hp+=3";
		initCard(
			Core_Rager,				//card
			"BRM_014",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> If your hand is empty, gain +3/+3. It takes a special kind of hunter to venture deep into a firey lava pit and convince a monster who lives there to come home and be a cuddly housepet.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Dark_Iron_Skulker;
		Dark_Iron_Skulker.fx[0] = true;			//Battlecry
		Dark_Iron_Skulker.fx2[0] = "ift(!damaged):Oboard|min|all|nan,dam+=2";
		initCard(
			Dark_Iron_Skulker,				//card
			"BRM_008",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> Deal 2 damage to all undamaged enemy minions. He loves skulking. He skulks after hours just for the joy of it, but his friends are pretty worried he'll get burnt out.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Demonwrath;
		Demonwrath.fx[0] = true;			//Spell AKA battlecry
		Demonwrath.fx2[0] = "nan:board|!demon|all|dam+=2";
		initCard(
			Demonwrath,				//card
			"BRM_005",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to all non-Demon minions. Demons are not angry most of the time. You have to play this card in order to really bring it out of them.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragon_Consort;
		Dragon_Consort.fx[0] = true;			//Battlecry
		Dragon_Consort.fx2[0] = "nan:Pboard|dragon|nan|cheap(2)";
		initCard(
			Dragon_Consort,				//card
			"BRM_018",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> The next Dragon you play costs (2) less. Everybody wants someone to snuggle with. Even giant armored scaly draconic beasts of destruction.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Dragon_Egg;
		Dragon_Egg.fx[16] = true;		//trigger
		Dragon_Egg.fx2[16] = "ift(damaged):Pboard|nan|self,nan|nan,summon(whelp=1)";
		initCard(
			Dragon_Egg,				//card
			"BRM_022",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			2,				//hp
			"Whenever this minion takes damage, summon a 2/1 Whelp. Think of them as bullets for your dragon gun.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragons_Breath;
		Dragons_Breath.fx[0] = true;			//Spell AKA battlecry
		Dragons_Breath.fx2[0] = "cheap(num(PminKilled)):board|cha|cho1|dam+=4";
		initCard(
			Dragons_Breath,				//card
			"BRM_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage. Costs (1) less for each minion that died this turn. Dragons breathe fire, sure, but did you know they can also breathe Cotton Candy?  It's harder to give them a reason to do that, though.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragonkin;
		initCard(
			Dragonkin,				//card
			"BRMA09_4t",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			3,				//atk
			1,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Dragonkin;
		initCard(
			Dragonkin,				//card
			"BRMA09_4Ht",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			5,				//atk
			4,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Dragonkin_Sorcerer;
		Dragonkin_Sorcerer.fx[16] = true;		//trigger
		Dragonkin_Sorcerer.fx2[16] = "spelltar:Pboard|nan|self|atk+=1,hp+=1";
		initCard(
			Dragonkin_Sorcerer,				//card
			"BRM_020",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Whenever <b>you</b> target this minion with a spell, gain +1/+1. Dragonkin Sorcerers be all \"I'm a wizard\" and everyone else be all \"daaaaang\".",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Drakonid_Crusher;
		Drakonid_Crusher.fx[0] = true;			//Battlecry
		Drakonid_Crusher.fx2[0] = "ift(hp<=15):Oboard,Pboard,Pboard|hero,nan,nan|nan,self,self|nan,atk+=3,hp+=3";
		initCard(
			Drakonid_Crusher,				//card
			"BRM_024",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"<b>Battlecry:</b> If your opponent has 15 or less Health, gain +3/+3. Drakonids were created to have all the bad parts of a dragon in the form of a humaniod. But, like, why?",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Flame1;
		initCard(
			Druid_of_the_Flame1,				//card
			"BRM_010t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			5,				//atk
			2,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Flame;
		Druid_of_the_Flame.fx[0] = true;		//battlecry
		Druid_of_the_Flame.fx2[0] = "choose:Pboard|nan|self|transform(Druid_of_the_Flame1),transform(Druid_of_the_Flame2)";
		initCard(
			Druid_of_the_Flame,				//card
			"BRM_010",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Choose One</b> - Transform into a 5/2 minion; or a 2/5 minion. Druids who fought too long in Northrend were easily seduced by Ragnaros; a mug of hot chocolate was generally all it took.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Flame2;
		initCard(
			Druid_of_the_Flame2,				//card
			"BRM_010t2",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			5,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Emperor_Thaurissan;
		Emperor_Thaurissan.fx[14] = true;		//turnpoint
		Emperor_Thaurissan.fx[14] = "PE:Phand|card|all|cost-=1";
		initCard(
			Emperor_Thaurissan,				//card
			"BRM_028",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"At the end of your turn, reduce the Cost of cards in your hand by (1). His second greatest regret is summoning an evil Firelord who enslaved his entire people.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fireguard_Destroyer;
		Fireguard_Destroyer.fx[0] = true;			//Battlecry
		Fireguard_Destroyer.fx2[0] = "nan:Pboard|nan|self|atk+=rand(1,4)";
		Fireguard_Destroyer.fx[6] = true;			//Overload
		Fireguard_Destroyer.fx2[6] = "1";
		initCard(
			Fireguard_Destroyer,				//card
			"BRM_012",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			6,				//hp
			"<b>Battlecry:</b> Gain 1-4 Attack. <b>Overload:</b> (1) Ragnaros interviews hundreds of Fire Elementals for the position of \"Destroyer\" but very few have what it takes.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flamewaker;
		Flamewaker.fx[16] = true;		//trigger
		Flamewaker.fx2[16] = "castP:Oboard|cha|2rnd|dam+=1";
		initCard(
			Flamewaker,				//card
			"BRM_002",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"After you cast a spell, deal 2 damage randomly split among all enemies. Flamewakers HATE being confused for Flamewalkers. They just wake up fire, they don’t walk on it. Walking on fire is CRAZY.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gang_Up;
		Gang_Up.fx[0] = true;			//Spell AKA battlecry
		Gang_Up.fx2[0] = "nan:board,Pboard|min,nan|cho1,nan|nan,shuffle3(tar)";
		initCard(
			Gang_Up,				//card
			"BRM_007",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Choose a minion. Shuffle 3 copies of it into your deck. If you are thinking about visiting Moonbrook, you better roll deep.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grim_Patron;
		Grim_Patron.fx[16] = true;		//trigger
		Grim_Patron.fx2[16] = "survive:Pboard|nan|self,nan|nan,summon(Grim_Patron=1)";
		initCard(
			Grim_Patron,				//card
			"BRM_019",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			3,				//hp
			"Whenever this minion survives damage, summon another Grim Patron. If you love getting your face punched, come to the Grim Guzzler!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Imp;
		initCard(
			Imp,				//card
			"BRM_006t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Imp_Gang_Boss;
		Imp_Gang_Boss.fx[16] = true;		//trigger
		Imp_Gang_Boss.fx2[16] = "ift(damaged):Pboard|nan|self,nan|nan,summon(Imp=1)";
		initCard(
			Imp_Gang_Boss,				//card
			"BRM_006",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Whenever this minion takes damage, summon a 1/1 Imp. His imp gang likes to sneak into Stormwind to spraypaint \"Ragnaros Rulez\" on the Mage Tower.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card LAVA;
		LAVA.fx[0] = true;			//Spell AKA battlecry
		LAVA.fx2[0] = "nan:board|min|all|dam+=2";
		initCard(
			LAVA,				//card
			"BRMA17_4",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to all minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lava_Shock;
		Lava_Shock.fx[0] = true;			//Spell AKA battlecry
		Lava_Shock.fx2[0] = "nan:board,Pboard|min,nan|cho1,nan|dam+=2,unlock";
		initCard(
			Lava_Shock,				//card
			"BRM_011",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage.\nUnlock your <b>Overloaded</b> Mana Crystals. Chocolate lava cake is shockingly delicious.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Living_Lava;
		Living_Lava.fx[10] = true;			//Taunt
		initCard(
			Living_Lava,				//card
			"BRMA13_6",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			6,				//atk
			6,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Magmaw;
		Magmaw.fx[10] = true;			//Taunt
		initCard(
			Magmaw,				//card
			"BRMA14_12",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			10,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Majordomo_Executus;
		Majordomo_Executus.fx[2] = true;			//Deathrattle
		Majordomo_Executus.fx2[2] = "nan:Pboard|hero|nan|transform(Ragnaros)";
		initCard(
			Majordomo_Executus,				//card
			"BRM_027",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			9,				//atk
			7,				//hp
			"<b>Deathrattle:</b> Replace your hero with Ragnaros, the Firelord. You thought Executus turned you into Ragnaros, but really Ragnaros was in you the whole time.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nefarian;
		Nefarian.fx[0] = true;			//Battlecry
		Nefarian.fx2[0] = "nan:Phand|nan|nan|get2(rand(spell, Oclass))";
		initCard(
			Nefarian,				//card
			"BRM_030",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			8,				//hp
			"<b>Battlecry:</b> Add 2 random spells to your hand <i>(from your opponent's class)</i>. They call him \"Blackwing\" because he's a black dragon...... and he's got wings.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Onyxiclaw;
		initCard(
			Onyxiclaw,				//card
			"BRMA17_9",				//id
			"",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			2,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Quick_Shot;
		Quick_Shot.fx[0] = true;			//Spell AKA battlecry
		Quick_Shot.fx2[0] = "nan,ift(num):board,Phand,Phand|nan|nan|dam+=3,nan,draw(1)";
		initCard(
			Quick_Shot,				//card
			"BRM_013",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage.\nIf your hand is empty, draw a card. Han shot first.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Recharge;
		Recharge.fx[0] = true;			//Spell AKA battlecry
		Recharge.fx2[0] = "nan:Pboard|nan|nan|PCMana=PMMana";
		initCard(
			Recharge,				//card
			"BRMA14_11",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Fill all empty Mana Crystals.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rend_Blackhand;
		Rend_Blackhand.fx[0] = true;			//Battlecry
		Rend_Blackhand.fx2[0] = "if(num>0):Phand,board|dragon,legendary|nan,cho1|nan,destroy";
		initCard(
			Rend_Blackhand,				//card
			"BRM_029",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			8,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, destroy a <b>Legendary</b> minion. Rend believes he is the True Warchief of the Horde and he keeps editing the wikipedia page for \"Warchief of the Horde\" to include his picture.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Resurrect;
		Resurrect.fx[0] = true;			//Spell AKA battlecry
		Resurrect.fx2[0] = "nan:Pboard|nan|nan|summon(graveyard=1)";
		initCard(
			Resurrect,				//card
			"BRM_017",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Summon a random friendly minion that died this game. I walked into the dungeon and noticed a slain adventurer. In his final moments, he had scrawled out a message in the dust on the wall beside him. Two words: \"rez plz\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Revenge;
		Revenge.fx[0] = true;			//Spell AKA battlecry
		Revenge.fx2[0] = "if(hp<=12):Pboard,board,board|hero,min,min|nan,all,all|nan,dam+=1,dam+=3";
		initCard(
			Revenge,				//card
			"BRM_015",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to all minions. If you have 12 or less Health, deal $3 damage instead. This is better than Arcane Explosion, so I guess warriors are finally getting revenge on mages for Mortal Strike being worse than Fireball.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Reverberating_Gong;
		Reverberating_Gong.fx[0] = true;			//Spell AKA battlecry
		Reverberating_Gong.fx2[0] = "nan:Oboard|wep|nan|destroy";
		initCard(
			Reverberating_Gong,				//card
			"BRMA16_4",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Destroy your opponent's weapon.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Solemn_Vigil;
		Solemn_Vigil.fx[0] = true;			//Spell AKA battlecry
		Solemn_Vigil.fx2[0] = "nan:Phand|nan|nan|draw(2)";
		Solemn_Vigil.fx[15] = true;			//aura
		Solemn_Vigil.fx2[15] = "nan:Phand|nan|self|cheap(killed(Pmin))";
		initCard(
			Solemn_Vigil,				//card
			"BRM_001",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Draw 2 cards. Costs (1) less for each minion that died this turn. Each year, folk gather in front of Blackrock Mountain to mourn those who were mind-controlled into the lava.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Son_of_the_Flame;
		Son_of_the_Flame.fx[0] = true;			//Battlecry
		Son_of_the_Flame.fx2[0] = "nan:board|min|cho1|dam+=6";
		initCard(
			Son_of_the_Flame,				//card
			"BRMA13_5",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			6,				//atk
			3,				//hp
			"<b>Battlecry:</b> Deal 6 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sonic_Breath;
		Sonic_Breath.fx[0] = true;			//Spell AKA battlecry
		Sonic_Breath.fx2[0] = "nan:board,Pboard|min,wep|cho1,nan|dam+=3,atk+=3";
		initCard(
			Sonic_Breath,				//card
			"BRMA16_3",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to a minion. Give your weapon +3 Attack.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tail_Swipe;
		Tail_Swipe.fx[0] = true;			//Spell AKA battlecry
		Tail_Swipe.fx2[0] = "nan:board|cha|cho1|dam+=4";
		initCard(
			Tail_Swipe,				//card
			"BRM_030t",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Twilight_Whelp;
		Twilight_Whelp.fx[0] = true;			//Battlecry
		Twilight_Whelp.fx2[0] = "ift(num>0):Phand,Pboard|dragon,nan|nan,self|nan,hp+=2";
		initCard(
			Twilight_Whelp,				//card
			"BRM_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, gain +2 Health. The twilight whelps are basically magic-vampires. Despite this, they are not a reference to any popular series of novels.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Volcanic_Drake;
		Volcanic_Drake.fx[15] = true;		//aura
		Volcanic_Drake.fx2[15] = "nan:Phand|nan|nan|cost-=num(killed)";
		initCard(
			Volcanic_Drake,				//card
			"BRM_025",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			4,				//hp
			"Costs (1) less for each minion that died this turn. Volcanic Drakes breathe lava instead of fire. The antacid vendor at Thorium Point does a brisk business with them.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Volcanic_Lumberer;
		Volcanic_Lumberer.fx[10] = true;			//Taunt
		Volcanic_Lumberer.fx[15] = true;		//aura
		Volcanic_Lumberer.fx2[15] = "nan:Phand|nan|nan|cost-=num(killed)"
			initCard(
				Volcanic_Lumberer,				//card
				"BRM_009",				//id
				"Rare",				//rarity
				true,					//Collect
				"Minion",				//type
				9,				//cost
				7,				//atk
				8,				//hp
				"<b>Taunt</b>\nCosts (1) less for each minion that died this turn. The roots, the roots, the roots is on fire!",
				"",				//race
				""				//hero
				);
	}
	{
		Card Whelp;
		initCard(
			Whelp,				//card
			"BRMA09_2t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Whirling_Ash;
		Whirling_Ash.fx[11] = true;			//Windfury
		initCard(
			Whirling_Ash,				//card
			"BRMA13_7",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			4,				//atk
			5,				//hp
			"<b>Windfury</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Abomination;
		Abomination.fx[2] = true;			//Deathrattle
		Abomination.fx2[2] = "nan:board|cha|all|dam+=2";
		Abomination.fx[10] = true;			//Taunt
		initCard(
			Abomination,				//card
			"EX1_097",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Taunt</b>. <b>Deathrattle:</b> Deal 2 damage to ALL characters. Abominations enjoy Fresh Meat and long walks on the beach.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Abusive_Sergeant;
		Abusive_Sergeant.fx[0] = true;			//Battlecry
		Abusive_Sergeant.fx2[0] = "time(till,PE):board|min|cho1|atk+=2";
		initCard(
			Abusive_Sergeant,				//card
			"CS2_188",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> Give a minion +2 Attack this turn. ADD ME TO YOUR DECK, MAGGOT!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Acolyte_of_Pain;
		Acolyte_of_Pain.fx[16] = true;		//trigger
		Acolyte_of_Pain.fx2[16] = "ift(damaged):Pboard,Phand|nan|self,nan|nan,draw(1)"
			initCard(
				Acolyte_of_Pain,				//card
				"EX1_007",				//id
				"Common",				//rarity
				true,					//Collect
				"Minion",				//type
				3,				//cost
				1,				//atk
				3,				//hp
				"Whenever this minion takes damage, draw a card. He trained when he was younger to be an acolyte of joy, but things didn’t work out like he thought they would.",
				"",				//race
				""				//hero
				);
	}
	{
		Card AlAkir_the_Windlord;
		AlAkir_the_Windlord.fx[1] = true;			//Charge
		AlAkir_the_Windlord.fx[3] = true;			//Divine Shield
		AlAkir_the_Windlord.fx[10] = true;			//Taunt
		AlAkir_the_Windlord.fx[11] = true;			//Windfury
		initCard(
			AlAkir_the_Windlord,				//card
			"NEW1_010",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			3,				//atk
			5,				//hp
			"<b>Windfury, Charge, Divine Shield, Taunt</b> He is the weakest of the four Elemental Lords.  And the other three don't let him forget it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Alarm_o_Bot;
		Alarm_o_Bot.fx[14] = true;		//turnpoint
		Alarm_o_Bot.fx2[14] = "PS:Phand|nan|nan|swap(rand(Phand))";
		initCard(
			Alarm_o_Bot,				//card
			"EX1_006",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			0,				//atk
			3,				//hp
			"At the start of your turn, swap this minion with a random one in your hand. WARNING.  WARNING.  WARNING.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Aldor_Peacekeeper;
		Aldor_Peacekeeper.fx[0] = true;			//Battlecry
		Aldor_Peacekeeper.fx2[0] = "nan:Oboard|min|cho1|atk=1";
		initCard(
			Aldor_Peacekeeper,				//card
			"EX1_382",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Change an enemy minion's Attack to 1. The Aldor hate two things: the Scryers and smooth jazz.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Alexstrasza;
		Alexstrasza.fx[0] = true;			//Battlecry
		Alexstrasza.fx2[0] = "nan:board|hero|cho1|dam=15";
		initCard(
			Alexstrasza,				//card
			"EX1_561",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			8,				//hp
			"<b>Battlecry:</b> Set a hero's remaining Health to 15. Alexstrasza the Life-Binder brings life and hope to everyone.  Except Deathwing.  And Malygos.  And Nekros.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Amani_Berserker;
		Amani_Berserker.fx[4] = true;			//Enrage
		Amani_Berserker.fx2[4] = "nan:Pboard|nan|self|atk+=3";
		initCard(
			Amani_Berserker,				//card
			"EX1_393",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Enrage:</b> +3 Attack If an Amani berserker asks \"Joo lookin' at me?!\", the correct response is \"Nah, mon\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancestral_Spirit;
		Ancestral_Spirit.fx[0] = true;			//Spell AKA battlecry
		Ancestral_Spirit.fx2[0] = "nan:board|min|cho1,tar|fx[2]=true,fx2[2]=\"nan:Pboard|nan|self|resummon\"";
		initCard(
			Ancestral_Spirit,				//card
			"CS2_038",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give a minion \"<b>Deathrattle:</b> Resummon this minion.\" It was just a flesh wound.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_Brewmaster;
		Ancient_Brewmaster.fx[0] = true;			//Battlecry
		Ancient_Brewmaster.fx2[0] = "nan:Pboard|min|rnd1|return";
		initCard(
			Ancient_Brewmaster,				//card
			"EX1_057",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> Return a friendly minion from the battlefield to your hand. Most pandaren say his brew tastes like yak.  But apparently that's a compliment.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_Mage;
		Ancient_Mage.fx[0] = true;			//Battlecry
		Ancient_Mage.fx2[0] = "nan:Pboard|min|adj|spDam+=1";
		initCard(
			Ancient_Mage,				//card
			"EX1_584",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give adjacent minions <b>Spell Damage +1</b>. Sometimes he forgets and just wanders into someone else's game.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_Secrets;
		Ancient_Secrets.fx[0] = true;			//Spell AKA battlecry
		Ancient_Secrets.fx2[0] = "nan:board|cha|cho1|dam-=5";
		initCard(
			Ancient_Secrets,				//card
			"NEW1_008b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore 5 Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_Teachings;
		Ancient_Teachings.fx[0] = true;			//Spell AKA battlecry
		Ancient_Teachings.fx2[0] = "nan:Phand|nan|nan|draw(2)";
		initCard(
			Ancient_Teachings,				//card
			"NEW1_008a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Draw 2 cards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_Watcher;
		Ancient_Watcher.fx[15] = true;		//aura
		Ancient_Watcher.fx2[15] = "pacifist";
		initCard(
			Ancient_Watcher,				//card
			"EX1_045",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			5,				//hp
			"Can't attack. Why do its eyes seem to follow you as you walk by?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_of_Lore;
		Ancient_of_Lore.fx[0] = true;		//battlecry
		Ancient_of_Lore.fx2[0] = "choose:Phand,board|nan,cha|nan,cho1|draw(2),dam-=5";
		initCard(
			Ancient_of_Lore,				//card
			"NEW1_008",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			5,				//hp
			"<b>Choose One -</b> Draw 2 cards; or Restore 5 Health. Go ahead, carve your initials in him.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancient_of_War;
		Ancient_of_War.fx[0] = true;		//battlecry
		Ancient_of_War.fx2[0] = "choose:Pboard|nan|self|atk+=5,hp+=5";
		initCard(
			Ancient_of_War,				//card
			"EX1_178",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			5,				//hp
			"<b>Choose One</b> -\n+5 Attack; or +5 Health and <b>Taunt</b>. Young Night Elves love to play \"Who can get the Ancient of War to Uproot?\"  You lose if you get crushed to death.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Angry_Chicken;
		Angry_Chicken.fx[4] = true;			//Enrage
		Angry_Chicken.fx2[4] = "nan:Pboard|nan|self|atk+=5";
		initCard(
			Angry_Chicken,				//card
			"EX1_009",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Enrage:</b> +5 Attack. There is no beast more frightening (or ridiculous) than a fully enraged chicken.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Arathi_Weaponsmith;
		Arathi_Weaponsmith.fx[0] = true;			//Battlecry
		Arathi_Weaponsmith.fx2[0] = "nan:Pboard|wep|nan|equip(2,2)";
		initCard(
			Arathi_Weaponsmith,				//card
			"EX1_398",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Equip a 2/2 weapon. 50% off fist weapons, limited time only!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Golem;
		Arcane_Golem.fx[0] = true;			//Battlecry
		Arcane_Golem.fx2[0] = "nan:Oboard|nan|nan|PMMana+=1";
		Arcane_Golem.fx[1] = true;			//Charge
		initCard(
			Arcane_Golem,				//card
			"EX1_089",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Charge</b>. <b>Battlecry:</b> Give your opponent a Mana Crystal. Having Arcane golems at home really classes up the place, and as a bonus they are great conversation pieces.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Archmage_Antonidas;
		Archmage_Antonidas.fx[16] = true;		//trigger
		Archmage_Antonidas.fx2[16] = "cast:Pboard,Phand|nan|nan|nan,get(Fireball)";
		initCard(
			Archmage_Antonidas,				//card
			"EX1_559",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			7,				//hp
			"Whenever you cast a spell, add a 'Fireball' spell to your hand. Antonidas was the Grand Magus of the Kirin Tor, and Jaina's mentor.  This was a big step up from being Grand Magus of Jelly Donuts.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Commander;
		Argent_Commander.fx[1] = true;			//Charge
		Argent_Commander.fx[3] = true;			//Divine Shield
		initCard(
			Argent_Commander,				//card
			"EX1_067",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			2,				//hp
			"<b>Charge</b>\n<b>Divine Shield</b> The Argent Dawn stands vigilant against the Scourge, as well as people who cut in line at coffee shops.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Protector;
		Argent_Protector.fx[0] = true;			//Battlecry
		Argent_Protector.fx2[0] = "nan:Pboard|min|cho1|fx[3]=true";
		initCard(
			Argent_Protector,				//card
			"EX1_362",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give a friendly minion <b>Divine Shield</b>. \"I'm not saying you can dodge fireballs.  I'm saying with this shield, you won't have to.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Squire;
		Argent_Squire.fx[3] = true;			//Divine Shield
		initCard(
			Argent_Squire,				//card
			"EX1_008",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Divine Shield</b> \"I solemnly swear to uphold the Light, purge the world of darkness, and to eat only burritos.\" - The Argent Dawn Oath",
			"",				//race
			""				//hero
			);
	}
	{
		Card Armorsmith;
		Armorsmith.fx[16] = true;		//trigger
		Armorsmith.fx2[16] = "ift(damaged):Pboard|min,hero|nan|nan,armr+=1";
		initCard(
			Armorsmith,				//card
			"EX1_402",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			4,				//hp
			"Whenever a friendly minion takes damage, gain 1 Armor. She accepts guild funds for repairs!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ashbringer;
		initCard(
			Ashbringer,				//card
			"EX1_383t",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Weapon",				//type
			5,				//cost
			5,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Auchenai_Soulpriest;
		Auchenai_Soulpriest.fx[15] = true;		//aura
		Auchenai_Soulpriest.fx2[15] = "nan:Pboard|nan|nan|heal2dam";
		initCard(
			Auchenai_Soulpriest,				//card
			"EX1_591",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Your cards and powers that restore Health now deal damage instead. The Auchenai know the end is coming, but they're not sure when.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Avenging_Wrath;
		Avenging_Wrath.fx[0] = true;			//Spell AKA battlecry
		Avenging_Wrath.fx2[0] = "nan:Oboard|cha|8rnd|dam+=1";
		initCard(
			Avenging_Wrath,				//card
			"EX1_384",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Deal $8 damage randomly split among all enemies. Wham! Wham! Wham! Wham! Wham! Wham! Wham! Wham!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Azure_Drake;
		Azure_Drake.fx[0] = true;			//Battlecry
		Azure_Drake.fx2[0] = "nan:Phand|nan|nan|draw(1)";
		Azure_Drake.fx[15] = true;			//Aura
		Azure_Drake.fx2[15] = "nan:Pboard|nan|nan|spDam+=1";
		initCard(
			Azure_Drake,				//card
			"EX1_284",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Spell Damage +1</b>. <b>Battlecry:</b> Draw a card. They initially planned to be the Beryl or Cerulean drakes, but those felt a tad too pretentious.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Baine_Bloodhoof;
		initCard(
			Baine_Bloodhoof,				//card
			"EX1_110t",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			5,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bananas;
		Bananas.fx[0] = true;			//Spell AKA battlecry
		Bananas.fx2[0] = "nan:board|min|cho1,tar|atk+=1,hp+=1";
		initCard(
			Bananas,				//card
			"EX1_014t",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +1/+1.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bane_of_Doom;
		Bane_of_Doom.fx[0] = true;			//Spell AKA battlecry
		Bane_of_Doom.fx2[0] = "ift(killed):board,Pboard|cha,nan|cho1,nan|dam+=1,summon(demon)";
		initCard(
			Bane_of_Doom,				//card
			"EX1_320",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to a character. If that kills it, summon a random Demon. My advice to you is to avoid Doom, if possible.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Baron_Geddon;
		Baron_Geddon.fx[14] = true;		//turnpoint
		Baron_Geddon.fx2[14] = "PE:board|cha|!self|dam+=2";
		initCard(
			Baron_Geddon,				//card
			"EX1_249",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			5,				//hp
			"At the end of your turn, deal 2 damage to ALL other characters. Baron Geddon was Ragnaros's foremost lieutenant, until he got FIRED.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Battle_Axe;
		initCard(
			Battle_Axe,				//card
			"EX1_398t",				//id
			"",				//rarity
			false,					//Collect
			"Weapon",				//type
			1,				//cost
			2,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Battle_Rage;
		Battle_Rage.fx[0] = true;			//Spell AKA battlecry
		Battle_Rage.fx2[0] = "nan:Phand|nan|nan|draw(num(Pdam))";
		initCard(
			Battle_Rage,				//card
			"EX1_392",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Draw a card for each damaged friendly character. \"You won't like me when I'm angry.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bear_Form;
		Bear_Form.fx[0] = true;			//Spell AKA battlecry
		Bear_Form.fx2[0] = "nan:board|cha|cho1,tar|hp+=2,fx[11]=true";
		initCard(
			Bear_Form,				//card
			"EX1_165b",				//id
			"Common",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+2 Health and <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bestial_Wrath;
		Bestial_Wrath.fx[0] = true;			//Spell AKA battlecry
		Bestial_Wrath.fx2[0] = "time(till,PE):Pboard|beast|cho1,tar|atk+=2,fx[17]=true";
		initCard(
			Bestial_Wrath,				//card
			"EX1_549",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a friendly Beast +2 Attack and <b>Immune</b> this turn. The seething wrath is just beneath the surface.  Beneath that is wild abandon, followed by slight annoyance.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Betrayal;
		Betrayal.fx[0] = true;			//Spell AKA battlecry
		Betrayal.fx2[0] = "nan:Oboard|min|cho1|dam(adj)";
		initCard(
			Betrayal,				//card
			"EX1_126",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Force an enemy minion to deal its damage to the minions next to it. Everyone has a price. Gnomes, for example, can be persuaded by stuffed animals and small amounts of chocolate.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Big_Game_Hunter;
		Big_Game_Hunter.fx[0] = true;			//Battlecry
		Big_Game_Hunter.fx2[0] = "ift(atk>=7):board|min|cho1,tar|nan,destroy";
		initCard(
			Big_Game_Hunter,				//card
			"EX1_005",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Battlecry:</b> Destroy a minion with an Attack of 7 or more. Mere devilsaurs no longer excite him.  Soon he'll be trying to catch Onyxia with only a dull Krol Blade.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bite;
		Bite.fx[0] = true;			//Spell AKA battlecry
		Bite.fx2[0] = "nan:Pboard|hero|nan|atk+=4,armr+=4";
		initCard(
			Bite,				//card
			"EX1_570",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Give your hero +4 Attack this turn and 4 Armor. Chew your food!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blade_Flurry;
		Blade_Flurry.fx[0] = true;			//Spell AKA battlecry
		Blade_Flurry.fx2[0] = "nan:Oboard,Pboard|cha,wep|all,nan|dam+=wepatk,destroy";
		initCard(
			Blade_Flurry,				//card
			"CS2_233",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Destroy your weapon and deal its damage to all enemies. \"Look, it's not just about waving daggers around really fast.  It's a lot more complicated than that.\" - Shan, Rogue Trainer",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blessed_Champion;
		Blessed_Champion.fx[0] = true;			//Spell AKA battlecry
		Blessed_Champion.fx2[0] = "nan:board|min|cho1|atk*=2";
		initCard(
			Blessed_Champion,				//card
			"EX1_355",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Double a minion's Attack. This card causes double the trouble AND double the fun.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blessing_of_Wisdom;
		Blessing_of_Wisdom.fx[0] = true;			//Spell AKA battlecry
		Blessing_of_Wisdom.fx2[0] = "nan:board|min|cho1,tar|fx[16]=true,fx2[16]=\"ift(attacks):Pboard,Phand|nan|self,nan|nan,draw(1)\"";
		initCard(
			Blessing_of_Wisdom,				//card
			"EX1_363",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Choose a minion. Whenever it attacks, draw a card. Apparently with wisdom comes the knowledge that you should probably be attacking every turn.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blizzard;
		Blizzard.fx[5] = true;			//Freeze
		Blizzard.fx[0] = true;			//Spell AKA battlecry
		Blizzard.fx2[0] = "nan:Oboard|min|all|dam+=2,freeze";
		initCard(
			Blizzard,				//card
			"CS2_028",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to all enemy minions and <b>Freeze</b> them. This spell can be very Entertaining.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blood_Fury;
		initCard(
			Blood_Fury,				//card
			"EX1_323w",				//id
			"",				//rarity
			false,					//Collect
			"Weapon",				//type
			3,				//cost
			3,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blood_Imp;
		Blood_Imp.fx[9] = true;			//Stealth
		Blood_Imp.fx2[14] = "PE:Pboard|min|rnd1|hp+=1";
		initCard(
			Blood_Imp,				//card
			"CS2_059",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			1,				//hp
			"<b>Stealth</b>. At the end of your turn, give another random friendly minion +1 Health. Imps are content to hide and viciously taunt everyone nearby.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Blood_Knight;
		Blood_Knight.fx[0] = true;			//Battlecry
		Blood_Knight.fx2[0] = "ift(fx[3]=true):board,Pboard,Pboard,board|min,nan,nan,min|all,nan,nan,all|nan,atk+=3,hp+=3,fx[3]=false";			//todo
		initCard(
			Blood_Knight,				//card
			"EX1_590",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> All minions lose <b>Divine Shield</b>. Gain +3/+3 for each Shield lost. The Blood Knights get their holy powers from the Sunwell, which you should NOT bathe in.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bloodmage_Thalnos;
		Bloodmage_Thalnos.fx[2] = true;			//Deathrattle
		Bloodmage_Thalnos.fx2[2] = "nan:Phand|nan|nan|draw(1)";
		Bloodmage_Thalnos.fx[15] = true;			//aura
		Bloodmage_Thalnos.fx2[15] = "nan:Pboard|nan|nan|spDam+=1";
		initCard(
			Bloodmage_Thalnos,				//card
			"EX1_012",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			1,				//hp
			"<b>Spell Damage +1</b>. <b>Deathrattle:</b> Draw a card. He's in charge of the Annual Scarlet Monastery Blood Drive!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bloodsail_Corsair;
		Bloodsail_Corsair.fx[0] = true;			//Battlecry
		Bloodsail_Corsair.fx2[0] = "nan:Oboard|wep|nan|dur-=1";
		initCard(
			Bloodsail_Corsair,				//card
			"NEW1_025",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Remove 1 Durability from your opponent's weapon. Every pirate uses the same four digits to access Automated Gold Dispensers.  It's called the \"Pirate's Code\".",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Bloodsail_Raider;
		Bloodsail_Raider.fx[0] = true;			//Battlecry
		Bloodsail_Raider.fx2[0] = "nan:Pboard|nan|self|atk+=wepatk";
		initCard(
			Bloodsail_Raider,				//card
			"NEW1_018",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Gain Attack equal to the Attack of your weapon. \"I only plunder on days that end in 'y'.\"",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Brawl;
		Brawl.fx[0] = true;			//Spell AKA battlecry
		Brawl.fx2[0] = "nan:board|min|all|brawl";
		initCard(
			Brawl,				//card
			"EX1_407",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Destroy all minions except one. <i>(chosen randomly)</i> Do you know the first rule of Brawl Club?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cabal_Shadow_Priest;
		Cabal_Shadow_Priest.fx[0] = true;			//Battlecry
		Cabal_Shadow_Priest.fx2[0] = "ift(atk<=2):Oboard|min|cho1,tar|nan,control";
		initCard(
			Cabal_Shadow_Priest,				//card
			"EX1_091",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			5,				//hp
			"<b>Battlecry:</b> Take control of an enemy minion that has 2 or less Attack. You never know who may be secretly working for the Cabal....",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cairne_Bloodhoof;
		Cairne_Bloodhoof.fx[2] = true;			//Deathrattle
		Cairne_Bloodhoof.fx2[2] = "nan:Pboard|nan|nan|summon(Baine_Bloodhoof=1)";
		initCard(
			Cairne_Bloodhoof,				//card
			"EX1_110",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			5,				//hp
			"<b>Deathrattle:</b> Summon a 4/5 Baine Bloodhoof. Cairne was killed by Garrosh, so... don't put this guy in a Warrior deck.  It's pretty insensitive.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Captain_Greenskin;
		Captain_Greenskin.fx[0] = true;			//Battlecry
		Captain_Greenskin.fx2[0] = "nan:Pboard|wep|nan|atk+=1,dur+=1";
		initCard(
			Captain_Greenskin,				//card
			"NEW1_024",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> Give your weapon +1/+1. He was <i>this close</i> to piloting a massive juggernaut into Stormwind Harbor. If it weren't for those pesky kids!",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Cat_Form;
		Cat_Form.fx[0] = true;			//Spell AKA battlecry
		Cat_Form.fx2[0] = "nan:";
		initCard(
			Cat_Form,				//card
			"EX1_165a",				//id
			"Common",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"<b>Charge</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cenarius;
		Cenarius.fx[0] = true;		//battlecry
		Cenarius.fx2[0] = "choose(2):Pboard|min,min,nan|!self,!self,nan|atk+=2,hp+=2,summon2(Treant=1)";
		initCard(
			Cenarius,				//card
			"EX1_573",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			5,				//atk
			8,				//hp
			"<b>Choose One</b> - Give your other minions +2/+2; or Summon two 2/2 Treants with <b>Taunt</b>. Yes, he's a demigod. No, he doesn't need to wear a shirt.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Circle_of_Healing;
		Circle_of_Healing.fx[0] = true;			//Spell AKA battlecry
		Circle_of_Healing.fx2[0] = "nan:board|min|all|dam-=4";
		initCard(
			Circle_of_Healing,				//card
			"EX1_621",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore #4 Health to ALL minions. It isn't really a circle.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cold_Blood;
		Cold_Blood.fx[0] = true;			//Spell AKA battlecry
		Cold_Blood.fx2[0] = "combo:board|min|cho1|atk+=2,atk+=4";
		initCard(
			Cold_Blood,				//card
			"CS2_073",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +2 Attack. <b>Combo:</b> +4 Attack instead. \"I'm cold blooded, check it and see!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Coldlight_Oracle;
		Coldlight_Oracle.fx[0] = true;			//Battlecry
		Coldlight_Oracle.fx2[0] = "nan:Phand,Ohand|nan|nan|draw(2)";
		initCard(
			Coldlight_Oracle,				//card
			"EX1_050",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Each player draws 2 cards. They can see the future.   In that future both players draw more cards.   Spoooky.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Coldlight_Seer;
		Coldlight_Seer.fx[0] = true;			//Battlecry
		Coldlight_Seer.fx2[0] = "nan:board|murloc|!self|hp+=2";
		initCard(
			Coldlight_Seer,				//card
			"EX1_103",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Give ALL other Murlocs +2 Health. The Coldlight murlocs reside in the darkest pits of the Abyssal Depths.  So no, there's no getting away from murlocs.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Commanding_Shout;
		Commanding_Shout.fx[0] = true;			//Spell AKA battlecry
		Commanding_Shout.fx2[0] = "time(till,PE):Pboard,Phand|min,nan|all,nan|hpmin(1),draw(1)";
		initCard(
			Commanding_Shout,				//card
			"NEW1_036",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Your minions can't be reduced below 1 Health this turn. Draw a card. \"Shout! Shout! Let it all out!\" - Advice to warriors-in-training",
			"",				//race
			""				//hero
			);
	}
	{
		Card Conceal;
		Conceal.fx[0] = true;			//Spell AKA battlecry
		Conceal.fx2[0] = "time(till,PS):Pboard|min|all|fx[10]=true";
		initCard(
			Conceal,				//card
			"EX1_128",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give your minions <b>Stealth</b> until your next turn. Rogues conceal everything but their emotions.  You can't get 'em to shut up about feelings.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cone_of_Cold;
		Cone_of_Cold.fx[5] = true;			//Freeze
		Cone_of_Cold.fx[0] = true;			//Spell AKA battlecry
		Cone_of_Cold.fx2[0] = "nan:board|min|cho1,tar,adj(tar),tar|freeze,freeze,dam+=1,dam+=1";
		initCard(
			Cone_of_Cold,				//card
			"EX1_275",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"<b>Freeze</b> a minion and the minions next to it, and deal $1 damage to them. Magi of the Kirin Tor were casting Cubes of Cold for many years before Cones came into fashion some 90 years ago.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Counterspell;
		Counterspell.fx[8] = true;			//Secret
		Counterspell.fx2[8] = "counter";
		initCard(
			Counterspell,				//card
			"EX1_287",				//id
			"Rarity",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your opponent casts a spell, <b>Counter</b> it. What's the difference between a mage playing with Counterspell and a mage who isn't?  The mage who isn't is getting Pyroblasted in the face.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Crazed_Alchemist;
		Crazed_Alchemist.fx[0] = true;			//Battlecry
		Crazed_Alchemist.fx2[0] = "nan:board|min|cho1|bizarro";
		initCard(
			Crazed_Alchemist,				//card
			"EX1_059",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Swap the Attack and Health of a minion. \"You'll <i>love</i> my new recipe!\" he says... especially if you're not happy with your current number of limbs.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cruel_Taskmaster;
		Cruel_Taskmaster.fx[0] = true;			//Battlecry
		Cruel_Taskmaster.fx2[0] = "nan:board|min|cho1,tar|dam+=1,atk+=2";
		initCard(
			Cruel_Taskmaster,				//card
			"EX1_603",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 1 damage to a minion and give it +2 Attack. \"I'm going to need you to come in on Sunday.\" - Cruel Taskmaster",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cult_Master;
		Cult_Master.fx[16] = true;		//trigger
		Cult_Master.fx2[16] = "ift(killed):Pboard,Phand|min,nan|nan|nan,draw(1)";
		initCard(
			Cult_Master,				//card
			"EX1_595",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			2,				//hp
			"Whenever one of your other minions dies, draw a card. She may be an evil cult master, but she still calls her parents once a week.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damaged_Golem;
		initCard(
			Damaged_Golem,				//card
			"skele21",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Dark_Iron_Dwarf;
		Dark_Iron_Dwarf.fx[0] = true;			//Battlecry
		Dark_Iron_Dwarf.fx2[0] = "time(till,PE):board|min|cho1|atk+=2";
		initCard(
			Dark_Iron_Dwarf,				//card
			"EX1_046",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Give a minion +2 Attack this turn. Guardians of Dark Iron Ore.  Perhaps the most annoying ore, given where you have to forge it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deadly_Shot;
		Deadly_Shot.fx[0] = true;			//Spell AKA battlecry
		Deadly_Shot.fx2[0] = "nan:Oboard|min|rnd1|destroy";
		initCard(
			Deadly_Shot,				//card
			"EX1_617",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Destroy a random enemy minion. Accuracy is not a highly valued trait among the mok'nathal.  Deadliness is near the top, though.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deathwing;
		Deathwing.fx[0] = true;			//Battlecry
		Deathwing.fx2[0] = "nan:board,Phand|min,nan|!self,all|destroy,discard";
		initCard(
			Deathwing,				//card
			"NEW1_030",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			10,				//cost
			12,				//atk
			12,				//hp
			"<b>Battlecry:</b> Destroy all other minions and discard your hand. Once a noble dragon known as Neltharion, Deathwing lost his mind and shattered Azeroth before finally being defeated.  Daddy issues?",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Defender;
		initCard(
			Defender,				//card
			"EX1_130a",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Defender_of_Argus;
		Defender_of_Argus.fx[0] = true;			//Battlecry
		Defender_of_Argus.fx2[0] = "nan:board|min|adj(self)|atk+=1,hp+=1,fx[11]=true";
		initCard(
			Defender_of_Argus,				//card
			"EX1_093",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Give adjacent minions +1/+1 and <b>Taunt</b>. You wouldn’t think that Argus would need this much defending.  But it does.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Defias_Bandit;
		initCard(
			Defias_Bandit,				//card
			"EX1_131t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Defias_Ringleader;
		Defias_Ringleader.fx[0] = true;		//battlecry
		Defias_Ringleader.fx2[0] = "combo:Pboard|nan|nan|summon(Defias_Bandit=1)";
		initCard(
			Defias_Ringleader,				//card
			"EX1_131",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Combo:</b> Summon a 2/1 Defias Bandit. He stole the deed to town years ago, so technically the town <i>is</i> his. He just calls people Scrub to be mean.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Demigods_Favor;
		Demigods_Favor.fx[0] = true;			//Spell AKA battlecry
		Demigods_Favor.fx2[0] = "nan:Pboard|min|!self|atk+=2,hp+=2";
		initCard(
			Demigods_Favor,				//card
			"EX1_573a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give your other minions +2/+2.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Demolisher;
		Demolisher.fx[14] = true;		//turnpoint
		Demolisher.fx2[14] = "PS:Oboard|cha|rnd1|dam+=2";
		initCard(
			Demolisher,				//card
			"EX1_102",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"At the start of your turn, deal 2 damage to a random enemy. Laying siege isn't fun for anyone.  It's not even all that effective, now that everyone has a flying mount.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Demonfire;
		Demonfire.fx[0] = true;			//Spell AKA battlecry
		Demonfire.fx2[0] = "if(Pdemon,1):board|min|cho1,tar,tar,tar|nan,dam+=2,atk+=2,hp+=2";
		initCard(
			Demonfire,				//card
			"EX1_596",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to a minion. If it’s a friendly Demon, give it +2/+2 instead. Demonfire is like regular fire except for IT NEVER STOPS BURNING HELLLPPP",
			"",				//race
			""				//hero
			);
	}
	{
		Card Devilsaur;
		initCard(
			Devilsaur,				//card
			"EX1_tk29",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Dire_Wolf_Alpha;
		Dire_Wolf_Alpha.fx[15] = true;		//aura
		Dire_Wolf_Alpha.fx2[15] = "board|min|adj(self)|atk+=1";
		initCard(
			Dire_Wolf_Alpha,				//card
			"EX1_162",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"Adjacent minions have +1 Attack. We are pretty excited about the upcoming release of Dire Wolf Beta, just repost this sign for a chance at a key.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Dispel;
		Dispel.fx[0] = true;			//Spell AKA battlecry
		Dispel.fx2[0] = "nan:board|min|cho1|silence";
		initCard(
			Dispel,				//card
			"EX1_166b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"<b>Silence</b> a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Divine_Favor;
		Divine_Favor.fx[0] = true;			//Spell AKA battlecry
		Divine_Favor.fx2[0] = "nan:Phand|nan|nan|match";
		initCard(
			Divine_Favor,				//card
			"EX1_349",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Draw cards until you have as many in hand as your opponent. This is not just a favor, but a divine one, like helping someone move a couch with a fold out bed!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Doomguard;
		Doomguard.fx[0] = true;			//Battlecry
		Doomguard.fx2[0] = "nan:Phand|nan|2rnd|discard";
		Doomguard.fx[1] = true;			//Charge
		initCard(
			Doomguard,				//card
			"EX1_310",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			7,				//hp
			"<b>Charge</b>. <b>Battlecry:</b> Discard two random cards. Summoning a doomguard is risky. <i>Someone</i> is going to die.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Doomhammer;
		Doomhammer.fx[6] = true;			//Overload
		Doomhammer.fx2[6] = "2";
		Doomhammer.fx[11] = true;			//Windfury
		initCard(
			Doomhammer,				//card
			"EX1_567",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			5,				//cost
			2,				//atk
			0,				//hp
			"<b>Windfury, Overload:</b> (2) Orgrim Doomhammer gave this legendary weapon to Thrall.  His name is a total coincidence.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Doomsayer;
		Doomsayer.fx[14] = true;		//turnpoint
		Doomsayer.fx2[14] = "PS:board|min|all|destroy";
		initCard(
			Doomsayer,				//card
			"NEW1_021",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			7,				//hp
			"At the start of your turn, destroy ALL minions. He's almost been right so many times. He was <i>sure</i> it was coming during the Cataclysm.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dread_Corsair;
		Dread_Corsair.fx[15] = true;		//aura
		Dread_Corsair.fx2[15] = "nan:Phand|nan|self|cheap(wepatk)";
		Dread_Corsair.fx[10] = true;			//Taunt
		initCard(
			Dread_Corsair,				//card
			"NEW1_022",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"<b>Taunt.</b> Costs (1) less per Attack of your weapon. \"Yarrrr\" is a pirate word that means \"Greetings, milord.\"",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Dream;
		Dream.fx[0] = true;			//Spell AKA battlecry
		Dream.fx2[0] = "nan:board|min|cho1|return";
		initCard(
			Dream,				//card
			"DREAM_04",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Return a minion to its owner's hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Claw2;
		Druid_of_the_Claw2.fx[10] = true;			//Taunt
		initCard(
			Druid_of_the_Claw2,				//card
			"EX1_165t2",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			6,				//hp
			"<b>Taunt</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Claw;
		Druid_of_the_Claw.fx[0] = true;		//battlecry
		Druid_of_the_Claw.fx2[0] = "choose(1):Pboard|nan|self|fx[1]=true,fx[11]=true,hp+=2";
		initCard(
			Druid_of_the_Claw,				//card
			"EX1_165",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Choose One -</b> <b>Charge</b>; or +2 Health and <b>Taunt</b>. Cat or Bear?  Cat or Bear?!  I just cannot CHOOSE!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Claw1;
		Druid_of_the_Claw1.fx[1] = true;			//Charge
		initCard(
			Druid_of_the_Claw1,				//card
			"EX1_165t1",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Charge</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Dust_Devil;
		Dust_Devil.fx[6] = true;			//Overload
		Dust_Devil.fx2[6] = "2";
		Dust_Devil.fx[11] = true;			//Windfury
		initCard(
			Dust_Devil,				//card
			"EX1_243",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			3,				//atk
			1,				//hp
			"<b>Windfury</b>. <b>Overload:</b> (2) Westfall is full of dust devils. And buzzards. And crazed golems. And pirates. Why does anyone live here?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eaglehorn_Bow;
		Eaglehorn_Bow.fx[16] = true;		//trigger
		Eaglehorn_Bow.fx2[16] = "reveal:Pboard|nan|self|dur+=1";
		initCard(
			Eaglehorn_Bow,				//card
			"EX1_536",				//id
			"Rare",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			3,				//atk
			0,				//hp
			"Whenever a friendly <b>Secret</b> is revealed, gain +1 Durability. First Lesson: Put the pointy end in the other guy.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Earth_Elemental;
		Earth_Elemental.fx[6] = true;			//Overload
		Earth_Elemental.fx2[6] = "3";
		Earth_Elemental.fx[10] = true;			//Taunt
		initCard(
			Earth_Elemental,				//card
			"EX1_250",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			8,				//hp
			"<b>Taunt</b>. <b>Overload:</b> (3) Nothing beats rock.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Earth_Shock;
		Earth_Shock.fx[0] = true;			//Spell AKA battlecry
		Earth_Shock.fx2[0] = "nan:board|min|cho1,tar|silence,dam+=1";
		initCard(
			Earth_Shock,				//card
			"EX1_245",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Silence</b> a minion, then deal $1 damage to it. Earth Shock? Shouldn't it be \"Azeroth Shock\"?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Earthen_Ring_Farseer;
		Earthen_Ring_Farseer.fx[0] = true;			//Battlecry
		Earthen_Ring_Farseer.fx2[0] = "nan:board|cha|cho1|dam-=3";
		initCard(
			Earthen_Ring_Farseer,				//card
			"CS2_117",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Restore 3 Health. He can see really far, and he doesn't use a telescope like those filthy pirates.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Edwin_VanCleef;
		Edwin_VanCleef.fx[0] = true;		//battlecry
		Edwin_VanCleef.fx2[0] = "combo:Pboard|nan|self|atk+=2*num(played),hp+=2*num(played)";
		initCard(
			Edwin_VanCleef,				//card
			"EX1_613",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Combo:</b> Gain +2/+2 for each card played earlier this turn. He led the Stonemasons in the reconstruction of Stormwind, and when the nobles refused to pay, he founded the Defias Brotherhood to, well, <i>deconstruct</i> Stormwind.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Emerald_Drake;
		initCard(
			Emerald_Drake,				//card
			"DREAM_03",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			4,				//cost
			7,				//atk
			6,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Emperor_Cobra;
		Emperor_Cobra.fx[7] = true;			//Poisonous
		Emperor_Cobra.fx[13] = true;		//thorns
		Emperor_Cobra.fx2[13] = "destroy";
		initCard(
			Emperor_Cobra,				//card
			"EX1_170",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"Destroy any minion damaged by this minion. The Sholazar Basin is home to a lot of really horrible things. If you're going to visit, wear bug spray.  And plate armor.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Equality;
		Equality.fx[0] = true;			//Spell AKA battlecry
		Equality.fx2[0] = "nan:board|min|all|hp=1";
		initCard(
			Equality,				//card
			"EX1_619",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Change the Health of ALL minions to 1. We are all special unique snowflakes... with 1 Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ethereal_Arcanist;
		Ethereal_Arcanist.fx[14] = true;		//turnpoint
		Ethereal_Arcanist.fx2[14] = "PE:ift(num>0):Pboard|secret,nan,nan|nan,self,self|nan,atk+=2,hp+=2";
		initCard(
			Ethereal_Arcanist,				//card
			"EX1_274",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"If you control a <b>Secret</b> at the end of your turn, gain +2/+2. The ethereals are wrapped in cloth to give form to their non-corporeal bodies. Also because it's nice and soft.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eviscerate;
		Eviscerate.fx[0] = true;			//Spell AKA battlecry
		Eviscerate.fx2[0] = "combo:board|min|cho1,tar|dam+=2,dam+=4";
		initCard(
			Eviscerate,				//card
			"EX1_124",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage. <b>Combo:</b> Deal $4 damage instead. There is a high cost to Eviscerating your opponent:  It takes a long time to get blood stains out of leather armor.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Explosive_Shot;
		Explosive_Shot.fx[0] = true;			//Spell AKA battlecry
		Explosive_Shot.fx2[0] = "nan:board|min|cho1,adj(tar)|dam+=5,dam+=2";
		initCard(
			Explosive_Shot,				//card
			"EX1_537",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage to a minion and $2 damage to adjacent ones. Pull the pin, count to 5, then shoot.  Then duck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Explosive_Trap;
		Explosive_Trap.fx[8] = true;			//Secret
		Explosive_Trap.fx2[8] = "ift(attacked):Pboard,Oboard|hero,cha|nan,all|nan,dam+=2";
		initCard(
			Explosive_Trap,				//card
			"EX1_610",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your hero is attacked, deal $2 damage to all enemies. It traps your food AND cooks it for you!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eye_for_an_Eye;
		Eye_for_an_Eye.fx[8] = true;			//Secret
		Eye_for_an_Eye.fx2[8] = "ift(damaged):Pboard,Oboard|hero|nan|nan,dam+=lastdam";
		initCard(
			Eye_for_an_Eye,				//card
			"EX1_132",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your hero takes damage, deal that much damage to the enemy hero. Justice sometimes takes the form of a closed fist into a soft cheek.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Faceless_Manipulator;
		Faceless_Manipulator.fx[0] = true;			//Battlecry
		Faceless_Manipulator.fx2[0] = "nan:board,Pboard|min,nan|cho1,self|nan,transform(1)";
		initCard(
			Faceless_Manipulator,				//card
			"EX1_564",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Choose a minion and become a copy of it. The Faceless Ones are servants of Yogg-Saron, and they feed on fear. Right now they are feeding on your fear of accidentally disenchanting all your good cards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Faerie_Dragon;
		Faerie_Dragon.fx[15] = true;		//aura
		Faerie_Dragon.fx2[15] = "magimmune";
		initCard(
			Faerie_Dragon,				//card
			"NEW1_023",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"Can't be targeted by spells or Hero Powers. Adorable.  Immune to Magic.  Doesn't pee on the rug.  The perfect pet!",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Far_Sight;
		Far_Sight.fx[0] = true;			//Spell AKA battlecry
		Far_Sight.fx2[0] = "nan:Phand|nan|nan|draw(1,3)";
		initCard(
			Far_Sight,				//card
			"CS2_053",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Draw a card. That card costs (3) less. Drek'thar can't see, but he can <i>see</i>. You know what I mean? It's ok if you don't.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Felguard;
		Felguard.fx[0] = true;			//Battlecry
		Felguard.fx2[0] = "nan:Pboard|nan|nan|PMMana-=1,PCMana-=1";
		Felguard.fx[10] = true;			//Taunt
		initCard(
			Felguard,				//card
			"EX1_301",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			5,				//hp
			"<b>Taunt</b>. <b>Battlecry:</b> Destroy one of your Mana Crystals. Yes, he'll fight for you.  BUT HE'S NOT GOING TO LIKE IT.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Fen_Creeper;
		Fen_Creeper.fx[10] = true;			//Taunt
		initCard(
			Fen_Creeper,				//card
			"CS1_069",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			6,				//hp
			"<b>Taunt</b> He used to be called Bog Beast, but it confused people because he wasn't an actual beast.   Boom, New Name!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Feral_Spirit;
		Feral_Spirit.fx[0] = true;			//Spell AKA battlecry
		Feral_Spirit.fx2[0] = "nan:Pboard|nan|nan|summon2(Spirit_Wolf=1)";
		Feral_Spirit.fx[6] = true;		//overload
		Feral_Spirit.fx2[6] = "2";
		initCard(
			Feral_Spirit,				//card
			"EX1_248",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Summon two 2/3 Spirit Wolves with <b>Taunt</b>. <b>Overload:</b> (2) Spirit wolves are like regular wolves with pom-poms.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Finkle_Einhorn;
		initCard(
			Finkle_Einhorn,				//card
			"EX1_finkle",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			3,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flame_Imp;
		Flame_Imp.fx[0] = true;			//Battlecry
		Flame_Imp.fx2[0] = "nan:Pboard|hero|nan|dam+=3";
		initCard(
			Flame_Imp,				//card
			"EX1_319",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 3 damage to your hero. Imps like being on fire.  They just do.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Flame_of_Azzinoth;
		initCard(
			Flame_of_Azzinoth,				//card
			"EX1_614t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flare;
		Flare.fx[0] = true;			//Spell AKA battlecry
		Flare.fx2[0] = "nan:board,Oboard,Pboard|min,secret,nan|all,all,nan|fx[10]=true,destroy,draw(1)";
		initCard(
			Flare,				//card
			"EX1_544",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"All minions lose <b>Stealth</b>. Destroy all enemy <b>Secrets</b>. Draw a card. Not only does it reveal your enemies, but it's also great for parties!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flesheating_Ghoul;
		Flesheating_Ghoul.fx[16] = true;		//trigger
		Flesheating_Ghoul.fx2[16] = "ift(killed):board,Pboard|min,nan|nan,self|nan,atk+=1";
		initCard(
			Flesheating_Ghoul,				//card
			"tt_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"Whenever a minion dies, gain +1 Attack. 'Flesheating' is an unfair name.  It's just that there's not really much else for him to eat.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Force_of_Nature;
		Force_of_Nature.fx[0] = true;			//Spell AKA battlecry
		Force_of_Nature.fx2[0] = "time(till,PE):Pboard|nan|nan|summon3(Treant=1)";
		initCard(
			Force_of_Nature,				//card
			"EX1_571",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Summon three 2/2 Treants with <b>Charge</b> that die at the end of the turn. \"I think I'll just nap under these trees. Wait... AAAAAHHH!\" - Blinkfizz, the Unfortunate Gnome",
			"",				//race
			""				//hero
			);
	}
	{
		Card Forked_Lightning;
		Forked_Lightning.fx[0] = true;			//Spell AKA battlecry
		Forked_Lightning.fx2[0] = "nan:Oboard|min|rnd2|dam+=2";
		Forked_Lightning.fx[6] = true;			//overload
		Forked_Lightning.fx2[6] = "2";
		initCard(
			Forked_Lightning,				//card
			"EX1_251",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to 2 random enemy minions. <b>Overload:</b> (2) If you combine it with Spooned Lightning and Knived Lightning, you have the full dining set.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Freezing_Trap;
		Freezing_Trap.fx[8] = true;			//Secret
		Freezing_Trap.fx2[8] = "ift(attacks):Oboard|min|nan,tar|nan,return(2)";
		initCard(
			Freezing_Trap,				//card
			"EX1_611",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When an enemy minion attacks, return it to its owner's hand and it costs (2) more. \"Dang, that's cold.\" - appropriate response to Freezing Trap, or a mean joke.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frost_Elemental;
		Frost_Elemental.fx[0] = true;			//Battlecry
		Frost_Elemental.fx2[0] = "nan:board|cha|cho1|freeze";
		Frost_Elemental.fx[5] = true;			//Freeze
		initCard(
			Frost_Elemental,				//card
			"EX1_283",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> <b>Freeze</b> a character. When a Water elemental and an Ice elemental love each other VERY much...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frothing_Berserker;
		Frothing_Berserker.fx[16] = true;		//trigger
		Frothing_Berserker.fx2[16] = "ift(damaged):board,Pboard|min,nan|nan,self|nan,atk+=1";
		initCard(
			Frothing_Berserker,				//card
			"EX1_604",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Whenever a minion takes damage, gain +1 Attack. He used to work as an accountant before he tried his hand at Berserkering.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gadgetzan_Auctioneer;
		Gadgetzan_Auctioneer.fx[16] = true;			//trigger
		Gadgetzan_Auctioneer.fx2[16] = "ift(cast):Pboard,Phand|nan|nan|nan,draw(1)";
		initCard(
			Gadgetzan_Auctioneer,				//card
			"EX1_095",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			4,				//hp
			"Whenever you cast a spell, draw a card. He used to run the black market auction house, but there was just too much violence and he had to move.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gladiators_Longbow;
		Gladiators_Longbow.fx[15] = true;		//aura
		Gladiators_Longbow.fx2[15] = "attimmune";
		initCard(
			Gladiators_Longbow,				//card
			"DS1_188",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			7,				//cost
			5,				//atk
			0,				//hp
			"Your hero is <b>Immune</b> while attacking. The longbow allows shots to be fired from farther away and is useful for firing on particularly odorous targets.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gnoll;
		Gnoll.fx[10] = true;			//Taunt
		initCard(
			Gnoll,				//card
			"NEW1_040t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gorehowl;
		Gorehowl.fx[15] = true;		//aura
		Gorehowl.fx2[15] = "gorehowl";
		initCard(
			Gorehowl,				//card
			"EX1_411",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			7,				//cost
			7,				//atk
			0,				//hp
			"Attacking a minion costs 1 Attack instead of 1 Durability. Grommash Hellscream's famous axe.  Somehow this ended up in Prince Malchezaar's possession.  Quite the mystery!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grommash_Hellscream;
		Grommash_Hellscream.fx[1] = true;			//Charge
		Grommash_Hellscream.fx[4] = true;			//Enrage
		Grommash_Hellscream.fx2[4] = "nan:Pboard|nan|self|atk+=6";
		initCard(
			Grommash_Hellscream,				//card
			"EX1_414",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			4,				//atk
			9,				//hp
			"<b>Charge</b>\n<b>Enrage:</b> +6 Attack Grommash drank the tainted blood of Mannoroth, dooming the orcs to green skin and red eyes!  Maybe not his best decision.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gruul;
		Gruul.fx[14] = true;			//turnpoint
		Gruul.fx2[14] = "TE:Pboard|nan|self|atk+=1,hp+=1";
		initCard(
			Gruul,				//card
			"NEW1_038",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			7,				//atk
			7,				//hp
			"At the end of each turn, gain +1/+1 . He's Gruul \"the Dragonkiller\".  He just wanted to cuddle them… he never meant to…",
			"",				//race
			""				//hero
			);
	}
	{
		Card Harrison_Jones;
		Harrison_Jones.fx[0] = true;			//Battlecry
		Harrison_Jones.fx2[0] = "nan:Phand,Oboard|nan,wep|nan|draw(Odur),destroy";
		initCard(
			Harrison_Jones,				//card
			"EX1_558",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> Destroy your opponent's weapon and draw cards equal to its Durability. “That belongs in the Hall of Explorers!”",
			"",				//race
			""				//hero
			);
	}
	{
		Card Harvest_Golem;
		Harvest_Golem.fx[2] = true;			//Deathrattle
		Harvest_Golem.fx2[2] = "nan:Pboard|nan|nan|summon(Golem=1)";
		initCard(
			Harvest_Golem,				//card
			"EX1_556",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Deathrattle:</b> Summon a 2/1 Damaged Golem. \"Overheat threshold exceeded. System failure. Wheat clog in port two. Shutting down.\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Headcrack;
		Headcrack.fx[0] = true;			//Spell AKA battlecry
		Headcrack.fx2[0] = "combo(1):time(then,PS,3):board|hero,hero,nan|nan,nan,self|dam+=2,dam+=2,return";
		initCard(
			Headcrack,				//card
			"EX1_137",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to the enemy hero. <b>Combo:</b> Return this to your hand next turn. When all else fails, nothing beats a swift whack upside the head.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Heavy_Axe;
		initCard(
			Heavy_Axe,				//card
			"EX1_409t",				//id
			"",				//rarity
			false,					//Collect
			"Weapon",				//type
			1,				//cost
			1,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hogger;
		Hogger.fx[14] = true;		//turnpoint
		Hogger.fx2[14] = "PE:Pboard|nan|nan|summon(Gnoll=1)";
		initCard(
			Hogger,				//card
			"NEW1_040",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			4,				//hp
			"At the end of your turn, summon a 2/2 Gnoll with <b>Taunt</b>. Hogger is super powerful. If you kill him, it's because he <i>let</i> you.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Fire;
		Holy_Fire.fx[0] = true;			//Spell AKA battlecry
		Holy_Fire.fx2[0] = "nan:board,Pboard|cha,hero|cho1,nan|dam+=5,dam-=5";
		initCard(
			Holy_Fire,				//card
			"EX1_624",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage. Restore #5 Health to your hero. Often followed by Holy Smokes!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Wrath;
		Holy_Wrath.fx[0] = true;			//Spell AKA battlecry
		Holy_Wrath.fx2[0] = "nan:Pboard,board|nan,cha|nan,cho1|draw(1),dam+=lastcost";
		initCard(
			Holy_Wrath,				//card
			"EX1_365",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Draw a card and deal damage equal to its cost. C'mon Molten Giant!!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hound;
		Hound.fx[1] = true;			//Charge
		initCard(
			Hound,				//card
			"EX1_538t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Charge</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Hungry_Crab;
		Hungry_Crab.fx[0] = true;			//Battlecry
		Hungry_Crab.fx2[0] = "nan:board,Pboard,Pboard|murloc,nan,nan|cho1,self,self|destroy,atk+=2,hp+=2";
		initCard(
			Hungry_Crab,				//card
			"NEW1_017",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Destroy a Murloc and gain +2/+2. Murloc.  It's what's for dinner.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Hyena;
		initCard(
			Hyena,				//card
			"EX1_534t",				//id
			"Rare",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Ice_Barrier;
		Ice_Barrier.fx[8] = true;			//Secret
		Ice_Barrier.fx2[8] = "ift(attacked):Pboard|hero|nan|nan,armr+=8";
		initCard(
			Ice_Barrier,				//card
			"EX1_289",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your hero is attacked, gain 8 Armor. This is Rank 1.  Rank 2 is Chocolate Milk Barrier.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ice_Block;
		Ice_Block.fx[8] = true;			//Secret
		Ice_Block.fx2[8] = "ift(fatal):time(till,PE,2):Pboard|hero|nan|nan,fx[17]=true";
		initCard(
			Ice_Block,				//card
			"EX1_295",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your hero takes fatal damage, prevent it and become <b>Immune</b> this turn. Ice is nice, and will suffice!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ice_Lance;
		Ice_Lance.fx[5] = true;			//Freeze
		Ice_Lance.fx[0] = true;			//Spell AKA battlecry
		Ice_Lance.fx2[0] = "if(frozen):board|cha|cho1,tar,tar|nan,freeze,dam+=4";
		initCard(
			Ice_Lance,				//card
			"CS2_031",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Freeze</b> a character. If it was already <b>Frozen</b>, deal $4 damage instead. The trick is not to break the lance.  Otherwise, you have \"Ice Pieces.\"  Ice Pieces aren't as effective.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Illidan_Stormrage;
		Illidan_Stormrage.fx[16] = true;		//trigger
		Illidan_Stormrage.fx2[16] = "ift(play):Pboard|nan|nan|nan,summon(Flame_of_Azzinoth=1)";
		initCard(
			Illidan_Stormrage,				//card
			"EX1_614",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			5,				//hp
			"Whenever you play a card, summon a 2/1 Flame of Azzinoth. Illidan's brother, Malfurion, imprisoned him beneath Hyjal for 10,000 years.  Stormrages are not good at letting go of grudges.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Imp;
		initCard(
			Imp,				//card
			"EX1_598",				//id
			"Rare",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Imp_Master;
		Imp_Master.fx[14] = true;		//turnpoint
		Imp_Master.fx2[14] = "PE:board,Pboard|nan|self,nan|dam+=1,summon(Imp=1)";
		initCard(
			Imp_Master,				//card
			"EX1_597",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			5,				//hp
			"At the end of your turn, deal 1 damage to this minion and summon a 1/1 Imp. She would enjoy the job a lot more if she just could get the imps to QUIT BITING HER.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Infernal;
		initCard(
			Infernal,				//card
			"EX1_tk34",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Injured_Blademaster;
		Injured_Blademaster.fx[0] = true;			//Battlecry
		Injured_Blademaster.fx2[0] = "nan:Pboard|nan|self|dam+=4";
		initCard(
			Injured_Blademaster,				//card
			"CS2_181",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			7,				//hp
			"<b>Battlecry:</b> Deal 4 damage to HIMSELF. He claims it is an old war wound, but we think he just cut himself shaving.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Inner_Fire;
		Inner_Fire.fx[0] = true;			//Spell AKA battlecry
		Inner_Fire.fx2[0] = "nan:board|min|cho1|atk=hp";
		initCard(
			Inner_Fire,				//card
			"CS1_129",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Change a minion's Attack to be equal to its Health. Good idea: Buffing your minions.  Bad idea: Starting a conversation in the Barrens.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Inner_Rage;
		Inner_Rage.fx[0] = true;			//Spell AKA battlecry
		Inner_Rage.fx2[0] = "nan:board|min|cho1,tar|dam+=1,atk+=2";
		initCard(
			Inner_Rage,				//card
			"EX1_607",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to a minion and give it +2 Attack. They're only smiling on the outside.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ironbeak_Owl;
		Ironbeak_Owl.fx[0] = true;			//Battlecry
		Ironbeak_Owl.fx2[0] = "nan:board|min|cho1|silence";
		initCard(
			Ironbeak_Owl,				//card
			"CS2_203",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> <b>Silence</b> a minion. Their wings are silent but their screech is... whatever the opposite of silent is.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Jungle_Panther;
		Jungle_Panther.fx[9] = true;			//Stealth
		initCard(
			Jungle_Panther,				//card
			"EX1_017",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Stealth</b> Stranglethorn is a beautiful place to visit, but you wouldn't want to live there.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Keeper_of_the_Grove;
		initCard(
			Keeper_of_the_Grove,				//card
			"EX1_166",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			4,				//hp
			"<b>Choose One</b> - Deal 2 damage; or <b>Silence</b> a minion. These guys just show up and start Keeping your Groves without even asking.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kidnapper;
		initCard(
			Kidnapper,				//card
			"NEW1_005",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			3,				//hp
			"<b>Combo:</b> Return a minion to its owner's hand. He just wants people to see his vacation photos.",
			"",				//race
			""				//hero
			);
	}
	{
		Card King_Krush;
		King_Krush.fx[1] = true;			//Charge
		initCard(
			King_Krush,				//card
			"EX1_543",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			8,				//hp
			"<b>Charge</b> The best defense against King Krush is to have someone you don’t like standing in front of you.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card King_Mukla;
		King_Mukla.fx[0] = true;			//Battlecry
		King_Mukla.fx2[0] = "nan:";
		initCard(
			King_Mukla,				//card
			"EX1_014",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give your opponent 2 Bananas. King Mukla wanders Jaguero Isle, searching for love.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Kirin_Tor_Mage;
		Kirin_Tor_Mage.fx[0] = true;			//Battlecry
		Kirin_Tor_Mage.fx2[0] = "nan:";
		initCard(
			Kirin_Tor_Mage,				//card
			"EX1_612",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> The next <b>Secret</b> you play this turn costs (0). The Kirin Tor reside in the floating city of Dalaran.  How do you make a Dalaran float?  Two scoops of ice cream, one scoop of Dalaran.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Knife_Juggler;
		initCard(
			Knife_Juggler,				//card
			"NEW1_019",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"After you summon a minion, deal 1 damage to a random enemy. Ambitious Knife Jugglers sometimes graduate to Bomb Jugglers.    They never last long enough to make it onto a card though.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Laughing_Sister;
		initCard(
			Laughing_Sister,				//card
			"DREAM_01",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			5,				//hp
			"Can't be targeted by spells or Hero Powers.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lava_Burst;
		Lava_Burst.fx[0] = true;			//Spell AKA battlecry
		Lava_Burst.fx2[0] = "nan:";
		initCard(
			Lava_Burst,				//card
			"EX1_241",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage. <b>Overload:</b> (2) It's like an ocean of liquid magma in your mouth!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lay_on_Hands;
		Lay_on_Hands.fx[0] = true;			//Spell AKA battlecry
		Lay_on_Hands.fx2[0] = "nan:";
		initCard(
			Lay_on_Hands,				//card
			"EX1_354",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			8,				//cost
			0,				//atk
			0,				//hp
			"Restore #8 Health. Draw 3 cards. A grammatically awkward life saver.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Leader_of_the_Pack;
		Leader_of_the_Pack.fx[0] = true;			//Spell AKA battlecry
		Leader_of_the_Pack.fx2[0] = "nan:";
		initCard(
			Leader_of_the_Pack,				//card
			"EX1_160b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give your minions +1/+1.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Leeroy_Jenkins;
		Leeroy_Jenkins.fx[0] = true;			//Battlecry
		Leeroy_Jenkins.fx2[0] = "nan:";
		Leeroy_Jenkins.fx[1] = true;			//Charge
		initCard(
			Leeroy_Jenkins,				//card
			"EX1_116",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			2,				//hp
			"<b>Charge</b>. <b>Battlecry:</b> Summon two 1/1 Whelps for your opponent. At least he has Angry Chicken.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Leper_Gnome;
		Leper_Gnome.fx[2] = true;			//Deathrattle
		Leper_Gnome.fx2[2] = "nan:";
		initCard(
			Leper_Gnome,				//card
			"EX1_029",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Deal 2 damage to the enemy hero. He really just wants to be your friend, but the constant rejection is starting to really get to him.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightning_Bolt;
		Lightning_Bolt.fx[0] = true;			//Spell AKA battlecry
		Lightning_Bolt.fx2[0] = "nan:";
		initCard(
			Lightning_Bolt,				//card
			"EX1_238",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage. <b>Overload:</b> (1) Lightning Bolt! Lightning Bolt! Lightning Bolt!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightning_Storm;
		Lightning_Storm.fx[0] = true;			//Spell AKA battlecry
		Lightning_Storm.fx2[0] = "nan:";
		initCard(
			Lightning_Storm,				//card
			"EX1_259",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $2-$3 damage to all enemy minions. <b>Overload:</b> (2) An umbrella won't be effective, I'm afraid.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightspawn;
		initCard(
			Lightspawn,				//card
			"EX1_335",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			0,				//atk
			5,				//hp
			"This minion's Attack is always equal to its Health. Spawn of the Light? Or Pawn of the Lights?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightwarden;
		initCard(
			Lightwarden,				//card
			"EX1_001",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"Whenever a character is healed, gain +2 Attack. She’s smaller than her sisters Mediumwarden and Heavywarden.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightwell;
		initCard(
			Lightwell,				//card
			"EX1_341",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			5,				//hp
			"At the start of your turn, restore 3 Health to a damaged friendly character. It isn't clear if people ignore the Lightwell, or if it is just invisible.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Loot_Hoarder;
		Loot_Hoarder.fx[2] = true;			//Deathrattle
		Loot_Hoarder.fx2[2] = "nan:";
		initCard(
			Loot_Hoarder,				//card
			"EX1_096",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Draw a card. Always roll need.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lord_Jaraxxus;
		Lord_Jaraxxus.fx[0] = true;			//Battlecry
		Lord_Jaraxxus.fx2[0] = "nan:";
		initCard(
			Lord_Jaraxxus,				//card
			"EX1_323",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			3,				//atk
			15,				//hp
			"<b>Battlecry:</b> Destroy your hero and replace it with Lord Jaraxxus. \"TRIFLING GNOME! YOUR ARROGANCE WILL BE YOUR UNDOING!!!!\"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Lorewalker_Cho;
		initCard(
			Lorewalker_Cho,				//card
			"EX1_100",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			4,				//hp
			"Whenever a player casts a spell, put a copy into the other player’s hand. Lorewalker Cho archives and shares tales from the land of Pandaria, but his favorite story is the one where Joey and Phoebe go on a road trip.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mad_Bomber;
		Mad_Bomber.fx[0] = true;			//Battlecry
		Mad_Bomber.fx2[0] = "nan:";
		initCard(
			Mad_Bomber,				//card
			"EX1_082",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 3 damage randomly split between all other characters. He's not really all that crazy, he is just not as careful with explosives as he should be.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Malygos;
		initCard(
			Malygos,				//card
			"EX1_563",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			4,				//atk
			12,				//hp
			"<b>Spell Damage +5</b> Malygos hates it when mortals use magic.  He gets so mad!",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Mana_Addict;
		initCard(
			Mana_Addict,				//card
			"EX1_055",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			3,				//hp
			"Whenever you cast a spell, gain +2 Attack this turn. She’s trying to kick the habit, but still takes some mana whenever she has a stressful day.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mana_Tide_Totem;
		initCard(
			Mana_Tide_Totem,				//card
			"EX1_575",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			0,				//atk
			3,				//hp
			"At the end of your turn, draw a card. It is said that some shaman can say \"Floatin' totem\" 10 times, fast.",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Mana_Wraith;
		initCard(
			Mana_Wraith,				//card
			"EX1_616",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"ALL minions cost (1) more. They come out at night to eat leftover mana crystals. \"Mmmmmm,\" they say.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mana_Wyrm;
		initCard(
			Mana_Wyrm,				//card
			"NEW1_012",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			3,				//hp
			"Whenever you cast a spell, gain +1 Attack. These wyrms feed on arcane energies, and while they are generally considered a nuisance rather than a real threat, you really shouldn't leave them alone with a bucket of mana.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mark_of_Nature;
		Mark_of_Nature.fx[0] = true;			//Spell AKA battlecry
		Mark_of_Nature.fx2[0] = "nan:";
		initCard(
			Mark_of_Nature,				//card
			"EX1_155",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One</b> - Give a minion +4 Attack; or +4 Health and <b>Taunt</b>. Druids call it the \"Mark of Nature.\"  Everyone else calls it \"needing a bath.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mass_Dispel;
		Mass_Dispel.fx[0] = true;			//Spell AKA battlecry
		Mass_Dispel.fx2[0] = "nan:";
		initCard(
			Mass_Dispel,				//card
			"EX1_626",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"<b>Silence</b> all enemy minions. Draw a card. It dispels buffs, powers, hopes, and dreams.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Master_Swordsmith;
		initCard(
			Master_Swordsmith,				//card
			"NEW1_037",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			3,				//hp
			"At the end of your turn, give another random friendly minion +1 Attack. He's currently trying to craft a \"flail-axe\", but all the other swordsmiths say it can't be done.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Master_of_Disguise;
		Master_of_Disguise.fx[0] = true;			//Battlecry
		Master_of_Disguise.fx2[0] = "nan:";
		initCard(
			Master_of_Disguise,				//card
			"NEW1_014",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Give a friendly minion <b>Stealth</b>. She's actually a male tauren.  People don't call him \"Master of Disguise\" for nothing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Millhouse_Manastorm;
		Millhouse_Manastorm.fx[0] = true;			//Battlecry
		Millhouse_Manastorm.fx2[0] = "nan:";
		initCard(
			Millhouse_Manastorm,				//card
			"NEW1_029",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Enemy spells cost (0) next turn. \"I'm gonna light you up, sweetcheeks!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mind_Control_Tech;
		Mind_Control_Tech.fx[0] = true;			//Battlecry
		Mind_Control_Tech.fx2[0] = "nan:";
		initCard(
			Mind_Control_Tech,				//card
			"EX1_085",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> If your opponent has 4 or more minions, take control of one at random. Mind Control technology is getting better, but that's not saying much.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mindgames;
		Mindgames.fx[0] = true;			//Spell AKA battlecry
		Mindgames.fx2[0] = "nan:";
		initCard(
			Mindgames,				//card
			"EX1_345",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Put a copy of a random minion from your opponent's deck into the battlefield. Sometimes it feels like this is all a game.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mirror_Entity;
		Mirror_Entity.fx[8] = true;			//Secret
		Mirror_Entity.fx2[8] = "nan:";
		Mirror_Entity.fx[0] = true;			//Spell AKA battlecry
		Mirror_Entity.fx2[0] = "nan:";
		initCard(
			Mirror_Entity,				//card
			"EX1_294",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your opponent plays a minion, summon a copy of it. \"You go first.\" - Krush'gor the Behemoth, to his pet boar.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Misdirection;
		Misdirection.fx[8] = true;			//Secret
		Misdirection.fx2[8] = "nan:";
		Misdirection.fx[0] = true;			//Spell AKA battlecry
		Misdirection.fx2[0] = "nan:";
		initCard(
			Misdirection,				//card
			"EX1_533",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When a character attacks your hero, instead he attacks another random character. Sometimes it's as simple as putting on a fake mustache and pointing at someone else.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mogushan_Warden;
		Mogushan_Warden.fx[10] = true;			//Taunt
		initCard(
			Mogushan_Warden,				//card
			"EX1_396",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			7,				//hp
			"<b>Taunt</b> All these guys ever do is talk about the Thunder King.   BOOOORRRINNG!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Molten_Giant;
		initCard(
			Molten_Giant,				//card
			"EX1_620",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			20,				//cost
			8,				//atk
			8,				//hp
			"Costs (1) less for each damage your hero has taken. He gets terrible heartburn.  BECAUSE HE IS FULL OF LAVA.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Moonfire;
		Moonfire.fx[0] = true;			//Spell AKA battlecry
		Moonfire.fx2[0] = "nan:";
		initCard(
			Moonfire,				//card
			"EX1_166a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal 2 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mortal_Strike;
		Mortal_Strike.fx[0] = true;			//Spell AKA battlecry
		Mortal_Strike.fx2[0] = "nan:";
		initCard(
			Mortal_Strike,				//card
			"EX1_408",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage. If you have 12 or less Health, deal $6 instead. \"If you only use one ability, use Mortal Strike.\" - The Warrior Code, Line 6",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mountain_Giant;
		initCard(
			Mountain_Giant,				//card
			"EX1_105",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			12,				//cost
			8,				//atk
			8,				//hp
			"Costs (1) less for each other card in your hand. His mother said that he was just big boned.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Tidecaller;
		initCard(
			Murloc_Tidecaller,				//card
			"EX1_509",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"Whenever a Murloc is summoned, gain +1 Attack. This guy gets crazy strong at family reunions.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Warleader;
		initCard(
			Murloc_Warleader,				//card
			"EX1_507",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"ALL other Murlocs have +2/+1. Do Murlocs ever get tired of making the same old sound?  Nope!  Mrglglrglglglglglglgl!",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Nat_Pagle;
		initCard(
			Nat_Pagle,				//card
			"EX1_557",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			4,				//hp
			"At the start of your turn, you have a 50% chance to draw an extra card. Nat Pagle, Azeroth's premier fisherman!  He invented the Auto-Angler 3000, the Extendo-Pole 3000, and the Lure-o-matic 2099 (still in testing).",
			"",				//race
			""				//hero
			);
	}
	{
		Card Naturalize;
		Naturalize.fx[0] = true;			//Spell AKA battlecry
		Naturalize.fx2[0] = "nan:";
		initCard(
			Naturalize,				//card
			"EX1_161",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion. Your opponent draws 2 cards. Another one bites the dust.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nightmare;
		Nightmare.fx[0] = true;			//Spell AKA battlecry
		Nightmare.fx2[0] = "nan:";
		initCard(
			Nightmare,				//card
			"DREAM_05",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +5/+5. At the start of your next turn, destroy it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Noble_Sacrifice;
		Noble_Sacrifice.fx[8] = true;			//Secret
		Noble_Sacrifice.fx2[8] = "nan:";
		Noble_Sacrifice.fx[0] = true;			//Spell AKA battlecry
		Noble_Sacrifice.fx2[0] = "nan:";
		initCard(
			Noble_Sacrifice,				//card
			"EX1_130",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When an enemy attacks, summon a 2/1 Defender as the new target. We will always remember you, \"Defender!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nourish;
		Nourish.fx[0] = true;			//Spell AKA battlecry
		Nourish.fx2[0] = "nan:";
		initCard(
			Nourish,				//card
			"EX1_164",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One</b> - Gain 2 Mana Crystals; or Draw 3 cards. Druids take nourishment from many things: the power of nature, the songbird's chirp, a chocolate cake.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nozdormu;
		initCard(
			Nozdormu,				//card
			"EX1_560",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			8,				//hp
			"Players only have 15 seconds to take their turns. Time to write some flavor text.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Onyxia;
		Onyxia.fx[0] = true;			//Battlecry
		Onyxia.fx2[0] = "nan:";
		initCard(
			Onyxia,				//card
			"EX1_562",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			8,				//hp
			"<b>Battlecry:</b> Summon 1/1 Whelps until your side of the battlefield is full. Onyxia long manipulated the Stormwind Court by disguising herself as Lady Katrana Prestor.   You would have thought that the giant wings and scales would have been a giveaway.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Panther;
		initCard(
			Panther,				//card
			"EX1_160t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Patient_Assassin;
		Patient_Assassin.fx[7] = true;			//Poisonous
		Patient_Assassin.fx[9] = true;			//Stealth
		initCard(
			Patient_Assassin,				//card
			"EX1_522",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			1,				//hp
			"<b>Stealth</b>. Destroy any minion damaged by this minion. He’s not really that patient. It just takes a while for someone to walk by that he can actually reach.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Perditions_Blade;
		Perditions_Blade.fx[0] = true;			//Battlecry
		Perditions_Blade.fx2[0] = "nan:";
		initCard(
			Perditions_Blade,				//card
			"EX1_133",				//id
			"Rare",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			2,				//atk
			0,				//hp
			"<b>Battlecry:</b> Deal 1 damage. <b>Combo:</b> Deal 2 instead. Perdition's Blade is Ragnaros's back-up weapon while Sulfuras is in the shop.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pint_Sized_Summoner;
		initCard(
			Pint_Sized_Summoner,				//card
			"EX1_076",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"The first minion you play each turn costs (1) less. She's quite jealous of the Gallon-Sized Summoner.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pit_Lord;
		Pit_Lord.fx[0] = true;			//Battlecry
		Pit_Lord.fx2[0] = "nan:";
		initCard(
			Pit_Lord,				//card
			"EX1_313",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			6,				//hp
			"<b>Battlecry:</b> Deal 5 damage to your hero. Mannoroth, Magtheridon, and Brutallus may be dead, but it turns out there are a LOT of pit lords.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Power_Overwhelming;
		Power_Overwhelming.fx[0] = true;			//Spell AKA battlecry
		Power_Overwhelming.fx2[0] = "nan:";
		initCard(
			Power_Overwhelming,				//card
			"EX1_316",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a friendly minion +4/+4 until end of turn. Then, it dies. Horribly. We cannot even describe how horrible the death is.  It's CRAZY bad!  Maybe worse than that.  Just don't do it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Power_of_the_Wild;
		Power_of_the_Wild.fx[0] = true;			//Spell AKA battlecry
		Power_of_the_Wild.fx2[0] = "nan:";
		initCard(
			Power_of_the_Wild,				//card
			"EX1_160",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One</b> - Give your minions +1/+1; or Summon a 3/2 Panther. Never look a panther in the eye.  Or is it 'Always look a panther in the eye'?  Well, it's one of those.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Preparation;
		Preparation.fx[0] = true;			//Spell AKA battlecry
		Preparation.fx2[0] = "nan:";
		initCard(
			Preparation,				//card
			"EX1_145",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"The next spell you cast this turn costs (3) less. \"Be Prepared\" - Rogue Motto",
			"",				//race
			""				//hero
			);
	}
	{
		Card Priestess_of_Elune;
		Priestess_of_Elune.fx[0] = true;			//Battlecry
		Priestess_of_Elune.fx2[0] = "nan:";
		initCard(
			Priestess_of_Elune,				//card
			"EX1_583",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> Restore 4 Health to your hero. If she threatens to \"moon\" you, it's not what you think.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Prophet_Velen;
		initCard(
			Prophet_Velen,				//card
			"EX1_350",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			7,				//hp
			"Double the damage and healing of your spells and Hero Power. He's been exiled from his home, and all his brothers turned evil, but otherwise he doesn't have a lot to complain about.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pyroblast;
		Pyroblast.fx[0] = true;			//Spell AKA battlecry
		Pyroblast.fx2[0] = "nan:";
		initCard(
			Pyroblast,				//card
			"EX1_279",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			10,				//cost
			0,				//atk
			0,				//hp
			"Deal $10 damage. Take the time for an evil laugh after you draw this card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Questing_Adventurer;
		initCard(
			Questing_Adventurer,				//card
			"EX1_044",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"Whenever you play a card, gain +1/+1. \"Does anyone have some extra Boar Pelts?\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Raging_Worgen;
		Raging_Worgen.fx[4] = true;			//Enrage
		Raging_Worgen.fx2[4] = "nan:";
		initCard(
			Raging_Worgen,				//card
			"EX1_412",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Enrage:</b> <b>Windfury</b> and +1 Attack If he's raging now, just wait until he gets nerfed.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ragnaros_the_Firelord;
		initCard(
			Ragnaros_the_Firelord,				//card
			"EX1_298",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			8,				//atk
			8,				//hp
			"Can't attack. At the end of your turn, deal 8 damage to a random enemy. Ragnaros was summoned by the Dark Iron dwarves, who were eventually enslaved by the Firelord.  Summoning Ragnaros often doesn’t work out the way you want it to.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rampage;
		Rampage.fx[0] = true;			//Spell AKA battlecry
		Rampage.fx2[0] = "nan:";
		initCard(
			Rampage,				//card
			"CS2_104",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give a damaged minion +3/+3. Minion get ANGRY.   Minion SMASH!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ravenholdt_Assassin;
		Ravenholdt_Assassin.fx[9] = true;			//Stealth
		initCard(
			Ravenholdt_Assassin,				//card
			"CS2_161",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			5,				//hp
			"<b>Stealth</b> Just mail him a package with a name and 10,000 gold.  He'll take care of the rest.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Redemption;
		Redemption.fx[8] = true;			//Secret
		Redemption.fx2[8] = "nan:";
		Redemption.fx[0] = true;			//Spell AKA battlecry
		Redemption.fx2[0] = "nan:";
		initCard(
			Redemption,				//card
			"EX1_136",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When one of your minions dies, return it to life with 1 Health. I am not sure how you get demptioned the first time.  It’s a mystery!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Repentance;
		Repentance.fx[8] = true;			//Secret
		Repentance.fx2[8] = "nan:";
		Repentance.fx[0] = true;			//Spell AKA battlecry
		Repentance.fx2[0] = "nan:";
		initCard(
			Repentance,				//card
			"EX1_379",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your opponent plays a minion, reduce its Health to 1. Repentance often comes in the moment before obliteration. Curious.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rooted;
		Rooted.fx[0] = true;			//Spell AKA battlecry
		Rooted.fx2[0] = "nan:";
		initCard(
			Rooted,				//card
			"EX1_178a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+5 Health and <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card SI_7_Agent;
		initCard(
			SI_7_Agent,				//card
			"EX1_134",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Combo:</b> Deal 2 damage. The agents of SI:7 are responsible for Stormwind's covert activities.  Their duties include espionage, assassination, and throwing surprise birthday parties for the royal family.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Savagery;
		Savagery.fx[0] = true;			//Spell AKA battlecry
		Savagery.fx2[0] = "nan:";
		initCard(
			Savagery,				//card
			"EX1_578",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal damage equal to your hero's Attack to a minion. It is true that some druids are savage, but others still enjoy a quiet moment and a spot of tea.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Savannah_Highmane;
		Savannah_Highmane.fx[2] = true;			//Deathrattle
		Savannah_Highmane.fx2[2] = "nan:";
		initCard(
			Savannah_Highmane,				//card
			"EX1_534",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			5,				//hp
			"<b>Deathrattle:</b> Summon two 2/2 Hyenas. In the jungle, the mighty jungle, the lion gets slowly consumed by hyenas.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Scarlet_Crusader;
		Scarlet_Crusader.fx[3] = true;			//Divine Shield
		initCard(
			Scarlet_Crusader,				//card
			"EX1_020",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			1,				//hp
			"<b>Divine Shield</b> Never wash your whites with a Scarlet Crusader.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Scavenging_Hyena;
		initCard(
			Scavenging_Hyena,				//card
			"EX1_531",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"Whenever a friendly Beast dies, gain +2/+1. Hyenas prefer the bones of kodos or windserpents, but they'll eat pretty much anything.  Even Brussels sprouts.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Sea_Giant;
		initCard(
			Sea_Giant,				//card
			"EX1_586",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			10,				//cost
			8,				//atk
			8,				//hp
			"Costs (1) less for each other minion on the battlefield. See?  Giant.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Secretkeeper;
		initCard(
			Secretkeeper,				//card
			"EX1_080",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"Whenever a <b>Secret</b> is played, gain +1/+1. She promises not to tell anyone about that thing you did last night with that one person.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sense_Demons;
		Sense_Demons.fx[0] = true;			//Spell AKA battlecry
		Sense_Demons.fx2[0] = "nan:";
		initCard(
			Sense_Demons,				//card
			"EX1_317",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Put 2 random Demons from your deck into your hand. Generally demons are pretty obvious and you don’t need a spell to sense them.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadow_Madness;
		Shadow_Madness.fx[0] = true;			//Spell AKA battlecry
		Shadow_Madness.fx2[0] = "nan:";
		initCard(
			Shadow_Madness,				//card
			"EX1_334",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Gain control of an enemy minion with 3 or less Attack until end of turn. You can rationalize it all you want, it's still a mean thing to do.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadow_of_Nothing;
		initCard(
			Shadow_of_Nothing,				//card
			"EX1_345t",				//id
			"Epic",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			1,				//hp
			"Mindgames whiffed! Your opponent had no minions!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowflame;
		Shadowflame.fx[0] = true;			//Spell AKA battlecry
		Shadowflame.fx2[0] = "nan:";
		initCard(
			Shadowflame,				//card
			"EX1_303",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Destroy a friendly minion and deal its Attack damage to all enemy minions. Start with a powerful minion and stir in Shadowflame and you have a good time!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowform;
		Shadowform.fx[0] = true;			//Spell AKA battlecry
		Shadowform.fx2[0] = "nan:";
		initCard(
			Shadowform,				//card
			"EX1_625",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Your Hero Power becomes 'Deal 2 damage'. If already in Shadowform: 3 damage. If a bright light shines on a priest in Shadowform… do they cast a shadow?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowstep;
		Shadowstep.fx[0] = true;			//Spell AKA battlecry
		Shadowstep.fx2[0] = "nan:";
		initCard(
			Shadowstep,				//card
			"EX1_144",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Return a friendly minion to your hand. It costs (2) less. Rogue dance troops will sometimes Shadowstep away at the end of a performance.  Crowds love it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shandos_Lesson;
		Shandos_Lesson.fx[0] = true;			//Spell AKA battlecry
		Shandos_Lesson.fx2[0] = "nan:";
		initCard(
			Shandos_Lesson,				//card
			"EX1_573b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Summon two 2/2 Treants with <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shield_Slam;
		Shield_Slam.fx[0] = true;			//Spell AKA battlecry
		Shield_Slam.fx2[0] = "nan:";
		initCard(
			Shield_Slam,				//card
			"EX1_410",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal 1 damage to a minion for each Armor you have. \"What is a better weapon? The sharp one your enemies expect, or the blunt one they ignore?\" - The Art of Warrior, Chapter 9",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shieldbearer;
		Shieldbearer.fx[10] = true;			//Taunt
		initCard(
			Shieldbearer,				//card
			"EX1_405",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			4,				//hp
			"<b>Taunt</b> Have you seen the size of the shields in this game??  This is no easy job.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silence;
		Silence.fx[0] = true;			//Spell AKA battlecry
		Silence.fx2[0] = "nan:";
		initCard(
			Silence,				//card
			"EX1_332",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"<b>Silence</b> a minion. Reserved for enemy spellcasters, evil liches from beyond the grave, and karaoke nights at the Grim Guzzler.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silver_Hand_Knight;
		Silver_Hand_Knight.fx[0] = true;			//Battlecry
		Silver_Hand_Knight.fx2[0] = "nan:";
		initCard(
			Silver_Hand_Knight,				//card
			"CS2_151",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Summon a 2/2 Squire. It's good to be a knight.   Less so to be one's squire.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silvermoon_Guardian;
		Silvermoon_Guardian.fx[3] = true;			//Divine Shield
		initCard(
			Silvermoon_Guardian,				//card
			"EX1_023",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"<b>Divine Shield</b> The first time they tried to guard Silvermoon against the scourge, it didn’t go so well…",
			"",				//race
			""				//hero
			);
	}
	{
		Card Siphon_Soul;
		Siphon_Soul.fx[0] = true;			//Spell AKA battlecry
		Siphon_Soul.fx2[0] = "nan:";
		initCard(
			Siphon_Soul,				//card
			"EX1_309",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion. Restore #3 Health to your hero. You probably should avoid siphoning your own soul.  You might create some kind of weird infinite loop.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Slam;
		Slam.fx[0] = true;			//Spell AKA battlecry
		Slam.fx2[0] = "nan:";
		initCard(
			Slam,				//card
			"EX1_391",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to a minion. If it survives, draw a card. \"Dun da dun, dun da dun\": if you've heard an ogre sing this, it's too late.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Snake;
		initCard(
			Snake,				//card
			"EX1_554t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Snake_Trap;
		Snake_Trap.fx[8] = true;			//Secret
		Snake_Trap.fx2[8] = "nan:";
		Snake_Trap.fx[0] = true;			//Spell AKA battlecry
		Snake_Trap.fx2[0] = "nan:";
		initCard(
			Snake_Trap,				//card
			"EX1_554",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When one of your minions is attacked, summon three 1/1 Snakes. Why did it have to be snakes?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Snipe;
		Snipe.fx[8] = true;			//Secret
		Snipe.fx2[8] = "nan:";
		Snipe.fx[0] = true;			//Spell AKA battlecry
		Snipe.fx2[0] = "nan:";
		initCard(
			Snipe,				//card
			"EX1_609",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your opponent plays a minion, deal $4 damage to it. A great sniper hits the spot.  Just like a delicious flank of boar. Mmmmm.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sorcerers_Apprentice;
		initCard(
			Sorcerers_Apprentice,				//card
			"EX1_608",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"Your spells cost (1) less. Apprentices are great for bossing around.  \"Conjure me some mana buns! And a coffee!  Make that a mana coffee!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Soul_of_the_Forest;
		Soul_of_the_Forest.fx[0] = true;			//Spell AKA battlecry
		Soul_of_the_Forest.fx2[0] = "nan:";
		initCard(
			Soul_of_the_Forest,				//card
			"EX1_158",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Give your minions \"<b>Deathrattle:</b> Summon a 2/2 Treant.\" \"Reforestation\" is suddenly a terrifying word.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Southsea_Captain;
		initCard(
			Southsea_Captain,				//card
			"NEW1_027",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"Your other Pirates have +1/+1. When he saves enough plunder, he's going to commission an enormous captain's hat.  He has hat envy.",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Southsea_Deckhand;
		initCard(
			Southsea_Deckhand,				//card
			"CS2_146",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"Has <b>Charge</b> while you have a weapon equipped. Pirates are into this new fad called \"Planking\".",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Spellbender;
		Spellbender.fx[8] = true;			//Secret
		Spellbender.fx2[8] = "nan:";
		Spellbender.fx[0] = true;			//Spell AKA battlecry
		Spellbender.fx2[0] = "nan:";
		initCard(
			Spellbender,				//card
			"tt_010",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When an enemy casts a spell on a minion, summon a 1/3 as the new target. While it's fun to intercept enemy lightning bolts, a spellbender much prefers to intercept opposing Marks of the Wild.  It just feels meaner.  And blood elves... well, they're a little mean.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spellbender;
		initCard(
			Spellbender,				//card
			"tt_010a",				//id
			"Epic",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			3,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spellbreaker;
		Spellbreaker.fx[0] = true;			//Battlecry
		Spellbreaker.fx2[0] = "nan:";
		initCard(
			Spellbreaker,				//card
			"EX1_048",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> <b>Silence</b> a minion. Spellbreakers can rip enchantments from magic-wielders.  The process is painless and can be performed on an outpatient basis.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spirit_Wolf;
		Spirit_Wolf.fx[10] = true;			//Taunt
		initCard(
			Spirit_Wolf,				//card
			"EX1_tk11",				//id
			"Rare",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spiteful_Smith;
		Spiteful_Smith.fx[4] = true;			//Enrage
		Spiteful_Smith.fx2[4] = "nan:";
		initCard(
			Spiteful_Smith,				//card
			"CS2_221",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			6,				//hp
			"<b>Enrage:</b> Your weapon has +2 Attack. She'll craft you a sword, but you'll need to bring her 5 Steel Ingots, 3 Motes of Earth, and the scalp of her last customer.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Squire;
		initCard(
			Squire,				//card
			"CS2_152",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Squirrel;
		initCard(
			Squirrel,				//card
			"EX1_tk28",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Stampeding_Kodo;
		Stampeding_Kodo.fx[0] = true;			//Battlecry
		Stampeding_Kodo.fx2[0] = "nan:";
		initCard(
			Stampeding_Kodo,				//card
			"NEW1_041",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			5,				//hp
			"<b>Battlecry:</b> Destroy a random enemy minion with 2 or less Attack. This Kodo is so big that he can stampede by <i>himself</i>.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Starfall;
		Starfall.fx[0] = true;			//Spell AKA battlecry
		Starfall.fx2[0] = "nan:";
		initCard(
			Starfall,				//card
			"NEW1_007",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One -</b> Deal $5 damage to a minion; or $2 damage to all enemy minions. Is the sky falling?  Yes.  Yes it is.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stormforged_Axe;
		initCard(
			Stormforged_Axe,				//card
			"EX1_247",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			2,				//atk
			0,				//hp
			"<b>Overload:</b> (1) Yo, that's a nice axe.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stranglethorn_Tiger;
		Stranglethorn_Tiger.fx[9] = true;			//Stealth
		initCard(
			Stranglethorn_Tiger,				//card
			"EX1_028",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Stealth</b> The wonderful thing about tigers is tigers are wonderful things!",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Summon_a_Panther;
		Summon_a_Panther.fx[0] = true;			//Spell AKA battlecry
		Summon_a_Panther.fx2[0] = "nan:";
		initCard(
			Summon_a_Panther,				//card
			"EX1_160a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Summon a 3/2 Panther.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Summoning_Portal;
		initCard(
			Summoning_Portal,				//card
			"EX1_315",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			0,				//atk
			4,				//hp
			"Your minions cost (2) less, but not less than (1). NOT LESS THAN 1!  Don't get any ideas!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sunfury_Protector;
		Sunfury_Protector.fx[0] = true;			//Battlecry
		Sunfury_Protector.fx2[0] = "nan:";
		initCard(
			Sunfury_Protector,				//card
			"EX1_058",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Give adjacent minions <b>Taunt</b>. She carries a shield, but only so she can give it to someone she can stand behind.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sunwalker;
		Sunwalker.fx[3] = true;			//Divine Shield
		Sunwalker.fx[10] = true;			//Taunt
		initCard(
			Sunwalker,				//card
			"EX1_032",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			5,				//hp
			"<b>Taunt</b>\n<b>Divine Shield</b> She doesn’t ACTUALLY walk on the Sun.  It's just a name.  Don’t worry!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sword_of_Justice;
		initCard(
			Sword_of_Justice,				//card
			"EX1_366",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			1,				//atk
			0,				//hp
			"Whenever you summon a minion, give it +1/+1 and this loses 1 Durability. I dub you Sir Loin of Beef!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sylvanas_Windrunner;
		Sylvanas_Windrunner.fx[2] = true;			//Deathrattle
		Sylvanas_Windrunner.fx2[2] = "nan:";
		initCard(
			Sylvanas_Windrunner,				//card
			"EX1_016",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"<b>Deathrattle:</b> Take control of a random enemy minion. Sylvanas was turned into the Banshee Queen by Arthas, but he probably should have just killed her because it just pissed her off.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tauren_Warrior;
		Tauren_Warrior.fx[4] = true;			//Enrage
		Tauren_Warrior.fx2[4] = "nan:";
		Tauren_Warrior.fx[10] = true;			//Taunt
		initCard(
			Tauren_Warrior,				//card
			"EX1_390",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Taunt</b>. <b>Enrage:</b> +3 Attack Tauren Warrior: Champion of Mulgore, Slayer of Quilboar, Rider of Thunderbluff Elevators.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Temple_Enforcer;
		Temple_Enforcer.fx[0] = true;			//Battlecry
		Temple_Enforcer.fx2[0] = "nan:";
		initCard(
			Temple_Enforcer,				//card
			"EX1_623",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"<b>Battlecry:</b> Give a friendly minion +3 Health. He also moonlights Thursday nights as a bouncer at the Pig and Whistle Tavern.",
			"",				//race
			""				//hero
			);
	}
	{
		Card The_Beast;
		The_Beast.fx[2] = true;			//Deathrattle
		The_Beast.fx2[2] = "nan:";
		initCard(
			The_Beast,				//card
			"EX1_577",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			9,				//atk
			7,				//hp
			"<b>Deathrattle:</b> Summon a 3/3 Finkle Einhorn for your opponent. He lives in Blackrock Mountain.  He eats Gnomes.  That's pretty much it.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card The_Black_Knight;
		The_Black_Knight.fx[0] = true;			//Battlecry
		The_Black_Knight.fx2[0] = "nan:";
		initCard(
			The_Black_Knight,				//card
			"EX1_002",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			5,				//hp
			"<b>Battlecry:</b> Destroy an enemy minion with <b>Taunt</b>. He was sent by the Lich King to disrupt the Argent Tournament.   We can pretty much mark that a failure.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Thoughtsteal;
		Thoughtsteal.fx[0] = true;			//Spell AKA battlecry
		Thoughtsteal.fx2[0] = "nan:";
		initCard(
			Thoughtsteal,				//card
			"EX1_339",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Copy 2 cards from your opponent's deck and put them into your hand. \"What do you get when you cast Thoughtsteal on an Orc?  Nothing!\" - Tauren joke",
			"",				//race
			""				//hero
			);
	}
	{
		Card Thrallmar_Farseer;
		Thrallmar_Farseer.fx[11] = true;			//Windfury
		initCard(
			Thrallmar_Farseer,				//card
			"EX1_021",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Windfury</b> He's stationed in the Hellfire Peninsula, but he's hoping for a reassignment closer to Orgrimmar, or really anywhere the ground is less on fire.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tinkmaster_Overspark;
		Tinkmaster_Overspark.fx[0] = true;			//Battlecry
		Tinkmaster_Overspark.fx2[0] = "nan:";
		initCard(
			Tinkmaster_Overspark,				//card
			"EX1_083",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Transform another random minion into a 5/5 Devilsaur or a 1/1 Squirrel. Tinkmaster Overspark nearly lost his Tinker's license after the Great Ironforge Squirrel Stampede of '09.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tirion_Fordring;
		Tirion_Fordring.fx[2] = true;			//Deathrattle
		Tirion_Fordring.fx2[2] = "nan:";
		Tirion_Fordring.fx[3] = true;			//Divine Shield
		Tirion_Fordring.fx[10] = true;			//Taunt
		initCard(
			Tirion_Fordring,				//card
			"EX1_383",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			6,				//atk
			6,				//hp
			"<b>Divine Shield</b>. <b>Taunt</b>. <b>Deathrattle:</b> Equip a 5/3 Ashbringer. If you haven't heard the Tirion Fordring theme song, it's because it doesn't exist.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Treant;
		Treant.fx[1] = true;			//Charge
		initCard(
			Treant,				//card
			"EX1_tk9",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"<b>Charge</b>.  At the end of the turn, destroy this minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Treant;
		initCard(
			Treant,				//card
			"EX1_158t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Treant;
		Treant.fx[10] = true;			//Taunt
		initCard(
			Treant,				//card
			"EX1_573t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Twilight_Drake;
		Twilight_Drake.fx[0] = true;			//Battlecry
		Twilight_Drake.fx2[0] = "nan:";
		initCard(
			Twilight_Drake,				//card
			"EX1_043",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			1,				//hp
			"<b>Battlecry:</b> Gain +1 Health for each card in your hand. Twilight drakes feed on Mystical Energy.  And Tacos.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Twisting_Nether;
		Twisting_Nether.fx[0] = true;			//Spell AKA battlecry
		Twisting_Nether.fx2[0] = "nan:";
		initCard(
			Twisting_Nether,				//card
			"EX1_312",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			8,				//cost
			0,				//atk
			0,				//hp
			"Destroy all minions. The Twisting Nether is a formless place of magic and illusion and destroyed minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Unbound_Elemental;
		initCard(
			Unbound_Elemental,				//card
			"EX1_258",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Whenever you play a card with <b>Overload</b>, gain +1/+1. Unlike bound elementals, Unbound ones really enjoy a night on the town.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Unleash_the_Hounds;
		Unleash_the_Hounds.fx[0] = true;			//Spell AKA battlecry
		Unleash_the_Hounds.fx2[0] = "nan:";
		initCard(
			Unleash_the_Hounds,				//card
			"EX1_538",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"For each enemy minion, summon a 1/1 Hound with <b>Charge</b>. You must read the name of this card out loud each time you play it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Upgrade;
		Upgrade.fx[0] = true;			//Spell AKA battlecry
		Upgrade.fx2[0] = "nan:";
		initCard(
			Upgrade,				//card
			"EX1_409",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"If you have a weapon, give it +1/+1. Otherwise equip a 1/3 weapon. Easily worth 50 DKP.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Uproot;
		Uproot.fx[0] = true;			//Spell AKA battlecry
		Uproot.fx2[0] = "nan:";
		initCard(
			Uproot,				//card
			"EX1_178b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+5 Attack.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Vaporize;
		Vaporize.fx[8] = true;			//Secret
		Vaporize.fx2[8] = "nan:";
		Vaporize.fx[0] = true;			//Spell AKA battlecry
		Vaporize.fx2[0] = "nan:";
		initCard(
			Vaporize,				//card
			"EX1_594",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When a minion attacks your hero, destroy it. Rumor has it that Deathwing brought about the Cataclysm after losing a game to this card.  We may never know the truth.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Venture_Co_Mercenary;
		initCard(
			Venture_Co_Mercenary,				//card
			"CS2_227",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			6,				//hp
			"Your minions cost (3) more. No Job is too big.  No fee is too big.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Violet_Apprentice;
		initCard(
			Violet_Apprentice,				//card
			"NEW1_026t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Violet_Teacher;
		initCard(
			Violet_Teacher,				//card
			"NEW1_026",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Whenever you cast a spell, summon a 1/1 Violet Apprentice. If you don't pay attention, you may be turned into a pig.  And then you get your name on the board.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Void_Terror;
		Void_Terror.fx[0] = true;			//Battlecry
		Void_Terror.fx2[0] = "nan:";
		initCard(
			Void_Terror,				//card
			"EX1_304",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Destroy the minions on either side of this minion and gain their Attack and Health. If you put this into your deck, you WILL lose the trust of your other minions.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Whelp;
		initCard(
			Whelp,				//card
			"EX1_116t",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Whelp;
		initCard(
			Whelp,				//card
			"ds1_whelptoken",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Wild_Pyromancer;
		initCard(
			Wild_Pyromancer,				//card
			"NEW1_020",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"After you cast a spell, deal 1 damage to ALL minions. BOOM BABY BOOM!  BAD IS GOOD!  DOWN WITH GOVERNMENT!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Windfury_Harpy;
		Windfury_Harpy.fx[11] = true;			//Windfury
		initCard(
			Windfury_Harpy,				//card
			"EX1_033",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			5,				//hp
			"<b>Windfury</b> Harpies are not pleasant sounding.  That's the nicest I can put it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wisp;
		initCard(
			Wisp,				//card
			"CS2_231",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"If you hit an Eredar Lord with enough Wisps, it will explode.   But why?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Worgen_Infiltrator;
		Worgen_Infiltrator.fx[9] = true;			//Stealth
		initCard(
			Worgen_Infiltrator,				//card
			"EX1_010",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Stealth</b> If you want to stop a worgen from infiltrating, just yell, \"No! Bad boy!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Worthless_Imp;
		initCard(
			Worthless_Imp,				//card
			"EX1_317t",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<i>You are out of demons! At least there are always imps...</i>",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Wrath;
		Wrath.fx[0] = true;			//Spell AKA battlecry
		Wrath.fx2[0] = "nan:";
		initCard(
			Wrath,				//card
			"EX1_154",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One</b> - Deal $3 damage to a minion; or $1 damage and draw a card. The talk around the Ratchet Inn is that this card is too good and should be a Legendary.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Young_Dragonhawk;
		Young_Dragonhawk.fx[11] = true;			//Windfury
		initCard(
			Young_Dragonhawk,				//card
			"CS2_169",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Windfury</b> They were the inspiration for the championship Taurenball team: The Dragonhawks.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Young_Priestess;
		initCard(
			Young_Priestess,				//card
			"EX1_004",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"At the end of your turn, give another random friendly minion +1 Health. She can't wait to learn Power Word: Fortitude Rank 2.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Youthful_Brewmaster;
		Youthful_Brewmaster.fx[0] = true;			//Battlecry
		Youthful_Brewmaster.fx2[0] = "nan:";
		initCard(
			Youthful_Brewmaster,				//card
			"EX1_049",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Return a friendly minion from the battlefield to your hand. His youthful enthusiasm doesn’t always equal excellence in his brews.   Don’t drink the Mogu Stout!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ysera;
		initCard(
			Ysera,				//card
			"EX1_572",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			4,				//atk
			12,				//hp
			"At the end of your turn, add a Dream Card to your hand. Ysera rules the Emerald Dream.  Which is some kind of green-mirror-version of the real world, or something?",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Ysera_Awakens;
		Ysera_Awakens.fx[0] = true;			//Spell AKA battlecry
		Ysera_Awakens.fx2[0] = "nan:";
		initCard(
			Ysera_Awakens,				//card
			"DREAM_02",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Spell",				//type
			2,				//cost
			1,				//atk
			3,				//hp
			"Deal $5 damage to all characters except Ysera.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Becca_Abel;
		initCard(
			Becca_Abel,				//card
			"CRED_18",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"Whenever you draw a card, make it Golden.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ben_Brode;
		initCard(
			Ben_Brode,				//card
			"CRED_08",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			1,				//hp
			"Your volume can't be reduced below maximum.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ben_Thompson;
		initCard(
			Ben_Thompson,				//card
			"CRED_09",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			7,				//hp
			"<b>Battlecry:</b> Draw some cards. With a pen.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Beomki_Hong;
		initCard(
			Beomki_Hong,				//card
			"CRED_19",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			6,				//atk
			3,				//hp
			"<b>Taunt.</b> Friendly minions can’t be <b>Frozen.</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bob_Fitch;
		initCard(
			Bob_Fitch,				//card
			"CRED_03",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"<b>Super Taunt</b> <i>(EVERY character must attack this minion.)</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Brian_Birmingham;
		initCard(
			Brian_Birmingham,				//card
			"CRED_20",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Choose One</b> - Restore a Mech to full Health; or Give a Designer <b>Windfury.</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Brian_Schwab;
		initCard(
			Brian_Schwab,				//card
			"CRED_13",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			10,				//cost
			10,				//atk
			10,				//hp
			"At the end of your turn, give a random minion +1 Attack.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bryan_Chang;
		initCard(
			Bryan_Chang,				//card
			"CRED_21",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			3,				//hp
			"<b>Foodie:</b> Make all minions edible.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cameron_Chrisman;
		initCard(
			Cameron_Chrisman,				//card
			"CRED_22",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"While this is in your hand, Golden cards cost (1) less.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Christopher_Yim;
		initCard(
			Christopher_Yim,				//card
			"CRED_23",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			6,				//atk
			5,				//hp
			"<b>Battlecry:</b> Your emotes are now spoken in \"Radio Voice.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dean_Ayala;
		initCard(
			Dean_Ayala,				//card
			"CRED_24",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			5,				//hp
			"You can't lose stars while this is in your deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Derek_Sakamoto;
		initCard(
			Derek_Sakamoto,				//card
			"CRED_06",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			3,				//atk
			1,				//hp
			"<i>The notorious Footclapper.</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Elizabeth_Cho;
		initCard(
			Elizabeth_Cho,				//card
			"CRED_25",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> Add Echo of Medivh and Echoing Ooze to your hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eric_Del_Priore;
		initCard(
			Eric_Del_Priore,				//card
			"CRED_26",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			6,				//hp
			"Has <b>Taunt</b> if it's 3 AM.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eric_Dodds;
		initCard(
			Eric_Dodds,				//card
			"CRED_02",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Summon a 2/2 Pirate and destroy all Ninjas.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hamilton_Chu;
		initCard(
			Hamilton_Chu,				//card
			"CRED_16",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			9,				//atk
			5,				//hp
			"<i>Was successfully NOT part of the problem! ...most of the time.</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card He_Rim_Woo;
		initCard(
			He_Rim_Woo,				//card
			"CRED_28",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Choose One</b> - Punch an arm; Offer a treat; or Give a big hug.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Henry_Ho;
		initCard(
			Henry_Ho,				//card
			"CRED_27",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"<b>Battlecry:</b> Spectate your opponent's hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card JC_Park;
		initCard(
			JC_Park,				//card
			"CRED_30",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> Add a new platform for Hearthstone.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jason_Chayes;
		initCard(
			Jason_Chayes,				//card
			"CRED_01",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			6,				//hp
			"<b>Enrage:</b> Just kidding! He never Enrages.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jason_MacAllister;
		initCard(
			Jason_MacAllister,				//card
			"CRED_29",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			5,				//hp
			"<i>He's a real stand-up guy.</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jay_Baxter;
		initCard(
			Jay_Baxter,				//card
			"CRED_11",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			4,				//hp
			"<b>Battlecry:</b> Summon FIVE random Inventions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jeremy_Cranford;
		initCard(
			Jeremy_Cranford,				//card
			"CRED_31",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"When the game starts, this card climbs to the top of the deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jerry_Mascho;
		initCard(
			Jerry_Mascho,				//card
			"CRED_32",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"At the start of your turn, deal 1 damage. If this card is golden, deal 1 damage at the end of your turn instead. THIS IS A HAN SOLO JOKE.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jomaro_Kindred;
		initCard(
			Jomaro_Kindred,				//card
			"CRED_33",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			6,				//hp
			"<b>Battlecry:</b> TAKE any cards from your opponent's hand that they don't want.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jon_Bankard;
		initCard(
			Jon_Bankard,				//card
			"CRED_43",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"50% chance to be 100% right.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Jonas_Laster;
		initCard(
			Jonas_Laster,				//card
			"CRED_45",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"Whenever a <b>Silenced</b> minion dies, gain +1/+1.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Keith_Landes;
		initCard(
			Keith_Landes,				//card
			"CRED_46",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			6,				//hp
			"At the start of your turn, get -2 Health due to hunger.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kyle_Harrison;
		initCard(
			Kyle_Harrison,				//card
			"CRED_05",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			5,				//atk
			4,				//hp
			"<i>3 for a 5/4? That's a good deal!</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Max_Ma;
		initCard(
			Max_Ma,				//card
			"CRED_34",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			6,				//atk
			3,				//hp
			"Can only be played on a mobile device.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Max_McCall;
		initCard(
			Max_McCall,				//card
			"CRED_35",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			9,				//atk
			2,				//hp
			"Your emotes have no cooldown and can't be squelched.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Michael_Schweitzer;
		initCard(
			Michael_Schweitzer,				//card
			"CRED_10",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>C-C-C-COMBO:</b> Destroy a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mike_Donais;
		initCard(
			Mike_Donais,				//card
			"CRED_36",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			8,				//hp
			"<b>Battlecry:</b> Replace all minions in the battlefield, in both hands, and in both decks with random minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rachelle_Davis;
		initCard(
			Rachelle_Davis,				//card
			"CRED_12",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Draw TWO cards. <i>She's not a novice engineer.</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ricardo_Robaina;
		initCard(
			Ricardo_Robaina,				//card
			"CRED_37",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			4,				//hp
			"<b>Battlecry:</b> Summon three 1/1 Chinchillas.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rob_Pardo;
		initCard(
			Rob_Pardo,				//card
			"CRED_17",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			9,				//atk
			9,				//hp
			"You can't start a game without this minion in your deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Robin_Fredericksen;
		initCard(
			Robin_Fredericksen,				//card
			"CRED_38",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you have no other Erics on the battlefield, rename this card to \"Eric\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ryan_Chew;
		initCard(
			Ryan_Chew,				//card
			"CRED_39",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Chews One</b> - Sing karaoke; or Leave on time and tell everyone about it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ryan_Masterson;
		initCard(
			Ryan_Masterson,				//card
			"CRED_40",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			7,				//atk
			2,				//hp
			"<b>Battlecry:</b> Cast copies of Backstab, Cold Blood, and Eviscerate. <i>(targets chosen randomly).</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Seyil_Yoon;
		initCard(
			Seyil_Yoon,				//card
			"CRED_41",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			2,				//atk
			9,				//hp
			"<b>Battlecry:</b> Add 3 Sprints and a Marathon to your hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Steven_Gabriel;
		initCard(
			Steven_Gabriel,				//card
			"CRED_04",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Summon a frothy beverage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tim_Erskine;
		initCard(
			Tim_Erskine,				//card
			"CRED_42",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Whenever this minion destroys another minion, draw a card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Walter_Kong;
		initCard(
			Walter_Kong,				//card
			"CRED_44",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Deal 1 damage to each of 2 strategic targets.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Yong_Woo;
		initCard(
			Yong_Woo,				//card
			"CRED_14",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			2,				//hp
			"Your other minions have +3 Attack and <b>Charge</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Zwick;
		initCard(
			Zwick,				//card
			"CRED_07",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> Complain about bacon prices.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Anubar_Ambusher;
		Anubar_Ambusher.fx[2] = true;			//Deathrattle
		Anubar_Ambusher.fx2[2] = "nan:";
		initCard(
			Anubar_Ambusher,				//card
			"FP1_026",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			5,				//hp
			"<b>Deathrattle:</b> Return a random friendly minion to your hand. Originally he was called \"Anub'ar Guy who bounces a guy back to your hand\", but it lacked a certain zing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Avenge;
		Avenge.fx[8] = true;			//Secret
		Avenge.fx2[8] = "nan:";
		Avenge.fx[0] = true;			//Spell AKA battlecry
		Avenge.fx2[0] = "nan:";
		initCard(
			Avenge,				//card
			"FP1_020",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When one of your minions dies, give a random friendly minion +3/+2. Several paladins have joined together to deliver justice under the name \"Justice Force\".  Their lawyer talked them out of calling themselves the Justice League.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Baron_Rivendare;
		initCard(
			Baron_Rivendare,				//card
			"FP1_031",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			7,				//hp
			"Your minions trigger their <b>Deathrattles</b> twice. There used to be five Horsemen but one of them left because a job opened up in the deadmines and the benefits were better.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dancing_Swords;
		Dancing_Swords.fx[2] = true;			//Deathrattle
		Dancing_Swords.fx2[2] = "nan:";
		initCard(
			Dancing_Swords,				//card
			"FP1_029",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Your opponent draws a card. They like to dance to reggae.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dark_Cultist;
		Dark_Cultist.fx[2] = true;			//Deathrattle
		Dark_Cultist.fx2[2] = "nan:";
		initCard(
			Dark_Cultist,				//card
			"FP1_023",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Give a random friendly minion +3 Health. The Cult of the Damned has found it's best not to mention their name when recruiting new cultists.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deaths_Bite;
		Deaths_Bite.fx[2] = true;			//Deathrattle
		Deaths_Bite.fx2[2] = "nan:";
		initCard(
			Deaths_Bite,				//card
			"FP1_021",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			4,				//cost
			4,				//atk
			0,				//hp
			"<b>Deathrattle:</b> Deal 1 damage to all minions. \"Take a bite outta Death.\" - McScruff the Deathlord",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deathcharger;
		Deathcharger.fx[1] = true;			//Charge
		Deathcharger.fx[2] = true;			//Deathrattle
		Deathcharger.fx2[2] = "nan:";
		initCard(
			Deathcharger,				//card
			"FP1_006",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			3,				//hp
			"<b>Charge. Deathrattle:</b> Deal 3 damage to your hero.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deathlord;
		Deathlord.fx[2] = true;			//Deathrattle
		Deathlord.fx2[2] = "nan:";
		Deathlord.fx[10] = true;			//Taunt
		initCard(
			Deathlord,				//card
			"FP1_009",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			8,				//hp
			"<b>Taunt. Deathrattle:</b> Your opponent puts a minion from their deck into the battlefield. \"Rise from your grave!\" - Kel'Thuzad",
			"",				//race
			""				//hero
			);
	}
	{
		Card Duplicate;
		Duplicate.fx[8] = true;			//Secret
		Duplicate.fx2[8] = "nan:";
		Duplicate.fx[0] = true;			//Spell AKA battlecry
		Duplicate.fx2[0] = "nan:";
		initCard(
			Duplicate,				//card
			"FP1_018",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When a friendly minion dies, put 2 copies of it into your hand. The one time when duping cards won't get your account banned!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Echoing_Ooze;
		Echoing_Ooze.fx[0] = true;			//Battlecry
		Echoing_Ooze.fx2[0] = "nan:";
		initCard(
			Echoing_Ooze,				//card
			"FP1_003",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Summon an exact copy of this minion at the end of the turn. OOZE... Ooze... Ooze... (ooze...)",
			"",				//race
			""				//hero
			);
	}
	{
		Card Feugen;
		initCard(
			Feugen,				//card
			"NAX13_04H",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			7,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Feugen;
		Feugen.fx[2] = true;			//Deathrattle
		Feugen.fx2[2] = "nan:";
		initCard(
			Feugen,				//card
			"FP1_015",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			7,				//hp
			"<b>Deathrattle:</b> If Stalagg also died this game, summon Thaddius. Feugen is sad because everyone likes Stalagg better.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Guardian_of_Icecrown;
		Guardian_of_Icecrown.fx[10] = true;			//Taunt
		initCard(
			Guardian_of_Icecrown,				//card
			"NAX15_03t",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			5,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Guardian_of_Icecrown;
		Guardian_of_Icecrown.fx[10] = true;			//Taunt
		initCard(
			Guardian_of_Icecrown,				//card
			"NAX15_03n",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			3,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Haunted_Creeper;
		Haunted_Creeper.fx[2] = true;			//Deathrattle
		Haunted_Creeper.fx2[2] = "nan:";
		initCard(
			Haunted_Creeper,				//card
			"FP1_002",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"<b>Deathrattle:</b> Summon two 1/1 Spectral Spiders. Arachnofauxbia: Fear of fake spiders.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card KelThuzad;
		initCard(
			KelThuzad,				//card
			"FP1_013",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			6,				//atk
			8,				//hp
			"At the end of each turn, summon all friendly minions that died this turn. Kel'Thuzad could not resist the call of the Lich King. Even when it's just a robo-call extolling the Lich King's virtues.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Loatheb;
		Loatheb.fx[0] = true;			//Battlecry
		Loatheb.fx2[0] = "nan:";
		initCard(
			Loatheb,				//card
			"FP1_030",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Enemy spells cost (5) more next turn. Loatheb used to be a simple Bog Beast.  This is why we need stricter regulations on mining and agriculture.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Locust_Swarm;
		Locust_Swarm.fx[0] = true;			//Spell AKA battlecry
		Locust_Swarm.fx2[0] = "nan:";
		initCard(
			Locust_Swarm,				//card
			"NAX1_05",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			7,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to all enemy minions. Restore #3 Health to your hero.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mad_Scientist;
		Mad_Scientist.fx[2] = true;			//Deathrattle
		Mad_Scientist.fx2[2] = "nan:";
		initCard(
			Mad_Scientist,				//card
			"FP1_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Deathrattle:</b> Put a <b>Secret</b> from your deck into the battlefield. His mother wanted him to be a mage or a warlock, but noooooooo, he had to go and be a scientist like his father.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Maexxna;
		Maexxna.fx[7] = true;			//Poisonous
		initCard(
			Maexxna,				//card
			"FP1_010",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			2,				//atk
			8,				//hp
			"Destroy any minion damaged by this minion. Maexxna gets super mad when people introduce her as \"Maxina\" or \"Maxxy\".",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Massive_Runeblade;
		initCard(
			Massive_Runeblade,				//card
			"NAX7_04H",				//id
			"",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			10,				//atk
			0,				//hp
			"Deals double damage to heroes.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Massive_Runeblade;
		initCard(
			Massive_Runeblade,				//card
			"NAX7_04",				//id
			"",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			5,				//atk
			0,				//hp
			"Deals double damage to heroes.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mutating_Injection;
		Mutating_Injection.fx[0] = true;			//Spell AKA battlecry
		Mutating_Injection.fx2[0] = "nan:";
		initCard(
			Mutating_Injection,				//card
			"NAX11_04",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +4/+4 and <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Necrotic_Poison;
		Necrotic_Poison.fx[0] = true;			//Spell AKA battlecry
		Necrotic_Poison.fx2[0] = "nan:";
		initCard(
			Necrotic_Poison,				//card
			"NAX3_03",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubar_Weblord;
		initCard(
			Nerubar_Weblord,				//card
			"FP1_017",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			4,				//hp
			"Minions with <b>Battlecry</b> cost (2) more. Weblords spend all day making giant trampoline parks.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubian;
		initCard(
			Nerubian,				//card
			"NAX1h_03",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			4,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubian;
		initCard(
			Nerubian,				//card
			"NAX1_03",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubian;
		initCard(
			Nerubian,				//card
			"FP1_007t",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			4,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubian_Egg;
		Nerubian_Egg.fx[2] = true;			//Deathrattle
		Nerubian_Egg.fx2[2] = "nan:";
		initCard(
			Nerubian_Egg,				//card
			"FP1_007",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			2,				//hp
			"<b>Deathrattle:</b> Summon a 4/4 Nerubian. Eggs are a good source of protein and Nerubians.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Poison_Seeds;
		Poison_Seeds.fx[0] = true;			//Spell AKA battlecry
		Poison_Seeds.fx2[0] = "nan:";
		initCard(
			Poison_Seeds,				//card
			"FP1_019",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Destroy all minions and summon 2/2 Treants to replace them. \"Poisonseed Bagel\" is the least popular bagel at McTiggin's Druidic Bagel Emporium.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Reincarnate;
		Reincarnate.fx[0] = true;			//Spell AKA battlecry
		Reincarnate.fx2[0] = "nan:";
		initCard(
			Reincarnate,				//card
			"FP1_025",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion, then return it to life with full Health. It's like birth, except you're an adult and you were just dead a second ago.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shade_of_Naxxramas;
		Shade_of_Naxxramas.fx[9] = true;			//Stealth
		initCard(
			Shade_of_Naxxramas,				//card
			"FP1_005",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Stealth.</b> At the start of your turn, gain +1/+1. The Shades of Naxxramas <i>hate</i> the living. They even have a slur they use to refer them: <i>Livers</i>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Skeletal_Smith;
		Skeletal_Smith.fx[2] = true;			//Deathrattle
		Skeletal_Smith.fx2[2] = "nan:";
		initCard(
			Skeletal_Smith,				//card
			"NAXM_002",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Deathrattle:</b> Destroy your opponent's weapon.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Skeleton;
		initCard(
			Skeleton,				//card
			"NAX4_03H",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Skeleton;
		initCard(
			Skeleton,				//card
			"NAX4_03",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Slime;
		Slime.fx[10] = true;			//Taunt
		initCard(
			Slime,				//card
			"FP1_012t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sludge_Belcher;
		Sludge_Belcher.fx[2] = true;			//Deathrattle
		Sludge_Belcher.fx2[2] = "nan:";
		Sludge_Belcher.fx[10] = true;			//Taunt
		initCard(
			Sludge_Belcher,				//card
			"FP1_012",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			5,				//hp
			"<b>Taunt.\nDeathrattle:</b> Summon a 1/2 Slime with <b>Taunt</b>. DO NOT GIVE HIM A ROOT BEER.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spectral_Knight;
		initCard(
			Spectral_Knight,				//card
			"FP1_008",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			6,				//hp
			"Can't be targeted by spells or Hero Powers. What do Faerie Dragons and Spectral Knights have in common?  They both love pasta!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spectral_Spider;
		initCard(
			Spectral_Spider,				//card
			"FP1_002t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stalagg;
		initCard(
			Stalagg,				//card
			"NAX13_05H",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			4,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stalagg;
		Stalagg.fx[2] = true;			//Deathrattle
		Stalagg.fx2[2] = "nan:";
		initCard(
			Stalagg,				//card
			"FP1_014",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			4,				//hp
			"<b>Deathrattle:</b> If Feugen also died this game, summon Thaddius. Stalagg want to write own flavor text.  \"STALAGG AWESOME!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stoneskin_Gargoyle;
		initCard(
			Stoneskin_Gargoyle,				//card
			"FP1_027",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"At the start of your turn, restore this minion to full Health. Stoneskin Gargoyles love freeze tag.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Supercharge;
		Supercharge.fx[0] = true;			//Spell AKA battlecry
		Supercharge.fx2[0] = "nan:";
		initCard(
			Supercharge,				//card
			"NAX13_03",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give your minions +2 Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Thaddius;
		initCard(
			Thaddius,				//card
			"FP1_014t",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Minion",				//type
			10,				//cost
			11,				//atk
			11,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Treant;
		initCard(
			Treant,				//card
			"FP1_019t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Understudy;
		Understudy.fx[10] = true;			//Taunt
		initCard(
			Understudy,				//card
			"NAX7_02",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			7,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Undertaker;
		initCard(
			Undertaker,				//card
			"FP1_028",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"Whenever you summon a minion with <b>Deathrattle</b>, gain +1 Attack. In a world where you can run to a spirit healer and resurrect yourself, Undertakers do pretty light business.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Unstable_Ghoul;
		Unstable_Ghoul.fx[2] = true;			//Deathrattle
		Unstable_Ghoul.fx2[2] = "nan:";
		Unstable_Ghoul.fx[10] = true;			//Taunt
		initCard(
			Unstable_Ghoul,				//card
			"FP1_024",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			3,				//hp
			"<b>Taunt</b>. <b>Deathrattle:</b> Deal 1 damage to all minions. Filling your Ghouls with Rocket Fuel is all the rage at Necromancer school.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Voidcaller;
		Voidcaller.fx[2] = true;			//Deathrattle
		Voidcaller.fx2[2] = "nan:";
		initCard(
			Voidcaller,				//card
			"FP1_022",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Put a random Demon from your hand into the battlefield. \"Void!  Here, void!  Here, buddy!\"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Wailing_Soul;
		Wailing_Soul.fx[0] = true;			//Battlecry
		Wailing_Soul.fx2[0] = "nan:";
		initCard(
			Wailing_Soul,				//card
			"FP1_016",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"<b>Battlecry: Silence</b> your other minions. This soul just <i>wails</i> on you. Dang, soul, let up already.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Webspinner;
		Webspinner.fx[2] = true;			//Deathrattle
		Webspinner.fx2[2] = "nan:";
		initCard(
			Webspinner,				//card
			"FP1_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Add a random Beast card to your hand. Spider cocoons are like little piñatas!",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Zombie_Chow;
		Zombie_Chow.fx[2] = true;			//Deathrattle
		Zombie_Chow.fx2[2] = "nan:";
		initCard(
			Zombie_Chow,				//card
			"FP1_001",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			3,				//hp
			"<b>Deathrattle:</b> Restore 5 Health to the enemy hero. Zombie.  It's what's for dinner.",
			"",				//race
			""				//hero
			);
	}
	{
		Card x1000_Stats;
		x1000_Stats.fx[0] = true;			//Spell AKA battlecry
		x1000_Stats.fx2[0] = "nan:";
		initCard(
			x1000_Stats,				//card
			"XXX_055",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give a Minion +1000/+1000",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Buddy___All_Charge;
		initCard(
			AI_Buddy___All_Charge,				//card
			"XXX_095",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Spawn into play to give all minions <b>Charge</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Buddy___Blank_Slate;
		initCard(
			AI_Buddy___Blank_Slate,				//card
			"XXX_094",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Spawn into play to clear the entire board, both hands, both decks, all mana and all secrets.",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Buddy___Damage_Own_Hero_5;
		initCard(
			AI_Buddy___Damage_Own_Hero_5,				//card
			"XXX_096",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Spawn into play to smack your own hero for 5.",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Buddy___Destroy_Minions;
		initCard(
			AI_Buddy___Destroy_Minions,				//card
			"XXX_097",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Spawn into play to destroy all minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Buddy___No_Deck_Hand;
		initCard(
			AI_Buddy___No_Deck_Hand,				//card
			"XXX_098",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Spawn into play to destroy the AI's Hand and Deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card AI_Helper_Buddy;
		initCard(
			AI_Helper_Buddy,				//card
			"XXX_099",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"Get the AI ready for testing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Armor_1;
		Armor_1.fx[0] = true;			//Spell AKA battlecry
		Armor_1.fx2[0] = "nan:";
		initCard(
			Armor_1,				//card
			"XXX_061",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give target Hero +1 Armor",
			"",				//race
			""				//hero
			);
	}
	{
		Card Armor_100;
		Armor_100.fx[0] = true;			//Spell AKA battlecry
		Armor_100.fx2[0] = "nan:";
		initCard(
			Armor_100,				//card
			"XXX_053",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give target Hero +100 Armor",
			"",				//race
			""				//hero
			);
	}
	{
		Card Armor_5;
		Armor_5.fx[0] = true;			//Spell AKA battlecry
		Armor_5.fx2[0] = "nan:";
		initCard(
			Armor_5,				//card
			"XXX_062",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give target Hero +5 Armor",
			"",				//race
			""				//hero
			);
	}
	{
		Card Become_Hogger;
		Become_Hogger.fx[0] = true;			//Spell AKA battlecry
		Become_Hogger.fx2[0] = "nan:";
		initCard(
			Become_Hogger,				//card
			"XXX_039",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Become Hogger for Video Recording.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bounce;
		Bounce.fx[0] = true;			//Spell AKA battlecry
		Bounce.fx2[0] = "nan:";
		initCard(
			Bounce,				//card
			"XXX_012",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Return a minion to its owner's hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Break_Weapon;
		Break_Weapon.fx[0] = true;			//Spell AKA battlecry
		Break_Weapon.fx2[0] = "nan:";
		initCard(
			Break_Weapon,				//card
			"XXX_006",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy a hero's weapon.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Crash;
		Crash.fx[0] = true;			//Spell AKA battlecry
		Crash.fx2[0] = "nan:";
		initCard(
			Crash,				//card
			"XXX_015",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Crash the game.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damage_1;
		Damage_1.fx[0] = true;			//Spell AKA battlecry
		Damage_1.fx2[0] = "nan:";
		initCard(
			Damage_1,				//card
			"XXX_001",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal 1 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damage_5;
		Damage_5.fx[0] = true;			//Spell AKA battlecry
		Damage_5.fx2[0] = "nan:";
		initCard(
			Damage_5,				//card
			"XXX_002",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Deal 5 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damage_All;
		Damage_All.fx[0] = true;			//Spell AKA battlecry
		Damage_All.fx2[0] = "nan:";
		initCard(
			Damage_All,				//card
			"XXX_060",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Set the Health of a character to 0.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damage_Reflector;
		initCard(
			Damage_Reflector,				//card
			"XXX_024",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			3,				//atk
			10,				//hp
			"Whenever this minion takes damage, deal 1 damage to ALL other characters.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Damage_all_but_1;
		Damage_all_but_1.fx[0] = true;			//Spell AKA battlecry
		Damage_all_but_1.fx2[0] = "nan:";
		initCard(
			Damage_all_but_1,				//card
			"XXX_020",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Set the Health of a character to 1.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy;
		Destroy.fx[0] = true;			//Spell AKA battlecry
		Destroy.fx2[0] = "nan:";
		initCard(
			Destroy,				//card
			"XXX_005",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion or hero.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_ALL_Secrets;
		Destroy_ALL_Secrets.fx[0] = true;			//Spell AKA battlecry
		Destroy_ALL_Secrets.fx2[0] = "nan:";
		initCard(
			Destroy_ALL_Secrets,				//card
			"XXX_063",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy all <b>Secrets:</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_All_Heroes;
		Destroy_All_Heroes.fx[0] = true;			//Spell AKA battlecry
		Destroy_All_Heroes.fx2[0] = "nan:";
		initCard(
			Destroy_All_Heroes,				//card
			"XXX_023",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy all heroes.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_All_Minions;
		Destroy_All_Minions.fx[0] = true;			//Spell AKA battlecry
		Destroy_All_Minions.fx2[0] = "nan:";
		initCard(
			Destroy_All_Minions,				//card
			"XXX_018",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy all minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_Deck;
		Destroy_Deck.fx[0] = true;			//Spell AKA battlecry
		Destroy_Deck.fx2[0] = "nan:";
		initCard(
			Destroy_Deck,				//card
			"XXX_047",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Delete an opponent's deck",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_Hero_Power;
		Destroy_Hero_Power.fx[0] = true;			//Spell AKA battlecry
		Destroy_Hero_Power.fx2[0] = "nan:";
		initCard(
			Destroy_Hero_Power,				//card
			"XXX_041",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy a player's Hero Power.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_Heros_Stuff;
		Destroy_Heros_Stuff.fx[0] = true;			//Spell AKA battlecry
		Destroy_Heros_Stuff.fx2[0] = "nan:";
		initCard(
			Destroy_Heros_Stuff,				//card
			"XXX_059",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy target hero's hero power, weapon, deck, hand, minions, and secrets.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_Target_Secrets;
		Destroy_Target_Secrets.fx[0] = true;			//Spell AKA battlecry
		Destroy_Target_Secrets.fx2[0] = "nan:";
		initCard(
			Destroy_Target_Secrets,				//card
			"XXX_057",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Choose a hero. Destroy all <b>Secrets</b> controlled by that hero.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_a_Mana_Crystal;
		Destroy_a_Mana_Crystal.fx[0] = true;			//Spell AKA battlecry
		Destroy_a_Mana_Crystal.fx2[0] = "nan:";
		initCard(
			Destroy_a_Mana_Crystal,				//card
			"XXX_050",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Pick a player and destroy one of his Mana Crystals.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Destroy_all_Mana;
		Destroy_all_Mana.fx[0] = true;			//Spell AKA battlecry
		Destroy_all_Mana.fx2[0] = "nan:";
		initCard(
			Destroy_all_Mana,				//card
			"XXX_049",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Destroy all of a player's Mana Crystals.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Discard;
		Discard.fx[0] = true;			//Spell AKA battlecry
		Discard.fx2[0] = "nan:";
		initCard(
			Discard,				//card
			"XXX_013",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Choose a hero.  That hero's controller discards his hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Do_Nothing;
		Do_Nothing.fx[0] = true;			//Spell AKA battlecry
		Do_Nothing.fx2[0] = "nan:";
		initCard(
			Do_Nothing,				//card
			"XXX_025",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"This does nothing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Draw_3_Cards;
		Draw_3_Cards.fx[0] = true;			//Spell AKA battlecry
		Draw_3_Cards.fx2[0] = "nan:";
		initCard(
			Draw_3_Cards,				//card
			"XXX_017",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Draw 3 cards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Enable_Emotes;
		Enable_Emotes.fx[0] = true;			//Spell AKA battlecry
		Enable_Emotes.fx2[0] = "nan:";
		initCard(
			Enable_Emotes,				//card
			"XXX_026",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Enable emotes for your VS.AI game. (not in tutorials, though)",
			"",				//race
			""				//hero
			);
	}
	{
		Card Enable_for_Attack;
		Enable_for_Attack.fx[0] = true;			//Spell AKA battlecry
		Enable_for_Attack.fx2[0] = "nan:";
		initCard(
			Enable_for_Attack,				//card
			"XXX_007",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give a character Charge and make him able to attack!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Enchant;
		Enchant.fx[0] = true;			//Spell AKA battlecry
		Enchant.fx2[0] = "nan:";
		initCard(
			Enchant,				//card
			"XXX_009",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Enchant a minion with an empty enchant.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Force_AI_to_Use_Hero_Power;
		Force_AI_to_Use_Hero_Power.fx[0] = true;			//Spell AKA battlecry
		Force_AI_to_Use_Hero_Power.fx2[0] = "nan:";
		initCard(
			Force_AI_to_Use_Hero_Power,				//card
			"XXX_046",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Force the AI to use their Hero Power every turn from now on.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Free_Cards;
		Free_Cards.fx[0] = true;			//Spell AKA battlecry
		Free_Cards.fx2[0] = "nan:";
		initCard(
			Free_Cards,				//card
			"XXX_022",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Your cards cost (0) for the rest of the game.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Freeze;
		Freeze.fx[5] = true;			//Freeze
		Freeze.fx[0] = true;			//Spell AKA battlecry
		Freeze.fx2[0] = "nan:";
		initCard(
			Freeze,				//card
			"XXX_008",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"<b>Freeze</b> a character.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grant_Mega_Windfury;
		Grant_Mega_Windfury.fx[0] = true;			//Spell AKA battlecry
		Grant_Mega_Windfury.fx2[0] = "nan:";
		initCard(
			Grant_Mega_Windfury,				//card
			"XXX_052",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give a minion <b>Mega-Windfury</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hand_Swapper_Minion;
		initCard(
			Hand_Swapper_Minion,				//card
			"XXX_044",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Discard 3 cards, then draw 3 cards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hand_to_Deck;
		Hand_to_Deck.fx[0] = true;			//Spell AKA battlecry
		Hand_to_Deck.fx2[0] = "nan:";
		initCard(
			Hand_to_Deck,				//card
			"XXX_042",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Shuffle a player's hand into his deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Make_Immune;
		Make_Immune.fx[0] = true;			//Spell AKA battlecry
		Make_Immune.fx2[0] = "nan:";
		initCard(
			Make_Immune,				//card
			"XXX_051",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Permanently make a character <b>Immune</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mill_10;
		Mill_10.fx[0] = true;			//Spell AKA battlecry
		Mill_10.fx2[0] = "nan:";
		initCard(
			Mill_10,				//card
			"XXX_014",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Put 10 cards from a hero's deck into his graveyard.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mill_30;
		Mill_30.fx[0] = true;			//Spell AKA battlecry
		Mill_30.fx2[0] = "nan:";
		initCard(
			Mill_30,				//card
			"XXX_043",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Put 30 cards from a hero's deck into his graveyard.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Molasses;
		Molasses.fx[0] = true;			//Spell AKA battlecry
		Molasses.fx2[0] = "nan:";
		initCard(
			Molasses,				//card
			"XXX_019",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"You can take as long as you want on your turn.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Opponent_Concede;
		Opponent_Concede.fx[0] = true;			//Spell AKA battlecry
		Opponent_Concede.fx2[0] = "nan:";
		initCard(
			Opponent_Concede,				//card
			"XXX_029",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Force your opponent to concede.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Opponent_Disconnect;
		Opponent_Disconnect.fx[0] = true;			//Spell AKA battlecry
		Opponent_Disconnect.fx2[0] = "nan:";
		initCard(
			Opponent_Disconnect,				//card
			"XXX_030",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Force your opponnet to disconnect.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Restore_1;
		Restore_1.fx[0] = true;			//Spell AKA battlecry
		Restore_1.fx2[0] = "nan:";
		initCard(
			Restore_1,				//card
			"XXX_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore 1 Health to a character.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Restore_5;
		Restore_5.fx[0] = true;			//Spell AKA battlecry
		Restore_5.fx2[0] = "nan:";
		initCard(
			Restore_5,				//card
			"XXX_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore 5 Health to a character.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Restore_All_Health;
		Restore_All_Health.fx[0] = true;			//Spell AKA battlecry
		Restore_All_Health.fx2[0] = "nan:";
		initCard(
			Restore_All_Health,				//card
			"XXX_021",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Restore all Health to a character.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Reveal_Hand;
		Reveal_Hand.fx[0] = true;			//Spell AKA battlecry
		Reveal_Hand.fx2[0] = "nan:";
		initCard(
			Reveal_Hand,				//card
			"XXX_028",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Server_Crash;
		Server_Crash.fx[0] = true;			//Spell AKA battlecry
		Server_Crash.fx2[0] = "nan:";
		initCard(
			Server_Crash,				//card
			"XXX_027",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Crash the Server.  DON'T BE A FOOL.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silence___debug;
		Silence___debug.fx[0] = true;			//Spell AKA battlecry
		Silence___debug.fx2[0] = "nan:";
		initCard(
			Silence___debug,				//card
			"XXX_010",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Remove all enchantments and powers from a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silence_Destroy;
		Silence_Destroy.fx[0] = true;			//Spell AKA battlecry
		Silence_Destroy.fx2[0] = "nan:";
		initCard(
			Silence_Destroy,				//card
			"XXX_056",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Silence and Destroy ALL Minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Snake_Ball;
		Snake_Ball.fx[0] = true;			//Spell AKA battlecry
		Snake_Ball.fx2[0] = "nan:";
		initCard(
			Snake_Ball,				//card
			"XXX_016",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Summon five 1/1 snakes.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Steal_Card;
		Steal_Card.fx[0] = true;			//Spell AKA battlecry
		Steal_Card.fx2[0] = "nan:";
		initCard(
			Steal_Card,				//card
			"XXX_045",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Steal a random card from your opponent.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Summon_a_random_Secret;
		Summon_a_random_Secret.fx[0] = true;			//Spell AKA battlecry
		Summon_a_random_Secret.fx2[0] = "nan:";
		initCard(
			Summon_a_random_Secret,				//card
			"XXX_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Summon a secret from your deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Weapon_Buff;
		Weapon_Buff.fx[0] = true;			//Spell AKA battlecry
		Weapon_Buff.fx2[0] = "nan:";
		initCard(
			Weapon_Buff,				//card
			"XXX_054",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give your Weapon +100/+100",
			"",				//race
			""				//hero
			);
	}
	{
		Card Weapon_Nerf;
		Weapon_Nerf.fx[0] = true;			//Spell AKA battlecry
		Weapon_Nerf.fx2[0] = "nan:";
		initCard(
			Weapon_Nerf,				//card
			"XXX_058",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give a weapon a negative enchantment.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Anima_Golem;
		initCard(
			Anima_Golem,				//card
			"GVG_077",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			9,				//atk
			9,				//hp
			"At the end of each turn, destroy this minion if it's your only one. The Dark Animus is evil and mysterious and huge and unable to write sentences that utilize proper grammar.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Annoy_o_Tron;
		Annoy_o_Tron.fx[3] = true;			//Divine Shield
		Annoy_o_Tron.fx[10] = true;			//Taunt
		initCard(
			Annoy_o_Tron,				//card
			"GVG_085",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"<b>Taunt</b>\n<b>Divine Shield</b> The inventor of the Annoy-o-Tron was immediately expelled from Tinkerschool, Tinkertown, and was eventually exiled from the Eastern Kingdoms altogether.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Anodized_Robo_Cub;
		Anodized_Robo_Cub.fx[10] = true;			//Taunt
		initCard(
			Anodized_Robo_Cub,				//card
			"GVG_030",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Taunt</b>. <b>Choose One -</b>\n+1 Attack; or +1 Health. It's adorable! AND OH MY GOODNESS WHY IS IT EATING MY FACE",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Antique_Healbot;
		Antique_Healbot.fx[0] = true;			//Battlecry
		Antique_Healbot.fx2[0] = "nan:";
		initCard(
			Antique_Healbot,				//card
			"GVG_069",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Restore 8 Health to your hero. They don't make 'em like they used to! (Because of explosions, mostly.)",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Nullifier_X_21;
		Arcane_Nullifier_X_21.fx[10] = true;			//Taunt
		initCard(
			Arcane_Nullifier_X_21,				//card
			"GVG_091",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"<b>Taunt</b>\nCan't be targeted by spells or Hero Powers. There was some hard talk between gnome magi and engineers about inventing this mech.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Armor_Plating;
		Armor_Plating.fx[0] = true;			//Spell AKA battlecry
		Armor_Plating.fx2[0] = "nan:";
		initCard(
			Armor_Plating,				//card
			"PART_001",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +1 Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Attack_Mode;
		Attack_Mode.fx[0] = true;			//Spell AKA battlecry
		Attack_Mode.fx2[0] = "nan:";
		initCard(
			Attack_Mode,				//card
			"GVG_030a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+1 Attack.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Blingtron_3000;
		Blingtron_3000.fx[0] = true;			//Battlecry
		Blingtron_3000.fx2[0] = "nan:";
		initCard(
			Blingtron_3000,				//card
			"GVG_119",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			4,				//hp
			"<b>Battlecry:</b> Equip a random weapon for each player. PREPARE PARTY SERVOS FOR IMMEDIATE DEPLOYMENT.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Bolvar_Fordragon;
		initCard(
			Bolvar_Fordragon,				//card
			"GVG_063",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			1,				//atk
			7,				//hp
			"Whenever a friendly minion dies while this is in your hand, gain +1 Attack. Spoiler alert: Bolvar gets melted and then sits on an ice throne and everyone forgets about him.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bomb_Lobber;
		Bomb_Lobber.fx[0] = true;			//Battlecry
		Bomb_Lobber.fx2[0] = "nan:";
		initCard(
			Bomb_Lobber,				//card
			"GVG_099",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> Deal 4 damage to a random enemy minion. He lobbies Orgrimmar daily on behalf of bombs.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Boom_Bot;
		Boom_Bot.fx[2] = true;			//Deathrattle
		Boom_Bot.fx2[2] = "nan:";
		initCard(
			Boom_Bot,				//card
			"GVG_110t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"<b>Deathrattle</b>: Deal 1-4 damage to a random enemy.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Bouncing_Blade;
		Bouncing_Blade.fx[0] = true;			//Spell AKA battlecry
		Bouncing_Blade.fx2[0] = "nan:";
		initCard(
			Bouncing_Blade,				//card
			"GVG_050",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage to a random minion. Repeat until a minion dies. Only goblins would think this was a good idea. Even they are starting to have their doubts.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Burly_Rockjaw_Trogg;
		initCard(
			Burly_Rockjaw_Trogg,				//card
			"GVG_068",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Whenever your opponent casts a spell, gain +2 Attack. He's burly because he does CrossFit.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Burrowing_Mine;
		Burrowing_Mine.fx[0] = true;			//Spell AKA battlecry
		Burrowing_Mine.fx2[0] = "nan:";
		initCard(
			Burrowing_Mine,				//card
			"GVG_056t",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"When you draw this, it explodes. You take 10 damage and draw a card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Call_Pet;
		Call_Pet.fx[0] = true;			//Spell AKA battlecry
		Call_Pet.fx2[0] = "nan:";
		initCard(
			Call_Pet,				//card
			"GVG_017",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Draw a card.\nIf it's a Beast, it costs (4) less. Real hunters tame hungry crabs.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Chicken;
		initCard(
			Chicken,				//card
			"GVG_092t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Clockwork_Giant;
		initCard(
			Clockwork_Giant,				//card
			"GVG_121",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			12,				//cost
			8,				//atk
			8,				//hp
			"Costs (1) less for each card in your opponent's hand. He and Mountain Giant don't get along.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Clockwork_Gnome;
		Clockwork_Gnome.fx[2] = true;			//Deathrattle
		Clockwork_Gnome.fx2[2] = "nan:";
		initCard(
			Clockwork_Gnome,				//card
			"GVG_082",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Add a <b>Spare Part</b> card to your hand. Clockwork gnomes are always asking what time it is.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Cobalt_Guardian;
		initCard(
			Cobalt_Guardian,				//card
			"GVG_062",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			3,				//hp
			"Whenever you summon a Mech, gain <b>Divine Shield</b>. Guardians used to be built out of Adamantium, but production got moved to Gadgetzan and Cobalt was cheap.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Cobra_Shot;
		Cobra_Shot.fx[0] = true;			//Spell AKA battlecry
		Cobra_Shot.fx2[0] = "nan:";
		initCard(
			Cobra_Shot,				//card
			"GVG_073",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage to a minion and the enemy hero. \"Cobra Shot\" hurts way, way, way more than \"Cobra Cuddle.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Coghammer;
		Coghammer.fx[0] = true;			//Battlecry
		Coghammer.fx2[0] = "nan:";
		initCard(
			Coghammer,				//card
			"GVG_059",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			2,				//atk
			0,				//hp
			"<b>Battlecry:</b> Give a random friendly minion <b>Divine Shield</b> and <b>Taunt</b>. So you ripped this out of a machine, carved some runes on it, stuck it on a handle, and now it's a weapon of great divine power? Seems legit.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cogmaster;
		initCard(
			Cogmaster,				//card
			"GVG_013",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"Has +2 Attack while you have a Mech. After a while, you don't see the cogs and sprockets. All you see is a robot, a spider tank, a deathray...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cogmasters_Wrench;
		initCard(
			Cogmasters_Wrench,				//card
			"GVG_024",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			1,				//atk
			0,				//hp
			"Has +2 Attack while you have a Mech. For tightening cogs and smashin' troggs!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Crackle;
		Crackle.fx[0] = true;			//Spell AKA battlecry
		Crackle.fx2[0] = "nan:";
		initCard(
			Crackle,				//card
			"GVG_038",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $3-$6 damage. <b>Overload:</b> (1) Snap! This card! Pop!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Crush;
		Crush.fx[0] = true;			//Spell AKA battlecry
		Crush.fx2[0] = "nan:";
		initCard(
			Crush,				//card
			"GVG_052",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			7,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion. If you have a damaged minion, this costs (4) less. Using this card on your enemies is one of the best things in life, according to some barbarians.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dark_Wispers;
		Dark_Wispers.fx[0] = true;			//Spell AKA battlecry
		Dark_Wispers.fx2[0] = "nan:";
		initCard(
			Dark_Wispers,				//card
			"GVG_041",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One -</b> Summon 5 Wisps; or Give a minion +5/+5 and <b>Taunt</b>. Don't worry; we fired the person who named this card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Darkbomb;
		Darkbomb.fx[0] = true;			//Spell AKA battlecry
		Darkbomb.fx2[0] = "nan:";
		initCard(
			Darkbomb,				//card
			"GVG_015",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage. If you're looking to make an \"Emo\" deck, this card is perfect!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Demonheart;
		Demonheart.fx[0] = true;			//Spell AKA battlecry
		Demonheart.fx2[0] = "nan:";
		initCard(
			Demonheart,				//card
			"GVG_019",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $5 damage to a minion.  If it's a friendly Demon, give it +5/+5 instead. Virtually every member of the pro demon lobby is a warlock. Weird.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dr_Boom;
		Dr_Boom.fx[0] = true;			//Battlecry
		Dr_Boom.fx2[0] = "nan:";
		initCard(
			Dr_Boom,				//card
			"GVG_110",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			7,				//hp
			"<b>Battlecry</b>: Summon two 1/1 Boom Bots. <i>WARNING: Bots may explode.</i> MARVEL AT HIS MIGHT!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Fang;
		initCard(
			Druid_of_the_Fang,				//card
			"GVG_080t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			7,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Fang;
		Druid_of_the_Fang.fx[0] = true;			//Battlecry
		Druid_of_the_Fang.fx2[0] = "nan:";
		initCard(
			Druid_of_the_Fang,				//card
			"GVG_080",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you have a Beast, transform this minion into a 7/7. The Druids of the Fang live in the Wailing Caverns. They wear cool snake shirts and tell snake jokes and say \"bro\" a lot.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dunemaul_Shaman;
		Dunemaul_Shaman.fx[6] = true;			//Overload
		Dunemaul_Shaman.fx2[6] = "nan:";
		Dunemaul_Shaman.fx[11] = true;			//Windfury
		initCard(
			Dunemaul_Shaman,				//card
			"GVG_066",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Windfury, Overload: (1)</b>\n50% chance to attack the wrong enemy. He just closes his eyes and goes for it. Raarararrrarar!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Echo_of_Medivh;
		Echo_of_Medivh.fx[0] = true;			//Spell AKA battlecry
		Echo_of_Medivh.fx2[0] = "nan:";
		initCard(
			Echo_of_Medivh,				//card
			"GVG_005",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Put a copy of each friendly minion into your hand. Medivh's echo haunts Karazhan, eternally cheating at chess and <i>Hearthstone</i>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Emergency_Coolant;
		Emergency_Coolant.fx[5] = true;			//Freeze
		Emergency_Coolant.fx[0] = true;			//Spell AKA battlecry
		Emergency_Coolant.fx2[0] = "nan:";
		initCard(
			Emergency_Coolant,				//card
			"PART_005",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Freeze</b> a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Enhance_o_Mechano;
		Enhance_o_Mechano.fx[0] = true;			//Battlecry
		Enhance_o_Mechano.fx2[0] = "nan:";
		initCard(
			Enhance_o_Mechano,				//card
			"GVG_107",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give your other minions <b>Windfury</b>, <b>Taunt</b>, or <b>Divine Shield</b>.\n<i>(at random)</i> His enhancements are gluten free!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Explosive_Sheep;
		Explosive_Sheep.fx[2] = true;			//Deathrattle
		Explosive_Sheep.fx2[2] = "nan:";
		initCard(
			Explosive_Sheep,				//card
			"GVG_076",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Deal 2 damage to all minions. How is this supposed to work?  Your enemies think, \"<i>Hey!</i> Cute sheep!\" and run over to cuddle it?",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Feign_Death;
		Feign_Death.fx[0] = true;			//Spell AKA battlecry
		Feign_Death.fx2[0] = "nan:";
		initCard(
			Feign_Death,				//card
			"GVG_026",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Trigger all <b>Deathrattles</b> on your minions. The hardest part about doing a \"Feign Death\" convincingly is learning how to make the right smell. It takes a lot of commitment.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fel_Cannon;
		initCard(
			Fel_Cannon,				//card
			"GVG_020",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"At the end of your turn, deal 2 damage to a non-Mech minion. The box says, \"New and improved, with 200% more fel!\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Fel_Reaver;
		initCard(
			Fel_Reaver,				//card
			"GVG_016",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			8,				//atk
			8,				//hp
			"Whenever your opponent plays a card, remove the top 3 cards of your deck. So reaver. Much fel. Wow.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Finicky_Cloakfield;
		Finicky_Cloakfield.fx[0] = true;			//Spell AKA battlecry
		Finicky_Cloakfield.fx2[0] = "nan:";
		initCard(
			Finicky_Cloakfield,				//card
			"PART_004",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a friendly minion <b>Stealth</b> until your next turn.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flame_Leviathan;
		initCard(
			Flame_Leviathan,				//card
			"GVG_007",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			7,				//hp
			"When you draw this, deal 2 damage to all characters. Mimiron likes to take the Flame Leviathan out on some sweet joyrides.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Flamecannon;
		Flamecannon.fx[0] = true;			//Spell AKA battlecry
		Flamecannon.fx2[0] = "nan:";
		initCard(
			Flamecannon,				//card
			"GVG_001",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage to a random enemy minion. Calling something a flamecannon really doesn't do much to distinguish it from other goblin devices.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Floating_Watcher;
		initCard(
			Floating_Watcher,				//card
			"GVG_100",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"Whenever your hero takes damage on your turn, gain +2/+2. \"Evil Eye Watcher of Doom\" was the original name, but marketing felt it was a bit too aggressive.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Flying_Machine;
		Flying_Machine.fx[11] = true;			//Windfury
		initCard(
			Flying_Machine,				//card
			"GVG_084",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"<b>Windfury</b> To operate, this contraption needs a hula doll on the dashboard. Otherwise it's just a “falling machine.”",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Foe_Reaper_4000;
		initCard(
			Foe_Reaper_4000,				//card
			"GVG_113",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			6,				//atk
			9,				//hp
			"Also damages the minions next to whomever he attacks. Foe reaping is really not so different from harvest reaping, at the end of the day.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Force_Tank_MAX;
		Force_Tank_MAX.fx[3] = true;			//Divine Shield
		initCard(
			Force_Tank_MAX,				//card
			"GVG_079",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			7,				//atk
			7,				//hp
			"<b>Divine Shield</b> There is a factory in Tanaris for crafting force-tanks, but it only ever made two, because of cost overruns.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Gahzrilla;
		initCard(
			Gahzrilla,				//card
			"GVG_049",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			9,				//hp
			"Whenever this minion takes damage, double its Attack. The Sen'jin High football team is The Gahz'rillas.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Gallywixs_Coin;
		Gallywixs_Coin.fx[0] = true;			//Spell AKA battlecry
		Gallywixs_Coin.fx2[0] = "nan:";
		initCard(
			Gallywixs_Coin,				//card
			"GVG_028t",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Gain 1 Mana Crystal this turn only.\n<i>(Won't trigger Gallywix.)</i>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gazlowe;
		initCard(
			Gazlowe,				//card
			"GVG_117",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			3,				//atk
			6,				//hp
			"Whenever you cast a 1-mana spell, add a random Mech to your hand. Gazlowe was voted \"Most Likely to Explode\" in high school.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gift_of_Cards;
		Gift_of_Cards.fx[0] = true;			//Spell AKA battlecry
		Gift_of_Cards.fx2[0] = "nan:";
		initCard(
			Gift_of_Cards,				//card
			"GVG_032b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Each player draws a card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gift_of_Mana;
		Gift_of_Mana.fx[0] = true;			//Spell AKA battlecry
		Gift_of_Mana.fx2[0] = "nan:";
		initCard(
			Gift_of_Mana,				//card
			"GVG_032a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Give each player a Mana Crystal.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gilblin_Stalker;
		Gilblin_Stalker.fx[9] = true;			//Stealth
		initCard(
			Gilblin_Stalker,				//card
			"GVG_081",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Stealth</b> \"Shhh, I think I hear something.\"\n\n\"Ah, it's probably nothing.\" - Every Henchman",
			"",				//race
			""				//hero
			);
	}
	{
		Card Glaivezooka;
		Glaivezooka.fx[0] = true;			//Battlecry
		Glaivezooka.fx2[0] = "nan:";
		initCard(
			Glaivezooka,				//card
			"GVG_043",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			2,				//atk
			0,				//hp
			"<b>Battlecry:</b> Give a random friendly minion +1 Attack. For the times when a regular bazooka just isn't enough.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gnomeregan_Infantry;
		Gnomeregan_Infantry.fx[1] = true;			//Charge
		Gnomeregan_Infantry.fx[10] = true;			//Taunt
		initCard(
			Gnomeregan_Infantry,				//card
			"GVG_098",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			1,				//atk
			4,				//hp
			"<b>Charge</b>\n<b>Taunt</b> The gnomes are valiant and ready to return to their irradiated, poorly ventilated homeland!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gnomish_Experimenter;
		Gnomish_Experimenter.fx[0] = true;			//Battlecry
		Gnomish_Experimenter.fx2[0] = "nan:";
		initCard(
			Gnomish_Experimenter,				//card
			"GVG_092",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Draw a card. If it's a minion, transform it into a Chicken. He's legitimately surprised every time he turns himself into a chicken.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Goblin_Auto_Barber;
		Goblin_Auto_Barber.fx[0] = true;			//Battlecry
		Goblin_Auto_Barber.fx2[0] = "nan:";
		initCard(
			Goblin_Auto_Barber,				//card
			"GVG_023",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry</b>: Give your weapon +1 Attack. This guy is excellent at adjusting your haircut and/or height.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Goblin_Blastmage;
		Goblin_Blastmage.fx[0] = true;			//Battlecry
		Goblin_Blastmage.fx2[0] = "nan:";
		initCard(
			Goblin_Blastmage,				//card
			"GVG_004",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you have a Mech, deal 4 damage randomly split among all enemies. If you can't find a bomb to throw, just pick up any goblin invention and throw that.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Goblin_Sapper;
		initCard(
			Goblin_Sapper,				//card
			"GVG_095",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Has +4 Attack while your opponent has 6 or more cards in hand. He’s not such a binge exploder anymore. These days, he only explodes socially.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grove_Tender;
		initCard(
			Grove_Tender,				//card
			"GVG_032",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"<b>Choose One -</b> Give each player a Mana Crystal; or Each player draws a card. Likes: Hiking and the great outdoors. Dislikes: Goblin shredders and sandals. (Can’t find any that fit!).",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hemet_Nesingwary;
		Hemet_Nesingwary.fx[0] = true;			//Battlecry
		Hemet_Nesingwary.fx2[0] = "nan:";
		initCard(
			Hemet_Nesingwary,				//card
			"GVG_120",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			3,				//hp
			"<b>Battlecry:</b> Destroy a Beast. It's hard to make a living as a hunter in a world where beasts instantly reappear minutes after you kill them.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Hobgoblin;
		initCard(
			Hobgoblin,				//card
			"GVG_104",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"Whenever you play a 1-Attack minion, give it +2/+2. Hobgoblins are meeting next week to discuss union benefits.  First on the list: dental plan.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Illuminator;
		initCard(
			Illuminator,				//card
			"GVG_089",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"If you control a <b>Secret</b> at the end of your turn, restore 4 health to your hero. \"LUMOS!\" is not what they yell. What do you think this is, Hogwarts?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Imp;
		initCard(
			Imp,				//card
			"GVG_045t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Imp_losion;
		Imp_losion.fx[0] = true;			//Spell AKA battlecry
		Imp_losion.fx2[0] = "nan:";
		initCard(
			Imp_losion,				//card
			"GVG_045",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $2-$4 damage to a minion. Summon a 1/1 Imp for each damage dealt. The shrapnel is waaaaay worse than the explosion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Iron_Juggernaut;
		Iron_Juggernaut.fx[0] = true;			//Battlecry
		Iron_Juggernaut.fx2[0] = "nan:";
		initCard(
			Iron_Juggernaut,				//card
			"GVG_056",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			5,				//hp
			"<b>Battlecry:</b> Shuffle a Mine into your opponent's deck. When drawn, it explodes for 10 damage. The Iron Juggernaut guards Orgrimmar and has just earned the \"Employee of the Month\" award!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Iron_Sensei;
		initCard(
			Iron_Sensei,				//card
			"GVG_027",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"At the end of your turn, give another friendly Mech +2/+2. Mechs like learning from him because he really speaks their language.\n\n0110100001101001",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Jeeves;
		initCard(
			Jeeves,				//card
			"GVG_094",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			4,				//hp
			"At the end of each player's turn, that player draws until they have 3 cards. This robot is a lean, mean, butlerin' machine.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Junkbot;
		initCard(
			Junkbot,				//card
			"GVG_106",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			1,				//atk
			5,				//hp
			"Whenever a friendly Mech dies, gain +2/+2. One bot's junk is another bot's AWESOME UPGRADE!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Kezan_Mystic;
		Kezan_Mystic.fx[0] = true;			//Battlecry
		Kezan_Mystic.fx2[0] = "nan:";
		initCard(
			Kezan_Mystic,				//card
			"GVG_074",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> Take control of a random enemy <b>Secret</b>. They pretend to be wise and enlightened, but they mostly just hate to be left out of a secret.",
			"",				//race
			""				//hero
			);
	}
	{
		Card King_of_Beasts;
		King_of_Beasts.fx[0] = true;			//Battlecry
		King_of_Beasts.fx2[0] = "nan:";
		King_of_Beasts.fx[10] = true;			//Taunt
		initCard(
			King_of_Beasts,				//card
			"GVG_046",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			2,				//atk
			6,				//hp
			"<b>Taunt</b>. <b>Battlecry:</b> Gain +1 Attack for each other Beast you have. He never sleeps.  Not even in the mighty jungle.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Light_of_the_Naaru;
		Light_of_the_Naaru.fx[0] = true;			//Spell AKA battlecry
		Light_of_the_Naaru.fx2[0] = "nan:";
		initCard(
			Light_of_the_Naaru,				//card
			"GVG_012",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Restore #3 Health. If the target is still damaged, summon a Lightwarden. \"Light it up!\" - Command given to both Lightwardens and Goblins holding Flamecannons.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lightbomb;
		Lightbomb.fx[0] = true;			//Spell AKA battlecry
		Lightbomb.fx2[0] = "nan:";
		initCard(
			Lightbomb,				//card
			"GVG_008",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Deal damage to each minion equal to its Attack. This is what happens when you allow goblins to be priests.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lil_Exorcist;
		Lil_Exorcist.fx[0] = true;			//Battlecry
		Lil_Exorcist.fx2[0] = "nan:";
		Lil_Exorcist.fx[10] = true;			//Taunt
		initCard(
			Lil_Exorcist,				//card
			"GVG_097",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			3,				//hp
			"<b>Taunt</b>\n<b>Battlecry:</b> Gain +1/+1 for each enemy <b>Deathrattle</b> minion. Warlocks have the town exorcist on speed dial in case they unleash the wrong demon.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lost_Tallstrider;
		initCard(
			Lost_Tallstrider,				//card
			"GVG_071",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"The message, \"If found, please return to Mulgore,\" is tattooed on his rear.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Madder_Bomber;
		Madder_Bomber.fx[0] = true;			//Battlecry
		Madder_Bomber.fx2[0] = "nan:";
		initCard(
			Madder_Bomber,				//card
			"GVG_090",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Battlecry:</b> Deal 6 damage randomly split between all other characters. Dang, Bomber, calm down.",
			"",				//race
			""				//hero
			);
	}
	{
		Card MalGanis;
		initCard(
			MalGanis,				//card
			"GVG_021",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			9,				//atk
			7,				//hp
			"Your other Demons have +2/+2.\nYour hero is <b>Immune</b>. Mal'Ganis doesn't like being betrayed, so if you discard him, watch out.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Malorne;
		Malorne.fx[2] = true;			//Deathrattle
		Malorne.fx2[2] = "nan:";
		initCard(
			Malorne,				//card
			"GVG_035",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			9,				//atk
			7,				//hp
			"<b>Deathrattle:</b> Shuffle this minion into your deck. When Malorne isn't mauling hordes of demons, he enjoys attending parties, though he prefers to go stag.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Mech_Bear_Cat;
		initCard(
			Mech_Bear_Cat,				//card
			"GVG_034",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			6,				//hp
			"Whenever this minion takes damage, add a <b>Spare Part</b> card to your hand. Crushes buildings with his BEAR hands.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mechanical_Yeti;
		Mechanical_Yeti.fx[2] = true;			//Deathrattle
		Mechanical_Yeti.fx2[2] = "nan:";
		initCard(
			Mechanical_Yeti,				//card
			"GVG_078",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			5,				//hp
			"<b>Deathrattle:</b> Give each player a <b>Spare Part.</b> The yetis of Chillwind Point are a source of both inspiration and savage beatings.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mechwarper;
		initCard(
			Mechwarper,				//card
			"GVG_006",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Your Mechs cost (1) less. Mechs that summon mechs? What's next? Donuts that summon donuts? Mmmmm.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mekgineer_Thermaplugg;
		initCard(
			Mekgineer_Thermaplugg,				//card
			"GVG_116",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			9,				//atk
			7,				//hp
			"Whenever an enemy minion dies, summon a Leper Gnome. He was obsessed with explosives until he discovered knitting. Now he yells, “SWEATERS! MORE SWEATERS!”",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Metaltooth_Leaper;
		Metaltooth_Leaper.fx[0] = true;			//Battlecry
		Metaltooth_Leaper.fx2[0] = "nan:";
		initCard(
			Metaltooth_Leaper,				//card
			"GVG_048",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry</b>: Give your other Mechs +2 Attack. Don't leave them out in the rain. In Un'Goro Crater there is a whole colony of rust-tooth leapers.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Micro_Machine;
		initCard(
			Micro_Machine,				//card
			"GVG_103",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"At the start of each turn, gain +1 Attack. This card is the real thing.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mimirons_Head;
		initCard(
			Mimirons_Head,				//card
			"GVG_111",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			5,				//hp
			"At the start of your turn, if you have at least 3 Mechs, destroy them all and form V-07-TR-0N. Do not push the big red button!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Mini_Mage;
		Mini_Mage.fx[9] = true;			//Stealth
		initCard(
			Mini_Mage,				//card
			"GVG_109",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			1,				//hp
			"<b>Stealth</b>\n<b>Spell Damage +1</b> He is sometimes found hiding in the treasure chest in the Gurubashi Arena.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mistress_of_Pain;
		initCard(
			Mistress_of_Pain,				//card
			"GVG_018",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			4,				//hp
			"Whenever this minion deals damage, restore that much Health to your hero. Her sister is the Mistress of Pane who sells windows and shower doors.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Mogor_the_Ogre;
		initCard(
			Mogor_the_Ogre,				//card
			"GVG_112",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			6,				//hp
			"All minions have a 50% chance to attack the wrong enemy. Mogor helped reopen the Dark Portal once. You know you're in trouble when you have to rely on an ogre.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Muster_for_Battle;
		Muster_for_Battle.fx[0] = true;			//Spell AKA battlecry
		Muster_for_Battle.fx2[0] = "nan:";
		initCard(
			Muster_for_Battle,				//card
			"GVG_061",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Summon three 1/1 Silver Hand Recruits. Equip a 1/4 Weapon. \"I'm bringing the guacamole!\" – One of the most successful (yet rare) Silver Hand rallying cries",
			"",				//race
			""				//hero
			);
	}
	{
		Card Neptulon;
		Neptulon.fx[0] = true;			//Battlecry
		Neptulon.fx2[0] = "nan:";
		Neptulon.fx[6] = true;			//Overload
		Neptulon.fx2[6] = "nan:";
		initCard(
			Neptulon,				//card
			"GVG_042",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			7,				//atk
			7,				//hp
			"<b>Battlecry:</b> Add 4 random Murlocs to your hand. <b>Overload:</b> (3) Neptulon is \"The Tidehunter\". He’s one of the four elemental lords. And he and Ragnaros get together and make really amazing saunas.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ogre_Brute;
		initCard(
			Ogre_Brute,				//card
			"GVG_065",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			4,				//hp
			"50% chance to attack the wrong enemy. Ogres have really terrible short-term chocolate.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ogre_Ninja;
		Ogre_Ninja.fx[9] = true;			//Stealth
		initCard(
			Ogre_Ninja,				//card
			"GVG_088",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			6,				//hp
			"<b>Stealth</b>\n50% chance to attack the wrong enemy. He didn't have the grades to get into ninja school, but his dad pulled some strings.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ogre_Warmaul;
		initCard(
			Ogre_Warmaul,				//card
			"GVG_054",				//id
			"Common",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			4,				//atk
			0,				//hp
			"50% chance to attack the wrong enemy. Simple, misguided, and incredibly dangerous. You know, like most things ogre.",
			"",				//race
			""				//hero
			);
	}
	{
		Card One_eyed_Cheat;
		initCard(
			One_eyed_Cheat,				//card
			"GVG_025",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			1,				//hp
			"Whenever you summon a Pirate, gain <b>Stealth</b>. When pirates say there is no \"Eye\" in \"team,\" they are very literal about it.",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Piloted_Shredder;
		Piloted_Shredder.fx[2] = true;			//Deathrattle
		Piloted_Shredder.fx2[2] = "nan:";
		initCard(
			Piloted_Shredder,				//card
			"GVG_096",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			3,				//hp
			"<b>Deathrattle:</b> Summon a random 2-Cost minion. Once upon a time, only goblins piloted shredders. These days, everyone from Doomsayer to Lorewalker Cho seems to ride one.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Piloted_Sky_Golem;
		Piloted_Sky_Golem.fx[2] = true;			//Deathrattle
		Piloted_Sky_Golem.fx2[2] = "nan:";
		initCard(
			Piloted_Sky_Golem,				//card
			"GVG_105",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Summon a random 4-Cost minion. The pinnacle of goblin engineering. Includes an espresso machine and foot massager.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Powermace;
		Powermace.fx[2] = true;			//Deathrattle
		Powermace.fx2[2] = "nan:";
		initCard(
			Powermace,				//card
			"GVG_036",				//id
			"Rare",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			3,				//atk
			0,				//hp
			"<b>Deathrattle</b>: Give a random friendly Mech +2/+2. People assume that shamans control the elements, but really, they have to ask them stuff and the elements are like, \"Yeah ok, sure.\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Puddlestomper;
		initCard(
			Puddlestomper,				//card
			"GVG_064",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"He pays homage to Morgl, the great murloc oracle! (Who doesn't??)",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Quartermaster;
		Quartermaster.fx[0] = true;			//Battlecry
		Quartermaster.fx2[0] = "nan:";
		initCard(
			Quartermaster,				//card
			"GVG_060",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			2,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give your Silver Hand Recruits +2/+2. His specialty? Dividing things into four pieces.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Recombobulator;
		Recombobulator.fx[0] = true;			//Battlecry
		Recombobulator.fx2[0] = "nan:";
		initCard(
			Recombobulator,				//card
			"GVG_108",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Transform a friendly minion into a random minion with the same Cost. For when you didn’t combobulate quite right the first time around.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Recycle;
		Recycle.fx[0] = true;			//Spell AKA battlecry
		Recycle.fx2[0] = "nan:";
		initCard(
			Recycle,				//card
			"GVG_031",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Shuffle an enemy minion into your opponent's deck. Druidic recycling involves putting plastics in one bin and enemy minions in another bin.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Reversing_Switch;
		Reversing_Switch.fx[0] = true;			//Spell AKA battlecry
		Reversing_Switch.fx2[0] = "nan:";
		initCard(
			Reversing_Switch,				//card
			"PART_006",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Swap a minion's Attack and Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rusty_Horn;
		Rusty_Horn.fx[0] = true;			//Spell AKA battlecry
		Rusty_Horn.fx2[0] = "nan:";
		initCard(
			Rusty_Horn,				//card
			"PART_003",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sabotage;
		Sabotage.fx[0] = true;			//Spell AKA battlecry
		Sabotage.fx2[0] = "nan:";
		initCard(
			Sabotage,				//card
			"GVG_047",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Destroy a random enemy minion. <b>Combo</b>: And your opponent's weapon. Rogues can't stand it. They know you planned it! They are going to set you straight!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Salty_Dog;
		initCard(
			Salty_Dog,				//card
			"GVG_070",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			7,				//atk
			4,				//hp
			"He's recently recovered from being a \"scurvy dog.\"",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Scarlet_Purifier;
		Scarlet_Purifier.fx[0] = true;			//Battlecry
		Scarlet_Purifier.fx2[0] = "nan:";
		initCard(
			Scarlet_Purifier,				//card
			"GVG_101",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry</b>: Deal 2 damage to all minions with <b>Deathrattle</b>. The Scarlet Crusade is doing market research to find out if the \"Mauve Crusade\" would be better received.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Screwjank_Clunker;
		Screwjank_Clunker.fx[0] = true;			//Battlecry
		Screwjank_Clunker.fx2[0] = "nan:";
		initCard(
			Screwjank_Clunker,				//card
			"GVG_055",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"<b>Battlecry</b>: Give a friendly Mech +2/+2. If it breaks, just kick it a couple of times while yelling \"Durn thing!\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Seal_of_Light;
		Seal_of_Light.fx[0] = true;			//Spell AKA battlecry
		Seal_of_Light.fx2[0] = "nan:";
		initCard(
			Seal_of_Light,				//card
			"GVG_057",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Restore #4 Health to your hero and gain +2 Attack this turn. The walrus of Light restores EIGHT Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowbomber;
		Shadowbomber.fx[0] = true;			//Battlecry
		Shadowbomber.fx2[0] = "nan:";
		initCard(
			Shadowbomber,				//card
			"GVG_009",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Battlecry:</b> Deal 3 damage to each hero. Shadowbomber does her job, but she's kind of phoning it in at this point.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowboxer;
		initCard(
			Shadowboxer,				//card
			"GVG_072",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Whenever a character is healed, deal 1 damage to a random enemy. Punching is its primary function. Also, its secondary function.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Shielded_Minibot;
		Shielded_Minibot.fx[3] = true;			//Divine Shield
		initCard(
			Shielded_Minibot,				//card
			"GVG_058",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"<b>Divine Shield</b> He chooses to believe what he is programmed to believe!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Shieldmaiden;
		Shieldmaiden.fx[0] = true;			//Battlecry
		Shieldmaiden.fx2[0] = "nan:";
		initCard(
			Shieldmaiden,				//card
			"GVG_053",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Gain 5 Armor. She has three shieldbearers in her party to supply her with back ups when she gets low on durability.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ships_Cannon;
		initCard(
			Ships_Cannon,				//card
			"GVG_075",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Whenever you summon a Pirate, deal 2 damage to a random enemy. If you hear someone yell, \"Cannonball!\" you're about to get wet. Or crushed.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shrinkmeister;
		Shrinkmeister.fx[0] = true;			//Battlecry
		Shrinkmeister.fx2[0] = "nan:";
		initCard(
			Shrinkmeister,				//card
			"GVG_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give a minion -2 Attack this turn. After the debacle of the Gnomish World Enlarger, gnomes are wary of size-changing inventions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Siege_Engine;
		initCard(
			Siege_Engine,				//card
			"GVG_086",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"Whenever you gain Armor, give this minion +1 Attack. Wintergrasp Keep's only weakness!",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Siltfin_Spiritwalker;
		initCard(
			Siltfin_Spiritwalker,				//card
			"GVG_040",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"Whenever another friendly Murloc dies, draw a card. <b>Overload</b>: (1) The elements respond to anyone who calls them for a worthy cause, even if you call them by yelling, \"MRGHRGLGLGL!\"",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Sneeds_Old_Shredder;
		Sneeds_Old_Shredder.fx[2] = true;			//Deathrattle
		Sneeds_Old_Shredder.fx2[2] = "nan:";
		initCard(
			Sneeds_Old_Shredder,				//card
			"GVG_114",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			5,				//atk
			7,				//hp
			"<b>Deathrattle:</b> Summon a random legendary minion. When Sneed was defeated in the Deadmines, his shredder was sold at auction to an anonymous buyer. (Probably Hogger.)",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Snowchugger;
		Snowchugger.fx[5] = true;			//Freeze
		initCard(
			Snowchugger,				//card
			"GVG_002",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Freeze</b> any character damaged by this minion. Do the slow chant when he waddles by: \"Chug! Chug! Chug!\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Soot_Spewer;
		initCard(
			Soot_Spewer,				//card
			"GVG_123",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Spell Damage +1</b> The inventor of the goblin shredder is involved in several patent disputes with the inventor of the soot spewer.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Spider_Tank;
		initCard(
			Spider_Tank,				//card
			"GVG_044",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"\"What if we put guns on it?\" -Fizzblitz, staring at the spider-transportation-machine",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Steamwheedle_Sniper;
		initCard(
			Steamwheedle_Sniper,				//card
			"GVG_087",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Your Hero Power can target minions. Goblins seldom have the patience for sniping. Most prefer lobbing explosives.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stonesplinter_Trogg;
		initCard(
			Stonesplinter_Trogg,				//card
			"GVG_067",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"Whenever your opponent casts a spell, gain +1 Attack. The only thing worse than smelling troggs is listening to their poetry.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tank_Mode;
		Tank_Mode.fx[0] = true;			//Spell AKA battlecry
		Tank_Mode.fx2[0] = "nan:";
		initCard(
			Tank_Mode,				//card
			"GVG_030b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+1 Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Target_Dummy;
		Target_Dummy.fx[10] = true;			//Taunt
		initCard(
			Target_Dummy,				//card
			"GVG_093",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			2,				//hp
			"<b>Taunt</b> The engineering equivalent of a \"Kick Me\" sticker.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Time_Rewinder;
		Time_Rewinder.fx[0] = true;			//Spell AKA battlecry
		Time_Rewinder.fx2[0] = "nan:";
		initCard(
			Time_Rewinder,				//card
			"PART_002",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Return a friendly minion to your hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tinkers_Sharpsword_Oil;
		Tinkers_Sharpsword_Oil.fx[0] = true;			//Spell AKA battlecry
		Tinkers_Sharpsword_Oil.fx2[0] = "nan:";
		initCard(
			Tinkers_Sharpsword_Oil,				//card
			"GVG_022",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Give your weapon +3 Attack. <b>Combo:</b> Give a random friendly minion +3 Attack. \"Get ready to strike oil!\" - Super-cheesy battle cry",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tinkertown_Technician;
		Tinkertown_Technician.fx[0] = true;			//Battlecry
		Tinkertown_Technician.fx2[0] = "nan:";
		initCard(
			Tinkertown_Technician,				//card
			"GVG_102",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> If you have a Mech, gain +1/+1 and add a <b>Spare Part</b> to your hand. Won't you take me to... Tinkertown?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Toshley;
		Toshley.fx[0] = true;			//Battlecry
		Toshley.fx2[0] = "nan:";
		Toshley.fx[2] = true;			//Deathrattle
		Toshley.fx2[2] = "nan:";
		initCard(
			Toshley,				//card
			"GVG_115",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			7,				//hp
			"<b>Battlecry and Deathrattle:</b> Add a <b>Spare Part</b> card to your hand. Something about power converters.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Trade_Prince_Gallywix;
		initCard(
			Trade_Prince_Gallywix,				//card
			"GVG_028",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			8,				//hp
			"Whenever your opponent casts a spell, gain a copy of it and give them a Coin. Gallywix believes in supply and demand. He supplies the beatings and demands you pay up!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tree_of_Life;
		Tree_of_Life.fx[0] = true;			//Spell AKA battlecry
		Tree_of_Life.fx2[0] = "nan:";
		initCard(
			Tree_of_Life,				//card
			"GVG_033",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			9,				//cost
			0,				//atk
			0,				//hp
			"Restore all characters to full Health. Healing: It grows on trees!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Troggzor_the_Earthinator;
		initCard(
			Troggzor_the_Earthinator,				//card
			"GVG_118",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			6,				//hp
			"Whenever your opponent casts a spell, summon a Burly Rockjaw Trogg. He keeps earthinating the countryside despite attempts to stop him.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Unstable_Portal;
		Unstable_Portal.fx[0] = true;			//Spell AKA battlecry
		Unstable_Portal.fx2[0] = "nan:";
		initCard(
			Unstable_Portal,				//card
			"GVG_003",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Add a random minion to your hand. It costs (3) less. The denizens of Azeroth have no idea how much work goes into stabilizing portals.  We spend like 30% of GDP on portal upkeep.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Upgraded_Repair_Bot;
		Upgraded_Repair_Bot.fx[0] = true;			//Battlecry
		Upgraded_Repair_Bot.fx2[0] = "nan:";
		initCard(
			Upgraded_Repair_Bot,				//card
			"GVG_083",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give a friendly Mech +4 Health. It's the same as the previous generation but they slapped the word \"upgraded\" on it to sell it for double.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card V_07_TR_0N;
		V_07_TR_0N.fx[1] = true;			//Charge
		initCard(
			V_07_TR_0N,				//card
			"GVG_111t",				//id
			"Legendary",				//rarity
			false,					//Collect
			"Minion",				//type
			8,				//cost
			4,				//atk
			8,				//hp
			"<b>Charge</b>\n<b>Mega-Windfury</b> <i>(Can attack four times a turn.)</i>",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Velens_Chosen;
		Velens_Chosen.fx[0] = true;			//Spell AKA battlecry
		Velens_Chosen.fx2[0] = "nan:";
		initCard(
			Velens_Chosen,				//card
			"GVG_010",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +2/+4 and <b>Spell Damage +1</b>. Velen wrote a \"Lovely Card\" for Tyrande with a picture of the Deeprun Tram that said \"I Choo-Choo-Choose you!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Vitality_Totem;
		initCard(
			Vitality_Totem,				//card
			"GVG_039",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			0,				//atk
			3,				//hp
			"At the end of your turn, restore 4 Health to your hero. You can usually find these at the totemist's market on Saturdays.",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Voljin;
		Voljin.fx[0] = true;			//Battlecry
		Voljin.fx2[0] = "nan:";
		initCard(
			Voljin,				//card
			"GVG_014",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			6,				//atk
			2,				//hp
			"<b>Battlecry:</b> Swap Health with another minion. Vol'jin is a shadow hunter, which is like a shadow priest except more voodoo.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Warbot;
		Warbot.fx[4] = true;			//Enrage
		Warbot.fx2[4] = "nan:";
		initCard(
			Warbot,				//card
			"GVG_051",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			3,				//hp
			"<b>Enrage:</b> +1 Attack. Mass production of warbots was halted when it was discovered that they were accidentally being produced at \"sample size.\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Wee_Spellstopper;
		initCard(
			Wee_Spellstopper,				//card
			"GVG_122",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			5,				//hp
			"Adjacent minions can't be targeted by spells or Hero Powers. Bane of spellcasters and spelling bees everywhere.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Whirling_Blades;
		Whirling_Blades.fx[0] = true;			//Spell AKA battlecry
		Whirling_Blades.fx2[0] = "nan:";
		initCard(
			Whirling_Blades,				//card
			"PART_007",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +1 Attack.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Whirling_Zap_o_matic;
		Whirling_Zap_o_matic.fx[11] = true;			//Windfury
		initCard(
			Whirling_Zap_o_matic,				//card
			"GVG_037",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Windfury</b> If you pay a little extra, you can get it in \"candy-apple red.\"",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Brewmaster;
		initCard(
			Brewmaster,				//card
			"TU4f_005",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gnoll;
		initCard(
			Gnoll,				//card
			"TU4a_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Massive_Gnoll;
		initCard(
			Massive_Gnoll,				//card
			"TU4a_005",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pandaren_Scout;
		initCard(
			Pandaren_Scout,				//card
			"TU4f_002",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Riverpaw_Gnoll;
		initCard(
			Riverpaw_Gnoll,				//card
			"TU4a_002",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shado_Pan_Monk;
		initCard(
			Shado_Pan_Monk,				//card
			"TU4f_003",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stomp;
		Stomp.fx[0] = true;			//Spell AKA battlecry
		Stomp.fx2[0] = "nan:";
		initCard(
			Stomp,				//card
			"TU4c_004",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Deal 2 damage to all enemies.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Will_of_Mukla;
		Will_of_Mukla.fx[0] = true;			//Spell AKA battlecry
		Will_of_Mukla.fx2[0] = "nan:";
		initCard(
			Will_of_Mukla,				//card
			"TU4c_008",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			1,				//atk
			1,				//hp
			"Restore 8 Health.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Elite_Tauren_Chieftain;
		Elite_Tauren_Chieftain.fx[0] = true;			//Battlecry
		Elite_Tauren_Chieftain.fx2[0] = "nan:";
		initCard(
			Elite_Tauren_Chieftain,				//card
			"PRO_001",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give both players the power to ROCK! (with a Power Chord card) He's looking for a drummer.  The current candidates are: Novice Engineer, Sen'jin Shieldmasta', and Ragnaros the Firelord.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Emboldener_3000;
		initCard(
			Emboldener_3000,				//card
			"Mekka3",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			4,				//hp
			"At the end of your turn, give a random minion +1/+1.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Gelbin_Mekkatorque;
		Gelbin_Mekkatorque.fx[0] = true;			//Battlecry
		Gelbin_Mekkatorque.fx2[0] = "nan:";
		initCard(
			Gelbin_Mekkatorque,				//card
			"EX1_112",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"<b>Battlecry:</b> Summon an AWESOME invention. He's the leader of the gnomes, and an incredible inventor.  He's getting better, too; He turns things into chickens WAY less than he used to.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Homing_Chicken;
		initCard(
			Homing_Chicken,				//card
			"Mekka1",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			1,				//hp
			"At the start of your turn, destroy this minion and draw 3 cards.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card I_Am_Murloc;
		I_Am_Murloc.fx[0] = true;			//Spell AKA battlecry
		I_Am_Murloc.fx2[0] = "nan:";
		initCard(
			I_Am_Murloc,				//card
			"PRO_001a",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Summon three, four, or five 1/1 Murlocs.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Murloc;
		initCard(
			Murloc,				//card
			"PRO_001at",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Poultryizer;
		initCard(
			Poultryizer,				//card
			"Mekka4",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			3,				//hp
			"At the start of your turn, transform a random minion into a 1/1 Chicken.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Power_of_the_Horde;
		Power_of_the_Horde.fx[0] = true;			//Spell AKA battlecry
		Power_of_the_Horde.fx2[0] = "nan:";
		initCard(
			Power_of_the_Horde,				//card
			"PRO_001c",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Summon a random Horde Warrior.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Repair_Bot;
		initCard(
			Repair_Bot,				//card
			"Mekka2",				//id
			"Common",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			0,				//atk
			3,				//hp
			"At the end of your turn, restore 6 Health to a damaged character.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Rogues_Do_It;
		Rogues_Do_It.fx[0] = true;			//Spell AKA battlecry
		Rogues_Do_It.fx2[0] = "nan:";
		initCard(
			Rogues_Do_It,				//card
			"PRO_001b",				//id
			"",				//rarity
			false,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Deal $4 damage. Draw a card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Old_Murk_Eye;
		Old_Murk_Eye.fx[1] = true;			//Charge
		initCard(
			Old_Murk_Eye,				//card
			"EX1_062",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			4,				//hp
			"<b>Charge</b>. Has +1 Attack for each other Murloc on the battlefield. He's a legend among murlocs.  \"Mrghllghghllghg!\", they say.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Big_Banana;
		Big_Banana.fx[0] = true;			//Spell AKA battlecry
		Big_Banana.fx2[0] = "nan:";
		initCard(
			Big_Banana,				//card
			"TB_006",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Give a minion +2/+2.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Choose_a_New_Card;
		Choose_a_New_Card.fx[0] = true;			//Spell AKA battlecry
		Choose_a_New_Card.fx2[0] = "nan:";
		initCard(
			Choose_a_New_Card,				//card
			"TB_014",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Look at 3 random cards. Choose one and put it into your hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Choose_a_New_Card;
		Choose_a_New_Card.fx[0] = true;			//Spell AKA battlecry
		Choose_a_New_Card.fx2[0] = "nan:";
		initCard(
			Choose_a_New_Card,				//card
			"TB_012",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Look at 3 random cards. Choose one and shuffle it into your deck.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Core_Hound_Pup;
		initCard(
			Core_Hound_Pup,				//card
			"BRMC_95he",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"At the end of each turn, summon all Core Hound Pups that died this turn.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Core_Hound_Puppies;
		Core_Hound_Puppies.fx[0] = true;			//Spell AKA battlecry
		Core_Hound_Puppies.fx2[0] = "nan:";
		initCard(
			Core_Hound_Puppies,				//card
			"BRMC_95h",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Summon two 2/4 Core Hound Pups.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Coren_Direbrew;
		Coren_Direbrew.fx[0] = true;			//Battlecry
		Coren_Direbrew.fx2[0] = "nan:";
		initCard(
			Coren_Direbrew,				//card
			"BRMC_92",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			8,				//hp
			"Always wins Brawls.\n <b>Battlecry:</b> Add a Brawl to your hand.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Deviate_Banana;
		Deviate_Banana.fx[0] = true;			//Spell AKA battlecry
		Deviate_Banana.fx2[0] = "nan:";
		initCard(
			Deviate_Banana,				//card
			"TB_007",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Swap a minion's Attack and Health.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragonkin_Spellcaster;
		Dragonkin_Spellcaster.fx[0] = true;			//Battlecry
		Dragonkin_Spellcaster.fx2[0] = "nan:";
		initCard(
			Dragonkin_Spellcaster,				//card
			"BRMC_84",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			6,				//hp
			"<b>Battlecry:</b> Summon two 2/2 Whelps.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Drakonid_Slayer;
		initCard(
			Drakonid_Slayer,				//card
			"BRMC_88",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"Also damages the minions next to whomever he attacks.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Garr;
		initCard(
			Garr,				//card
			"BRMC_99",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			8,				//hp
			"Whenever this minion takes damage, summon a 2/3 Elemental with <b>Taunt</b>.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Golemagg;
		initCard(
			Golemagg,				//card
			"BRMC_95",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			50,				//cost
			20,				//atk
			20,				//hp
			"Costs (1) less for each damage your hero has taken.",
			"",				//race
			""				//hero
			);
	}
	{
		Card High_Justice_Grimstone;
		initCard(
			High_Justice_Grimstone,				//card
			"BRMC_96",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			5,				//hp
			"At the start of your turn, summon a <b>Legendary</b> minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Living_Lava;
		Living_Lava.fx[10] = true;			//Taunt
		initCard(
			Living_Lava,				//card
			"BRMC_90",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			6,				//atk
			6,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lucifron;
		Lucifron.fx[0] = true;			//Battlecry
		Lucifron.fx2[0] = "nan:";
		initCard(
			Lucifron,				//card
			"BRMC_85",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			7,				//hp
			"<b>Battlecry:</b> Cast Corruption on all other minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Moira_Bronzebeard;
		Moira_Bronzebeard.fx[2] = true;			//Deathrattle
		Moira_Bronzebeard.fx2[2] = "nan:";
		initCard(
			Moira_Bronzebeard,				//card
			"BRMC_87",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Deathrattle:</b> Summon Emperor Thaurissan.",
			"",				//race
			""				//hero
			);
	}
	{
		Card OLDLegit_Healer;
		initCard(
			OLDLegit_Healer,				//card
			"TBST_004",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"At the end of your turn, summon a random friendly minion that died this turn.",
			"",				//race
			""				//hero
			);
	}
	{
		Card OLDN3wb_Healer;
		initCard(
			OLDN3wb_Healer,				//card
			"TBST_003",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"At the end of your turn, heal 2 damage from adjacent minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card OLDN3wb_Mage;
		initCard(
			OLDN3wb_Mage,				//card
			"TBST_002",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"At the end of your turn, deal 1 damage to random enemy minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card OLDN3wb_Tank;
		OLDN3wb_Tank.fx[10] = true;			//Taunt
		initCard(
			OLDN3wb_Tank,				//card
			"TBST_001",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card OLDPvP_Rogue;
		OLDPvP_Rogue.fx[9] = true;			//Stealth
		initCard(
			OLDPvP_Rogue,				//card
			"TBST_005",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			6,				//hp
			"<b>Stealth</b>\nRegain <b>Stealth</b> when PvP Rogue kills a minion.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Omnotron_Defense_System;
		Omnotron_Defense_System.fx[0] = true;			//Spell AKA battlecry
		Omnotron_Defense_System.fx2[0] = "nan:";
		initCard(
			Omnotron_Defense_System,				//card
			"BRMC_93",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Summon a random Tron.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Open_the_Gates;
		Open_the_Gates.fx[0] = true;			//Spell AKA battlecry
		Open_the_Gates.fx2[0] = "nan:";
		initCard(
			Open_the_Gates,				//card
			"BRMC_83",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			8,				//cost
			0,				//atk
			0,				//hp
			"Fill your board with 2/2 Whelps.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pirate;
		initCard(
			Pirate,				//card
			"TB_015",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Razorgore;
		initCard(
			Razorgore,				//card
			"BRMC_98",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			12,				//hp
			"At the start of your turn, give your minions +3 Attack.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Rock_Elemental;
		Rock_Elemental.fx[10] = true;			//Taunt
		initCard(
			Rock_Elemental,				//card
			"BRMC_99e",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rotten_Banana;
		Rotten_Banana.fx[0] = true;			//Spell AKA battlecry
		Rotten_Banana.fx2[0] = "nan:";
		initCard(
			Rotten_Banana,				//card
			"TB_008",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $1 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Son_of_the_Flame;
		Son_of_the_Flame.fx[0] = true;			//Battlecry
		Son_of_the_Flame.fx2[0] = "nan:";
		initCard(
			Son_of_the_Flame,				//card
			"BRMC_91",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			6,				//atk
			3,				//hp
			"<b>Battlecry:</b> Deal 6 damage.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sulfuras;
		Sulfuras.fx[2] = true;			//Deathrattle
		Sulfuras.fx2[2] = "nan:";
		initCard(
			Sulfuras,				//card
			"BRMC_94",				//id
			"",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			2,				//atk
			0,				//hp
			"<b>Deathrattle:</b> Your Hero Power becomes 'Deal 8 damage to a random enemy'.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tarnished_Coin;
		Tarnished_Coin.fx[0] = true;			//Spell AKA battlecry
		Tarnished_Coin.fx2[0] = "nan:";
		initCard(
			Tarnished_Coin,				//card
			"TB_011",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"Gain 1 Mana Crystal this turn only.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Vaelastrasz;
		initCard(
			Vaelastrasz,				//card
			"BRMC_97",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			7,				//hp
			"Your cards cost (3) less.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Whirling_Ash;
		Whirling_Ash.fx[11] = true;			//Windfury
		initCard(
			Whirling_Ash,				//card
			"BRMC_89",				//id
			"",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			5,				//hp
			"<b>Windfury</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Alexstraszas_Champion;
		Alexstraszas_Champion.fx[0] = true;			//Battlecry
		Alexstraszas_Champion.fx2[0] = "nan:";
		initCard(
			Alexstraszas_Champion,				//card
			"AT_071",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, gain +1 Attack and <b>Charge</b>. \"Put more spikes on her.  No, more spikes.  What part of 'more spikes' do you not understand?  MORE SPIKES!\" - Alexstrasza",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ambush;
		Ambush.fx[0] = true;			//Spell AKA battlecry
		Ambush.fx2[0] = "nan:";
		initCard(
			Ambush,				//card
			"AT_035t",				//id
			"",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"When you draw this, summon a 4/4 Nerubian for your opponent. Draw a card.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ancestral_Knowledge;
		Ancestral_Knowledge.fx[0] = true;			//Spell AKA battlecry
		Ancestral_Knowledge.fx2[0] = "nan:";
		initCard(
			Ancestral_Knowledge,				//card
			"AT_053",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Draw 2 cards. <b>Overload: (2)</b> MOMMMMMYYYYYYYYY!!!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Anubarak;
		Anubarak.fx[2] = true;			//Deathrattle
		Anubarak.fx2[2] = "nan:";
		initCard(
			Anubarak,				//card
			"AT_036",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			8,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Return this to your hand and summon a 4/4 Nerubian. Was actually a pretty nice guy before, you know, the whole Lich King thing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Arcane_Blast;
		Arcane_Blast.fx[0] = true;			//Spell AKA battlecry
		Arcane_Blast.fx2[0] = "nan:";
		initCard(
			Arcane_Blast,				//card
			"AT_004",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to a minion. This spell gets double bonus from <b>Spell Damage</b>. Now with 100% more blast!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Horserider;
		Argent_Horserider.fx[1] = true;			//Charge
		Argent_Horserider.fx[3] = true;			//Divine Shield
		initCard(
			Argent_Horserider,				//card
			"AT_087",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			1,				//hp
			"<b>Charge</b>\n<b>Divine Shield</b> His horse's name is Betsy.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Lance;
		Argent_Lance.fx[0] = true;			//Battlecry
		Argent_Lance.fx2[0] = "nan:";
		initCard(
			Argent_Lance,				//card
			"AT_077",				//id
			"Rare",				//rarity
			true,					//Collect
			"Weapon",				//type
			2,				//cost
			2,				//atk
			0,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, +1 Durability. The stripes make it look like a candy cane, but we recommend against licking it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Argent_Watchman;
		Argent_Watchman.fx[12] = true;			//Inspire
		Argent_Watchman.fx2[12] = "nan:";
		initCard(
			Argent_Watchman,				//card
			"AT_109",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			4,				//hp
			"Can't attack.\n<b>Inspire:</b> Can attack as normal this turn. Who argent watches the Argent Watchman?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Armored_Warhorse;
		Armored_Warhorse.fx[0] = true;			//Battlecry
		Armored_Warhorse.fx2[0] = "nan:";
		initCard(
			Armored_Warhorse,				//card
			"AT_108",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			3,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, gain <b>Charge</b>. Yep.  It's a horse... wearing armor... going to war.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Astral_Communion;
		Astral_Communion.fx[0] = true;			//Spell AKA battlecry
		Astral_Communion.fx2[0] = "nan:";
		initCard(
			Astral_Communion,				//card
			"AT_043",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"Gain 10 Mana Crystals. Discard your hand. Hey!  Moon!  Can I have some mana crystals?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Aviana;
		initCard(
			Aviana,				//card
			"AT_045",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			5,				//atk
			5,				//hp
			"Your minions cost (1). Call her \"Tweety\".  She'll find it real funny.  I PROMISE.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ball_of_Spiders;
		Ball_of_Spiders.fx[0] = true;			//Spell AKA battlecry
		Ball_of_Spiders.fx2[0] = "nan:";
		initCard(
			Ball_of_Spiders,				//card
			"AT_062",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Summon three 1/1 Webspinners. \"THEY'RE EVERYWHERE GET THEM OFF!!!\" - Everyone",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bash;
		Bash.fx[0] = true;			//Spell AKA battlecry
		Bash.fx2[0] = "nan:";
		initCard(
			Bash,				//card
			"AT_064",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $3 damage.\nGain 3 Armor. You might think bashing doesn't take a lot of practice.  It doesn't.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bear_Trap;
		Bear_Trap.fx[8] = true;			//Secret
		Bear_Trap.fx2[8] = "nan:";
		Bear_Trap.fx[0] = true;			//Spell AKA battlecry
		Bear_Trap.fx2[0] = "nan:";
		initCard(
			Bear_Trap,				//card
			"AT_060",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> After your hero is attacked, summon a 3/3 Bear with <b>Taunt</b>. You'll never guess what's in that conveniently bear-sized, bear-smelling box.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Beneath_the_Grounds;
		Beneath_the_Grounds.fx[0] = true;			//Spell AKA battlecry
		Beneath_the_Grounds.fx2[0] = "nan:";
		initCard(
			Beneath_the_Grounds,				//card
			"AT_035",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Shuffle 3 Ambushes into your opponent's deck. When drawn, you summon a 4/4 Nerubian. Can you hold these eggs for just a second?  I promise they're not full of giant enraged undead spider things.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Boar;
		Boar.fx[1] = true;			//Charge
		initCard(
			Boar,				//card
			"AT_005t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Charge</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Bolf_Ramshield;
		initCard(
			Bolf_Ramshield,				//card
			"AT_124",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			3,				//atk
			9,				//hp
			"Whenever your hero takes damage, this minion takes it instead. Bolf keeps coming in 2nd at the Grand Tournament.  It might be his year this year, if Lebron doesn't enter.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Bolster;
		Bolster.fx[0] = true;			//Spell AKA battlecry
		Bolster.fx2[0] = "nan:";
		initCard(
			Bolster,				//card
			"AT_068",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give your <b>Taunt</b> minions +2/+2. The best offense is a good defense.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Boneguard_Lieutenant;
		Boneguard_Lieutenant.fx[12] = true;			//Inspire
		Boneguard_Lieutenant.fx2[12] = "nan:";
		initCard(
			Boneguard_Lieutenant,				//card
			"AT_089",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Inspire:</b> Gain +1 Health. Underneath all that impressive armor, he's just skin and bones.  Okay, maybe just bones.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Brave_Archer;
		Brave_Archer.fx[12] = true;			//Inspire
		Brave_Archer.fx2[12] = "nan:";
		initCard(
			Brave_Archer,				//card
			"AT_059",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Inspire:</b> If your hand is empty, deal 2 damage to the enemy hero. This is a \"bearly\" concealed reference.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Buccaneer;
		initCard(
			Buccaneer,				//card
			"AT_029",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"Whenever you equip a weapon, give it +1 Attack. The best part of buccaneering is the pants.",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Burgle;
		Burgle.fx[0] = true;			//Spell AKA battlecry
		Burgle.fx2[0] = "nan:";
		initCard(
			Burgle,				//card
			"AT_033",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Add 2 random class cards to your hand <i>(from your opponent's class)</i>. Yoink!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Captured_Jormungar;
		initCard(
			Captured_Jormungar,				//card
			"AT_102",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			9,				//hp
			"You can keep him, but you have to promise to feed him and clean out his tank every day!",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Charged_Hammer;
		Charged_Hammer.fx[2] = true;			//Deathrattle
		Charged_Hammer.fx2[2] = "nan:";
		initCard(
			Charged_Hammer,				//card
			"AT_050",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			4,				//cost
			2,				//atk
			0,				//hp
			"<b>Deathrattle:</b> Your Hero Power becomes 'Deal 2 damage.' You can only pick it up if you are worthy.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Chillmaw;
		Chillmaw.fx[2] = true;			//Deathrattle
		Chillmaw.fx2[2] = "nan:";
		Chillmaw.fx[10] = true;			//Taunt
		initCard(
			Chillmaw,				//card
			"AT_123",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			6,				//hp
			"<b>Taunt</b>\n<b>Deathrattle:</b> If you're holding a Dragon, deal 3 damage to all minions. Chillmaw keeps trying to ruin the Grand Tournament, and she would've done it too, if it weren't for those dang kids!",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Clockwork_Knight;
		Clockwork_Knight.fx[0] = true;			//Battlecry
		Clockwork_Knight.fx2[0] = "nan:";
		initCard(
			Clockwork_Knight,				//card
			"AT_096",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Give a friendly Mech +1/+1. It takes a lot to wind him up.",
			"Mech",				//race
			""				//hero
			);
	}
	{
		Card Coldarra_Drake;
		initCard(
			Coldarra_Drake,				//card
			"AT_008",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"You can use your Hero Power any number of times. The Grand Tournament has a \"No dragons allowed\" policy, but it's rarely enforced.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Coliseum_Manager;
		Coliseum_Manager.fx[12] = true;			//Inspire
		Coliseum_Manager.fx2[12] = "nan:";
		initCard(
			Coliseum_Manager,				//card
			"AT_110",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			5,				//hp
			"<b>Inspire:</b> Return this minion to your hand. Meets monthly with the gladiators to discuss career goals.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Competitive_Spirit;
		Competitive_Spirit.fx[8] = true;			//Secret
		Competitive_Spirit.fx2[8] = "nan:";
		Competitive_Spirit.fx[0] = true;			//Spell AKA battlecry
		Competitive_Spirit.fx2[0] = "nan:";
		initCard(
			Competitive_Spirit,				//card
			"AT_073",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When your turn starts, give your minions +1/+1. Competition can be an inspiration to improve oneself.  Or kill all the competitors.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Confessor_Paletress;
		Confessor_Paletress.fx[12] = true;			//Inspire
		Confessor_Paletress.fx2[12] = "nan:";
		initCard(
			Confessor_Paletress,				//card
			"AT_018",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			5,				//atk
			4,				//hp
			"<b>Inspire:</b> Summon a random <b>Legendary</b> minion. She sees into your past and makes you face your fears.  Most common fear:  Getting Majordomo out of Sneed's Old Shredder.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Confuse;
		Confuse.fx[0] = true;			//Spell AKA battlecry
		Confuse.fx2[0] = "nan:";
		initCard(
			Confuse,				//card
			"AT_016",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Swap the Attack and Health of all minions. This minion is really powerful!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Convert;
		Convert.fx[0] = true;			//Spell AKA battlecry
		Convert.fx2[0] = "nan:";
		initCard(
			Convert,				//card
			"AT_015",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Put a copy of an enemy minion into your hand. \"Are you interested in... HEALTH benefits?!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Crowd_Favorite;
		initCard(
			Crowd_Favorite,				//card
			"AT_121",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"Whenever you play a card with <b>Battlecry</b>, gain +1/+1. The crowd ALWAYS yells lethal.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Cutpurse;
		initCard(
			Cutpurse,				//card
			"AT_031",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			2,				//hp
			"Whenever this minion attacks a hero, add the Coin to your hand. He has a giant collection of purses now.  One for every outfit!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dalaran_Aspirant;
		Dalaran_Aspirant.fx[12] = true;			//Inspire
		Dalaran_Aspirant.fx2[12] = "nan:";
		initCard(
			Dalaran_Aspirant,				//card
			"AT_006",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"<b>Inspire:</b> Gain <b>Spell Damage +1</b>. Is he aspiring or inspiring?  Make up your mind!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dark_Bargain;
		Dark_Bargain.fx[0] = true;			//Spell AKA battlecry
		Dark_Bargain.fx2[0] = "nan:";
		initCard(
			Dark_Bargain,				//card
			"AT_025",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Destroy 2 random enemy minions. Discard 2 random cards. A prime example of lose-lose negotiating.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Darnassus_Aspirant;
		Darnassus_Aspirant.fx[0] = true;			//Battlecry
		Darnassus_Aspirant.fx2[0] = "nan:";
		Darnassus_Aspirant.fx[2] = true;			//Deathrattle
		Darnassus_Aspirant.fx2[2] = "nan:";
		initCard(
			Darnassus_Aspirant,				//card
			"AT_038",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Gain an empty Mana Crystal.\n<b>Deathrattle:</b> Lose a Mana Crystal. She loves mana crystals, she hates mana crystals.   So fickle!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Demonfuse;
		Demonfuse.fx[0] = true;			//Spell AKA battlecry
		Demonfuse.fx2[0] = "nan:";
		initCard(
			Demonfuse,				//card
			"AT_024",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Give a Demon +3/+3. Give your opponent a Mana Crystal. Very dangerous when attached to a demonbomb.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Draenei_Totemcarver;
		Draenei_Totemcarver.fx[0] = true;			//Battlecry
		Draenei_Totemcarver.fx2[0] = "nan:";
		initCard(
			Draenei_Totemcarver,				//card
			"AT_047",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Gain +1/+1 for each friendly Totem. It's nice to find a real craftsman in this day and age of mass-produced totems.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dragonhawk_Rider;
		Dragonhawk_Rider.fx[12] = true;			//Inspire
		Dragonhawk_Rider.fx2[12] = "nan:";
		initCard(
			Dragonhawk_Rider,				//card
			"AT_083",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Inspire:</b> Gain <b>Windfury</b>\nthis turn. Check it out.  You can do barrel rolls on this thing.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Dreadscale;
		initCard(
			Dreadscale,				//card
			"AT_063t",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"At the end of your turn, deal 1 damage to all other minions. Let's be clear about this:  ACIDMAW is the sidekick.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Dreadsteed;
		Dreadsteed.fx[2] = true;			//Deathrattle
		Dreadsteed.fx2[2] = "nan:";
		initCard(
			Dreadsteed,				//card
			"AT_019",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			1,				//hp
			"<b>Deathrattle:</b> Summon a Dreadsteed. Crescendo himself summoned this steed, riding it to victory in the Grand Tournament.  Wherever he rides, an army of riders ride behind him, supporting the legendary champion.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Druid_of_the_Saber;
		initCard(
			Druid_of_the_Saber,				//card
			"AT_042",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Choose One -</b> Transform to gain <b>Charge</b>; or +1/+1 and <b>Stealth</b>. That's saberTEETH, not like curved pirate blades.  That's a different kind of druid.  Druid of the Curved Pirate Blades.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eadric_the_Pure;
		Eadric_the_Pure.fx[0] = true;			//Battlecry
		Eadric_the_Pure.fx2[0] = "nan:";
		initCard(
			Eadric_the_Pure,				//card
			"AT_081",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			3,				//atk
			7,				//hp
			"<b>Battlecry:</b> Change all enemy minions'\nAttack to 1. Nobody rocks a monocle like Eadric.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Effigy;
		Effigy.fx[8] = true;			//Secret
		Effigy.fx2[8] = "nan:";
		Effigy.fx[0] = true;			//Spell AKA battlecry
		Effigy.fx2[0] = "nan:";
		initCard(
			Effigy,				//card
			"AT_002",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"<b>Secret:</b> When a friendly minion dies, summon a random minion with the same Cost. Burning man, brah.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Elemental_Destruction;
		Elemental_Destruction.fx[0] = true;			//Spell AKA battlecry
		Elemental_Destruction.fx2[0] = "nan:";
		initCard(
			Elemental_Destruction,				//card
			"AT_051",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $4-$5 damage to all minions. <b>Overload: (5)</b> I'm not a shaman or anything, but isn't Elemental Destruction the opposite of what they want to do?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Enter_the_Coliseum;
		Enter_the_Coliseum.fx[0] = true;			//Spell AKA battlecry
		Enter_the_Coliseum.fx2[0] = "nan:";
		initCard(
			Enter_the_Coliseum,				//card
			"AT_078",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			6,				//cost
			0,				//atk
			0,				//hp
			"Destroy all minions except each player's highest Attack minion. You have to get past the vendors first.  So many are lost to shopping...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Evil_Heckler;
		Evil_Heckler.fx[10] = true;			//Taunt
		initCard(
			Evil_Heckler,				//card
			"AT_114",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Taunt</b> To be honest, heckling is not the most effective form of evil.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Eydis_Darkbane;
		initCard(
			Eydis_Darkbane,				//card
			"AT_131",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"Whenever <b>you</b> target this minion with a spell, deal 3 damage to a random enemy. HATES being called \"the wonder twins\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fallen_Hero;
		initCard(
			Fallen_Hero,				//card
			"AT_003",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"Your Hero Power deals 1 extra damage. And he can't get up.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fearsome_Doomguard;
		initCard(
			Fearsome_Doomguard,				//card
			"AT_020",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			8,				//hp
			"They were originally called Cuddleguards, but they were not inspiring the proper amount of fear.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Fencing_Coach;
		Fencing_Coach.fx[0] = true;			//Battlecry
		Fencing_Coach.fx2[0] = "nan:";
		initCard(
			Fencing_Coach,				//card
			"AT_115",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Battlecry:</b> The next time you use your Hero Power, it costs (2) less. Good fencers make good neighbors, right?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fist_of_Jaraxxus;
		Fist_of_Jaraxxus.fx[0] = true;			//Spell AKA battlecry
		Fist_of_Jaraxxus.fx2[0] = "nan:";
		initCard(
			Fist_of_Jaraxxus,				//card
			"AT_022",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			4,				//cost
			0,				//atk
			0,				//hp
			"When you play or discard this, deal $4 damage to a random enemy. * Not actually Jaraxxus' fist.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Fjola_Lightbane;
		initCard(
			Fjola_Lightbane,				//card
			"AT_129",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"Whenever <b>you</b> target this minion with a spell, gain <b>Divine Shield.</b> LOVES being called \"the wonder twins\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flame_Juggler;
		Flame_Juggler.fx[0] = true;			//Battlecry
		Flame_Juggler.fx2[0] = "nan:";
		initCard(
			Flame_Juggler,				//card
			"AT_094",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"<b>Battlecry:</b> Deal 1 damage to a random enemy. At first he liked juggling chain saws, but then he thought, \"Flames are better!  Because FIRE!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flame_Lance;
		Flame_Lance.fx[0] = true;			//Spell AKA battlecry
		Flame_Lance.fx2[0] = "nan:";
		initCard(
			Flame_Lance,				//card
			"AT_001",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			5,				//cost
			0,				//atk
			0,				//hp
			"Deal $8 damage to a minion. It's on the rack next to ice lance, acid lance, and English muffin lance.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Flash_Heal;
		Flash_Heal.fx[0] = true;			//Spell AKA battlecry
		Flash_Heal.fx2[0] = "nan:";
		initCard(
			Flash_Heal,				//card
			"AT_055",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Restore #5 Health. Flash!  Ahhhhhhh~",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frigid_Snobold;
		initCard(
			Frigid_Snobold,				//card
			"AT_093",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			6,				//hp
			"<b>Spell Damage +1</b> Ironically, the natural enemy of the snobold is THE CANDLE.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Frost_Giant;
		initCard(
			Frost_Giant,				//card
			"AT_120",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			10,				//cost
			8,				//atk
			8,				//hp
			"Costs (1) less for each time you used your Hero Power this game. Don't ask him about the beard.  JUST DON'T.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gadgetzan_Jouster;
		Gadgetzan_Jouster.fx[0] = true;			//Battlecry
		Gadgetzan_Jouster.fx2[0] = "nan:";
		initCard(
			Gadgetzan_Jouster,				//card
			"AT_133",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, gain +1/+1. It's not HER fault you didn't put a spinning saw blade on your horse.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Garrison_Commander;
		initCard(
			Garrison_Commander,				//card
			"AT_080",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			3,				//hp
			"You can use your Hero Power twice a turn. He'll never admit it, but he pushes you hard because he really cares about you.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Gormok_the_Impaler;
		Gormok_the_Impaler.fx[0] = true;			//Battlecry
		Gormok_the_Impaler.fx2[0] = "nan:";
		initCard(
			Gormok_the_Impaler,				//card
			"AT_122",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you have at least 4 other minions, deal 4 damage. Gormok has been giving impaling lessons in a small tent near the tournament grounds.  For only 25g you too could learn the fine art of impaling!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Grand_Crusader;
		Grand_Crusader.fx[0] = true;			//Battlecry
		Grand_Crusader.fx2[0] = "nan:";
		initCard(
			Grand_Crusader,				//card
			"AT_118",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Add a random Paladin card to your hand. A veteran of a number of crusades, she is a force for light and goodness.  Her latest crusade is against goblin telemarketers.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Healing_Totem;
		initCard(
			Healing_Totem,				//card
			"AT_132_SHAMANa",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			2,				//hp
			"At the end of your turn, restore 1 Health to all friendly minions.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Healing_Wave;
		Healing_Wave.fx[0] = true;			//Spell AKA battlecry
		Healing_Wave.fx2[0] = "nan:";
		initCard(
			Healing_Wave,				//card
			"AT_048",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Restore #7 Health. Reveal a minion in each deck. If yours costs more, Restore #14 instead. Favored by shaman who study the art of restoration and healing, this spell would feel smug, if it had feelings.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Holy_Champion;
		initCard(
			Holy_Champion,				//card
			"AT_011",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"Whenever a character is healed, gain +2 Attack. She really likes seeing people get better.  That's why she hurts them in the first place.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ice_Rager;
		initCard(
			Ice_Rager,				//card
			"AT_092",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			5,				//atk
			2,				//hp
			"He's a lot cooler than Magma Rager.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Icehowl;
		Icehowl.fx[1] = true;			//Charge
		initCard(
			Icehowl,				//card
			"AT_125",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			10,				//atk
			10,				//hp
			"<b>Charge</b>\nCan't attack heroes. This massive yeti just closes his eyes and charges at the nearest target.  The nearest Target is a couple blocks away and has sick deals on skateboards.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Injured_Kvaldir;
		Injured_Kvaldir.fx[0] = true;			//Battlecry
		Injured_Kvaldir.fx2[0] = "nan:";
		initCard(
			Injured_Kvaldir,				//card
			"AT_105",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			4,				//hp
			"<b>Battlecry:</b> Deal 3 damage to this minion. Don't worry.  With a little skin cream he's going to clear right up.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Justicar_Trueheart;
		Justicar_Trueheart.fx[0] = true;			//Battlecry
		Justicar_Trueheart.fx2[0] = "nan:";
		initCard(
			Justicar_Trueheart,				//card
			"AT_132",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			3,				//hp
			"<b>Battlecry:</b> Replace your starting Hero Power with a better one. It's like putting racing stripes and a giant spoiler on your hero power.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kings_Defender;
		Kings_Defender.fx[0] = true;			//Battlecry
		Kings_Defender.fx2[0] = "nan:";
		initCard(
			Kings_Defender,				//card
			"AT_065",				//id
			"Rare",				//rarity
			true,					//Collect
			"Weapon",				//type
			3,				//cost
			3,				//atk
			0,				//hp
			"<b>Battlecry</b>: If you have a minion with <b>Taunt</b>,  gain +1 Durability. \"King's Attacker\" is a shield.  Funny, huh?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kings_Elekk;
		Kings_Elekk.fx[0] = true;			//Battlecry
		Kings_Elekk.fx2[0] = "nan:";
		initCard(
			Kings_Elekk,				//card
			"AT_058",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, draw it. Elekk jousting is AWESOME.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Knight_of_the_Wild;
		initCard(
			Knight_of_the_Wild,				//card
			"AT_041",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			6,				//atk
			6,				//hp
			"Whenever you summon a Beast, reduce the Cost of this card by (1). He gets a discount on the tournament entry fee because he is his own horse.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kodorider;
		Kodorider.fx[12] = true;			//Inspire
		Kodorider.fx2[12] = "nan:";
		initCard(
			Kodorider,				//card
			"AT_099",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			3,				//atk
			5,				//hp
			"<b>Inspire:</b> Summon a 3/5 War Kodo. Someone called her a Rhinorider, and she's NOT HAPPY.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Kvaldir_Raider;
		Kvaldir_Raider.fx[12] = true;			//Inspire
		Kvaldir_Raider.fx2[12] = "nan:";
		initCard(
			Kvaldir_Raider,				//card
			"AT_119",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			4,				//hp
			"<b>Inspire:</b> Gain +2/+2. Coming soon... to a tuskarr village near you!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lance_Carrier;
		Lance_Carrier.fx[0] = true;			//Battlecry
		Lance_Carrier.fx2[0] = "nan:";
		initCard(
			Lance_Carrier,				//card
			"AT_084",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give a friendly minion +2 Attack. Lance Carrier is an obscure entry level position in orcish armies.  A mystery, since orcs don't generally use lances.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lights_Champion;
		Lights_Champion.fx[0] = true;			//Battlecry
		Lights_Champion.fx2[0] = "nan:";
		initCard(
			Lights_Champion,				//card
			"AT_106",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> <b>Silence</b> a Demon. When there's something strange (say, a gibbering demon) in your neighborhood, who are you going to call?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lion_Form;
		Lion_Form.fx[0] = true;			//Spell AKA battlecry
		Lion_Form.fx2[0] = "nan:";
		initCard(
			Lion_Form,				//card
			"AT_042a",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"<b>Charge</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Living_Roots;
		Living_Roots.fx[0] = true;			//Spell AKA battlecry
		Living_Roots.fx2[0] = "nan:";
		initCard(
			Living_Roots,				//card
			"AT_037",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"<b>Choose One</b> - Deal $2 damage; or Summon two 1/1 Saplings. 2 out of 2 saplings recommend that you summon the saplings.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lock_and_Load;
		Lock_and_Load.fx[0] = true;			//Spell AKA battlecry
		Lock_and_Load.fx2[0] = "nan:";
		initCard(
			Lock_and_Load,				//card
			"AT_061",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			2,				//cost
			0,				//atk
			0,				//hp
			"Each time you cast a spell this turn, add a random Hunter card to your hand. Rexxar narrowed his eyes, grabbed his machine gun, and said: \"It's go time.  Lock and load.\"\n\nThis card pays homage to that special moment.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Lowly_Squire;
		Lowly_Squire.fx[12] = true;			//Inspire
		Lowly_Squire.fx2[12] = "nan:";
		initCard(
			Lowly_Squire,				//card
			"AT_082",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			2,				//hp
			"<b>Inspire:</b> Gain +1 Attack. But not the lowliest!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Magnataur_Alpha;
		initCard(
			Magnataur_Alpha,				//card
			"AT_067",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			3,				//hp
			"Also damages the minions next to whomever\nhe attacks. Playing him also gets you into the Magnataur Beta.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Maiden_of_the_Lake;
		initCard(
			Maiden_of_the_Lake,				//card
			"AT_085",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			6,				//hp
			"Your Hero Power costs (1). Not a good basis for a system of government.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Master_Jouster;
		Master_Jouster.fx[0] = true;			//Battlecry
		Master_Jouster.fx2[0] = "nan:";
		initCard(
			Master_Jouster,				//card
			"AT_112",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			6,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, gain <b>Taunt</b> and <b>Divine Shield</b>. Needs just a few more ratings points to become Grandmaster Jouster.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Master_of_Ceremonies;
		Master_of_Ceremonies.fx[0] = true;			//Battlecry
		Master_of_Ceremonies.fx2[0] = "nan:";
		initCard(
			Master_of_Ceremonies,				//card
			"AT_117",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Battlecry:</b> If you have a minion with <b>Spell Damage</b>, gain +2/+2. Goes by \"MC ElfyElf\".",
			"",				//race
			""				//hero
			);
	}
	{
		Card Mogors_Champion;
		initCard(
			Mogors_Champion,				//card
			"AT_088",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			8,				//atk
			5,				//hp
			"50% chance to attack the wrong enemy. This champion has learned from the best.  Except for his target selection.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Muklas_Champion;
		Muklas_Champion.fx[12] = true;			//Inspire
		Muklas_Champion.fx2[12] = "nan:";
		initCard(
			Muklas_Champion,				//card
			"AT_090",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			3,				//hp
			"<b>Inspire:</b> Give your other minions +1/+1. An elegant gorilla, for a more civilized age.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Mulch;
		Mulch.fx[0] = true;			//Spell AKA battlecry
		Mulch.fx2[0] = "nan:";
		initCard(
			Mulch,				//card
			"AT_044",				//id
			"Epic",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Destroy a minion.\nAdd a random minion to your opponent's hand. Is this a noun or a verb?  We will never know.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Murloc_Knight;
		Murloc_Knight.fx[12] = true;			//Inspire
		Murloc_Knight.fx2[12] = "nan:";
		initCard(
			Murloc_Knight,				//card
			"AT_076",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			4,				//hp
			"<b>Inspire:</b> Summon a random Murloc. Hee hee!  Look at his cute little feet.",
			"Murloc",				//race
			""				//hero
			);
	}
	{
		Card Mysterious_Challenger;
		Mysterious_Challenger.fx[0] = true;			//Battlecry
		Mysterious_Challenger.fx2[0] = "nan:";
		initCard(
			Mysterious_Challenger,				//card
			"AT_079",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			6,				//hp
			"<b>Battlecry:</b> Put one of each <b>Secret</b> from your deck into the battlefield. He may sound surly and antisocial, but he's actually just really shy.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nerubian;
		initCard(
			Nerubian,				//card
			"AT_036t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			4,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Nexus_Champion_Saraad;
		Nexus_Champion_Saraad.fx[12] = true;			//Inspire
		Nexus_Champion_Saraad.fx2[12] = "nan:";
		initCard(
			Nexus_Champion_Saraad,				//card
			"AT_127",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			4,				//atk
			5,				//hp
			"<b>Inspire:</b> Add a random spell to your hand. The ethereals have their own jousting tournament, and Saraad is the reigning champion.  Also he won the ethereal hot dog eating contest.",
			"",				//race
			""				//hero
			);
	}
	{
		Card North_Sea_Kraken;
		North_Sea_Kraken.fx[0] = true;			//Battlecry
		North_Sea_Kraken.fx2[0] = "nan:";
		initCard(
			North_Sea_Kraken,				//card
			"AT_103",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			9,				//cost
			9,				//atk
			7,				//hp
			"<b>Battlecry:</b> Deal 4 damage. You have no idea how tired this guy is of being released.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Orgrimmar_Aspirant;
		Orgrimmar_Aspirant.fx[12] = true;			//Inspire
		Orgrimmar_Aspirant.fx2[12] = "nan:";
		initCard(
			Orgrimmar_Aspirant,				//card
			"AT_066",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Inspire:</b> Give your weapon +1 Attack. \"Four out of three orcs struggle with math.\" - Angry Zurge",
			"",				//race
			""				//hero
			);
	}
	{
		Card Panther_Form;
		Panther_Form.fx[0] = true;			//Spell AKA battlecry
		Panther_Form.fx2[0] = "nan:";
		initCard(
			Panther_Form,				//card
			"AT_042b",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			0,				//cost
			0,				//atk
			0,				//hp
			"+1/+1 and <b>Stealth</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Pit_Fighter;
		initCard(
			Pit_Fighter,				//card
			"AT_101",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			6,				//hp
			"What did the pits ever do to you?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Poisoned_Blade;
		initCard(
			Poisoned_Blade,				//card
			"AT_034",				//id
			"Epic",				//rarity
			true,					//Collect
			"Weapon",				//type
			4,				//cost
			1,				//atk
			0,				//hp
			"Your Hero Power gives this weapon +1 Attack instead of replacing it. How much more poisoned can a blade get?  The answer is a lot.  A lot more poisoned.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Poisoned_Dagger;
		initCard(
			Poisoned_Dagger,				//card
			"AT_132_ROGUEt",				//id
			"",				//rarity
			false,					//Collect
			"Weapon",				//type
			1,				//cost
			2,				//atk
			0,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Polymorph__Boar;
		Polymorph__Boar.fx[0] = true;			//Spell AKA battlecry
		Polymorph__Boar.fx2[0] = "nan:";
		initCard(
			Polymorph__Boar,				//card
			"AT_005",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Transform a minion into a 4/2 Boar with <b>Charge</b>. It's always Huffer.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Power_Word__Glory;
		Power_Word__Glory.fx[0] = true;			//Spell AKA battlecry
		Power_Word__Glory.fx2[0] = "nan:";
		initCard(
			Power_Word__Glory,				//card
			"AT_013",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			1,				//cost
			0,				//atk
			0,				//hp
			"Choose a minion. Whenever it attacks, restore 4 Health to\nyour hero. The promise of glory is a powerful tool to get minions to do your bidding.  Only slightly less powerful than the promise of an ice cream bar!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Powershot;
		Powershot.fx[0] = true;			//Spell AKA battlecry
		Powershot.fx2[0] = "nan:";
		initCard(
			Powershot,				//card
			"AT_056",				//id
			"Rare",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Deal $2 damage to a minion and the minions next to it. pow POW pow",
			"",				//race
			""				//hero
			);
	}
	{
		Card Ram_Wrangler;
		Ram_Wrangler.fx[0] = true;			//Battlecry
		Ram_Wrangler.fx2[0] = "nan:";
		initCard(
			Ram_Wrangler,				//card
			"AT_010",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			3,				//hp
			"<b>Battlecry:</b> If you have a Beast, summon a\nrandom Beast. Not getting trampled is really the trick here.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Recruiter;
		Recruiter.fx[12] = true;			//Inspire
		Recruiter.fx2[12] = "nan:";
		initCard(
			Recruiter,				//card
			"AT_113",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			4,				//hp
			"<b>Inspire:</b> Add a 2/2 Squire to your hand. Join the Argent Crusade!  We have attractive tabards and you get to carry really nice swords!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Refreshment_Vendor;
		Refreshment_Vendor.fx[0] = true;			//Battlecry
		Refreshment_Vendor.fx2[0] = "nan:";
		initCard(
			Refreshment_Vendor,				//card
			"AT_111",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			3,				//atk
			5,				//hp
			"<b>Battlecry:</b> Restore 4 Health to each hero. Menu:  Funnel cakes, carrots, popcorn, jormungar steaks.  It's hard serving a diverse clientele.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Rhonin;
		Rhonin.fx[2] = true;			//Deathrattle
		Rhonin.fx2[2] = "nan:";
		initCard(
			Rhonin,				//card
			"AT_009",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			8,				//cost
			7,				//atk
			7,				//hp
			"<b>Deathrattle:</b> Add 3 copies of Arcane Missiles to your hand. A masterless shamurai.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sabertooth_Lion;
		Sabertooth_Lion.fx[1] = true;			//Charge
		initCard(
			Sabertooth_Lion,				//card
			"AT_042t",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			2,				//atk
			1,				//hp
			"<b>Charge</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Sabertooth_Panther;
		Sabertooth_Panther.fx[9] = true;			//Stealth
		initCard(
			Sabertooth_Panther,				//card
			"AT_042t2",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Stealth</b>",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Saboteur;
		Saboteur.fx[0] = true;			//Battlecry
		Saboteur.fx2[0] = "nan:";
		initCard(
			Saboteur,				//card
			"AT_086",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> Your opponent's Hero Power costs (5) more next turn. Listen all y'all it's a saboteur!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sapling;
		initCard(
			Sapling,				//card
			"AT_037t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			1,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Savage_Combatant;
		Savage_Combatant.fx[12] = true;			//Inspire
		Savage_Combatant.fx2[12] = "nan:";
		initCard(
			Savage_Combatant,				//card
			"AT_039",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Inspire:</b> Give your hero\n+2 Attack this turn. Maybe if you whistle a tune it will soothe him.  Yeah...  Try that.",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Sea_Reaver;
		initCard(
			Sea_Reaver,				//card
			"AT_130",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			7,				//hp
			"When you draw this, deal 1 damage to your minions. A little better than Sea Minus Reaver.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Seal_of_Champions;
		Seal_of_Champions.fx[0] = true;			//Spell AKA battlecry
		Seal_of_Champions.fx2[0] = "nan:";
		initCard(
			Seal_of_Champions,				//card
			"AT_074",				//id
			"Common",				//rarity
			true,					//Collect
			"Spell",				//type
			3,				//cost
			0,				//atk
			0,				//hp
			"Give a minion\n+3 Attack and <b>Divine Shield</b>. \"Arf! Arf! Arf!\" - Seal of Champions",
			"",				//race
			""				//hero
			);
	}
	{
		Card Searing_Totem;
		initCard(
			Searing_Totem,				//card
			"AT_132_SHAMANb",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			1,				//atk
			1,				//hp
			"",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shado_Pan_Rider;
		initCard(
			Shado_Pan_Rider,				//card
			"AT_028",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			7,				//hp
			"<b>Combo:</b> Gain +3 Attack. He needed a break after that business in the Vale of Eternal Blossoms. Naturally, he chose to spend his vacation in an icy snowscape killing monsters.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shadowfiend;
		initCard(
			Shadowfiend,				//card
			"AT_014",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"Whenever you draw a card, reduce its Cost by (1). Hopes to be promoted to \"Shadowfriend\" someday.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Shady_Dealer;
		Shady_Dealer.fx[0] = true;			//Battlecry
		Shady_Dealer.fx2[0] = "nan:";
		initCard(
			Shady_Dealer,				//card
			"AT_032",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			3,				//hp
			"<b>Battlecry:</b> If you have a Pirate, gain +1/+1. I have great deal for you... for 4 damage to your face!",
			"",				//race
			""				//hero
			);
	}
	{
		Card Sideshow_Spelleater;
		Sideshow_Spelleater.fx[0] = true;			//Battlecry
		Sideshow_Spelleater.fx2[0] = "nan:";
		initCard(
			Sideshow_Spelleater,				//card
			"AT_098",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			6,				//atk
			5,				//hp
			"<b>Battlecry:</b> Copy your opponent's Hero Power. Hey!  Let me try that...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silent_Knight;
		Silent_Knight.fx[3] = true;			//Divine Shield
		Silent_Knight.fx[9] = true;			//Stealth
		initCard(
			Silent_Knight,				//card
			"AT_095",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			2,				//hp
			"<b>Stealth</b>\n<b>Divine Shield</b> He used to be a librarian.  Old habits die hard.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Silver_Hand_Regent;
		Silver_Hand_Regent.fx[12] = true;			//Inspire
		Silver_Hand_Regent.fx2[12] = "nan:";
		initCard(
			Silver_Hand_Regent,				//card
			"AT_100",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			3,				//hp
			"<b>Inspire:</b> Summon a 1/1 Silver Hand Recruit. The Silver Hand is the best paladin organization.  The Argent Crusaders are super jealous.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Skycapn_Kragg;
		Skycapn_Kragg.fx[1] = true;			//Charge
		initCard(
			Skycapn_Kragg,				//card
			"AT_070",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			7,				//cost
			4,				//atk
			6,				//hp
			"<b>Charrrrrge</b>\nCosts (1) less for each friendly Pirate. What's more boss than riding a parrot with a jawbone for a shoulderpad while wielding a giant hook-lance-thing and wearing a pirate hat?  NOTHING.",
			"Pirate",				//race
			""				//hero
			);
	}
	{
		Card Sparring_Partner;
		Sparring_Partner.fx[0] = true;			//Battlecry
		Sparring_Partner.fx2[0] = "nan:";
		Sparring_Partner.fx[10] = true;			//Taunt
		initCard(
			Sparring_Partner,				//card
			"AT_069",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Taunt</b>\n<b>Battlecry:</b> Give a\nminion <b>Taunt</b>. Come at me, bro.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spawn_of_Shadows;
		Spawn_of_Shadows.fx[12] = true;			//Inspire
		Spawn_of_Shadows.fx2[12] = "nan:";
		initCard(
			Spawn_of_Shadows,				//card
			"AT_012",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			5,				//atk
			4,				//hp
			"<b>Inspire:</b> Deal 4 damage to each hero. What did you expect to happen?  He's a Spawn.  Of Shadows.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Spellslinger;
		Spellslinger.fx[0] = true;			//Battlecry
		Spellslinger.fx2[0] = "nan:";
		initCard(
			Spellslinger,				//card
			"AT_007",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			4,				//hp
			"<b>Battlecry:</b> Add a random spell to each player's hand. Does he sling spells, or do his spells linger about.  Who can say?",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stablemaster;
		Stablemaster.fx[0] = true;			//Battlecry
		Stablemaster.fx2[0] = "nan:";
		initCard(
			Stablemaster,				//card
			"AT_057",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			4,				//atk
			2,				//hp
			"<b>Battlecry:</b> Give a friendly Beast <b>Immune</b> this turn. Takes way better care of her pets than her brother, Unstablemaster.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Stoneclaw_Totem;
		initCard(
			Stoneclaw_Totem,				//card
			"AT_132_SHAMANc",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			2,				//hp
			"<b>Taunt</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card The_Mistcaller;
		The_Mistcaller.fx[0] = true;			//Battlecry
		The_Mistcaller.fx2[0] = "nan:";
		initCard(
			The_Mistcaller,				//card
			"AT_054",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Give all minions in your hand and deck +1/+1. Calling the mist doesn't sound all that great.  \"Ooooh, it is slightly damp now!\"",
			"",				//race
			""				//hero
			);
	}
	{
		Card The_Skeleton_Knight;
		The_Skeleton_Knight.fx[2] = true;			//Deathrattle
		The_Skeleton_Knight.fx2[2] = "nan:";
		initCard(
			The_Skeleton_Knight,				//card
			"AT_128",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			7,				//atk
			4,				//hp
			"<b>Deathrattle:</b> Reveal a minion in each deck. If yours costs more, return this to your hand. Apparently it really was just a flesh wound.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Thunder_Bluff_Valiant;
		Thunder_Bluff_Valiant.fx[12] = true;			//Inspire
		Thunder_Bluff_Valiant.fx2[12] = "nan:";
		initCard(
			Thunder_Bluff_Valiant,				//card
			"AT_049",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			6,				//hp
			"<b>Inspire:</b> Give your Totems +2 Attack. Allowing totems to attack is not cheating.  I mean, there isn't anything in the rule books about it.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tiny_Knight_of_Evil;
		initCard(
			Tiny_Knight_of_Evil,				//card
			"AT_021",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"Whenever you discard a card, gain +1/+1. \"No, no, no. I asked for a tiny JESTER of evil.\"",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Totem_Golem;
		initCard(
			Totem_Golem,				//card
			"AT_052",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			4,				//hp
			"<b>Overload: (1)</b> What happens when you glue a buncha totems together.",
			"Totem",				//race
			""				//hero
			);
	}
	{
		Card Tournament_Attendee;
		Tournament_Attendee.fx[10] = true;			//Taunt
		initCard(
			Tournament_Attendee,				//card
			"AT_097",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			1,				//cost
			2,				//atk
			1,				//hp
			"<b>Taunt</b> He was so excited to get season tickets to this year's Grand Tournament.  He normally doesn't get them at first and has to buy them from Ogre scalpers.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tournament_Medic;
		Tournament_Medic.fx[12] = true;			//Inspire
		Tournament_Medic.fx2[12] = "nan:";
		initCard(
			Tournament_Medic,				//card
			"AT_091",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			1,				//atk
			8,				//hp
			"<b>Inspire:</b> Restore 2 Health to your hero. The medic tournament is less entertaining than the Grand Tournament.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tuskarr_Jouster;
		Tuskarr_Jouster.fx[0] = true;			//Battlecry
		Tuskarr_Jouster.fx2[0] = "nan:";
		initCard(
			Tuskarr_Jouster,				//card
			"AT_104",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			5,				//cost
			5,				//atk
			5,				//hp
			"<b>Battlecry:</b> Reveal a minion in each deck. If yours costs more, restore 7 Health to your hero. Just could not be talked out of using his turtle for the joust...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Tuskarr_Totemic;
		Tuskarr_Totemic.fx[0] = true;			//Battlecry
		Tuskarr_Totemic.fx2[0] = "nan:";
		initCard(
			Tuskarr_Totemic,				//card
			"AT_046",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			3,				//atk
			2,				//hp
			"<b>Battlecry:</b> Summon ANY random Totem. Turns out the tuskarr aren't real choosy about their totems.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Twilight_Guardian;
		Twilight_Guardian.fx[0] = true;			//Battlecry
		Twilight_Guardian.fx2[0] = "nan:";
		initCard(
			Twilight_Guardian,				//card
			"AT_017",				//id
			"Epic",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			2,				//atk
			6,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, gain +1 Attack and <b>Taunt</b>. A result of magical experiments carried out by the Black Dragonflight, it's not his fault that he's a vicious killer.",
			"Dragon",				//race
			""				//hero
			);
	}
	{
		Card Undercity_Valiant;
		initCard(
			Undercity_Valiant,				//card
			"AT_030",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			3,				//atk
			2,				//hp
			"<b>Combo:</b> Deal 1 damage. Almost went to play for Stormwind before signing with Undercity.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Varian_Wrynn;
		Varian_Wrynn.fx[0] = true;			//Battlecry
		Varian_Wrynn.fx2[0] = "nan:";
		initCard(
			Varian_Wrynn,				//card
			"AT_072",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			10,				//cost
			7,				//atk
			7,				//hp
			"<b>Battlecry:</b> Draw 3 cards.\nPut any minions you drew directly into the battlefield. Leader of the Alliance!  Father of Anduin!  Also he likes to play Arena, and he averages 12 wins.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Void_Crusher;
		Void_Crusher.fx[12] = true;			//Inspire
		Void_Crusher.fx2[12] = "nan:";
		initCard(
			Void_Crusher,				//card
			"AT_023",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			5,				//atk
			4,				//hp
			"<b>Inspire:</b> Destroy a random minion for each player. We like to call him \"Wesley\".",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card War_Kodo;
		initCard(
			War_Kodo,				//card
			"AT_099t",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			5,				//cost
			3,				//atk
			5,				//hp
			"",
			"Beast",				//race
			""				//hero
			);
	}
	{
		Card Warhorse_Trainer;
		initCard(
			Warhorse_Trainer,				//card
			"AT_075",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			3,				//cost
			2,				//atk
			4,				//hp
			"Your Silver Hand Recruits have +1 Attack. He doesn't even get Sundays off.  Every day he's hostling.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wildwalker;
		Wildwalker.fx[0] = true;			//Battlecry
		Wildwalker.fx2[0] = "nan:";
		initCard(
			Wildwalker,				//card
			"AT_040",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			4,				//cost
			4,				//atk
			4,				//hp
			"<b>Battlecry:</b> Give a friendly Beast +3 Health. She was born to be something.  She is just not quite sure what yet...",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wilfred_Fizzlebang;
		initCard(
			Wilfred_Fizzlebang,				//card
			"AT_027",				//id
			"Legendary",				//rarity
			true,					//Collect
			"Minion",				//type
			6,				//cost
			4,				//atk
			4,				//hp
			"Cards you draw from your Hero Power cost (0). He can summon anything, even a FEARSOME DOOMGUARD*.\n\n*He's pretty sure this is going to work out.",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wrath_of_Air_Totem;
		initCard(
			Wrath_of_Air_Totem,				//card
			"AT_132_SHAMANd",				//id
			"",				//rarity
			false,					//Collect
			"Minion",				//type
			0,				//cost
			0,				//atk
			2,				//hp
			"<b>Spell Damage +1</b>",
			"",				//race
			""				//hero
			);
	}
	{
		Card Wrathguard;
		initCard(
			Wrathguard,				//card
			"AT_026",				//id
			"Common",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			4,				//atk
			3,				//hp
			"Whenever this minion takes damage, also deal that amount to your hero. After playing against 5 Annoy-O-Trons, any normal guard will become a Wrathguard.",
			"Demon",				//race
			""				//hero
			);
	}
	{
		Card Wyrmrest_Agent;
		Wyrmrest_Agent.fx[0] = true;			//Battlecry
		Wyrmrest_Agent.fx2[0] = "nan:";
		initCard(
			Wyrmrest_Agent,				//card
			"AT_116",				//id
			"Rare",				//rarity
			true,					//Collect
			"Minion",				//type
			2,				//cost
			1,				//atk
			4,				//hp
			"<b>Battlecry:</b> If you're holding a Dragon, gain +1 Attack and <b>Taunt</b>. Keeping tabs on the Grand Tournament is priority #1 for the five mighty Dragonflights!",
			"",				//race
			""				//hero
			);
	}
}