#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string tblName = "fullpinyinsimple";
    std::string pinyin = "nihc";
    std::string hanValue = "拟好";
    std::string insertSQL = "insert into " + tblName + " (key, value, weight) values ('" + pinyin + "', '" + hanValue + "', 0)";
    std::string querySQL = "select count(*) from " + tblName + " where key = '" + pinyin + "' and value = '" + hanValue + "'";
    std::cout << querySQL << '\n';
    std::cout << insertSQL << '\n';
    return 0;
}