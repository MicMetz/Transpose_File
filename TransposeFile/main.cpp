#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <list>

namespace fs = std::filesystem;

int main() {
	std::list<std::pair<std::string, std::string>> fieldcontainer[10];
	std::string                                    field  = "";
	std::string                                    field2 = "";
	std::ifstream                                  out;
	std::ofstream                                  in;
	out.open("file.txt");

	if (out.is_open()) {

		getline(out, field, ' ');
		getline(out, field2, '\n');
		fieldcontainer[0].push_back(std::make_pair(field, field2));

		int level = 1;
		while (getline(out, field, ' ') && getline(out, field2, '\n')) {
			fieldcontainer[level].push_back(std::make_pair(field, field2));
			level++;
		}

		out.close();
		in.open("file_out.txt", std::ofstream::out | std::ofstream::trunc);

		int i = 0;
		while (!fieldcontainer[i].empty() && i < level) {
			in << fieldcontainer[i].front().first << " | ";
			i++;
			if (i == level) {
				in << "\n";
				int x = 0;
				while (x < i) {
					in <<  fieldcontainer[x].front().second << " | ";
					x++;
				}
			}
		}

		in.close();
	}
	else {
		std::cout << "File does not exist." << std::endl;
		exit(1);
	}


}
