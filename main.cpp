#include "Player.h"
#include "NPC.h"
#include "Team.h"
#include "Container.h"
#include "CustomException.h"
#include <memory>
#include <vector>
#include <limits> 

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
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
            std::cout << "Choose an option: ";
        }

        try {
            switch (choice) {
                case 1: {
                    std::string name;
                    int level;
                    double rating;

                    std::cout << "Enter player's name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);

                    std::cout << "Enter player's level: ";
                    while (!(std::cin >> level)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter an integer for the level.\n";
                        std::cout << "Enter player's level: ";
                    }

                    std::cout << "Enter player's rating: ";
                    while (!(std::cin >> rating)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a valid number for the rating.\n";
                        std::cout << "Enter player's rating: ";
                    }

                    Player player(name, level, rating);
                    playerContainer.add(player);
                    entities.push_back(std::unique_ptr<Player>(new Player(player)));
                    break;
                }
                case 2: {
                    std::string role;

                    std::cout << "Enter NPC role: ";
                    std::cin.ignore();
                    std::getline(std::cin, role);

                    NPC npc(role);
                    npcContainer.add(npc);
                    entities.push_back(std::unique_ptr<NPC>(new NPC(role)));
                    break;
                }
                case 3: {
                    int value;

                    std::cout << "Enter utility value: ";
                    while (!(std::cin >> value)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter an integer.\n";
                        std::cout << "Enter utility value: ";
                    }

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
                    std::cout << "Invalid option. Please choose a valid option (1-8).\n";
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
