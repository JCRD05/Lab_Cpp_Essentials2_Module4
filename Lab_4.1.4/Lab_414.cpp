#include <iostream>
#include <array>
#include <string_view>
#include <stdexcept>


class Calendar
{
public:
	Calendar(const int day, const int month, const int year)  
	{
		if (year < 1970)
		{
			throw std::invalid_argument("Invalid argument: Year cannot be less than 1970");
		}

		if (month < 1 || month > 12)
		{
			throw std::invalid_argument
			(
				"Invalid argument: month cannot be less than 1 or greather than 12"
			);
		}

		int maxDays = s_daysInMonth[month];
		if (month == 2 && isALeap(year))
		{
			maxDays = 29;
		}

		if (day < 1 || day > maxDays)
		{
			throw std::invalid_argument("Invalid argument: Input days cannot be bigger than month days");
		}

		m_day = day;
		m_month = static_cast<Month>(month);
		m_year = year;
	}

	void print() const
	{
		int totalDays = daysSince1970();

		Day weekday = toWeekday(totalDays);

		std::cout << m_day << " " << s_monthsName[static_cast<int>(m_month)] << " "
			<< m_year << " " << s_daysName[static_cast<int>(weekday)] << " "
			<< totalDays << "\n";
	}

private:
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	enum class Day
	{
		Friday = 1,
		Saturday,
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday
	};

	int m_day;
	Month m_month;
	int m_year;

	static constexpr std::array<std::string_view, 13> s_monthsName
	{
		"",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	static constexpr std::array<int, 13> s_daysInMonth
	{
		0,
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};

	static constexpr std::array<std::string_view, 8> s_daysName
	{
		"",
		"Friday",
		"Saturday",
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday"
	};

	Day toWeekday(const int day) const
	{
		int weekday = (day % 7);

		if (weekday == 0) { return static_cast<Day>(7); }

		return static_cast<Day>(weekday);
	}

	int daysSince1970() const
	{
		int totalDays{};

		for (int i = 1970; i < m_year; i++)
		{
			if(isALeap(i))
			{
				totalDays += 366;
			}
			else
			{
				totalDays += 365;
			}
		}

		int month = static_cast<int>(m_month);

		for(int i = 0; i < month; i++)
		{
			totalDays += s_daysInMonth[i + 1];
		}

		totalDays -= (s_daysInMonth[month] - m_day);

		if (isALeap(m_year) && month > 2)
		{
			totalDays++;
		}

		return totalDays - 1;
	}

	bool isALeap(const int year) const
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
};

int main()
{
	try
	{
		int day{};
		std::cin >> day;
		
		int month{};
		std::cin >> month;

		int year{};
		std::cin >> year;

		Calendar myCalendar(day, month, year);

		myCalendar.print();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}