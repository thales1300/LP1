#include "App.h"
#include "GetConfig.h"

int main(int argc, char* argv[]){

    std::unordered_map<std::string, std::string> config1 = config();
    App aplicativo(config1["path"]);
    return aplicativo.run(argc, argv,config1["default_format"]);
}
