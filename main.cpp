#include "colors.hpp"
#include "locate.hpp"
#include "screen.hpp"
#include "inkey.hpp"

int main() {
    // Clear Screen from colors.hpp
    std::cout << SetColor::Clear();

    // Get Screen/Terminal Resolution
    ScreenSize screen = screenRes();
    std::string text = std::format("\n\t Screen Width:{} Screen Height:{}",screen.width, screen.height);


    std::println("{}", printChar(screen.width, '*', SetColor(Color::Green).bright()));

    std::println("{}Green Text", SetColor(Color::Green).bold().bright().escape());

    text = std::format("{}{} Screen Size ({}x{})",locate(4, 1), SetColor(Color::Yellow).bright().escape(), screen.width, screen.height);
    std::println("{}{}", text, SetColor::Reset());

    std::println("\t{}", printChar(20, '*', SetColor(Color::Cyan).bright()));
    std::println("{}{} Press Any Key To Continue{}", locate(6, 20), SetColor(Color::White).bold().escape(), SetColor::Reset());

    getch();

    return 0;
}
