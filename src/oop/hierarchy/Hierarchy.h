//
// Created by yoonsung on 17. 9. 17.
//

#ifndef CPPTEST_HIERARCHY_H
#define CPPTEST_HIERARCHY_H

class GrandParent{
public:
    virtual string grandParentPureVirtual()=0;
    virtual string grandParentVirtual()=0;
    string grandParentOridnary(){return "grandParent";};
    virtual string implementsUntilParent()=0;
};
class Parent: public GrandParent{
public:
    virtual string grandParentPureVirtual(){return "parent Pure imple";};
    string grandParentVirtual(){return "parent imple";};
    string grandParentOridnary(){return "parent";};
    virtual string implementsUntilParent(){return "parent";};
    virtual string defineOnParent(){return "parent";};
};
class Child: public Parent{
public:
    string grandParentPureVirtual(){return "child Pure imple";};
    string grandParentVirtual(){return "child imple";};
    string grandParentOridnary(){return "child";};
    virtual string defineOnParent(){return "child";};
};

#endif //CPPTEST_HIERARCHY_H
