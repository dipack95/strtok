# include <iostream>
# include <vector>
# include <string>

std::vector<std::string> strtok(std::string mashedString, char delimiter){
    std::vector<std::string> tokens;
    int length = mashedString.size();

    if(length <= 0) {
        return tokens;
    }

    std::string token;
    for(int i = 0 ; i < length ; i++) {
        if(mashedString[i] == delimiter) {
            if(token.size() == 0) {
                continue;
            } else {
                tokens.push_back(token);
                token.clear();
            }
        } else if(mashedString[i] != delimiter || mashedString[i] == '\0') {
            token.push_back(mashedString[i]);
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
