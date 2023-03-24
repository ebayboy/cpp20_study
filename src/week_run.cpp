
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
    enum class RUN { X = 0, E = 1, T = 2, M = 3, L = 4 };
    int hot_cold = 4;

    week[int(RUN::T)] = t + hot_cold;
    week[int(RUN::M)] = m + hot_cold;
    week[int(RUN::L)] = l;

    int t_m_l_sum =
	std::accumulate(begin(week), end(week), 0, std::plus<int>());
    float e_avg = (sum - t_m_l_sum) / 3.0;
    fmt::println("sum:{} t:{} m:{} l:{} e_avg:{:.2f}", sum, t, m, l, e_avg);

    return 0;
}

