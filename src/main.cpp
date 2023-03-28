#include "toml/toml.h"

using namespace toml;

void test1() {
    Table root_table;
    Table tbl;
    Table glfw;

    String sdl("sdl");
    String sdl_version("2.0.0");

    String glfw_name("glfw");
    String glfw_version("3.0.0");

    tbl.set("lib", &sdl);
    tbl.set("version", &sdl_version);
    glfw.set("name", &glfw_name);
    glfw.set("version", &glfw_version);

    root_table.set("tbl.beep", &tbl);
    root_table.set("glfw", &glfw);

    std::cout << "printing out root table" << std::endl;
    std::cout << root_table << std::endl;
}

void test2() {
    str content = "[test.blo.bla] #taoeu\n"
    "deps = ['sdl', 'glfw']\n"
    "name = 'beep'\n"
    "age = 23\n"
    "\n"
    "[hello]\n"
    "great = 'hi'\n";

    std::cout << "parsing" << std::endl;
    Table root_table = parse(content);

    std::cout << "printing out sub table hello" << std::endl;
    std::cout << root_table["hello"] << std::endl;

    std::cout << "printing out root table" << std::endl;
    std::cout << root_table << std::endl;
}

int main(int argc, char* argv[]) {
    test1();
    std::cout << "test1 done" << std::endl;
    test2();
    std::cout << "test2 done" << std::endl;
    return 0;
};

