#pragma once

namespace objects {
    class Object;
}

namespace Tmpl8 {
    class Rocket;
    class Beam;
    class Tank;

    class Visitor {
        public:
            virtual void visit_rocket(Rocket* rocket, Tank* tank) = 0;
            virtual void visit_beam(Beam* beam, Tank* tank) = 0;
            virtual void visit_tank(Tank* tank, Tank* other) = 0;

        private:

        protected:
    };
}