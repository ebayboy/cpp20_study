
import person;
import <iostream>;
import <string>;

using namespace std;

int main(int argc, char **argv)
{
	person p{"fanp", "pengfei"};

	cout << p.getLastName() << ", " << p.getFirstName() << endl;

	return 0;
}

