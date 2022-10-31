#include <iostream>
using namespace std;
class person {
    public:
        person(const std::string name = "", int age = 0) : 
            name_(name), age_(age) {
                std::cout << "Init a person!" << std::endl;
            }
        ~person() {
            std::cout << "Destory a person!" << std::endl;
        }
        const std::string& getname() const {
            return this->name_;
        }    
        int getage() const {
            return this->age_;
        }      
    private:
        const std::string name_;
        int age_;  
};
int main() {
    person p;
    return 0;
}
