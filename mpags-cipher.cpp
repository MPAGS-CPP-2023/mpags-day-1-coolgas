#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char* argv[])
{  
    // char in_char {'x'};
    std::string out_str {""};
    std::string inputFile;
    std::string outputFile; 

    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    for (size_t i{0}; i < cmdLineArgs.size(); i++) {
        std::string arg = cmdLineArgs[i];

        if (arg == "--help" || arg == "-h") {
            std::cout << "This is a help" << std::endl;
            return 0;
        }
        
        if (arg == "-i") {
            if (i + 1 < cmdLineArgs.size()) {
                inputFile += cmdLineArgs[i+1];
                if (inputFile.empty()) {
                    std::cerr << "No input file provided after -i option." << std::endl;
                    return 1;
                }
            } else {
                std::cerr << "No input file provided after -i option." << std::endl;
                return 1;
            }
        }

        if (arg == "-o") {
            if (i + 1 < cmdLineArgs.size()) {
                outputFile += cmdLineArgs[i+1];
                if (outputFile.empty()) {
                    std::cerr << "The output file entered is empty." << std::endl;
                    return 1;
                }
            } else {
                std::cerr << "No output file provided after -i option." << std::endl;
                return 1;
            }

        }
    }

    // Open the inputFile 
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Failed to open the input file" << inputFile << std::endl;
        return 1;
    }

    // Open the outputFile
    std::ofstream output;
    if (!outputFile.empty()) {
        output.open(outputFile);
        if (!output.is_open()) {
            std::cerr << "Failed to open the output file" << outputFile << std::endl;
            return 1;
        }
    }

    // Read and copy the contents to the 
    std::string line;
    while (std::getline(input, line)) {
        for (char& c: line) {
            c = toupper(c);
        }
        output << line << std::endl;
    }

    // Close the files
    input.close();
    if (output.is_open()) {
        output.close();
    }

    // while (std::cin >> in_char)
    // {
    //     if (isalpha(in_char)) {
    //         out_str += std::toupper(in_char);
    //         continue;
    //     }

    //    switch (in_char) {
    //         case '0':
    //         out_str += "ZERO";
    //         break;

    //         case '1':
    //         out_str += "ONE";
    //         break;

    //         case '2':
    //         out_str += "TWO";
    //         break;

    //         case '3':
    //         out_str += "THREE";
    //         break;

    //         case '4':
    //         out_str += "FOUR";
    //         break;

    //         case '5':
    //         out_str += "FIVE";
    //         break;

    //         case '6':
    //         out_str += "SIX";
    //         break;

    //         case '7':
    //         out_str += "SEVEN";
    //         break;

    //         case '8':
    //         out_str += "EIGHT";
    //         break;

    //         case '9':
    //         out_str += "NINE";
    //         break;
                 
    //         default:
    //         break;
    //    }
    // }
    
    // std::cout << out_str << std::endl;
    return 0;
}