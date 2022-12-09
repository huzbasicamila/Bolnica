//
// Created by aidah on 12/9/2022.
//

#include "Krevet.h"

Krevet::Krevet() {
    this->status=slobodno;
}
Krevet::Krevet(int a, Status s) {
    this->broj=a;
    this->status=s;
}
void Krevet::setBroj(int a) {
    this->broj=a;
}
void Krevet::setStatus(Status s) {
    this->status=s;
}
int Krevet::getBroj() {
    return this->broj;
}
Status Krevet::getStatus() {
    return this->status;
}