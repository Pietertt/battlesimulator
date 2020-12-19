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

            int range = 0;

            void set_damage(int damage){
                this->damage = damage;
            }

            int get_damage(){
                return this->damage;
            }

        private:
            int damage = 0;

        protected:
    };
}