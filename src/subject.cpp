#include <iostream>

namespace unihelp{
    class Subject{

        public:
        void sayHello(){
            std::cout << "Hello" <<std::endl;
        }

    };



}

int main(){
    unihelp::Subject subj;
    subj.sayHello();
    return 0;
}