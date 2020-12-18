#pragma once

namespace Tmpl8 {
    class Tank;
    class Surface;
    class vec2;
}

namespace objects {
    class Object {
        public:
            virtual void draw(Tmpl8::Surface* screen) = 0;
            virtual void tick() = 0;
            virtual Tmpl8::vec2 get_position() = 0;

            int range = 0;

        private:

        protected:
    };
}