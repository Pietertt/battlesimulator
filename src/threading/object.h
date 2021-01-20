#pragma once

namespace threading {

    typedef void (*functiontype)(int);

    struct object {

        functiontype f;
        int parameter;
        
    };
    

}