#include "FamilyTree.hpp"

#include <iostream>
namespace family{
Tree::Tree(std::string iname){
    father.insert(std::pair<std::string,std::string>("__root__", iname) );
}
Tree& Tree::addFather(std::string my_name, std::string my_father) {
    std::string key = "__null__";
    for (auto &i : this->father) {
       if (i.second == my_name) {
          key = i.first;
          break; // to stop searching
       }
    }
    for (auto &i : this->mother) {
       if (i.second == my_name) {
          key = i.first;
          break; // to stop searching
       }
    }
    if (key != "__null__") {
        father.insert(std::pair<std::string,std::string>(my_name, my_father));
        return *this;
    } else {
        throw std::exception();
    }
}
Tree& Tree::addMother(std::string my_name, std::string my_mather) {
    std::string key = "__null__";
    for (auto &i : this->father) {
       if (i.second == my_name) {
          key = i.first;
          break; // to stop searching
       }
    }
    for (auto &i : this->mother) {
       if (i.second == my_name) {
          key = i.first;
          break; // to stop searching
       }
    }
    if (key != "__null__") {
        mother.insert(std::pair<std::string,std::string>(my_name, my_mather));
        return *this;
    } else {
        throw std::exception();
    }
}
void Tree::display() {
    std::cout << "hello display";
}
std::string Tree::relation(std::string relative_name) {

    return "relation";
}
std::string Tree::find(std::string relation) {
    std::cout << "hello find\n";
    return "find";
}
void Tree::remove(std::string relative_name) {
    std::cout << "hello remove";
}
}
