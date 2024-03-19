#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

//193 = avg;
int main(int argc, char* argv[])
{
	bool gtgChk = true;

	if(argc == 3 && std::string(argv[1]) == "-a")
	{
		int number = std::atoi(argv[2]);
		if(number != 0 || std::string(argv[2]) == "0")
		{
			std::ifstream avgInFile("avg" + std::to_string(number) + ".txt");
			std::ifstream infile("output" + std::to_string(number) + ".txt");
			std::ofstream outfile("final" + std::to_string(number) + ".txt");

			if(!infile.is_open() || !outfile.is_open() || !avgInFile.is_open())
			{
				std::cerr << "Error opening files!" << std::endl;
				return 1;
			}
			std::string avgS;
			getline(avgInFile, avgS);
			int avg = std::stoi(avgS);
			std::string line;
			while(getline(infile, line))
			{
				if(line.rfind(">chr1:", 0) == 0)
				{
					size_t colonPos = line.find(':');
					size_t dashPos = line.find('-', colonPos);
					if(colonPos != std::string::npos && dashPos != std::string::npos)
					{
						int start = std::stoi(line.substr(colonPos + 1, dashPos - colonPos - 1));
						int end = std::stoi(line.substr(dashPos + 1));
						int length = end - start;
						if(length < avg)
						{
							gtgChk = false;
						}else{
							gtgChk = true;
						}
					}
				}else{
				
					if(gtgChk)
					{
						std::string out;
						for(int i = 0; i < avg; ++i)
						{
							out += line.substr(i);
						}
						outfile << out << std::endl;
					}
				}
			}
			infile.close();
			avgInFile.close();
			outfile.close();
		}else{
			std::cout << "Error: please enter an integer after -a " <<std::endl;
		}
	}else{
		std::cout << "Error: please enter -a (int)  " << std::endl;
	}

	return 0;
}
