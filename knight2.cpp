#include "knight2.h"

/* * * BEGIN implementation of class BaseItem * * */
bool BaseItem::canUse(BaseKnight *knight ){
    
}
bool BaseItem::use(BaseKnight *knight){

}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag::insertFirst(BaseItem *item){
    
}
BaseItem* BaseBag::get(ItemType itemType){
    if (knight->knightType == DRAGON)
}
string BaseBag::toString() const {
    string s("");
    s += "Bag[count=";
    
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    BaseKnight* knight = new BaseKnight();
    knight->id = id;
    knight->hp = maxhp;
    knight->maxhp = maxhp;
    knight->level = level;
    knight->gil = gil;
    knight->antidote = antidote;
    return knight;
}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights ArmyKnights::
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    // Release
}
void KnightAdventure::loadArmyKnights(const string &){
    ArmyKnights* armyKnights_temp(const string &)
    armyKnights = armyKnights_temp
}
void KnightAdventure::loadEvents(const string &){
    Events* events_temp(const string &)
    events = events_temp
}
void KnightAdventure::run(){

}
void KnightAdventure::printResult(bool result){

}
/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class BaseOpponent * * */
void BaseOpponent::get(Events* events){
    levelO = (events.get() + event_id) % 10 + 1
}
virtual void BaseOpponent::attack(ArmyKnight * ){
    last_knight = new BaseKnight();
    last_knight = ArmyKnight.lastKnight();
    while (last_knight != NULL){
        if(last_knight->level > levelO || last_knight->level == levelO){
            result = true;
            break;
        }
        else if (last_knight->hp > 0){
            last_knight->hp -= baseDamage*(levelO - last_knight->level)
        }
        if (last_knight->hp < 0 || last_knight->hp == 0){
            if(last_knight->revised == True){
                // last_knight = BaseKnight.revised(last_knight) 
            }
            else{
                last_knight = last_knight->next;
            }
        }
    }
}
virtual void BaseOpponent::result(ArmyKnight *){
    if(result == true){
        last_knight = new BaseKnight();
        last_knight = ArmyKnight.lastKnight();
        last_knight->gil += gil;
    }
    else{

    }
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class Tornbery * * */
void Tornbery::result(ArmyKnight * ) override {
    last_knight = new BaseKnight();
    last_knight = ArmyKnight.lastKnight();
    if(result == false){
        poisoned = true;
        // roi do
        // doc tinh
        while(last_knight != NULL){
            last_knight->hp -= 10;
            if(last_knight->hp < 0){
                if(last_knight->revised == True){
                    // last_knight = BaseKnight.revised(last_knight) 
                }
                else{
                    last_knight = last_knight->next;
                }
            }
        }
    }
    else{
        if(last_knight->level == 10){
        }
        else{
            last_knight->level += 1;
        }
    }
}
/* * * END implementation of class Tornbery * * */

/* * * BEGIN implementation of class Queen of Cards, * * */
void QueenOfCards::result(ArmyKnights *) override {
    last_knight = new BaseKnight();
    last_knight = ArmyKnight.lastKnight();
    if(result == false){
        last_knight->gil /= 2;         
    }
    else{
        int i = 1;
        int gil_temp;
        while(last_knight->gil < 999 && last_knight != NULL){
            if(i == 1){
                last_knight->gil *= 2;
                if(last_knight->gil > 999){
                    gil_temp = last_knight->gil - 999;
                    last_knight = last_knight->next;
                    i++;
                }
                else{
                    break;
                }
            }
            else{
                last_knight->gil += gil_temp;
                if(last_knight->gil > 999){
                    gil_temp = last_knight->gil - 999;
                    last_knight = last_knight->next;
                }
            }
        }
    }
}
/* * * END implementation of class Queen of Cards, * * */







