#include <iostream>
#include <string>
#include <string_view>


struct Monster {

    enum Type {
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
    };

    Type type {};
    std::string_view name {};
    int health {};
};

std::string_view getMonsterType(Monster::Type monsterType) {
    switch(monsterType) {
        case Monster::ogre: return "Ogre";
        case Monster::dragon: return "Dragon";
        case Monster::orc: return "Orc";
        case Monster::giantSpider: return "Giant Spider";
        case Monster::slime: return "Slime";
        default: return "invalid";
    }
}

std::ostream& operator<<(std::ostream& out, Monster::Type monsterType) {
    return out << getMonsterType(monsterType);
}

void printMonster(const Monster& monster) {
    std::cout << "This " << monster.type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
    Monster ogre {Monster::ogre, "Torg", 145};
    printMonster(ogre);
    Monster slime {Monster::slime, "Blurp", 23};
    printMonster(slime);
    return 0;
}
