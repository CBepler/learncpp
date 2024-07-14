#include <string>
#include <vector>
#include <string_view>

class Player {
private:
    static constexpr int s_minStartingGold {80};
    static constexpr int s_maxStartingGold {120};

    std::string m_name {};
    std::vector<int> m_inventory {};
    int m_gold {};

public:
    Player(std::string_view name, int itemCount);
    std::string_view name() const;
    int gold() const;
    bool spendGold(int amount);
    const std::vector<int>& inventory() const;
    void addToInventory(int index);
};