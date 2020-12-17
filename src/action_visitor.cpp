#include "precomp.h"

namespace Tmpl8 {
    ActionVisitor::ActionVisitor(){
        std::cout << this << std::endl;
    }

    void ActionVisitor::visit_rocket(Rocket* rocket){

    }
}