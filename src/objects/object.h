#pragma once

namespace Tmpl8 {
    class Visitor;
}

namespace objects {
    class Object {
        public:
            virtual void accept(Tmpl8::Visitor* visitor) = 0;

        private:

        protected:
    };
}