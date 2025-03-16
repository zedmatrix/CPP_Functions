#ifndef LOCATE_HPP
#define LOCATE_HPP

struct locate {
    int y, x;
};

std::ostream& operator<<(std::ostream& os, const locate& p) {
    return os << std::format("\033[{};{}H", p.y, p.x);
}

template <>
struct std::formatter<locate> : std::formatter<std::string_view> {
    auto format(const locate& p, auto& ctx) const {
        return std::formatter<std::string_view>::format(
            std::format("\033[{};{}H", p.y, p.x), ctx);
    }
};

#endif //LOCATE_HPP
