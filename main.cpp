#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "MarkovChain.h"


int main()
{
    std::stringstream ss;
    // send your JSON above to the parser below, but populate ss first

    std::ifstream f("../data2.json");
    if (f) {
        ss << f.rdbuf();
        f.close();
    }

    MarkovChain mc(ss);
    mc.print();
    std::stringstream ss2 = mc.serialize_json();
    std::cout << ss2.str() << std::endl;

    std::ofstream f2("../data.json");
    f2 << ss2.rdbuf();
    f2.close();


}