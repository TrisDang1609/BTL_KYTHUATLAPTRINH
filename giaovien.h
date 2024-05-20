#include<iostream>
#include<string>
#include<map>
#include<vector>
std::map<int, std::string> weekPresent = {
    {1, "Monday"},
    {2, "Tuesday"},
    {3, "Wednesday"},
    {4, "Thursday"},
    {5, "Friday"},
    {6, "Saturday"},
    {7, "Sunday"}
};
class scheduleInWeek{
    std::vector<bool> dayOfWeek (7, false);
};

class giaoVien{
    std::string name;
    std::string telNum;

public:
    void set_name(std::string a){
        name = a;
    }
    void set_telNum(std::string a){
        telNum = a;
    }
    
};+