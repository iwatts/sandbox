#include <iostream>
#include <cstring>
using namespace std;

int main() {
   char personName[100] = "Albert Johnson";
   char searchChar = 'J';
   char* searchResult = nullptr;

   /* Your solution goes here  */
   searchResult = strrchr(personName, searchChar);

   if (searchResult != nullptr) {
      cout << "Character found." << endl;
   }
   else {
      cout << "Character not found." << endl;
   }

   return 0;