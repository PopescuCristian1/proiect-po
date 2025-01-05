#include "Player.h"
#include "NPC.h"
#include "Team.h"
#include "Container.h"
#include "CustomException.h"
#include <memory>
#include <vector>

void menu() {
    Team* team = Team::getInstance();
    std::vector<std::unique_ptr<AbstractEntity>> entities;
    Container<Player> playerContainer;
    Container<NPC> npcContainer;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Player\n";
        std::cout << "2. Add NPC\n";
        std::cout << "3. Add Utility\n";
        std::cout << "4. Display Players\n";
        std::cout << "5. Display Utilities\n";
        std::cout << "6. Sort Utilities\n";
        std::cout << "7. Display First NPC\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    std::string name;
                    int level;
                    double rating;
                    std::cout << "Enter name, level, and rating: ";
                    std::cin >> name >> level >> rating;
                    Player player(name, level, rating);
                    playerContainer.add(player);
                    entities.push_back(make_unique<Player>(player));
                    break;
                }
                case 2: {
                    std::string role;
                    std::cout << "Enter NPC role: ";
                    std::cin >> role;
                    NPC npc(role);
                    npcContainer.add(npc);
                    entities.push_back(make_unique<NPC>(role));
                    break;
                }
                case 3: {
                    int value;
                    std::cout << "Enter utility value: ";
                    std::cin >> value;
                    if (value < 0) {
                        throw CustomException();
                    }
                    team->addUtility(Utility(value));
                    break;
                }
                case 4: {
                    for (const auto& entity : entities) {
                        entity->display();
                    }
                    break;
                }
                case 5: {
                    team->displayUtilities();
                    break;
                }
                case 6: {
                    try {
                        team->sortUtilities();
                        std::cout << "Utilities sorted.\n";
                    } catch (const CustomException& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 7: {
                    try {
                        NPC firstNPC = npcContainer.getFirstElement();
                        firstNPC.display();
                    } catch (const CustomException& e) {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                case 8: {
                    return;
                }
                default: {
                    std::cout << "Invalid option. Try again.\n";
                    break;
                }
            }
        } catch (const CustomException& e) {
            std::cerr << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cerr << "Standard exception: " << e.what() << '\n';
        }
    }
}

int main() {
    menu();
    return 0;
}
