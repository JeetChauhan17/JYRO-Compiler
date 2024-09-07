#include<iostream>
#include<fstream>
#include<sstream>
#include<optional>
#include<vector>

// Lexical tokenisation starts here. 
// Enumeration: 
enum class TokenType{
    jreturn,
    int_lit,
    jemi
};

struct Token{
    TokenType type;
    std::optional<std::string> value;
};


// remember soldier, switching to  a vector is faster tha reloading
// personal hate to list

std::vector<Token> tokenize (const std::string& str){
    // iterate through each word and tokenise it. assuming its ascii lol
    for(char c : str){
        std::cout<< c << std::endl;
    }

    // 3rd approah: if i see a letter, i'll start readig it into a buffer until its no loger a letter or no,
    // that'll maybe help find out what the buffer contains and it its a token.

    // todo : fix segfault (add ret whe i have cotent worth returing)
}

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



    // std::cout<<contents<<std::endl; //works heheheha
    tokenize(contents);
    return EXIT_SUCCESS;
    
}