#include <pybind11/pybind11.h>

char race[]="chat";

char const* getRace() {
	return race;
}

char const* jaiFaim() {
  return "miaw... miaw... !";
}

namespace py = pybind11;


PYBIND11_MODULE(animal_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  
  greetings.def("greet", &greet, "a function saying hello");
  greetings.def("getVersion", &getVersion, "a function returning the version");
}
