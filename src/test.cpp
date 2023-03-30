
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

using namespace std;

const int EVENTSNUM = 4096;

class Demo
{
public:
	Demo (int event_size): epoll_events_(event_size) {};
	~Demo (){};
	void showEventSize() const {
		fmt::println("event_size:{}", epoll_events_.size());
	};

private:
	/* data */
	std::vector<int> epoll_events_;
};

int main(int argc, char **argv)
{
	Demo d {EVENTSNUM};
	d.showEventSize();

	return 0;
}

