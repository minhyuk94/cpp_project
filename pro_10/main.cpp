#include <iostream>

class User {
    private:
        int _id;
        int _pw;
    public:
        User(); //생성자 선언
        User(int id, int pw);
        ~User(); //소멸자 선언
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = int(pw);
}
const int User::getPW() {
    return _pw;
}

// 생성자
User::User() : User((int)NULL, (int)NULL){ 
    std::cout << "Constructor" << std::endl;
}

// 생성자2
User::User(int id, int pw) : _id{id}, _pw{pw} {
    std::cout << "Constructor2" << std::endl;
}

// 소멸자
User::~User() {
    // if(_pw) delete _pw;
    std::cout << "Destructor" << std::endl;
}


int main() {
    User user = User();

    std::cout << user.getID() << " " << user.getPW() << std::endl;
}