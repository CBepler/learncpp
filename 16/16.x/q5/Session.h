#include <string>
#include <string_view>
#include <vector>

class Session {
private:
    std::string m_ans {};
    std::vector<bool> m_guesses;
    int m_lives {6};
    std::string m_lifeView {"++++++"};
public:
    Session(std::string_view ans)
        : m_ans {ans}
        , m_guesses (26)
    {}

    bool displayState() const;
    void getInput();
};