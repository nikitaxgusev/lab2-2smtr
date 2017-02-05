#include <iostream>
#include <string>
#include <fstream>
#include <vector>



typedef struct Ñity {
	std::string Name;
	int Ppl;
	double Area;
	int Birth;
	int Schools;
}Ñ;

void Help();
void printRecordsFromFile(int num, std::vector<std::string> lines);


int main(int argc, char *argv[]) {

	std::ofstream writeRecord;
	std::ifstream readRecord;
	
	std::string help("-h");
	std::string help1("--help");
	std::string create("-c");
	std::string read("-r");
	std::vector<std::string> lines;

	std::cout << "argc: " << argc << std::endl;

	for (int i = 0; i < argc; i++) 
	{
		std::cout << "Argument: " << i <<" = "<< argv[i] <<std::endl;
	}
	std::cout << std::endl<<std::endl;

		if ((argv[1] == "-h") || (argv[1] == help1))
		{
			Help();
		}
		
		if (argv[1] == create) 
		{
			writeRecord.open(argv[3], std::ios_base::app);
			if (!writeRecord)
			{
				std::cerr << "Error: canNOT oprn a text file" << std::endl;
				exit(-1);
			}

			int n = atoi(argv[2]);

			for (int i = 0; i < n; i++) 
			{
				Ñ o;
				std::cout <<"Enter a name of the city:   ";
				std::cin >> o.Name;
				std::cout << "Enter quanity of people in the city:   ";
				std::cin >> o.Ppl;
				std::cout<< "Enter area of the city:   ";
				std::cin >> o.Area;
				std::cout << "Enter a year of foundation of the city:   ";
				std::cin >> o.Birth;
				std::cout  << "Enter quanity of schools in the city:   ";
				std::cin >> o.Schools;

				writeRecord << "" << i + 1 <<"Name of your city: " << o.Name<<std::endl;
				writeRecord << "" << i + 1 << "Quanity of people in your city: "<< o.Ppl << std::endl;
				writeRecord << "" << i + 1 << "Area of in your city: " << o.Area << std::endl;
				writeRecord << "" << i + 1 <<  "A year of foundation of your city: " << o.Birth << std::endl;
				writeRecord << "" << i + 1 <<  "Quanity of schools in your city: " << o.Schools<< std::endl;
				writeRecord << "" << i + 1 << std::endl;
			}
		}
			if (argv[1] == read) 
			{
				std::string str;
				int readCount=0;
				int n = atoi(argv[2]);
			
				std::cout << " -r " << std::endl;
				readRecord.open(argv[3]);
				while (!readRecord.eof())
				{
					getline(readRecord,str);
					readCount++;
					lines.push_back(str);
				}
		
	
				if (0 == readCount) 
				{
					std::cout << "ERROR: The file, which you are trying to open, is empty or it stops out" << std::endl;
					exit(-1);
				}
				if (n > readCount) 
				{
					std::cout << "!Warning!" << std::endl;
					std::cout<<"You want to read  " <<n<<" recordings"<<" But AVAILABLE: "<< readCount << " recordings" <<std::endl;
					printRecordsFromFile(readCount, lines);
				}
				else 
				{
					printRecordsFromFile(n, lines);
				}
		}
			readRecord.close();
			writeRecord.close();


	return 0;
}


void Help() 
{
	std::cout << "Help note: " << std::endl;
	std::cout << "if you would like to run the program in creating an electronic mode. You should ENTER: -c[N][file_name]" << std::endl;
	std::cout << "[N]-number of records" << std::endl;
	std::cout << "[file_name]-name of a text file" << std::endl;
	std::cout << std::endl;
	std::cout << "if you would like to run the program in read mode content text file.You should ENTER: -r[N][file_name]" << std::endl;
	std::cout << "[N]-number of records" << std::endl;
	std::cout << "[file_name]-name of a text file" << std::endl;
}

void printRecordsFromFile(int num, std::vector<std::string> lines)
{
	
 	
	for (int i = 0; i < num; i++) 
	{
		std::cout << lines[i] << std::endl;
	}
}

