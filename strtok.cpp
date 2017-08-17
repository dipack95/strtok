# include <iostream>
# include <vector>
# include <string>

std::vector<std::string> strtok(std::string mashedString, char delimiter){
    std::vector<std::string> tokens;
    int length = mashedString.size();

    if(length <= 0) {
        return tokens;
    }

    std::cout << "Delimiter is " << delimiter << "\n";
    std::cout << "Length " << length << "\n";

    std::string token;
    for(unsigned int i = 0 ; i < length ; i++) {
        std::cout << i << "\t" << mashedString[i] << "\n";
        if(mashedString[i] == delimiter || i == length - 1) {
            if(token.size() == 0) {
                continue;
            } else {
                tokens.push_back(token);
                token.clear();
            }
        } else if(mashedString[i] != delimiter)  {
            token.push_back(mashedString[i]);
            std::cout << "Token is now " << token.c_str() << "\n";
        }
    }

    return tokens;
}

int main(int argc, char** argv) {
    char delimiter = '|';
    std::string testString = "test | test1 | test 2";
    std::vector<std::string> result = strtok(testString, delimiter);
    for(int i = 0 ; i < result.size() ; i++ ) {
        std::cout << result[i] << "\n";
    }
    return 0;
}
