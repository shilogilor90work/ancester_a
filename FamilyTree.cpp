#include "FamilyTree.hpp"

#include <iostream>
namespace family{
Tree::Tree(std::string iname){
    name = iname;
}
Tree& Tree::addFather(std::string name, std::string father) {
    std::cout << "hello father";
    return *this;
}
Tree& Tree::addMother(std::string name, std::string mather) {
    std::cout << "hello mother";
    return *this;
}
void Tree::display() {
    std::cout << "hello display";
}
std::string Tree::relation(std::string relative_name) {
    return "relation";
}
std::string Tree::find(std::string relation) {
    return "find";
}
void Tree::remove(std::string relative_name) {
    std::cout << "hello remove";
}
}
