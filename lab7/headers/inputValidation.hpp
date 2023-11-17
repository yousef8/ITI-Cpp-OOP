#ifndef INPUTVALIDATION_HPP_INCLUDED
#define INPUTVALIDATION_HPP_INCLUDED

#include <iostream>
#include <limits>
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

void getIntInput(int& in, const std::string& message)
{
    while(true)
    {
        std::cout << message;
        // Handle Extraction Failure and Overflow
        if(!(std::cin >> in))
        {
            // On Unix systems, entering an end-of-file (EOF) character (via ctrl-D) closes the input stream. This is something that std::cin.clear() can’t fix,
            if (std::cin.eof()) // if the stream was closed
            {
                exit(0); // shut down the program now
            }
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid Input\n\n";
        }
        else
        {
            // Handle Extraneous input
            ignoreLine();

            //program will have to handle meaningless input
            return;
        }
    }
}


#endif // INPUTVALIDATION_HPP_INCLUDED
