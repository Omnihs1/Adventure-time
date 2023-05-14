#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType {Antidote, PhoenixDownI, PhoenixDownII, PhoenixDownIII, PhoenixDownIV};

#Lam sau
class BaseItem {
public:
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

#Lam sau
class BaseBag {
protected:
    BaseKnight * knight;

public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
#Linh
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;

public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

#Linh
class PaladinKnight :: public BaseKnight{
protected:
    knightBaseDamage = 0.06
public:
    fight //
};
class LancelotKnight :: public BaseKnight{
protected:
    knightBaseDamage = 0.05 
public:
    fight //   
};
class DragonKnight :: public BaseKnight{
protected:
    knightBaseDamage = 0.075
public:
    fight //
};
class NormalKnight :: public BaseKnight{
protected:

public:
    fight //
    
};
#Linh
class ArmyKnights {
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};


#Linh
class Events {
public:
    int count() const;
    int get(int i) const;
};
#Linh
class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
    void printResult(bool result);
};

#Son
class BaseOpponent{
protected:
    int baseDamage; 
    int levelO;
    int event_id;
    int i;
    int gil;
    bool result = false;
public:
    BaseOpponent(int baseDamage, int event_id, int i, int gil);
    ~BaseOpponent();
    virtual void attack(ArmyKnight *);
    virtual void result(ArmyKnight *);
};
class MadBear :: public BaseOpponent{
protected:
    int baseDamage = 10;
    int event_id = 1;   
    int gil = 100;
public:
    MadBear(int i) : BaseOpponent(10, 1, i, 100){}
};
class Bandit :: public BaseOpponent{
protected:
    int baseDamage = 15;
    int event_id = 2;
    int gil = 150;
public:
    Bandit(int i) : BaseOpponent(15, 2, i, 150){}
};
class LordLupin :: public BaseOpponent{
protected:
    int baseDamage = 45;
    int event_id = 3;
    int gil = 450;
public:
    LordLupin(int i) : BaseOpponent(45, 3, i, 450){}
};
class Elf :: public BaseOpponent{
protected:
    int baseDamage = 75;
    int event_id = 4;
    int gil = 750;
public:
    Elf(int i) : BaseOpponent(75, 4, i, 750){}
};
class Troll :: public BaseOpponent{
protected:
    int baseDamage = 95;
    int event_id = 5;
    int gil = 800;
    int levelO;
public:
};
class Tornbery :: public BaseOpponent{
protected:
    int baseDamage = 120;
    int event_id = 6;
    bool poisoned = false;
public:
    void result(ArmyKnight *) override;
};
class QueenOfCards :: public BaseOpponent{
protected:
    int baseDamage = 150;
    int event_id = 7;
public:
    void result(ArmyKnight *) override;
};
class NinaDeRings{
public:
    void shopping(ArmyKnight *);
};
class DurianGarden{
public:
    void result(ArmyKnight *);
};
class OmegaWeapon{
int:
    bool static encountered = false;
public:
    void result(ArmyKnight *);
};
class Hades{
int:
    bool static encountered = false;
public:
    void result(ArmyKnight *);
};
class Ultimetica{
int:
    int hp = 5000;
    bool fight = false;
    bool result_final = false;
public:
    void result(ArmyKnights *);
}



#endif // __KNIGHT2_H__