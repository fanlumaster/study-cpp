#include <istream>
#include <string>

namespace Chrono
{
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

class Date
{
  public: // 公共接口
    class Bad_date
    {
    }; // 异常类

    explicit Date(int dd = {}, Month mm = {}, int yy = {}); // 表示选择默认值
    // 非修改性函数，用于查询 Date：
    int day() const;
    Month month() const;
    int year() const;

    std::string string_rep() const;         // 字符串表示
    void char_rep(char s[], int max) const; // C 风格字符串表示

    // 修改性函数，用于改变 Date：
    Date &add_year(int n);  // 增加 n 年
    Date &add_month(int n); // 增加 n 个月
  private:
    bool is_valid(); // 检查 Date 是否表示一个日期
    int d, m, y;
};

bool is_date(int d, Month m, int y); // 对合法日期返回 true
bool is_leapyear(int y);             // 若 y 是闰年返回 true

bool operator==(const Date &a, const Date &b);
bool operator!=(const Date &a, const Date &b);

const Date &default_date(); // 默认日期

std::ostream &operator<<(std::ostream &os, const Date &d); // 将 d 打印到 os
std::istream &operator>>(std::istream &os, Date &d);       // 从 is 读取 Date 存入 d

Date::Date(int dd, Month mm, int yy) : d{dd}, m{(int)mm}, y{yy}
{
    if (y == 0)
        y = default_date().year();
    if (m == (int)Month{})
        m = (int)default_date().month();
}
} // namespace Chrono
