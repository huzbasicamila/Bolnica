//
// Created by aidah on 12/9/2022.
//

#ifndef BOLNICA_KREVET_H
#define BOLNICA_KREVET_H

enum Status{slobodno=1, zauzeto, rezervisano};

class Krevet {
private:
    int broj;
    Status status;
public:
    Krevet();
    Krevet(int a, Status s);
    void setBroj(int a);
    void setStatus(Status s);
    int getBroj();
    Status getStatus();
    ~Krevet()=default;
};


#endif //BOLNICA_KREVET_H
