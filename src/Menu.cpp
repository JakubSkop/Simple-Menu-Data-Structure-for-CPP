#include "Menu.hpp"
#include <iostream>
#include <memory>
#include <algorithm>

using MenuNodePtr = std::shared_ptr<MenuNode>;
using WeakMenuNodePtr = std::weak_ptr<MenuNode>;
using Destination = std::optional<MenuNodePtr>;

/////////////////////

MenuNodePtr MenuNode::build(std::string NewName, std::initializer_list<MenuNodePtr> NewNodes){
    MenuNodePtr Node = std::make_shared<MenuNode>(NewName,NewNodes);

    for(auto i: NewNodes){
        i->AddSuperNode(Node);
    };

    return Node;
}

MenuNodePtr MenuNode::build(std::string NewName){
    MenuNodePtr Node = std::make_shared<MenuNode>(NewName);
    return Node;
}

MenuNode::MenuNode(std::string NewName, std::initializer_list<MenuNodePtr> NewNodes){
    Name = NewName;
    SubMenus = NewNodes;
};

MenuNode::MenuNode(std::string NewName){
    Name = NewName;
    SubMenus = {};
};

std::string MenuNode::GetName() const {
    return Name;
};

void MenuNode::AddSuperNode(MenuNodePtr NewNode){
    SuperMenus.push_back(WeakMenuNodePtr{NewNode});
};

//Do Not Use this other than debugging - it doesn't validate/sanitate - inherit MenuNode and override this function to add new types of menus
Destination MenuNode::MenuFunction() const {
    std::cout << Name << ": executing the default function - SubMenus:\n\n";
    for(auto i: SubMenus){
        std::cout << "\t- " <<i->GetName() << "\n";
    }
    std::cout << "\nChoose a submenu to travel to: ";
    int input;
    std::cin >> input;
    return Destination{SubMenus.at(input)};
};

/////////////////////

/////////////////////

MenuManager::MenuManager(MenuNodePtr RootNode){
    CurrentNode = RootNode;
    PreviousNode = RootNode;
};

void MenuManager::StartMenu(){
    Destination Result = CurrentNode->MenuFunction();
    if(Result){
        PreviousNode = CurrentNode;
        CurrentNode = Result.value();
    }
    else{
        std::swap(CurrentNode, PreviousNode);
    }
    StartMenu();
};