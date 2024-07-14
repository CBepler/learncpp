#include "Player.h"
#include "Random.h"
#include <string_view>

Player::Player(std::string_view name, int itemCount)
    : m_name {name}
    , m_gold {Random::get(s_minStartingGold, s_maxStartingGold)}
{
    m_inventory.resize(itemCount);
}

std::string_view Player::name() const {
    return m_name;
}

int Player::gold() const {
    return m_gold;
}

bool Player::spendGold(int amount) {
    if(m_gold - amount < 0) {return false;}
    m_gold -= amount;
    return true;
}

const std::vector<int>& Player::inventory() const {
    return m_inventory;
}

void Player::addToInventory(int index) {
    m_inventory[index] += 1;
}
