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
