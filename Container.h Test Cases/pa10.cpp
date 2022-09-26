/// @file pa10.cpp
/// @author Jordan Scherf <5005736913@student.csn.edu>
/// @date 13/06/2021
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This lab demonstates [ The Use of Classes]. Introduces the
/// the uses of class and the test cases with the Container.h File
/// @note Time Taken to Develop Program is about 8 hours
/// between days 11/06 and 13/06  with Assitance of
/// [TA William and Professor Kevin Mess]

#include <iostream>
#include "Container.h"
#include <sstream>
#include <string>
using namespace std;
    
bool check(bool expr, const char msg[] = "");
void test_constructor();
void test_size();
void test_insert();
void test_erase();
void test_write();
void test_empty();
void test_clear();
void test_count();
void test_contains();


int main() {

    test_constructor();  // Test Constructor
    test_size();  // Size Test 
    test_erase();  // Erase Test
    test_write();  // Write Output Test
    test_empty();  // Empty Test
    test_clear();  // Clear Test
    test_count();  // Count Test
    test_insert();  // Insert Test  
        

        
    return EXIT_SUCCESS;
}

/// ---------------------------------------------------------------
/// Function Name: check
///
/// Gets Called to Check if the expression is True
/// If not, it will display an error message 
///
/// @param expr the expression to check
/// @param msg the message to output on faliure
///
/// @returns Bool (True or False)
/// ---------------------------------------------------------------
    
bool check(bool expr, const char msg[]){
          
          if (expr == false) {
        cerr << "FAILED: " << msg << endl;
}

    return expr;
}


/// ---------------------------------------------------------------
/// Function Name: test_size
///
/// test the size of the container (array within the container) 
/// and ensures that the size is equal to how many things were
/// put in it. The check will return a number value.
///
/// ---------------------------------------------------------------

void test_size(){
    Container emptyBin;  // emptyBin of the Container class  
    Container bin;  // bin of the Container class to hold some stuff  
    Container fullBin;  // fullBin of the Container Class to be full 

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index <
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

  check(bin.size() == 10, "The Size should be 10");
  check(fullBin.size() == 20, "The Size should be 20");
  check(emptyBin.size() == 0, "The Size should be 0" );
}

/// ---------------------------------------------------------------
/// Function Name: test_insert
///
/// test the insert function so that things can be put into the 
/// container if there is room and shuts down the program if it
/// does. The check will return a mix of number values and boolians
///
/// ---------------------------------------------------------------

void test_insert(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

  check(bin.size() == 10, "The Size should be 10");
  check(fullBin.size() == 20, "The Size should be 20");
  check(emptyBin.size() == 0, "The Size should be 0" );

  check(bin.contains(9) == true, "This should Contain a 9");
  check(bin.contains(0) == true, "This should Contain a 0");
  check(fullBin.contains(0) == true, "This Should Contain a 0");
  check(fullBin.contains(19) == true, "This Should Contain a 19");
  check(emptyBin.contains(4) == false, "This shouldnt Contain Anything");

  check(fullBin.count(15) == 1, "This Should Contain the number 15");
  check(bin.count(3) == 1, "This Should Contain at least 1 of the Number 3");
  check(emptyBin.count(4) == 0, "This Shouldnt Contain Anything");
}

/// ---------------------------------------------------------------
/// Function Name: test_erase
///
/// erases the target number (anything really) and attempts to
/// erase it from the container, it checks using the "test_contains"
/// function. The check will return a boolian value.
///
/// ---------------------------------------------------------------

void test_erase(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

    bin.erase(5);
    check(bin.contains(5) == false, "bin Should Not Contain a 5, It was Erased");

    fullBin.erase(15);
    check(fullBin.contains(15) == false, "bin Should Not Contain a 15");
}

/// ---------------------------------------------------------------
/// Function Name: test_write
///
/// Writes out to an output so we can see if it is inputing the
/// right numbers, this is seen by us using the "test_insert"
/// function then telling it to write out the contents to prove
/// it works.
///
/// ---------------------------------------------------------------

void test_write(){
    
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }
    
    ostringstream output;
    
    bin.insert(42);
    bin.insert(73);
    bin.insert(2);
    bin.write(output);
    
    cout << output.str() << endl;
    
}

/// ---------------------------------------------------------------
/// Function Name: test_empty
///
/// This function test whether the container is empty by putting
/// it through the ".empty()" boolian function. The Check will 
/// return a number value.
///
/// ---------------------------------------------------------------

void test_empty(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

    check(emptyBin.empty() == true, "This Should Be Empty" );
    check(bin.empty() == false, "This should have things in it");
    check(fullBin.empty() == false, "This should have things in it");
}

/// ---------------------------------------------------------------
/// Function Name: test_clear
///
/// This Function test to see that the clear function works by
/// using ".clear()", which sets the "uses" to 0. The check will 
/// return a number value
///
/// ---------------------------------------------------------------

void test_clear(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

    emptyBin.clear();
    bin.clear();
    fullBin.clear();

    check(emptyBin.size() == 0, "Empty bin should be empty");
    check(bin.size() == 0, "bin should be Empty");
    check(fullBin.size() == 0, "Full bin should Ironically be Empty");
}

/// ---------------------------------------------------------------
/// Function Name: test_count
///
/// This Function test the count function by using ".count(target)"
/// and it increments everytime the target is seen in the container
/// The check will return a number value 
///
/// ---------------------------------------------------------------

void test_count(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

    check(emptyBin.count(5) == 0, "This should, You geussed it, be empty");
    check(bin.count(0) == 1, "This should contain 1 of the number 0");
    check(bin.count(9) == 1, "This should contain 1 of the number 9");
    check(fullBin.count(0) == 1, "This should contain 1 of the number 0");
    check(fullBin.count(19) == 1, "This should contain 1 of the number 19");
}


/// ---------------------------------------------------------------
/// Function Name: test_contains
///
/// This Function test whether the container has the target number
/// in it using ".contains(target)". The check will return true or
/// false.
///
/// ---------------------------------------------------------------

void test_contains(){
    Container emptyBin;  // emptyBin of the Container class
    Container bin;  // bin of the Container class to hold some stuff
    Container fullBin;  // fullBin of the Container Class to be full

    for(Container::value_type index = 0; index < 10; index++){
        bin.insert(index);
    }

    for(Container::value_type index = 0; index < 
        static_cast <Container::value_type> (Container::CAPACITY); index++){
        fullBin.insert(index);
    }

    check(emptyBin.contains(3) == false, "Needs to be empty");
    check(bin.contains(4) == true, "The bin Should Contain a 4");
    check(fullBin.contains(15) == true, "The Full bin Should Contain a 15");
}

void test_constructor(){
    Container emptyBin;  // emptyBin of the Container class

    check(emptyBin.empty() == true, "This should be empty");
    check(emptyBin.size() == 0, "emptyBin Should be empty");
}
