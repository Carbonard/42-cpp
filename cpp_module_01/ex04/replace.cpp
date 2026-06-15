#include <iostream>
#include <fstream>
#include <string>

void check_args(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr
			<< "Error: 3 arguments required:\n"
			<< "\t<File name>\n"
			<< "\t<Text to replace>\n"
			<< "\t<Replacement text>";
		throw std::runtime_error("");
	}
	if (!argv[2][0])
		throw std::runtime_error("Second argument must not be empty");
}

std::string read_file(char *fileName)
{
	std::ifstream inFile(fileName);
	if (!inFile)
		throw std::runtime_error("Error opening input file");

	std::string fileContent;
	char c;
	while (inFile.get(c))
		fileContent += c;
	
	return (fileContent);
}

std::string replace(const std::string &str,
					const std::string &to_find,
					const std::string &replacement)
{
	std::string	new_str;
	size_t		match;
	size_t		start = 0;
	
	match = str.find(to_find, 0);
	if (match == std::string::npos)
		return (str);
	do
	{
		new_str += str.substr(start, match - start);
		new_str += replacement;
		start = match + to_find.length();
		match = str.find(to_find, start);
	} while (match != std::string::npos);
	new_str += str.substr(start);

	return (new_str);
}

void save_into_file(const std::string &text,
					const std::string &file)
{
	std::ofstream outFile(file.c_str());
	if (!outFile)
		throw (std::runtime_error("Error opening output file"));
	outFile << text;
}

int main(int argc, char **argv)
{
	try
	{
		check_args(argc, argv);
		std::string fileContent = read_file(argv[1]);
		std::string editedContent = replace(fileContent, argv[2], argv[3]);
		std::string outFile = std::string(argv[1]) + ".replace";
		save_into_file(editedContent, outFile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}
