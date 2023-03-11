//
//  main.cpp
//  Practice Midterm 2
//
//  Created by Kareem Elnaghy on 3/11/23.
//


#include <iostream>
#include <cmath>
using namespace std;

class Box {
    
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
    
    Box operator-(const Box& b) {   // overload subtract (-) operator
       Box box;
       box.length = this->length - b.length;
       box.breadth = this->breadth - b.breadth;
       box.height = this->height - b.height;
       return box;
    }
    
    Box operator++(int) {       //overload post-fix increment
       Box box;
        box = *this;
        this->length++;
        this->breadth++;
        this->height++;
       return box;
    }
    
    Box& operator++() {          //overload pre-fix increment
       
        this->length++;
        this->breadth++;
        this->height++;
       return *this;
    }
    
  
};
// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;
    cout<<"Volume of Box3 After Adding Box1 and Box2: "<<endl;
   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
    
   //Using - operator
    cout<<"Volume of Box3 After Subtracting Box1 and Box2: "<<endl;
    Box3 = Box1 - Box2;
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << abs(volume) <<endl; //absolute since volume cannot be negative 
    
  //using post fix increment operator
    cout<<"Volume of Box3 After post fix increment Box1 and Box2: "<<endl;
    Box3 = Box1++;
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;
    
//reset values
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);
    
 //using pre fix increment operator
    cout<<"Volume of Box3 After Pre fix increment Box1 and Box2: "<<endl;
    Box3 = ++Box1;
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume<<endl;
    
   return 0;
}
