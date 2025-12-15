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



