#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		cout << "printbin <file> <size>" << endl;
		return 0;
	}

	cout << "File: " << argv[1] << endl;
	ifstream file(argv[1], std::ifstream::binary | std::ifstream::in | std::ifstream::ate );
	if(!file.is_open())
	{
		cout << "File " << argv[1] << " cannot be open" << endl;
		return 0;
	}

	size_t file_size = file.tellg();
	cout << "File size: " << file_size << endl;

	size_t max_size = file_size;

	if(argc == 3)
	{
		cout << argv[2] << endl;
		max_size = atoi(argv[2]);
		cout << "Max printed size: " << max_size << endl;
	}

	file.close();

	ifstream f(argv[1], std::ifstream::binary | std::ifstream::in);

	uint8_t *buf = new uint8_t[file_size];
	f.read((char*)buf, file_size * sizeof(uint8_t));
	for(size_t i = 0; i < file_size; ++i)
	{
		printf("%2X ", buf[i]);
		if(i > max_size)
		{
			break;
		}
	}

	printf("\n");
	delete[] buf;
	f.close();
	return 0;
}
