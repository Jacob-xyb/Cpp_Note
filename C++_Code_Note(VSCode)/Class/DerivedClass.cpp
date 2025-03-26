/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-18 15:52:02
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-18 16:39:58
 * @Description: Life is struggle.
 */
#include <iostream>
#include <memory>

using namespace std;

// 基类
class Animal
{
public:
    void sayHello()
    {
        std::cout << "Hello, I am an animal." << std::endl;
    }

    void eat()
    {
        std::cout << "Animal is eating." << std::endl;
    }

    void sleep()
    {
        std::cout << "Animal is sleeping." << std::endl;
    }

    virtual void makeSound()
    {
        std::cout << "Animal is making sound." << std::endl;
    }

    virtual void makeHard()
    {
        std::cout << "Animal is making hard." << std::endl;
    }

    void play() { makeSound(); Animal::makeHard(); }
};

// 派生类
class Dog : public Animal
{
public:
    void bark()
    {
        std::cout << "Dog is barking." << std::endl;
    }

    // 重写基类的成员函数
    void eat()
    {
        std::cout << "Dog is eating." << std::endl;
    }

    // 多态
    void makeSound() override
    {
        std::cout << "Dog is making sound." << std::endl;
    }

    virtual void makeHard()
    {
        std::cout << "Dog is making hard." << std::endl;
    }
};

/// @brief 什么是派生
void what_is_derived()
{
    printf("** Start what_is_derived **\n");

    // 派生就是派生类可以调用基类的函数和变量
    Dog dog;
    dog.sayHello(); // 调用基类的 sayHello() 函数
    dog.eat();      // 调用派生类的 eat() 函数
}

/// @brief 基类调用虚函数
void base_call_virtual_function()
{
    printf("** Start base_call_virtual_function **\n");

    shared_ptr<Animal> animal = make_shared<Dog>();
    animal->play();       // 调用派生类的 makeSound() 函数
}

int main()
{
    what_is_derived();
    base_call_virtual_function();
    return 0;
}