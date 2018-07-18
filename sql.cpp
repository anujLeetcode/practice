#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct blockNode {
 int size;
 struct blockNode* next;
 char* ptr; 
};

class block {
  list <blockNode*> freeList;
  list <blockNode*> usedList;
  char *data = NULL;  
  block() {
    data = new char[4 * 1024];
    blockNode *temp = (blockNode*)data;
    temp->size = 4 * 1024;
    temp->next = NULL;
    freeList.push(temp);
  } 

  char* Allocate(int size) {
     //if(size > 4096) return NULL;
     while(auto itr : freeList) {
       if(itr->size > size + sizeof(blockNode)) break;
     }
     
     if(itr == freeList.end()) return NULL;
     int block_size = itr->size;
     blockNode* temp = itr;
     temp->size = size;
     temp->ptr = (char*)(temp + sizeof(blockNode));
     char* ret_ptr = (char*)temp->ptr;
     usedList.push(temp);
     freeList.remove(itr);
     
     temp += sizeof(blockNode) + size;
     temp->size = block_size - (size + sizeof(blockNode));
     freeList.push(temp);
     return ret_ptr;
  }

  bool DeAllocate(char* ptr) {
     if(usedList.empty()) return false;
     while(auto itr : usedList) {
       if(itr->ptr == ptr) break;
     }
     if(usedList.end() == itr) return false;
     
     blockNode* temp = itr;
     temp = temp - sizeof(blockNode));
     
     freeList.push(temp);
     usedList.remove(itr);
     return true;
  }
};


class sql {
  unordered_map<string key, char*> sql_map;
  block obj;
  public:
  bool parser(string cmd, string key, char* value) {
     if(cmd == "INS") {
       int size = strlen(value);
       char *ptr = obj.Allocate(size + 5);
       if (!ptr) return false;
       strncpy(ptr, key.c_str(), 5);
       strcpy(ptr+5, value);
       sql_map[key] = ptr;
     } else if (cmd == "UPD") {
       int size = strlen(value);
       char *ptr = obj.Allocate(size + 5);
       if (!ptr) return false;
       strncpy(ptr, key.c_str(), 5);
       strcpy(ptr+5, value);
       char* old_val = sql_map[key];
       if(!DeAllocate(old_val)) return false;
       sql_map[key] = value;
     } else if(cmd == "DEL") {
       char* old_val = sql_map[key];
       if(!DeAllocate(old_val)) return false;
       sql_map.remove(key);
     } else if(cmd == "SEL") {
       char* val = sql_map[key]+5;
       printf("%s \n",val);
     } else {
       cout << "unsupported operation";
       return false;
     }
     return true;
  }

}

int main()
{
int i;
int commandCount = sizeof(CommandList)/sizeof(CommandList[0]);
for (i = 0; i < commandCount; i++)
{
if (CommandList[i].value == NULL)
{
printf("%s: %s\n", CommandList[i].cmd, CommandList[i].key);
}
else
{
printf("%s: %s %s\n",
CommandList[i].cmd,
CommandList[i].key,
CommandList[i].value);
sql obj;
obj.parser(string(cmd), string(key), value);
}
}
return (0);
}
