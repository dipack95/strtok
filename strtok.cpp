# include <iostream>
# include <vector>
# include <string>

std::vector<std::string> strtok(std::string mashedString, char delimiter){
    std::vector<std::string> tokens;
    int length = mashedString.size();

    if(mashedString.empty()) {
        return tokens;
    }

    std::string token;
    for(unsigned int i = 0 ; i < length ; i++) {
        if(mashedString[i] == delimiter) {
            if(token.empty()) {
                continue;
            } else {
                tokens.push_back(token);
                token.clear();
            }
        } else if(mashedString[i] != delimiter)  {
            token.push_back(mashedString[i]);
        }
    }
    if(!token.empty()) {
        tokens.push_back(token);
        token.clear();
    }

    return tokens;
}

int main(int argc, char** argv) {
    char delimiter = '|';
    std::string testString = "test | test 1 | test 2";

    std::vector<std::string> result = strtok(testString, delimiter);

    std::cout << "The tokens in\n";
    std::cout << testString.c_str() << "\n";
    std::cout << "are:\n";

    for(int i = 0 ; i < result.size() ; i++ ) {
        std::cout << result[i] << "\n";
    }

    return 0;
}
