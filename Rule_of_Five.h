/*
 * See http://en.cppreference.com/w/cpp/language/rule_of_three
 *
 */
#include <cstring>
#include <memory>

class Rule_of_Five
{

 private:
  char* cstr;
 public:
  Rule_of_Five(const char* obj_cstr) {
    cstr = new char[std::strlen(obj_cstr) + 1];
    std::strcpy(cstr, obj_cstr);
  }
  // const

  // copy
  Rule_of_Five(const Rule_of_Five& obj) {
    cstr = new char[std::strlen(obj.cstr) + 1];
    std::strcpy(cstr, obj.cstr);
  }
  // move
  Rule_of_Five(Rule_of_Five&& obj):cstr(obj.cstr) {
    obj.cstr = nullptr;
  }

  // operator

  // copy
  Rule_of_Five& operator=(const Rule_of_Five& obj) {
    if (this != &obj) {
      delete[] cstr;
      cstr = new char[std::strlen(obj.cstr) + 1];
      std::strcpy(cstr, obj.cstr);
    }
    return *this;
  }
  // move
  Rule_of_Five& operator=(Rule_of_Five&& obj) {
    if (this != &obj) {
      delete[] cstr;
      cstr = obj.cstr;
      obj.cstr = nullptr;
    }
    return *this;
  }

  // destr
  virtual ~Rule_of_Five() {
    if (cstr) {
      delete[] cstr;
    }
  }
};
