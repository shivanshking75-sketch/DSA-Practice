/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        unordered_map<int, Employee*> emap;
        for(auto& employee : employees){
            emap[employee->id] = employee;
        }
        queue<Employee*> q;
        q.push(emap[id]);
        while (!q.empty()) {
            Employee* emp = q.front();  q.pop();
            result += emp->importance;
            for (int s : emp->subordinates) {
                q.push(emap[s]);
            }
        }
        return result;
    }
};