#ifndef CLASS_H
#define CLASS_H
class node
{
public:
    std::string name;
    int d, m, y;
    int wd, wm, wy;
    double price;
    node *ptr;
};
class billing : public node
{
public:
    node *new_node, *front = NULL, *rear = NULL, *temp, *prev;
    void insertp();
    void traversep();
    void deletebyposition();
    void deletebyname();
};
#endif