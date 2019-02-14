#include "stage.h"
#include "../../stub/stub.h"
#include "../../../libs/termcolor.hpp"
#include "../../../libs/json.hpp"

using namespace nlohmann;

namespace Engine {
    namespace Stages {
        Stage::Stage(const char* path) {
            std::cout << termcolor::blue << "(ENGINE)   " << termcolor::reset;
            printf("Stages->Stage->Loading: \"%s\"...\n", path);

            std::ifstream file_stream(path);
            std::string file_content((std::istreambuf_iterator<char>(file_stream)), (std::istreambuf_iterator<char>()));

            json data = json::parse(file_content);

            stub();
        }
    }
}