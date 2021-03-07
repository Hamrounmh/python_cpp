#include <pybind11/pybind11.h>

char version[]="1.0";

char const* getVersion() {
	return version;
}


class Animal {    
  private:            
    int age;
  public: 

  
Animal(int x){
  age=x;
  } 
void setAge (int x) {
 age = x;

}
int birthDay(){
age+=1;
return age;

}


};



namespace py = pybind11;


PYBIND11_MODULE(animal_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
      py::class_<Animal>(greetings, "Animal", py::dynamic_attr())
        .def(py::init<int>())
        .def("birthDay", &Animal::birthDay,"increment the age of the animal and return the new age")
	.def("setAge", &Animal::setAge,"set the age of the animal");
}
