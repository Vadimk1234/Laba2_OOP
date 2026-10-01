#include <iostream>
#include <string>
#include <iomanip>

class Project {
private:
    std::string title;       
    std::string client;      
    std::string manager;     
    double budget;           
    int teamMembersCount;    
    bool isActive;           

public:
    Project(std::string pTitle = "Untitled",
        std::string pClient = "Unknown",
        std::string pManager = "Unassigned",
        double pBudget = 0.0,
        int pMembers = 0,
        bool pStatus = true)
        : title(pTitle), client(pClient), manager(pManager),
        budget(pBudget), teamMembersCount(pMembers), isActive(pStatus) {
    }

    // 2. Компоненти-функції для запису даних (Setters)
    void setTitle(const std::string& pTitle) { title = pTitle; }
    void setClient(const std::string& pClient) { client = pClient; }
    void setManager(const std::string& pManager) { manager = pManager; }
    void setBudget(double pBudget) {
        if (pBudget >= 0) budget = pBudget;
    }
    void setTeamMembersCount(int pMembers) {
        if (pMembers >= 0) teamMembersCount = pMembers;
    }
    void setIsActive(bool pStatus) { isActive = pStatus; }

    // Компоненти-функції для перегляду даних (Getters)
    std::string getTitle() const { return title; }
    std::string getClient() const { return client; }
    std::string getManager() const { return manager; }
    double getBudget() const { return budget; }
    int getTeamMembersCount() const { return teamMembersCount; }
    bool getIsActive() const { return isActive; }

    // Функція для консольного введення (запису) всіх полів
    void inputFromConsole() {
        std::cout << "\n--- Entering project data ---\n";
        std::cout << "Enter the project name: ";
        std::getline(std::cin >> std::ws, title);

        std::cout << "Enter the client: ";
        std::getline(std::cin, client);

        std::cout << "Enter the project manager: ";
        std::getline(std::cin, manager);

        std::cout << "Enter the budget ($): ";
        std::cin >> budget;

        std::cout << "Enter the number of workers: ";
        std::cin >> teamMembersCount;

        std::cout << "Is the project active? (1 - yes, 0 - no): ";
        std::cin >> isActive;
    }


    void displayInfo() const {
        std::cout << " Project information: " << title << "\n";
        std::cout << "Client:          " << client << "\n";
        std::cout << "Manager:          " << manager << "\n";
        std::cout << "Budget:            $" << std::fixed << std::setprecision(2) << budget << "\n";
        std::cout << "Number of workers: " << teamMembersCount << "\n";
        std::cout << "Status:            " << (isActive ? "In progress" : "Complited") << "\n";
    }
};

int main() {
    Project proj1("CRM System", "Tech Corp", "Alexdanr V.", 15000.50, 8, true);

    std::cout << "Initial data for the object (proj1)::";
    proj1.displayInfo();

        proj1.setBudget(18500.00);
    proj1.setTeamMembersCount(10);

    std::cout << "\nAfter updating the budget and the team:";
    std::cout << "\nUpdated budget: $" << proj1.getBudget();
    std::cout << "\nUpdated number of workers: " << proj1.getTeamMembersCount() << "\n";

   
    Project proj2;
    proj2.inputFromConsole();
    proj2.displayInfo();

    return 0;
}