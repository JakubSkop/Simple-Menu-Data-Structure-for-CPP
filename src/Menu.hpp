#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <optional>

class MenuNode;
using MenuNodePtr = std::shared_ptr<MenuNode>;
using WeakMenuNodePtr = std::weak_ptr<MenuNode>;
using Destination = std::optional<MenuNodePtr>;

class MenuNode{
    private:
        std::vector<MenuNodePtr> SubMenus;
        std::vector<WeakMenuNodePtr> SuperMenus;
        std::string Name;
        
    public:
        static MenuNodePtr build(std::string NewName, std::initializer_list<MenuNodePtr> NewNodes);
        static MenuNodePtr build(std::string NewName);

        MenuNode(std::string NewName, std::initializer_list<MenuNodePtr> NewNodes);
        MenuNode(std::string NewName);

        std::string GetName() const;
        void AddSuperNode(MenuNodePtr NewNode);

        virtual Destination MenuFunction() const;

};

class MenuManager{
    private:
        MenuNodePtr CurrentNode;
        MenuNodePtr PreviousNode;

    public:
        MenuManager(MenuNodePtr RootNode);
        void StartMenu();
        
};