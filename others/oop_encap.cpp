/*
Create a class named Name. This Name class has following properties:
    - one private attribute: string name
    - a public constructor (This constructor takes a string as parameter and set it to the name attribute)
    - a public method (This method takes a string as parameter and concatenate it with the name attribute)
    - a public method (This method will return the value of name attribute.)

Create an object of Name class. Set a name using constructor with this object. Call the concatName method by passing another string.
And finally print the name by calling getName function via this object.
*/

#include <iostream>
using namespace std;

class Name {
    private:
      // hidden data from outside world
      string name;

   public:
      // constructor
      Name(string first_name) {
         name = first_name;
      }

      // interface to outside world
      void concatName(string last_name) {
         name += " " + last_name;
      }

      // interface to outside world
      string getName() {
         return name;
      };
};

int main() {
   Name obj("Alex");
   obj.concatName("John");

   cout << "Name=" << obj.getName() <<endl;

   return 0;
}
