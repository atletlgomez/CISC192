Part A.cpp File
```c++
#include <iostream>
#include "Task.h"

void completeTask(Task* t) {
    if (t) t->markCompleted();
}
    int main() {
    Task t1(1, "finish the report");
    Task t2(2, "study for the exam");

    Task* p1 = &t1;
    Task* p2 = &t2;

    completeTask(p1);

    std::cout << p1->getId() << ": " << p1->getDescription() << (p1->isCompleted() ? " [completed]" : " [not completed]") << std::endl;
    std::cout << p2->getId() << ": " << p2->getDescription() << (p2->isCompleted() ? " [completed]" : " [not completed]") << std::endl;

    return 0;
}
```
Part B.cpp File

```c++
#include <iostream>
#include <string>
#include "Task.h"

void addTask(Task* tasks, int& size, int capacity, int& nextId, const std::string& desc) {
    if (size >= capacity) {
        std::cout << "cannot add more tasks" << std::endl;
        return;
    }
    tasks[size].set(nextId++, desc);
    size++;
    }

void removeTask(Task* tasks, int& size, int id) {
    for (int i = 0; i < size; ++i) {
        if (tasks[i].getId() == id) {
            for (int j = i; j < size - 1; ++j) {
                tasks[j] = tasks[j + 1];
            }
            size--;
            return;
        }
    }
    std::cout << "task not found" << std::endl;
}

void listTasks(const Task* tasks, int size) {
    if (size == 0) {
        std::cout << "no tasks available" << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << tasks[i].getId() << tasks[i].getDescription();
}
}


int main() {
    const int capacity = 3;
    int size = 0;
    int nextId = 1;

    Task* tasks = new Task[capacity];
    bool running = true;
    while (running) {
        std::cout << "pick (1. add, 2. remove, 3. list, 4. exit): ";
        int pick;
        std::cin >> pick;

        if (pick == 1) {
            std::cin.ignore();
            std::string desc;
            std::cout << "choice?:";
            std::getline(std::cin, desc);
            addTask(tasks, size, capacity, nextId, desc);
        } else if (pick == 2) {
            int id;
            std::cout << "id?:";
            std::cin >> id;
            removeTask(tasks, size, id);
        } else if (pick == 3) {
            listTasks(tasks, size);
        } else if (pick == 4) {
            running = false;
        } else {
            std::cout << "choose one" << std::endl;
        }
    }
    delete[] tasks;
    return 0;   
}
```

Part C cpp File
```c++
#include <iostream>
#include <string>
#include "taskManager.h"

int main() {
    TaskManager tm(5);

    bool running = true;
    while (running) {
        std::cout << "1.add 2.rmove 3.list 4.done: ";
        int pick;
        std::cin >> pick;

        if (pick == 1) {
            std::cin.ignore();
            std::string desc;
            std::cout << "choice?:";
            std::getline(std::cin, desc);
            tm.addTask(desc);
        } else if (pick == 2) {
            int id;
            std::cout << "id?:";
            std::cin >> id;
            tm.removeTask(id);
        } else if (pick == 3) {
            tm.listTasks();
        } else if (pick == 4) {
            running = false;
        } else {
            std::cout << "invalid pick" << std::endl;
        }
    }

    return 0;
}
```




taskManager.h File

```c++
#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "Task.h"

class TaskManager {
    private:
        std::unique_ptr<Task[]> tasks;
        int size;
        int capacity;
        int nextId;

    public:
        TaskManager(int initialCapacity)
        : tasks(std::make_unique<Task[]>(initialCapacity)),
          size(0),
          capacity(initialCapacity),
          nextId(1) {}

        void addTask(const std::string& desc) {
            if (size >= capacity) {
                std::cout << "cannot add more tasks" << std::endl;
                return;
            }
            tasks[size].set(nextId++, desc);
            size++;
        }


        void removeTask(int id) {
            for (int i = 0; i < size; ++i) {
                if (tasks[i].getId() == id) {
                    for (int j = i; j < size - 1; ++j) {
                        tasks[j] = tasks[j + 1];
                    }
                    size--;
                    return;
                }
            }
            std::cout << "task not found" << std::endl;
        }

        void listTasks() const {
            if (size == 0) {
                std::cout << "no tasks available" << std::endl;
                return;
            }
            for (int i = 0; i < size; ++i) {
                std::cout << tasks[i].getId() << ": " << tasks[i].getDescription()
                          << (tasks[i].isCompleted() ? " [completed]" : " [not completed]") << std::endl;
            }
        }
};

```



Task.H File

```c++

#pragma once
#include <string>

class Task {
    private:
        int id;
        std::string description;
        bool completed;

    public:
        Task(): id(0), description(""), completed(false) {}

        Task(int id, const std::string& desc) : id(id), description(desc), completed(false) {}


        void markCompleted() {
            completed = true;
        }


        bool isCompleted() {return completed; }


        int getId() const { return id; }
        std::string getDescription() const { return description; }

        void set(int newId, const std::string& newDesc) {
            id = newId;
            description = newDesc;
            completed = false;
        }
};  

```


```
UML DIAGRAM

**CLASS TASK**

id : int -

desc : string - 

completed : bool -

Task() +

Task (id:int, desc:string) +

markCompleted() : void +

isCompleted() : bool +

getId() : int +

getDescription() : string +

set(newId:int, desc:string) : void +


**CLASS TASKMANAGER**

tasks : unique_ptr<Task[]> -

size : int -

capacity : int -

nextId : int -

TaskManager(intitialCapacity:int) +

addTask (desc : string) : void +

removeTask (id : int ) : void +

listTasks() : void +

```
**PART D REFLECTION**

pointer to stack memory is memory that is created whle the program is running but once it is completed, it will disappear. pointer to heap memory is created by the user rather than the program like stack memory. Issue can arise from mishandling heap memory. Smart pointers automate some of tha memory handling for the user. Delete is used in Part B because heap memory is handled by the user, it must deals with all types of memory maintanance. Part A, memory belonged to the stack, while in part B, its belonged to the user. In part C, the ownership belonged to the smart pointer since it handles more of the issues. Overall, the smart pointer is the safest to use because there is less user error when handling memory. 



