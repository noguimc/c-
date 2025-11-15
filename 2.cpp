#include <iostream>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某个月份的天数
int getDaysInMonth(int month, int year) {
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	} else {
		return 31;
	}
}

int main() {
	int a, end_year, end_month;
	cout << "请输入起始月份a (1-12): ";
	cin >> a;
	cout << "请输入结束年份和月份 (年 月): ";
	cin >> end_year >> end_month;
	
	int start_year = 1900;
	int current_year = start_year;
	int current_month = a;
	int total_days = 0;
	
	while (current_year < end_year || (current_year == end_year && current_month < end_month)) {
		total_days += getDaysInMonth(current_month, current_year);
		current_month++;
		if (current_month > 12) {
			current_month = 1;
			current_year++;
		}
	}
	
	cout << "从1900年" << a << "月1日到" << end_year << "年" << end_month << "月1日的天数是: " << total_days << "天" << endl;
	return 0;
}
