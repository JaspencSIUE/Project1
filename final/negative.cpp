#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

int main(int argc, char* argv[])
{
	
	if(argc == 4 && std::string(argv[1]) == "-a")
	{
		int number = std::atoi(argv[2]);
		std::string inf = std::string(argv[3]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			std::ifstream infile(inf);
			std::ofstream outfile("negative" + std::to_string(number) + ".bed");

			if(!infile.is_open() || !outfile.is_open())
			{
				std::cerr << "Error opening files!" << std::endl;
				return 1;
			}
			int val2;
			int val1;
			std::string line;
			bool first = true;
			while(getline(infile, line))
			{

				std::istringstream iss(line);
				std::string chr, num1_str, num2_str;
				int val1, val2;
				if(!(iss >> chr >> num1_str >> num2_str))
				{
					std::cerr << "Error reading line!" << std::endl;
					continue;
				}
				if(first)
				{
					val1 = std::stoi(num1_str);
					val1++;
					first = false;
				}else{
					val2 = std::stoi(num2_str);
					val2--;
					if(val2 < val1)
					{
						std::cerr << "Error with value " << num2_str << " being less than " << num1_str << std::endl;
					}else{
						std::string output = "chr1\t" + std::to_string(val1) + "\t" + std::to_string(val2);
						outfile << output << std::endl;
					}
					val1 = std::stoi(num1_str);
					val1++;
				}
			}
			infile.close();
			outfile.close();
		}
	}
	return 0;
}

