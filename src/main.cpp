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
    std::optional<std::string> value {};
};


// remember soldier, switching to  a vector is faster tha using list or reloading
// personal hate to list

std::vector<Token> tokenize (const std::string& str){
    // iterate through each word and tokenise it. assuming its ascii lol

    std::vector<Token> tokens;
    
    std::string buf; // creating a string buffer and initialising it to nothing
    for(int i = 0; i< str.length(); i++){
        char c = str.at(i);
        if(isalpha(c)){
            buf.push_back(c); //adding new element at the end of the buffer.
            i++;

            while(std::isalnum(str.at(i))){
                buf.push_back(str.at(i));
                i++;
            }
            i--; // fixes the one char ahead thing. REFACTOR later.
        if(buf == "return"){
            tokens.push_back({.type = TokenType::jreturn});
            buf.clear(); //clear buffer after a word has been detected and tokenised.
            continue;
        } else{
            std::cerr<<"ya messed up"<<std::endl;
            exit(EXIT_FAILURE);
        }
        }
        else if(std::isdigit(c)){
            buf.push_back(c);
            i++;
            while(std::isdigit(str.at(i))){
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buf});
            buf.clear();
        }
        else if(c == ';'){
            tokens.push_back({.type = TokenType::jemi});
        }
        else if(std::isspace(c)){
            continue;
        }
        else{
            std::cerr<<"YA MESSED UP"<<std::endl;
            exit(EXIT_FAILURE);
        }

    }

    // 3rd approah: if i see a letter, i'll start readig it into a buffer until its no loger a letter or no,
    // that'll maybe help find out what the buffer contains and it its a token.

    // todo : fix segfault (add ret whe i have cotent worth returing)
    return tokens;
}


// Coverting to assembly  tokens -> assenbly:
std::string tokens_to_asm(std::vector<Token>& tokens) {
    std::stringstream output;
    output << "global _start\n_start:\n";
    for(int i = 0; i<tokens.size(); i++){
        const Token& token = tokens.at(i);
        if(token.type == TokenType::jreturn){

            // very jank pattern solution. FIX later. to figure out if we have a return keyword, we need a int literal and a following semicolon. 
            
            if(i+1 < tokens.size() && tokens.at(i+1).type == TokenType::int_lit){
                if(i+2 < tokens.size() && tokens.at(i+2).type == TokenType::jemi){
                    output << "    mov rax, 60\n";
                    output << "    mov rdi, "<<tokens.at(i+1).value.value()<< "\n";
                    output << "    syscall ";
                }

            }
        }
    }
    return output.str();
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




    // tokenize(contents);
    std::vector<Token> tokens = tokenize(contents);
    // std::cout<<<<std::endl; //works heheheha
    
    {
        std::fstream file("../out.asm", std::ios::out);
        file << tokens_to_asm(tokens);
    }

    
    return EXIT_SUCCESS;
    
}
