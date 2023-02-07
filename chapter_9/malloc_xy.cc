
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

int main(int argc, char **argv)
{
	size_t width { 3 }, height { 4 };
	int **m_cells { nullptr };

	/* malloc */
	m_cells = new int*[width];
	for(size_t i = 0; i < width; i++) {
		m_cells[i] = new int[height];
	}

	for (size_t i = 0; i < width; i ++) {
		for(size_t j = 0; j < height; j++) {
			m_cells[i][j] = i+j;
			fmt::print("[{}][{}]:{}\n", i, j, m_cells[i][j]);
		}
	}

	/* delete  */
	for(size_t i = 0; i < width; i++) {
		delete [] m_cells[i];
	}
	delete [] m_cells;

	return 0;
}

