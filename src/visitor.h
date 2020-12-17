#pragma once

namespace Tmpl8 {
    class Rocket;

    class Visitor {
        public:
            virtual void visit_rocket(Rocket* rocket) = 0;

        private:

        protected:
    };
}