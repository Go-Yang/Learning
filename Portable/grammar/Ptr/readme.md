创建 shared_ptr:
    auto p = std::make_shared<int>(10);
构造函数:
    std::shared_ptr<int> p(new int(10));

返回与当前 shared_ptr 共享对象的智能指针数量:
    auto p1 = std::make_shared<int>(10);
    std::cout << p1.use_count() << std::endl; // 输出：1
    auto p2 = p1;
    std::cout << p1.use_count() << std::endl; // 输出：2

释放 shared_ptr 所管理的对象，并可选择重新管理新的对象:
    auto p = std::make_shared<int>(10);
    p.reset(); // 释放对象
    p.reset(new int(20)); // 重新管理新的对象

返回 shared_ptr 所管理的对象的原始指针:
    auto p = std::make_shared<int>(10);
    int* rawPtr = p.get();

交换两个 shared_ptr 所管理的对象:
    auto p1 = std::make_shared<int>(10);
    auto p2 = std::make_shared<int>(20);
    p1.swap(p2);

访问 shared_ptr 所管理的对象:
    auto p = std::make_shared<int>(10);
    std::cout << *p << std::endl; // 输出：10
    struct Foo { void display() { std::cout << "Foo" << std::endl; } };
    auto foo = std::make_shared<Foo>();
    foo->display(); // 输出：Foo

判断当前 shared_ptr 是否是唯一一个管理对象的智能指针:
    auto p1 = std::make_shared<int>(10);    
    auto p2 = p1;
    std::cout << std::boolalpha << p1.unique() << std::endl; // 输出：false
    p2.reset();
    std::cout << std::boolalpha << p1.unique() << std::endl; // 输出：true

比较两个 shared_ptr 或 weak_ptr 所管理对象的所有权顺序:
    auto p1 = std::make_shared<int>(10);
    auto p2 = std::make_shared<int>(20);
    if (p1.owner_before(p2)) {
        std::cout << "p1 is managed before p2" << std::endl;
    } else {
        std::cout << "p2 is managed before p1" << std::endl;
    }
!!!对于 shared_ptr 和 weak_ptr，owner_before 只比较所有权控制块的位置，而不比较实际指向的对象。