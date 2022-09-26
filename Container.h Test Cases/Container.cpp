#include "Container.h"
#include <assert.h>


void Container::erase(const value_type& target){

    
    
    size_type index = 0;  // used to check place in array

    while (index < used){
        if (data[index] == target){
            data[index] = data[used - 1];
            used = used-1;
            index++;
        } else{
            index++;
        }
    }

}

void Container::insert(const value_type& value){
    assert(size()<CAPACITY);  // shuts down prgram if the size is bigger 

    data[used] = value;
    used++;

}

Container::size_type Container::count(const value_type& target) const{
    
    size_type count = 0;  // Keeps count of the number of targets found 
    
    for(size_type index = 0; index < used; index++){
        if(data[index] == target){
            count++;
        }
    }
    return count;
}

void Container::write(std::ostream& output){
    
    output << "{";

    for(size_type index = 0; index < used; index++){
        
        output << data[index];

        if(index != used - 1){
            output << ",";
        }
    }
    output << "}";
}

