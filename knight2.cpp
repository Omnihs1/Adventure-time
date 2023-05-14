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
BaseOpponent::BaseOpponent(int baseDamage, int event_id, int i, int gil) {
    this->baseDamage = baseDamage;
    this->event_id = event_id;
    this->i = i;
    this->levelO = (i + event_id) % 10 + 1;
    this->gil = gil;
}
void BaseOpponent::attack(ArmyKnight * armyKnight){
    if(armyKnight.count() == 0){
        return;
    }
    else{
        BaseKnight* last_knight = new BaseKnight();
        BaseKnight* last_knight = armyKnight.lastKnight();
        while(result != true){
            if(last_knight->level > this->levelO || last_knight->level == this->levelO){this->result = true; return;}
            else{last_knight->hp -= this->baseDamage * (this->levelO - last_knight->level)}
            if(last_knight.checkInfo() == true){
                last_knight.reborn();
            }
            else{
                last_knight = last_knight->next;
            }
        }
    }
}
void BaseOpponent::result(ArmyKnight * armyKnight){
    if(this->result == true){
        BaseKnight* last_knight = new BaseKnight();
        last_knight = armyKnight.lastKnight();
        last_knight->gil += this->gil;
        while(last_knight->gil > 999){
            gil_temp = last_knight->gil - 999;
            last_knight = last_knight->next;
            last_knight->gil += gil_temp;
        }
    }
    else{
    }
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class Tornbery * * */
void Tornbery::result(ArmyKnight* armyKnight){
    BaseKnight* last_knight = new BaseKnight();
    last_knight = armyKnight.lastKnight();
    if(this->result == true){
        if(last_knight->level == 10){
        }
        else{
            last_knight->level += 1;
        }
    }
    else{
        this->poisoned = true;
        while(last_knight != NULL){
            if(last_knight->antidote > 0) {last_knight.resume(); return;}
            last_knight->hp -= 10;
            if(last_knight->hp < 0){
                if(last_knight.checkInfo() == true){
                    last_knight.reborn();
                }
                else{
                    last_knight = last_knight->next;
                }
            }
        }
    }
}
/* * * END implementation of class Tornbery * * */

/* * * BEGIN implementation of class Queen of Cards, * * */
void QueenOfCards::result(ArmyKnights * armyKnight){
    BaseKnight* last_knight = new BaseKnight();
    last_knight = armyKnight.lastKnight();
    if(this->result == true){
        last_knight->gil *= 2;
        while(last_knight->gil > 999 && last_knight != NULL){
            gil_temp = last_knight->gil - 999;
            last_knight = last_knight->next;
            last_knight->gil += gil_temp;
        }
    }
    else{
        last_knight->gil /= 2;
    }
}
/* * * END implementation of class Queen of Cards, * * */

/* * * BEGIN implementation of class NinaDeRings, * * */
void NinaDeRings::shopping(ArmyKnights * armyKnight){
    BaseKnight* last_knight = new BaseKnight();
    last_knight = armyKnight.lastKnight();
    if(last_knight->gil < 50){
        return; 
    }
    else{
        if(last_knight->hp < (last_knight->maxhp / 3)){
            last_knight->gil -= 50;
            last_knight->hp += last_knight->maxhp / 5;
        }
    }
}
/* * * END implementation of class NinaDeRings, * * */

/* * * BEGIN implementation of class DurianGarden, * * */
void DurianGarden::result(ArmyKnights * armyKnight){
    BaseKnight* last_knight = new BaseKnight();
    last_knight = armyKnight.lastKnight();
    while(last_knight != NULL){
        last_knight->hp = last_knight->maxhp;
        last_knight = last_knight->next;
    }
}
/* * * END implementation of class DurianGarden, * * */

/* * * BEGIN implementation of class OmegaWeapon, * * */
void OmegaWeapon::result(ArmyKnights * armyKnight){
    if(this->encountered == true){return;}
    else{
        while(armyKnight.count() > 0){
            BaseKnight* last_knight = new BaseKnight();
            last_knight = armyKnight.lastKnight();
            if((last_knight->level == 10 && last_knight->hp == last_knight->maxhp) || (last_knight->knightType == PALADIN)){
                this->encountered = true;
                while(last_knight != NULL){
                    last_knight->level = 10;
                    last_knight->gil = 999;
                    last_knight = last_knight->next;
                }
            }
            else{
                armyKnight.last_knight() = armyKnight.lastKnight()->next;
            }
        }
    }
}
/* * * END implementation of class OmegaWeapon, * * */

/* * * BEGIN implementation of class Hades, * * */
void Hades::result(ArmyKnights * armyKnight) {
    while(armyKnight.count() > 0){
        BaseKnight* last_knight = new BaseKnight();
        last_knight = armyKnight.lastKnight();
        if(last_knight->level == 10 || (last_knight->knightType == PALADIN && last_knight->level > 8)){
            this->encountered = true;
            armyKnight.hasPaladinShield() = true;
        }
        else{
            armyKnight.last_knight() = armyKnight.lastKnight()->next;
        }
    }
}
/* * * END implementation of class Hades, * * */

/* * * BEGIN implementation of class Ultimetica, * * */
void Ultimetica::result(ArmyKnights * armyKnight) {
    if(armyKnight.hasExcaliburSword() == true ||
        (armyKnight.hasGuinevereHair() == true &&
        armyKnight.hasLancelotSpear() == true &&
        armyKnight.hasPaladinShield() == true)){
            this->fight = true;
        while(armyKnight.count() > 0){
            BaseKnight* last_knight = new BaseKnight();
            last_knight = armyKnight.lastKnight();
            if(last_knight->knightType == PALADIN || last_knight->knightType == LANCELOT || 
                last_knight->knightType == DRAGON){
                int damage = this->hp * last_knight->level * last_knight->knightBaseDamage;
                this->hp -= damage;
                if(this->hp < 0){
                    this->result_final = true;
                    return;
                }
                else{
                    last_knight = last_knight->next;
                }
            }
            else{
                armyKnight.last_knight() = armyKnight.lastKnight()->next;
            }
        }
    }
    else{
        this->result_final = false;
        return;
    }
}
/* * * END implementation of class Ultimetica, * * */

/* * * BEGIN implementation of class Events, * * */
Events::Events(const string & file_events){
    ifstream inputFile(file_events);
    if (inputFile.is_open()) {
        string line1, line2;
        getLine(inputFile, line1);
        this->size = (int) line1;
        getLine(inputFile, line2);
        int value;
        stringstream ss(line2);
        while(ss >> value){
            this->events_list.push_back(value);    
        }
        inputFile.close();
    }
    else {
        cout << "Failed to open file: " << file_events << endl;
    }
}
Events::count(){
    return this->events_list.size();
}
Events::get(int i){
    return this->events_list[i];
}
/* * * END implementation of class Events, * * */






