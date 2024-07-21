#include <string>
#include <vector>
#include <algorithm>
#include <string_view>

class GradeMap {
    struct StudentGrade {
        std::string name {};
        char grade {'F'};
    };
private:
    std::vector<StudentGrade> m_map {};
public:
    GradeMap(){}

    char& operator[] (std::string_view index);
};

char& GradeMap::operator[] (std::string_view index) {
    auto pos {std::lower_bound(m_map.begin(), m_map.end(), index, [&](const StudentGrade& s, std::string_view name) {
        return name < s.name;
    })};
    // auto pos {std::find_if(m_map.begin(), m_map.end(), [&](const StudentGrade& student) {
    //     return student.name == index;
    // })};
    if(pos == m_map.end() || pos->name != index) {
        pos = m_map.insert(pos, StudentGrade {std::string{index}});
    }
    return pos->grade;
}