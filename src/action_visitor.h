#pragma once

namespace Tmpl8 {

    class Rocket;
    class Beam;
    class Tank;

    class ActionVisitor : public Visitor {
        public:
            ActionVisitor();
            void visit_rocket(Rocket* rocket, Tank* tank) override;
            void visit_beam(Beam* rocket, Tank* tank) override;

        private:

        protected:
    };
}