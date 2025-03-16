#ifndef COLORS_HPP
#define COLORS_HPP

#include <iostream>
#include <format>
#include <string>
#include <print>

namespace Color {
    static constexpr int Reset{0};
    static constexpr int Red{31};
    static constexpr int Green{32};
    static constexpr int Yellow{33};
    static constexpr int Blue{34};
    static constexpr int Magenta{35};
    static constexpr int Cyan{36};
    static constexpr int White{37};
}

struct SetColor {
    int code;
    bool b;

    constexpr SetColor(int c, bool b = false) : code(c), b(b) {}

    std::string escape() const {
        return "\033[" + std::string(b ? "1;" : "") + std::to_string(code) + "m";
    }

    constexpr SetColor bold() const { return SetColor(code, true); }
    constexpr SetColor bright() const { return SetColor(code + 60, b); }
    static constexpr std::string Reset() { return "\033[0m"; }
    static constexpr std::string Clear() { return "\033[2J\033[1H"; }
};

struct printChar {
    int number;
    char chr;
    SetColor color;

};

template <>
struct std::formatter<printChar> : std::formatter<std::string> {
    auto format(const printChar& p, auto& ctx) const {
        return std::formatter<std::string>::format(
            std::format("{}{}{}", p.color.escape(), std::string(p.number, p.chr), SetColor::Reset()),
            ctx);
    }
};

#endif //COLORS_HPP
