
#include <fmt/core.h>
#include <getopt.h>
#include <unistd.h>

#include <array>
#include <iostream>
#include <numeric>
#include <utility>

using namespace std;

int main(int argc, char **argv) {
    int opt;
    int option_index{0};
    int t, m, l, sum;

    static struct option long_options[] = {{"t", required_argument, NULL, 't'},
					   {"m", required_argument, NULL, 'm'},
					   {"l", required_argument, NULL, 'l'},
					   {"s", required_argument, NULL, 's'},
					   {0, 0, 0, 0}};

    while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) !=
	   -1) {
	switch (opt) {
	    case 't':
		t = atoi(optarg);
		break;
	    case 'm':
		m = atoi(optarg);
		break;
	    case 'l':
		l = atoi(optarg);
		break;
	    case 's':
		sum = atoi(optarg);
		break;
	    default:
		break;
	}
    }

    array<int, 7> week{};
    int hot_cold = 4;

    int t_m_l_sum = t + m + l + hot_cold * 2;
    int e_avg = (sum - t_m_l_sum) / 3;
    fmt::println("sum:{} t:{} m:{} l:{} e_avg:{}", sum, t, m, l, e_avg);

    fmt::println("day1: {}E", e_avg);
    fmt::println("day2: {}E", e_avg);
    fmt::println("day3: {}T", t);
    fmt::println("day4: {}E", e_avg);
    fmt::println("day5: {}M", m);
    fmt::println("day6: X");
    fmt::println("day7 {}L", l);

    return 0;
}

