#include <iostream>
#include "./src/Menu.hpp"


//Example Script
int main() {
    auto M = MenuNode::build("Main Menu",{
        MenuNode::build("Edit"),
        MenuNode::build("Play",{
            MenuNode::build("Assemble Team"),
            MenuNode::build("Start Match")
        })
    });

    MenuManager Handler{M};
    Handler.StartMenu();

}
