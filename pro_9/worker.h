#ifndef WORKER
#define WORKER

class Worker {
private:
    int _id;
public:
    char name[100];
public:
    void setID(int id);
    int getID();
};

#endif