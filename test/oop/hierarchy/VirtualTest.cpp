//
// Created by yoonsung on 17. 9. 17.
//
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <iostream>

using namespace std;
#include "../../../src/oop/hierarchy/Hierarchy.h"


/**
 * [virtual 정리]
 * pure virtual ( function()=0; 으로 정의) 이 하나라도 있으면 abstract class로 new를 할 수 없다.
 *
 * java에서 쓰던 Override를 하려면 virtual로 선언하고 자식에서 해당 메소드를 재정의 하면 된다.
 * 이게 Parent에서 virtual로 쓰이던 것인지 확인하기 위해서 virtual을 그대로 붙여주던가 override를 붙인다.
 *
 * virtual을 쓰지 않고 그냥 똑같은 함수를 재정의 하는 경우. 선언된 type에 따라서 해당 함수가 불린다.
 * 즉, 객체를 new 하는 시점에 초기화시킨 concrete 타입과 별개로, 함수를 call하는 시점에 사용하는 타입에서 선언된 메소드내용을 쫓아간다.
 *
 *
 *
 */
SCENARIO("virtual methods implementation and call on inheritance", "[test][inheritance][virtual][override]"){
    WHEN("GrandParent has two pure virtual method and one ordinary method"){
//        GrandParent* gp=new GrandParent();
        AND_WHEN("Parent inherited GrandParent override one method to normal and another to virtual and the other ordinary method"){
            Parent* parent=new Parent();
            AND_THEN("Child inherited Parent override two method to normal and the other ordinary method"){
                Child* child=new Child();
                GIVEN("Child call all methods"){
                    cout<< "pure virtual : " << child->grandParentPureVirtual()<< endl;
                    REQUIRE(child->grandParentOridnary()=="child");
                    REQUIRE(child->grandParentVirtual()=="child imple");
                    REQUIRE(child->grandParentPureVirtual()=="child Pure imple");
                    REQUIRE(child->defineOnParent()=="child");
                }
                GIVEN("Parent call all methods"){
                    cout<< "pure virtual : " << parent->grandParentPureVirtual()<< endl;
                    REQUIRE(parent->grandParentOridnary()=="parent");
                    REQUIRE(parent->grandParentVirtual()=="parent imple");
                    REQUIRE(parent->grandParentPureVirtual()=="parent Pure imple");
                    REQUIRE(parent->defineOnParent()=="parent");
                }

                GIVEN("Child object allocate parent type"){
                    Parent* tempParent=child;
                    CHECK(tempParent->grandParentOridnary()=="parent");
                    CHECK(tempParent->grandParentVirtual()=="child imple");
                    CHECK(tempParent->grandParentPureVirtual()=="child Pure imple");
                    CHECK(tempParent->implementsUntilParent()=="parent");
                    CHECK(tempParent->defineOnParent()=="child");
                }
                GIVEN("Child object allocate grandParent type"){
                    GrandParent* tempGrandParent= dynamic_cast<GrandParent*>(child);
                    CHECK(tempGrandParent->grandParentOridnary()=="grandParent");
                    CHECK(tempGrandParent->grandParentVirtual()=="child imple");
                    CHECK(tempGrandParent->grandParentPureVirtual()=="child Pure imple");
                    CHECK(tempGrandParent->implementsUntilParent()=="parent");
                }

                GIVEN("Parent object allocate grandParent type"){
                    GrandParent* tempGrandParent= dynamic_cast<GrandParent*>(parent);
                    CHECK(tempGrandParent->grandParentOridnary()=="grandParent");
                    CHECK(tempGrandParent->grandParentVirtual()=="parent imple");
                    CHECK(tempGrandParent->grandParentPureVirtual()=="parent Pure imple");
                    CHECK(tempGrandParent->implementsUntilParent()=="parent");
                }

            }
        }
    }
}