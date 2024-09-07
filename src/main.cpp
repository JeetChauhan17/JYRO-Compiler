#include<iostream>
#include<fstream>
#include<sstream>

int main(int argc, char* argv[]){
    // dont let the arg to be 0 or 1:
    if(argc != 2){
        std::cerr<<"Incorrect Usage, Correct usage is..."<<std::endl;
        std::cerr<<"Jyro <input.jj>"<<std::endl;
        return EXIT_FAILURE;
    }

    // reading the file:. we are giving the file path and then using it as input.

    std::string contents;
    {
    std::stringstream contents_stream;
    std::fstream input(argv[1], std::ios::in);
    contents_stream << input.rdbuf();
    contents = contents_stream.str(); 
    }



    std::cout<<contents<<std::endl; //works heheheha
    return EXIT_SUCCESS;
    
}