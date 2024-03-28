#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, std::string> u = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"},
    };

    auto print_key_value = [](const auto &key, const auto &value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    for (const std::pair<const std::string, std::string> &n : u)
    {
        print_key_value(n.first, n.second);
    }

    std::cout << "--------------------------------------------------------\n";

    for (const auto &[key, value] : u)
        print_key_value(key, value);

    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    std::cout << "Count of black is: " << u.count("black") << '\n';
    std::cout << "Count of black is: " << u.count("black") << '\n';

    std::cout << "Output values by key:\n"
              << "The HEX color RED is:[" << u["RED"] << "]\n"
              << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n"
              << "The HEX of color BLACK is:[" << u["black"] << "]\n\n"; // 不存在的值默认是空

    std::cout << "Count of black is: " << u.count("black") << '\n';
    std::cout << "Count of RED is: " << u.count("RED") << '\n';

    for (const auto &n : u)
        print_key_value(n.first, n.second);

    return 0;
}
