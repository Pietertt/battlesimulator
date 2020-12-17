#pragma once

namespace Tmpl8 {
    class Visitor;
    class Tank;
    class Surface;
}

namespace objects {
    class Object {
        public:
            virtual void accept(Tmpl8::Visitor* visitor, Tmpl8::Tank* tank) = 0;
            virtual void draw(Tmpl8::Surface* screen) = 0;
            virtual void tick() = 0;

        private:

        protected:
    };
}